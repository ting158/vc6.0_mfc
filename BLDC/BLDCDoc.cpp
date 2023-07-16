// BLDCDoc.cpp : implementation of the CBLDCDoc class
//

#include "stdafx.h"
#include "BLDC.h"

#include "BLDCDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBLDCDoc

IMPLEMENT_DYNCREATE(CBLDCDoc, CDocument)

BEGIN_MESSAGE_MAP(CBLDCDoc, CDocument)
	//{{AFX_MSG_MAP(CBLDCDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBLDCDoc construction/destruction

CBLDCDoc::CBLDCDoc()
{
	// TODO: add one-time construction code here

}

CBLDCDoc::~CBLDCDoc()
{
}

BOOL CBLDCDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CBLDCDoc serialization

void CBLDCDoc::Serialize(CArchive& ar)
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
// CBLDCDoc diagnostics

#ifdef _DEBUG
void CBLDCDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CBLDCDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBLDCDoc commands
