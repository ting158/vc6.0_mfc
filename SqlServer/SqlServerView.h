// SqlServerView.h : interface of the CSqlServerView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SQLSERVERVIEW_H__33F6AAFB_B600_4193_9F8D_E5479D9C979C__INCLUDED_)
#define AFX_SQLSERVERVIEW_H__33F6AAFB_B600_4193_9F8D_E5479D9C979C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CSqlServerSet;

class CSqlServerView : public CRecordView
{
protected: // create from serialization only
	CSqlServerView();
	DECLARE_DYNCREATE(CSqlServerView)

public:
	//{{AFX_DATA(CSqlServerView)
	enum{ IDD = IDD_SQLSERVER_FORM };
	CSqlServerSet* m_pSet;
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:
	CSqlServerDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSqlServerView)
	public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSqlServerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSqlServerView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in SqlServerView.cpp
inline CSqlServerDoc* CSqlServerView::GetDocument()
   { return (CSqlServerDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SQLSERVERVIEW_H__33F6AAFB_B600_4193_9F8D_E5479D9C979C__INCLUDED_)
