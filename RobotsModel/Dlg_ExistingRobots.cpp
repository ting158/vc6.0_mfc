// Dlg_ExistingRobots.cpp : implementation file
//

#include "stdafx.h"
#include "RobotsModel.h"
#include "Dlg_ExistingRobots.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlg_ExistingRobots dialog


CDlg_ExistingRobots::CDlg_ExistingRobots(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg_ExistingRobots::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_ExistingRobots)
	m_AngleArm = _T("");
	m_hArm = _T("");
	m_hBody = _T("");
	m_hEyes = _T("");
	m_hFoot = _T("");
	m_hLeg = _T("");
	m_hMouth = _T("");
	m_hNeck = _T("");
	m_rHead = _T("");
	m_robotName = _T("");
	m_wArm = _T("");
	m_wBody = _T("");
	m_wEyes = _T("");
	m_wFoot = _T("");
	m_wLeg = _T("");
	m_wMouth = _T("");
	m_wNeck = _T("");
	m_wNose = _T("");
	m_x = _T("");
	m_y = _T("");
	//}}AFX_DATA_INIT
}


void CDlg_ExistingRobots::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_ExistingRobots)
	DDX_Control(pDX, IDC_LIST_Robots, m_listRobots);
	DDX_Text(pDX, IDC_EDIT_AngleArm2, m_AngleArm);
	DDX_Text(pDX, IDC_EDIT_hArm2, m_hArm);
	DDX_Text(pDX, IDC_EDIT_hBody, m_hBody);
	DDX_Text(pDX, IDC_EDIT_hEyes2, m_hEyes);
	DDX_Text(pDX, IDC_EDIT_hFoot2, m_hFoot);
	DDX_Text(pDX, IDC_EDIT_hLeg2, m_hLeg);
	DDX_Text(pDX, IDC_EDIT_hMouth, m_hMouth);
	DDX_Text(pDX, IDC_EDIT_hNeck, m_hNeck);
	DDX_Text(pDX, IDC_EDIT_rHead2, m_rHead);
	DDX_Text(pDX, IDC_EDIT_robotName, m_robotName);
	DDX_Text(pDX, IDC_EDIT_wArm2, m_wArm);
	DDX_Text(pDX, IDC_EDIT_wBody, m_wBody);
	DDX_Text(pDX, IDC_EDIT_wEyes2, m_wEyes);
	DDX_Text(pDX, IDC_EDIT_wFoot2, m_wFoot);
	DDX_Text(pDX, IDC_EDIT_wLeg2, m_wLeg);
	DDX_Text(pDX, IDC_EDIT_wMouth2, m_wMouth);
	DDX_Text(pDX, IDC_EDIT_wNeck, m_wNeck);
	DDX_Text(pDX, IDC_EDIT_wNose2, m_wNose);
	DDX_Text(pDX, IDC_EDIT_x, m_x);
	DDX_Text(pDX, IDC_EDIT_y, m_y);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlg_ExistingRobots, CDialog)
	//{{AFX_MSG_MAP(CDlg_ExistingRobots)
	ON_NOTIFY(NM_CLICK, IDC_LIST_Robots, OnClickLISTRobots)
	ON_BN_CLICKED(IDC_BUTTON_Delete, OnBUTTONDelete)
	ON_BN_CLICKED(IDC_BUTTON_Modify, OnBUTTONModify)
	ON_BN_CLICKED(IDC_BUTTON_Add, OnBUTTONAdd)
	ON_BN_CLICKED(IDC_BUTTON_SaveToFile, OnBUTTONSaveToFile)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlg_ExistingRobots message handlers

