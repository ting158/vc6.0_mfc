// CTreeViewµÄÓÃ·¨Doc.h : interface of the CCTreeViewDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CTREEVIEWDOC_H__B722834A_9684_4468_84CB_578F37D92067__INCLUDED_)
#define AFX_CTREEVIEWDOC_H__B722834A_9684_4468_84CB_578F37D92067__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCTreeViewDoc : public CDocument
{
protected: // create from serialization only
	CCTreeViewDoc();
	DECLARE_DYNCREATE(CCTreeViewDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCTreeViewDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCTreeViewDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCTreeViewDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CTREEVIEWDOC_H__B722834A_9684_4468_84CB_578F37D92067__INCLUDED_)
