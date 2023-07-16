// Robot.h: interface for the CRobot class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ROBOT_H__AB2D29FC_B987_420A_89A9_055FD24ECF82__INCLUDED_)
#define AFX_ROBOT_H__AB2D29FC_B987_420A_89A9_055FD24ECF82__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Ado.h"


enum BodyType
{
	CRICLE, TRIANGLE, ELLIPTIC, RECTANGLE
};

enum MoveType
{
	WALK, JUMP, WAVE, WINK
};

typedef struct
{
	int type;
	CString name;
	float x, y;
	float r, w, h;
}SBody;


class CRobot : public CAdo  
{
public:
	void DrawArm(SBody body, float angle);
	void ModifyEyesHigh(CString new_h);
	void Move();
	void MoveWink();
	void MoveWave();
	void MoveJump();
	void MoveWalk();
	void DrawRobot();
	void Draw(CDC *p);
	void CreateRobot();
	CRobot();
	virtual ~CRobot();


	CDC *pDC;

	CPoint m_YD;
	float m_kx, m_ky;

	float m_deltaT;
	float m_v, m_vJump;
	float m_Angle;  //»ÓÊÖµÄ½Ç¶È
	float m_t;

	int m_MoveType;
	int m_eyeOper;

	SBody m_Body[100];
	int m_nBody;
};

#endif // !defined(AFX_ROBOT_H__AB2D29FC_B987_420A_89A9_055FD24ECF82__INCLUDED_)
