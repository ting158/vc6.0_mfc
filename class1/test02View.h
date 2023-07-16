// test02View.h : interface of the CTest02View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TEST02VIEW_H__D6098590_F49A_44BE_AC19_99DA513E71B4__INCLUDED_)
#define AFX_TEST02VIEW_H__D6098590_F49A_44BE_AC19_99DA513E71B4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTest02View : public CView
{
protected: // create from serialization only
	CTest02View();
	DECLARE_DYNCREATE(CTest02View)

// Attributes
public:
	CTest02Doc* GetDocument();

// Operations
public:
	int x, y, r;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest02View)
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
	virtual ~CTest02View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTest02View)
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnHuaYuan();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnDongHua();
	afx_msg void OnTingZhi();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in test02View.cpp
inline CTest02Doc* CTest02View::GetDocument()
   { return (CTest02Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST02VIEW_H__D6098590_F49A_44BE_AC19_99DA513E71B4__INCLUDED_)
