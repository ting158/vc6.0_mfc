// Robot.h: interface for the CRobot class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ROBOT_H__00254751_1505_4B99_9556_803415E790E4__INCLUDED_)
#define AFX_ROBOT_H__00254751_1505_4B99_9556_803415E790E4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Room.h"

#include "math.h"

class CRobot : public CRoom
{
public:
	void Move();
	int isPointInRectangle(float x, float y, float rec[][2]);
	int CollisionChecking(float x, float y);
	void MoveByKey(UINT nChar);
	void Draw(CDC *p);
	CRobot();
	virtual ~CRobot();

	float m_deltaT;

	float m_x, m_y;
	float m_r;
	float m_voltage;  //电压（用来控制速度）
	float m_v, m_vx, m_vy;        //速度
	float m_kv;       //电压与速度的转换系数
	float m_angle;



};

#endif // !defined(AFX_ROBOT_H__00254751_1505_4B99_9556_803415E790E4__INCLUDED_)
