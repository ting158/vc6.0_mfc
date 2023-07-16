// RobotModelDoc.cpp : implementation of the CRobotModelDoc class
//

#include "stdafx.h"
#include "RobotModel.h"

#include "RobotModelDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRobotModelDoc

IMPLEMENT_DYNCREATE(CRobotModelDoc, CDocument)

BEGIN_MESSAGE_MAP(CRobotModelDoc, CDocument)
	//{{AFX_MSG_MAP(CRobotModelDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRobotModelDoc construction/destruction

CRobotModelDoc::CRobotModelDoc()
{
	// TODO: add one-time construction code here

}

CRobotModelDoc::~CRobotModelDoc()
{
}

BOOL CRobotModelDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CRobotModelDoc serialization

void CRobotModelDoc::Serialize(CArchive& ar)
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
// CRobotModelDoc diagnostics

#ifdef _DEBUG
void CRobotModelDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRobotModelDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRobotModelDoc commands
