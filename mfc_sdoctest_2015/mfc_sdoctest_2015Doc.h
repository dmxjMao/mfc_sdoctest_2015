
// mfc_sdoctest_2015Doc.h : interface of the Cmfc_sdoctest_2015Doc class
//


#pragma once


class Cmfc_sdoctest_2015Doc : public CDocument
{
protected: // create from serialization only
	Cmfc_sdoctest_2015Doc();
	DECLARE_DYNCREATE(Cmfc_sdoctest_2015Doc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~Cmfc_sdoctest_2015Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
