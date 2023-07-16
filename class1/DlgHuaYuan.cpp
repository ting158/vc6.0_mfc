// DlgHuaYuan.cpp : implementation file
//

#include "stdafx.h"
#include "test02.h"
#include "DlgHuaYuan.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgHuaYuan dialog


CDlgHuaYuan::CDlgHuaYuan(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgHuaYuan::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgHuaYuan)
	m_r = 0;
	m_x = 0;
	m_y = 0;
	//}}AFX_DATA_INIT
}


void CDlgHuaYuan::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgHuaYuan)
	DDX_Text(pDX, IDC_R, m_r);
	DDX_Text(pDX, IDC_X, m_x);
	DDX_Text(pDX, IDC_Y, m_y);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgHuaYuan, CDialog)
	//{{AFX_MSG_MAP(CDlgHuaYuan)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgHuaYuan message handlers
