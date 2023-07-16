// BLDC.h : main header file for the BLDC application
//

#if !defined(AFX_BLDC_H__FD20491F_BB5E_428A_8430_20967ECE8704__INCLUDED_)
#define AFX_BLDC_H__FD20491F_BB5E_428A_8430_20967ECE8704__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CBLDCApp:
// See BLDC.cpp for the implementation of this class
//

class CBLDCApp : public CWinApp
{
public:
	CBLDCApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBLDCApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CBLDCApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BLDC_H__FD20491F_BB5E_428A_8430_20967ECE8704__INCLUDED_)
