// Ado.h: interface for the CAdo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADO_H__5F3F0FF8_FCA8_411F_877F_467107828B76__INCLUDED_)
#define AFX_ADO_H__5F3F0FF8_FCA8_411F_877F_467107828B76__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#import "C:\Program Files\Common Files\System\ado\msado15.dll" no_namespace rename("EOF","adoEOF")


class CAdo  
{
public:
	void Delete();
	void Add();
	void Query();
	void Connect();
	CAdo();
	virtual ~CAdo();

	_ConnectionPtr m_pConnection;
	_RecordsetPtr m_pRecordset;


};

#endif // !defined(AFX_ADO_H__5F3F0FF8_FCA8_411F_877F_467107828B76__INCLUDED_)
