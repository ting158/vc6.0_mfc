// Access_Robot.h : main header file for the ACCESS_ROBOT application
//

#if !defined(AFX_ACCESS_ROBOT_H__2304B341_9183_460E_89D0_27C886DA8E86__INCLUDED_)
#define AFX_ACCESS_ROBOT_H__2304B341_9183_460E_89D0_27C886DA8E86__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CAccess_RobotApp:
// See Access_Robot.cpp for the implementation of this class
//

class CAccess_RobotApp : public CWinApp
{
public:
	CAccess_RobotApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAccess_RobotApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CAccess_RobotApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ACCESS_ROBOT_H__2304B341_9183_460E_89D0_27C886DA8E86__INCLUDED_)
