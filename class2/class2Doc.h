// class2Doc.h : interface of the CClass2Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CLASS2DOC_H__8EFD809F_292D_428C_B407_C69BE8E7A63F__INCLUDED_)
#define AFX_CLASS2DOC_H__8EFD809F_292D_428C_B407_C69BE8E7A63F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CClass2Doc : public CDocument
{
protected: // create from serialization only
	CClass2Doc();
	DECLARE_DYNCREATE(CClass2Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClass2Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CClass2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CClass2Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLASS2DOC_H__8EFD809F_292D_428C_B407_C69BE8E7A63F__INCLUDED_)
