// 2_4Doc.cpp : implementation of the CMy2_4Doc class
//

#include "stdafx.h"
#include "2_4.h"

#include "2_4Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMy2_4Doc

IMPLEMENT_DYNCREATE(CMy2_4Doc, CDocument)

BEGIN_MESSAGE_MAP(CMy2_4Doc, CDocument)
	//{{AFX_MSG_MAP(CMy2_4Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy2_4Doc construction/destruction

CMy2_4Doc::CMy2_4Doc()
{
	// TODO: add one-time construction code here

}

CMy2_4Doc::~CMy2_4Doc()
{
}

BOOL CMy2_4Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMy2_4Doc serialization

void CMy2_4Doc::Serialize(CArchive& ar)
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
// CMy2_4Doc diagnostics

#ifdef _DEBUG
void CMy2_4Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMy2_4Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMy2_4Doc commands
