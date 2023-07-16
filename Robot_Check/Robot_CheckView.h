// Robot_CheckView.h : interface of the CRobot_CheckView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ROBOT_CHECKVIEW_H__85763A6B_D124_4968_9FA5_2E31748D651B__INCLUDED_)
#define AFX_ROBOT_CHECKVIEW_H__85763A6B_D124_4968_9FA5_2E31748D651B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ChangJing.h"
#include "Car.h"
#include "DlgSet.h"
#include "WRJ.h"

class CRobot_CheckView : public CView
{
protected: // create from serialization only
	CRobot_CheckView();
	DECLARE_DYNCREATE(CRobot_CheckView)

// Attributes
public:
	CRobot_CheckDoc* GetDocument();

// Operations
public:
	CChangJing m_scene;
	CCar m_car;
	CDlgSet m_set;
	CWRJ m_wrj;
	CPoint m_tempYD;
	CPoint m_LBD;
	CPoint m_MBD;
	bool m_bjLBD;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRobot_CheckView)
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
	void ChuLiLBD();
	virtual ~CRobot_CheckView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CRobot_CheckView)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMDianNaDaoNa();
	afx_msg void OnMYunSuDaoMuBiaoDian();
	afx_msg void OnMZhuanQuan();
	afx_msg void OnMStart();
	afx_msg void OnMStop();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnMStartLuJing();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnMCarNotSpot();
	afx_msg void OnMFindXieLouDian();
	afx_msg void OnMStartXieLou();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnMDrawLiZi();
	afx_msg void OnMNotDrawLiZi();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Robot_CheckView.cpp
inline CRobot_CheckDoc* CRobot_CheckView::GetDocument()
   { return (CRobot_CheckDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ROBOT_CHECKVIEW_H__85763A6B_D124_4968_9FA5_2E31748D651B__INCLUDED_)
