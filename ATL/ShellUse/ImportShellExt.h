// ImportShellExt.h : CImportShellExt ������

#pragma once
#include "resource.h"       // ������



#include "ShellUse_i.h"
#include <shobjidl.h>
#include <vector>
#include <string>



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
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

	//���ڱ����ļ�·��
	std::vector<std::wstring> m_vtFilePath;

};

OBJECT_ENTRY_AUTO(__uuidof(ImportShellExt), CImportShellExt)
