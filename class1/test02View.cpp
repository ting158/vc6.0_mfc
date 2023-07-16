// test02View.cpp : implementation of the CTest02View class
//

#include "stdafx.h"
#include "test02.h"

#include "test02Doc.h"
#include "test02View.h"

#include "DlgHuaYuan.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTest02View

IMPLEMENT_DYNCREATE(CTest02View, CView)

BEGIN_MESSAGE_MAP(CTest02View, CView)
	//{{AFX_MSG_MAP(CTest02View)
	ON_WM_KEYDOWN()
	ON_WM_MOUSEWHEEL()
	ON_COMMAND(IDD_HuaYuan, OnHuaYuan)
	ON_WM_TIMER()
	ON_COMMAND(ID_DongHua, OnDongHua)
	ON_COMMAND(ID_TingZhi, OnTingZhi)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTest02View construction/destruction

CTest02View::CTest02View()
{
	// TODO: add construction code here
	x = 200;
	y = 200;
	r = 40;
}

CTest02View::~CTest02View()
{
}

BOOL CTest02View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTest02View drawing

void CTest02View::OnDraw(CDC* pDC)
{
	CTest02Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

	pDC->Ellipse(x - r, y - r, x + r, y + r);
}

/////////////////////////////////////////////////////////////////////////////
// CTest02View printing

BOOL CTest02View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTest02View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTest02View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTest02View diagnostics

#ifdef _DEBUG
void CTest02View::AssertValid() const
{
	CView::AssertValid();
}

void CTest02View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTest02Doc* CTest02View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTest02Doc)));
	return (CTest02Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTest02View message handlers



void CTest02View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	switch(nChar) {
	case 37:
		x = x - 10;
		break;
	case 38:
		y = y - 10;
		break;
	case 39:
		x = x + 10;
		break;
	case 40:
		y = y + 10;
		break;
	}
	Invalidate(true);

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

BOOL CTest02View::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt) 
{
	// TODO: Add your message handler code here and/or call default
	if (zDelta > 0)
		r = r + 5;
	if (zDelta < 0)
		r = r - 5;
	Invalidate(true);

	return CView::OnMouseWheel(nFlags, zDelta, pt);
}

void CTest02View::OnHuaYuan() 
{
	// TODO: Add your command handler code here
	CDlgHuaYuan dlg;
	if (dlg.DoModal() == IDOK) {
		x = dlg.m_x;
		y = dlg.m_y;
		r = dlg.m_r;
	}

	Invalidate(true);
}

void CTest02View::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	x = x + 10;
	Invalidate(true);
	CView::OnTimer(nIDEvent);
}

void CTest02View::OnDongHua() 
{
	// TODO: Add your command handler code here
	SetTimer(1, 100, NULL);
}

void CTest02View::OnTingZhi() 
{
	// TODO: Add your command handler code here
	KillTimer(1);
}
