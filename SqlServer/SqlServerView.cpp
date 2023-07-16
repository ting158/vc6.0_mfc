// SqlServerView.cpp : implementation of the CSqlServerView class
//

#include "stdafx.h"
#include "SqlServer.h"

#include "SqlServerSet.h"
#include "SqlServerDoc.h"
#include "SqlServerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSqlServerView

IMPLEMENT_DYNCREATE(CSqlServerView, CRecordView)

BEGIN_MESSAGE_MAP(CSqlServerView, CRecordView)
	//{{AFX_MSG_MAP(CSqlServerView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CRecordView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSqlServerView construction/destruction

CSqlServerView::CSqlServerView()
	: CRecordView(CSqlServerView::IDD)
{
	//{{AFX_DATA_INIT(CSqlServerView)
		// NOTE: the ClassWizard will add member initialization here
	m_pSet = NULL;
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CSqlServerView::~CSqlServerView()
{
}

void CSqlServerView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSqlServerView)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BOOL CSqlServerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CRecordView::PreCreateWindow(cs);
}

void CSqlServerView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_sqlServerSet;
	CRecordView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

/////////////////////////////////////////////////////////////////////////////
// CSqlServerView printing

BOOL CSqlServerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSqlServerView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSqlServerView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSqlServerView diagnostics

#ifdef _DEBUG
void CSqlServerView::AssertValid() const
{
	CRecordView::AssertValid();
}

void CSqlServerView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CSqlServerDoc* CSqlServerView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSqlServerDoc)));
	return (CSqlServerDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSqlServerView database support
CRecordset* CSqlServerView::OnGetRecordset()
{
	return m_pSet;
}


/////////////////////////////////////////////////////////////////////////////
// CSqlServerView message handlers
