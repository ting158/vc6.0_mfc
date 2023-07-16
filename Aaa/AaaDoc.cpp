// AaaDoc.cpp : implementation of the CAaaDoc class
//

#include "stdafx.h"
#include "Aaa.h"

#include "AaaDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAaaDoc

IMPLEMENT_DYNCREATE(CAaaDoc, CDocument)

BEGIN_MESSAGE_MAP(CAaaDoc, CDocument)
	//{{AFX_MSG_MAP(CAaaDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAaaDoc construction/destruction

CAaaDoc::CAaaDoc()
{
	// TODO: add one-time construction code here

}

CAaaDoc::~CAaaDoc()
{
}

BOOL CAaaDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CAaaDoc serialization

void CAaaDoc::Serialize(CArchive& ar)
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
// CAaaDoc diagnostics

#ifdef _DEBUG
void CAaaDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CAaaDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAaaDoc commands
