// SweepingRobotDoc.h : interface of the CSweepingRobotDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SWEEPINGROBOTDOC_H__DB459971_7AC6_4BF5_9AE0_C9F9A6DD3C7A__INCLUDED_)
#define AFX_SWEEPINGROBOTDOC_H__DB459971_7AC6_4BF5_9AE0_C9F9A6DD3C7A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSweepingRobotDoc : public CDocument
{
protected: // create from serialization only
	CSweepingRobotDoc();
	DECLARE_DYNCREATE(CSweepingRobotDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSweepingRobotDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSweepingRobotDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSweepingRobotDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SWEEPINGROBOTDOC_H__DB459971_7AC6_4BF5_9AE0_C9F9A6DD3C7A__INCLUDED_)
