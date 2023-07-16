// TankWarDoc.cpp : implementation of the CTankWarDoc class
//

#include "stdafx.h"
#include "TankWar.h"

#include "TankWarDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTankWarDoc

IMPLEMENT_DYNCREATE(CTankWarDoc, CDocument)

BEGIN_MESSAGE_MAP(CTankWarDoc, CDocument)
	//{{AFX_MSG_MAP(CTankWarDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTankWarDoc construction/destruction

CTankWarDoc::CTankWarDoc()
{
	// TODO: add one-time construction code here

}

CTankWarDoc::~CTankWarDoc()
{
}

BOOL CTankWarDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTankWarDoc serialization

void CTankWarDoc::Serialize(CArchive& ar)
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
// CTankWarDoc diagnostics

#ifdef _DEBUG
void CTankWarDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTankWarDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTankWarDoc commands
