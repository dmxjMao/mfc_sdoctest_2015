
// mfc_sdoctest_2015View.cpp : implementation of the Cmfc_sdoctest_2015View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "mfc_sdoctest_2015.h"
#endif

#include "mfc_sdoctest_2015Doc.h"
#include "mfc_sdoctest_2015View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cmfc_sdoctest_2015View

IMPLEMENT_DYNCREATE(Cmfc_sdoctest_2015View, CView)

BEGIN_MESSAGE_MAP(Cmfc_sdoctest_2015View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND_RANGE(ID_SORTING_RED, ID_SORTING_BLUE+1, OnColor)
	ON_UPDATE_COMMAND_UI_RANGE(ID_SORTING_RED, ID_SORTING_BLUE+1, OnUpdateColor)
END_MESSAGE_MAP()

const COLORREF Cmfc_sdoctest_2015View::m_colors[3] = {
	RGB(255,0,0),
	RGB(0,255,0),
	RGB(0,0,255)
};

// Cmfc_sdoctest_2015View construction/destruction

Cmfc_sdoctest_2015View::Cmfc_sdoctest_2015View()
{
	// TODO: add construction code here

}

Cmfc_sdoctest_2015View::~Cmfc_sdoctest_2015View()
{
}

BOOL Cmfc_sdoctest_2015View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Cmfc_sdoctest_2015View drawing

void Cmfc_sdoctest_2015View::OnDraw(CDC* /*pDC*/)
{
	Cmfc_sdoctest_2015Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}

void Cmfc_sdoctest_2015View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cmfc_sdoctest_2015View::OnContextMenu(CWnd* /* pWnd */, CPoint pt)
{
#ifndef SHARED_HANDLERS
	//theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
	CMenu m;
	m.LoadMenu(IDR_POPUP_SORT);
	CMenu* pMenu = m.GetSubMenu(0);

	for (int i = 0; i < 3; ++i) {
		pMenu->ModifyMenu(ID_SORTING_RED + i, MF_BYCOMMAND | MF_OWNERDRAW, ID_SORTING_RED + i);
	}
	pMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_LEFTBUTTON, pt.x, pt.y, AfxGetMainWnd());
}


// Cmfc_sdoctest_2015View diagnostics

#ifdef _DEBUG
void Cmfc_sdoctest_2015View::AssertValid() const
{
	CView::AssertValid();
}

void Cmfc_sdoctest_2015View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cmfc_sdoctest_2015Doc* Cmfc_sdoctest_2015View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cmfc_sdoctest_2015Doc)));
	return (Cmfc_sdoctest_2015Doc*)m_pDocument;
}
#endif //_DEBUG


// Cmfc_sdoctest_2015View message handlers
void Cmfc_sdoctest_2015View::OnColor(UINT nID)
{
	m_nColor = nID - ID_SORTING_RED;
	Invalidate();
}

void Cmfc_sdoctest_2015View::OnUpdateColor(CCmdUI* pCmdUI)
{
	int nCheck = pCmdUI->m_nID - ID_SORTING_RED == m_nColor;
	pCmdUI->SetCheck(nCheck);
}