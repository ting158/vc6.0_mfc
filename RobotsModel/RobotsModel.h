// RobotsModel.h : main header file for the ROBOTSMODEL application
//

#if !defined(AFX_ROBOTSMODEL_H__8F41291A_BCDF_4800_B159_451670DDA06F__INCLUDED_)
#define AFX_ROBOTSMODEL_H__8F41291A_BCDF_4800_B159_451670DDA06F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CRobotsModelApp:
// See RobotsModel.cpp for the implementation of this class
//

class CRobotsModelApp : public CWinApp
{
public:
	CRobotsModelApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRobotsModelApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CRobotsModelApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ROBOTSMODEL_H__8F41291A_BCDF_4800_B159_451670DDA06F__INCLUDED_)
