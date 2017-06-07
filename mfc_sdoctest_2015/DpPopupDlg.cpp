// DpPopupDlg.cpp : implementation file
//

#include "stdafx.h"
#include "mfc_sdoctest_2015.h"
#include "DpPopupDlg.h"
#include "afxdialogex.h"


// CDpPopupDlg dialog

IMPLEMENT_DYNAMIC(CDpPopupDlg, CDialogEx)

CDpPopupDlg::CDpPopupDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_popup, pParent)
{

}

CDpPopupDlg::~CDpPopupDlg()
{
}

void CDpPopupDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDpPopupDlg, CDialogEx)
END_MESSAGE_MAP()


// CDpPopupDlg message handlers
