// DlgYunSuan.cpp : implementation file
//

#include "stdafx.h"
#include "µ¥Ñ¡¿Ø¼þ.h"
#include "DlgYunSuan.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgYunSuan dialog


CDlgYunSuan::CDlgYunSuan(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgYunSuan::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgYunSuan)
	m_Result = 0;
	m_x = 0;
	m_y = 0;
	m_rad = -1;
	//}}AFX_DATA_INIT
}


void CDlgYunSuan::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgYunSuan)
	DDX_Control(pDX, IDC_BUTTON_YunSuan, m_Radio_YunSuan);
	DDX_Text(pDX, IDC_He, m_Result);
	DDX_Text(pDX, IDC_X, m_x);
	DDX_Text(pDX, IDC_Y, m_y);
	DDX_Radio(pDX, IDC_RADIO1, m_rad);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgYunSuan, CDialog)
	//{{AFX_MSG_MAP(CDlgYunSuan)
	ON_BN_CLICKED(IDC_BUTTON_YunSuan, OnBUTTONYunSuan)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgYunSuan message handlers

void CDlgYunSuan::OnBUTTONYunSuan() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	if(m_rad == 0)
		m_Result = m_x + m_y;
	if(m_rad == 1)
		m_Result = m_x - m_y;
	UpdateData(false);

}
