
// 0903TaskBarMessageDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "0903TaskBarMessage.h"
#include "0903TaskBarMessageDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
UINT g_uSHellRestart;

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
END_MESSAGE_MAP()


// CMy0903TaskBarMessageDlg �Ի���




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


// CMy0903TaskBarMessageDlg ��Ϣ�������

BOOL CMy0903TaskBarMessageDlg::OnInitDialog()
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

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMy0903TaskBarMessageDlg::OnPaint()
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
HCURSOR CMy0903TaskBarMessageDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy0903TaskBarMessageDlg::OnBnClickedButtonInittaskbarmessage()
{
	
	g_uSHellRestart = RegisterWindowMessage(L"TaskbarCreated");
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
