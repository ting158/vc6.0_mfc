// AccessTestDoc.h : interface of the CAccessTestDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ACCESSTESTDOC_H__0EA9FD7C_A85C_4BB8_AC80_327DD0D2716E__INCLUDED_)
#define AFX_ACCESSTESTDOC_H__0EA9FD7C_A85C_4BB8_AC80_327DD0D2716E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CAccessTestDoc : public CDocument
{
protected: // create from serialization only
	CAccessTestDoc();
	DECLARE_DYNCREATE(CAccessTestDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAccessTestDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CAccessTestDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CAccessTestDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ACCESSTESTDOC_H__0EA9FD7C_A85C_4BB8_AC80_327DD0D2716E__INCLUDED_)
