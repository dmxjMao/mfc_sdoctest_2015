
// mfc_sdoctest_2015View.h : interface of the Cmfc_sdoctest_2015View class
//

#pragma once


class Cmfc_sdoctest_2015View : public CView
{
protected: // create from serialization only
	Cmfc_sdoctest_2015View();
	DECLARE_DYNCREATE(Cmfc_sdoctest_2015View)

// Attributes
public:
	Cmfc_sdoctest_2015Doc* GetDocument() const;
	static const COLORREF m_colors[3];

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~Cmfc_sdoctest_2015View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	int m_nColor = 0;

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnColor(UINT nID);
	afx_msg void OnUpdateColor(CCmdUI*);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in mfc_sdoctest_2015View.cpp
inline Cmfc_sdoctest_2015Doc* Cmfc_sdoctest_2015View::GetDocument() const
   { return reinterpret_cast<Cmfc_sdoctest_2015Doc*>(m_pDocument); }
#endif

