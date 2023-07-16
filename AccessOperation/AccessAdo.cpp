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

//����access���ݿ�
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
		AfxMessageBox("���ӳɹ�");
	}
	catch(_com_error e)
	{
		AfxMessageBox(e.ErrorMessage());
	}
}

//����sql����Ҫ��ѯ���ֶ���
CString CAccessAdo::GetCollect(CString strSQL, CString fieldname)
{
	// �������SQL���ת��Ϊ_bstr_t����
    _bstr_t bstrSQL = (_bstr_t)strSQL;
    
    try
    {   
        // ������¼������
        m_pRecordset.CreateInstance(__uuidof(Recordset));
        
        // �����¼�����ڴ�״̬�����ȹرռ�¼��
        if (m_pRecordset->State == adStateOpen)
        {
            AfxMessageBox("��¼���Ѵ�");
            m_pRecordset->Close();
        }
        
        // �򿪼�¼����ִ��SQL���
        m_pRecordset->Open(bstrSQL, m_pConnection.GetInterfacePtr(), adOpenStatic, adLockOptimistic, adCmdText);
        
    }
    catch (_com_error e)
    {
        // ������ʾ�쳣������Ϣ
        AfxMessageBox(e.Description());
    }
    
	if (!m_pRecordset->adoEOF)
	{
		CString strValue;

		_variant_t variValue,variField;
		variField = (_variant_t)fieldname;  //CStringת��Ϊ_variant_t

		variValue = m_pRecordset->GetCollect(variField);   //��ȡ�ֶ�ֵ

		if( variValue.vt != VT_NULL)
		{
			strValue = (char *) _bstr_t  (variValue);  //_variant_tת��ΪCString
		}
		return strValue;	
	}	
}

//ִ��SQL��䣬����CString����
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
