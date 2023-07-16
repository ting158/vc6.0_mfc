// DlgLieBiao.cpp : implementation file
//

#include "stdafx.h"
#include "列表框.h"
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
	dwStyle |= LVS_EX_FULLROWSELECT;//选中某行使整行高亮（只适用与report风格） 
	dwStyle |= LVS_EX_GRIDLINES;//网格线（只适用与report风格的listctrl） 
	dwStyle |= LVS_EX_CHECKBOXES;//item前生成checkbox控件 
	m_ListCtr.SetExtendedStyle(dwStyle); //设置扩展风格
	m_ListCtr.SetExtendedStyle(LVS_EX_FLATSB
		|LVS_EX_FULLROWSELECT
		|LVS_EX_HEADERDRAGDROP
		|LVS_EX_ONECLICKACTIVATE
		|LVS_EX_GRIDLINES);

	int i = 0;
	m_ListCtr.InsertColumn(i++,"模型名",LVCFMT_LEFT,120,0);
	m_ListCtr.InsertColumn(i++,"类型",LVCFMT_LEFT,80,1);
	m_ListCtr.InsertColumn(i++,"创建时间",LVCFMT_LEFT,130,1);
	m_ListCtr.InsertColumn(i++,"最后修改时间",LVCFMT_LEFT,130,1);
	m_ListCtr.InsertColumn(i++,"备注",LVCFMT_LEFT,300,1);


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
