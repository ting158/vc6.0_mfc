// DlgPaintHuoJian.cpp : implementation file
//

#include "stdafx.h"
#include "picture控件.h"
#include "DlgPaintHuoJian.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgPaintHuoJian dialog


CDlgPaintHuoJian::CDlgPaintHuoJian(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgPaintHuoJian::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgPaintHuoJian)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlgPaintHuoJian::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgPaintHuoJian)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgPaintHuoJian, CDialog)
	//{{AFX_MSG_MAP(CDlgPaintHuoJian)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgPaintHuoJian message handlers

void CDlgPaintHuoJian::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	CBitmap bmp;
	bmp.LoadBitmap(IDB_HuoJian);      //得到图片信息 
	BITMAP bmpInfo;
	bmp.GetBitmap(&bmpInfo);       //在内存中创建一个位图兼容设备 
	CDC dcMemory;
	dcMemory.CreateCompatibleDC(&dc);       //将图片选入兼容设备 
	CBitmap *pOldBmp=dcMemory.SelectObject(&bmp);   //将兼容设备的内容copy到屏幕设备中，实现真正的Paint 
	dc.BitBlt(0,0,bmpInfo.bmWidth,bmpInfo.bmHeight,&dcMemory,50,50,SRCCOPY);
	dcMemory.SelectObject(pOldBmp);//将设备还原
	CDialog::OnPaint();

	// Do not call CDialog::OnPaint() for painting messages
}
