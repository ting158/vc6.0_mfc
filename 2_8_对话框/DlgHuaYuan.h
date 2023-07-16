#if !defined(AFX_DLGHUAYUAN_H__48A9F6E3_8B44_47CD_9417_5902E8C44682__INCLUDED_)
#define AFX_DLGHUAYUAN_H__48A9F6E3_8B44_47CD_9417_5902E8C44682__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgHuaYuan.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgHuaYuan dialog

class CDlgHuaYuan : public CDialog
{
// Construction
public:
	CDlgHuaYuan(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgHuaYuan)
	enum { IDD = IDD_HuaYuan };
	int		m_r;
	int		m_x;
	int		m_y;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgHuaYuan)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgHuaYuan)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGHUAYUAN_H__48A9F6E3_8B44_47CD_9417_5902E8C44682__INCLUDED_)
