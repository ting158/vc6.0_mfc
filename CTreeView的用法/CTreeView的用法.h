// CTreeView的用法.h : main header file for the CTREEVIEW的用法 application
//

#if !defined(AFX_CTREEVIEW_H__9E7DBE1C_77A5_43E3_B5E1_5291E1714038__INCLUDED_)
#define AFX_CTREEVIEW_H__9E7DBE1C_77A5_43E3_B5E1_5291E1714038__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CCTreeViewApp:
// See CTreeView的用法.cpp for the implementation of this class
//

class CCTreeViewApp : public CWinApp
{
public:
	CCTreeViewApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCTreeViewApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CCTreeViewApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CTREEVIEW_H__9E7DBE1C_77A5_43E3_B5E1_5291E1714038__INCLUDED_)
