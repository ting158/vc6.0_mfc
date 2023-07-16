// 2_4.h : main header file for the 2_4 application
//

#if !defined(AFX_2_4_H__2F29D404_6394_4C1D_8071_CADE0A353771__INCLUDED_)
#define AFX_2_4_H__2F29D404_6394_4C1D_8071_CADE0A353771__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy2_4App:
// See 2_4.cpp for the implementation of this class
//

class CMy2_4App : public CWinApp
{
public:
	CMy2_4App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy2_4App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMy2_4App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_2_4_H__2F29D404_6394_4C1D_8071_CADE0A353771__INCLUDED_)
