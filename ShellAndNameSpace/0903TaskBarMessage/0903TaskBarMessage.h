
// 0903TaskBarMessage.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMy0903TaskBarMessageApp:
// �йش����ʵ�֣������ 0903TaskBarMessage.cpp
//

class CMy0903TaskBarMessageApp : public CWinApp
{
public:
	CMy0903TaskBarMessageApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMy0903TaskBarMessageApp theApp;