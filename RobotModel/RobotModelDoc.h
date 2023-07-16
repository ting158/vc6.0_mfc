// RobotModelDoc.h : interface of the CRobotModelDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ROBOTMODELDOC_H__E6B301C5_0BB2_4857_831D_15133134B438__INCLUDED_)
#define AFX_ROBOTMODELDOC_H__E6B301C5_0BB2_4857_831D_15133134B438__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CRobotModelDoc : public CDocument
{
protected: // create from serialization only
	CRobotModelDoc();
	DECLARE_DYNCREATE(CRobotModelDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRobotModelDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CRobotModelDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CRobotModelDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ROBOTMODELDOC_H__E6B301C5_0BB2_4857_831D_15133134B438__INCLUDED_)
