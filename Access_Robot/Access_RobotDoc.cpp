// Access_RobotDoc.cpp : implementation of the CAccess_RobotDoc class
//

#include "stdafx.h"
#include "Access_Robot.h"

#include "Access_RobotDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAccess_RobotDoc

IMPLEMENT_DYNCREATE(CAccess_RobotDoc, CDocument)

BEGIN_MESSAGE_MAP(CAccess_RobotDoc, CDocument)
	//{{AFX_MSG_MAP(CAccess_RobotDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAccess_RobotDoc construction/destruction

CAccess_RobotDoc::CAccess_RobotDoc()
{
	// TODO: add one-time construction code here

}

CAccess_RobotDoc::~CAccess_RobotDoc()
{
}

BOOL CAccess_RobotDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CAccess_RobotDoc serialization

void CAccess_RobotDoc::Serialize(CArchive& ar)
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
// CAccess_RobotDoc diagnostics

#ifdef _DEBUG
void CAccess_RobotDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CAccess_RobotDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAccess_RobotDoc commands
