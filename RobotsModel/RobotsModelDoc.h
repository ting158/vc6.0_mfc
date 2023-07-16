// RobotsModelDoc.h : interface of the CRobotsModelDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ROBOTSMODELDOC_H__FF417AC6_B648_4BAF_855E_01BCEA7076C8__INCLUDED_)
#define AFX_ROBOTSMODELDOC_H__FF417AC6_B648_4BAF_855E_01BCEA7076C8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CRobotsModelDoc : public CDocument
{
protected: // create from serialization only
	CRobotsModelDoc();
	DECLARE_DYNCREATE(CRobotsModelDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRobotsModelDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CRobotsModelDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CRobotsModelDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ROBOTSMODELDOC_H__FF417AC6_B648_4BAF_855E_01BCEA7076C8__INCLUDED_)
