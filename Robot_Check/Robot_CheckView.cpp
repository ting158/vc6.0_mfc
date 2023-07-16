// Robot_CheckView.cpp : implementation of the CRobot_CheckView class
//

#include "stdafx.h"
#include "Robot_Check.h"

#include "Robot_CheckDoc.h"
#include "Robot_CheckView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define PI 3.1415926

/////////////////////////////////////////////////////////////////////////////
// CRobot_CheckView

IMPLEMENT_DYNCREATE(CRobot_CheckView, CView)

BEGIN_MESSAGE_MAP(CRobot_CheckView, CView)
	//{{AFX_MSG_MAP(CRobot_CheckView)
	ON_WM_ERASEBKGND()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_MOUSEWHEEL()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_M_DianNaDaoNa, OnMDianNaDaoNa)
	ON_COMMAND(ID_M_YunSuDaoMuBiaoDian, OnMYunSuDaoMuBiaoDian)
	ON_COMMAND(ID_M_ZhuanQuan, OnMZhuanQuan)
	ON_COMMAND(ID_M_Start, OnMStart)
	ON_COMMAND(ID_M_Stop, OnMStop)
	ON_WM_TIMER()
	ON_COMMAND(ID_M_StartLuJing, OnMStartLuJing)
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_M_CarNotSpot, OnMCarNotSpot)
	ON_COMMAND(ID_M_FindXieLouDian, OnMFindXieLouDian)
	ON_COMMAND(ID_M_StartXieLou, OnMStartXieLou)
	ON_WM_KEYDOWN()
	ON_COMMAND(ID_M_DrawLiZi, OnMDrawLiZi)
	ON_COMMAND(ID_M_NotDrawLiZi, OnMNotDrawLiZi)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRobot_CheckView construction/destruction

CRobot_CheckView::CRobot_CheckView()
{
	// TODO: add construction code here
	m_bjLBD = false;

	m_set.m_sn = 0;
}

CRobot_CheckView::~CRobot_CheckView()
{
}

BOOL CRobot_CheckView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CRobot_CheckView drawing

void CRobot_CheckView::OnDraw(CDC* pDC)
{
	CRobot_CheckDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

	CDC MemDC;
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

	m_scene.Draw(&MemDC);
	m_car.Draw(&MemDC);
	m_wrj.Draw(&MemDC);
	
	pDC->BitBlt(0,0,nWidth,nHeight,&MemDC,0,0,SRCCOPY); 
    MemBitmap.DeleteObject(); 
    MemDC.DeleteDC(); 
}

/////////////////////////////////////////////////////////////////////////////
// CRobot_CheckView printing

BOOL CRobot_CheckView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CRobot_CheckView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CRobot_CheckView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CRobot_CheckView diagnostics

#ifdef _DEBUG
void CRobot_CheckView::AssertValid() const
{
	CView::AssertValid();
}

void CRobot_CheckView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRobot_CheckDoc* CRobot_CheckView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRobot_CheckDoc)));
	return (CRobot_CheckDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRobot_CheckView message handlers

BOOL CRobot_CheckView::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	
	return true;
}

void CRobot_CheckView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_bjLBD = true;

	if (m_bjLBD)
	{
		m_LBD = point;
		m_tempYD = m_scene.m_YD;

		m_car.ZhuanHuaMuBiaoDian(point);

		if (m_car.m_bjCreate == 1)
			m_car.ChuLiGuiJiZuoBiao(point);
	}

	Invalidate(true);
	CView::OnLButtonDown(nFlags, point);
}

void CRobot_CheckView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if (m_bjLBD)
	{
		m_scene.m_YD = m_tempYD + point - m_LBD;
		m_car.m_YD = m_scene.m_YD;
		m_wrj.m_YD = m_scene.m_YD;
	}


	Invalidate(true);
	CView::OnMouseMove(nFlags, point);
}

BOOL CRobot_CheckView::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt) 
{
	// TODO: Add your message handler code here and/or call default
	if (zDelta > 0)
	{
		m_scene.m_kx *= 1.2;
		m_scene.m_ky *= 1.2;
		m_car.m_kx = m_scene.m_kx;
		m_car.m_ky = m_scene.m_ky;
		m_wrj.m_kx = m_scene.m_kx;
		m_wrj.m_ky = m_scene.m_ky;
	}
	if (zDelta < 0)
	{
		m_scene.m_kx *= 0.8;
		m_scene.m_ky *= 0.8;
		m_car.m_kx = m_scene.m_kx;
		m_car.m_ky = m_scene.m_ky;
		m_wrj.m_kx = m_scene.m_kx;
		m_wrj.m_ky = m_scene.m_ky;
	}

	Invalidate(true);
	return CView::OnMouseWheel(nFlags, zDelta, pt);
}

