// Robot_TestView.h : interface of the CRobot_TestView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ROBOT_TESTVIEW_H__7E2168E3_B870_43C8_B426_AE28B2AEE097__INCLUDED_)
#define AFX_ROBOT_TESTVIEW_H__7E2168E3_B870_43C8_B426_AE28B2AEE097__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Robot.h"
#include "DlgSelRobot.h"

class CRobot_TestView : public CView
{
protected: // create from serialization only
	CRobot_TestView();
	DECLARE_DYNCREATE(CRobot_TestView)

// Attributes
public:
	CRobot_TestDoc* GetDocument();
	CRobot m_Robot;
	CDlgSelRobot m_dlg;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRobot_TestView)
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
	virtual ~CRobot_TestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CRobot_TestView)
	afx_msg void OnMSelect();
	afx_msg void OnMUpdate();
	afx_msg void OnMCreate();
	afx_msg void OnMDeleteRobot();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Robot_TestView.cpp
inline CRobot_TestDoc* CRobot_TestView::GetDocument()
   { return (CRobot_TestDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ROBOT_TESTVIEW_H__7E2168E3_B870_43C8_B426_AE28B2AEE097__INCLUDED_)
