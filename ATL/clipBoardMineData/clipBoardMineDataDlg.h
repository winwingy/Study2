
// clipBoardMineDataDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CclipBoardMineDataDlg �Ի���
class CclipBoardMineDataDlg : public CDialogEx
{
// ����
public:
	CclipBoardMineDataDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CLIPBOARDMINEDATA_DIALOG };

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
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CStatic m_staticShow;
	CStatic m_staticBitmap;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
};
