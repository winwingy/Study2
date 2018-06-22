
// clipBoardMineDataDlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CclipBoardMineDataDlg 对话框
class CclipBoardMineDataDlg : public CDialogEx
{
// 构造
public:
	CclipBoardMineDataDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CLIPBOARDMINEDATA_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CStatic m_staticShow;
	CStatic m_staticBitmap;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
};
