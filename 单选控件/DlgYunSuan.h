#if !defined(AFX_DLGYUNSUAN_H__D10B41AD_AE6D_4784_8136_16C1E02B573B__INCLUDED_)
#define AFX_DLGYUNSUAN_H__D10B41AD_AE6D_4784_8136_16C1E02B573B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgYunSuan.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgYunSuan dialog

class CDlgYunSuan : public CDialog
{
// Construction
public:
	CDlgYunSuan(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgYunSuan)
	enum { IDD = IDD_YunSuan };
	CButton	m_Radio_YunSuan;
	int		m_Result;
	int		m_x;
	int		m_y;
	int		m_rad;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgYunSuan)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgYunSuan)
	afx_msg void OnBUTTONYunSuan();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGYUNSUAN_H__D10B41AD_AE6D_4784_8136_16C1E02B573B__INCLUDED_)
