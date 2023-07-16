// 3_4_2View.cpp : implementation of the CMy3_4_2View class
//

#include "stdafx.h"
#include "3_4_2.h"

#include "3_4_2Doc.h"
#include "3_4_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMy3_4_2View

IMPLEMENT_DYNCREATE(CMy3_4_2View, CView)

BEGIN_MESSAGE_MAP(CMy3_4_2View, CView)
	//{{AFX_MSG_MAP(CMy3_4_2View)
	ON_COMMAND(ID_M_Start, OnMStart)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy3_4_2View construction/destruction

CMy3_4_2View::CMy3_4_2View()
{
	// TODO: add construction code here

}

CMy3_4_2View::~CMy3_4_2View()
{
}

BOOL CMy3_4_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMy3_4_2View drawing

void CMy3_4_2View::OnDraw(CDC* pDC)
{
	CMy3_4_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMy3_4_2View printing

BOOL CMy3_4_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMy3_4_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMy3_4_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMy3_4_2View diagnostics

#ifdef _DEBUG
void CMy3_4_2View::AssertValid() const
{
	CView::AssertValid();
}

void CMy3_4_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy3_4_2Doc* CMy3_4_2View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy3_4_2Doc)));
	return (CMy3_4_2Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMy3_4_2View message handlers

void CMy3_4_2View::read_write_file()
{
	CString filename,string;
	filename = "test.txt";
	CStdioFile f;
	if(!f.Open(filename,CFile::modeRead | CFile::shareExclusive))
		return;
	while(f.ReadString(string))	
	{
		AfxMessageBox(string);
	}
	f.Close();

}

void CMy3_4_2View::OnMStart() 
{
	// TODO: Add your command handler code here
	read_write_file();
}
