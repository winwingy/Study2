// TxtExt.h : CTxtExt 的声明

#pragma once
#include "resource.h"       // 主符号



#include "ShellIconUse_i.h"
#include <shlobj.h>



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE 平台(如不提供完全 DCOM 支持的 Windows Mobile 平台)上无法正确支持单线程 COM 对象。定义 _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA 可强制 ATL 支持创建单线程 COM 对象实现并允许使用其单线程 COM 对象实现。rgs 文件中的线程模型已被设置为“Free”，原因是该模型是非 DCOM Windows CE 平台支持的唯一线程模型。"
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
	//实现接口的三个函数
	STDMETHOD(GetPriority(THIS_ _Out_ int * pIPriority));
	STDMETHOD(IsMemberOf(THIS_ _In_ PCWSTR pwszPath, DWORD dwAttrib));
	STDMETHOD(GetOverlayInfo(LPTSTR pwszIconFile, int cchMax, 
		_Out_ int * pIndex, _Out_ DWORD * pdwFlags));


};

OBJECT_ENTRY_AUTO(__uuidof(TxtExt), CTxtExt)
