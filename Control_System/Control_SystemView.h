// Control_SystemView.h : interface of the CControl_SystemView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONTROL_SYSTEMVIEW_H__AC07C2C6_115B_4D31_85B5_05EAB0011123__INCLUDED_)
#define AFX_CONTROL_SYSTEMVIEW_H__AC07C2C6_115B_4D31_85B5_05EAB0011123__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Control.h"
#include "DlgSet.h"
#include "DlgSetEfficiency.h"

class CControl_SystemView : public CView
{
protected: // create from serialization only
	CControl_SystemView();
	DECLARE_DYNCREATE(CControl_SystemView)

// Attributes
public:
	CControl_SystemDoc* GetDocument();

// Operations
public:
	CControl m_control;
	CDlgSet m_set;
	CDlgSetEfficiency m_set_XL;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CControl_SystemView)
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
	virtual ~CControl_SystemView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CControl_SystemView)
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnMStart();
	afx_msg void OnMStop();
	afx_msg void OnMSet();
	afx_msg void OnMRestart();
	afx_msg void OnMYunSu();
	afx_msg void OnMYunJiaSu();
	afx_msg void OnMZhengXian();
	afx_msg void OnMWeiYi();
	afx_msg void OnMSuDu();
	afx_msg void OnMJiaSuDu();
	afx_msg void OnMAllCurve();
	afx_msg void OnMFriction();
	afx_msg void OnMEfficiency();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Control_SystemView.cpp
inline CControl_SystemDoc* CControl_SystemView::GetDocument()
   { return (CControl_SystemDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONTROL_SYSTEMVIEW_H__AC07C2C6_115B_4D31_85B5_05EAB0011123__INCLUDED_)
