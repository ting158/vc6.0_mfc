// RobotModelView.h : interface of the CRobotModelView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ROBOTMODELVIEW_H__D6991892_B5CD_48C0_BB23_7AF1B1D65ABC__INCLUDED_)
#define AFX_ROBOTMODELVIEW_H__D6991892_B5CD_48C0_BB23_7AF1B1D65ABC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Robot.h"

class CRobotModelView : public CView
{
protected: // create from serialization only
	CRobotModelView();
	DECLARE_DYNCREATE(CRobotModelView)

// Attributes
public:
	CRobotModelDoc* GetDocument();

// Operations
public:
	CRobot m_robot;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRobotModelView)
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
	virtual ~CRobotModelView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CRobotModelView)
	afx_msg void OnMRefresh();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnMStart();
	afx_msg void OnMStop();
	afx_msg void OnMWalk();
	afx_msg void OnMJump();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnMWink();
	afx_msg void OnMWave();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in RobotModelView.cpp
inline CRobotModelDoc* CRobotModelView::GetDocument()
   { return (CRobotModelDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ROBOTMODELVIEW_H__D6991892_B5CD_48C0_BB23_7AF1B1D65ABC__INCLUDED_)
