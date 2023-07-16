// 2_4View.h : interface of the CMy2_4View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_2_4VIEW_H__5EB8B075_81EE_418A_BC16_758CDE35CEDA__INCLUDED_)
#define AFX_2_4VIEW_H__5EB8B075_81EE_418A_BC16_758CDE35CEDA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMy2_4View : public CView
{
protected: // create from serialization only
	CMy2_4View();
	DECLARE_DYNCREATE(CMy2_4View)

// Attributes
public:
	CMy2_4Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy2_4View)
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
	void DrawSqure(CDC *pDC, int x, int y, int w, int h);
	void DrawCircle(CDC *pDC, int x, int y, int r);
	virtual ~CMy2_4View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMy2_4View)
	afx_msg void OnMCircle();
	afx_msg void OnMSquare();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in 2_4View.cpp
inline CMy2_4Doc* CMy2_4View::GetDocument()
   { return (CMy2_4Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_2_4VIEW_H__5EB8B075_81EE_418A_BC16_758CDE35CEDA__INCLUDED_)
