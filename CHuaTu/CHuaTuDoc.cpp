// CHuaTuDoc.cpp : implementation of the CCHuaTuDoc class
//

#include "stdafx.h"
#include "CHuaTu.h"

#include "CHuaTuDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCHuaTuDoc

IMPLEMENT_DYNCREATE(CCHuaTuDoc, CDocument)

BEGIN_MESSAGE_MAP(CCHuaTuDoc, CDocument)
	//{{AFX_MSG_MAP(CCHuaTuDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCHuaTuDoc construction/destruction

CCHuaTuDoc::CCHuaTuDoc()
{
	// TODO: add one-time construction code here

}

CCHuaTuDoc::~CCHuaTuDoc()
{
}

BOOL CCHuaTuDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CCHuaTuDoc serialization

void CCHuaTuDoc::Serialize(CArchive& ar)
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
// CCHuaTuDoc diagnostics

#ifdef _DEBUG
void CCHuaTuDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCHuaTuDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCHuaTuDoc commands
