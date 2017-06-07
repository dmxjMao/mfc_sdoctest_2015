// DockPane3.cpp : implementation file
//

#include "stdafx.h"
#include "mfc_sdoctest_2015.h"
#include "DockPane3.h"


// CDockPane3


CDockPane3::CDockPane3()
{

}

CDockPane3::~CDockPane3()
{
}


BEGIN_MESSAGE_MAP(CDockPane3, CDockablePane)
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()



// CDockPane3 message handlers




int CDockPane3::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	CRect rectDummy;
	rectDummy.SetRectEmpty();
	m_tab.Create(CMFCTabCtrl::STYLE_FLAT, rectDummy, this, 1);

	const DWORD dwStyle = LBS_NOINTEGRALHEIGHT | WS_CHILD | WS_VISIBLE | WS_HSCROLL | WS_VSCROLL;
	m_lb1.Create(dwStyle, rectDummy, &m_tab, 2);
	m_lb2.Create(dwStyle, rectDummy, &m_tab, 3);

	m_tab.AddTab(&m_lb1, _T("lb1"), 0);
	m_tab.AddTab(&m_lb2, _T("lb2"), 1);

	CString tmpStr;
	for (int i = 0; i < 10; ++i) {
		tmpStr.Format(_T("%d + %d = %d"), i, i, 2 * i);
		m_lb1.AddString(tmpStr);

		tmpStr.Format(_T("here is %d line"), i + 1);
		m_lb2.AddString(tmpStr);
	}


	return 0;
}


void CDockPane3::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	m_tab.SetWindowPos(NULL, -1, -1, cx, cy, SWP_NOMOVE | SWP_NOACTIVATE | SWP_NOZORDER);
}
