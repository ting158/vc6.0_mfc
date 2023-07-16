// Robot_Test.h : main header file for the ROBOT_TEST application
//

#if !defined(AFX_ROBOT_TEST_H__29B11A79_8B46_48F8_97E9_010D268DAECC__INCLUDED_)
#define AFX_ROBOT_TEST_H__29B11A79_8B46_48F8_97E9_010D268DAECC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CRobot_TestApp:
// See Robot_Test.cpp for the implementation of this class
//

class CRobot_TestApp : public CWinApp
{
public:
	CRobot_TestApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRobot_TestApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CRobot_TestApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ROBOT_TEST_H__29B11A79_8B46_48F8_97E9_010D268DAECC__INCLUDED_)
