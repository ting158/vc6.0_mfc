// DlgXiaLa.cpp : implementation file
//

#include "stdafx.h"
#include "ÏÂÀ­¿ò.h"
#include "DlgXiaLa.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgXiaLa dialog


CDlgXiaLa::CDlgXiaLa(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgXiaLa::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgXiaLa)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlgXiaLa::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgXiaLa)
	DDX_Control(pDX, IDC_COMBO1, m_Combo);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgXiaLa, CDialog)
	//{{AFX_MSG_MAP(CDlgXiaLa)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgXiaLa message handlers

BOOL CDlgXiaLa::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_Combo.AddString("aaa");
	m_Combo.AddString("bbb");
	m_Combo.AddString("ccc");

//	m_Combo.SetCurSel(0);

//	UpdateData(true);
//	CString str;
//	m_Combo.GetWindowText(str);
//	AfxMessageBox(str);


	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}





void CDlgXiaLa::OnOK() 
{
	// TODO: Add extra validation here
	CString str;
	UpdateData(true);
	m_Combo.GetLBText(m_Combo.GetCurSel(),str);
	AfxMessageBox(str);

	//CDialog::OnOK();
}
