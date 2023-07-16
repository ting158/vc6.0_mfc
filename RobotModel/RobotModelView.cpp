// RobotModelView.cpp : implementation of the CRobotModelView class
//

#include "stdafx.h"
#include "RobotModel.h"

#include "RobotModelDoc.h"
#include "RobotModelView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRobotModelView

IMPLEMENT_DYNCREATE(CRobotModelView, CView)

BEGIN_MESSAGE_MAP(CRobotModelView, CView)
	//{{AFX_MSG_MAP(CRobotModelView)
	ON_COMMAND(ID_M_Refresh, OnMRefresh)
	ON_WM_TIMER()
	ON_COMMAND(ID_M_Start, OnMStart)
	ON_COMMAND(ID_M_Stop, OnMStop)
	ON_COMMAND(ID_M_Walk, OnMWalk)
	ON_COMMAND(ID_M_Jump, OnMJump)
	ON_WM_ERASEBKGND()
	ON_COMMAND(ID_M_Wink, OnMWink)
	ON_COMMAND(ID_M_Wave, OnMWave)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRobotModelView construction/destruction

CRobotModelView::CRobotModelView()
{
	// TODO: add construction code here

}

CRobotModelView::~CRobotModelView()
{
}

BOOL CRobotModelView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CRobotModelView drawing

void CRobotModelView::OnDraw(CDC* pDC)
{
	CRobotModelDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CDC MemDC; //定义一个新的CDC变量，用于将绘图先画入到内存中，从而实现双缓存
	int nWidth,nHeight; 
	CRect  rect; //获取当前View的大小，宽度为nWidth，高度为nHeight，单位是像素
	CBitmap MemBitmap;
    GetWindowRect(&rect); 
    nWidth = rect.Width(); 
    nHeight= rect.Height(); 
	MemDC.CreateCompatibleDC(NULL); 
	MemBitmap.CreateCompatibleBitmap(pDC,nWidth,nHeight); 
	CBitmap *pOldBit=MemDC.SelectObject(&MemBitmap); 
	MemDC.FillSolidRect(0,0,nWidth,nHeight,RGB(255,255,255));

	m_robot.Draw(&MemDC);

	pDC->BitBlt(0,0,nWidth,nHeight,&MemDC,0,0,SRCCOPY); 
    MemBitmap.DeleteObject(); 
    MemDC.DeleteDC(); 


}

/////////////////////////////////////////////////////////////////////////////
// CRobotModelView printing

BOOL CRobotModelView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CRobotModelView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CRobotModelView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CRobotModelView diagnostics

#ifdef _DEBUG
void CRobotModelView::AssertValid() const
{
	CView::AssertValid();
}

void CRobotModelView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRobotModelDoc* CRobotModelView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRobotModelDoc)));
	return (CRobotModelDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRobotModelView message handlers

void CRobotModelView::OnMRefresh() 
{
	// TODO: Add your command handler code here
	m_robot.CreateRobot();

	Invalidate(true);
}

void CRobotModelView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	
	m_robot.Move();

	Invalidate(true);

	CView::OnTimer(nIDEvent);
}

void CRobotModelView::OnMStart() 
{
	// TODO: Add your command handler code here
	SetTimer(1, 100, NULL);
}

void CRobotModelView::OnMStop() 
{
	// TODO: Add your command handler code here
	KillTimer(1);
}

void CRobotModelView::OnMWalk() 
{
	// TODO: Add your command handler code here
	m_robot.m_MoveType = WALK;
}

void CRobotModelView::OnMJump() 
{
	// TODO: Add your command handler code here
	m_robot.m_MoveType = JUMP;
}

BOOL CRobotModelView::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	
	return true;
}

void CRobotModelView::OnMWink() 
{
	// TODO: Add your command handler code here
	m_robot.m_MoveType = WINK;
}

void CRobotModelView::OnMWave() 
{
	// TODO: Add your command handler code here
	m_robot.m_MoveType = WAVE;
}
