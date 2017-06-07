#pragma once

// CDpSimpleDlg dialog

class CDpSimpleDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CDpSimpleDlg)
	DECLARE_MESSAGE_MAP()
public:
	CDpSimpleDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDpSimpleDlg();

	// Dialog Data
//#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_dp_simple };
//#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
};

// CSimpleDlgDockPane

class CSimpleDlgDockPane : public CDockablePane
{
	DECLARE_DYNAMIC(CSimpleDlgDockPane)
	DECLARE_MESSAGE_MAP()
public:
	CSimpleDlgDockPane();
	virtual ~CSimpleDlgDockPane();

protected:
	CDpSimpleDlg m_dlg;
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};


