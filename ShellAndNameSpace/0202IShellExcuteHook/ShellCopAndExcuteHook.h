// ShellCopAndExcuteHook.h : CShellCopAndExcuteHook ������

#pragma once
#include "resource.h"       // ������
#include <ShlObj.h>


#include "My0202IShellExcuteHook_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif

using namespace ATL;


// CShellCopAndExcuteHook

class ATL_NO_VTABLE CShellCopAndExcuteHook :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CShellCopAndExcuteHook, &CLSID_ShellCopAndExcuteHook>,
	public IDispatchImpl<IShellCopAndExcuteHook, &IID_IShellCopAndExcuteHook, &LIBID_My0202IShellExcuteHookLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public ICopyHook,
	public IShellExecuteHook
{
public:
	CShellCopAndExcuteHook()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_SHELLCOPANDEXCUTEHOOK)


BEGIN_COM_MAP(CShellCopAndExcuteHook)
	COM_INTERFACE_ENTRY(IShellCopAndExcuteHook)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ICopyHook)
	COM_INTERFACE_ENTRY(IShellExecuteHook)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:

	UINT STDMETHODCALLTYPE CopyCallback (HWND hwnd, UINT wFunc, UINT wFlags, 
		LPCTSTR pszSrcFile, DWORD dwSrcAttribs,
		LPCTSTR pszDestFile, DWORD dwDestAttribs);

	HRESULT STDMETHODCALLTYPE Execute (LPSHELLEXECUTEINFO pei);

};

OBJECT_ENTRY_AUTO(__uuidof(ShellCopAndExcuteHook), CShellCopAndExcuteHook)
