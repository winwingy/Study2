
// 0801ExeExcutableDlg.h : 头文件
//

#pragma once


// CMy0801ExeExcutableDlg 对话框
class CMy0801ExeExcutableDlg : public CDialogEx
{
// 构造
public:
	CMy0801ExeExcutableDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MY0801EXEEXCUTABLE_DIALOG };

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
	afx_msg void OnBnClickedButtondefaultbrowser();
	afx_msg void OnBnClickedButtonshowproperty();
};