void CRobot_CheckView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_bjLBD = false;
	CView::OnLButtonUp(nFlags, point);
}

void CRobot_CheckView::OnMDianNaDaoNa() 
{
	// TODO: Add your command handler code here
	m_car.m_mode = ShunYi;
}

void CRobot_CheckView::OnMYunSuDaoMuBiaoDian() 
{
	// TODO: Add your command handler code here
	m_car.m_mode = YunSu;
}

void CRobot_CheckView::OnMZhuanQuan() 
{
	// TODO: Add your command handler code here
	m_car.m_mode = ZhuanQuan;

	m_set.m_dir = m_car.m_dir;
	m_set.m_r = m_car.m_r;
	m_set.m_sn = m_car.m_sn;
	m_set.m_vJD = m_car.m_vJD;

	if (m_set.DoModal() == IDOK)
	{
		m_car.m_dir = m_set.m_dir;
		m_car.m_r = m_set.m_r;
		m_car.m_sn = m_set.m_sn;
		m_car.m_vJD = m_set.m_vJD;
		m_car.ChuLiYuanXinCanShu();
	}
}

void CRobot_CheckView::OnMStart() 
{
	// TODO: Add your command handler code here
	SetTimer(1, 100, NULL);
}

void CRobot_CheckView::OnMStop() 
{
	// TODO: Add your command handler code here
	KillTimer(1);
}

void CRobot_CheckView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	switch (nIDEvent)
	{
	case 1:
		m_car.Move();

		if (m_car.isOverLuJing() == 1 && m_car.m_mode == LuJing)
		KillTimer(1);

		break;
	case 2:
		m_scene.CreateLiZi();
		m_scene.MoveLiZi();
		m_car.m_nd = m_scene.QiuNongDu(m_car.m_x, m_car.m_y);
		m_wrj.m_nd = m_scene.QiuNongDu(m_wrj.m_x, m_wrj.m_y);
		ChuLiLBD();
		m_wrj.LuoXuanJiangXuanZhuan();
		break;
	}

	Invalidate(true);
	CView::OnTimer(nIDEvent);
}

void CRobot_CheckView::OnMStartLuJing() 
{
	// TODO: Add your command handler code here
	m_car.m_mode = LuJing;
	m_car.m_bjCreate = 1;
	m_car.m_nowMB = 1;
}

void CRobot_CheckView::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_car.ZhuanHuaMuBiaoDian(point);
	m_car.m_bjCreate = 0;
	SetTimer(1, 100, NULL);

	CView::OnLButtonDblClk(nFlags, point);
}

void CRobot_CheckView::ChuLiLBD()
{
	float x, y;
	
	x = (m_LBD.x - m_scene.m_YD.x) / m_scene.m_kx;
	y = (m_LBD.y - m_scene.m_YD.y) / m_scene.m_ky;

	m_scene.m_nd = m_scene.QiuNongDu(x, y);
}

void CRobot_CheckView::OnMCarNotSpot() 
{
	// TODO: Add your command handler code here
	m_car.m_mode = -1;
}

void CRobot_CheckView::OnMFindXieLouDian() 
{
	// TODO: Add your command handler code here
	m_car.m_mode = FindXieLou;

	m_car.initCircleNDTest();
}

void CRobot_CheckView::OnMStartXieLou() 
{
	// TODO: Add your command handler code here
	m_scene.m_XLDx = rand() % (477 + 310 + 1) - 310;
	m_scene.m_XLDy = rand() % (686 + 100 + 1) - 100;
	SetTimer(2, 100, NULL);
}

void CRobot_CheckView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default

	m_wrj.Move(nChar);

	Invalidate(true);

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CRobot_CheckView::OnMDrawLiZi() 
{
	// TODO: Add your command handler code here
	m_scene.m_flag_drawlz = true;
}

void CRobot_CheckView::OnMNotDrawLiZi() 
{
	// TODO: Add your command handler code here
	m_scene.m_flag_drawlz = false;
}
