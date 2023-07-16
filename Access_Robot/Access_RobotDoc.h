// Access_RobotDoc.h : interface of the CAccess_RobotDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ACCESS_ROBOTDOC_H__A725368A_C7A0_4956_9BF7_0D1CFBAC2EAE__INCLUDED_)
#define AFX_ACCESS_ROBOTDOC_H__A725368A_C7A0_4956_9BF7_0D1CFBAC2EAE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CAccess_RobotDoc : public CDocument
{
protected: // create from serialization only
	CAccess_RobotDoc();
	DECLARE_DYNCREATE(CAccess_RobotDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAccess_RobotDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CAccess_RobotDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CAccess_RobotDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ACCESS_ROBOTDOC_H__A725368A_C7A0_4956_9BF7_0D1CFBAC2EAE__INCLUDED_)
