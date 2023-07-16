// SinCosMoveDoc.h : interface of the CSinCosMoveDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SINCOSMOVEDOC_H__1FC767F0_9C8F_4246_9FE3_0086BA5006DD__INCLUDED_)
#define AFX_SINCOSMOVEDOC_H__1FC767F0_9C8F_4246_9FE3_0086BA5006DD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSinCosMoveDoc : public CDocument
{
protected: // create from serialization only
	CSinCosMoveDoc();
	DECLARE_DYNCREATE(CSinCosMoveDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSinCosMoveDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSinCosMoveDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSinCosMoveDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SINCOSMOVEDOC_H__1FC767F0_9C8F_4246_9FE3_0086BA5006DD__INCLUDED_)
