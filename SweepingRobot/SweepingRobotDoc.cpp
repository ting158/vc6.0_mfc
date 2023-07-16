// SweepingRobotDoc.cpp : implementation of the CSweepingRobotDoc class
//

#include "stdafx.h"
#include "SweepingRobot.h"

#include "SweepingRobotDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSweepingRobotDoc

IMPLEMENT_DYNCREATE(CSweepingRobotDoc, CDocument)

BEGIN_MESSAGE_MAP(CSweepingRobotDoc, CDocument)
	//{{AFX_MSG_MAP(CSweepingRobotDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSweepingRobotDoc construction/destruction

CSweepingRobotDoc::CSweepingRobotDoc()
{
	// TODO: add one-time construction code here

}

CSweepingRobotDoc::~CSweepingRobotDoc()
{
}

BOOL CSweepingRobotDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSweepingRobotDoc serialization

void CSweepingRobotDoc::Serialize(CArchive& ar)
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
// CSweepingRobotDoc diagnostics

#ifdef _DEBUG
void CSweepingRobotDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSweepingRobotDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSweepingRobotDoc commands
