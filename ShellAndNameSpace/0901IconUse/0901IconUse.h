
// 0901IconUse.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMy0901IconUseApp:
// �йش����ʵ�֣������ 0901IconUse.cpp
//

class CMy0901IconUseApp : public CWinApp
{
public:
	CMy0901IconUseApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMy0901IconUseApp theApp;