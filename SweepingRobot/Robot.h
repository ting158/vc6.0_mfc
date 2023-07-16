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
	float m_voltage;  //��ѹ�����������ٶȣ�
	float m_v, m_vx, m_vy;        //�ٶ�
	float m_kv;       //��ѹ���ٶȵ�ת��ϵ��
	float m_angle;



};

#endif // !defined(AFX_ROBOT_H__00254751_1505_4B99_9556_803415E790E4__INCLUDED_)
