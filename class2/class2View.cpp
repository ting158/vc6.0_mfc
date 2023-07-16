// class2View.cpp : implementation of the CClass2View class
//

#include "stdafx.h"
#include "class2.h"

#include "class2Doc.h"
#include "class2View.h"
#include "math.h"
#include "time.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CClass2View

IMPLEMENT_DYNCREATE(CClass2View, CView)

BEGIN_MESSAGE_MAP(CClass2View, CView)
	//{{AFX_MSG_MAP(CClass2View)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_Circle, OnCircle)
	ON_COMMAND(ID_Rectangle, OnRectangle)
	ON_COMMAND(ID_Triangle, OnTriangle)
	ON_COMMAND(ID_Sport, OnSport)
	ON_COMMAND(ID_Start, OnStart)
	ON_COMMAND(ID_Stop, OnStop)
	ON_WM_TIMER()
	ON_WM_MOUSEWHEEL()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CClass2View construction/destruction

CClass2View::CClass2View()
{
	// TODO: add construction code here
	m_nCir = 0;
	m_nRec = 0;
	m_nTri = 0;
	m_Pic = 1;
	m_LBD = 0;
	m_xBK = 50;
	m_yBK = 50;
	m_wBK = 600;
}

CClass2View::~CClass2View()
{
}

BOOL CClass2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CClass2View drawing

void CClass2View::OnDraw(CDC* pDC)
{
	CClass2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	int i;
	int x, y, r;

	pDC->Rectangle(m_xBK, m_yBK, m_xBK + m_wBK, m_yBK + m_wBK);

	for (i = 0; i < m_nCir; i++) {
		x = m_Cir[i].x + m_xBK;
		y = m_Cir[i].y + m_yBK;
		r = m_Cir[i].r;
		pDC->Ellipse(x - r, y - r, x + r, y + r);
	}
	if (m_Pic == 1) {
		x = m_CirTemp.x;
		y = m_CirTemp.y;
		r = m_CirTemp.r;
		pDC->Ellipse(x - r, y - r, x + r, y + r);
	}


	int w, h;
	for (i = 0; i < m_nRec; i++) {
		x = m_Rec[i].x + m_xBK;
		y = m_Rec[i].y + m_yBK;
		w = m_Rec[i].w;
		h = m_Rec[i].h;
		pDC->Rectangle(x, y, x + w, y + h);
	}
	if (m_Pic == 2) {
		x = m_RecTemp.x;
		y = m_RecTemp.y;
		w = m_RecTemp.w;
		h = m_RecTemp.h;
		pDC->Rectangle(x, y, x + w, y + h);
	}


	CPoint p1, p2, p3;
	for (i = 0; i < m_nTri; i++) {
		x = m_Tri[i].x + m_xBK;
		y = m_Tri[i].y + m_yBK;
		w = m_Tri[i].w;
		h = m_Tri[i].h;
		p1.x = x;           p1.y = y;
		p2.x = x - w / 2;   p2.y = y + h;
		p3.x = p2.x + w;    p3.y = p2.y;
		pDC->MoveTo(p3);
		pDC->LineTo(p2);
		pDC->LineTo(p1);
		pDC->LineTo(p3);
	}
	if (m_Pic == 3) {
		x = m_TriTemp.x;
		y = m_TriTemp.y;
		w = m_TriTemp.w;
		h = m_TriTemp.h;
		p1.x = x;             p1.y = y;
		p2.x = x - w / 2;         p2.y = y + h;
		p3.x = p2.x + w;  p3.y = p2.y;
		pDC->MoveTo(p3);
		pDC->LineTo(p2);
		pDC->LineTo(p1);
		pDC->LineTo(p3);
	}



}

/////////////////////////////////////////////////////////////////////////////
// CClass2View printing

BOOL CClass2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CClass2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CClass2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CClass2View diagnostics

#ifdef _DEBUG
void CClass2View::AssertValid() const
{
	CView::AssertValid();
}

void CClass2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CClass2Doc* CClass2View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CClass2Doc)));
	return (CClass2Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CClass2View message handlers

void CClass2View::Insert()
{
	srand((int)time(NULL));

	if (m_Pic == 1) {
		m_Cir[m_nCir].x = m_ptD.x - m_xBK;
		m_Cir[m_nCir].y = m_ptD.y - m_yBK;
		m_Cir[m_nCir].r = sqrt((m_ptD.x - m_ptU.x) * (m_ptD.x - m_ptU.x) + (m_ptD.y - m_ptU.y) * (m_ptD.y - m_ptU.y));
		m_Cir[m_nCir].vx = rand() % 21 + 30;
		m_Cir[m_nCir].vy = rand() % 21 + 30;
		m_nCir++;
	}
	if (m_Pic == 2) {
		m_Rec[m_nRec].x = m_ptD.x - m_xBK;
		m_Rec[m_nRec].y = m_ptD.y - m_yBK;
		m_Rec[m_nRec].w = m_ptU.x - m_ptD.x;
		m_Rec[m_nRec].h = m_ptU.y - m_ptD.y;
		m_Rec[m_nRec].vx = rand() % 21 + 30;
		m_Rec[m_nRec].vy = rand() % 21 + 30;
		m_nRec++;
	}
	if (m_Pic == 3) {
		m_Tri[m_nTri].x = m_ptD.x - m_xBK;
		m_Tri[m_nTri].y = m_ptD.y - m_yBK;
		m_Tri[m_nTri].w = (m_ptU.x - m_ptD.x) * 2;
		m_Tri[m_nTri].h = m_ptU.y - m_ptD.y;
		m_Tri[m_nTri].vx = rand() % 21 + 30;
		m_Tri[m_nTri].vy = rand() % 21 + 30;
		m_nTri++;
	}
}


void CClass2View::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_LBD = 1;
	m_ptD = point;

	m_ptMTemp = point;

	m_CirTemp.x = point.x;
	m_CirTemp.y = point.y;
	m_RecTemp.x = point.x;
	m_RecTemp.y = point.y;
	m_TriTemp.x = point.x;
	m_TriTemp.y = point.y;




	CView::OnLButtonDown(nFlags, point);
}

