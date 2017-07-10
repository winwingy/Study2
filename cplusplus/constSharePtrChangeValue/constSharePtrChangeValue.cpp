// constSharePtrChangeValue.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <memory>
#include <string>

std::shared_ptr<std::string> g_name(new std::string);
const std::shared_ptr<std::string> GetName()
{
	return g_name;
}


int _tmain(int argc, _TCHAR* argv[])
{
	*g_name = "111";
	const std::shared_ptr<const std::string> name =  GetName();
	name = nullptr;
	*name = "66";
	return 0;
}

