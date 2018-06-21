
// 1201ShellOptDlg.h : 头文件
//

#pragma once


// CMy1201ShellOptDlg 对话框
class CMy1201ShellOptDlg : public CDialogEx
{
// 构造
public:
	CMy1201ShellOptDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MY1201SHELLOPT_DIALOG };

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

	afx_msg void OnBnClickedButtonFolderview();
	afx_msg void OnBnClickedButtonFolderbrowsec();
	afx_msg void OnBnClickedButtonControlpanelitem();
	afx_msg void OnBnClickedButtonExplore();
	afx_msg void OnBnClickedButtonNamespace();
	afx_msg void OnBnClickedButtonWindows();
	afx_msg void OnBnClickedButtonFolderitems();
	afx_msg void OnBnClickedButtonGetopenfilename();
};
