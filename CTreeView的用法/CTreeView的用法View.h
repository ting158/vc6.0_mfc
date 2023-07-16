// CTreeView的用法View.h : interface of the CCTreeViewView class
//
/////////////////////////////////////////////////////////////////////////////
#include "CTreeView的用法Doc.h"

#if !defined(AFX_CTREEVIEWVIEW_H__7CCC745E_AEC3_48E1_B474_EFA0DBE55EE2__INCLUDED_)
#define AFX_CTREEVIEWVIEW_H__7CCC745E_AEC3_48E1_B474_EFA0DBE55EE2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCTreeViewView : public CView
{
protected: // create from serialization only
	CCTreeViewView();
	DECLARE_DYNCREATE(CCTreeViewView)

// Attributes
public:
	CCTreeViewDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCTreeViewView)
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
	virtual ~CCTreeViewView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCTreeViewView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in CTreeView的用法View.cpp
inline CCTreeViewDoc* CCTreeViewView::GetDocument()
   { return (CCTreeViewDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CTREEVIEWVIEW_H__7CCC745E_AEC3_48E1_B474_EFA0DBE55EE2__INCLUDED_)
