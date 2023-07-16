// TankWarView.h : interface of the CTankWarView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TANKWARVIEW_H__A2DE5F43_310D_4080_9E1E_7550B1ADDBEF__INCLUDED_)
#define AFX_TANKWARVIEW_H__A2DE5F43_310D_4080_9E1E_7550B1ADDBEF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Tank.h"

class CTankWarView : public CView
{
protected: // create from serialization only
	CTankWarView();
	DECLARE_DYNCREATE(CTankWarView)

// Attributes
public:
	CTankWarDoc* GetDocument();

// Operations
public:
	CTank m_Tank;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTankWarView)
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
	virtual ~CTankWarView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTankWarView)
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnMStart();
	afx_msg void OnMStop();
	afx_msg void OnMRestart();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TankWarView.cpp
inline CTankWarDoc* CTankWarView::GetDocument()
   { return (CTankWarDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TANKWARVIEW_H__A2DE5F43_310D_4080_9E1E_7550B1ADDBEF__INCLUDED_)
