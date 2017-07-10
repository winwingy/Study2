// existFun.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>
class Teach
{
public:
	Teach()
	{

	}
	~Teach()
	{

	}
};

Teach g_teach;

void __cdecl func1(void)
{

}




int _tmain(int argc, _TCHAR* argv[])
{

	atexit(func1);
	return 0;
}

