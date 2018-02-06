// HookWndDLL.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "HookWndDLL.h"
HHOOK g_hook = nullptr;


LRESULT CALLBACK CBTProcMy(
	_In_ int    nCode,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam
	)
{
	if (HCBT_CREATEWND == nCode && lParam)
	{
		CREATESTRUCT* pCreate = reinterpret_cast<CREATESTRUCT*>(lParam);
		std::wstring className = pCreate->lpszClass;
		std::wstring title = pCreate->lpszName;
		if (className == _T("") && className == _T(""))
		{

		}	
	}

	return ::CallNextHookEx(g_hook, nCode, wParam, lParam);
}



void injectWnd()
{
	g_hook = SetWindowsHookEx(WH_CBT, CBTProcMy, g_hModule, 0);
	assert(g_hook);
}

void unjectWnd()
{
	 UnhookWindowsHookEx(g_hook);
}