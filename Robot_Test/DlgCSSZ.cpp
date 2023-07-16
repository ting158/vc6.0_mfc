// DlgCSSZ.cpp : implementation file
//

#include "stdafx.h"
#include "Robot_Test.h"
#include "DlgCSSZ.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgCSSZ dialog


CDlgCSSZ::CDlgCSSZ(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgCSSZ::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgCSSZ)
	m_Hbody = _T("");
	m_Hleftarm = _T("");
	m_Hleftfoot = _T("");
	m_Hleftleg = _T("");
	m_Hneck = _T("");
	m_Hrightarm = _T("");
	m_Hrightfoot = _T("");
	m_Hrightleg = _T("");
	m_Lmouth = _T("");
	m_Lnose = _T("");
	m_Rhead = _T("");
	m_Rlefteye = _T("");
	m_RobotName = _T("");
	m_Rrighteye = _T("");
	m_Smouth = _T("");
	m_Wbody = _T("");
	m_Wleftarm = _T("");
	m_Wleftleg = _T("");
	m_Wneck = _T("");
	m_Wrightarm = _T("");
	m_Wrightfoot = _T("");
	m_Wrightleg = _T("");
	m_Xbody = _T("");
	m_X = _T("");
	m_Xhead = _T("");
	m_Xleftarm = _T("");
	m_Xlefteye = _T("");
	m_Xleftfoot = _T("");
	m_Xleftleg = _T("");
	m_Xmouth = _T("");
	m_Xneck = _T("");
	m_Xnose = _T("");
	m_Xrightarm = _T("");
	m_Xrighteye = _T("");
	m_Xrightfoot = _T("");
	m_Xrightleg = _T("");
	m_Y = _T("");
	m_Ybody = _T("");
	m_Yhead = _T("");
	m_Yleftarm = _T("");
	m_Ylefteye = _T("");
	m_Yleftfoot = _T("");
	m_Yleftleg = _T("");
	m_Ymouth = _T("");
	m_Yneck = _T("");
	m_Ynose = _T("");
	m_Yrightarm = _T("");
	m_Yrighteye = _T("");
	m_Yrightfoot = _T("");
	m_Yrightleg = _T("");
	
	m_Wleftfoot = _T("");
	//}}AFX_DATA_INIT
}


void CDlgCSSZ::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgCSSZ)
	DDX_Text(pDX, IDC_Hbody, m_Hbody);
	DDX_Text(pDX, IDC_Hleftarm, m_Hleftarm);
	DDX_Text(pDX, IDC_Hleftfoot, m_Hleftfoot);
	DDX_Text(pDX, IDC_Hleftleg, m_Hleftleg);
	DDX_Text(pDX, IDC_Hneck, m_Hneck);
	DDX_Text(pDX, IDC_Hrightarm, m_Hrightarm);
	DDX_Text(pDX, IDC_Hrightfoot, m_Hrightfoot);
	DDX_Text(pDX, IDC_Hrightleg, m_Hrightleg);
	DDX_Text(pDX, IDC_Lmouth, m_Lmouth);
	DDX_Text(pDX, IDC_Lnose, m_Lnose);
	DDX_Text(pDX, IDC_Rhead, m_Rhead);
	DDX_Text(pDX, IDC_Rlefteye, m_Rlefteye);
	DDX_Text(pDX, IDC_RobotName, m_RobotName);
	DDX_Text(pDX, IDC_Rrighteye, m_Rrighteye);
	DDX_Text(pDX, IDC_Smouth, m_Smouth);
	DDX_Text(pDX, IDC_Wbody, m_Wbody);
	DDX_Text(pDX, IDC_Wleftarm, m_Wleftarm);
	DDX_Text(pDX, IDC_Wleftleg, m_Wleftleg);
	DDX_Text(pDX, IDC_Wneck, m_Wneck);
	DDX_Text(pDX, IDC_Wrightarm, m_Wrightarm);
	DDX_Text(pDX, IDC_Wrightfoot, m_Wrightfoot);
	DDX_Text(pDX, IDC_Wrightleg, m_Wrightleg);
	DDX_Text(pDX, IDC_Xbody, m_Xbody);
	DDX_Text(pDX, IDC_X, m_X);
	DDX_Text(pDX, IDC_Xhead, m_Xhead);
	DDX_Text(pDX, IDC_Xleftarm, m_Xleftarm);
	DDX_Text(pDX, IDC_Xlefteye, m_Xlefteye);
	DDX_Text(pDX, IDC_Xleftfoot, m_Xleftfoot);
	DDX_Text(pDX, IDC_Xleftleg, m_Xleftleg);
	DDX_Text(pDX, IDC_Xmouth, m_Xmouth);
	DDX_Text(pDX, IDC_Xneck, m_Xneck);
	DDX_Text(pDX, IDC_Xnose, m_Xnose);
	DDX_Text(pDX, IDC_Xrightarm, m_Xrightarm);
	DDX_Text(pDX, IDC_Xrighteye, m_Xrighteye);
	DDX_Text(pDX, IDC_Xrightfoot, m_Xrightfoot);
	DDX_Text(pDX, IDC_Xrightleg, m_Xrightleg);
	DDX_Text(pDX, IDC_Y, m_Y);
	DDX_Text(pDX, IDC_Ybody, m_Ybody);
	DDX_Text(pDX, IDC_Yhead, m_Yhead);
	DDX_Text(pDX, IDC_Yleftarm, m_Yleftarm);
	DDX_Text(pDX, IDC_Ylefteye, m_Ylefteye);
	DDX_Text(pDX, IDC_Yleftfoot, m_Yleftfoot);
	DDX_Text(pDX, IDC_Yleftleg, m_Yleftleg);
	DDX_Text(pDX, IDC_Ymouth, m_Ymouth);
	DDX_Text(pDX, IDC_Yneck, m_Yneck);
	DDX_Text(pDX, IDC_Ynose, m_Ynose);
	DDX_Text(pDX, IDC_Yrightarm, m_Yrightarm);
	DDX_Text(pDX, IDC_Yrighteye, m_Yrighteye);
	DDX_Text(pDX, IDC_Yrightfoot, m_Yrightfoot);
	DDX_Text(pDX, IDC_Yrightleg, m_Yrightleg);
	
	DDX_Text(pDX, IDC_Wleftfoot, m_Wleftfoot);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgCSSZ, CDialog)
	//{{AFX_MSG_MAP(CDlgCSSZ)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgCSSZ message handlers
