// Robot_CheckDoc.h : interface of the CRobot_CheckDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ROBOT_CHECKDOC_H__EA3603D4_91ED_4050_ABD9_789E16AD2F07__INCLUDED_)
#define AFX_ROBOT_CHECKDOC_H__EA3603D4_91ED_4050_ABD9_789E16AD2F07__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CRobot_CheckDoc : public CDocument
{
protected: // create from serialization only
	CRobot_CheckDoc();
	DECLARE_DYNCREATE(CRobot_CheckDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRobot_CheckDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CRobot_CheckDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CRobot_CheckDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ROBOT_CHECKDOC_H__EA3603D4_91ED_4050_ABD9_789E16AD2F07__INCLUDED_)
