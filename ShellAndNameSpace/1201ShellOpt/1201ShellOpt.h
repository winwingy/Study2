
// 1201ShellOpt.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMy1201ShellOptApp:
// �йش����ʵ�֣������ 1201ShellOpt.cpp
//

class CMy1201ShellOptApp : public CWinApp
{
public:
	CMy1201ShellOptApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMy1201ShellOptApp theApp;