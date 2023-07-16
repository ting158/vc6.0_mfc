// AabDoc.h : interface of the CAabDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_AABDOC_H__8486AC5F_8A5A_4F64_AB23_C613A58CD38A__INCLUDED_)
#define AFX_AABDOC_H__8486AC5F_8A5A_4F64_AB23_C613A58CD38A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CAabDoc : public CDocument
{
protected: // create from serialization only
	CAabDoc();
	DECLARE_DYNCREATE(CAabDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAabDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CAabDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CAabDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AABDOC_H__8486AC5F_8A5A_4F64_AB23_C613A58CD38A__INCLUDED_)
