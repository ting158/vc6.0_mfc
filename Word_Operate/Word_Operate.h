// Word_Operate.h : main header file for the WORD_OPERATE application
//

#if !defined(AFX_WORD_OPERATE_H__977FB105_6B65_4E87_A59E_F5113E7E1AB1__INCLUDED_)
#define AFX_WORD_OPERATE_H__977FB105_6B65_4E87_A59E_F5113E7E1AB1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CWord_OperateApp:
// See Word_Operate.cpp for the implementation of this class
//

class CWord_OperateApp : public CWinApp
{
public:
	CWord_OperateApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWord_OperateApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CWord_OperateApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WORD_OPERATE_H__977FB105_6B65_4E87_A59E_F5113E7E1AB1__INCLUDED_)
