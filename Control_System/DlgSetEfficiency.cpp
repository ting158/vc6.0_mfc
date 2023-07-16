// DlgSetEfficiency.cpp : implementation file
//

#include "stdafx.h"
#include "Control_System.h"
#include "DlgSetEfficiency.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgSetEfficiency dialog


CDlgSetEfficiency::CDlgSetEfficiency(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgSetEfficiency::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgSetEfficiency)
	m_XL = 0.0f;
	//}}AFX_DATA_INIT
}


void CDlgSetEfficiency::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgSetEfficiency)
	DDX_Text(pDX, IDC_Efficiency, m_XL);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgSetEfficiency, CDialog)
	//{{AFX_MSG_MAP(CDlgSetEfficiency)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgSetEfficiency message handlers
