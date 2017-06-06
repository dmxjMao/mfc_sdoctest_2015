
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
END_MESSAGE_MAP()

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

void Cmfc_sdoctest_2015View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	//theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
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
