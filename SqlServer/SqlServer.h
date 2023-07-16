// SqlServer.h : main header file for the SQLSERVER application
//

#if !defined(AFX_SQLSERVER_H__CF1D9779_5FE5_414D_9961_8B2B77CE7DD2__INCLUDED_)
#define AFX_SQLSERVER_H__CF1D9779_5FE5_414D_9961_8B2B77CE7DD2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSqlServerApp:
// See SqlServer.cpp for the implementation of this class
//

class CSqlServerApp : public CWinApp
{
public:
	CSqlServerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSqlServerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CSqlServerApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SQLSERVER_H__CF1D9779_5FE5_414D_9961_8B2B77CE7DD2__INCLUDED_)
