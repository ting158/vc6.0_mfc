// SqlServerDoc.h : interface of the CSqlServerDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SQLSERVERDOC_H__E8D4D55D_A7A2_427A_BB99_4346F54346E3__INCLUDED_)
#define AFX_SQLSERVERDOC_H__E8D4D55D_A7A2_427A_BB99_4346F54346E3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "SqlServerSet.h"


class CSqlServerDoc : public CDocument
{
protected: // create from serialization only
	CSqlServerDoc();
	DECLARE_DYNCREATE(CSqlServerDoc)

// Attributes
public:
	CSqlServerSet m_sqlServerSet;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSqlServerDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSqlServerDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSqlServerDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SQLSERVERDOC_H__E8D4D55D_A7A2_427A_BB99_4346F54346E3__INCLUDED_)
