// AaaView.h : interface of the CAaaView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_AAAVIEW_H__0CADFAD0_44D4_4A07_9991_F31DD7363C3B__INCLUDED_)
#define AFX_AAAVIEW_H__0CADFAD0_44D4_4A07_9991_F31DD7363C3B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CAaaView : public CView
{
public:
	int m_nPic; //表示当前要画哪一个图形
	int m_x;

protected: // create from serialization only
	CAaaView();
	DECLARE_DYNCREATE(CAaaView)

// Attributes
public:
	CAaaDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAaaView)
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
	void DrawSin(CDC *pDC, int init_x, int init_y, float a, float b);
	void DrawCircle(CDC *pDC, int x, int y, int r);
	void DrawSqure(CDC *pDC, int x, int y, int w, int h);
	virtual ~CAaaView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CAaaView)
	afx_msg void OnMCircle();
	afx_msg void OnMSquare();
	afx_msg void OnMDongHua();
	afx_msg void OnMStop();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnCanShuSheZhi();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in AaaView.cpp
inline CAaaDoc* CAaaView::GetDocument()
   { return (CAaaDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AAAVIEW_H__0CADFAD0_44D4_4A07_9991_F31DD7363C3B__INCLUDED_)
