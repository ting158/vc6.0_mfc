// AabView.h : interface of the CAabView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_AABVIEW_H__E6D91B54_E3DD_4856_8CE0_9D82A7BAF659__INCLUDED_)
#define AFX_AABVIEW_H__E6D91B54_E3DD_4856_8CE0_9D82A7BAF659__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "AabDoc.h"

class CAabView : public CView
{
protected: // create from serialization only
	CAabView();
	DECLARE_DYNCREATE(CAabView)

// Attributes
public:
	CAabDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAabView)
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
	virtual ~CAabView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CAabView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in AabView.cpp
inline CAabDoc* CAabView::GetDocument()
   { return (CAabDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AABVIEW_H__E6D91B54_E3DD_4856_8CE0_9D82A7BAF659__INCLUDED_)
