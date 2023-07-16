// Ado.cpp: implementation of the CAdo class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Ado.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CAdo::CAdo()
{

}

CAdo::~CAdo()
{

}

void CAdo::OnInitADOConn()
{
	OnInitADOConnAccess();
//	OnInitADOConnOrcal();
//	OnInitADOConnSQLServer();
}

_RecordsetPtr& CAdo::GetRecordSet(_bstr_t bstrSQL)
{//�������غ�����ֻͬ���ββ�ͬ

  try
	{
		if(m_pConnection==NULL)
              OnInitADOConn();
		m_pRecordset.CreateInstance(__uuidof(Recordset));
		//adStateClosed   !=   m_recordset->GetState()
		if(  m_pRecordset->State ==adStateOpen)
		{
			 AfxMessageBox("��¼����");
            m_pRecordset->Close();
			//m_pRecordset=NULL;
		}
        m_pRecordset->Open(bstrSQL,m_pConnection.GetInterfacePtr(),adOpenStatic,adLockOptimistic,adCmdText);
		//m_pRecordset->Open(bstrSQL,m_pConnection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);

		 variant_t m_dirno;

	}
    catch(_com_error e)
	{
		AfxMessageBox(e.Description());
	}
	
	
	return m_pRecordset;
	
}

BOOL CAdo::ExecuteSQL(_bstr_t bstrSQL)
{//�������غ�����ͬ��ֻ�Ǵ���������Ͳ�ͬ����������ת��
	_variant_t RecordsAffected;
	try
	{
        if(m_pConnection==NULL)
	     	OnInitADOConn();
        m_pConnection->Execute(bstrSQL,NULL,adCmdText);
		return true;
	}
	catch(_com_error e)
	{
		AfxMessageBox(e.Description());
		return false;
	}
}

void CAdo::ExitConnect()
{
 try{
	 //��Ϊ NULL������״̬��State����Ϊ NULL��ʾ��¼�������Դ��ڴ�״̬����Ҫ�ȹر���
		if(m_pRecordset!=NULL)
		{
			if( m_pRecordset->State!=NULL)
			{
				m_pRecordset->Close();
				m_pRecordset=NULL;
			}
		}
		//������Ӷ����Դ��ڴ�״̬
		if( m_pConnection->State ==adStateOpen)
		{
			m_pConnection->Close();
			m_pConnection=NULL;
		}
		//�ͷ� COM��Component Object Model�������Դ
		::CoUninitialize();
	}
	catch(_com_error e)
	{
		AfxMessageBox(e.Description());
	}
}

void CAdo::OnInitADOConn(CString filename)
{//ָ��access���ݿ��ļ�attend.mdb��������
	::CoInitialize(NULL);
	try
	{
       m_pConnection.CreateInstance("ADODB.Connection");
	   char pBuf[MAX_PATH]; //���·���ı���
       CString appath,strConnect;
       GetModuleFileName(NULL, pBuf, MAX_PATH);//��ȡ��ǰִ�г��������·����
       (_tcsrchr(pBuf, _T('\\')))[1] = 0; //ɾ���ļ�����ֻ���·��
	   
	   //��·���洢��appath�ַ����У���ɾ��·��ĩβ�ķ�б�ܵõ�Ŀ¼·����
       appath=pBuf;
	   appath.TrimRight('\\');
	   
	   //��û���ļ���·�����Ƶ�pBuf�ַ������С�
	   strcpy(pBuf,appath);
      (_tcsrchr(pBuf, _T('\\')))[1] = 0; //ɾ���ļ�����ֻ���·�����൱�ڷ�����һ�������ļ�attend.mdb
	   appath=pBuf;
	   //�̶�·��attend.mdb
       appath+="attend.mdb";

	   //������֮ǰ��·�����ã�֮ǰ�ƺ�����Ч��
	   appath=filename;
      strConnect.Format("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=%s;Jet OLEDB:DataBase Password=ahut@123;Persist Security Info=False;Mode=Share Deny None",appath);
      m_pConnection->Open((_bstr_t)strConnect,"","",adModeUnknown);
	  
	   
	}
	catch(_com_error e)
	{
		AfxMessageBox("OnInitADOConn()");
		AfxMessageBox(e.Description());
	}
	/*AfxOleInit();
	m_pConnection.CreateInstance(__uuidof(Connection));

	try                 
	{	
		// �򿪱���Access��Demo.mdb
		m_pConnection->Open("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=Image.mdb","","",adModeUnknown);
	}
	catch(_com_error e)
	{
		AfxMessageBox("���ݿ�����ʧ�ܣ�ȷ�����ݿ�Image.mdb�Ƿ��ڵ�ǰ·����!");	
	}     */ 
  
}

void CAdo::OnInitADOConnSQLServer()
{
    ::CoInitialize(NULL);
	try
	{
       m_pConnection.CreateInstance("ADODB.Connection");
       CString strConnect;
	   
      strConnect.Format("Provider=SQLOLEDB;Data Sourse=Sql Server;Initial Catalog=master;User ID=sa;Password=sa");
      m_pConnection->Open((_bstr_t)strConnect,"","",adModeUnknown);
	  
	   
	}
	catch(_com_error e)
	{
		AfxMessageBox("OnInitADOConnSQLServer()");
		AfxMessageBox(e.Description());
	}
}

