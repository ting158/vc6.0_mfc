// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Aab.h"
#include "AabView.h"
#include "MyView.h"
#include "DrawCircleView.h"
#include "DrawRectangleView.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_M_DrawCircle, OnMDrawCircle)
	ON_COMMAND(ID_M_DrawRectangle, OnMDrawRectangle)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(!m_wndSlitter.CreateStatic(this, 1, 2))
		return false;
	m_wndSlitter.CreateView(0, 0, RUNTIME_CLASS(CAabView), CSize(270,100), pContext); //0行0列
	m_wndSlitter.CreateView(0, 1, RUNTIME_CLASS(CMyView), CSize(100,100), pContext);  //0行1列
	return true; 

	return CFrameWnd::OnCreateClient(lpcs, pContext);
}

void CMainFrame::OnMDrawCircle() 
{
	// TODO: Add your command handler code here
	m_wndSlitter.DeleteView(0,0); //加载之前先要删除，删除以后又重新加载（删除0行1列）
	m_wndSlitter.CreateView(0,0,RUNTIME_CLASS(CDrawCircleView),CSize(270,100),NULL); //用画圆的视图加载进来
	m_wndSlitter.RecalcLayout(); //重新计算一下布局
}

void CMainFrame::OnMDrawRectangle() 
{
	// TODO: Add your command handler code here
	m_wndSlitter.DeleteView(0,1);
	m_wndSlitter.CreateView(0,1,RUNTIME_CLASS(CDrawRectangleView),CSize(100,100),NULL);
	m_wndSlitter.RecalcLayout();
}
