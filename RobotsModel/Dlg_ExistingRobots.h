#if !defined(AFX_DLG_EXISTINGROBOTS_H__0D6DCC7B_FE23_40E3_8C65_3AC9EC149C98__INCLUDED_)
#define AFX_DLG_EXISTINGROBOTS_H__0D6DCC7B_FE23_40E3_8C65_3AC9EC149C98__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dlg_ExistingRobots.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlg_ExistingRobots dialog

#include "Ado.h"

class CDlg_ExistingRobots : public CDialog
{
// Construction
public:
	void Display();
	CDlg_ExistingRobots(CWnd* pParent = NULL);   // standard constructor

	CAdo m_ado;

	CString m_strID;
	int m_index;

// Dialog Data
	//{{AFX_DATA(CDlg_ExistingRobots)
	enum { IDD = IDD_DlgManageRobots };
	CListCtrl	m_listRobots;
	CString	m_AngleArm;
	CString	m_hArm;
	CString	m_hBody;
	CString	m_hEyes;
	CString	m_hFoot;
	CString	m_hLeg;
	CString	m_hMouth;
	CString	m_hNeck;
	CString	m_rHead;
	CString	m_robotName;
	CString	m_wArm;
	CString	m_wBody;
	CString	m_wEyes;
	CString	m_wFoot;
	CString	m_wLeg;
	CString	m_wMouth;
	CString	m_wNeck;
	CString	m_wNose;
	CString	m_x;
	CString	m_y;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlg_ExistingRobots)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlg_ExistingRobots)
	virtual BOOL OnInitDialog();
	afx_msg void OnClickLISTRobots(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBUTTONDelete();
	afx_msg void OnBUTTONModify();
	afx_msg void OnBUTTONAdd();
	afx_msg void OnBUTTONSaveToFile();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_EXISTINGROBOTS_H__0D6DCC7B_FE23_40E3_8C65_3AC9EC149C98__INCLUDED_)
