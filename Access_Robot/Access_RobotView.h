// Access_RobotView.h : interface of the CAccess_RobotView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ACCESS_ROBOTVIEW_H__B21D2881_4A7D_4627_9172_69017F384BE3__INCLUDED_)
#define AFX_ACCESS_ROBOTVIEW_H__B21D2881_4A7D_4627_9172_69017F384BE3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Robot.h"

class CAccess_RobotView : public CView
{
protected: // create from serialization only
	CAccess_RobotView();
	DECLARE_DYNCREATE(CAccess_RobotView)

// Attributes
public:
	CAccess_RobotDoc* GetDocument();

// Operations
public:
	CRobot m_robot;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAccess_RobotView)
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
	virtual ~CAccess_RobotView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CAccess_RobotView)
	afx_msg void OnMConnectDatabase();
	afx_msg void OnMInitRobot();
	afx_msg void OnMRefresh();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Access_RobotView.cpp
inline CAccess_RobotDoc* CAccess_RobotView::GetDocument()
   { return (CAccess_RobotDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ACCESS_ROBOTVIEW_H__B21D2881_4A7D_4627_9172_69017F384BE3__INCLUDED_)
