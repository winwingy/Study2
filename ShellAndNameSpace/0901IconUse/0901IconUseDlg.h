
// 0901IconUseDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CMy0901IconUseDlg �Ի���
class CMy0901IconUseDlg : public CDialogEx
{
// ����
public:
	CMy0901IconUseDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MY0901ICONUSE_DIALOG };

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
	afx_msg void OnBnClickedButtonBitmaptoicon();
	CStatic m_showIcon;
};
