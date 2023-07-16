// DlgSelRobot.cpp : implementation file
//

#include "stdafx.h"
#include "Robot_Test.h"
#include "DlgSelRobot.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgSelRobot dialog


CDlgSelRobot::CDlgSelRobot(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgSelRobot::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgSelRobot)
	m_RobotName = _T("");
	//}}AFX_DATA_INIT
}


void CDlgSelRobot::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgSelRobot)
	DDX_Text(pDX, IDC_RobotName, m_RobotName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgSelRobot, CDialog)
	//{{AFX_MSG_MAP(CDlgSelRobot)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgSelRobot message handlers
