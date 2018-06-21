
// 1201ShellOptDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "1201ShellOpt.h"
#include "1201ShellOptDlg.h"
#include "afxdialogex.h"
#include <atlbase.h>
#include <comdef.h>
#include <ExDisp.h>
#include <sstream>

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


// CMy1201ShellOptDlg 对话框




CMy1201ShellOptDlg::CMy1201ShellOptDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMy1201ShellOptDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy1201ShellOptDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMy1201ShellOptDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()

	ON_BN_CLICKED(IDC_BUTTON_FolderView, &CMy1201ShellOptDlg::OnBnClickedButtonFolderview)
	ON_BN_CLICKED(IDC_BUTTON_FolderBrowseC, &CMy1201ShellOptDlg::OnBnClickedButtonFolderbrowsec)
	ON_BN_CLICKED(IDC_BUTTON_ControlPanelItem, &CMy1201ShellOptDlg::OnBnClickedButtonControlpanelitem)
	ON_BN_CLICKED(IDC_BUTTON_Explore, &CMy1201ShellOptDlg::OnBnClickedButtonExplore)
	ON_BN_CLICKED(IDC_BUTTON_NameSpace, &CMy1201ShellOptDlg::OnBnClickedButtonNamespace)
	ON_BN_CLICKED(IDC_BUTTON_Windows, &CMy1201ShellOptDlg::OnBnClickedButtonWindows)
	ON_BN_CLICKED(IDC_BUTTON_FolderItems, &CMy1201ShellOptDlg::OnBnClickedButtonFolderitems)
	ON_BN_CLICKED(IDC_BUTTON_GetOpenFileName, &CMy1201ShellOptDlg::OnBnClickedButtonGetopenfilename)
END_MESSAGE_MAP()


// CMy1201ShellOptDlg 消息处理程序

BOOL CMy1201ShellOptDlg::OnInitDialog()
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
	CoInitialize(NULL);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMy1201ShellOptDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy1201ShellOptDlg::OnPaint()
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
HCURSOR CMy1201ShellOptDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMy1201ShellOptDlg::OnBnClickedButtonFolderview()
{
	IShellDispatch* pShellDisp = nullptr;
	HRESULT hr = CoCreateInstance(CLSID_Shell, NULL, CLSCTX_SERVER,
		IID_IShellDispatch, reinterpret_cast<LPVOID*>(&pShellDisp));


	Folder* pFolder = nullptr;
	CComVariant vRoot(CSIDL_DRIVES);
	CComBSTR bstrTitle(L"My Computer:");

	hr = pShellDisp->BrowseForFolder(reinterpret_cast<long>(m_hWnd), bstrTitle,
		0, vRoot, &pFolder);
}


void CMy1201ShellOptDlg::OnBnClickedButtonFolderbrowsec()
{
	IShellDispatch* pShellDisp = nullptr;
	HRESULT hr = CoCreateInstance(CLSID_Shell, NULL, CLSCTX_SERVER,
		IID_IShellDispatch, reinterpret_cast<LPVOID*>(&pShellDisp));


	Folder* pFolder = nullptr;
	CComVariant vRoot(L"C:");
	CComBSTR bstrTitle(L"My Computer C:");

	hr = pShellDisp->BrowseForFolder(reinterpret_cast<long>(m_hWnd), bstrTitle,
		0, vRoot, &pFolder);
}


void CMy1201ShellOptDlg::OnBnClickedButtonControlpanelitem()
{
	IShellDispatch* pShellDisp = nullptr;
	HRESULT hr = CoCreateInstance(CLSID_Shell, NULL, CLSCTX_SERVER,
		IID_IShellDispatch, reinterpret_cast<LPVOID*>(&pShellDisp));

	// 无效果
	CComBSTR bstr(L"desk.cp");
	hr = pShellDisp->ControlPanelItem(bstr);
}


void CMy1201ShellOptDlg::OnBnClickedButtonExplore()
{
	IShellDispatch* pShellDisp = nullptr;
	HRESULT hr = CoCreateInstance(CLSID_Shell, NULL, CLSCTX_SERVER,
		IID_IShellDispatch, reinterpret_cast<LPVOID*>(&pShellDisp));

	CComVariant vDir(CSIDL_HISTORY);
	hr = pShellDisp->Explore(vDir);
}


void CMy1201ShellOptDlg::OnBnClickedButtonNamespace()
{
	IShellDispatch* pShellDisp = nullptr;
	HRESULT hr = CoCreateInstance(CLSID_Shell, NULL, CLSCTX_SERVER,
		IID_IShellDispatch, reinterpret_cast<LPVOID*>(&pShellDisp));

	Folder* pFolder = nullptr;
	CComVariant vDir("D:\\test");
	pShellDisp->NameSpace(vDir, &pFolder);
	CComBSTR bs;
	pFolder->get_Title(&bs);
	pFolder->Release();

	pShellDisp->Release();
}


void CMy1201ShellOptDlg::OnBnClickedButtonWindows()
{
	IShellDispatch* pShellDisp = nullptr;
	HRESULT hr = CoCreateInstance(CLSID_Shell, NULL, CLSCTX_SERVER,
		IID_IShellDispatch, reinterpret_cast<LPVOID*>(&pShellDisp));

	IDispatch* pDis = nullptr;
	hr = pShellDisp->Windows(&pDis);
	UINT out = 0;
	hr = pDis->GetTypeInfoCount(&out);
	pDis->Release();
}


void CMy1201ShellOptDlg::OnBnClickedButtonFolderitems()
{
	IShellDispatch* pShellDisp = nullptr;
	HRESULT hr = CoCreateInstance(CLSID_Shell, NULL, CLSCTX_SERVER,
		IID_IShellDispatch, reinterpret_cast<LPVOID*>(&pShellDisp));

	Folder* pFolder = nullptr;
	CComVariant vDir("D:\\test");
	pShellDisp->NameSpace(vDir, &pFolder);
	
	FolderItems* pItems = nullptr;
	pFolder->Items(&pItems);

	long count = 0;
	pItems->get_Count(&count);

	for (int i = 0; i < count; ++i)
	{
		FolderItem* pItem = nullptr;
		CComVariant var(i);
		hr = pItems->Item(var, &pItem);
		CComBSTR name;
		pItem->get_Name(&name);
		long size = 0;
		pItem->get_Size(&size);
		std::wstringstream ss;
		ss << L"name: " << name.m_str << L"  size: " <<size  << L"\n";	
		OutputDebugString(ss.str().c_str());
		pItem->Release();
	}
	pItems->Release();

	pFolder->Release();

	pShellDisp->Release();
}


void CMy1201ShellOptDlg::OnBnClickedButtonGetopenfilename()
{
	OPENFILENAME opfn = {0};	
}
