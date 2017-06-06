// DockPane1.cpp : implementation file
//

#include "stdafx.h"
#include "mfc_sdoctest_2015.h"
#include "DockPane1.h"


BEGIN_MESSAGE_MAP(CDockPane1TreeCtrl, CTreeCtrl)
END_MESSAGE_MAP()

// CDockPane1

CDockPane1::CDockPane1()
{

}

CDockPane1::~CDockPane1()
{
}


BEGIN_MESSAGE_MAP(CDockPane1, CDockablePane)
	ON_WM_CREATE()
	ON_WM_PAINT()
	ON_WM_SIZE()
	ON_COMMAND(ID_PROPERTIES, &CDockPane1::OnProperties)
END_MESSAGE_MAP()



// CDockPane1 message handlers




int CDockPane1::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	CRect rectDummy;
	rectDummy.SetRectEmpty();

	// Create view:
	const DWORD dwViewStyle = WS_CHILD | WS_VISIBLE | TVS_HASLINES | TVS_LINESATROOT | TVS_HASBUTTONS;

	if (!m_tree.Create(dwViewStyle, rectDummy, this, 4))
	{
		TRACE0("Failed to create file view\n");
		return -1;      // fail to create
	}

	// Load view images:
	m_imglist.Create(IDB_FILE_VIEW_24, 16, 0, RGB(255, 0, 255));
	m_tree.SetImageList(&m_imglist, TVSIL_NORMAL);

	m_toolbar.Create(this, AFX_DEFAULT_TOOLBAR_STYLE, IDR_EXPLORER);
	m_toolbar.LoadToolBar(IDR_EXPLORER, 0, 0, TRUE /* Is locked */);

	m_toolbar.CleanUpLockedImages();
	m_toolbar.LoadBitmap(IDB_EXPLORER_24, 0, 0, TRUE /* Locked */);

	m_toolbar.SetPaneStyle(m_toolbar.GetPaneStyle() | CBRS_TOOLTIPS | CBRS_FLYBY);

	m_toolbar.SetPaneStyle(m_toolbar.GetPaneStyle() & ~(CBRS_GRIPPER | CBRS_SIZE_DYNAMIC | CBRS_BORDER_TOP | CBRS_BORDER_BOTTOM | CBRS_BORDER_LEFT | CBRS_BORDER_RIGHT));

	m_toolbar.SetOwner(this);

	// All commands will be routed via this control , not via the parent frame:
	m_toolbar.SetRouteCommandsViaFrame(FALSE);

	// Fill in some static tree view data (dummy code, nothing magic here)
	FillFileView();
	AdjustLayout();

	return 0;
}


void CDockPane1::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: Add your message handler code here
					   // Do not call CDockablePane::OnPaint() for painting messages
	CRect rectTree;
	m_tree.GetWindowRect(rectTree);
	ScreenToClient(rectTree);

	rectTree.InflateRect(1, 1);
	//dc.Draw3dRect(rectTree, ::GetSysColor(COLOR_3DSHADOW), ::GetSysColor(COLOR_3DSHADOW));
}


void CDockPane1::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	AdjustLayout();
}



void CDockPane1::FillFileView()
{
	HTREEITEM hRoot = m_tree.InsertItem(_T("FakeApp files"), 0, 0);
	m_tree.SetItemState(hRoot, TVIS_BOLD, TVIS_BOLD);

	HTREEITEM hSrc = m_tree.InsertItem(_T("FakeApp Source Files"), 0, 0, hRoot);

	m_tree.InsertItem(_T("FakeApp.cpp"), 1, 1, hSrc);
	m_tree.InsertItem(_T("FakeApp.rc"), 1, 1, hSrc);
	m_tree.InsertItem(_T("FakeAppDoc.cpp"), 1, 1, hSrc);
	m_tree.InsertItem(_T("FakeAppView.cpp"), 1, 1, hSrc);
	m_tree.InsertItem(_T("MainFrm.cpp"), 1, 1, hSrc);
	m_tree.InsertItem(_T("StdAfx.cpp"), 1, 1, hSrc);

	HTREEITEM hInc = m_tree.InsertItem(_T("FakeApp Header Files"), 0, 0, hRoot);

	m_tree.InsertItem(_T("FakeApp.h"), 2, 2, hInc);
	m_tree.InsertItem(_T("FakeAppDoc.h"), 2, 2, hInc);
	m_tree.InsertItem(_T("FakeAppView.h"), 2, 2, hInc);
	m_tree.InsertItem(_T("Resource.h"), 2, 2, hInc);
	m_tree.InsertItem(_T("MainFrm.h"), 2, 2, hInc);
	m_tree.InsertItem(_T("StdAfx.h"), 2, 2, hInc);

	HTREEITEM hRes = m_tree.InsertItem(_T("FakeApp Resource Files"), 0, 0, hRoot);

	m_tree.InsertItem(_T("FakeApp.ico"), 2, 2, hRes);
	m_tree.InsertItem(_T("FakeApp.rc2"), 2, 2, hRes);
	m_tree.InsertItem(_T("FakeAppDoc.ico"), 2, 2, hRes);
	m_tree.InsertItem(_T("FakeToolbar.bmp"), 2, 2, hRes);

	m_tree.Expand(hRoot, TVE_EXPAND);
	m_tree.Expand(hSrc, TVE_EXPAND);
	m_tree.Expand(hInc, TVE_EXPAND);
}



void CDockPane1::AdjustLayout()
{
	if (GetSafeHwnd() == NULL)
	{
		return;
	}

	CRect rectClient;
	GetClientRect(rectClient);

	int cyTlb = m_toolbar.CalcFixedLayout(FALSE, TRUE).cy;

	m_toolbar.SetWindowPos(NULL, rectClient.left, rectClient.top, rectClient.Width(), cyTlb, SWP_NOACTIVATE | SWP_NOZORDER);
	m_tree.SetWindowPos(NULL, rectClient.left + 1, rectClient.top + cyTlb + 1, rectClient.Width() - 2, rectClient.Height() - cyTlb - 2, SWP_NOACTIVATE | SWP_NOZORDER);
}

void CDockPane1::OnProperties()
{
	// TODO: Add your command handler code here
	AfxMessageBox(_T("you click me!"));
}
