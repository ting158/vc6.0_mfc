// AaaView.cpp : implementation of the CAaaView class
//

#include "stdafx.h"
#include "Aaa.h"

#include "AaaDoc.h"
#include "AaaView.h"

#include<math.h>
#include "DlgCanShuSheZhi.h"
#include "DlgYuan.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

	int m_R = 0;
	int m_X = 0;
	int m_Y = 0;
	int m_Pic = 0;

/////////////////////////////////////////////////////////////////////////////
// CAaaView

IMPLEMENT_DYNCREATE(CAaaView, CView)

BEGIN_MESSAGE_MAP(CAaaView, CView)
	//{{AFX_MSG_MAP(CAaaView)
	ON_COMMAND(ID_M_Circle, OnMCircle)
	ON_COMMAND(D_M_Square, OnMSquare)
	ON_COMMAND(ID_M_DongHua, OnMDongHua)
	ON_COMMAND(ID_M_Stop, OnMStop)
	ON_WM_TIMER()
	ON_COMMAND(ID_MENUITEM32778, OnCanShuSheZhi)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAaaView construction/destruction

CAaaView::CAaaView()
{
	// TODO: add construction code here

}

CAaaView::~CAaaView()
{
}

BOOL CAaaView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CAaaView drawing

void CAaaView::OnDraw(CDC* pDC)
{
	CAaaDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here


	//画五子棋盘
//	int i, j;
//	for(i = 0; i <= 18; i++){
//		pDC->MoveTo(50, 50 + i * 20);
//		pDC->LineTo(410, 50 + i * 20);
//	}
//	for(i = 0; i <= 18; i++){
//		pDC->MoveTo(50 + i * 20, 50);
//		pDC->LineTo(50 + i * 20, 410);
//	}
//	//画九个星位
//	CBrush   Brush;     
//	Brush.CreateSolidBrush(RGB(0,0,0));     
//	pDC->SelectObject(&Brush);
//	for(i = 0; i < 3; i++){
//		for(j = 0; j < 3; j++){
//			pDC->Ellipse(110 + 120 * i - 5, 110 + 120 * j - 5, 110 + 120 * i + 5, 110 + 120 * j + 5);
//		}
//	}
//	pDC->EndPath();          
//	pDC->FillPath(); 


	//画正弦曲线
	//DrawSin(pDC, 200, 200, 60, 2);




//	DrawCircle(pDC,100,100,30);
//	DrawSqure(pDC,200,100,230,150);


  


//	CFont ft;
//	ft.CreatePointFont(300,_T("楷体"),NULL);
//	pDC->SelectObject(&ft);
//	pDC->SetTextColor(RGB(200,100,255));
//	pDC->TextOut(200,200,"Hello!");


//	CPoint dd[4];
//	dd[0].x = 30;dd[0].y = 30;
//	dd[1].x = 200;dd[1].y = 30;
//	dd[2].x = 200;dd[2].y = 200;
//	dd[3].x = 30;dd[3].y = 200;
//	CBrush brush;
//	brush.CreateSolidBrush(RGB(100,210,120));
//	CBrush* oldBr = pDC->SelectObject(&brush);
//	pDC->Polygon(dd,4);
//	//方块里写hello
//	CFont ft;
//	ft.CreatePointFont(300,_T("楷体"),NULL);
//	pDC->SelectObject(&ft);
//	pDC->SetTextColor(RGB(200,100,255));
//	pDC->TextOut(50,100,"Hello!");

//	if(m_nPic==1)
//		DrawCircle(pDC,m_x,100,30);
//	if(m_nPic==2)
//		DrawSqure(pDC,m_x,100,230,150);




}

/////////////////////////////////////////////////////////////////////////////
// CAaaView printing

BOOL CAaaView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CAaaView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CAaaView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CAaaView diagnostics

#ifdef _DEBUG
void CAaaView::AssertValid() const
{
	CView::AssertValid();
}

void CAaaView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CAaaDoc* CAaaView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAaaDoc)));
	return (CAaaDoc*)m_pDocument;
}





#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAaaView message handlers



void CAaaView::DrawSqure(CDC *pDC, int x, int y, int w, int h)
{
	pDC->MoveTo(x,y);
	pDC->LineTo(x+w,y);
	pDC->LineTo(x+w,y+h);
	pDC->LineTo(x,y+h);
	pDC->LineTo(x,y);
}

void CAaaView::DrawCircle(CDC *pDC, int x, int y, int r)
{
	pDC->Ellipse(x-r,y-r,x+r,y+r);
}






void CAaaView::DrawSin(CDC *pDC, int init_x, int init_y, float a, float b)
{
	int x;
	double y;
	
	//绘制x轴和y轴
	pDC->MoveTo(init_x - 10000, init_y);
	pDC->LineTo(init_x + 10000, init_y);
	pDC->MoveTo(init_x, init_y - 10000);
	pDC->LineTo(init_x, init_y + 10000);

	//绘制曲线
	pDC->MoveTo(init_x, init_y);
	for(x = 0; x <= 600; x++)
	{
		y = - a * sin(b * x * 3.14 / 100);
		pDC->LineTo(init_x + x, init_y + y);
	}
}



void CAaaView::OnMCircle() 
{
	// TODO: Add your command handler code here
	m_x = 50;
	m_nPic = 1;
	Invalidate(true);

}

void CAaaView::OnMSquare() 
{
	// TODO: Add your command handler code here
	m_nPic = 2;
	Invalidate(true);

}

void CAaaView::OnMDongHua() 
{
	// TODO: Add your command handler code here
	SetTimer(1,100,NULL);
}

void CAaaView::OnMStop() 
{
	// TODO: Add your command handler code here
	KillTimer(1);
}

void CAaaView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	m_x += 10;
	Invalidate(true);

	CView::OnTimer(nIDEvent);
}

void CAaaView::OnCanShuSheZhi() 
{
	// TODO: Add your command handler code here
	CDlgCanShuSheZhi dlg;
	dlg.DoModal();

}


