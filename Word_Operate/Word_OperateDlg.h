// Word_OperateDlg.h : header file
//

#if !defined(AFX_WORD_OPERATEDLG_H__3042E2FD_549D_467D_83E5_C82FB161A6BF__INCLUDED_)
#define AFX_WORD_OPERATEDLG_H__3042E2FD_549D_467D_83E5_C82FB161A6BF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CWord_OperateDlg dialog

class CWord_OperateDlg : public CDialog
{
// Construction
public:
	CWord_OperateDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CWord_OperateDlg)
	enum { IDD = IDD_WORD_OPERATE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWord_OperateDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CWord_OperateDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBUTTONTest();
	afx_msg void OnBUTTONWord();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WORD_OPERATEDLG_H__3042E2FD_549D_467D_83E5_C82FB161A6BF__INCLUDED_)
