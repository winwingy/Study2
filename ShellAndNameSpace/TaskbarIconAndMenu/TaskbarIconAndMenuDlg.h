
// TaskbarIconAndMenuDlg.h : ͷ�ļ�
//

#pragma once


// CTaskbarIconAndMenuDlg �Ի���
class CTaskbarIconAndMenuDlg : public CDialogEx
{
// ����
public:
	CTaskbarIconAndMenuDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_TASKBARICONANDMENU_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
