// 2_8_对话框View.cpp : implementation of the CMy2_8_View class
//

#include "stdafx.h"
#include "2_8_对话框.h"

#include "2_8_对话框Doc.h"
#include "2_8_对话框View.h"
#include "DlgHuaYuan.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMy2_8_View

IMPLEMENT_DYNCREATE(CMy2_8_View, CView)

BEGIN_MESSAGE_MAP(CMy2_8_View, CView)
	//{{AFX_MSG_MAP(CMy2_8_View)
	ON_COMMAND(ID_HuaYuan, OnHuaYuan)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy2_8_View construction/destruction

CMy2_8_View::CMy2_8_View()
{
	// TODO: add construction code here
	m_X = 300;
	m_Y = 400;
	m_R = 50;

}

CMy2_8_View::~CMy2_8_View()
{
}

BOOL CMy2_8_View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMy2_8_View drawing

void CMy2_8_View::OnDraw(CDC* pDC)
{
	CMy2_8_Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	pDC->Ellipse(m_X-m_R,m_Y-m_R,m_X+m_R,m_Y+m_R);

}

/////////////////////////////////////////////////////////////////////////////
// CMy2_8_View printing

BOOL CMy2_8_View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMy2_8_View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMy2_8_View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMy2_8_View diagnostics

#ifdef _DEBUG
void CMy2_8_View::AssertValid() const
{
	CView::AssertValid();
}

void CMy2_8_View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2_8_Doc* CMy2_8_View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2_8_Doc)));
	return (CMy2_8_Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMy2_8_View message handlers

void CMy2_8_View::OnHuaYuan() 
{
	// TODO: Add your command handler code here
	CDlgHuaYuan dlg;
	dlg.m_x = m_X;   //打开对话框之前，先将对话框中的变量值
	dlg.m_y = m_Y;   //设置为上一次画图用过的值
	dlg.m_r = m_R;

	if(dlg.DoModal()==IDOK)
	{
		m_X = dlg.m_x;
		m_Y = dlg.m_y;
		m_R = dlg.m_r;

		m_Pic = 1;
	}
	Invalidate(true);


}
