#if !defined(AFX_DLGSELROBOT_H__FF1FFEAC_FA3B_480C_B2C6_2837FD1197BC__INCLUDED_)
#define AFX_DLGSELROBOT_H__FF1FFEAC_FA3B_480C_B2C6_2837FD1197BC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgSelRobot.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgSelRobot dialog

class CDlgSelRobot : public CDialog
{
// Construction
public:
	CDlgSelRobot(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgSelRobot)
	enum { IDD = IDD_DIALOG1 };
	CString	m_RobotName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgSelRobot)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgSelRobot)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSELROBOT_H__FF1FFEAC_FA3B_480C_B2C6_2837FD1197BC__INCLUDED_)
