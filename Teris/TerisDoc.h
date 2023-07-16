// TerisDoc.h : interface of the CTerisDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TERISDOC_H__49D0394D_B021_4C9E_82C3_81CC3758F074__INCLUDED_)
#define AFX_TERISDOC_H__49D0394D_B021_4C9E_82C3_81CC3758F074__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTerisDoc : public CDocument
{
protected: // create from serialization only
	CTerisDoc();
	DECLARE_DYNCREATE(CTerisDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTerisDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTerisDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTerisDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TERISDOC_H__49D0394D_B021_4C9E_82C3_81CC3758F074__INCLUDED_)
