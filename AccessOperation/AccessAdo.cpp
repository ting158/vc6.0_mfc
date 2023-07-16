// AccessAdo.cpp: implementation of the CAccessAdo class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AccessOperation.h"
#include "AccessAdo.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CAccessAdo::CAccessAdo()
{

}

CAccessAdo::~CAccessAdo()
{

}

//连接access数据库
void CAccessAdo::ConnectionDatabase()
{
	::CoInitialize(NULL);
	try
	{
       m_pConnection.CreateInstance("ADODB.Connection");
       CString DBpath,strConnect;
	   
	   DBpath = ".\\student.mdb";

       strConnect.Format("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=%s;Persist Security Info=False;Mode=Share Deny None",DBpath);
       m_pConnection->Open((_bstr_t)strConnect,"","",adModeUnknown);
		AfxMessageBox("连接成功");
	}
	catch(_com_error e)
	{
		AfxMessageBox(e.ErrorMessage());
	}
}

//传入sql语句和要查询的字段名
CString CAccessAdo::GetCollect(CString strSQL, CString fieldname)
{
	// 将传入的SQL语句转换为_bstr_t类型
    _bstr_t bstrSQL = (_bstr_t)strSQL;
    
    try
    {   
        // 创建记录集对象
        m_pRecordset.CreateInstance(__uuidof(Recordset));
        
        // 如果记录集处于打开状态，则先关闭记录集
        if (m_pRecordset->State == adStateOpen)
        {
            AfxMessageBox("记录集已打开");
            m_pRecordset->Close();
        }
        
        // 打开记录集，执行SQL语句
        m_pRecordset->Open(bstrSQL, m_pConnection.GetInterfacePtr(), adOpenStatic, adLockOptimistic, adCmdText);
        
    }
    catch (_com_error e)
    {
        // 捕获并显示异常错误信息
        AfxMessageBox(e.Description());
    }
    
	if (!m_pRecordset->adoEOF)
	{
		CString strValue;

		_variant_t variValue,variField;
		variField = (_variant_t)fieldname;  //CString转换为_variant_t

		variValue = m_pRecordset->GetCollect(variField);   //获取字段值

		if( variValue.vt != VT_NULL)
		{
			strValue = (char *) _bstr_t  (variValue);  //_variant_t转换为CString
		}
		return strValue;	
	}	
}

//执行SQL语句，传入CString类型
void CAccessAdo::ExecuteCStringSql(CString strSQL)
{
	_bstr_t bstrSQL;
	_variant_t RecordsAffected;

	bstrSQL = (_bstr_t)strSQL;

	try
	{
        m_pConnection->Execute(bstrSQL,NULL,adCmdText);
	}
	catch(_com_error e)
	{
		AfxMessageBox(e.Description());
	}
}
