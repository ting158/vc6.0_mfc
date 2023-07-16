// SpringSportView.h : interface of the CSpringSportView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SPRINGSPORTVIEW_H__B1A5C1AE_D47C_4F47_A3F0_A9CC0B4F839B__INCLUDED_)
#define AFX_SPRINGSPORTVIEW_H__B1A5C1AE_D47C_4F47_A3F0_A9CC0B4F839B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Spring.h"
#include "DlgSet.h"

class CSpringSportView : public CView
{
protected: // create from serialization only
	CSpringSportView();
	DECLARE_DYNCREATE(CSpringSportView)

// Attributes
public:
	CSpringSportDoc* GetDocument();

// Operations
public:
	CSpring m_spring;
	CDlgSet m_dlg;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSpringSportView)
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
	virtual ~CSpringSportView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSpringSportView)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnMStart();
	afx_msg void OnMStop();
	afx_msg void OnMSet();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in SpringSportView.cpp
inline CSpringSportDoc* CSpringSportView::GetDocument()
   { return (CSpringSportDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPRINGSPORTVIEW_H__B1A5C1AE_D47C_4F47_A3F0_A9CC0B4F839B__INCLUDED_)
