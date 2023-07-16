// Robot_CheckDoc.cpp : implementation of the CRobot_CheckDoc class
//

#include "stdafx.h"
#include "Robot_Check.h"

#include "Robot_CheckDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRobot_CheckDoc

IMPLEMENT_DYNCREATE(CRobot_CheckDoc, CDocument)

BEGIN_MESSAGE_MAP(CRobot_CheckDoc, CDocument)
	//{{AFX_MSG_MAP(CRobot_CheckDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRobot_CheckDoc construction/destruction

CRobot_CheckDoc::CRobot_CheckDoc()
{
	// TODO: add one-time construction code here

}

CRobot_CheckDoc::~CRobot_CheckDoc()
{
}

BOOL CRobot_CheckDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CRobot_CheckDoc serialization

void CRobot_CheckDoc::Serialize(CArchive& ar)
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
// CRobot_CheckDoc diagnostics

#ifdef _DEBUG
void CRobot_CheckDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRobot_CheckDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRobot_CheckDoc commands
