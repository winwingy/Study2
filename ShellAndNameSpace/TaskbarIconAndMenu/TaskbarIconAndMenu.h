
// TaskbarIconAndMenu.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CTaskbarIconAndMenuApp:
// �йش����ʵ�֣������ TaskbarIconAndMenu.cpp
//

class CTaskbarIconAndMenuApp : public CWinApp
{
public:
	CTaskbarIconAndMenuApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CTaskbarIconAndMenuApp theApp;