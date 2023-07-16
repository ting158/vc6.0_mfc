// TankWarDoc.h : interface of the CTankWarDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TANKWARDOC_H__499C1FCB_7754_4740_A117_461D36B339FB__INCLUDED_)
#define AFX_TANKWARDOC_H__499C1FCB_7754_4740_A117_461D36B339FB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTankWarDoc : public CDocument
{
protected: // create from serialization only
	CTankWarDoc();
	DECLARE_DYNCREATE(CTankWarDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTankWarDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTankWarDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTankWarDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TANKWARDOC_H__499C1FCB_7754_4740_A117_461D36B339FB__INCLUDED_)
