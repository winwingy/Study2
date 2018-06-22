// ImportShellExt.cpp : CImportShellExt ��ʵ��

#include "stdafx.h"
#include "ImportShellExt.h"


// CImportShellExt


std::wstring int2T(int number)
{
	TCHAR* pBuf =new TCHAR[1024];
	memset(pBuf, 0, 1024);
	_itot_s(number, pBuf, 1024, 10);
	std::wstring ret(pBuf);
	delete [] pBuf;
	return ret;
}

struct MenuItem
{
	int menuId;
	std::wstring title;
	std::wstring tips;

};

std::vector<MenuItem> g_menuList;

size_t g_idCmdFirst = 0;

HRESULT CImportShellExt::QueryContextMenu(HMENU hmenu, UINT indexMenu, 
	UINT idCmdFirst, UINT uidLastCmd, UINT uFlags)
{
	if (uFlags & CMF_DEFAULTONLY)
	{//��ʱ�����κδ���
		return MAKE_HRESULT(SEVERITY_SUCCESS, FACILITY_NULL, 0);
	}
// 	g_menuList.clear();
// 	for (size_t id = idCmdFirst; id < idCmdFirst + 5; ++id)
// 	{
// 		MenuItem item = {id, L"title"+ int2T(id), L"tips"+ int2T(id)};
// 		g_menuList.push_back(item);
// 	}	
	g_idCmdFirst = idCmdFirst;
	std::wstring str;
	str = L"indexMenu:" + int2T(indexMenu) + L"idCmdFirst:" + int2T(idCmdFirst) +
		L"uidLastCmd:" + int2T(uidLastCmd);
	//MessageBox(nullptr, str.c_str(), L"dd", MB_OK);
	BOOL bRet = false;

	int nCmdId = idCmdFirst;
	//��Ӱ�ť
	bRet = InsertMenu(hmenu, indexMenu, MF_STRING | MF_BYPOSITION, nCmdId, _T("��ȡ�ļ���С"));
	//���ð�ť��ͼ��
	//HBITMAP hBitmap = nullptr;// LoadBitmap(_AtlBaseModule.GetModuleInstance(), MAKEINTRESOURCE(IDB_BITMAP1));
	//bRet = SetMenuItemBitmaps(hmenu, indexMenu, MF_BYPOSITION, hBitmap, NULL);

	++indexMenu;//��ŵ���
	++nCmdId;//����ID����
	bRet = InsertMenu(hmenu, indexMenu, MF_STRING | MF_BYPOSITION, nCmdId, _T("��ʾsee me"));

	++indexMenu;//��ŵ���
	++nCmdId;//����ID����
	bRet = InsertMenu(hmenu, indexMenu, MF_STRING | MF_BYPOSITION, nCmdId, _T("see me"));

	++indexMenu;//��ŵ���
	++nCmdId;//����ID����
	bRet = InsertMenu(hmenu, indexMenu, MF_STRING | MF_BYPOSITION, nCmdId, _T("good bye"));

	//���һ������Ϊ�����Ĳ˵��ĸ���
	return MAKE_HRESULT(SEVERITY_SUCCESS, FACILITY_NULL, nCmdId);
}

HRESULT CImportShellExt::GetCommandString(UINT_PTR idCmd, UINT uFlags, UINT *pwReserved, 
	LPSTR pszName, UINT cchMax)
{
	USES_CONVERSION;
	if (uFlags & GCS_HELPTEXT)
	{
		LPTSTR pText = _T("ͳ���ļ����е��ļ�����");
		if (uFlags & GCS_UNICODE)
		{
			lstrcpynW((LPWSTR)pszName, T2CW(pText), cchMax);
		}
		else
		{
			lstrcpynA((LPSTR)pszName, T2CA(pText), cchMax);
		}
		return S_OK;
	}
	return E_INVALIDARG;
}

HRESULT CImportShellExt::InvokeCommand(LPCMINVOKECOMMANDINFO pCmdInfo)
{
	if (0 != HIWORD(pCmdInfo->lpVerb))
	{
		return E_INVALIDARG;
	}
	switch (LOWORD(pCmdInfo->lpVerb))
	{
	case 0:
		{
			TCHAR szMsg[MAX_PATH + 32];
			wsprintf(szMsg, _T("ѡ�е��ļ���Ϊ%s"), L"�������");
			MessageBox(pCmdInfo->hwnd, szMsg, L"��Ϣ", MB_OK);
			return S_OK;
		}
	case 1:
		{
			TCHAR szMsg[MAX_PATH + 32];
			wsprintf(szMsg, _T("ѡ�е��ļ���Ϊ1111%s"), L"�������12222");
			MessageBox(pCmdInfo->hwnd, szMsg, L"��Ϣ", MB_OK);
			return S_OK;
		}
	default:
		return E_INVALIDARG;
	}
}

HRESULT CImportShellExt::Initialize(
	__in_opt PCIDLIST_ABSOLUTE pidlFolder, __in_opt IDataObject *pdtobj,
	__in_opt HKEY hkeyProgID)
{
	FORMATETC fmt = { CF_HDROP, NULL, DVASPECT_CONTENT, -1, TYMED_HGLOBAL };
	STGMEDIUM stg = { TYMED_HGLOBAL };
	HDROP hDrop;

	//�����ݶ����в���CF_HDROP��������
	if (FAILED(pdtobj->GetData(&fmt, &stg)))
	{//û�и�����
		return E_INVALIDARG;
	}

	//��ȡָ��ʵ�����ݵ�ָ��
	hDrop = (HDROP)GlobalLock(stg.hGlobal);

	//���
	if (NULL == hDrop)
	{
		return E_INVALIDARG;
	}

	HRESULT hr = S_OK;
	do
	{
		//��Ч�Լ�飬��֤������һ���ļ���
		UINT uNumFiles = DragQueryFile(hDrop, 0xFFFFFFFF, NULL, 0);
		if (0 == uNumFiles)
		{
			hr = E_INVALIDARG;
			break;
		}

		WCHAR tFilePath[MAX_PATH];
		//ȡ�����������ļ����ļ���
		for (UINT i = 0; i < uNumFiles; i++)
		{
			if (0 != DragQueryFileW(hDrop, i, tFilePath, MAX_PATH))
			{
				//������ļ��б���
				m_vtFilePath.push_back(tFilePath);
			}
			else
			{//�д���
				hr = E_INVALIDARG;
				break;
			}
		}
	} while (0);

	//�ͷ���Դ
	GlobalUnlock(stg.hGlobal);
	ReleaseStgMedium(&stg);
	return hr;
}
