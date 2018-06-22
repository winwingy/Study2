// TxtExt.h : CTxtExt ������

#pragma once
#include "resource.h"       // ������



#include "ShellIconUse_i.h"
#include <shlobj.h>



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif

using namespace ATL;


// CTxtExt

class ATL_NO_VTABLE CTxtExt :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CTxtExt, &CLSID_TxtExt>,
	public IDispatchImpl<ITxtExt, &IID_ITxtExt, &LIBID_ShellIconUseLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public IShellIconOverlayIdentifier
{
public:
	CTxtExt()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_TXTEXT)


BEGIN_COM_MAP(CTxtExt)
	COM_INTERFACE_ENTRY(ITxtExt)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IShellIconOverlayIdentifier)
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
	//ʵ�ֽӿڵ���������
	STDMETHOD(GetPriority(THIS_ _Out_ int * pIPriority));
	STDMETHOD(IsMemberOf(THIS_ _In_ PCWSTR pwszPath, DWORD dwAttrib));
	STDMETHOD(GetOverlayInfo(LPTSTR pwszIconFile, int cchMax, 
		_Out_ int * pIndex, _Out_ DWORD * pdwFlags));


};

OBJECT_ENTRY_AUTO(__uuidof(TxtExt), CTxtExt)
