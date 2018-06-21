
// 0903TaskBarMessageDlg.h : 头文件
//

#pragma once


// CMy0903TaskBarMessageDlg 对话框
class CMy0903TaskBarMessageDlg : public CDialogEx
{
// 构造
public:
	CMy0903TaskBarMessageDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MY0903TASKBARMESSAGE_DIALOG };

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
	afx_msg void OnBnClickedButtonInittaskbarmessage();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedButtonFlashwindow();
	afx_msg void OnBnClickedButtonTaskbarpos();
	afx_msg void OnBnClickedButtonAppbarstate();
	afx_msg void OnBnClickedButtonShoworhidetaskbar();
	afx_msg void OnBnClickedButtonAddtaskbartab();

private:
	HWND m_hTaskButton;
};
