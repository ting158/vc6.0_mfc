// test02Doc.cpp : implementation of the CTest02Doc class
//

#include "stdafx.h"
#include "test02.h"

#include "test02Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTest02Doc

IMPLEMENT_DYNCREATE(CTest02Doc, CDocument)

BEGIN_MESSAGE_MAP(CTest02Doc, CDocument)
	//{{AFX_MSG_MAP(CTest02Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTest02Doc construction/destruction

CTest02Doc::CTest02Doc()
{
	// TODO: add one-time construction code here

}

CTest02Doc::~CTest02Doc()
{
}

BOOL CTest02Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTest02Doc serialization

void CTest02Doc::Serialize(CArchive& ar)
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
// CTest02Doc diagnostics

#ifdef _DEBUG
void CTest02Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTest02Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTest02Doc commands
