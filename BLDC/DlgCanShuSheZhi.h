#if !defined(AFX_DLGCANSHUSHEZHI_H__501CAE9D_FE92_43E8_81F0_45E7C4D0BD86__INCLUDED_)
#define AFX_DLGCANSHUSHEZHI_H__501CAE9D_FE92_43E8_81F0_45E7C4D0BD86__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgCanShuSheZhi.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgCanShuSheZhi dialog

class CDlgCanShuSheZhi : public CDialog
{
// Construction
public:
	CDlgCanShuSheZhi(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgCanShuSheZhi)
	enum { IDD = IDD_DIALOG1 };
	float	m_k;
	float	m_kp;
	int		m_r;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgCanShuSheZhi)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgCanShuSheZhi)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGCANSHUSHEZHI_H__501CAE9D_FE92_43E8_81F0_45E7C4D0BD86__INCLUDED_)
