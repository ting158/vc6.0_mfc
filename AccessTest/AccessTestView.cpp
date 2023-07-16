// AccessTestView.cpp : implementation of the CAccessTestView class
//

#include "stdafx.h"
#include "AccessTest.h"

#include "AccessTestDoc.h"
#include "AccessTestView.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAccessTestView

IMPLEMENT_DYNCREATE(CAccessTestView, CView)

BEGIN_MESSAGE_MAP(CAccessTestView, CView)
	//{{AFX_MSG_MAP(CAccessTestView)
	ON_COMMAND(ID_M_Connection, OnMConnection)
	ON_COMMAND(ID_M_Select, OnMSelect)
	ON_COMMAND(ID_M_Add, OnMAdd)
	ON_COMMAND(ID_M_Delete, OnMDelete)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAccessTestView construction/destruction

CAccessTestView::CAccessTestView()
{
	// TODO: add construction code here

}

CAccessTestView::~CAccessTestView()
{
}

BOOL CAccessTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CAccessTestView drawing

void CAccessTestView::OnDraw(CDC* pDC)
{
	CAccessTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CAccessTestView printing

BOOL CAccessTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CAccessTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CAccessTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CAccessTestView diagnostics

#ifdef _DEBUG
void CAccessTestView::AssertValid() const
{
	CView::AssertValid();
}

void CAccessTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CAccessTestDoc* CAccessTestView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAccessTestDoc)));
	return (CAccessTestDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAccessTestView message handlers

void CAccessTestView::OnMConnection() 
{
	// TODO: Add your command handler code here
	m_ado.Connect();
}

void CAccessTestView::OnMSelect() 
{
	// TODO: Add your command handler code here
	m_ado.Query();
}

void CAccessTestView::OnMAdd() 
{
	// TODO: Add your command handler code here
	m_ado.Add();
}

void CAccessTestView::OnMDelete() 
{
	// TODO: Add your command handler code here
	m_ado.Delete();
}
