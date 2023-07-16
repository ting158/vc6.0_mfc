// pingpang_SportDoc.cpp : implementation of the CPingpang_SportDoc class
//

#include "stdafx.h"
#include "pingpang_Sport.h"

#include "pingpang_SportDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPingpang_SportDoc

IMPLEMENT_DYNCREATE(CPingpang_SportDoc, CDocument)

BEGIN_MESSAGE_MAP(CPingpang_SportDoc, CDocument)
	//{{AFX_MSG_MAP(CPingpang_SportDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPingpang_SportDoc construction/destruction

CPingpang_SportDoc::CPingpang_SportDoc()
{
	// TODO: add one-time construction code here

}

CPingpang_SportDoc::~CPingpang_SportDoc()
{
}

BOOL CPingpang_SportDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CPingpang_SportDoc serialization

void CPingpang_SportDoc::Serialize(CArchive& ar)
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
// CPingpang_SportDoc diagnostics

#ifdef _DEBUG
void CPingpang_SportDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPingpang_SportDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPingpang_SportDoc commands
