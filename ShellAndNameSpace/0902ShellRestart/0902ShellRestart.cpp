// 0902ShellRestart.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <windows.h>

int _tmain(int argc, _TCHAR* argv[])
{
	HWND hWnd = FindWindow(L"Progman", NULL);
	PostMessage(hWnd, WM_QUIT, 0, 0);
	ShellExecute(NULL, NULL, L"explorer.exe", nullptr, nullptr, SW_SHOW);

	return 0;
}

