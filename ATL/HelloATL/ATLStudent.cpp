// ATLStudent.cpp : CATLStudent ��ʵ��
#include "stdafx.h"
#include "ATLStudent.h"


// CATLStudent


STDMETHODIMP CATLStudent::showName(LONG para1, LONG para2, LONG* result)
{
	// TODO: �ڴ����ʵ�ִ���

	*result = para1 + para2;

	return S_OK;
}


STDMETHODIMP CATLStudent::subStr(BSTR name, BSTR text, BSTR* showText)
{
	// TODO: �ڴ����ʵ�ִ���
	CComBSTR ret;
	ret.Append(name);
	ret.Append(L" + ");
	ret.Append(text);
	*showText = ret.Detach();
	return S_OK;
}
