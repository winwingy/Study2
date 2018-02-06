// ReadeWriteLockUse.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <windows.h>
#include <winbase.h>
#include <process.h>
#include <string>

SRWLOCK g_srw;
std::wstring g_text;


unsigned __stdcall ReadProc1(void* param)
{
	for (int i = 0; i < 10; ++i)
	{
		AcquireSRWLockShared(&g_srw);
		wprintf(L"%ls", g_text.c_str());
		ReleaseSRWLockShared(&g_srw);
		Sleep(100);
	}
	return 0;
}

unsigned __stdcall ReadProc2(void* param)
{
	for (int i = 0; i < 10; ++i)
	{
		AcquireSRWLockShared(&g_srw);
		wprintf(L"%ls", g_text.c_str());
		ReleaseSRWLockShared(&g_srw);
		Sleep(100);
	}
	return 0;
}

unsigned __stdcall ReadProc3(void* param)
{
	for (int i = 0; i < 10; ++i)
	{
		AcquireSRWLockShared(&g_srw);
		wprintf(L"%ls", g_text.c_str());
		ReleaseSRWLockShared(&g_srw);
		Sleep(100);
	}
	return 0;
}

unsigned __stdcall ReadProc4(void* param)
{
	for (int i = 0; i < 30; ++i)
	{
		//AcquireSRWLockExclusive(&g_srw);
		g_text += L"AA" + std::wstring(L" ");
		//ReleaseSRWLockExclusive(&g_srw);
		Sleep(100);
	}
	return 0;
}

unsigned __stdcall ReadProc5(void* param)
{
	for (int i = 0; i < 30; ++i)
	{
		//AcquireSRWLockExclusive(&g_srw);	
		if (g_text.size() > _tclen(L"AA "))
		{
			g_text.erase(g_text.end() - 3);
		}
		//ReleaseSRWLockExclusive(&g_srw);
		Sleep(200);
	}
	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	InitializeSRWLock(&g_srw);

	HANDLE thread1 = (HANDLE)_beginthreadex(nullptr, 0, ReadProc1, 0, 0, nullptr);
	HANDLE thread2 = (HANDLE)_beginthreadex(nullptr, 0, ReadProc2, 0, 0, nullptr);
	HANDLE thread3 = (HANDLE)_beginthreadex(nullptr, 0, ReadProc3, 0, 0, nullptr);
	HANDLE thread4 = (HANDLE)_beginthreadex(nullptr, 0, ReadProc4, 0, 0, nullptr);
	HANDLE thread5 = (HANDLE)_beginthreadex(nullptr, 0, ReadProc5, 0, 0, nullptr);


	system("pause");


	return 0;
}

