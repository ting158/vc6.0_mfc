// picture¿Ø¼þView.h : interface of the CPictureView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PICTUREVIEW_H__B5B5486B_743E_426D_89E5_20798E984373__INCLUDED_)
#define AFX_PICTUREVIEW_H__B5B5486B_743E_426D_89E5_20798E984373__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPictureView : public CView
{
protected: // create from serialization only
	CPictureView();
	DECLARE_DYNCREATE(CPictureView)

// Attributes
public:
	CPictureDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPictureView)
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
	virtual ~CPictureView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPictureView)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in picture¿Ø¼þView.cpp
inline CPictureDoc* CPictureView::GetDocument()
   { return (CPictureDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PICTUREVIEW_H__B5B5486B_743E_426D_89E5_20798E984373__INCLUDED_)
