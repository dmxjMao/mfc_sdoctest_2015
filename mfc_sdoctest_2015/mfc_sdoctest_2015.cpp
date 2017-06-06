
// mfc_sdoctest_2015.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "mfc_sdoctest_2015.h"
#include "MainFrm.h"

#include "mfc_sdoctest_2015Doc.h"
#include "mfc_sdoctest_2015View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cmfc_sdoctest_2015App

BEGIN_MESSAGE_MAP(Cmfc_sdoctest_2015App, CWinAppEx)
	ON_COMMAND(ID_APP_ABOUT, &Cmfc_sdoctest_2015App::OnAppAbout)
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, &CWinAppEx::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinAppEx::OnFileOpen)
END_MESSAGE_MAP()


// Cmfc_sdoctest_2015App construction

Cmfc_sdoctest_2015App::Cmfc_sdoctest_2015App()
{
	m_bHiColorIcons = TRUE;

	// TODO: replace application ID string below with unique ID string; recommended
	// format for string is CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("mfc_sdoctest_2015.AppID.NoVersion"));

	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

// The one and only Cmfc_sdoctest_2015App object

Cmfc_sdoctest_2015App theApp;


// Cmfc_sdoctest_2015App initialization

BOOL Cmfc_sdoctest_2015App::InitInstance()
{
	//固定大小
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));
	//LoadStdProfileSettings(4);  // Load standard INI file options (including MRU)

	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(Cmfc_sdoctest_2015Doc),
		RUNTIME_CLASS(CMainFrame),       // main SDI frame window
		RUNTIME_CLASS(Cmfc_sdoctest_2015View));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Dispatch commands specified on the command line.  Will return FALSE if
	// app was launched with /RegServer, /Register, /Unregserver or /Unregister.
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// The one and only window has been initialized, so show and update it
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

// Cmfc_sdoctest_2015App message handlers


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// App command to run the dialog
void Cmfc_sdoctest_2015App::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// Cmfc_sdoctest_2015App customization load/save methods

void Cmfc_sdoctest_2015App::PreLoadState()
{
	//BOOL bNameValid;
	//CString strName;
	//bNameValid = strName.LoadString(IDS_EDIT_MENU);
	//ASSERT(bNameValid);
	//GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EDIT);
}

void Cmfc_sdoctest_2015App::LoadCustomState()
{
}

void Cmfc_sdoctest_2015App::SaveCustomState()
{
}

// Cmfc_sdoctest_2015App message handlers





BOOL Cmfc_sdoctest_2015App::LoadState(LPCTSTR lpszSectionName, CFrameImpl* pFrameImpl)
{
	// TODO: Add your specialized code here and/or call the base class
	//不要加载注册表信息
	return TRUE;
	//return CWinAppEx::LoadState(lpszSectionName, pFrameImpl);
}
