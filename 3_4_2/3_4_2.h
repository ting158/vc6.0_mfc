// 3_4_2.h : main header file for the 3_4_2 application
//

#if !defined(AFX_3_4_2_H__E6EB7518_606D_4C14_9111_A70D2BC03CF1__INCLUDED_)
#define AFX_3_4_2_H__E6EB7518_606D_4C14_9111_A70D2BC03CF1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy3_4_2App:
// See 3_4_2.cpp for the implementation of this class
//

class CMy3_4_2App : public CWinApp
{
public:
	CMy3_4_2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy3_4_2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMy3_4_2App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_3_4_2_H__E6EB7518_606D_4C14_9111_A70D2BC03CF1__INCLUDED_)
