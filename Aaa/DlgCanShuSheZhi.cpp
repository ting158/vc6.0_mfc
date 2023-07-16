// DlgCanShuSheZhi.cpp : implementation file
//

#include "stdafx.h"
#include "Aaa.h"
#include "DlgCanShuSheZhi.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgCanShuSheZhi dialog


CDlgCanShuSheZhi::CDlgCanShuSheZhi(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgCanShuSheZhi::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgCanShuSheZhi)
	m_x = 0;
	m_y = 0;
	m_he = 0;
	//}}AFX_DATA_INIT
}


void CDlgCanShuSheZhi::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgCanShuSheZhi)
	DDX_Text(pDX, IDC_X, m_x);
	DDX_Text(pDX, IDC_Y, m_y);
	DDX_Text(pDX, IDC_He, m_he);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgCanShuSheZhi, CDialog)
	//{{AFX_MSG_MAP(CDlgCanShuSheZhi)
	ON_BN_CLICKED(IDC_QiuHe, OnQiuHe)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgCanShuSheZhi message handlers

void CDlgCanShuSheZhi::OnQiuHe() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	m_he = m_x + m_y;
	UpdateData(false);

}
