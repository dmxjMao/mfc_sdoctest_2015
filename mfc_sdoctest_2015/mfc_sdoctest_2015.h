
// mfc_sdoctest_2015.h : main header file for the mfc_sdoctest_2015 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// Cmfc_sdoctest_2015App:
// See mfc_sdoctest_2015.cpp for the implementation of this class
//

class Cmfc_sdoctest_2015App : public CWinAppEx
{
public:
	Cmfc_sdoctest_2015App();


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
	virtual BOOL LoadState(LPCTSTR lpszSectionName = NULL, CFrameImpl* pFrameImpl = NULL);
};

extern Cmfc_sdoctest_2015App theApp;
