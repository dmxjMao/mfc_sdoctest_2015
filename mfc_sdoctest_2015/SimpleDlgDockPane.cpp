// SimpleDlgDockPane.cpp : implementation file
//

#include "stdafx.h"
#include "mfc_sdoctest_2015.h"
#include "SimpleDlgDockPane.h"


// CDpSimpleDlg dialog

IMPLEMENT_DYNAMIC(CDpSimpleDlg, CDialogEx)

CDpSimpleDlg::CDpSimpleDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_dp_simple, pParent)
{

}

CDpSimpleDlg::~CDpSimpleDlg()
{
}

void CDpSimpleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDpSimpleDlg, CDialogEx)
END_MESSAGE_MAP()


// CSimpleDlgDockPane

IMPLEMENT_DYNAMIC(CSimpleDlgDockPane, CDockablePane)

CSimpleDlgDockPane::CSimpleDlgDockPane()
{

}

CSimpleDlgDockPane::~CSimpleDlgDockPane()
{
}


BEGIN_MESSAGE_MAP(CSimpleDlgDockPane, CDockablePane)
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()



// CSimpleDlgDockPane message handlers




int CSimpleDlgDockPane::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	if (!m_dlg.Create(CDpSimpleDlg::IDD, this))
		return -1;
	m_dlg.ShowWindow(SW_SHOWDEFAULT);

	return 0;
}


void CSimpleDlgDockPane::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	m_dlg.SetWindowPos(NULL, 0, 0, cx, cy, SWP_NOACTIVATE | SWP_NOMOVE | SWP_NOZORDER);
}
