// AccessTestView.h : interface of the CAccessTestView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ACCESSTESTVIEW_H__C2D81323_A6E8_4138_8772_5FE7D297D669__INCLUDED_)
#define AFX_ACCESSTESTVIEW_H__C2D81323_A6E8_4138_8772_5FE7D297D669__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Ado.h"

class CAccessTestView : public CView
{
protected: // create from serialization only
	CAccessTestView();
	DECLARE_DYNCREATE(CAccessTestView)

// Attributes
public:
	CAccessTestDoc* GetDocument();

// Operations
public:
	CAdo m_ado;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAccessTestView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CAccessTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CAccessTestView)
	afx_msg void OnMConnection();
	afx_msg void OnMSelect();
	afx_msg void OnMAdd();
	afx_msg void OnMDelete();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in AccessTestView.cpp
inline CAccessTestDoc* CAccessTestView::GetDocument()
   { return (CAccessTestDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ACCESSTESTVIEW_H__C2D81323_A6E8_4138_8772_5FE7D297D669__INCLUDED_)
