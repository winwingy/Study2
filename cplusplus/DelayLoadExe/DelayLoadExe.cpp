// DelayLoadExe.cpp : �������̨Ӧ�ó������ڵ㡣
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

