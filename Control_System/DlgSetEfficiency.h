#if !defined(AFX_DLGSETEFFICIENCY_H__3FCDC8A4_C442_4F6D_AEA1_74CCC0DC9840__INCLUDED_)
#define AFX_DLGSETEFFICIENCY_H__3FCDC8A4_C442_4F6D_AEA1_74CCC0DC9840__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgSetEfficiency.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgSetEfficiency dialog

class CDlgSetEfficiency : public CDialog
{
// Construction
public:
	CDlgSetEfficiency(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgSetEfficiency)
	enum { IDD = IDD_DIALOG1 };
	float	m_XL;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgSetEfficiency)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgSetEfficiency)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSETEFFICIENCY_H__3FCDC8A4_C442_4F6D_AEA1_74CCC0DC9840__INCLUDED_)
