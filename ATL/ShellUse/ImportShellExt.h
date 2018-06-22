// ImportShellExt.h : CImportShellExt 的声明

#pragma once
#include "resource.h"       // 主符号



#include "ShellUse_i.h"
#include <shobjidl.h>
#include <vector>
#include <string>



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE 平台(如不提供完全 DCOM 支持的 Windows Mobile 平台)上无法正确支持单线程 COM 对象。定义 _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA 可强制 ATL 支持创建单线程 COM 对象实现并允许使用其单线程 COM 对象实现。rgs 文件中的线程模型已被设置为“Free”，原因是该模型是非 DCOM Windows CE 平台支持的唯一线程模型。"
#endif

using namespace ATL;


// CImportShellExt

class ATL_NO_VTABLE CImportShellExt :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CImportShellExt, &CLSID_ImportShellExt>,
	public IDispatchImpl<IImportShellExt, &IID_IImportShellExt, &LIBID_ShellUseLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public IShellExtInit,
	public IContextMenu
{
public:
	CImportShellExt()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_IMPORTSHELLEXT)


BEGIN_COM_MAP(CImportShellExt)
	COM_INTERFACE_ENTRY(IImportShellExt)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IShellExtInit)
	COM_INTERFACE_ENTRY(IContextMenu)
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

	virtual HRESULT STDMETHODCALLTYPE Initialize(__in_opt PCIDLIST_ABSOLUTE pidlFolder, 
		__in_opt IDataObject *pdtobj, __in_opt HKEY hkeyProgID) override;


	// IContextMenu  
	HRESULT STDMETHODCALLTYPE GetCommandString ( UINT_PTR idCmd, UINT uFlags, UINT *pwReserved,
		LPSTR pszName, UINT cchMax );  
	HRESULT STDMETHODCALLTYPE InvokeCommand ( LPCMINVOKECOMMANDINFO pCmdInfo );  
	HRESULT STDMETHODCALLTYPE QueryContextMenu( HMENU hmenu, UINT uMenuIndex, UINT uidFirstCmd,
		UINT uidLastCmd, UINT uFlags );  

	//用于保存文件路径
	std::vector<std::wstring> m_vtFilePath;

};

OBJECT_ENTRY_AUTO(__uuidof(ImportShellExt), CImportShellExt)
