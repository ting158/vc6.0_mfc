// Robot_TestDoc.cpp : implementation of the CRobot_TestDoc class
//

#include "stdafx.h"
#include "Robot_Test.h"

#include "Robot_TestDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRobot_TestDoc

IMPLEMENT_DYNCREATE(CRobot_TestDoc, CDocument)

BEGIN_MESSAGE_MAP(CRobot_TestDoc, CDocument)
	//{{AFX_MSG_MAP(CRobot_TestDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRobot_TestDoc construction/destruction

CRobot_TestDoc::CRobot_TestDoc()
{
	// TODO: add one-time construction code here

}

CRobot_TestDoc::~CRobot_TestDoc()
{
}

BOOL CRobot_TestDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CRobot_TestDoc serialization

void CRobot_TestDoc::Serialize(CArchive& ar)
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
// CRobot_TestDoc diagnostics

#ifdef _DEBUG
void CRobot_TestDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRobot_TestDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRobot_TestDoc commands
