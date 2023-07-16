// ̰����View.cpp : implementation of the CMyView class
//

#include "stdafx.h"
#include "̰����.h"

#include "̰����Doc.h"
#include "̰����View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyView

IMPLEMENT_DYNCREATE(CMyView, CView)

BEGIN_MESSAGE_MAP(CMyView, CView)
	//{{AFX_MSG_MAP(CMyView)
	ON_WM_KEYDOWN()
	ON_WM_TIMER()
	ON_COMMAND(ID_Start, OnStart)
	ON_COMMAND(ID_Stop, OnStop)
	ON_WM_ERASEBKGND()
	ON_COMMAND(ID_ReStart, OnReStart)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyView construction/destruction

CMyView::CMyView()
{
	// TODO: add construction code here

}

CMyView::~CMyView()
{
}

BOOL CMyView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMyView drawing

void CMyView::OnDraw(CDC* pDC)
{
	CMyDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here


	CDC MemDC; //����һ���µ�CDC���������ڽ���ͼ�Ȼ��뵽�ڴ��У��Ӷ�ʵ��˫����
	int nWidth,nHeight; 
	CRect  rect; //��ȡ��ǰView�Ĵ�С�����ΪnWidth���߶�ΪnHeight����λ������
	CBitmap MemBitmap;
    GetWindowRect(&rect); 
    nWidth = rect.Width(); 
    nHeight= rect.Height(); 
	MemDC.CreateCompatibleDC(NULL); 
	MemBitmap.CreateCompatibleBitmap(pDC,nWidth,nHeight); 
	CBitmap *pOldBit=MemDC.SelectObject(&MemBitmap); 
	MemDC.FillSolidRect(0,0,nWidth,nHeight,RGB(200,255,175)); //��ǳ��ɫ�������
	MemDC.SetBkMode(TRANSPARENT);
	ASSERT_VALID(pDoc);
	



	Snake.DrawAll(&MemDC);




	//��MemDC�ύ��pDC���Ƶ�������
	pDC->BitBlt(0,0,nWidth,nHeight,&MemDC,0,0,SRCCOPY); 
    MemBitmap.DeleteObject(); 
    MemDC.DeleteDC();

}

/////////////////////////////////////////////////////////////////////////////
// CMyView printing

BOOL CMyView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMyView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMyView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMyView diagnostics

#ifdef _DEBUG
void CMyView::AssertValid() const
{
	CView::AssertValid();
}

void CMyView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyDoc* CMyView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyDoc)));
	return (CMyDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyView message handlers

void CMyView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	switch(nChar)
	{
	case 37:   //��
		if (Snake.m_Dir != 3)
			Snake.m_Dir = 1;
		break;
	case 38:   //��
		if (Snake.m_Dir != 4)
			Snake.m_Dir = 2;
		break;
	case 39:   //��
		if (Snake.m_Dir != 1)
			Snake.m_Dir = 3;
		break;
	case 40:   //��
		if (Snake.m_Dir != 2)
			Snake.m_Dir = 4;
		break;
	}
	Invalidate(true);

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CMyView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	Snake.Move();

	int ret = Snake.isOver();
	if(1 == ret) 
	{
		KillTimer(1);
		CString str;
		str.Format("ײǽ����ǰ����Ϊ��%d\n������¿�ʼ���ɼ�����Ϸ", Snake.m_nlen);
		AfxMessageBox(str);
	}
	else if(2 == ret) 
	{
		KillTimer(1);
		CString str;
		str.Format("ҧ�����壬��ǰ����Ϊ��%d \n������¿�ʼ���ɼ�����Ϸ", Snake.m_nlen);
		AfxMessageBox(str);
	}
	else if(3 == ret) 
	{
		KillTimer(1);
		AfxMessageBox("��ϲ����ʤ����\n������¿�ʼ���ɼ�����Ϸ");
	}

	Invalidate(true);
	CView::OnTimer(nIDEvent);
}

void CMyView::OnStart() 
{
	// TODO: Add your command handler code here
	SetTimer(1,200,NULL);

}

void CMyView::OnStop() 
{
	// TODO: Add your command handler code here
	KillTimer(1);
	AfxMessageBox("�����ʼ��Ϸ����");
}


BOOL CMyView::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	
	return true;
}


void CMyView::OnReStart() 
{
	// TODO: Add your command handler code here
	
	Snake.initSnake();
	Invalidate(true);
	KillTimer(1);
	AfxMessageBox("�����ʼ��Ϸ�������¿�ʼ");
}

