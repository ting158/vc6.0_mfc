#if !defined(AFX_DLGSET_H__A439D2C7_581F_456F_9459_941E8BF38C1D__INCLUDED_)
#define AFX_DLGSET_H__A439D2C7_581F_456F_9459_941E8BF38C1D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgSet dialog

class CDlgSet : public CDialog
{
// Construction
public:
	CDlgSet(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgSet)
	enum { IDD = IDD_Set };
	float	m_dir;
	float	m_r;
	float	m_vJD;
	int		m_sn;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgSet)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgSet)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSET_H__A439D2C7_581F_456F_9459_941E8BF38C1D__INCLUDED_)
