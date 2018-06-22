// TxtExt.cpp : CTxtExt 的实现

#include "stdafx.h"
#include "TxtExt.h"


// CTxtExt


// CTxtExt
//pwszPath 为当前文件的全路径
STDMETHODIMP CTxtExt::IsMemberOf(THIS_ _In_ PCWSTR pwszPath, DWORD dwAttrib)
{
	HRESULT hRef = S_FALSE;	
	wchar_t* fileClass = _wcsdup(wcsrchr(pwszPath, '.'));
	if (fileClass != NULL)
	{
		if (_wcsicmp(fileClass, L".txt") == 0)
		{//判断是否是txt后缀的文件
			hRef = S_OK;
		}
	}

	free(fileClass);
	//如果是符合要求的文件，就返回S_OK
	return hRef;
}

//pwszIconFile 用于设置图标文件的路径，路径长度不能超过cchMax个字符。
//pIndex 用于设置图标覆盖的先后顺序
STDMETHODIMP CTxtExt::GetOverlayInfo(LPTSTR pwszIconFile, 
	int cchMax, _Out_ int * pIndex, _Out_ DWORD * pdwFlags)
{
	WCHAR *buff = new WCHAR[cchMax];
// 	//获取当前程序的路径，而不是调用该程序的程序的路径，因为调用该程序的是资源管理器（explorer.exe）,直接过去路径的话，获取的是资源管理器的路径。
// 	GetModuleFileNameW(_AtlBaseModule.GetModuleInstance(), buff, cchMax);
// 
// 	WCHAR *nChar = wcsrchr(buff, L'\\');
// 	if (nChar != NULL)
// 	{//写入当前程序路径下的图标的名字
// 		//wcscpy_s(nChar, cchMax - wcslen(buff), L"D:\\test\\test.png");
// 		wcscpy_s(pwszIconFile, cchMax, L"D:\\test\\test.png");
// 	}
	wcscpy_s(pwszIconFile, cchMax, L"D:\\test\\bitbug.ico");
	//设置顺序
	*pIndex = 0;

	//标识所修改过的数据pwszIconFile 与 pIndex
	*pdwFlags = ISIOI_ICONFILE | ISIOI_ICONINDEX;

	delete [] buff;
	//完成返回S_OK
	return S_OK;
}

STDMETHODIMP CTxtExt::GetPriority(THIS_ _Out_ int * pIPriority)
{
	*pIPriority = 0;
	return S_OK;
}