BOOL CDlg_ExistingRobots::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	DWORD dwStyle;

	dwStyle = m_listRobots.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES  | LVS_EX_ONECLICKACTIVATE;
	m_listRobots.SetExtendedStyle(dwStyle); //设置显示风格

	m_listRobots.InsertColumn(0,"序号",LVCFMT_CENTER,100); //第一个参数是字段的编号
	m_listRobots.InsertColumn(1,"姓名",LVCFMT_CENTER,150); //第二个参数是字段的名字

	Display();  //在列表框中显示所有的机器人

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlg_ExistingRobots::OnClickLISTRobots(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	m_ado.OnInitADOConn(".\\Robots.mdb");

	m_index = m_listRobots.GetSelectionMark(); //获取选中的行
	m_strID = m_listRobots.GetItemText(m_index, 0);  //选中行，列的的值

	CString strSQL;
	strSQL.Format("select * from Robots where ID = %s", m_strID);
	m_ado.GetRecordSet(strSQL);

	m_robotName = m_ado.GetCollect("robotName");   m_x = m_ado.GetCollect("x");
	m_y = m_ado.GetCollect("y");                   m_wBody = m_ado.GetCollect("wBody");
	m_hBody = m_ado.GetCollect("hBody");           m_wNeck = m_ado.GetCollect("wNeck");
	m_hNeck = m_ado.GetCollect("hNeck");           m_rHead = m_ado.GetCollect("rHead");
	m_wEyes = m_ado.GetCollect("wEyes");           m_hEyes = m_ado.GetCollect("hEyes");
	m_wNose = m_ado.GetCollect("wNose");		   m_wMouth = m_ado.GetCollect("wMouth");
	m_hMouth = m_ado.GetCollect("hMouth");         m_wArm = m_ado.GetCollect("wArm");
	m_hArm = m_ado.GetCollect("hArm");			   m_AngleArm = m_ado.GetCollect("AngleArm");
	m_wLeg = m_ado.GetCollect("wLeg");             m_hLeg = m_ado.GetCollect("hLeg");
	m_wFoot = m_ado.GetCollect("wFoot");		   m_hFoot = m_ado.GetCollect("hFoot");

	GetDlgItem(IDC_EDIT_robotName)->SetWindowText(m_robotName); GetDlgItem(IDC_EDIT_x)->SetWindowText(m_x);
	GetDlgItem(IDC_EDIT_y)->SetWindowText(m_y);                 GetDlgItem(IDC_EDIT_wBody)->SetWindowText(m_wBody);
	GetDlgItem(IDC_EDIT_hBody)->SetWindowText(m_hBody);         GetDlgItem(IDC_EDIT_hNeck)->SetWindowText(m_hNeck);
	GetDlgItem(IDC_EDIT_rHead2)->SetWindowText(m_rHead);        GetDlgItem(IDC_EDIT_wNeck)->SetWindowText(m_wNeck);
	GetDlgItem(IDC_EDIT_wEyes2)->SetWindowText(m_wEyes);        GetDlgItem(IDC_EDIT_hEyes2)->SetWindowText(m_hEyes);
	GetDlgItem(IDC_EDIT_wNose2)->SetWindowText(m_wNose);        GetDlgItem(IDC_EDIT_hMouth)->SetWindowText(m_hMouth);
	GetDlgItem(IDC_EDIT_wMouth2)->SetWindowText(m_wMouth);      GetDlgItem(IDC_EDIT_wArm2)->SetWindowText(m_wArm);
	GetDlgItem(IDC_EDIT_hArm2)->SetWindowText(m_hArm);          GetDlgItem(IDC_EDIT_AngleArm2)->SetWindowText(m_AngleArm);
	GetDlgItem(IDC_EDIT_wLeg2)->SetWindowText(m_wLeg);          GetDlgItem(IDC_EDIT_hLeg2)->SetWindowText(m_hLeg);
	GetDlgItem(IDC_EDIT_wFoot2)->SetWindowText(m_wFoot);        GetDlgItem(IDC_EDIT_hFoot2)->SetWindowText(m_hFoot);

	m_ado.ExitConnect();

	*pResult = 0;
}

void CDlg_ExistingRobots::OnBUTTONDelete() 
{
	// TODO: Add your control notification handler code here
	m_ado.OnInitADOConn(".\\Robots.mdb");

	CString strSQL;
	strSQL.Format("delete from Robots where ID = %s", m_strID);
	m_ado.ExecuteSQL(strSQL);

	m_listRobots.DeleteItem(m_index);

	m_ado.ExitConnect();

}

