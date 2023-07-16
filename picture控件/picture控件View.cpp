// picture控件View.cpp : implementation of the CPictureView class
//

#include "stdafx.h"
#include "picture控件.h"

#include "picture控件Doc.h"
#include "picture控件View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPictureView

IMPLEMENT_DYNCREATE(CPictureView, CView)

BEGIN_MESSAGE_MAP(CPictureView, CView)
	//{{AFX_MSG_MAP(CPictureView)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPictureView construction/destruction

CPictureView::CPictureView()
{
	// TODO: add construction code here

}

CPictureView::~CPictureView()
{
}

BOOL CPictureView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CPictureView drawing

void CPictureView::OnDraw(CDC* pDC)
{
	CPictureDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CPictureView printing

BOOL CPictureView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPictureView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPictureView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CPictureView diagnostics

#ifdef _DEBUG
void CPictureView::AssertValid() const
{
	CView::AssertValid();
}

void CPictureView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPictureDoc* CPictureView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPictureDoc)));
	return (CPictureDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPictureView message handlers



