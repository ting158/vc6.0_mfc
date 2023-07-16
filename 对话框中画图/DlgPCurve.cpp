// DlgPCurve.cpp : implementation file
//

#include "stdafx.h"
#include "对话框中画图.h"
#include "DlgPCurve.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgPCurve dialog


CDlgPCurve::CDlgPCurve(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgPCurve::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgPCurve)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlgPCurve::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgPCurve)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgPCurve, CDialog)
	//{{AFX_MSG_MAP(CDlgPCurve)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgPCurve message handlers

void CDlgPCurve::OnPaint() 
{
CString str;
	int i;
	int max = 0;			// 最大计数

	CPaintDC dc(this);
	
	CWnd* pWnd = GetDlgItem(IDC_COORD);
	CDC* pDC = pWnd->GetDC();
	pWnd->Invalidate();
	pWnd->UpdateWindow();	
	pDC->Rectangle(0,0,365,300);
	
	CPen* pPenRed = new CPen;						// 创建画笔对象	
	pPenRed->CreatePen(PS_SOLID,1,RGB(255,0,0));	// 红色画笔	
	CPen* pPenBlue = new CPen;						// 创建画笔对象	
	pPenBlue->CreatePen(PS_SOLID,1,RGB(0,0, 255));	// 蓝色画笔	

	
	// 选中当前红色画笔，并保存以前的画笔
	CGdiObject* pOldPen = pDC->SelectObject(pPenRed);	
	pDC->MoveTo(35,10);								// 绘制坐标轴	
	pDC->LineTo(35,280);							// 垂直轴	
	pDC->LineTo(340,280);							// 水平轴
	
	// 写X轴刻度值
	double wholeT = 1.5;
	str.Format("0");
	pDC->TextOut(35, 283, str);
	str.Format("%.1f",wholeT/5);
	pDC->TextOut(85, 283, str);
	str.Format("%.1f",wholeT/5*2);
	pDC->TextOut(135, 283, str);
	str.Format("%.1f",wholeT/5*3);
	pDC->TextOut(185, 283, str);
	str.Format("%.1f",wholeT/5*4);
	pDC->TextOut(235, 283, str);
	str.Format("%.1f s",wholeT);
	pDC->TextOut(285, 283, str);
	
	// 绘制X轴刻度
	for (i = 0; i < 256; i += 5)
	{
		if ((i & 1) == 0)
		{
			pDC->MoveTo(i + 35, 280);
			pDC->LineTo(i + 35, 284);
		}
		else
		{
			pDC->MoveTo(i + 35, 280);
			pDC->LineTo(i + 35, 282);
		}
	}
	
	// 绘制X轴箭头
	pDC->MoveTo(335,275);
	pDC->LineTo(340,280);
	pDC->LineTo(335,285);
	// 绘制Y轴刻度
	for (i = 0; i < 256; i += 5)
	{
		if ((i & 1) == 0)
		{
			pDC->MoveTo(30, i + 20);
			pDC->LineTo(35, i + 20);
		}
		else
		{
			pDC->MoveTo(33, i + 20);
			pDC->LineTo(35, i + 20);
		}
	}
	// 绘制Y轴箭头
	pDC->MoveTo(35,10);
	pDC->LineTo(30,15);
	pDC->MoveTo(35,10);
	pDC->LineTo(40,15);

	// 写Y轴刻度值
	str.Format("0.2");
	pDC->TextOut(2, 230, str);
	str.Format("0.4");
	pDC->TextOut(2, 180, str);
	str.Format("0.6");
	pDC->TextOut(2, 130, str);
	str.Format("0.8");
	pDC->TextOut(2, 80, str);
	str.Format("1.0");
	pDC->TextOut(2, 30, str);
	str.Format("MPa");
	pDC->TextOut(12, 10, str);

	pDC->SelectObject(pPenBlue);	// 更改成蓝色画笔

	float data[2][20] = {
		{0.0, 0.079, 0.158, 0.237, 0.316, 0.395, 0.474, 0.553, 0.632, 0.711, 0.79, 0.869, 0.948, 1.027, 1.106, 1.185, 1.264, 1.343, 1.422, 1.501},
		{0.184, 0.475, 0.251, 0.424, 0.289, 0.842, 0.556, 0.295, 0.583, 0.657, 0.097, 0.634, 0.323, 0.008, 0.343, 0.123, 0.661, 0.341, 0.94, 0.546}};

	pDC->MoveTo(35+125*data[0][0],280-250*data[0][1]);
	for(i=0;i<20;i++)
	{
		pDC->LineTo((int)(35+125/wholeT*2*data[i][0]),280-250*data[i][1]);
	}
	
	pDC->SelectObject(pOldPen);	  // 恢复以前的画笔
	delete pPenRed;
	delete pPenBlue;

}
