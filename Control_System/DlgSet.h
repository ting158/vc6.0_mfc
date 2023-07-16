#if !defined(AFX_DLGSET_H__0D944653_3B75_475F_B9B0_3B53F5BB5155__INCLUDED_)
#define AFX_DLGSET_H__0D944653_3B75_475F_B9B0_3B53F5BB5155__INCLUDED_

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
	float	m_kp_a;
	float	m_kp_v;
	float	m_kp_x;
	float	m_kd_a;
	float	m_kd_v;
	float	m_kd_x;
	float	m_ki_a;
	float	m_ki_v;
	float	m_ki_x;
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

#endif // !defined(AFX_DLGSET_H__0D944653_3B75_475F_B9B0_3B53F5BB5155__INCLUDED_)