_RecordsetPtr& CAdo::GetRecordSet(CString strSQL)
{
	//sql��������ת��
	_bstr_t bstrSQL = (_bstr_t)strSQL;
	try
	{
		//û���ӵĻ���������
		if(m_pConnection==NULL)
              OnInitADOConn();

		//��������ʵ��
		m_pRecordset.CreateInstance(__uuidof(Recordset));
		//adStateClosed   !=   m_recordset->GetState()
		if(  m_pRecordset->State ==adStateOpen)
		{//�жϼ�¼���Ѵ򿪣�����رռ�¼��
			
			AfxMessageBox("��¼����");
            m_pRecordset->Close();
			//m_pRecordset=NULL;
		}
		//ִ��sql���
        m_pRecordset->Open(bstrSQL,m_pConnection.GetInterfacePtr(),adOpenStatic,adLockOptimistic,adCmdText);
		//m_pRecordset->Open(bstrSQL,m_pConnection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);

		 variant_t m_dirno;

	}
    catch(_com_error e)
	{
		AfxMessageBox(e.Description());
	}
	
	//���ؼ�¼��
	return m_pRecordset;
}

CString CAdo::GetCollect(CString strField)
{//strFieldҪ��ȡ���ֶ���

	//�洢��ȡ�����ֶ�ֵ��
	CString strValue;

	_variant_t variValue,variField;
	variField = (_variant_t)strField;
	//��ȡָ���ֶε�ֵ��m_pRecordset��ʾ���ݿ��ѯ����ļ�¼����
	variValue = m_pRecordset->GetCollect(variField);

	if( variValue.vt != VT_NULL)
    {//�鵽�����������ת��
		strValue = (char *) _bstr_t  (variValue);
    }
	//���鵽��ֵ���з���
	return strValue;
}

BOOL CAdo::ExecuteSQL(CString strSQL)
{
	_bstr_t bstrSQL;
	_variant_t RecordsAffected;

	//sql����������ת��
	bstrSQL = (_bstr_t)strSQL;

	try
	{
        if(m_pConnection==NULL)//���δ�������ݿ����������
	     	OnInitADOConn();
		//bstrSQL ��ʾҪִ�е� SQL ��䣬
		//NULL ��ʾ����Ҫ���ؼ�¼����adCmdText ��ʾִ�е����ı�����
        m_pConnection->Execute(bstrSQL,NULL,adCmdText);
		//ִ�гɹ�����true
		return true;
	}
	catch(_com_error e)
	{
		//ִ��ʧ�ܵ�����������true
		AfxMessageBox(e.Description());
		return false;
	}
}

void CAdo::OnInitADOConnAccess()
{
	::CoInitialize(NULL);
	try
	{
		
       m_pConnection.CreateInstance("ADODB.Connection");
       CString DBpath,strConnect;
	   
       //��õ�ǰӦ�ó���Ŀ¼���õ����ݿ�ľ���·�� 
       //DBpath = ex_AppPath + "\\db\\LianGang.mdb";
	   //���ݿ��ļ�λ�ڵ�ǰӦ�ó���Ŀ¼�µ� CAdo �ļ���
	   DBpath = ".\\CAdo\\student.mdb";

	   //������û��������붼������Ϊ���ַ���
       strConnect.Format("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=%s;Persist Security Info=False;Mode=Share Deny None",DBpath);
       m_pConnection->Open((_bstr_t)strConnect,"","",adModeUnknown);
	}
	catch(_com_error e)
	{
		AfxMessageBox("OnInitADOConn()");
		AfxMessageBox(e.Description());
	}
	/*AfxOleInit();
	m_pConnection.CreateInstance(__uuidof(Connection));

	try                 
	{	
		// �򿪱���Access��Demo.mdb
		m_pConnection->Open("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=Image.mdb","","",adModeUnknown);
	}
	catch(_com_error e)
	{
		AfxMessageBox("���ݿ�����ʧ�ܣ�ȷ�����ݿ�Image.mdb�Ƿ��ڵ�ǰ·����!");	
	}    
	*/
}

void CAdo::OnInitADOConnOrcal()
{
	::CoInitialize(NULL);
	try
	{
       m_pConnection.CreateInstance("ADODB.Connection");
       CString DBpath,strConnect;
	   
       //��õ�ǰӦ�ó���Ŀ¼���õ����ݿ�ľ���·��
       

  //     strConnect.Format("Provider=MSDAORA.1;User ID=%s;Password=%s;Data Source=%s;Persist Security Info=False",ex_pModel->m_DataBase.UserID,ex_pModel->m_DataBase.PassWord,ex_pModel->m_DataBase.DBName);
       m_pConnection->Open((_bstr_t)strConnect,"","",adModeUnknown);
	}
	catch(_com_error e)
	{
		AfxMessageBox("OnInitADOConn()");
		AfxMessageBox(e.Description());
	}
}

void CAdo::OnInitADOConn(CString UserID, CString PassWord, CString DataSouce)
{
	OnInitADOConnOrcal(UserID,PassWord,DataSouce);
}

void CAdo::OnInitADOConnOrcal(CString UserID, CString PassWord, CString DataSouce)
{
	::CoInitialize(NULL);
	try
	{
       m_pConnection.CreateInstance("ADODB.Connection");
       CString DBpath,strConnect;
	   
       //��õ�ǰӦ�ó���Ŀ¼���õ����ݿ�ľ���·��
       

       strConnect.Format("Provider=MSDAORA.1;User ID=%s;Password=%s;Data Source=%s;Persist Security Info=False",UserID,PassWord,DataSouce);
       m_pConnection->Open((_bstr_t)strConnect,"","",adModeUnknown);
	}
	catch(_com_error e)
	{
		AfxMessageBox("OnInitADOConn()");
		AfxMessageBox(e.Description());
	}
}
