// class2View.h : interface of the CClass2View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CLASS2VIEW_H__C093C8F9_34B5_4B89_B836_FAC9A6F1F09D__INCLUDED_)
#define AFX_CLASS2VIEW_H__C093C8F9_34B5_4B89_B836_FAC9A6F1F09D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

typedef struct {
	float x;
	float y;
	float r;
	float vx;
	float vy;
}SCircle;

typedef struct {
	float x;
	float y;
	float w;
	float h;
	float vx;
	float vy;
}SRectangle;

typedef struct {
	float x;
	float y;
	float w;
	float h;
	float vx;
	float vy;
}STriangle;


class CClass2View : public CView
{
protected: // create from serialization only
	CClass2View();
	DECLARE_DYNCREATE(CClass2View)

// Attributes
public:
	CClass2Doc* GetDocument();

// Operations
public:
	int m_nCir, m_nRec, m_nTri;

	SCircle m_Cir[100];
	SRectangle m_Rec[100];
	STriangle m_Tri[100];

	int m_Pic;
	int m_LBD, m_LBU;

	int m_xBK, m_yBK, m_wBK;

	SCircle m_CirTemp;
	SRectangle m_RecTemp;
	STriangle m_TriTemp;
	
	CPoint m_ptD, m_ptU;
	CPoint m_ptM;
	CPoint m_ptMTemp;


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClass2View)
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
	void Move();
	void Insert();
	virtual ~CClass2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CClass2View)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnCircle();
	afx_msg void OnRectangle();
	afx_msg void OnTriangle();
	afx_msg void OnSport();
	afx_msg void OnStart();
	afx_msg void OnStop();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in class2View.cpp
inline CClass2Doc* CClass2View::GetDocument()
   { return (CClass2Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLASS2VIEW_H__C093C8F9_34B5_4B89_B836_FAC9A6F1F09D__INCLUDED_)
