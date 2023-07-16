// SweepingRobot.h : main header file for the SWEEPINGROBOT application
//

#if !defined(AFX_SWEEPINGROBOT_H__52D782DD_C5A0_4B4A_93BB_70446B62182C__INCLUDED_)
#define AFX_SWEEPINGROBOT_H__52D782DD_C5A0_4B4A_93BB_70446B62182C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSweepingRobotApp:
// See SweepingRobot.cpp for the implementation of this class
//

class CSweepingRobotApp : public CWinApp
{
public:
	CSweepingRobotApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSweepingRobotApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CSweepingRobotApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SWEEPINGROBOT_H__52D782DD_C5A0_4B4A_93BB_70446B62182C__INCLUDED_)
