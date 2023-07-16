#if !defined(AFX_DRAWCIRCLEVIEW_H__0C52B6A6_AF9F_4561_8461_87063845DAB5__INCLUDED_)
#define AFX_DRAWCIRCLEVIEW_H__0C52B6A6_AF9F_4561_8461_87063845DAB5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DrawCircleView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDrawCircleView form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CDrawCircleView : public CFormView
{
protected:
	CDrawCircleView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CDrawCircleView)

// Form Data
public:
	//{{AFX_DATA(CDrawCircleView)
	enum { IDD = IDD_DlgDrawCircle };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDrawCircleView)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnDraw(CDC* pDC);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CDrawCircleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CDrawCircleView)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAWCIRCLEVIEW_H__0C52B6A6_AF9F_4561_8461_87063845DAB5__INCLUDED_)
