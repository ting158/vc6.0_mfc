// SinCosMoveDoc.cpp : implementation of the CSinCosMoveDoc class
//

#include "stdafx.h"
#include "SinCosMove.h"

#include "SinCosMoveDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSinCosMoveDoc

IMPLEMENT_DYNCREATE(CSinCosMoveDoc, CDocument)

BEGIN_MESSAGE_MAP(CSinCosMoveDoc, CDocument)
	//{{AFX_MSG_MAP(CSinCosMoveDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSinCosMoveDoc construction/destruction

CSinCosMoveDoc::CSinCosMoveDoc()
{
	// TODO: add one-time construction code here

}

CSinCosMoveDoc::~CSinCosMoveDoc()
{
}

BOOL CSinCosMoveDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSinCosMoveDoc serialization

void CSinCosMoveDoc::Serialize(CArchive& ar)
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
// CSinCosMoveDoc diagnostics

#ifdef _DEBUG
void CSinCosMoveDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSinCosMoveDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSinCosMoveDoc commands
