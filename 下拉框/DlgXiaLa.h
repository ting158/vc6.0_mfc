#if !defined(AFX_DLGXIALA_H__F4435C45_64B7_400B_AB58_7098D06EA00C__INCLUDED_)
#define AFX_DLGXIALA_H__F4435C45_64B7_400B_AB58_7098D06EA00C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgXiaLa.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgXiaLa dialog

class CDlgXiaLa : public CDialog
{
// Construction
public:
	CDlgXiaLa(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgXiaLa)
	enum { IDD = IDD_XiaLa };
	CComboBox	m_Combo;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgXiaLa)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgXiaLa)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGXIALA_H__F4435C45_64B7_400B_AB58_7098D06EA00C__INCLUDED_)
