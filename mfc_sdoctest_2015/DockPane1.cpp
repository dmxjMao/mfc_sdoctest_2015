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

	//OnChangeVisualStyle();

	//m_wndToolBar.SetPaneStyle(m_wndToolBar.GetPaneStyle() | CBRS_TOOLTIPS | CBRS_FLYBY);

	//m_wndToolBar.SetPaneStyle(m_wndToolBar.GetPaneStyle() & ~(CBRS_GRIPPER | CBRS_SIZE_DYNAMIC | CBRS_BORDER_TOP | CBRS_BORDER_BOTTOM | CBRS_BORDER_LEFT | CBRS_BORDER_RIGHT));

	//m_wndToolBar.SetOwner(this);

	//// All commands will be routed via this control , not via the parent frame:
	//m_wndToolBar.SetRouteCommandsViaFrame(FALSE);

	//// Fill in some static tree view data (dummy code, nothing magic here)
	//FillFileView();
	//AdjustLayout();

	return 0;
}


void CDockPane1::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: Add your message handler code here
					   // Do not call CDockablePane::OnPaint() for painting messages

}


void CDockPane1::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
}
