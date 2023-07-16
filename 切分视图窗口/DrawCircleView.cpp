// DrawCircleView.cpp : implementation file
//

#include "stdafx.h"
#include "Aab.h"
#include "DrawCircleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDrawCircleView

IMPLEMENT_DYNCREATE(CDrawCircleView, CFormView)

CDrawCircleView::CDrawCircleView()
	: CFormView(CDrawCircleView::IDD)
{
	//{{AFX_DATA_INIT(CDrawCircleView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CDrawCircleView::~CDrawCircleView()
{
}

void CDrawCircleView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDrawCircleView)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDrawCircleView, CFormView)
	//{{AFX_MSG_MAP(CDrawCircleView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDrawCircleView diagnostics

#ifdef _DEBUG
void CDrawCircleView::AssertValid() const
{
	CFormView::AssertValid();
}

void CDrawCircleView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDrawCircleView message handlers

void CDrawCircleView::OnDraw(CDC* pDC) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	pDC->Ellipse(50, 50, 100, 100);
}
