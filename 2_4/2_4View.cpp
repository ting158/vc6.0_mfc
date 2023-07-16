// 2_4View.cpp : implementation of the CMy2_4View class
//

#include "stdafx.h"
#include "2_4.h"

#include "2_4Doc.h"
#include "2_4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


int m_nPic;


/////////////////////////////////////////////////////////////////////////////
// CMy2_4View

IMPLEMENT_DYNCREATE(CMy2_4View, CView)

BEGIN_MESSAGE_MAP(CMy2_4View, CView)
	//{{AFX_MSG_MAP(CMy2_4View)
	ON_COMMAND(ID_M_Circle, OnMCircle)
	ON_COMMAND(ID_M_Square, OnMSquare)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy2_4View construction/destruction

CMy2_4View::CMy2_4View()
{
	// TODO: add construction code here

}

CMy2_4View::~CMy2_4View()
{
}

BOOL CMy2_4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMy2_4View drawing

void CMy2_4View::OnDraw(CDC* pDC)
{
	CMy2_4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	
	if(m_nPic==1)
		DrawCircle(pDC,50,100,30);
	if(m_nPic==2)
		DrawSqure(pDC,200,100,230,150);

}

/////////////////////////////////////////////////////////////////////////////
// CMy2_4View printing

BOOL CMy2_4View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMy2_4View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMy2_4View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMy2_4View diagnostics

#ifdef _DEBUG
void CMy2_4View::AssertValid() const
{
	CView::AssertValid();
}

void CMy2_4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2_4Doc* CMy2_4View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2_4Doc)));
	return (CMy2_4Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMy2_4View message handlers


void CMy2_4View::OnMCircle() 
{
	// TODO: Add your command handler code here
	m_nPic = 1;
	Invalidate(true);
}

void CMy2_4View::OnMSquare() 
{
	// TODO: Add your command handler code here
	m_nPic = 2;
	Invalidate(true);
}

void CMy2_4View::DrawCircle(CDC *pDC, int x, int y, int r)
{
	pDC->Ellipse(x-r,y-r,x+r,y+r);
}

void CMy2_4View::DrawSqure(CDC *pDC, int x, int y, int w, int h)
{
	pDC->MoveTo(x,y);
	pDC->LineTo(x+w,y);
	pDC->LineTo(x+w,y+h);
	pDC->LineTo(x,y+h);
	pDC->LineTo(x,y);
}
