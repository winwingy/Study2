
// 02ShellStruct.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMy02ShellStructApp:
// �йش����ʵ�֣������ 02ShellStruct.cpp
//

class CMy02ShellStructApp : public CWinApp
{
public:
	CMy02ShellStructApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMy02ShellStructApp theApp;