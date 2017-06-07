// ComplexDlgDockPane.cpp : implementation file
//

#include "stdafx.h"
#include "mfc_sdoctest_2015.h"
#include "ComplexDlgDockPane.h"

#include "DpPopupDlg.h"

IMPLEMENT_DYNAMIC(CDpComplexDlg, CDialogEx)

CDpComplexDlg::CDpComplexDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_dp_complex, pParent)
{

}

CDpComplexDlg::~CDpComplexDlg()
{
}

void CDpComplexDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDpComplexDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDpComplexDlg::OnClickedButton1)
END_MESSAGE_MAP()


// CComplexDlgDockPane

IMPLEMENT_DYNAMIC(CComplexDlgDockPane, CDockablePane)

CComplexDlgDockPane::CComplexDlgDockPane()
{

}

CComplexDlgDockPane::~CComplexDlgDockPane()
{
}


BEGIN_MESSAGE_MAP(CComplexDlgDockPane, CDockablePane)
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()



// CComplexDlgDockPane message handlers




int CComplexDlgDockPane::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	if (!m_dlg.Create(CDpComplexDlg::IDD, this))
		return -1;
	m_dlg.ShowWindow(SW_SHOWDEFAULT);

	return 0;
}


void CComplexDlgDockPane::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	m_dlg.SetWindowPos(NULL, 0, 0, cx, cy, SWP_NOMOVE | SWP_NOACTIVATE | SWP_NOZORDER);
}


void CDpComplexDlg::OnClickedButton1()
{
	// TODO: Add your control notification handler code here
	CDpPopupDlg dlg;
	dlg.DoModal();
}
