// testView.cpp : implementation of the CTestView class
//

#include "stdafx.h"
#include "test.h"

#include "testDoc.h"
#include "testView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestView

IMPLEMENT_DYNCREATE(CTestView, CView)

BEGIN_MESSAGE_MAP(CTestView, CView)
	//{{AFX_MSG_MAP(CTestView)
	ON_COMMAND(ID_M_Start, OnMStart)
	ON_COMMAND(ID_M_Stop, OnMStop)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestView construction/destruction

CTestView::CTestView()
{
	// TODO: add construction code here
	 m_spring.posL.x = 200;
	 m_spring.posL.y = 100;
	 m_spring.width = 100.0;
  	 m_spring.len = 200.0; //初始化弹簧形状大小
	 m_spring.s = 0.0; //弹簧拉伸的位移，向下为正，向上为负
	 m_spring.k = 100.0; //设定弹性系数（牛顿/米）
	 m_object.center.x = m_spring.posL.x + m_spring.width/2;
	 m_object.center.y = m_spring.posL.y + m_spring.len + m_spring.s + 50; //初始化重物
	 m_object.radius = 30;
	 m_object.m = 3.0; //重物质量（千克）
	 m_object.v = 30.0; //重物初速度
}

CTestView::~CTestView()
{
}

BOOL CTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTestView drawing

void CTestView::OnDraw(CDC* pDC)
{
	CTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

	//画悬挂弹簧的两条牵引线
	pDC->MoveTo(m_spring.posL.x - 50,0);
	pDC->LineTo(m_spring.posL.x,m_spring.posL.y);
	pDC->MoveTo(m_spring.posL.x + m_spring.width + 50,0);
	pDC->LineTo(m_spring.posL.x + m_spring.width,m_spring.posL.y);

	DrawSpring(pDC,m_spring); //画弹簧
	DrawObject(pDC,m_object); //画重物
	DrawLine(pDC,m_spring,m_object);//画弹簧和重物之间的连线
}

/////////////////////////////////////////////////////////////////////////////
// CTestView printing

BOOL CTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTestView diagnostics

#ifdef _DEBUG
void CTestView::AssertValid() const
{
	CView::AssertValid();
}

void CTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTestDoc* CTestView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTestDoc)));
	return (CTestDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTestView message handlers

void CTestView::DrawSpring(CDC *pDC, MySpring spring)
{
	pDC->Rectangle(spring.posL.x,spring.posL.y,spring.posL.x + spring.width,spring.posL.y + spring.len); //画矩形
}

void CTestView::DrawObject(CDC *pDC, MyObject object)
{
	CBrush brush;
	brush.CreateSolidBrush(RGB(0,0,0)); //画黑色物体
	pDC->SelectObject(&brush);
	pDC->BeginPath();
	pDC->Ellipse(object.center.x - object.radius,object.center.y - object.radius,object.center.x + object.radius,object.center.y + object.radius); //画圆
	pDC->EndPath();
	pDC->FillPath();
}

void CTestView::DrawLine(CDC *pDC, MySpring spring, MyObject object)
{
	pDC->MoveTo(spring.posL.x + spring.width/2,spring.posL.y + spring.len); //线的起点
	pDC->LineTo(object.center); //线的终点
}

void CTestView::OnMStart() 
{
	// TODO: Add your command handler code here
	SetTimer(1,30,NULL);
}

void CTestView::OnMStop() 
{
	// TODO: Add your command handler code here
	KillTimer(1);
}

void CTestView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	float delta_s; //在0.01秒的时间段里，物体产生的位移的增量（有正有负）
	float delta_t = 0.01; 
	m_object.a = (m_object.m*9.8 - m_spring.k*m_spring.s)/m_object.m; //m*g - k*s = m*a
	delta_s = 0.5*(m_object.v + m_object.v + m_object.a*delta_t)*delta_t; //s = v*t + (a*t*t)/2
	m_spring.s += delta_s;
	m_spring.len += m_spring.s; //计算弹簧长度的变化
	m_object.center.y = m_spring.posL.y + m_spring.len + 50;
	m_object.v = (m_object.v + m_object.a*delta_t); //v = v0 + a*t
	Invalidate(true);
	CView::OnTimer(nIDEvent);
}
