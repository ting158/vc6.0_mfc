#if !defined(AFX_DLGPAINTHUOJIAN_H__56A17931_D4D2_4A57_BF06_9B663D6E64C0__INCLUDED_)
#define AFX_DLGPAINTHUOJIAN_H__56A17931_D4D2_4A57_BF06_9B663D6E64C0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgPaintHuoJian.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgPaintHuoJian dialog

class CDlgPaintHuoJian : public CDialog
{
// Construction
public:
	CDlgPaintHuoJian(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgPaintHuoJian)
	enum { IDD = IDD_DIALOG2 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgPaintHuoJian)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgPaintHuoJian)
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPAINTHUOJIAN_H__56A17931_D4D2_4A57_BF06_9B663D6E64C0__INCLUDED_)
