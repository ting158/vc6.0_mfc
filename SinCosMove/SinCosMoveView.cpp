// SinCosMoveView.cpp : implementation of the CSinCosMoveView class
//

#include "stdafx.h"
#include "SinCosMove.h"

#include "SinCosMoveDoc.h"
#include "SinCosMoveView.h"

#define PI 3.1415926

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSinCosMoveView

IMPLEMENT_DYNCREATE(CSinCosMoveView, CView)

BEGIN_MESSAGE_MAP(CSinCosMoveView, CView)
	//{{AFX_MSG_MAP(CSinCosMoveView)
	ON_WM_TIMER()
	ON_COMMAND(ID_M_Start, OnMStart)
	ON_COMMAND(ID_M_Stop, OnMStop)
	ON_COMMAND(ID_M_Set, OnMSet)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSinCosMoveView construction/destruction

CSinCosMoveView::CSinCosMoveView()
{
	// TODO: add construction code here

}

CSinCosMoveView::~CSinCosMoveView()
{
}

BOOL CSinCosMoveView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSinCosMoveView drawing

void CSinCosMoveView::OnDraw(CDC* pDC)
{
	CSinCosMoveDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	
	m_sc.Draw(pDC);
}

/////////////////////////////////////////////////////////////////////////////
// CSinCosMoveView printing

BOOL CSinCosMoveView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSinCosMoveView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSinCosMoveView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSinCosMoveView diagnostics

#ifdef _DEBUG
void CSinCosMoveView::AssertValid() const
{
	CView::AssertValid();
}

void CSinCosMoveView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSinCosMoveDoc* CSinCosMoveView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSinCosMoveDoc)));
	return (CSinCosMoveDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSinCosMoveView message handlers

void CSinCosMoveView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	
	m_sc.Move();

	Invalidate(true);

	CView::OnTimer(nIDEvent);
}

void CSinCosMoveView::OnMStart() 
{
	// TODO: Add your command handler code here
	SetTimer(1, 100, NULL);
}

void CSinCosMoveView::OnMStop() 
{
	// TODO: Add your command handler code here
	KillTimer(1);
}


void CSinCosMoveView::OnMSet() 
{
	// TODO: Add your command handler code here
	m_dlg.m_XW = m_sc.m_Angle;
	m_dlg.m_ZQ = 2 * PI / m_sc.m_vAngle;
	m_dlg.m_ZF = m_sc.m_R;

	if (m_dlg.DoModal() == IDOK)
	{
		KillTimer(1);

		m_sc.m_Angle = m_dlg.m_XW;
		m_sc.m_vAngle = 2 * PI / m_dlg.m_ZQ;
		m_sc.m_R = m_dlg.m_ZF;

		m_sc.initCurve();
	}
}
