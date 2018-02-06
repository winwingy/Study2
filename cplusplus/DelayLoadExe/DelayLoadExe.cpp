// DelayLoadExe.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#pragma comment(lib, "DelayLoadMid.lib")
#pragma comment(lib, "DelayLoadDll.lib")
#include "../DelayLoadMid/DelayMidClass.h"


int _tmain(int argc, _TCHAR* argv[])
{
	DelayMidClass mid;
	mid.Init();
	return 0;
}

