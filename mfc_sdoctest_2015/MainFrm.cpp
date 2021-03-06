
// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "mfc_sdoctest_2015.h"

//#include "mfc_sdoctest_2015View.h"
#include "MainFrm.h"

#include "SimpleDlgDockPane.h"
#include "ComplexDlgDockPane.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define IDC_SimpleDlgPane		100
#define IDC_ComplexDlgPane		101

#if !defined(OBM_CHECK)
#define OBM_CHECK 32760
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWndEx)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWndEx)
	ON_WM_CREATE()
	ON_COMMAND(ID_VIEW_CUSTOMIZE, &CMainFrame::OnViewCustomize)
	ON_REGISTERED_MESSAGE(AFX_WM_CREATETOOLBAR, &CMainFrame::OnToolbarCreateNew)
	ON_WM_MEASUREITEM()
	ON_WM_DRAWITEM()
	//ON_WM_CONTEXTMENU()
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
	EnableDocking(CBRS_ALIGN_ANY);
	//DockPane(&m_wndMenuBar);
	//DockPane(&m_wndToolBar);
	//DockPane(&m_tbGfxm);
	//DockPaneLeftOf(&m_wndToolBar, &m_tbGfxm);


	// enable Visual Studio 2005 style docking window behavior
	//CDockingManager::SetDockingMode(DT_SMART);
	// enable Visual Studio 2005 style docking window auto-hide behavior
	//EnableAutoHidePanes(CBRS_ALIGN_ANY);

	// set the visual manager used to draw all user interface elements
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerVS2008));
	//CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerOffice2007));

	// Enable toolbar and docking window menu replacement
	//EnablePaneMenu(TRUE, ID_VIEW_CUSTOMIZE, strCustomize, ID_VIEW_TOOLBAR);

	// enable quick (Alt+drag) toolbar customization
	//CMFCToolBar::EnableQuickCustomization();
	BOOL b = CMFCToolBar::AddToolBarForImageCollection(IDR_MENU_IMAGES, IDB_MENU_IMAGES_24);


	//BOOL bRet = m_dp1.Create(_T("dp1"), this, CRect(0, 0, 200, 500), TRUE, ID_dp1,
	//	WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS 
	//	| WS_CLIPCHILDREN | CBRS_LEFT/*| CBRS_FLOAT_MULTI*/);
	////m_dp1.SetPaneStyle(m_dp1.GetPaneStyle() | AFX_CBRS_AUTOHIDE);
	//m_dp1.EnableDocking(CBRS_ALIGN_ANY);
	//DockPane(&m_dp1);


	//bRet = m_dp2.Create(_T("dp2"), this, CRect(0, 0, 200, 500), TRUE, ID_dp2,
	//	WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS
	//	| WS_CLIPCHILDREN | CBRS_LEFT/*| CBRS_FLOAT_MULTI*/);
	////m_dp1.SetPaneStyle(m_dp1.GetPaneStyle() | AFX_CBRS_AUTOHIDE);
	//m_dp2.EnableDocking(CBRS_ALIGN_ANY);
	////DockPane(&m_dp2);
	//CDockablePane* pTabbedBar = NULL;
	//m_dp2.AttachToTabWnd(&m_dp1, DM_SHOW, TRUE, &pTabbedBar);

	//bRet = m_dp3.Create(_T("dp3"), this, CRect(0, 0, 100, 100), TRUE, ID_dp3,
	//	WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS
	//	| WS_CLIPCHILDREN | CBRS_BOTTOM);
	//m_dp3.EnableDocking(CBRS_ALIGN_BOTTOM);
	//DockPane(&m_dp3);

	//if(!m_simpledlg_dp)
	//	m_simpledlg_dp = std::make_shared<CSimpleDlgDockPane>();
	//DWORD style = WS_CHILD | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | CBRS_RIGHT;
	//BOOL bRet = m_simpledlg_dp->Create(_T("simple dialog pane"), this, CRect(0, 0, 200, 500), 
	//	TRUE, IDC_SimpleDlgPane, style, AFX_CBRS_OUTLOOK_TABS);
	//m_simpledlg_dp->EnableDocking(CBRS_ALIGN_ANY);
	//DockPane(m_simpledlg_dp.get());
	//m_simpledlg_dp->ShowPane(TRUE, FALSE, TRUE);
	////RecalcLayout();

	//if (!m_complexdlg_dp)
	//	m_complexdlg_dp = std::make_shared<CComplexDlgDockPane>();
	////AFX_CBRS_AUTO_ROLLUP
	//bRet = m_complexdlg_dp->Create(_T("complex dialog pane"), this, CRect(0, 0, 200, 500),
	//	TRUE, IDC_ComplexDlgPane, style, AFX_CBRS_OUTLOOK_TABS);
	//m_complexdlg_dp->EnableDocking(CBRS_ALIGN_ANY);
	////DockPane(m_complexdlg_dp.get());
	//CDockablePane* pTabbedBar = NULL;
	//m_complexdlg_dp->AttachToTabWnd(m_simpledlg_dp.get(), DM_SHOW, FALSE, &pTabbedBar);
	//m_complexdlg_dp->ShowPane(TRUE, FALSE, TRUE);
	//RecalcLayout();

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
	//cs.hMenu = NULL;

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