void CDlg_ExistingRobots::OnBUTTONModify() 
{
	// TODO: Add your control notification handler code here
	m_ado.OnInitADOConn(".\\Robots.mdb");

	CString robotName, x, y, wBody, hBody, wNeck, hNeck, rHead, wEyes, hEyes, 
		wNose, wMouth, hMouth, wArm, hArm, AngleArm, wLeg, hLeg, wFoot, hFoot;

	GetDlgItemText(IDC_EDIT_robotName, robotName);  GetDlgItemText(IDC_EDIT_x, x);
	GetDlgItemText(IDC_EDIT_y, y);					GetDlgItemText(IDC_EDIT_wBody, wBody);
	GetDlgItemText(IDC_EDIT_hBody, hBody);		    GetDlgItemText(IDC_EDIT_hNeck, hNeck);
	GetDlgItemText(IDC_EDIT_rHead2, rHead);			GetDlgItemText(IDC_EDIT_wNeck, wNeck);
	GetDlgItemText(IDC_EDIT_wEyes2, wEyes);			GetDlgItemText(IDC_EDIT_hEyes2, hEyes);
	GetDlgItemText(IDC_EDIT_wNose2, wNose);			GetDlgItemText(IDC_EDIT_hMouth, hMouth);
	GetDlgItemText(IDC_EDIT_wMouth2, wMouth);		GetDlgItemText(IDC_EDIT_wArm2, wArm);
	GetDlgItemText(IDC_EDIT_hArm2, hArm);			GetDlgItemText(IDC_EDIT_AngleArm2, AngleArm);
	GetDlgItemText(IDC_EDIT_wLeg2, wLeg);			GetDlgItemText(IDC_EDIT_hLeg2, hLeg);
	GetDlgItemText(IDC_EDIT_wFoot2, wFoot);			GetDlgItemText(IDC_EDIT_hFoot2, hFoot);

	CString strSQL;
	strSQL.Format("update Robots set robotName = '%s', x = '%s', y = '%s', wBody = '%s', hBody = '%s',\
		wNeck = '%s', hNeck = '%s', rHead = '%s', wEyes = '%s', hEyes = '%s', wNose = '%s', wMouth = '%s',\
		hMouth = '%s', wArm = '%s', hArm = '%s', AngleArm = '%s', wLeg = '%s', hLeg = '%s', wFoot = '%s',\
		hFoot = '%s' where ID = %s", 
		robotName, x, y, wBody, hBody, wNeck, hNeck, rHead, wEyes, hEyes, wNose, wMouth, hMouth, wArm, hArm,
		AngleArm, wLeg, hLeg, wFoot, hFoot, m_strID);

	m_ado.ExecuteSQL(strSQL);

	m_ado.ExitConnect();

	Display();
}

void CDlg_ExistingRobots::Display()
{
	m_ado.OnInitADOConn(".\\Robots.mdb");

	m_listRobots.DeleteAllItems();

	try
	{
		// 创建ADO记录集对象
		m_ado.m_pRecordset.CreateInstance(__uuidof(Recordset));

		// 执行SQL查询语句
		CString strSQL = _T("select * from Robots");
		m_ado.m_pRecordset->Open((_bstr_t)strSQL, m_ado.m_pConnection.GetInterfacePtr(), adOpenStatic, adLockOptimistic, adCmdText);

		int i = 0;
		CString id, name;

		while(!(m_ado.m_pRecordset->adoEOF))
		{
			id = m_ado.GetCollect("ID");
			name = m_ado.GetCollect("robotName");

			m_listRobots.InsertItem(i, id); //0即表格中的第一行
			m_listRobots.SetItemText(i, 1, name);

			m_ado.m_pRecordset->MoveNext();
			i++;
		}
		m_ado.m_pRecordset->Close();
	}
	catch (_com_error& e)
    {
        CString strError = e.ErrorMessage();
        AfxMessageBox(strError);
    }

	m_ado.ExitConnect();
}



void CDlg_ExistingRobots::OnBUTTONAdd() 
{
	// TODO: Add your control notification handler code here
	m_ado.OnInitADOConn(".\\Robots.mdb");

	CString robotName, x, y, wBody, hBody, wNeck, hNeck, rHead, wEyes, hEyes, 
		wNose, wMouth, hMouth, wArm, hArm, AngleArm, wLeg, hLeg, wFoot, hFoot;

	GetDlgItemText(IDC_EDIT_robotName, robotName);  GetDlgItemText(IDC_EDIT_x, x);
	GetDlgItemText(IDC_EDIT_y, y);					GetDlgItemText(IDC_EDIT_wBody, wBody);
	GetDlgItemText(IDC_EDIT_hBody, hBody);		    GetDlgItemText(IDC_EDIT_hNeck, hNeck);
	GetDlgItemText(IDC_EDIT_rHead2, rHead);			GetDlgItemText(IDC_EDIT_wNeck, wNeck);
	GetDlgItemText(IDC_EDIT_wEyes2, wEyes);			GetDlgItemText(IDC_EDIT_hEyes2, hEyes);
	GetDlgItemText(IDC_EDIT_wNose2, wNose);			GetDlgItemText(IDC_EDIT_hMouth, hMouth);
	GetDlgItemText(IDC_EDIT_wMouth2, wMouth);		GetDlgItemText(IDC_EDIT_wArm2, wArm);
	GetDlgItemText(IDC_EDIT_hArm2, hArm);			GetDlgItemText(IDC_EDIT_AngleArm2, AngleArm);
	GetDlgItemText(IDC_EDIT_wLeg2, wLeg);			GetDlgItemText(IDC_EDIT_hLeg2, hLeg);
	GetDlgItemText(IDC_EDIT_wFoot2, wFoot);			GetDlgItemText(IDC_EDIT_hFoot2, hFoot);

	CString strSQL;
	strSQL.Format("insert into Robots (robotName, x, y, wBody, hBody, wNeck, hNeck, rHead, wEyes, hEyes, wNose, wMouth, \
		hMouth, wArm, hArm, AngleArm, wLeg, hLeg, wFoot, hFoot) values ('%s', '%s', '%s', '%s', '%s', '%s', '%s', \
		'%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s')", 
		robotName, x, y, wBody, hBody, wNeck, hNeck, rHead, wEyes, hEyes, wNose, wMouth,
		hMouth, wArm, hArm, AngleArm, wLeg, hLeg, wFoot, hFoot);

	m_ado.ExecuteSQL(strSQL);

	m_ado.ExitConnect();

	Display();
}

