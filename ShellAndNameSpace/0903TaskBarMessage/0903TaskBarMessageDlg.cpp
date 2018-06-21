
// 0903TaskBarMessageDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "0903TaskBarMessage.h"
#include "0903TaskBarMessageDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
UINT g_uSHellRestart;

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
END_MESSAGE_MAP()


// CMy0903TaskBarMessageDlg 对话框




CMy0903TaskBarMessageDlg::CMy0903TaskBarMessageDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMy0903TaskBarMessageDlg::IDD, pParent)
	, m_hTaskButton(nullptr)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy0903TaskBarMessageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMy0903TaskBarMessageDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_InitTaskbarMessage, &CMy0903TaskBarMessageDlg::OnBnClickedButtonInittaskbarmessage)
	ON_BN_CLICKED(IDC_BUTTON_FlashWindow, &CMy0903TaskBarMessageDlg::OnBnClickedButtonFlashwindow)
	ON_BN_CLICKED(IDC_BUTTON_TaskbarPos, &CMy0903TaskBarMessageDlg::OnBnClickedButtonTaskbarpos)
	ON_BN_CLICKED(IDC_BUTTON_AppBarState, &CMy0903TaskBarMessageDlg::OnBnClickedButtonAppbarstate)
	ON_BN_CLICKED(IDC_BUTTON_ShowOrHideTaskbar, &CMy0903TaskBarMessageDlg::OnBnClickedButtonShoworhidetaskbar)
	ON_BN_CLICKED(IDC_BUTTON_AddTaskBarTab, &CMy0903TaskBarMessageDlg::OnBnClickedButtonAddtaskbartab)
END_MESSAGE_MAP()


// CMy0903TaskBarMessageDlg 消息处理程序

BOOL CMy0903TaskBarMessageDlg::OnInitDialog()
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

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMy0903TaskBarMessageDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy0903TaskBarMessageDlg::OnPaint()
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
HCURSOR CMy0903TaskBarMessageDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy0903TaskBarMessageDlg::OnBnClickedButtonInittaskbarmessage()
{
	
	g_uSHellRestart = RegisterWindowMessage(L"TaskbarCreated");
	// TODO: 在此添加控件通知处理程序代码
}



BOOL CMy0903TaskBarMessageDlg::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == g_uSHellRestart)
	{
		OutputDebugString(L"TaskbarCreated");
	}
	if (pMsg->message == WM_LBUTTONDBLCLK)
	{
		OutputDebugString(L"WM_LBUTTONDBLCLK\n");
	}
	return __super::PreTranslateMessage(pMsg);
}


void CMy0903TaskBarMessageDlg::OnBnClickedButtonFlashwindow()
{
	FlashWindowEx(FLASHW_ALL, 100, 0);
}


void CMy0903TaskBarMessageDlg::OnBnClickedButtonTaskbarpos()
{
	APPBARDATA abd = {0};
	abd.cbSize = sizeof(abd);
	SHAppBarMessage(ABM_GETTASKBARPOS, &abd);
	switch (abd.uEdge)
	{
	case ABE_BOTTOM:
		MessageBox(L"Bottom", L"appBar", MB_OK);
		break;
	case ABE_LEFT:
		MessageBox(L"ABE_LEFT", L"appBar", MB_OK);
		break;
	case ABE_RIGHT:
		MessageBox(L"ABE_RIGHT", L"appBar", MB_OK);
		break;
	case ABE_TOP:
		MessageBox(L"ABE_TOP", L"appBar", MB_OK);
		break;
	}
}


void CMy0903TaskBarMessageDlg::OnBnClickedButtonAppbarstate()
{
	APPBARDATA abd = {0};
	abd.cbSize = sizeof(abd);
	UINT_PTR rc = SHAppBarMessage(ABM_GETSTATE, &abd);
	if (rc & ABS_ALWAYSONTOP)
	{
		MessageBox(L"ABS_ALWAYSONTOP", L"OnBnClickedButtonAppbarstate", MB_OK);
	}
	if (rc & ABS_AUTOHIDE)
	{
		MessageBox(L"ABS_AUTOHIDE", L"OnBnClickedButtonAppbarstate", MB_OK);
	}
}


void CMy0903TaskBarMessageDlg::OnBnClickedButtonShoworhidetaskbar()
{
	HWND hWndTaskbar = ::FindWindow(L"Shell_TrayWnd", nullptr);
	static bool show = false;
	show = !show;
	::ShowWindow(hWndTaskbar, show);
}




void CMy0903TaskBarMessageDlg::OnBnClickedButtonAddtaskbartab()
{
	if (!m_hTaskButton)
	{
		m_hTaskButton = CreateWindow(L"Button", L"Cunstom button ...", 
			WS_CAPTION|WS_SYSMENU|WS_VISIBLE, -300, -300, 50, 50,
			m_hWnd, nullptr, nullptr, nullptr);
	}
	ITaskbarList* pTList = nullptr;	
	CoCreateInstance(CLSID_TaskbarList, NULL, CLSCTX_SERVER, IID_ITaskbarList, 
		reinterpret_cast<void**>(&pTList));
	pTList->AddTab(m_hTaskButton);
	pTList->Release();
}
