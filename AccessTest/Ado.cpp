// Ado.cpp: implementation of the CAdo class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AccessTest.h"
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

void CAdo::Connect()
{
    // 创建ADO连接对象
    HRESULT hr = m_pConnection.CreateInstance(__uuidof(Connection));
    if (SUCCEEDED(hr))
    {
        try
        {
            // 连接字符串
            CString strConnect;
            strConnect.Format(_T("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=student.mdb;"));

            // 打开数据库连接
            m_pConnection->Open((_bstr_t)strConnect, "", "", adModeUnknown);

            // 连接成功
            AfxMessageBox(_T("连接成功！"));
        }
        catch (_com_error& e)
        {
            // 连接失败
            CString strError = e.ErrorMessage();
            AfxMessageBox(strError);
        }
    }
}

void CAdo::Query()
{
	try
    {
        // 创建ADO记录集对象
        m_pRecordset.CreateInstance(__uuidof(Recordset));

        // 执行SQL查询语句
        CString strSQL = _T("SELECT * FROM student");
        m_pRecordset->Open((_bstr_t)strSQL, m_pConnection.GetInterfacePtr(), adOpenStatic, adLockOptimistic, adCmdText);

        // 遍历记录集
        while (!m_pRecordset->adoEOF)
        {
            // 读取字段值
            _variant_t varValue = m_pRecordset->Fields->GetItem(_variant_t("SName"))->Value;

            // 转换为CString
            CString strValue;
            if (varValue.vt == VT_BSTR)
                strValue = varValue.bstrVal;
            else
                strValue = _T("");

            // 输出字段值
            AfxMessageBox(strValue);

            // 移动到下一条记录
            m_pRecordset->MoveNext();
        }

        // 关闭记录集
        m_pRecordset->Close();
    }
    catch (_com_error& e)
    {
        CString strError = e.ErrorMessage();
        AfxMessageBox(strError);
    }
}

void CAdo::Add()
{
	try
	{
		CString strSqlQuery = _T("INSERT INTO student VALUES ('1003', '李4', '男', '电子信息', '二班')"); // YourTable是你的表名，Field1和Field2是你的字段名

		_variant_t vRecordsAffected;
		m_pConnection->Execute(_bstr_t(strSqlQuery), &vRecordsAffected, adCmdText);

		AfxMessageBox("添加数据成功");
	}
	catch (_com_error &e)
	{
		AfxMessageBox("添加失败: " + CString(e.ErrorMessage()));
	}
}

void CAdo::Delete()
{
	try
	{
		CString strSqlQuery = _T("delete from student where SNo = '1005'"); // YourTable是你的表名，Field1和Field2是你的字段名

		_variant_t vRecordsAffected;
		m_pConnection->Execute(_bstr_t(strSqlQuery), &vRecordsAffected, adCmdText);

		AfxMessageBox("删除成功");
	}
	catch (_com_error &e)
	{
		AfxMessageBox("删除失败: " + CString(e.ErrorMessage()));
	}
}
