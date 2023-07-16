// Ado.h: interface for the CAdo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADO_H__BA20E45E_1A96_4FF8_9745_4378EBE46A42__INCLUDED_)
#define AFX_ADO_H__BA20E45E_1A96_4FF8_9745_4378EBE46A42__INCLUDED_
//#import "C:\Program Files\Common Files\System\ado\msado15.dll" no_namespace rename("EOF","adoEOF")
#import "c:/program files/common files/system/ado/msado15.dll" rename_namespace("myADO") rename("EOF","adoEOF")
using namespace myADO;

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CAdo  
{
public:
	//数据库查询结果的记录集对象
	_RecordsetPtr m_pRecordset;
	_ConnectionPtr m_pConnection;
	CString m_UserID;
	CString m_PassWord;
	CString m_DataSouce;

public:	
	void OnInitADOConnOrcal(CString UserID, CString PassWord, CString DataSouce);
	void OnInitADOConn(CString UserID,CString PassWord,CString DataSouce);
	void OnInitADOConnOrcal();
	void OnInitADOConnAccess();
	BOOL ExecuteSQL(CString strSQL);
	CString GetCollect(CString strField);
	_RecordsetPtr& GetRecordSet(CString strSQL);
	void OnInitADOConnSQLServer();
	void OnInitADOConn(CString filename);
	void ExitConnect();
	BOOL ExecuteSQL(_bstr_t bstrSQL);
	_RecordsetPtr& GetRecordSet(_bstr_t bstrSQL);
	void OnInitADOConn();
	CAdo();
	virtual ~CAdo();
};

#endif // !defined(AFX_ADO_H__BA20E45E_1A96_4FF8_9745_4378EBE46A42__INCLUDED_)
