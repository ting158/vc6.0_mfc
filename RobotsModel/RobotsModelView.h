// RobotsModelView.h : interface of the CRobotsModelView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ROBOTSMODELVIEW_H__2C338AD6_9F08_4121_83EF_306A082148F0__INCLUDED_)
#define AFX_ROBOTSMODELVIEW_H__2C338AD6_9F08_4121_83EF_306A082148F0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Robots.h"
#include "Dlg_ExistingRobots.h"

class CRobotsModelView : public CView
{
protected: // create from serialization only
	CRobotsModelView();
	DECLARE_DYNCREATE(CRobotsModelView)

// Attributes
public:
	CRobotsModelDoc* GetDocument();

// Operations
public:
	CRobots m_robot;
	CDlg_ExistingRobots m_dlgManage;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRobotsModelView)
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
	virtual ~CRobotsModelView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CRobotsModelView)
	afx_msg void OnMManageRobots();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnMStart();
	afx_msg void OnMStop();
	afx_msg void OnMWalk();
	afx_msg void OnMJump();
	afx_msg void OnMWink();
	afx_msg void OnMWave();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in RobotsModelView.cpp
inline CRobotsModelDoc* CRobotsModelView::GetDocument()
   { return (CRobotsModelDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ROBOTSMODELVIEW_H__2C338AD6_9F08_4121_83EF_306A082148F0__INCLUDED_)
