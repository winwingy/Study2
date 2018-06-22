// ATLStudent.cpp : CATLStudent 的实现
#include "stdafx.h"
#include "ATLStudent.h"


// CATLStudent


STDMETHODIMP CATLStudent::showName(LONG para1, LONG para2, LONG* result)
{
	// TODO: 在此添加实现代码

	*result = para1 + para2;

	return S_OK;
}


STDMETHODIMP CATLStudent::subStr(BSTR name, BSTR text, BSTR* showText)
{
	// TODO: 在此添加实现代码
	CComBSTR ret;
	ret.Append(name);
	ret.Append(L" + ");
	ret.Append(text);
	*showText = ret.Detach();
	return S_OK;
}
