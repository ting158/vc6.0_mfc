// 2_8_对话框View.h : interface of the CMy2_8_View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_2_8_VIEW_H__AD774CBE_37CB_4559_A77A_BC3D33A053AF__INCLUDED_)
#define AFX_2_8_VIEW_H__AD774CBE_37CB_4559_A77A_BC3D33A053AF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMy2_8_View : public CView
{
public:
	int m_X;
	int m_Y;
	int m_R;
	int m_Pic;

protected: // create from serialization only
	CMy2_8_View();
	DECLARE_DYNCREATE(CMy2_8_View)

// Attributes
public:
	CMy2_8_Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy2_8_View)
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
	virtual ~CMy2_8_View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMy2_8_View)
	afx_msg void OnHuaYuan();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in 2_8_对话框View.cpp
inline CMy2_8_Doc* CMy2_8_View::GetDocument()
   { return (CMy2_8_Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_2_8_VIEW_H__AD774CBE_37CB_4559_A77A_BC3D33A053AF__INCLUDED_)
