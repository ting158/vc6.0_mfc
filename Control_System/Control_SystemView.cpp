// Control_SystemView.cpp : implementation of the CControl_SystemView class
//

#include "stdafx.h"
#include "Control_System.h"

#include "Control_SystemDoc.h"
#include "Control_SystemView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CControl_SystemView

IMPLEMENT_DYNCREATE(CControl_SystemView, CView)

BEGIN_MESSAGE_MAP(CControl_SystemView, CView)
	//{{AFX_MSG_MAP(CControl_SystemView)
	ON_WM_TIMER()
	ON_WM_ERASEBKGND()
	ON_COMMAND(ID_M_Start, OnMStart)
	ON_COMMAND(ID_M_Stop, OnMStop)
	ON_COMMAND(ID_M_Set, OnMSet)
	ON_COMMAND(ID_M_Restart, OnMRestart)
	ON_COMMAND(ID_M_YunSu, OnMYunSu)
	ON_COMMAND(ID_M_YunJiaSu, OnMYunJiaSu)
	ON_COMMAND(ID_M_ZhengXian, OnMZhengXian)
	ON_COMMAND(ID_M_WeiYi, OnMWeiYi)
	ON_COMMAND(ID_M_SuDu, OnMSuDu)
	ON_COMMAND(ID_M_JiaSuDu, OnMJiaSuDu)
	ON_COMMAND(ID_M_AllCurve, OnMAllCurve)
	ON_COMMAND(ID_M_Friction, OnMFriction)
	ON_COMMAND(ID_M_Efficiency, OnMEfficiency)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CControl_SystemView construction/destruction

CControl_SystemView::CControl_SystemView()
{
	// TODO: add construction code here

}

CControl_SystemView::~CControl_SystemView()
{
}

BOOL CControl_SystemView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CControl_SystemView drawing

void CControl_SystemView::OnDraw(CDC* pDC)
{
	CControl_SystemDoc* pDoc = GetDocument();
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

	m_control.Draw(&MemDC);

	pDC->BitBlt(0,0,nWidth,nHeight,&MemDC,0,0,SRCCOPY); 
    MemBitmap.DeleteObject(); 
    MemDC.DeleteDC(); 


}

/////////////////////////////////////////////////////////////////////////////
// CControl_SystemView printing

BOOL CControl_SystemView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CControl_SystemView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CControl_SystemView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CControl_SystemView diagnostics

#ifdef _DEBUG
void CControl_SystemView::AssertValid() const
{
	CView::AssertValid();
}

void CControl_SystemView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CControl_SystemDoc* CControl_SystemView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CControl_SystemDoc)));
	return (CControl_SystemDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CControl_SystemView message handlers

void CControl_SystemView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	
	m_control.MoveMB();
	m_control.MoveKZ();

	Invalidate(true);

	CView::OnTimer(nIDEvent);
}

BOOL CControl_SystemView::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	
	return true;
}

void CControl_SystemView::OnMStart() 
{
	// TODO: Add your command handler code here
	SetTimer(1, 100, NULL);
}

void CControl_SystemView::OnMStop() 
{
	// TODO: Add your command handler code here
	KillTimer(1);
}

void CControl_SystemView::OnMSet() 
{
	// TODO: Add your command handler code here
	
	m_set.m_kp_x = m_control.m_CarKZX.kp;
	m_set.m_kp_v = m_control.m_CarKZV.kp;
	m_set.m_kp_a = m_control.m_CarKZA.kp;

	m_set.m_ki_x = m_control.m_CarKZX.ki;
	m_set.m_ki_v = m_control.m_CarKZV.ki;
	m_set.m_ki_a = m_control.m_CarKZA.ki;

	m_set.m_kd_x = m_control.m_CarKZX.kd;
	m_set.m_kd_v = m_control.m_CarKZV.kd;
	m_set.m_kd_a = m_control.m_CarKZA.kd;

	if (m_set.DoModal() == IDOK)
	{
		m_control.m_CarKZX.kp = m_set.m_kp_x;
		m_control.m_CarKZV.kp = m_set.m_kp_v;
		m_control.m_CarKZA.kp = m_set.m_kp_a;

		m_control.m_CarKZX.ki = m_set.m_ki_x;
		m_control.m_CarKZV.ki = m_set.m_ki_v;
		m_control.m_CarKZA.ki = m_set.m_ki_a;

		m_control.m_CarKZX.kd = m_set.m_kd_x;
		m_control.m_CarKZV.kd = m_set.m_kd_v;
		m_control.m_CarKZA.kd = m_set.m_kd_a;
	}

	Invalidate(true);
}

void CControl_SystemView::OnMRestart() 
{
	// TODO: Add your command handler code here
	m_control.initMove();
}

void CControl_SystemView::OnMYunSu() 
{
	// TODO: Add your command handler code here
	m_control.m_mode = YunSu;
}

void CControl_SystemView::OnMYunJiaSu() 
{
	// TODO: Add your command handler code here
	m_control.m_mode = YunJiaSu;
}

void CControl_SystemView::OnMZhengXian() 
{
	// TODO: Add your command handler code here
	m_control.m_mode = ZhengXian;
}

void CControl_SystemView::OnMWeiYi() 
{
	// TODO: Add your command handler code here
	m_control.m_bjCurveDraw = WeiYi;
}

void CControl_SystemView::OnMSuDu() 
{
	// TODO: Add your command handler code here
	m_control.m_bjCurveDraw = SuDu;
}

void CControl_SystemView::OnMJiaSuDu() 
{
	// TODO: Add your command handler code here
	m_control.m_bjCurveDraw = JiaSuDu;
}

void CControl_SystemView::OnMAllCurve() 
{
	// TODO: Add your command handler code here
	m_control.m_bjCurveDraw = -1;
}

void CControl_SystemView::OnMFriction() 
{
	// TODO: Add your command handler code here
	m_control.m_CarMB.v *= 0.9;
}

void CControl_SystemView::OnMEfficiency() 
{
	// TODO: Add your command handler code here
	m_set_XL.m_XL = m_control.m_CDXL;

	if (m_set_XL.DoModal() == IDOK)
	{
		m_control.m_CDXL = m_set_XL.m_XL;
		m_control.m_CarMB.v *= m_control.m_CDXL;
	}
}
