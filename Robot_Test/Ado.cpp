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
{//与其重载函数相同只是形参不同

  try
	{
		if(m_pConnection==NULL)
              OnInitADOConn();
		m_pRecordset.CreateInstance(__uuidof(Recordset));
		//adStateClosed   !=   m_recordset->GetState()
		if(  m_pRecordset->State ==adStateOpen)
		{
			 AfxMessageBox("记录集打开");
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
{//与其重载函数相同，只是传入参数类型不同，无需类型转换
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
	 //不为 NULL，且其状态（State）不为 NULL表示记录集对象仍处于打开状态，需要先关闭它
		if(m_pRecordset!=NULL)
		{
			if( m_pRecordset->State!=NULL)
			{
				m_pRecordset->Close();
				m_pRecordset=NULL;
			}
		}
		//检测连接对象仍处于打开状态
		if( m_pConnection->State ==adStateOpen)
		{
			m_pConnection->Close();
			m_pConnection=NULL;
		}
		//释放 COM（Component Object Model）库的资源
		::CoUninitialize();
	}
	catch(_com_error e)
	{
		AfxMessageBox(e.Description());
	}
}

void CAdo::OnInitADOConn(CString filename)
{//指定access数据库文件attend.mdb进行连接
	::CoInitialize(NULL);
	try
	{
       m_pConnection.CreateInstance("ADODB.Connection");
	   char pBuf[MAX_PATH]; //存放路径的变量
       CString appath,strConnect;
       GetModuleFileName(NULL, pBuf, MAX_PATH);//获取当前执行程序的完整路径。
       (_tcsrchr(pBuf, _T('\\')))[1] = 0; //删除文件名，只获得路径
	   
	   //将路径存储到appath字符串中，并删除路径末尾的反斜杠得到目录路径。
       appath=pBuf;
	   appath.TrimRight('\\');
	   
	   //将没有文件的路径复制到pBuf字符数组中。
	   strcpy(pBuf,appath);
      (_tcsrchr(pBuf, _T('\\')))[1] = 0; //删除文件名，只获得路径，相当于返回上一级查找文件attend.mdb
	   appath=pBuf;
	   //固定路径attend.mdb
       appath+="attend.mdb";

	   //覆盖了之前的路径设置，之前似乎是无效的
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
		// 打开本地Access库Demo.mdb
		m_pConnection->Open("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=Image.mdb","","",adModeUnknown);
	}
	catch(_com_error e)
	{
		AfxMessageBox("数据库连接失败，确认数据库Image.mdb是否在当前路径下!");	
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
	//sql语句的类型转换
	_bstr_t bstrSQL = (_bstr_t)strSQL;
	try
	{
		//没连接的话进行连接
		if(m_pConnection==NULL)
              OnInitADOConn();

		//创建对象实例
		m_pRecordset.CreateInstance(__uuidof(Recordset));
		//adStateClosed   !=   m_recordset->GetState()
		if(  m_pRecordset->State ==adStateOpen)
		{//判断记录集已打开，是则关闭记录集
			
			AfxMessageBox("记录集打开");
            m_pRecordset->Close();
			//m_pRecordset=NULL;
		}
		//执行sql语句
        m_pRecordset->Open(bstrSQL,m_pConnection.GetInterfacePtr(),adOpenStatic,adLockOptimistic,adCmdText);
		//m_pRecordset->Open(bstrSQL,m_pConnection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);

		 variant_t m_dirno;

	}
    catch(_com_error e)
	{
		AfxMessageBox(e.Description());
	}
	
	//返回记录集
	return m_pRecordset;
}

CString CAdo::GetCollect(CString strField)
{//strField要获取的字段名

	//存储获取到的字段值。
	CString strValue;

	_variant_t variValue,variField;
	variField = (_variant_t)strField;
	//获取指定字段的值，m_pRecordset表示数据库查询结果的记录集。
	variValue = m_pRecordset->GetCollect(variField);

	if( variValue.vt != VT_NULL)
    {//查到了则进行类型转换
		strValue = (char *) _bstr_t  (variValue);
    }
	//将查到的值进行返回
	return strValue;
}

BOOL CAdo::ExecuteSQL(CString strSQL)
{
	_bstr_t bstrSQL;
	_variant_t RecordsAffected;

	//sql语句进行类型转换
	bstrSQL = (_bstr_t)strSQL;

	try
	{
        if(m_pConnection==NULL)//如果未连接数据库则进行连接
	     	OnInitADOConn();
		//bstrSQL 表示要执行的 SQL 语句，
		//NULL 表示不需要返回记录集，adCmdText 表示执行的是文本命令
        m_pConnection->Execute(bstrSQL,NULL,adCmdText);
		//执行成功返回true
		return true;
	}
	catch(_com_error e)
	{
		//执行失败弹窗报错并返回true
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
	   
       //获得当前应用程序目录并得到数据库的绝对路径 
       //DBpath = ex_AppPath + "\\db\\LianGang.mdb";
	   //数据库文件位于当前应用程序目录下的 CAdo 文件夹
	   DBpath = ".\\CAdo\\student.mdb";

	   //在这里，用户名和密码都被设置为空字符串
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
		// 打开本地Access库Demo.mdb
		m_pConnection->Open("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=Image.mdb","","",adModeUnknown);
	}
	catch(_com_error e)
	{
		AfxMessageBox("数据库连接失败，确认数据库Image.mdb是否在当前路径下!");	
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
	   
       //获得当前应用程序目录并得到数据库的绝对路径
       

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
	   
       //获得当前应用程序目录并得到数据库的绝对路径
       

       strConnect.Format("Provider=MSDAORA.1;User ID=%s;Password=%s;Data Source=%s;Persist Security Info=False",UserID,PassWord,DataSouce);
       m_pConnection->Open((_bstr_t)strConnect,"","",adModeUnknown);
	}
	catch(_com_error e)
	{
		AfxMessageBox("OnInitADOConn()");
		AfxMessageBox(e.Description());
	}
}
