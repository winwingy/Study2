
// 0801ExeExcutableDlg.h : ͷ�ļ�
//

#pragma once


// CMy0801ExeExcutableDlg �Ի���
class CMy0801ExeExcutableDlg : public CDialogEx
{
// ����
public:
	CMy0801ExeExcutableDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MY0801EXEEXCUTABLE_DIALOG };

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
	afx_msg void OnBnClickedButtondefaultbrowser();
	afx_msg void OnBnClickedButtonshowproperty();
};
