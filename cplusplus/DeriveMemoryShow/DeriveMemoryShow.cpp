// DeriveMemoryShow.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <windows.h>
#include <string>

#define TRACEWJ(x) {TCHAR szBuf[1024];\
	OutputDebugStringW(__FUNCTIONW__);\
	_stprintf_s(szBuf, _countof(szBuf), _T("::%d "), __LINE__);\
	OutputDebugStringW(szBuf);\
	OutputDebugStringW(x);\
	OutputDebugStringW(_T("\n"));}


class Student
{
public:
	Student(int age, int pt)
		: m_age(age)
		, m_point(pt)
	{
		
	}

	~Student()
	{
		
	}

	void show()
	{
		TRACEWJ(_T(""));
	}

	void setAge(int age)
	{
		m_age = age;
		TRACEWJ(_T(""));
	}

private:
	int m_age;
	int m_point;
	//std::wstring m_name;
};

typedef void(*SetAgeFun)(Student* obj, int age);

int _tmain(int argc, _TCHAR* argv[])
{
	Student s(68, 10);
	s.show();
	s.setAge(21);
	int sz = sizeof(s);
	
	char szBuf[1024];
	sprintf_s(szBuf, "%d", &Student::setAge);
	int px = atoi(szBuf);

	SetAgeFun setAge;
	int* pSet = (int*)setAge;
	setAge = (SetAgeFun)px;


	system("pause");
	return 0;
}

