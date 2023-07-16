// DrawRectangleView.cpp : implementation file
//

#include "stdafx.h"
#include "Aab.h"
#include "DrawRectangleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDrawRectangleView

IMPLEMENT_DYNCREATE(CDrawRectangleView, CFormView)

CDrawRectangleView::CDrawRectangleView()
	: CFormView(CDrawRectangleView::IDD)
{
	//{{AFX_DATA_INIT(CDrawRectangleView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CDrawRectangleView::~CDrawRectangleView()
{
}

void CDrawRectangleView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDrawRectangleView)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDrawRectangleView, CFormView)
	//{{AFX_MSG_MAP(CDrawRectangleView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDrawRectangleView diagnostics

#ifdef _DEBUG
void CDrawRectangleView::AssertValid() const
{
	CFormView::AssertValid();
}

void CDrawRectangleView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDrawRectangleView message handlers

void CDrawRectangleView::OnDraw(CDC* pDC) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	pDC->Rectangle(100, 100, 300, 300);
}
