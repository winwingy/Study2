
// 0801ExeExcutable.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMy0801ExeExcutableApp:
// �йش����ʵ�֣������ 0801ExeExcutable.cpp
//

class CMy0801ExeExcutableApp : public CWinApp
{
public:
	CMy0801ExeExcutableApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMy0801ExeExcutableApp theApp;