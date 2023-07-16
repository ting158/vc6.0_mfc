// 3_4_2View.h : interface of the CMy3_4_2View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_3_4_2VIEW_H__B6361F55_ADCA_42A9_8950_24186534E68C__INCLUDED_)
#define AFX_3_4_2VIEW_H__B6361F55_ADCA_42A9_8950_24186534E68C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMy3_4_2View : public CView
{
protected: // create from serialization only
	CMy3_4_2View();
	DECLARE_DYNCREATE(CMy3_4_2View)

// Attributes
public:
	CMy3_4_2Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy3_4_2View)
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
	void read_write_file();
	virtual ~CMy3_4_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMy3_4_2View)
	afx_msg void OnMStart();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in 3_4_2View.cpp
inline CMy3_4_2Doc* CMy3_4_2View::GetDocument()
   { return (CMy3_4_2Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_3_4_2VIEW_H__B6361F55_ADCA_42A9_8950_24186534E68C__INCLUDED_)
