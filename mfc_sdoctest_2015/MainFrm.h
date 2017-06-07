
// MainFrm.h : interface of the CMainFrame class
//

#pragma once

#include "DockPane1.h"
#include "DockPane2.h"
#include "DockPane3.h"

#include <memory>

class CMainFrame : public CFrameWndEx
{
	
protected: // create from serialization only
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CMFCMenuBar       m_wndMenuBar;
	CMFCToolBar       m_wndToolBar;
	CMFCToolBar		  m_tbGfxm;
	
	CDockPane1		  m_dp1;
	CDockPane2		  m_dp2;
	CDockPane3		  m_dp3;

	std::shared_ptr<CDockablePane> m_simpledlg_dp;
	std::shared_ptr<CDockablePane> m_complexdlg_dp;

// Generated message map functions
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnViewCustomize();
	afx_msg LRESULT OnToolbarCreateNew(WPARAM wp, LPARAM lp);
	DECLARE_MESSAGE_MAP()

};


