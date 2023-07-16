// SweepingRobotView.h : interface of the CSweepingRobotView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SWEEPINGROBOTVIEW_H__03FF073A_D5C2_44CD_B995_8774A5DDD8EC__INCLUDED_)
#define AFX_SWEEPINGROBOTVIEW_H__03FF073A_D5C2_44CD_B995_8774A5DDD8EC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Room.h"
#include "Robot.h"

class CSweepingRobotView : public CView
{
protected: // create from serialization only
	CSweepingRobotView();
	DECLARE_DYNCREATE(CSweepingRobotView)

// Attributes
public:
	CSweepingRobotDoc* GetDocument();

// Operations
public:
	CRoom m_room;
	CRobot m_robot;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSweepingRobotView)
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
	virtual ~CSweepingRobotView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSweepingRobotView)
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnMStop();
	afx_msg void OnMStart();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in SweepingRobotView.cpp
inline CSweepingRobotDoc* CSweepingRobotView::GetDocument()
   { return (CSweepingRobotDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SWEEPINGROBOTVIEW_H__03FF073A_D5C2_44CD_B995_8774A5DDD8EC__INCLUDED_)
