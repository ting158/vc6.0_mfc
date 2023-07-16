// DlgYuan.cpp : implementation file
//

#include "stdafx.h"
#include "Aaa.h"
#include "DlgYuan.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgYuan dialog





void CDlgYuan::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgYuan)
	DDX_Text(pDX, IDC_X, m_x);
	DDX_Text(pDX, IDC_R, m_r);
	DDX_Text(pDX, IDC_Y, m_y);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgYuan, CDialog)
	//{{AFX_MSG_MAP(CDlgYuan)
	ON_BN_CLICKED(IDC_OK, OnOk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgYuan message handlers

void CDlgYuan::OnOk() 
{
	// TODO: Add your control notification handler code here
	
}
