// pingpang_SportView.h : interface of the CPingpang_SportView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PINGPANG_SPORTVIEW_H__0ED434E3_0392_4FB9_B5C9_28ED32B81D0F__INCLUDED_)
#define AFX_PINGPANG_SPORTVIEW_H__0ED434E3_0392_4FB9_B5C9_28ED32B81D0F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Ball.h"
#include "DlgSet.h"

class CPingpang_SportView : public CView
{
protected: // create from serialization only
	CPingpang_SportView();
	DECLARE_DYNCREATE(CPingpang_SportView)

// Attributes
public:
	CPingpang_SportDoc* GetDocument();

// Operations
public:
	CBall m_ball;
	CDlgSet m_set;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPingpang_SportView)
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
	virtual ~CPingpang_SportView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPingpang_SportView)
	afx_msg void OnMStart();
	afx_msg void OnMStop();
	afx_msg void OnMSet();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in pingpang_SportView.cpp
inline CPingpang_SportDoc* CPingpang_SportView::GetDocument()
   { return (CPingpang_SportDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PINGPANG_SPORTVIEW_H__0ED434E3_0392_4FB9_B5C9_28ED32B81D0F__INCLUDED_)
