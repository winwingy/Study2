
// TaskbarIconAndMenuDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TaskbarIconAndMenu.h"
#include "TaskbarIconAndMenuDlg.h"
#include "afxdialogex.h"
#include <tchar.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define WM_MYNOTIFYICON (WM_USER + 100)
const UINT WM_TASKBARCREATED = ::RegisterWindowMessage(L"TaskbarCreated");
// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_MESSAGE(WM_MYNOTIFYICON, &CTaskbarIconAndMenuDlg::OnMyNotifyIcon)
	ON_REGISTERED_MESSAGE(WM_TASKBARCREATED, &CTaskbarIconAndMenuDlg::OnTaskBarCreated)
	ON_COMMAND(ID_CONTEXTMENU_SHOW_HIDE, &CTaskbarIconAndMenuDlg::OnContextmenuShowHide)
END_MESSAGE_MAP()


// CTaskbarIconAndMenuDlg �Ի���




CTaskbarIconAndMenuDlg::CTaskbarIconAndMenuDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTaskbarIconAndMenuDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTaskbarIconAndMenuDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTaskbarIconAndMenuDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_MESSAGE(WM_MYNOTIFYICON, &CTaskbarIconAndMenuDlg::OnMyNotifyIcon)

END_MESSAGE_MAP()


// CTaskbarIconAndMenuDlg ��Ϣ�������

BOOL CTaskbarIconAndMenuDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	InitialBarIcons();

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

BOOL CTaskbarIconAndMenuDlg::InitialBarIcons()
{
	m_nid.cbSize = sizeof(m_nid);
	m_nid.hWnd = m_hWnd;
	m_nid.uID = 0;
	m_nid.hIcon = m_hIcon;
	m_nid.uFlags = NIF_ICON|NIF_MESSAGE|NIF_TIP|NIF_INFO;
	m_nid.uCallbackMessage = WM_MYNOTIFYICON;
	_tccpy_s(m_nid.szTip, _T("Dictionary - Client"));
	_tcscpy_s(m_nid.szInfo, _T("Dictionary Client is running"));
	_tcscpy_s(m_nid.szInfoTitle, _T("Dictionary Client"));
	m_nid.dwInfoFlags = NIF_INFO;
	m_nid.uTimeout = 1500;
	if (nullptr == m_myMenu.GetSafeHmenu())
	{
		m_myMenu.LoadMenu(IDR_MYCONTEXTMENU);
	}

	return Shell_NotifyIcon(NIM_ADD, &m_nid);
}

LRESULT CTaskbarIconAndMenuDlg::OnMyNotifyIcon(WPARAM wParam, LPARAM lParam)
{
	switch(lParam)
	{

	}
}


BOOL CTaskbarIconAndMenuDlg::ShowBalloonTip()


void CTaskbarIconAndMenuDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CTaskbarIconAndMenuDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CTaskbarIconAndMenuDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

