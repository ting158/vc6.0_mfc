// DlgPaintHuoJian.cpp : implementation file
//

#include "stdafx.h"
#include "picture�ؼ�.h"
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
	bmp.LoadBitmap(IDB_HuoJian);      //�õ�ͼƬ��Ϣ 
	BITMAP bmpInfo;
	bmp.GetBitmap(&bmpInfo);       //���ڴ��д���һ��λͼ�����豸 
	CDC dcMemory;
	dcMemory.CreateCompatibleDC(&dc);       //��ͼƬѡ������豸 
	CBitmap *pOldBmp=dcMemory.SelectObject(&bmp);   //�������豸������copy����Ļ�豸�У�ʵ��������Paint 
	dc.BitBlt(0,0,bmpInfo.bmWidth,bmpInfo.bmHeight,&dcMemory,50,50,SRCCOPY);
	dcMemory.SelectObject(pOldBmp);//���豸��ԭ
	CDialog::OnPaint();

	// Do not call CDialog::OnPaint() for painting messages
}
