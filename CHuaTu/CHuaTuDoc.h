// CHuaTuDoc.h : interface of the CCHuaTuDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHUATUDOC_H__A34A6854_ECA1_4D40_ABBA_D8086C62789A__INCLUDED_)
#define AFX_CHUATUDOC_H__A34A6854_ECA1_4D40_ABBA_D8086C62789A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCHuaTuDoc : public CDocument
{
protected: // create from serialization only
	CCHuaTuDoc();
	DECLARE_DYNCREATE(CCHuaTuDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCHuaTuDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCHuaTuDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCHuaTuDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHUATUDOC_H__A34A6854_ECA1_4D40_ABBA_D8086C62789A__INCLUDED_)
