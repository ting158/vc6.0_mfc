// SqlServerSet.h : interface of the CSqlServerSet class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SQLSERVERSET_H__C846DCF3_03E3_429A_B5D2_F1C97863A1F2__INCLUDED_)
#define AFX_SQLSERVERSET_H__C846DCF3_03E3_429A_B5D2_F1C97863A1F2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CSqlServerSet : public CRecordset
{
public:
	CSqlServerSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CSqlServerSet)

// Field/Param Data
	//{{AFX_FIELD(CSqlServerSet, CRecordset)
	long	m_no;
	CString	m_name;
	CString	m_passWord;
	CString	m_other;
	//}}AFX_FIELD

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSqlServerSet)
	public:
	virtual CString GetDefaultConnect();	// Default connection string
	virtual CString GetDefaultSQL(); 	// default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SQLSERVERSET_H__C846DCF3_03E3_429A_B5D2_F1C97863A1F2__INCLUDED_)

