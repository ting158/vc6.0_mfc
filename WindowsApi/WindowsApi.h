// WindowsApi.h : main header file for the WINDOWSAPI application
//

#if !defined(AFX_WINDOWSAPI_H__4872F4CC_2E00_47C7_8E4D_D417E504B931__INCLUDED_)
#define AFX_WINDOWSAPI_H__4872F4CC_2E00_47C7_8E4D_D417E504B931__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CWindowsApiApp:
// See WindowsApi.cpp for the implementation of this class
//

class CWindowsApiApp : public CWinApp
{
public:
	CWindowsApiApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWindowsApiApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CWindowsApiApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WINDOWSAPI_H__4872F4CC_2E00_47C7_8E4D_D417E504B931__INCLUDED_)
