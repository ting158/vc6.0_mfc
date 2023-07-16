// test02Doc.h : interface of the CTest02Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TEST02DOC_H__572D8970_A109_4A57_8750_0290379627A1__INCLUDED_)
#define AFX_TEST02DOC_H__572D8970_A109_4A57_8750_0290379627A1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTest02Doc : public CDocument
{
protected: // create from serialization only
	CTest02Doc();
	DECLARE_DYNCREATE(CTest02Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest02Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTest02Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTest02Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST02DOC_H__572D8970_A109_4A57_8750_0290379627A1__INCLUDED_)
