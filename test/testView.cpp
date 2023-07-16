// testView.cpp : implementation of the CTestView class
//

#include "stdafx.h"
#include "test.h"

#include "testDoc.h"
#include "testView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestView

IMPLEMENT_DYNCREATE(CTestView, CView)

BEGIN_MESSAGE_MAP(CTestView, CView)
	//{{AFX_MSG_MAP(CTestView)
	ON_COMMAND(ID_M_Start, OnMStart)
	ON_COMMAND(ID_M_Stop, OnMStop)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestView construction/destruction

CTestView::CTestView()
{
	// TODO: add construction code here
	 m_spring.posL.x = 200;
	 m_spring.posL.y = 100;
	 m_spring.width = 100.0;
  	 m_spring.len = 200.0; //��ʼ��������״��С
	 m_spring.s = 0.0; //���������λ�ƣ�����Ϊ��������Ϊ��
	 m_spring.k = 100.0; //�趨����ϵ����ţ��/�ף�
	 m_object.center.x = m_spring.posL.x + m_spring.width/2;
	 m_object.center.y = m_spring.posL.y + m_spring.len + m_spring.s + 50; //��ʼ������
	 m_object.radius = 30;
	 m_object.m = 3.0; //����������ǧ�ˣ�
	 m_object.v = 30.0; //������ٶ�
}

CTestView::~CTestView()
{
}

BOOL CTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTestView drawing

void CTestView::OnDraw(CDC* pDC)
{
	CTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

	//�����ҵ��ɵ�����ǣ����
	pDC->MoveTo(m_spring.posL.x - 50,0);
	pDC->LineTo(m_spring.posL.x,m_spring.posL.y);
	pDC->MoveTo(m_spring.posL.x + m_spring.width + 50,0);
	pDC->LineTo(m_spring.posL.x + m_spring.width,m_spring.posL.y);

	DrawSpring(pDC,m_spring); //������
	DrawObject(pDC,m_object); //������
	DrawLine(pDC,m_spring,m_object);//�����ɺ�����֮�������
}

/////////////////////////////////////////////////////////////////////////////
// CTestView printing

BOOL CTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTestView diagnostics

#ifdef _DEBUG
void CTestView::AssertValid() const
{
	CView::AssertValid();
}

void CTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTestDoc* CTestView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTestDoc)));
	return (CTestDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTestView message handlers

void CTestView::DrawSpring(CDC *pDC, MySpring spring)
{
	pDC->Rectangle(spring.posL.x,spring.posL.y,spring.posL.x + spring.width,spring.posL.y + spring.len); //������
}

void CTestView::DrawObject(CDC *pDC, MyObject object)
{
	CBrush brush;
	brush.CreateSolidBrush(RGB(0,0,0)); //����ɫ����
	pDC->SelectObject(&brush);
	pDC->BeginPath();
	pDC->Ellipse(object.center.x - object.radius,object.center.y - object.radius,object.center.x + object.radius,object.center.y + object.radius); //��Բ
	pDC->EndPath();
	pDC->FillPath();
}

void CTestView::DrawLine(CDC *pDC, MySpring spring, MyObject object)
{
	pDC->MoveTo(spring.posL.x + spring.width/2,spring.posL.y + spring.len); //�ߵ����
	pDC->LineTo(object.center); //�ߵ��յ�
}

void CTestView::OnMStart() 
{
	// TODO: Add your command handler code here
	SetTimer(1,30,NULL);
}

void CTestView::OnMStop() 
{
	// TODO: Add your command handler code here
	KillTimer(1);
}

void CTestView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	float delta_s; //��0.01���ʱ�������������λ�Ƶ������������и���
	float delta_t = 0.01; 
	m_object.a = (m_object.m*9.8 - m_spring.k*m_spring.s)/m_object.m; //m*g - k*s = m*a
	delta_s = 0.5*(m_object.v + m_object.v + m_object.a*delta_t)*delta_t; //s = v*t + (a*t*t)/2
	m_spring.s += delta_s;
	m_spring.len += m_spring.s; //���㵯�ɳ��ȵı仯
	m_object.center.y = m_spring.posL.y + m_spring.len + 50;
	m_object.v = (m_object.v + m_object.a*delta_t); //v = v0 + a*t
	Invalidate(true);
	CView::OnTimer(nIDEvent);
}
