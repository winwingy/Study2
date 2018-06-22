
// clipBoardMineDataDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "clipBoardMineData.h"
#include "clipBoardMineDataDlg.h"
#include "afxdialogex.h"
#include <windowsx.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


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


// CclipBoardMineDataDlg 对话框




CclipBoardMineDataDlg::CclipBoardMineDataDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CclipBoardMineDataDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CclipBoardMineDataDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_SHOW, m_staticShow);
	DDX_Control(pDX, IDC_STATIC_SHOW2, m_staticBitmap);
}

BEGIN_MESSAGE_MAP(CclipBoardMineDataDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CclipBoardMineDataDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CclipBoardMineDataDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CclipBoardMineDataDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CclipBoardMineDataDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CclipBoardMineDataDlg 消息处理程序

BOOL CclipBoardMineDataDlg::OnInitDialog()
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

void CclipBoardMineDataDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CclipBoardMineDataDlg::OnPaint()
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
		// win32 dc
		{
// 			PAINTSTRUCT ps;
// 			HDC dc = ::BeginPaint(m_hWnd, &ps);
// 
// 			HDC memDc = CreateCompatibleDC(dc);
// 			RECT rcMem = {0, 0, 200, 200};
// 			HBITMAP bitmap = CreateCompatibleBitmap(dc, 200, 200);
// 			SelectBitmap(memDc, bitmap);
// 
// 			HBRUSH bru = CreateSolidBrush(RGB(0, 255, 0));
// 			FillRect(memDc, &rcMem, bru); //(HBRUSH)::GetStockObject(NULL_BRUSH));
// 			HPEN pen = ::CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
// 			SelectPen(memDc, pen);
// 			::Rectangle(memDc, 10, 10, 100, 100);
// 			::Ellipse(memDc, 50, 50, 150, 150);
// 
// 			::BitBlt(dc, 100, 100, 300, 300, memDc, 0, 0, SRCCOPY);
// 
// 			DeleteBrush(bru);
// 			DeletePen(pen);
// 			DeleteDC(memDc);
// 
// 			::EndPaint(m_hWnd, &ps);
		}
// 
// 		{
// 
// 			CPaintDC dc(this);
// 			CDC dcCp;
// 			dcCp.CreateCompatibleDC(&dc);
// 			RECT rc = {200, 100, 350, 200};
// 			dcCp.DrawText(L"CompatibleDC", &rc, DT_LEFT);
// 
// 			RECT rc2 = {200, 200, 350, 300};
// 			dc.DrawText(L"CompatibleDC222", &rc2, DT_LEFT);
// 			CDialogEx::OnPaint();
// 		}
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CclipBoardMineDataDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CclipBoardMineDataDlg::OnBnClickedButton1()
{
	if (OpenClipboard())
	{
		EmptyClipboard();
		CMetaFileDC* pDc = new CMetaFileDC;
		pDc->CreateEnhanced(GetDC(), NULL, NULL, L"my Draw DC");
		RECT rc = {0, 0, 100, 20};
		pDc->DrawText(L"Hello Clipboard Mine", &rc, DT_LEFT);
		HENHMETAFILE handle =  pDc->CloseEnhanced();

		SetClipboardData(CF_ENHMETAFILE, handle);
		CloseClipboard();

		delete pDc;
	}
}


void CclipBoardMineDataDlg::OnBnClickedButton2()
{
	if (OpenClipboard())
	{
		HENHMETAFILE handle = (HENHMETAFILE)GetClipboardData(CF_ENHMETAFILE);

		LONG_PTR oldStyle = GetWindowLongPtr(m_staticShow.GetSafeHwnd(), GWL_STYLE);
		SetWindowLongPtr(m_staticShow.m_hWnd,GWL_STYLE, oldStyle|SS_ENHMETAFILE);

		m_staticShow.SetEnhMetaFile(handle);
		HENHMETAFILE newHandle = m_staticShow.GetEnhMetaFile();

		CloseClipboard();		

	}
}


void CclipBoardMineDataDlg::OnBnClickedButton3()
{
	if (OpenClipboard())
	{
		EmptyClipboard();
		CBitmap* bitmap = new CBitmap;
		CClientDC cdc(this);
		CDC memDC;
		memDC.CreateCompatibleDC(&cdc);
		CRect rc(0, 0, 200, 200);
		bitmap->CreateCompatibleBitmap(&cdc, rc.Width(), rc.Height());

		memDC.SelectObject(bitmap);
		CBrush bru;
		bru.CreateSysColorBrush(NULL_BRUSH);
		memDC.FillRect(&rc, &bru);
		memDC.DrawText(L"HEllo Bitmap", &rc, DT_LEFT);
		SetClipboardData(CF_BITMAP, bitmap->m_hObject);
		CloseClipboard();
		delete bitmap;
	}
}




void CclipBoardMineDataDlg::OnBnClickedButton4()
{
	if (OpenClipboard())
	{
		HBITMAP bit = (HBITMAP)GetClipboardData(CF_BITMAP);
		
		LONG_PTR oldStyle = GetWindowLongPtr(m_staticBitmap.GetSafeHwnd(), GWL_STYLE);
		SetWindowLongPtr(m_staticBitmap.GetSafeHwnd(), GWL_STYLE, oldStyle|SS_BITMAP);

		m_staticBitmap.SetBitmap(bit);
		CloseClipboard();
	}
}
