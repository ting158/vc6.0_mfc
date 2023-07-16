// AccessAdo.h: interface for the CAccessAdo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ACCESSADO_H__BFCEEFE6_A780_4BE3_9454_5F481EE5A215__INCLUDED_)
#define AFX_ACCESSADO_H__BFCEEFE6_A780_4BE3_9454_5F481EE5A215__INCLUDED_

#import "C:\Program Files\Common Files\System\ado\msado15.dll" no_namespace rename("EOF","adoEOF")

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CAccessAdo  
{
public:
	void ExecuteCStringSql(CString strSQL);
	CString GetCollect(CString sql, CString fieldname);
	void ConnectionDatabase();
	CAccessAdo();
	virtual ~CAccessAdo();

	_ConnectionPtr m_pConnection;
	_RecordsetPtr m_pRecordset;
};

#endif // !defined(AFX_ACCESSADO_H__BFCEEFE6_A780_4BE3_9454_5F481EE5A215__INCLUDED_)
