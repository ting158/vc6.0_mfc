// AccessTestDoc.cpp : implementation of the CAccessTestDoc class
//

#include "stdafx.h"
#include "AccessTest.h"

#include "AccessTestDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAccessTestDoc

IMPLEMENT_DYNCREATE(CAccessTestDoc, CDocument)

BEGIN_MESSAGE_MAP(CAccessTestDoc, CDocument)
	//{{AFX_MSG_MAP(CAccessTestDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAccessTestDoc construction/destruction

CAccessTestDoc::CAccessTestDoc()
{
	// TODO: add one-time construction code here

}

CAccessTestDoc::~CAccessTestDoc()
{
}

BOOL CAccessTestDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CAccessTestDoc serialization

void CAccessTestDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CAccessTestDoc diagnostics

#ifdef _DEBUG
void CAccessTestDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CAccessTestDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAccessTestDoc commands
