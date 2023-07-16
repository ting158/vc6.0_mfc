#if !defined(AFX_DLGYUAN_H__E7A4D45F_8753_4878_A1AD_C0FC086FBD97__INCLUDED_)
#define AFX_DLGYUAN_H__E7A4D45F_8753_4878_A1AD_C0FC086FBD97__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgYuan.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgYuan dialog

class CDlgYuan : public CDialog
{
// Construction
public:

// Dialog Data
	//{{AFX_DATA(CDlgYuan)
	enum { IDD = IDD_HuaYuan };
	int		m_x;
	int		m_r;
	int		m_y;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgYuan)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgYuan)
	afx_msg void OnOk();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGYUAN_H__E7A4D45F_8753_4878_A1AD_C0FC086FBD97__INCLUDED_)
