// ShellUse.cpp : DLL 导出的实现。


#include "stdafx.h"
#include "resource.h"
#include "ShellUse_i.h"
#include "dllmain.h"
#include <atlbase.h>
using namespace ATL;


// 用于确定 DLL 是否可由 OLE 卸载。
STDAPI DllCanUnloadNow(void)
{
			return _AtlModule.DllCanUnloadNow();
	}

// 返回一个类工厂以创建所请求类型的对象。
STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
		return _AtlModule.DllGetClassObject(rclsid, riid, ppv);
}

// DllRegisterServer - 在系统注册表中添加项。
STDAPI DllRegisterServer(void)
{
	// 注册对象、类型库和类型库中的所有接口
 	if (0 == (GetVersion()& 0x80000000UL))
  	{
  		CRegKey reg;
  		LONG lRet;
  
  		lRet = reg.Open(HKEY_LOCAL_MACHINE,  
  			_T("Software\\Microsoft\\Windows\\CurrentVersion\\Shell Extensions\\Approved"), 
  			KEY_SET_VALUE);
  		if (ERROR_SUCCESS != lRet)
  		{
  			return E_ACCESSDENIED;
  		}
  		lRet = reg.SetValue(_T("ImportShell Extensions"), 
  			_T("{A8681CA0-C36D-40CD-AF4F-340F4A944B9B}"));
  
  		if (ERROR_SUCCESS != lRet)
  		{
  			return E_ACCESSDENIED;
  		}		
  	}

	HRESULT hr = _AtlModule.DllRegisterServer();
		return hr;
}

// DllUnregisterServer - 在系统注册表中移除项。
STDAPI DllUnregisterServer(void)
{
	if (0 == (GetVersion() & 0x8000000UL))
 	{
 		CRegKey reg;
 		LONG lRet;
 		lRet = reg.Open(HKEY_LOCAL_MACHINE, 
 			_T("Software\\Microsoft\\Windows\\CurrentVersion\\Shell Extensions\\Approved"), 
 			KEY_SET_VALUE);
 		if (ERROR_SUCCESS == lRet)
 		{
 			reg.DeleteValue(_T("{A8681CA0-C36D-40CD-AF4F-340F4A944B9B}"));
 		}
 	}


	HRESULT hr = _AtlModule.DllUnregisterServer();
		return hr;
}

// DllInstall - 按用户和计算机在系统注册表中逐一添加/移除项。
STDAPI DllInstall(BOOL bInstall, LPCWSTR pszCmdLine)
{
	HRESULT hr = E_FAIL;
	static const wchar_t szUserSwitch[] = L"user";

	if (pszCmdLine != NULL)
	{
		if (_wcsnicmp(pszCmdLine, szUserSwitch, _countof(szUserSwitch)) == 0)
		{
			ATL::AtlSetPerUserRegistration(true);
		}
	}

	if (bInstall)
	{	
		hr = DllRegisterServer();
		if (FAILED(hr))
		{
			DllUnregisterServer();
		}
	}
	else
	{
		hr = DllUnregisterServer();
	}

	return hr;
}


