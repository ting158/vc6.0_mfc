// SpringSportDoc.cpp : implementation of the CSpringSportDoc class
//

#include "stdafx.h"
#include "SpringSport.h"

#include "SpringSportDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSpringSportDoc

IMPLEMENT_DYNCREATE(CSpringSportDoc, CDocument)

BEGIN_MESSAGE_MAP(CSpringSportDoc, CDocument)
	//{{AFX_MSG_MAP(CSpringSportDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSpringSportDoc construction/destruction

CSpringSportDoc::CSpringSportDoc()
{
	// TODO: add one-time construction code here

}

CSpringSportDoc::~CSpringSportDoc()
{
}

BOOL CSpringSportDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSpringSportDoc serialization

void CSpringSportDoc::Serialize(CArchive& ar)
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
// CSpringSportDoc diagnostics

#ifdef _DEBUG
void CSpringSportDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSpringSportDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSpringSportDoc commands
