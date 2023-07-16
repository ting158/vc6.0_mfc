// Control_SystemDoc.cpp : implementation of the CControl_SystemDoc class
//

#include "stdafx.h"
#include "Control_System.h"

#include "Control_SystemDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CControl_SystemDoc

IMPLEMENT_DYNCREATE(CControl_SystemDoc, CDocument)

BEGIN_MESSAGE_MAP(CControl_SystemDoc, CDocument)
	//{{AFX_MSG_MAP(CControl_SystemDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CControl_SystemDoc construction/destruction

CControl_SystemDoc::CControl_SystemDoc()
{
	// TODO: add one-time construction code here

}

CControl_SystemDoc::~CControl_SystemDoc()
{
}

BOOL CControl_SystemDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CControl_SystemDoc serialization

void CControl_SystemDoc::Serialize(CArchive& ar)
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
// CControl_SystemDoc diagnostics

#ifdef _DEBUG
void CControl_SystemDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CControl_SystemDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CControl_SystemDoc commands
