// CHuaTu.h : main header file for the CHUATU application
//

#if !defined(AFX_CHUATU_H__90375B0E_C367_4AEC_9337_64BDC51C04B8__INCLUDED_)
#define AFX_CHUATU_H__90375B0E_C367_4AEC_9337_64BDC51C04B8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CCHuaTuApp:
// See CHuaTu.cpp for the implementation of this class
//

class CCHuaTuApp : public CWinApp
{
public:
	CCHuaTuApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCHuaTuApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CCHuaTuApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHUATU_H__90375B0E_C367_4AEC_9337_64BDC51C04B8__INCLUDED_)
