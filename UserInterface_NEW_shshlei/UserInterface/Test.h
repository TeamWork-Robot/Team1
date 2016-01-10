//
// Test.h : main header file for the Test application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CTestApp:
// See Test.cpp for the implementation of this class
//

class CTestApp : public CBCGPWinApp
{
public:
	CTestApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CTestApp theApp;
