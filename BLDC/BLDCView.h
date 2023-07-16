// BLDCView.h : interface of the CBLDCView class
//
/////////////////////////////////////////////////////////////////////////////
#include "DianJi.h"
#if !defined(AFX_BLDCVIEW_H__A76F683A_C46F_4088_9B21_FEE64FFCF7C5__INCLUDED_)
#define AFX_BLDCVIEW_H__A76F683A_C46F_4088_9B21_FEE64FFCF7C5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CBLDCView : public CView
{
protected: // create from serialization only
	CBLDCView();
	DECLARE_DYNCREATE(CBLDCView)

// Attributes
public:
	CBLDCDoc* GetDocument();

// Operations
public:
	CDianJi m_DianJi;
	CRect m_rect;
	CPoint m_coord;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBLDCView)
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
	virtual ~CBLDCView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBLDCView)
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnMStart();
	afx_msg void OnMStop();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnMSet();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in BLDCView.cpp
inline CBLDCDoc* CBLDCView::GetDocument()
   { return (CBLDCDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BLDCVIEW_H__A76F683A_C46F_4088_9B21_FEE64FFCF7C5__INCLUDED_)
