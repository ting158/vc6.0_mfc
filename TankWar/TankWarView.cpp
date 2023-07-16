// TankWarView.cpp : implementation of the CTankWarView class
//

#include "stdafx.h"
#include "TankWar.h"

#include "TankWarDoc.h"
#include "TankWarView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTankWarView

IMPLEMENT_DYNCREATE(CTankWarView, CView)

BEGIN_MESSAGE_MAP(CTankWarView, CView)
	//{{AFX_MSG_MAP(CTankWarView)
	ON_WM_TIMER()
	ON_COMMAND(ID_M_Start, OnMStart)
	ON_COMMAND(ID_M_Stop, OnMStop)
	ON_COMMAND(ID_M_Restart, OnMRestart)
	ON_WM_KEYDOWN()
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTankWarView construction/destruction

CTankWarView::CTankWarView()
{
	// TODO: add construction code here

}

CTankWarView::~CTankWarView()
{
}

BOOL CTankWarView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTankWarView drawing

void CTankWarView::OnDraw(CDC* pDC)
{
	CTankWarDoc* pDoc = GetDocument();
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

	m_Tank.Draw(&MemDC);

	pDC->BitBlt(0,0,nWidth,nHeight,&MemDC,0,0,SRCCOPY); 
    MemBitmap.DeleteObject(); 
    MemDC.DeleteDC(); 


}

/////////////////////////////////////////////////////////////////////////////
// CTankWarView printing

BOOL CTankWarView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTankWarView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTankWarView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTankWarView diagnostics

#ifdef _DEBUG
void CTankWarView::AssertValid() const
{
	CView::AssertValid();
}

void CTankWarView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTankWarDoc* CTankWarView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTankWarDoc)));
	return (CTankWarDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTankWarView message handlers

void CTankWarView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	
	switch(nIDEvent)
	{
	case 1:
		m_Tank.CreateBlock();
		break;
	case 2:
		m_Tank.MoveBlock();
		m_Tank.MoveBullet();

		if (1 == m_Tank.BlockHitTank())
		{
			Invalidate(true);
			KillTimer(1);
			KillTimer(2);

			CString str;
			str.Format("您已被击中！");
			AfxMessageBox(str);
		}

		Invalidate(true);
		break;
	}

	CView::OnTimer(nIDEvent);
}

void CTankWarView::OnMStart() 
{
	// TODO: Add your command handler code here
	SetTimer(1, 1000, NULL);
	SetTimer(2, 50, NULL);
}

void CTankWarView::OnMStop() 
{
	// TODO: Add your command handler code here
	KillTimer(1);
	KillTimer(2);
}

void CTankWarView::OnMRestart() 
{
	// TODO: Add your command handler code here
	m_Tank.InitGame();
	SetTimer(1, 1000, NULL);
	SetTimer(2, 50, NULL);
}

void CTankWarView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	
	m_Tank.MoveTank(nChar);

	if (nChar == 32)  //空格
		m_Tank.CreateBullet();
	Invalidate(true);

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

BOOL CTankWarView::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	
	return true;
}
