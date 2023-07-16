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
    // ����ADO���Ӷ���
    HRESULT hr = m_pConnection.CreateInstance(__uuidof(Connection));
    if (SUCCEEDED(hr))
    {
        try
        {
            // �����ַ���
            CString strConnect;
            strConnect.Format(_T("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=student.mdb;"));

            // �����ݿ�����
            m_pConnection->Open((_bstr_t)strConnect, "", "", adModeUnknown);

            // ���ӳɹ�
            AfxMessageBox(_T("���ӳɹ���"));
        }
        catch (_com_error& e)
        {
            // ����ʧ��
            CString strError = e.ErrorMessage();
            AfxMessageBox(strError);
        }
    }
}

void CAdo::Query()
{
	try
    {
        // ����ADO��¼������
        m_pRecordset.CreateInstance(__uuidof(Recordset));

        // ִ��SQL��ѯ���
        CString strSQL = _T("SELECT * FROM student");
        m_pRecordset->Open((_bstr_t)strSQL, m_pConnection.GetInterfacePtr(), adOpenStatic, adLockOptimistic, adCmdText);

        // ������¼��
        while (!m_pRecordset->adoEOF)
        {
            // ��ȡ�ֶ�ֵ
            _variant_t varValue = m_pRecordset->Fields->GetItem(_variant_t("SName"))->Value;

            // ת��ΪCString
            CString strValue;
            if (varValue.vt == VT_BSTR)
                strValue = varValue.bstrVal;
            else
                strValue = _T("");

            // ����ֶ�ֵ
            AfxMessageBox(strValue);

            // �ƶ�����һ����¼
            m_pRecordset->MoveNext();
        }

        // �رռ�¼��
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
		CString strSqlQuery = _T("INSERT INTO student VALUES ('1003', '��4', '��', '������Ϣ', '����')"); // YourTable����ı�����Field1��Field2������ֶ���

		_variant_t vRecordsAffected;
		m_pConnection->Execute(_bstr_t(strSqlQuery), &vRecordsAffected, adCmdText);

		AfxMessageBox("������ݳɹ�");
	}
	catch (_com_error &e)
	{
		AfxMessageBox("���ʧ��: " + CString(e.ErrorMessage()));
	}
}

void CAdo::Delete()
{
	try
	{
		CString strSqlQuery = _T("delete from student where SNo = '1005'"); // YourTable����ı�����Field1��Field2������ֶ���

		_variant_t vRecordsAffected;
		m_pConnection->Execute(_bstr_t(strSqlQuery), &vRecordsAffected, adCmdText);

		AfxMessageBox("ɾ���ɹ�");
	}
	catch (_com_error &e)
	{
		AfxMessageBox("ɾ��ʧ��: " + CString(e.ErrorMessage()));
	}
}
