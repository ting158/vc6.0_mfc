// AabDoc.cpp : implementation of the CAabDoc class
//

#include "stdafx.h"
#include "Aab.h"

#include "AabDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAabDoc

IMPLEMENT_DYNCREATE(CAabDoc, CDocument)

BEGIN_MESSAGE_MAP(CAabDoc, CDocument)
	//{{AFX_MSG_MAP(CAabDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAabDoc construction/destruction

CAabDoc::CAabDoc()
{
	// TODO: add one-time construction code here

}

CAabDoc::~CAabDoc()
{
}

BOOL CAabDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CAabDoc serialization

void CAabDoc::Serialize(CArchive& ar)
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
// CAabDoc diagnostics

#ifdef _DEBUG
void CAabDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CAabDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAabDoc commands
