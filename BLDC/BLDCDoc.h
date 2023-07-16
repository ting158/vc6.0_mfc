// BLDCDoc.h : interface of the CBLDCDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BLDCDOC_H__1FCEECC6_E47E_493C_B2EA_F94897D13F45__INCLUDED_)
#define AFX_BLDCDOC_H__1FCEECC6_E47E_493C_B2EA_F94897D13F45__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CBLDCDoc : public CDocument
{
protected: // create from serialization only
	CBLDCDoc();
	DECLARE_DYNCREATE(CBLDCDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBLDCDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBLDCDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBLDCDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BLDCDOC_H__1FCEECC6_E47E_493C_B2EA_F94897D13F45__INCLUDED_)
