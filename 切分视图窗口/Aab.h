// Aab.h : main header file for the AAB application
//

#if !defined(AFX_AAB_H__7CF109E8_2FC4_428B_AA6D_4ED965B959CC__INCLUDED_)
#define AFX_AAB_H__7CF109E8_2FC4_428B_AA6D_4ED965B959CC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CAabApp:
// See Aab.cpp for the implementation of this class
//

class CAabApp : public CWinApp
{
public:
	CAabApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAabApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CAabApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AAB_H__7CF109E8_2FC4_428B_AA6D_4ED965B959CC__INCLUDED_)
