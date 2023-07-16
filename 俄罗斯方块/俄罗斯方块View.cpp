// 俄罗斯方块View.cpp : implementation of the CMyView class
//

#include "stdafx.h"
#include "俄罗斯方块.h"

#include "俄罗斯方块Doc.h"
#include "俄罗斯方块View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyView

IMPLEMENT_DYNCREATE(CMyView, CView)

BEGIN_MESSAGE_MAP(CMyView, CView)
	//{{AFX_MSG_MAP(CMyView)
	ON_WM_TIMER()
	ON_COMMAND(ID_Start, OnStart)
	ON_WM_KEYDOWN()
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyView construction/destruction

CMyView::CMyView()
{
	// TODO: add construction code here

}

CMyView::~CMyView()
{
}

BOOL CMyView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMyView drawing

void CMyView::OnDraw(CDC* pDC)
{
	CMyDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

//	T.DrawBackground(pDC);
//	T.DrawMap(pDC);
//	T.DrawNow(pDC);
//	T.DrawNext(pDC);

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

	MemDC.SetBkMode(TRANSPARENT);
	ASSERT_VALID(pDoc);
	MemDC.FillSolidRect(0,0,nWidth,nHeight,RGB(255,255,255)); //用浅绿色背景填充
	
	T.DrawBackground(&MemDC);
	T.DrawMap(&MemDC);
	T.DrawNow(&MemDC);
	T.DrawNext(&MemDC);

	//将MemDC提交给pDC绘制到界面上
	pDC->BitBlt(0,0,nWidth,nHeight,&MemDC,0,0,SRCCOPY); 
   
    MemBitmap.DeleteObject(); 
    MemDC.DeleteDC();

}

/////////////////////////////////////////////////////////////////////////////
// CMyView printing

BOOL CMyView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMyView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMyView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMyView diagnostics

#ifdef _DEBUG
void CMyView::AssertValid() const
{
	CView::AssertValid();
}

void CMyView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyDoc* CMyView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyDoc)));
	return (CMyDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyView message handlers

void CMyView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	T.Drop();
	
	if (T.isDown() == 1) {
		T.UpdateBlock();
	}

	if (1 == T.isOver()) {
		KillTimer(1);
		CString str;
		str.Format("游戏结束！\n您的得分为：%d", T.m_score);
		AfxMessageBox(str);
		T.GameInit();
	}

	Invalidate(true);
	CView::OnTimer(nIDEvent);
}

void CMyView::OnStart() 
{
	// TODO: Add your command handler code here
	SetTimer(1,300,NULL);
}

void CMyView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	switch(nChar) {
	case 37:  //左
		if (!T.isToLeft(T.m_nowid))
			T.map_X -= Size;
		break;
	case 38:  //上
		//变形
		if (T.isokChange())
			T.Change();
		break;
	case 39:  //右
		if (!T.isToRight(T.m_nowid))
			T.map_X += Size;
		break;
	case 40:  //下
		T.DropDown();
		break;
	case 80:  //暂停
		KillTimer(1);
		break;
	}

	Invalidate(true);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

BOOL CMyView::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	
	return true;

	return CView::OnEraseBkgnd(pDC);
}
