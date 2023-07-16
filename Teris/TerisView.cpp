// TerisView.cpp : implementation of the CTerisView class
//

#include "stdafx.h"
#include "Teris.h"

#include "TerisDoc.h"
#include "TerisView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTerisView

IMPLEMENT_DYNCREATE(CTerisView, CView)

BEGIN_MESSAGE_MAP(CTerisView, CView)
	//{{AFX_MSG_MAP(CTerisView)
	ON_COMMAND(ID_Start, OnStart)
	ON_COMMAND(ID_Stop, OnStop)
	ON_WM_KEYDOWN()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTerisView construction/destruction

CTerisView::CTerisView()
{
	// TODO: add construction code here

}

CTerisView::~CTerisView()
{
}

BOOL CTerisView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTerisView drawing

void CTerisView::OnDraw(CDC* pDC)
{
	CTerisDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

	m_RB.Draw(pDC);
}

/////////////////////////////////////////////////////////////////////////////
// CTerisView printing

BOOL CTerisView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTerisView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTerisView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTerisView diagnostics

#ifdef _DEBUG
void CTerisView::AssertValid() const
{
	CView::AssertValid();
}

void CTerisView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTerisDoc* CTerisView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTerisDoc)));
	return (CTerisDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTerisView message handlers

void CTerisView::OnStart() 
{
	// TODO: Add your command handler code here
	SetTimer(1,1000,NULL);
	Invalidate(TRUE);
}

void CTerisView::OnStop() 
{
	// TODO: Add your command handler code here
	KillTimer(1);
}

void CTerisView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	m_RB.KeyMove(nChar);
	Invalidate(TRUE);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CTerisView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	if (0 == m_RB.m_cret)
	{
		m_RB.CreateBlock();
		m_RB.m_cret =1;
//		m_RB.n = rand()%6;
	}
	m_RB.Move();
	m_RB.PanDuanDeFen();
	Invalidate(TRUE);
	CView::OnTimer(nIDEvent);
}
