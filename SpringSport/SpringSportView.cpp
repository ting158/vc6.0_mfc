// SpringSportView.cpp : implementation of the CSpringSportView class
//

#include "stdafx.h"
#include "SpringSport.h"

#include "SpringSportDoc.h"
#include "SpringSportView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSpringSportView

IMPLEMENT_DYNCREATE(CSpringSportView, CView)

BEGIN_MESSAGE_MAP(CSpringSportView, CView)
	//{{AFX_MSG_MAP(CSpringSportView)
	ON_WM_ERASEBKGND()
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
// CSpringSportView construction/destruction

CSpringSportView::CSpringSportView()
{
	// TODO: add construction code here

}

CSpringSportView::~CSpringSportView()
{
}

BOOL CSpringSportView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSpringSportView drawing

void CSpringSportView::OnDraw(CDC* pDC)
{
	CSpringSportDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

	CDC MemDC; //定义一个新的CDC变量，用于将绘图先画入到内存中，从而实现双缓存
	int nWidth,nHeight; 
	CRect  rect; //获取当前View的大小，宽度为nWidth，高度为nHeight，单位是像素
	CBitmap MemBitmap;
    GetWindowRect(&rect); 
    nWidth = rect.Width(); 
    nHeight= rect.Height(); 
	MemDC.CreateCompatibleDC(NULL); 
	MemBitmap.CreateCompatibleBitmap(pDC,nWidth,nHeight); 
	CBitmap *pOldBit=MemDC.SelectObject(&MemBitmap); 
	MemDC.FillSolidRect(0,0,nWidth,nHeight,RGB(255,255,255));
	
	m_spring.Draw(&MemDC);

	pDC->BitBlt(0,0,nWidth,nHeight,&MemDC,0,0,SRCCOPY); 
    MemBitmap.DeleteObject(); 
    MemDC.DeleteDC(); 

}

/////////////////////////////////////////////////////////////////////////////
// CSpringSportView printing

BOOL CSpringSportView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSpringSportView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSpringSportView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSpringSportView diagnostics

#ifdef _DEBUG
void CSpringSportView::AssertValid() const
{
	CView::AssertValid();
}

void CSpringSportView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSpringSportDoc* CSpringSportView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSpringSportDoc)));
	return (CSpringSportDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSpringSportView message handlers

BOOL CSpringSportView::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	
	return true;
}

void CSpringSportView::OnMStart() 
{
	// TODO: Add your command handler code here
	SetTimer(1, 100, NULL);
}

void CSpringSportView::OnMStop() 
{
	// TODO: Add your command handler code here
	KillTimer(1);
}

void CSpringSportView::OnMSet() 
{
	// TODO: Add your command handler code here
	m_dlg.m_k = m_spring.m_k;
	m_dlg.m_L = m_spring.m_L;
	m_dlg.m_m = m_spring.m_m;
	m_dlg.m_v = m_spring.m_v;
	m_dlg.m_zn = m_spring.m_zn;

	if (m_dlg.DoModal() == IDOK)
	{
		m_spring.m_k = m_dlg.m_k;
		m_spring.m_L = m_dlg.m_L;
		m_spring.m_m = m_dlg.m_m;
		m_spring.m_v = m_dlg.m_v;
		m_spring.m_zn = m_dlg.m_zn;

		m_spring.initSport();
	}

	Invalidate(true);
}

void CSpringSportView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	
	m_spring.Move();


	Invalidate(1);

	CView::OnTimer(nIDEvent);
}
