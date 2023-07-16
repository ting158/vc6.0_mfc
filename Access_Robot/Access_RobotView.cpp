// Access_RobotView.cpp : implementation of the CAccess_RobotView class
//

#include "stdafx.h"
#include "Access_Robot.h"

#include "Access_RobotDoc.h"
#include "Access_RobotView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAccess_RobotView

IMPLEMENT_DYNCREATE(CAccess_RobotView, CView)

BEGIN_MESSAGE_MAP(CAccess_RobotView, CView)
	//{{AFX_MSG_MAP(CAccess_RobotView)
	ON_COMMAND(ID_M_ConnectDatabase, OnMConnectDatabase)
	ON_COMMAND(ID_M_InitRobot, OnMInitRobot)
	ON_COMMAND(ID_M_Refresh, OnMRefresh)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAccess_RobotView construction/destruction

CAccess_RobotView::CAccess_RobotView()
{
	// TODO: add construction code here

}

CAccess_RobotView::~CAccess_RobotView()
{
}

BOOL CAccess_RobotView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CAccess_RobotView drawing

void CAccess_RobotView::OnDraw(CDC* pDC)
{
	CAccess_RobotDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

	m_robot.Draw(pDC);
}

/////////////////////////////////////////////////////////////////////////////
// CAccess_RobotView printing

BOOL CAccess_RobotView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CAccess_RobotView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CAccess_RobotView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CAccess_RobotView diagnostics

#ifdef _DEBUG
void CAccess_RobotView::AssertValid() const
{
	CView::AssertValid();
}

void CAccess_RobotView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CAccess_RobotDoc* CAccess_RobotView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAccess_RobotDoc)));
	return (CAccess_RobotDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAccess_RobotView message handlers

void CAccess_RobotView::OnMConnectDatabase() 
{
	// TODO: Add your command handler code here
	m_robot.ConnectDatabase();
}

void CAccess_RobotView::OnMInitRobot() 
{
	// TODO: Add your command handler code here
	m_robot.InitRobot();
}

void CAccess_RobotView::OnMRefresh() 
{
	// TODO: Add your command handler code here
	Invalidate(true);
}
