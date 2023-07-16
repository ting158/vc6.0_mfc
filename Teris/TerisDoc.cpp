// TerisDoc.cpp : implementation of the CTerisDoc class
//

#include "stdafx.h"
#include "Teris.h"

#include "TerisDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTerisDoc

IMPLEMENT_DYNCREATE(CTerisDoc, CDocument)

BEGIN_MESSAGE_MAP(CTerisDoc, CDocument)
	//{{AFX_MSG_MAP(CTerisDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTerisDoc construction/destruction

CTerisDoc::CTerisDoc()
{
	// TODO: add one-time construction code here

}

CTerisDoc::~CTerisDoc()
{
}

BOOL CTerisDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTerisDoc serialization

void CTerisDoc::Serialize(CArchive& ar)
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
// CTerisDoc diagnostics

#ifdef _DEBUG
void CTerisDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTerisDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTerisDoc commands
