
// clipBoardMineData.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CclipBoardMineDataApp:
// �йش����ʵ�֣������ clipBoardMineData.cpp
//

class CclipBoardMineDataApp : public CWinApp
{
public:
	CclipBoardMineDataApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CclipBoardMineDataApp theApp;