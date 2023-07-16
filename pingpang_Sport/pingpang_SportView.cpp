// pingpang_SportView.cpp : implementation of the CPingpang_SportView class
//

#include "stdafx.h"
#include "pingpang_Sport.h"

#include "pingpang_SportDoc.h"
#include "pingpang_SportView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPingpang_SportView

IMPLEMENT_DYNCREATE(CPingpang_SportView, CView)

BEGIN_MESSAGE_MAP(CPingpang_SportView, CView)
	//{{AFX_MSG_MAP(CPingpang_SportView)
	ON_COMMAND(ID_M_Start, OnMStart)
	ON_COMMAND(ID_M_Stop, OnMStop)
	ON_COMMAND(ID_M_Set, OnMSet)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPingpang_SportView construction/destruction

CPingpang_SportView::CPingpang_SportView()
{
	// TODO: add construction code here

}

CPingpang_SportView::~CPingpang_SportView()
{
}

BOOL CPingpang_SportView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CPingpang_SportView drawing

void CPingpang_SportView::OnDraw(CDC* pDC)
{
	CPingpang_SportDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

	m_ball.Draw(pDC);
}

/////////////////////////////////////////////////////////////////////////////
// CPingpang_SportView printing

BOOL CPingpang_SportView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPingpang_SportView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPingpang_SportView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CPingpang_SportView diagnostics

#ifdef _DEBUG
void CPingpang_SportView::AssertValid() const
{
	CView::AssertValid();
}

void CPingpang_SportView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPingpang_SportDoc* CPingpang_SportView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPingpang_SportDoc)));
	return (CPingpang_SportDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPingpang_SportView message handlers

void CPingpang_SportView::OnMStart() 
{
	// TODO: Add your command handler code here
	SetTimer(1, 10, NULL);
}

void CPingpang_SportView::OnMStop() 
{
	// TODO: Add your command handler code here
	KillTimer(1);
}

void CPingpang_SportView::OnMSet() 
{
	// TODO: Add your command handler code here

	m_set.m_x = m_ball.m_x0;
	m_set.m_y = m_ball.m_y0;
	m_set.m_z = m_ball.m_z0;
	m_set.m_vx = m_ball.m_vx0;
	m_set.m_vy = m_ball.m_vy0;
	m_set.m_vz = m_ball.m_vz0;

	if (m_set.DoModal() == IDOK)
	{

		m_ball.m_x0 = m_set.m_x;
		m_ball.m_y0 = m_set.m_y;
		m_ball.m_z0 = m_set.m_z;
		m_ball.m_vx0 = m_set.m_vx;
		m_ball.m_vy0 = m_set.m_vy;
		m_ball.m_vz0 = m_set.m_vz;

		m_ball.initState();

		Invalidate(true);
	}
}

void CPingpang_SportView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	
	m_ball.Move();

	if (m_ball.m_x > m_ball.m_L || m_ball.m_x < -m_ball.m_L / 4)
		KillTimer(1);

	Invalidate(true);
	CView::OnTimer(nIDEvent);
}
