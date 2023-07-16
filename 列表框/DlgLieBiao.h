#if !defined(AFX_DLGLIEBIAO_H__B115CE13_3CA3_47E0_B2F7_7833033C785D__INCLUDED_)
#define AFX_DLGLIEBIAO_H__B115CE13_3CA3_47E0_B2F7_7833033C785D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgLieBiao.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgLieBiao dialog

class CDlgLieBiao : public CDialog
{

// Construction
public:
	CDlgLieBiao(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgLieBiao)
	enum { IDD = IDD_LieBiao };
	CListCtrl	m_ListCtr;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgLieBiao)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgLieBiao)
	virtual BOOL OnInitDialog();
	afx_msg void OnClickList2(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGLIEBIAO_H__B115CE13_3CA3_47E0_B2F7_7833033C785D__INCLUDED_)
