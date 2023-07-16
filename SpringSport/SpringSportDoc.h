// SpringSportDoc.h : interface of the CSpringSportDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SPRINGSPORTDOC_H__2FA7BE03_FB6E_4A71_90AB_1EAA6B49FED2__INCLUDED_)
#define AFX_SPRINGSPORTDOC_H__2FA7BE03_FB6E_4A71_90AB_1EAA6B49FED2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSpringSportDoc : public CDocument
{
protected: // create from serialization only
	CSpringSportDoc();
	DECLARE_DYNCREATE(CSpringSportDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSpringSportDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSpringSportDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSpringSportDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPRINGSPORTDOC_H__2FA7BE03_FB6E_4A71_90AB_1EAA6B49FED2__INCLUDED_)
