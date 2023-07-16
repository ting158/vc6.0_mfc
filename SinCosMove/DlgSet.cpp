// DlgSet.cpp : implementation file
//

#include "stdafx.h"
#include "SinCosMove.h"
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
	m_XW = 0.0f;
	m_ZQ = 0.0f;
	m_ZF = 0.0f;
	//}}AFX_DATA_INIT
}


void CDlgSet::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgSet)
	DDX_Text(pDX, IDC_EDIT1, m_XW);
	DDX_Text(pDX, IDC_EDIT2, m_ZQ);
	DDX_Text(pDX, IDC_EDIT3, m_ZF);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgSet, CDialog)
	//{{AFX_MSG_MAP(CDlgSet)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgSet message handlers
