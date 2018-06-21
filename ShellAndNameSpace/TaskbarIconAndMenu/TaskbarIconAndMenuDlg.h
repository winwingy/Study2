
// TaskbarIconAndMenuDlg.h : 头文件
//

#pragma once


// CTaskbarIconAndMenuDlg 对话框
class CTaskbarIconAndMenuDlg : public CDialogEx
{
// 构造
public:
	CTaskbarIconAndMenuDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_TASKBARICONANDMENU_DIALOG };

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
	afx_msg void OnContextMenuShowHid();
	afx_msg LRESULT OnMyNotifyIcon(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnTaskBarCreated(WPARAM wParam, LPARAM lParam);

	DECLARE_MESSAGE_MAP()


private:
	BOOL InitialBarIcons();
	BOOL ShowBalloonTip(LPCTSTR szInfo, LPCTSTR szInfoTitle = _T("title"),
		DWORD dwInfoFlags = NIIF_INFO);

	NOTIFYICONDATA m_nid;
	CMenu m_myMenu;
};
