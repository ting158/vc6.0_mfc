// AaaDoc.h : interface of the CAaaDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_AAADOC_H__5250BC9E_05B7_4FB7_87D5_AA635AB79375__INCLUDED_)
#define AFX_AAADOC_H__5250BC9E_05B7_4FB7_87D5_AA635AB79375__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CAaaDoc : public CDocument
{
protected: // create from serialization only
	CAaaDoc();
	DECLARE_DYNCREATE(CAaaDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAaaDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CAaaDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CAaaDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AAADOC_H__5250BC9E_05B7_4FB7_87D5_AA635AB79375__INCLUDED_)
