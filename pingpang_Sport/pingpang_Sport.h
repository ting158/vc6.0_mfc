// pingpang_Sport.h : main header file for the PINGPANG_SPORT application
//

#if !defined(AFX_PINGPANG_SPORT_H__4AAC8BA5_86C6_4CDE_B59D_CBC49362CFAA__INCLUDED_)
#define AFX_PINGPANG_SPORT_H__4AAC8BA5_86C6_4CDE_B59D_CBC49362CFAA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CPingpang_SportApp:
// See pingpang_Sport.cpp for the implementation of this class
//

class CPingpang_SportApp : public CWinApp
{
public:
	CPingpang_SportApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPingpang_SportApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CPingpang_SportApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PINGPANG_SPORT_H__4AAC8BA5_86C6_4CDE_B59D_CBC49362CFAA__INCLUDED_)
