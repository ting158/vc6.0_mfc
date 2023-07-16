// CTreeView的用法View.cpp : implementation of the CCTreeViewView class
//

#include "stdafx.h"
#include "CTreeView的用法.h"

#include "CTreeView的用法Doc.h"
#include "CTreeView的用法View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCTreeViewView

IMPLEMENT_DYNCREATE(CCTreeViewView, CView)

BEGIN_MESSAGE_MAP(CCTreeViewView, CView)
	//{{AFX_MSG_MAP(CCTreeViewView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCTreeViewView construction/destruction

CCTreeViewView::CCTreeViewView()
{
	// TODO: add construction code here

}

CCTreeViewView::~CCTreeViewView()
{
}

BOOL CCTreeViewView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CCTreeViewView drawing

void CCTreeViewView::OnDraw(CDC* pDC)
{
	CCTreeViewDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CCTreeViewView printing

BOOL CCTreeViewView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCTreeViewView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCTreeViewView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CCTreeViewView diagnostics

#ifdef _DEBUG
void CCTreeViewView::AssertValid() const
{
	CView::AssertValid();
}

void CCTreeViewView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCTreeViewDoc* CCTreeViewView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCTreeViewDoc)));
	return (CCTreeViewDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCTreeViewView message handlers
