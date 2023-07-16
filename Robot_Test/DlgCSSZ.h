#if !defined(AFX_DLGCSSZ_H__1870F395_AE16_40A1_BCCA_7B8CD188060F__INCLUDED_)
#define AFX_DLGCSSZ_H__1870F395_AE16_40A1_BCCA_7B8CD188060F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgCSSZ.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgCSSZ dialog

class CDlgCSSZ : public CDialog
{
// Construction
public:
	CDlgCSSZ(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgCSSZ)
	enum { IDD = IDD_DIALOG2 };
	CString	m_Hbody;
	CString	m_Hleftarm;
	CString	m_Hleftfoot;
	CString	m_Hleftleg;
	CString	m_Hneck;
	CString	m_Hrightarm;
	CString	m_Hrightfoot;
	CString	m_Hrightleg;
	CString	m_Lmouth;
	CString	m_Lnose;
	CString	m_Rhead;
	CString	m_Rlefteye;
	CString	m_RobotName;
	CString	m_Rrighteye;
	CString	m_Smouth;
	CString	m_Wbody;
	CString	m_Wleftarm;
	CString	m_Wleftleg;
	CString	m_Wneck;
	CString	m_Wrightarm;
	CString	m_Wrightfoot;
	CString	m_Wrightleg;
	CString	m_Xbody;
	CString	m_X;
	CString	m_Xhead;
	CString	m_Xleftarm;
	CString	m_Xlefteye;
	CString	m_Xleftfoot;
	CString	m_Xleftleg;
	CString	m_Xmouth;
	CString	m_Xneck;
	CString	m_Xnose;
	CString	m_Xrightarm;
	CString	m_Xrighteye;
	CString	m_Xrightfoot;
	CString	m_Xrightleg;
	CString	m_Y;
	CString	m_Ybody;
	CString	m_Yhead;
	CString	m_Yleftarm;
	CString	m_Ylefteye;
	CString	m_Yleftfoot;
	CString	m_Yleftleg;
	CString	m_Ymouth;
	CString	m_Yneck;
	CString	m_Ynose;
	CString	m_Yrightarm;
	CString	m_Yrighteye;
	CString	m_Yrightfoot;
	CString	m_Yrightleg;
	CString	m_Wleftfoot;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgCSSZ)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgCSSZ)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGCSSZ_H__1870F395_AE16_40A1_BCCA_7B8CD188060F__INCLUDED_)
