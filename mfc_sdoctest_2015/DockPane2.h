#pragma once

class CClassToolBar : public CMFCToolBar
{
	virtual void OnUpdateCmdUI(CFrameWnd* /*pTarget*/, BOOL bDisableIfNoHndler)
	{
		CMFCToolBar::OnUpdateCmdUI((CFrameWnd*)GetOwner(), bDisableIfNoHndler);
	}

	virtual BOOL AllowShowOnList() const { return FALSE; }
};



// CDockPane2

class CDockPane2 : public CDockablePane
{

public:
	CDockPane2();
	virtual ~CDockPane2();
	virtual void AdjustLayout();

protected:
	CClassToolBar m_wndToolBar;
	CTreeCtrl m_wndClassView;
	CImageList m_ClassViewImages;
	UINT m_nCurrSort;

	void FillClassView();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};