void CMainFrame::OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct)
{
	// TODO: Add your message handler code here and/or call default
	if (ODT_MENU == lpMeasureItemStruct->CtlType) {
		lpMeasureItemStruct->itemWidth = ::GetSystemMetrics(SM_CYMENU);
		lpMeasureItemStruct->itemHeight = ::GetSystemMetrics(SM_CYMENU);
	}

	//CFrameWndEx::OnMeasureItem(nIDCtl, lpMeasureItemStruct);
}



void CMainFrame::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpdis)
{
	// TODO: Add your message handler code here and/or call default
	BITMAP bm;
	CBitmap bitmap;
	bitmap.LoadOEMBitmap(OBM_CHECK);
	bitmap.GetObject(sizeof(bm), &bm);

	CDC dc;
	dc.Attach(lpdis->hDC);

	CBrush* pBrush = new CBrush(::GetSysColor((lpdis->itemState & ODS_SELECTED) ? COLOR_HIGHLIGHT : COLOR_MENU));
	dc.FrameRect(&(lpdis->rcItem), pBrush);
	delete pBrush; pBrush = 0;

	static COLORREF colors[3] = {
		RGB(255,0,0),
		RGB(0,255,0),
		RGB(0,0,255)
	};

	if (lpdis->itemState & ODS_CHECKED) {
		CDC dcMem;
		dcMem.CreateCompatibleDC(&dc);
		CBitmap* pOldBitmap = dcMem.SelectObject(&bitmap);
		dc.BitBlt(lpdis->rcItem.left + 4, lpdis->rcItem.top +
			(((lpdis->rcItem.bottom - lpdis->rcItem.top) - bm.bmHeight) / 2),
			bm.bmWidth, bm.bmHeight, &dcMem, 0, 0, SRCCOPY);
		dcMem.SelectObject(pOldBitmap);
	}

	UINT itemID = lpdis->itemID;
	//Cmfc_sdoctest_2015View* pView = (Cmfc_sdoctest_2015View*)GetActiveView();
	pBrush = new CBrush(colors[itemID - ID_SORTING_RED]/*pView->m_colors[itemID - ID_SORTING_RED]*/);
	CRect rect = lpdis->rcItem;
	rect.DeflateRect(6, 4);
	rect.left += bm.bmWidth;
	dc.FillRect(rect, pBrush);
	delete pBrush; pBrush = 0;

	dc.Detach();
	//CFrameWndEx::OnDrawItem(nIDCtl, lpdis);
}


//void CMainFrame::OnContextMenu(CWnd* /*pWnd*/, CPoint pt)
//{
//	// TODO: Add your message handler code here
//	CMenu m;
//	m.LoadMenu(IDR_POPUP_SORT);
//	CMenu* pMenu = m.GetSubMenu(0);
//
//	pMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_LEFTBUTTON, pt.x, pt.y, AfxGetMainWnd());
//}
