// class2Doc.cpp : implementation of the CClass2Doc class
//

#include "stdafx.h"
#include "class2.h"

#include "class2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CClass2Doc

IMPLEMENT_DYNCREATE(CClass2Doc, CDocument)

BEGIN_MESSAGE_MAP(CClass2Doc, CDocument)
	//{{AFX_MSG_MAP(CClass2Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CClass2Doc construction/destruction

CClass2Doc::CClass2Doc()
{
	// TODO: add one-time construction code here

}

CClass2Doc::~CClass2Doc()
{
}

BOOL CClass2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CClass2Doc serialization

void CClass2Doc::Serialize(CArchive& ar)
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
// CClass2Doc diagnostics

#ifdef _DEBUG
void CClass2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CClass2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CClass2Doc commands
