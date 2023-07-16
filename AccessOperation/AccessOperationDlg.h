// AccessOperationDlg.h : header file
//

#if !defined(AFX_ACCESSOPERATIONDLG_H__D70B5218_DFB4_48C6_8770_EEB9394B5861__INCLUDED_)
#define AFX_ACCESSOPERATIONDLG_H__D70B5218_DFB4_48C6_8770_EEB9394B5861__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "AccessAdo.h"

/////////////////////////////////////////////////////////////////////////////
// CAccessOperationDlg dialog

class CAccessOperationDlg : public CDialog
{
// Construction
public:
	CAccessOperationDlg(CWnd* pParent = NULL);	// standard constructor

	CAccessAdo m_ado;

// Dialog Data
	//{{AFX_DATA(CAccessOperationDlg)
	enum { IDD = IDD_ACCESSOPERATION_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAccessOperationDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CAccessOperationDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnConnect();
	afx_msg void OnSelect();
	afx_msg void OnAdd();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ACCESSOPERATIONDLG_H__D70B5218_DFB4_48C6_8770_EEB9394B5861__INCLUDED_)
