// SpringSport.h : main header file for the SPRINGSPORT application
//

#if !defined(AFX_SPRINGSPORT_H__924F0FB5_1063_4DEF_94CB_D9B89E7149E6__INCLUDED_)
#define AFX_SPRINGSPORT_H__924F0FB5_1063_4DEF_94CB_D9B89E7149E6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSpringSportApp:
// See SpringSport.cpp for the implementation of this class
//

class CSpringSportApp : public CWinApp
{
public:
	CSpringSportApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSpringSportApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CSpringSportApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPRINGSPORT_H__924F0FB5_1063_4DEF_94CB_D9B89E7149E6__INCLUDED_)
