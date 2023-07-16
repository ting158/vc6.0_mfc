// DlgSet.cpp : implementation file
//

#include "stdafx.h"
#include "Control_System.h"
#include "DlgSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgSet dialog


CDlgSet::CDlgSet(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgSet::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgSet)
	m_kp_a = 0.0f;
	m_kp_v = 0.0f;
	m_kp_x = 0.0f;
	m_kd_a = 0.0f;
	m_kd_v = 0.0f;
	m_kd_x = 0.0f;
	m_ki_a = 0.0f;
	m_ki_v = 0.0f;
	m_ki_x = 0.0f;
	//}}AFX_DATA_INIT
}


void CDlgSet::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgSet)
	DDX_Text(pDX, IDC_KpA, m_kp_a);
	DDX_Text(pDX, IDC_KpV, m_kp_v);
	DDX_Text(pDX, IDC_KpX, m_kp_x);
	DDX_Text(pDX, IDC_KdA, m_kd_a);
	DDX_Text(pDX, IDC_KdV, m_kd_v);
	DDX_Text(pDX, IDC_KdX, m_kd_x);
	DDX_Text(pDX, IDC_KiA, m_ki_a);
	DDX_Text(pDX, IDC_KiV, m_ki_v);
	DDX_Text(pDX, IDC_KiX, m_ki_x);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgSet, CDialog)
	//{{AFX_MSG_MAP(CDlgSet)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgSet message handlers
