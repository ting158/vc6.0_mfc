// BLDCView.cpp : implementation of the CBLDCView class
//

#include "stdafx.h"
#include "BLDC.h"
#include "DlgCanShuSheZhi.h"
#include "BLDCDoc.h"
#include "BLDCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBLDCView

IMPLEMENT_DYNCREATE(CBLDCView, CView)

BEGIN_MESSAGE_MAP(CBLDCView, CView)
	//{{AFX_MSG_MAP(CBLDCView)
	ON_WM_TIMER()
	ON_COMMAND(ID_M_Start, OnMStart)
	ON_COMMAND(ID_M_Stop, OnMStop)
	ON_WM_ERASEBKGND()
	ON_COMMAND(ID_M_Set, OnMSet)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBLDCView construction/destruction

CBLDCView::CBLDCView()
{
	// TODO: add construction code here

}

CBLDCView::~CBLDCView()
{
}

BOOL CBLDCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CBLDCView drawing

void CBLDCView::OnDraw(CDC* pDC)
{
	CBLDCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CDC MemDC; 
	int nWidth,nHeight; 
	CRect  rect; 
	CBitmap MemBitmap;
    GetWindowRect(&rect); 
    nWidth = rect.Width(); 
    nHeight= rect.Height(); 

	MemDC.CreateCompatibleDC(pDC); 
	MemBitmap.CreateCompatibleBitmap(pDC,nWidth,nHeight); 
	CBitmap *pOldBit=MemDC.SelectObject(&MemBitmap); 
	MemDC.FillSolidRect(0,0,nWidth,nHeight,RGB(255,255,255));
	MemDC.SelectObject(&MemBitmap);

	m_DianJi.Draw(&MemDC);

	pDC->BitBlt(0,0,nWidth,nHeight,&MemDC,0,0,SRCCOPY); 
    MemBitmap.DeleteObject(); 
    MemDC.DeleteDC();

}

/////////////////////////////////////////////////////////////////////////////
// CBLDCView printing

BOOL CBLDCView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CBLDCView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CBLDCView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CBLDCView diagnostics

#ifdef _DEBUG
void CBLDCView::AssertValid() const
{
	CView::AssertValid();
}

void CBLDCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBLDCDoc* CBLDCView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBLDCDoc)));
	return (CBLDCDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBLDCView message handlers

void CBLDCView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_DianJi.Move() == 1)
		Invalidate(true);
	CView::OnTimer(nIDEvent);
}

void CBLDCView::OnMStart() 
{
	// TODO: Add your command handler code here
	SetTimer(1,10,NULL);
}

void CBLDCView::OnMStop() 
{
	// TODO: Add your command handler code here
	KillTimer(1);
}

BOOL CBLDCView::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	
	return true;
}

void CBLDCView::OnMSet() 
{
	// TODO: Add your command handler code here
	CDlgCanShuSheZhi dlg;
	dlg.m_k = m_DianJi.m_k;
	dlg.m_r = m_DianJi.m_r;
	dlg.m_kp = m_DianJi.m_kp;
	if(dlg.DoModal() == IDOK)
	{
		m_DianJi.m_k = dlg.m_k;
		m_DianJi.m_r = dlg.m_r;
		m_DianJi.m_kp = dlg.m_kp;
	}
}
