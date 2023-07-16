// AccessOperation.h : main header file for the ACCESSOPERATION application
//

#if !defined(AFX_ACCESSOPERATION_H__4A2823DB_803B_4982_9C15_7CE90E7572AB__INCLUDED_)
#define AFX_ACCESSOPERATION_H__4A2823DB_803B_4982_9C15_7CE90E7572AB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CAccessOperationApp:
// See AccessOperation.cpp for the implementation of this class
//

class CAccessOperationApp : public CWinApp
{
public:
	CAccessOperationApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAccessOperationApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CAccessOperationApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ACCESSOPERATION_H__4A2823DB_803B_4982_9C15_7CE90E7572AB__INCLUDED_)
