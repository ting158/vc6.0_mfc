// 2_8_对话框Doc.cpp : implementation of the CMy2_8_Doc class
//

#include "stdafx.h"
#include "2_8_对话框.h"

#include "2_8_对话框Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMy2_8_Doc

IMPLEMENT_DYNCREATE(CMy2_8_Doc, CDocument)

BEGIN_MESSAGE_MAP(CMy2_8_Doc, CDocument)
	//{{AFX_MSG_MAP(CMy2_8_Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy2_8_Doc construction/destruction

CMy2_8_Doc::CMy2_8_Doc()
{
	// TODO: add one-time construction code here

}

CMy2_8_Doc::~CMy2_8_Doc()
{
}

BOOL CMy2_8_Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMy2_8_Doc serialization

void CMy2_8_Doc::Serialize(CArchive& ar)
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
// CMy2_8_Doc diagnostics

#ifdef _DEBUG
void CMy2_8_Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMy2_8_Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMy2_8_Doc commands
