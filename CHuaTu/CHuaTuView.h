// CHuaTuView.h : interface of the CCHuaTuView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHUATUVIEW_H__D4B55FE6_9CE5_44F1_AAA2_C1A6B20B3222__INCLUDED_)
#define AFX_CHUATUVIEW_H__D4B55FE6_9CE5_44F1_AAA2_C1A6B20B3222__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCHuaTuView : public CView
{
public:
	int m_Length;

public:
	int m_x,m_y;      //圆心坐标
	int m_r;
	int m_xIni,m_yIni;  //保存左键按下时的初始圆心坐标
	CPoint m_LBD;     //保存左键按下时的鼠标位置
	int m_BJ_LBD;     //标记，初始值为0，左键按下时为1，左键抬起时为0


protected: // create from serialization only
	CCHuaTuView();
	DECLARE_DYNCREATE(CCHuaTuView)

// Attributes
public:
	CCHuaTuDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCHuaTuView)
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
	virtual ~CCHuaTuView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCHuaTuView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in CHuaTuView.cpp
inline CCHuaTuDoc* CCHuaTuView::GetDocument()
   { return (CCHuaTuDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHUATUVIEW_H__D4B55FE6_9CE5_44F1_AAA2_C1A6B20B3222__INCLUDED_)
