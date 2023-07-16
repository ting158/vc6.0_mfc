// Robot.h: interface for the CRobot class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ROBOT_H__1A504EE0_16E7_41D2_8B81_BFA56E353E48__INCLUDED_)
#define AFX_ROBOT_H__1A504EE0_16E7_41D2_8B81_BFA56E353E48__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#import "C:\Program Files\Common Files\System\ado\msado15.dll" no_namespace rename("EOF","adoEOF")

enum BodyType
{
	CRICLE, TRIANGLE, ELLIPTIC, RECTANGLE
};


typedef struct
{
	int type;
	CString name;
	int x, y;
	int r, w, h;
}SBody;



class CRobot
{
public:
	void DrawRobot();
	void Draw(CDC *p);
	void ConnectDatabase();
	void InitRobot();
	CRobot();
	virtual ~CRobot();

	_ConnectionPtr m_pConnection;
	_RecordsetPtr m_pRecordset;

	CDC *pDC;

	CPoint m_YD;
	float m_kx, m_ky;

	SBody m_Body[100];
	int m_nBody;

};

#endif // !defined(AFX_ROBOT_H__1A504EE0_16E7_41D2_8B81_BFA56E353E48__INCLUDED_)
