
// 1201ShellOptDlg.h : ͷ�ļ�
//

#pragma once


// CMy1201ShellOptDlg �Ի���
class CMy1201ShellOptDlg : public CDialogEx
{
// ����
public:
	CMy1201ShellOptDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MY1201SHELLOPT_DIALOG };

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
