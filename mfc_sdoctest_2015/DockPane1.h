#pragma once


class CDockPane1ToolBar : public CMFCToolBar
{
	virtual void OnUpdateCmdUI(CFrameWnd* /*pTarget*/, BOOL bDisableIfNoHndler)
	{
		CMFCToolBar::OnUpdateCmdUI((CFrameWnd*)GetOwner(), bDisableIfNoHndler);
	}

	//virtual BOOL AllowShowOnList() const { return FALSE; }
};

class CDockPane1TreeCtrl : public CTreeCtrl
{
	// Construction
public:
	CDockPane1TreeCtrl() { }

	// Overrides
protected:
	//virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);

	// Implementation
public:
	virtual ~CDockPane1TreeCtrl() {}

protected:
	DECLARE_MESSAGE_MAP()
};

// CDockPane1

class CDockPane1 : public CDockablePane
{

public:
	CDockPane1();
	virtual ~CDockPane1();
	virtual void AdjustLayout();

protected:
	
	void FillFileView();

protected:
	CDockPane1TreeCtrl m_tree;
	CDockPane1ToolBar m_toolbar;
	//CMFCToolBar m_toolbar;
	CImageList m_imglist;
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);


	DECLARE_MESSAGE_MAP()
	afx_msg void OnProperties();
};


