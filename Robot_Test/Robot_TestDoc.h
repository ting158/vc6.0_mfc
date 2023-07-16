// Robot_TestDoc.h : interface of the CRobot_TestDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ROBOT_TESTDOC_H__C9A897A8_B459_4ED9_9B29_CE21F212F120__INCLUDED_)
#define AFX_ROBOT_TESTDOC_H__C9A897A8_B459_4ED9_9B29_CE21F212F120__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CRobot_TestDoc : public CDocument
{
protected: // create from serialization only
	CRobot_TestDoc();
	DECLARE_DYNCREATE(CRobot_TestDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRobot_TestDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CRobot_TestDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CRobot_TestDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ROBOT_TESTDOC_H__C9A897A8_B459_4ED9_9B29_CE21F212F120__INCLUDED_)
