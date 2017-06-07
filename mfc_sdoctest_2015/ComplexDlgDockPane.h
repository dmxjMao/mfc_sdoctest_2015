#pragma once

// CDpComplexDlg dialog

class CDpComplexDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CDpComplexDlg)
	DECLARE_MESSAGE_MAP()
public:
	CDpComplexDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDpComplexDlg();

	// Dialog Data
//#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_dp_complex };
//#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
public:
	afx_msg void OnClickedButton1();
};

// CComplexDlgDockPane

class CComplexDlgDockPane : public CDockablePane
{
	DECLARE_DYNAMIC(CComplexDlgDockPane)
	DECLARE_MESSAGE_MAP()
public:
	CComplexDlgDockPane();
	virtual ~CComplexDlgDockPane();

protected:
	CDpComplexDlg m_dlg;
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};


