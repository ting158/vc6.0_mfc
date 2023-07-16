// TerisView.h : interface of the CTerisView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TERISVIEW_H__6365785D_9DB5_472F_AC44_A81EBFCD4681__INCLUDED_)
#define AFX_TERISVIEW_H__6365785D_9DB5_472F_AC44_A81EBFCD4681__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "RussiaBlock.h"
#include <time.h>


class CTerisView : public CView
{
protected: // create from serialization only
	CTerisView();
	DECLARE_DYNCREATE(CTerisView)

// Attributes
public:
	CTerisDoc* GetDocument();
	CRussiaBlock m_RB;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTerisView)
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
	virtual ~CTerisView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTerisView)
	afx_msg void OnStart();
	afx_msg void OnStop();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TerisView.cpp
inline CTerisDoc* CTerisView::GetDocument()
   { return (CTerisDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TERISVIEW_H__6365785D_9DB5_472F_AC44_A81EBFCD4681__INCLUDED_)
