
// 0903TaskBarMessageDlg.h : ͷ�ļ�
//

#pragma once


// CMy0903TaskBarMessageDlg �Ի���
class CMy0903TaskBarMessageDlg : public CDialogEx
{
// ����
public:
	CMy0903TaskBarMessageDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MY0903TASKBARMESSAGE_DIALOG };

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
