
// clipBoardMineDataDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "clipBoardMineData.h"
#include "clipBoardMineDataDlg.h"
#include "afxdialogex.h"
#include <windowsx.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


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


// CclipBoardMineDataDlg �Ի���




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


// CclipBoardMineDataDlg ��Ϣ�������

BOOL CclipBoardMineDataDlg::OnInitDialog()
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CclipBoardMineDataDlg::OnPaint()
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

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
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
