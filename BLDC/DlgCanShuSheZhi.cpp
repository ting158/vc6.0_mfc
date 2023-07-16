// DlgCanShuSheZhi.cpp : implementation file
//

#include "stdafx.h"
#include "BLDC.h"
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
	m_k = 0.0f;
	m_kp = 0.0f;
	m_r = 0;
	//}}AFX_DATA_INIT
}


void CDlgCanShuSheZhi::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgCanShuSheZhi)
	DDX_Text(pDX, IDC_mk, m_k);
	DDX_Text(pDX, IDC_mkp, m_kp);
	DDX_Text(pDX, IDC_mr, m_r);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgCanShuSheZhi, CDialog)
	//{{AFX_MSG_MAP(CDlgCanShuSheZhi)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgCanShuSheZhi message handlers
