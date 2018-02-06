// TypeTranslate.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <string>


int _tmain(int argc, _TCHAR* argv[])
{
	int a = boost::lexical_cast<int>("55");
	std::wstring text = L"100";
	int b = boost::lexical_cast<int>(text);
	text = L"100.02";
	double c = boost::lexical_cast<double>(text);

	double dd = 100.02;
	int d = boost::numeric_cast<int>(dd);

	boost::format(("%s %d %f")) % _T("abc")
		% 10 % 5.1;
	std::wstring formatText = boost::str(boost::wformat(_T("%s %d %f  %s")) % _T("abc")
		% 10 % 5.1 % text);


	system("pause"); 


	return 0;
}

