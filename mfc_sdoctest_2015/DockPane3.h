#pragma once


// CDockPane3

class CDockPane3 : public CDockablePane
{

public:
	CDockPane3();
	virtual ~CDockPane3();

protected:
	DECLARE_MESSAGE_MAP()

protected:
	CMFCTabCtrl m_tab;
	CListBox m_lb1;
	CListBox m_lb2;
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};


