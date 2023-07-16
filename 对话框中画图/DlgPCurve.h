#if !defined(AFX_DLGPCURVE_H__5BF13430_08AF_42F7_8FD2_F5BFD1AE3BD6__INCLUDED_)
#define AFX_DLGPCURVE_H__5BF13430_08AF_42F7_8FD2_F5BFD1AE3BD6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgPCurve.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgPCurve dialog

class CDlgPCurve : public CDialog
{
// Construction
public:
	CDlgPCurve(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgPCurve)
	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgPCurve)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgPCurve)
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPCURVE_H__5BF13430_08AF_42F7_8FD2_F5BFD1AE3BD6__INCLUDED_)
