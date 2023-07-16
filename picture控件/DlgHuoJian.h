#if !defined(AFX_DLGHUOJIAN_H__71C202F9_9AA5_4885_93DC_5F77E14C77A5__INCLUDED_)
#define AFX_DLGHUOJIAN_H__71C202F9_9AA5_4885_93DC_5F77E14C77A5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgHuoJian.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgHuoJian dialog

class CDlgHuoJian : public CDialog
{
// Construction
public:
	CDlgHuoJian(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgHuoJian)
	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgHuoJian)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgHuoJian)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGHUOJIAN_H__71C202F9_9AA5_4885_93DC_5F77E14C77A5__INCLUDED_)
