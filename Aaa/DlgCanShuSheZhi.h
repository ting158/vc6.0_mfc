#if !defined(AFX_DLGCANSHUSHEZHI_H__D31FD5C2_C2B2_4784_9EE0_CD7468F9C704__INCLUDED_)
#define AFX_DLGCANSHUSHEZHI_H__D31FD5C2_C2B2_4784_9EE0_CD7468F9C704__INCLUDED_

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
	enum { IDD = IDD_CanShuSheZhi };
	int		m_x;
	int		m_y;
	int		m_he;
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
	afx_msg void OnQiuHe();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGCANSHUSHEZHI_H__D31FD5C2_C2B2_4784_9EE0_CD7468F9C704__INCLUDED_)
