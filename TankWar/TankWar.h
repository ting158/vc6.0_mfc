// TankWar.h : main header file for the TANKWAR application
//

#if !defined(AFX_TANKWAR_H__7783CFCB_6703_4B4F_BE00_177F3091EAFA__INCLUDED_)
#define AFX_TANKWAR_H__7783CFCB_6703_4B4F_BE00_177F3091EAFA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTankWarApp:
// See TankWar.cpp for the implementation of this class
//

class CTankWarApp : public CWinApp
{
public:
	CTankWarApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTankWarApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CTankWarApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TANKWAR_H__7783CFCB_6703_4B4F_BE00_177F3091EAFA__INCLUDED_)
