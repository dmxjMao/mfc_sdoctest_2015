
// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "mfc_sdoctest_2015.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWndEx)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWndEx)
	ON_WM_CREATE()
	ON_COMMAND(ID_VIEW_CUSTOMIZE, &CMainFrame::OnViewCustomize)
	ON_REGISTERED_MESSAGE(AFX_WM_CREATETOOLBAR, &CMainFrame::OnToolbarCreateNew)
END_MESSAGE_MAP()

// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWndEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	//BOOL bNameValid;

	//if (!m_wndMenuBar.Create(this))
	//{
	//	TRACE0("Failed to create menubar\n");
	//	return -1;      // fail to create
	//}

	//m_wndMenuBar.SetPaneStyle(m_wndMenuBar.GetPaneStyle() | CBRS_SIZE_DYNAMIC | CBRS_TOOLTIPS | CBRS_FLYBY);

	//// prevent the menu bar from taking the focus on activation
	//CMFCPopupMenu::SetForceMenuFocus(FALSE);


	//TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC
	//if (!m_wndToolBar.CreateEx(this) ||
	//	!m_wndToolBar.LoadToolBar(theApp.m_bHiColorIcons ? IDR_MAINFRAME_256 : IDR_MAINFRAME))
	//{
	//	TRACE0("Failed to create toolbar\n");
	//	return -1;      // fail to create
	//}
	//m_wndToolBar.SetWindowText(/*strToolBarName*/_T("����"));
	//m_wndToolBar.SetPaneStyle(m_wndToolBar)
	
	//AFX_DEFAULT_TOOLBAR_STYLE | CBRS_HIDE_INPLACE
	//m_tbGfxm.CreateEx(this);
	////m_tbGfxm.SetPaneStyle(m_tbGfxm.GetPaneStyle() &~ CBRS_TOOLTIPS);
	//m_tbGfxm.LoadToolBar(IDR_tbGfxm);

	//m_tbGfxm.SetWindowText(_T("���"));
	//m_tbGfxm.EnableDocking(CBRS_ALIGN_TOP);

	//CString strToolBarName;
	//bNameValid = strToolBarName.LoadString(IDS_TOOLBAR_STANDARD);
	//ASSERT(bNameValid);
	

	// TODO: Delete these five lines if you don't want the toolbar and menubar to be dockable
	//m_wndMenuBar.EnableDocking(CBRS_ALIGN_ANY);
	////m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	//EnableDocking(CBRS_ALIGN_ANY);
	//DockPane(&m_wndMenuBar);
	//DockPane(&m_wndToolBar);
	//DockPane(&m_tbGfxm);
	//DockPaneLeftOf(&m_wndToolBar, &m_tbGfxm);


	// enable Visual Studio 2005 style docking window behavior
	CDockingManager::SetDockingMode(DT_SMART);
	// enable Visual Studio 2005 style docking window auto-hide behavior
	//EnableAutoHidePanes(CBRS_ALIGN_ANY);

	// set the visual manager used to draw all user interface elements
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerVS2008));

	// Enable toolbar and docking window menu replacement
	//EnablePaneMenu(TRUE, ID_VIEW_CUSTOMIZE, strCustomize, ID_VIEW_TOOLBAR);

	// enable quick (Alt+drag) toolbar customization
	//CMFCToolBar::EnableQuickCustomization();

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWndEx::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	cs.style =/* WS_OVERLAPPED | WS_CAPTION | FWS_ADDTOTITLE
		 | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX*/
	WS_OVERLAPPEDWINDOW;
	cs.hMenu = NULL;

	return TRUE;
}

// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWndEx::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWndEx::Dump(dc);
}
#endif //_DEBUG


// CMainFrame message handlers

void CMainFrame::OnViewCustomize()
{
	CMFCToolBarsCustomizeDialog* pDlgCust = new CMFCToolBarsCustomizeDialog(this, TRUE /* scan menus */);
	pDlgCust->Create();
}

LRESULT CMainFrame::OnToolbarCreateNew(WPARAM wp,LPARAM lp)
{
	LRESULT lres = CFrameWndEx::OnToolbarCreateNew(wp,lp);
	if (lres == 0)
	{
		return 0;
	}

	CMFCToolBar* pUserToolbar = (CMFCToolBar*)lres;
	ASSERT_VALID(pUserToolbar);

	BOOL bNameValid;
	CString strCustomize;
	bNameValid = strCustomize.LoadString(IDS_TOOLBAR_CUSTOMIZE);
	ASSERT(bNameValid);

	pUserToolbar->EnableCustomizeButton(TRUE, ID_VIEW_CUSTOMIZE, strCustomize);
	return lres;
}

