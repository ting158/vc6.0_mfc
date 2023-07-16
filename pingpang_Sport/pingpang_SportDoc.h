// pingpang_SportDoc.h : interface of the CPingpang_SportDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PINGPANG_SPORTDOC_H__8300CCD1_0AE7_4E2D_9D02_1D1A1B1ED9D0__INCLUDED_)
#define AFX_PINGPANG_SPORTDOC_H__8300CCD1_0AE7_4E2D_9D02_1D1A1B1ED9D0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPingpang_SportDoc : public CDocument
{
protected: // create from serialization only
	CPingpang_SportDoc();
	DECLARE_DYNCREATE(CPingpang_SportDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPingpang_SportDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPingpang_SportDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPingpang_SportDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PINGPANG_SPORTDOC_H__8300CCD1_0AE7_4E2D_9D02_1D1A1B1ED9D0__INCLUDED_)
