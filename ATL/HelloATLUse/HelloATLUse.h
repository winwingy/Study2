
// HelloATLUse.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CHelloATLUseApp:
// �йش����ʵ�֣������ HelloATLUse.cpp
//

class CHelloATLUseApp : public CWinApp
{
public:
	CHelloATLUseApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CHelloATLUseApp theApp;