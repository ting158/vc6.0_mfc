#if !defined(AFX_DRAWRECTANGLEVIEW_H__93B1A118_3E2E_4A87_9B77_880EEED42C3E__INCLUDED_)
#define AFX_DRAWRECTANGLEVIEW_H__93B1A118_3E2E_4A87_9B77_880EEED42C3E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DrawRectangleView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDrawRectangleView form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CDrawRectangleView : public CFormView
{
protected:
	CDrawRectangleView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CDrawRectangleView)

// Form Data
public:
	//{{AFX_DATA(CDrawRectangleView)
	enum { IDD = IDD_DIgDrawRectangle };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDrawRectangleView)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnDraw(CDC* pDC);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CDrawRectangleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CDrawRectangleView)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAWRECTANGLEVIEW_H__93B1A118_3E2E_4A87_9B77_880EEED42C3E__INCLUDED_)
