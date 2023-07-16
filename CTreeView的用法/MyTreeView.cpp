// MyTreeView.cpp : implementation file
//

#include "stdafx.h"
#include "CTreeView的用法.h"
#include "MyTreeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyTreeView

IMPLEMENT_DYNCREATE(CMyTreeView, CTreeView)

CMyTreeView::CMyTreeView()
{
}

CMyTreeView::~CMyTreeView()
{
}


BEGIN_MESSAGE_MAP(CMyTreeView, CTreeView)
	//{{AFX_MSG_MAP(CMyTreeView)
	ON_WM_PAINT()
	ON_NOTIFY_REFLECT(NM_DBLCLK, OnDblclk)
	ON_NOTIFY_REFLECT(TVN_ITEMEXPANDING, OnItemexpanding)
	ON_NOTIFY_REFLECT(TVN_ITEMEXPANDED, OnItemexpanded)
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyTreeView drawing

void CMyTreeView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CMyTreeView diagnostics

#ifdef _DEBUG
void CMyTreeView::AssertValid() const
{
	CTreeView::AssertValid();
}

void CMyTreeView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyTreeView message handlers

void CMyTreeView::OnInitialUpdate() 
{
	CTreeView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	m_list.Create(32, 32, ILC_COLOR32 | ILC_MASK, 0, 0);

	m_list.Add(::AfxGetApp()->LoadIcon(IDR_MAINFRAME));
	m_list.Add(::AfxGetApp()->LoadIcon(IDI_ICON1));
	m_list.Add(::AfxGetApp()->LoadIcon(IDI_ICON2));
	m_list.Add(::AfxGetApp()->LoadIcon(IDI_ICON3));
	this->GetTreeCtrl().SetImageList(&m_list, TVSIL_NORMAL);

	DWORD dwStyle = GetWindowLong(this->GetTreeCtrl().m_hWnd, GWL_STYLE);
	dwStyle |= TVS_EDITLABELS | TVS_HASBUTTONS | TVS_HASLINES | TVS_LINESATROOT;
    SetWindowLong(this->GetTreeCtrl().m_hWnd, GWL_STYLE, dwStyle);//设定风格

	HTREEITEM tree;
	{
		m_ModelTreeItem = this->GetTreeCtrl().InsertItem("任务", 0, 0);
		m_ModelTreeItem = this->GetTreeCtrl().InsertItem("模型计算", 2, 2);
		this->GetTreeCtrl().InsertItem("配料模型",3,3,m_ModelTreeItem);
		this->GetTreeCtrl().InsertItem("混合料制粒模型",1,1,m_ModelTreeItem);
	}
	this->GetTreeCtrl().InsertItem("模型",2,2);
	this->GetTreeCtrl().InsertItem("生成报告",3,3);


	m_Bitmap.LoadBitmap(IDB_BEIJING);
}

void CMyTreeView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	
	// Do not call CTreeView::OnPaint() for painting messages

	CRect rect;
	GetClientRect(&rect);

	CDC memdc;
	memdc.CreateCompatibleDC(&dc);
	CBitmap bitmap;
	bitmap.CreateCompatibleBitmap(&dc, rect.Width(), rect.Height());
	memdc.SelectObject(&bitmap);
	//获取原始画布
	CWnd::DefWindowProc(WM_PAINT, (WPARAM)memdc.m_hDC, 0);
	//绘制背景图片
	CMemDC tempDC(&dc, rect);
	CBrush brush;
	brush.CreatePatternBrush(&m_Bitmap);
	tempDC.FillRect(rect, &brush);

	//将原始图片与背景进行组合
	tempDC.BitBlt(rect.left, rect.top, rect.Width(), rect.Height(), &memdc, rect.left, rect.top, SRCAND);
	brush.DeleteObject();
}

void CMyTreeView::OnDblclk(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	HTREEITEM tree = this->GetTreeCtrl().GetSelectedItem();
	if (!this->GetTreeCtrl().GetChildItem(tree)) {
		CString str = this->GetTreeCtrl().GetItemText(tree);
	}

	*pResult = 0;
}

void CMyTreeView::OnItemexpanding(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	SetRedraw(false);
	*pResult = 0;
}

void CMyTreeView::OnItemexpanded(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	Invalidate();
	SetRedraw(true);
	*pResult = 0;
}

BOOL CMyTreeView::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	
	return true;
}
