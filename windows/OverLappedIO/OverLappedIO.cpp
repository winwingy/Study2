// OverLappedIO.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <windows.h>



void OverLappedIOUse()
{
	HANDLE file = CreateFile(L"E:\\setup\\qt-vs-addin-1.2.5.exe", 
		GENERIC_READ, FILE_SHARE_READ, 
		nullptr, OPEN_EXISTING, FILE_FLAG_OVERLAPPED, nullptr);
	OVERLAPPED overlapped = {0};
	overlapped.Offset = 1000;
	overlapped.hEvent = CreateEvent(nullptr, TRUE, FALSE, L"");
	const int Len = 100*1024*1024;
	char* szBuf = new char[Len];
	DWORD Readed = 0;
	BOOL ret = ReadFile(file, szBuf, Len, &Readed, &overlapped);
	if (ret == FALSE)
	{
		if (GetLastError() == ERROR_IO_PENDING)
		{
			WaitForSingleObject(overlapped.hEvent, INFINITE);
			DWORD overReaded = 0;
			BOOL getResult = GetOverlappedResult(file, &overlapped, &overReaded, TRUE);
			int a = 0;
		}
	}

}


int _tmain(int argc, _TCHAR* argv[])
{
	OverLappedIOUse();
	return 0;
}

