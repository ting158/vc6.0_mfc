// RobotsModelView.cpp : implementation of the CRobotsModelView class
//

#include "stdafx.h"
#include "RobotsModel.h"

#include "RobotsModelDoc.h"
#include "RobotsModelView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRobotsModelView

IMPLEMENT_DYNCREATE(CRobotsModelView, CView)

BEGIN_MESSAGE_MAP(CRobotsModelView, CView)
	//{{AFX_MSG_MAP(CRobotsModelView)
	ON_COMMAND(ID_M_ManageRobots, OnMManageRobots)
	ON_WM_TIMER()
	ON_COMMAND(ID_M_Start, OnMStart)
	ON_COMMAND(ID_M_Stop, OnMStop)
	ON_COMMAND(ID_M_Walk, OnMWalk)
	ON_COMMAND(ID_M_Jump, OnMJump)
	ON_COMMAND(ID_M_Wink, OnMWink)
	ON_COMMAND(ID_M_Wave, OnMWave)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRobotsModelView construction/destruction

CRobotsModelView::CRobotsModelView()
{
	// TODO: add construction code here

}

CRobotsModelView::~CRobotsModelView()
{
}

BOOL CRobotsModelView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CRobotsModelView drawing

void CRobotsModelView::OnDraw(CDC* pDC)
{
	CRobotsModelDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here


	m_robot.Draw(pDC);
}

/////////////////////////////////////////////////////////////////////////////
// CRobotsModelView printing

BOOL CRobotsModelView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CRobotsModelView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CRobotsModelView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CRobotsModelView diagnostics

#ifdef _DEBUG
void CRobotsModelView::AssertValid() const
{
	CView::AssertValid();
}

void CRobotsModelView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRobotsModelDoc* CRobotsModelView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRobotsModelDoc)));
	return (CRobotsModelDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRobotsModelView message handlers

void CRobotsModelView::OnMManageRobots() 
{
	// TODO: Add your command handler code here
//	m_dlgManage.DoModal();

	if (m_dlgManage.DoModal() == IDOK)
	{
		m_robot.m_id = atoi(m_dlgManage.m_strID);
		m_robot.InitRobot(m_robot.m_id);
	}

	Invalidate(true);
}

void CRobotsModelView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	
	m_robot.Move();

	Invalidate(true);

	CView::OnTimer(nIDEvent);
}

void CRobotsModelView::OnMStart() 
{
	// TODO: Add your command handler code here
	SetTimer(1, 100, NULL);
}

void CRobotsModelView::OnMStop() 
{
	// TODO: Add your command handler code here
	KillTimer(1);
}

void CRobotsModelView::OnMWalk() 
{
	// TODO: Add your command handler code here
	m_robot.m_MoveType = WALK;
}

void CRobotsModelView::OnMJump() 
{
	// TODO: Add your command handler code here
	m_robot.m_MoveType = JUMP;
}

void CRobotsModelView::OnMWink() 
{
	// TODO: Add your command handler code here
	m_robot.m_MoveType = WINK;
}

void CRobotsModelView::OnMWave() 
{
	// TODO: Add your command handler code here
	m_robot.m_MoveType = WAVE;
}
