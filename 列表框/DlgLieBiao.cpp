// DlgLieBiao.cpp : implementation file
//

#include "stdafx.h"
#include "�б��.h"
#include "DlgLieBiao.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgLieBiao dialog


CDlgLieBiao::CDlgLieBiao(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgLieBiao::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgLieBiao)
	//}}AFX_DATA_INIT
}


void CDlgLieBiao::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgLieBiao)
	DDX_Control(pDX, IDC_LIST2, m_ListCtr);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgLieBiao, CDialog)
	//{{AFX_MSG_MAP(CDlgLieBiao)
	ON_NOTIFY(NM_CLICK, IDC_LIST2, OnClickList2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgLieBiao message handlers

BOOL CDlgLieBiao::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	DWORD dwStyle = m_ListCtr.GetExtendedStyle(); 
	dwStyle |= LVS_EX_FULLROWSELECT;//ѡ��ĳ��ʹ���и�����ֻ������report��� 
	dwStyle |= LVS_EX_GRIDLINES;//�����ߣ�ֻ������report����listctrl�� 
	dwStyle |= LVS_EX_CHECKBOXES;//itemǰ����checkbox�ؼ� 
	m_ListCtr.SetExtendedStyle(dwStyle); //������չ���
	m_ListCtr.SetExtendedStyle(LVS_EX_FLATSB
		|LVS_EX_FULLROWSELECT
		|LVS_EX_HEADERDRAGDROP
		|LVS_EX_ONECLICKACTIVATE
		|LVS_EX_GRIDLINES);

	int i = 0;
	m_ListCtr.InsertColumn(i++,"ģ����",LVCFMT_LEFT,120,0);
	m_ListCtr.InsertColumn(i++,"����",LVCFMT_LEFT,80,1);
	m_ListCtr.InsertColumn(i++,"����ʱ��",LVCFMT_LEFT,130,1);
	m_ListCtr.InsertColumn(i++,"����޸�ʱ��",LVCFMT_LEFT,130,1);
	m_ListCtr.InsertColumn(i++,"��ע",LVCFMT_LEFT,300,1);


	m_ListCtr.InsertItem(0,"aaa");
	m_ListCtr.SetItemText(0,1,"bbb");
	m_ListCtr.SetItemText(0,2,"ccc");
	m_ListCtr.SetItemText(0,3,"ddd");
	m_ListCtr.SetItemText(0,4, "eee");

	m_ListCtr.InsertItem(1,"aaa");
	m_ListCtr.SetItemText(1,1,"bbb");
	m_ListCtr.SetItemText(1,2,"ccc");
	m_ListCtr.SetItemText(1,3,"ddd");
	m_ListCtr.SetItemText(1,4, "eee");

	m_ListCtr.SetItemState(1,LVIS_SELECTED|LVIS_FOCUSED,LVIS_SELECTED|LVIS_FOCUSED);
	m_ListCtr.SetFocus();

	m_ListCtr.GetItemCount();



	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgLieBiao::OnClickList2(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
//	int Pos;
//	Pos = m_ListCtr.GetSelectionMark();
//	m_ModelName = m_ListCtr.GetItemText(Pos,0);


	*pResult = 0;
}
