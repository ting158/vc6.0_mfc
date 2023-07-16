// WindowsApiDlg.h : header file
//

#if !defined(AFX_WINDOWSAPIDLG_H__26460350_456A_4D6F_BF66_5FE535DD943C__INCLUDED_)
#define AFX_WINDOWSAPIDLG_H__26460350_456A_4D6F_BF66_5FE535DD943C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CWindowsApiDlg dialog

class CWindowsApiDlg : public CDialog
{
// Construction
public:
	void DeleteDirectory(CString dpath);
	CWindowsApiDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CWindowsApiDlg)
	enum { IDD = IDD_WINDOWSAPI_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWindowsApiDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CWindowsApiDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDeleteDirectory();
	afx_msg void OnFindAllFilesFormDir();
	afx_msg void OnNowPath();
	afx_msg void OnObtainSystemHardwareInformation();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WINDOWSAPIDLG_H__26460350_456A_4D6F_BF66_5FE535DD943C__INCLUDED_)
