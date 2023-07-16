// SqlServerSet.cpp : implementation of the CSqlServerSet class
//

#include "stdafx.h"
#include "SqlServer.h"
#include "SqlServerSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSqlServerSet implementation

IMPLEMENT_DYNAMIC(CSqlServerSet, CRecordset)

CSqlServerSet::CSqlServerSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CSqlServerSet)
	m_no = 0;
	m_name = _T("");
	m_passWord = _T("");
	m_other = _T("");
	m_nFields = 4;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}

CString CSqlServerSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=Test");
}

CString CSqlServerSet::GetDefaultSQL()
{
	return _T("[dbo].[baseInfor]");
}

void CSqlServerSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CSqlServerSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[no]"), m_no);
	RFX_Text(pFX, _T("[name]"), m_name);
	RFX_Text(pFX, _T("[passWord]"), m_passWord);
	RFX_Text(pFX, _T("[other]"), m_other);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CSqlServerSet diagnostics

#ifdef _DEBUG
void CSqlServerSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CSqlServerSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
