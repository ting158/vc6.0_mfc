// 2_8_对话框.h : main header file for the 2_8_对话框 application
//

#if !defined(AFX_2_8__H__D63CF7B2_04C7_4A46_9709_C634F9196CC8__INCLUDED_)
#define AFX_2_8__H__D63CF7B2_04C7_4A46_9709_C634F9196CC8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy2_8_App:
// See 2_8_对话框.cpp for the implementation of this class
//

class CMy2_8_App : public CWinApp
{
public:
	CMy2_8_App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy2_8_App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMy2_8_App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_2_8__H__D63CF7B2_04C7_4A46_9709_C634F9196CC8__INCLUDED_)
