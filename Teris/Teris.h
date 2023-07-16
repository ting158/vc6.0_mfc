// Teris.h : main header file for the TERIS application
//

#if !defined(AFX_TERIS_H__52A3073A_69D6_443A_8549_08EE0FC3E0F1__INCLUDED_)
#define AFX_TERIS_H__52A3073A_69D6_443A_8549_08EE0FC3E0F1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTerisApp:
// See Teris.cpp for the implementation of this class
//

class CTerisApp : public CWinApp
{
public:
	CTerisApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTerisApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CTerisApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TERIS_H__52A3073A_69D6_443A_8549_08EE0FC3E0F1__INCLUDED_)
