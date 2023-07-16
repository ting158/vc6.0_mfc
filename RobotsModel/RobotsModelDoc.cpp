// RobotsModelDoc.cpp : implementation of the CRobotsModelDoc class
//

#include "stdafx.h"
#include "RobotsModel.h"

#include "RobotsModelDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRobotsModelDoc

IMPLEMENT_DYNCREATE(CRobotsModelDoc, CDocument)

BEGIN_MESSAGE_MAP(CRobotsModelDoc, CDocument)
	//{{AFX_MSG_MAP(CRobotsModelDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRobotsModelDoc construction/destruction

CRobotsModelDoc::CRobotsModelDoc()
{
	// TODO: add one-time construction code here

}

CRobotsModelDoc::~CRobotsModelDoc()
{
}

BOOL CRobotsModelDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CRobotsModelDoc serialization

void CRobotsModelDoc::Serialize(CArchive& ar)
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
// CRobotsModelDoc diagnostics

#ifdef _DEBUG
void CRobotsModelDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRobotsModelDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRobotsModelDoc commands
