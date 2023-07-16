// Robot_Check.h : main header file for the ROBOT_CHECK application
//

#if !defined(AFX_ROBOT_CHECK_H__BB5E6599_2EC7_4D43_8B25_30F1C621C0B4__INCLUDED_)
#define AFX_ROBOT_CHECK_H__BB5E6599_2EC7_4D43_8B25_30F1C621C0B4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CRobot_CheckApp:
// See Robot_Check.cpp for the implementation of this class
//

class CRobot_CheckApp : public CWinApp
{
public:
	CRobot_CheckApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRobot_CheckApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CRobot_CheckApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ROBOT_CHECK_H__BB5E6599_2EC7_4D43_8B25_30F1C621C0B4__INCLUDED_)
