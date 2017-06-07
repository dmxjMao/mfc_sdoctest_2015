#pragma once


// CDpPopupDlg dialog

class CDpPopupDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CDpPopupDlg)

public:
	CDpPopupDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDpPopupDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_popup };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
