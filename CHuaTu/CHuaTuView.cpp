// CHuaTuView.cpp : implementation of the CCHuaTuView class
//

#include "stdafx.h"
#include "CHuaTu.h"

#include "CHuaTuDoc.h"
#include "CHuaTuView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCHuaTuView

IMPLEMENT_DYNCREATE(CCHuaTuView, CView)

BEGIN_MESSAGE_MAP(CCHuaTuView, CView)
	//{{AFX_MSG_MAP(CCHuaTuView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEWHEEL()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_KEYDOWN()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCHuaTuView construction/destruction

CCHuaTuView::CCHuaTuView()
{
	// TODO: add construction code here
	m_x = 0;
	m_y = 0; 
	m_r = 50;
	m_xIni = 0;
	m_yIni = 0; 
	m_LBD.x = 0;
	m_LBD.y = 0;
	m_BJ_LBD = 1; 


}

CCHuaTuView::~CCHuaTuView()
{
}

BOOL CCHuaTuView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CCHuaTuView drawing

void CCHuaTuView::OnDraw(CDC* pDC)
{
	CCHuaTuDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

	//pDC->Ellipse(100,100,200,200); 

	pDC->Ellipse(m_x-m_r,m_y-m_r,m_x+m_r,m_y+m_r);

}

/////////////////////////////////////////////////////////////////////////////
// CCHuaTuView printing

BOOL CCHuaTuView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCHuaTuView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCHuaTuView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CCHuaTuView diagnostics

#ifdef _DEBUG
void CCHuaTuView::AssertValid() const
{
	CView::AssertValid();
}

void CCHuaTuView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCHuaTuDoc* CCHuaTuView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCHuaTuDoc)));
	return (CCHuaTuDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCHuaTuView message handlers

void CCHuaTuView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
//	CString str;
//	str.Format("x = %d, y = %d",point.x,point.y);
//	AfxMessageBox(str);

	m_BJ_LBD = 1;
	m_xIni = m_x;
	m_yIni = m_y;
	m_LBD = point;


	CView::OnLButtonDown(nFlags, point);
}

BOOL CCHuaTuView::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt) 
{
	// TODO: Add your message handler code here and/or call default
	if(zDelta>0)
		m_Length = m_Length*1.2;
	if(zDelta<0)
		m_Length = m_Length*0.8;
	Invalidate(true);

	return CView::OnMouseWheel(nFlags, zDelta, pt);
}





void CCHuaTuView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_BJ_LBD = 0;
	CView::OnLButtonUp(nFlags, point);
}

void CCHuaTuView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_BJ_LBD==1)
	{
		m_x = m_xIni + point.x - m_LBD.x; 
		m_y = m_yIni + point.y - m_LBD.y; 
		Invalidate(true);
	}

	CView::OnMouseMove(nFlags, point);
}

void CCHuaTuView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	switch(nChar)
	{
	case 37:   //按下向左的箭头
		m_x  -= 100;
	case 38:   //按下向上的箭头
		m_y  -= 100;
		break;
	case 39:   //按下向右的箭头
		m_x  += 100;
		break;
	case 40:   //按下向下的箭头
		m_y  += 100;
		break;
	}
	Invalidate(true);

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
