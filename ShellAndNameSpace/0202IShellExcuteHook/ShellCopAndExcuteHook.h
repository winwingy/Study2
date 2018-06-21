// ShellCopAndExcuteHook.h : CShellCopAndExcuteHook 的声明

#pragma once
#include "resource.h"       // 主符号
#include <ShlObj.h>


#include "My0202IShellExcuteHook_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE 平台(如不提供完全 DCOM 支持的 Windows Mobile 平台)上无法正确支持单线程 COM 对象。定义 _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA 可强制 ATL 支持创建单线程 COM 对象实现并允许使用其单线程 COM 对象实现。rgs 文件中的线程模型已被设置为“Free”，原因是该模型是非 DCOM Windows CE 平台支持的唯一线程模型。"
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
