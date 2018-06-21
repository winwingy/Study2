
// TaskbarIconAndMenuDlg.cpp : 实现文件
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
// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CTaskbarIconAndMenuDlg 对话框




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


// CTaskbarIconAndMenuDlg 消息处理程序

BOOL CTaskbarIconAndMenuDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	InitialBarIcons();

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CTaskbarIconAndMenuDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CTaskbarIconAndMenuDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

