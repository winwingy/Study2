// TxtExt.cpp : CTxtExt ��ʵ��

#include "stdafx.h"
#include "TxtExt.h"


// CTxtExt


// CTxtExt
//pwszPath Ϊ��ǰ�ļ���ȫ·��
STDMETHODIMP CTxtExt::IsMemberOf(THIS_ _In_ PCWSTR pwszPath, DWORD dwAttrib)
{
	HRESULT hRef = S_FALSE;	
	wchar_t* fileClass = _wcsdup(wcsrchr(pwszPath, '.'));
	if (fileClass != NULL)
	{
		if (_wcsicmp(fileClass, L".txt") == 0)
		{//�ж��Ƿ���txt��׺���ļ�
			hRef = S_OK;
		}
	}

	free(fileClass);
	//����Ƿ���Ҫ����ļ����ͷ���S_OK
	return hRef;
}

//pwszIconFile ��������ͼ���ļ���·����·�����Ȳ��ܳ���cchMax���ַ���
//pIndex ��������ͼ�긲�ǵ��Ⱥ�˳��
STDMETHODIMP CTxtExt::GetOverlayInfo(LPTSTR pwszIconFile, 
	int cchMax, _Out_ int * pIndex, _Out_ DWORD * pdwFlags)
{
	WCHAR *buff = new WCHAR[cchMax];
// 	//��ȡ��ǰ�����·���������ǵ��øó���ĳ����·������Ϊ���øó��������Դ��������explorer.exe��,ֱ�ӹ�ȥ·���Ļ�����ȡ������Դ��������·����
// 	GetModuleFileNameW(_AtlBaseModule.GetModuleInstance(), buff, cchMax);
// 
// 	WCHAR *nChar = wcsrchr(buff, L'\\');
// 	if (nChar != NULL)
// 	{//д�뵱ǰ����·���µ�ͼ�������
// 		//wcscpy_s(nChar, cchMax - wcslen(buff), L"D:\\test\\test.png");
// 		wcscpy_s(pwszIconFile, cchMax, L"D:\\test\\test.png");
// 	}
	wcscpy_s(pwszIconFile, cchMax, L"D:\\test\\bitbug.ico");
	//����˳��
	*pIndex = 0;

	//��ʶ���޸Ĺ�������pwszIconFile �� pIndex
	*pdwFlags = ISIOI_ICONFILE | ISIOI_ICONINDEX;

	delete [] buff;
	//��ɷ���S_OK
	return S_OK;
}

STDMETHODIMP CTxtExt::GetPriority(THIS_ _Out_ int * pIPriority)
{
	*pIPriority = 0;
	return S_OK;
}