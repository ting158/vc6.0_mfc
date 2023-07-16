// SqlServerDoc.cpp : implementation of the CSqlServerDoc class
//

#include "stdafx.h"
#include "SqlServer.h"

#include "SqlServerSet.h"
#include "SqlServerDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSqlServerDoc

IMPLEMENT_DYNCREATE(CSqlServerDoc, CDocument)

BEGIN_MESSAGE_MAP(CSqlServerDoc, CDocument)
	//{{AFX_MSG_MAP(CSqlServerDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSqlServerDoc construction/destruction

CSqlServerDoc::CSqlServerDoc()
{
	// TODO: add one-time construction code here

}

CSqlServerDoc::~CSqlServerDoc()
{
}

BOOL CSqlServerDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSqlServerDoc serialization

void CSqlServerDoc::Serialize(CArchive& ar)
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
// CSqlServerDoc diagnostics

#ifdef _DEBUG
void CSqlServerDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSqlServerDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSqlServerDoc commands
