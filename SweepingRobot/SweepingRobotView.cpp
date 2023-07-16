// SweepingRobotView.cpp : implementation of the CSweepingRobotView class
//

#include "stdafx.h"
#include "SweepingRobot.h"

#include "SweepingRobotDoc.h"
#include "SweepingRobotView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSweepingRobotView

IMPLEMENT_DYNCREATE(CSweepingRobotView, CView)

BEGIN_MESSAGE_MAP(CSweepingRobotView, CView)
	//{{AFX_MSG_MAP(CSweepingRobotView)
	ON_WM_KEYDOWN()
	ON_WM_ERASEBKGND()
	ON_WM_TIMER()
	ON_COMMAND(ID_M_Stop, OnMStop)
	ON_COMMAND(ID_M_Start, OnMStart)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSweepingRobotView construction/destruction

CSweepingRobotView::CSweepingRobotView()
{
	// TODO: add construction code here

}

CSweepingRobotView::~CSweepingRobotView()
{
}

BOOL CSweepingRobotView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSweepingRobotView drawing

void CSweepingRobotView::OnDraw(CDC* pDC)
{
	CSweepingRobotDoc* pDoc = GetDocument();
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
	
	m_room.Draw(&MemDC);
	m_robot.Draw(&MemDC);

	pDC->BitBlt(0,0,nWidth,nHeight,&MemDC,0,0,SRCCOPY); 
    MemBitmap.DeleteObject(); 
    MemDC.DeleteDC(); 



}

/////////////////////////////////////////////////////////////////////////////
// CSweepingRobotView printing

BOOL CSweepingRobotView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSweepingRobotView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSweepingRobotView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSweepingRobotView diagnostics

#ifdef _DEBUG
void CSweepingRobotView::AssertValid() const
{
	CView::AssertValid();
}

void CSweepingRobotView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSweepingRobotDoc* CSweepingRobotView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSweepingRobotDoc)));
	return (CSweepingRobotDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSweepingRobotView message handlers

void CSweepingRobotView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	m_robot.MoveByKey(nChar);

	if (nChar == 65)  //按a加速
	{
		m_robot.m_voltage *= 1.2;
		m_robot.m_v *= 1.2;
		m_robot.m_vx *= 1.2;
		m_robot.m_vy *= 1.2;
	}
		
	if (nChar == 90)  //按z减速
	{
		m_robot.m_voltage *= 0.8;
		m_robot.m_v *= 0.8;
		m_robot.m_vx *= 0.8;
		m_robot.m_vy *= 0.8;
	}

	Invalidate(true);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

BOOL CSweepingRobotView::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	return true;
}

void CSweepingRobotView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	m_robot.Move();

	Invalidate(true);

	CView::OnTimer(nIDEvent);
}

void CSweepingRobotView::OnMStop() 
{
	// TODO: Add your command handler code here
	KillTimer(1);
}

void CSweepingRobotView::OnMStart() 
{
	// TODO: Add your command handler code here
	SetTimer(1, 20, NULL);
}
