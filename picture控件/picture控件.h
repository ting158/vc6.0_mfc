// picture�ؼ�.h : main header file for the PICTURE�ؼ� application
//

#if !defined(AFX_PICTURE_H__8BB91B92_9DAD_4D2C_AC4C_180525C00DCD__INCLUDED_)
#define AFX_PICTURE_H__8BB91B92_9DAD_4D2C_AC4C_180525C00DCD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CPictureApp:
// See picture�ؼ�.cpp for the implementation of this class
//

class CPictureApp : public CWinApp
{
public:
	CPictureApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPictureApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CPictureApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PICTURE_H__8BB91B92_9DAD_4D2C_AC4C_180525C00DCD__INCLUDED_)