void CClass2View::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_LBD = 0;
	m_ptU = point;
	
	if (m_Pic != 0)
		Insert();
	
	m_CirTemp.r = 0;
	m_RecTemp.w = 0;
	m_RecTemp.h = 0;
	m_TriTemp.w = 0;
	m_TriTemp.h = 0;


	Invalidate(true);

	CView::OnLButtonUp(nFlags, point);
}


void CClass2View::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

	if (m_LBD == 1) {
		m_ptM = point;

		if (m_Pic == 0) {
			m_xBK = m_ptMTemp.x + point.x - m_ptD.x;
			m_yBK = m_ptMTemp.y + point.y - m_ptD.y;
		}

		m_CirTemp.r = sqrt((m_CirTemp.x - point.x) * (m_CirTemp.x - point.x) + (m_CirTemp.y - point.y) * (m_CirTemp.y - point.y));

		m_RecTemp.w = point.x - m_CirTemp.x;
		m_RecTemp.h = point.y - m_CirTemp.y;

		m_TriTemp.w = (point.x - m_TriTemp.x) * 2;
		m_TriTemp.h = point.y - m_TriTemp.y;

	}

	Invalidate(true);
	CView::OnMouseMove(nFlags, point);
}

void CClass2View::OnCircle() 
{
	// TODO: Add your command handler code here
	m_Pic = 1;
}

void CClass2View::OnRectangle() 
{
	// TODO: Add your command handler code here
	m_Pic = 2;
}

void CClass2View::OnTriangle() 
{
	// TODO: Add your command handler code here
	m_Pic = 3;
}

void CClass2View::Move()
{
	int i;
	float x = 0.1;
	for (i = 0; i < m_nCir; i++) {

		m_Cir[i].x += (m_Cir[i].vx * x);
		m_Cir[i].y += (m_Cir[i].vy * x);

		if ((m_Cir[i].x + m_Cir[i].r) > m_wBK) {
			m_Cir[i].vx = -m_Cir[i].vx;
		}
		if ((m_Cir[i].x - m_Cir[i].r) < 0) {
			m_Cir[i].vx = -m_Cir[i].vx;
		}
		if ((m_Cir[i].y + m_Cir[i].r) > m_wBK) {
			m_Cir[i].vy = -m_Cir[i].vy;
		}
		if ((m_Cir[i].y - m_Cir[i].r) < 0) {
			m_Cir[i].vy = -m_Cir[i].vy;
		}
	}

	for (i = 0; i < m_nRec; i++) {
		m_Rec[i].x += (m_Rec[i].vx * x);
		m_Rec[i].y += (m_Rec[i].vy * x);
		if ((m_Rec[i].x + m_Rec[i].w) > m_wBK) {
			m_Rec[i].vx = -m_Rec[i].vx;
		}
		if (m_Rec[i].x < 0) {
			m_Rec[i].vx = -m_Rec[i].vx;
		}
		if ((m_Rec[i].y + m_Rec[i].h) > m_wBK) {
			m_Rec[i].vy = -m_Rec[i].vy;
		}
		if (m_Rec[i].y < 0) {
			m_Rec[i].vy = -m_Rec[i].vy;
		}
	}

	for (i = 0; i < m_nTri; i++) {
		m_Tri[i].x += (m_Tri[i].vx * x);
		m_Tri[i].y += (m_Tri[i].vy * x);
		if ((m_Tri[i].x + m_Tri[i].w / 2) > m_wBK) {
			m_Tri[i].vx = -m_Tri[i].vx;
		}
		if (m_Tri[i].x - m_Tri[i].w / 2 < 0) {
			m_Tri[i].vx = -m_Tri[i].vx;
		}
		if ((m_Tri[i].y + m_Tri[i].h) > m_wBK) {
			m_Tri[i].vy = -m_Tri[i].vy;
		}
		if (m_Tri[i].y < 0) {
			m_Tri[i].vy = -m_Tri[i].vy;
		}
	}
}

void CClass2View::OnSport() 
{
	// TODO: Add your command handler code here
	m_Pic = 0;
}

void CClass2View::OnStart() 
{
	// TODO: Add your command handler code here
	SetTimer(1, 100, NULL);
}

void CClass2View::OnStop() 
{
	// TODO: Add your command handler code here
	KillTimer(1);
}

void CClass2View::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	Move();

	Invalidate(true);
	CView::OnTimer(nIDEvent);
}

BOOL CClass2View::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt) 
{
	// TODO: Add your message handler code here and/or call default
	if (zDelta > 0)
		m_wBK *= 1.05;
	if (zDelta < 0)
		m_wBK *= 0.95;

	Invalidate(true);

	return CView::OnMouseWheel(nFlags, zDelta, pt);
}