void CDlg_ExistingRobots::OnBUTTONSaveToFile() 
{
	// TODO: Add your control notification handler code here
	FILE * pf = fopen("Robots.txt", "w");

	CString robotName, x, y, wBody, hBody, wNeck, hNeck, rHead, wEyes, hEyes, 
		wNose, wMouth, hMouth, wArm, hArm, AngleArm, wLeg, hLeg, wFoot, hFoot;

	m_ado.OnInitADOConn(".\\Robots.mdb");

	try
    {
        // 创建ADO记录集对象
        m_ado.m_pRecordset.CreateInstance(__uuidof(Recordset));

        // 执行SQL查询语句
        CString strSQL = _T("select * from Robots");
        m_ado.m_pRecordset->Open((_bstr_t)strSQL, m_ado.m_pConnection.GetInterfacePtr(), adOpenStatic, adLockOptimistic, adCmdText);

        // 遍历记录集
        while (!m_ado.m_pRecordset->adoEOF)
        {
            // 读取字段值
			robotName = m_ado.GetCollect("robotName");
 			AngleArm = m_ado.GetCollect("AngleArm");
 			hArm = m_ado.GetCollect("hArm");
 			wArm = m_ado.GetCollect("wArm");
 			hBody = m_ado.GetCollect("hBody");
 			wBody = m_ado.GetCollect("wBody");
 			hEyes = m_ado.GetCollect("hEyes");
 			wEyes = m_ado.GetCollect("wEyes");
 			hFoot = m_ado.GetCollect("hFoot");
 			wFoot = m_ado.GetCollect("wFoot");
 			hLeg = m_ado.GetCollect("hLeg");
 			wLeg = m_ado.GetCollect("wLeg");
 			hNeck = m_ado.GetCollect("hNeck");
 			wNeck = m_ado.GetCollect("wNeck");
 			rHead = m_ado.GetCollect("rHead");
			wMouth = m_ado.GetCollect("wMouth");
 			hMouth = m_ado.GetCollect("hMouth");
 			x = m_ado.GetCollect("x");
 			y = m_ado.GetCollect("y");
 			wNose = m_ado.GetCollect("wNose");

			CString save;
			save.Format("robotName = %s, x = %s, y = %s, wBody = %s, hBody = %s, wNeck = %s, hNeck = %s, rHead = %s, wEyes = %s, hEyes = %s, wNose = %s, wMouth = %s, hMouth = %s, wArm = %s, hArm = %s, AngleArm = %s, wLeg = %f, hLeg = %s, wFoot = %s, hFoot = %s\n\n", 
				robotName, x, y, wBody, hBody, wNeck, hNeck, rHead, wEyes, hEyes, wNose, wMouth, hMouth, wArm, hArm, 
				AngleArm, wLeg, hLeg, wFoot, hFoot);

			fprintf(pf, save);

            // 移动到下一条记录
            m_ado.m_pRecordset->MoveNext();
        }
        // 关闭记录集
        m_ado.m_pRecordset->Close();

		
    }
    catch (_com_error& e)
    {
        CString strError = e.ErrorMessage();
        AfxMessageBox(strError);
    }

	m_ado.ExitConnect();

	fclose(pf);
	pf = NULL;
}
