// SinCosMoveView.h : interface of the CSinCosMoveView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SINCOSMOVEVIEW_H__AF87F8ED_452E_482B_B9AF_FBF42BABF2CB__INCLUDED_)
#define AFX_SINCOSMOVEVIEW_H__AF87F8ED_452E_482B_B9AF_FBF42BABF2CB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SinCos.h"
#include "DlgSet.h"

class CSinCosMoveView : public CView
{
protected: // create from serialization only
	CSinCosMoveView();
	DECLARE_DYNCREATE(CSinCosMoveView)

// Attributes
public:
	CSinCosMoveDoc* GetDocument();

// Operations
public:
	CSinCos m_sc;
	CDlgSet m_dlg;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSinCosMoveView)
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
	virtual ~CSinCosMoveView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSinCosMoveView)
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnMStart();
	afx_msg void OnMStop();
	afx_msg void OnMSet();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in SinCosMoveView.cpp
inline CSinCosMoveDoc* CSinCosMoveView::GetDocument()
   { return (CSinCosMoveDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SINCOSMOVEVIEW_H__AF87F8ED_452E_482B_B9AF_FBF42BABF2CB__INCLUDED_)
