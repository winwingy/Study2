
// 02ShellStructDlg.h : ͷ�ļ�
//

#pragma once


// CMy02ShellStructDlg �Ի���
class CMy02ShellStructDlg : public CDialogEx
{
// ����
public:
	CMy02ShellStructDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MY02SHELLSTRUCT_DIALOG };

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
	afx_msg void OnBnClickedButtonExtracticon();
	void drawIconList();
};
