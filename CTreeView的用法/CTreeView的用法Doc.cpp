// CTreeView的用法Doc.cpp : implementation of the CCTreeViewDoc class
//

#include "stdafx.h"
#include "CTreeView的用法.h"

#include "CTreeView的用法Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCTreeViewDoc

IMPLEMENT_DYNCREATE(CCTreeViewDoc, CDocument)

BEGIN_MESSAGE_MAP(CCTreeViewDoc, CDocument)
	//{{AFX_MSG_MAP(CCTreeViewDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCTreeViewDoc construction/destruction

CCTreeViewDoc::CCTreeViewDoc()
{
	// TODO: add one-time construction code here

}

CCTreeViewDoc::~CCTreeViewDoc()
{
}

BOOL CCTreeViewDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CCTreeViewDoc serialization

void CCTreeViewDoc::Serialize(CArchive& ar)
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
// CCTreeViewDoc diagnostics

#ifdef _DEBUG
void CCTreeViewDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCTreeViewDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCTreeViewDoc commands
