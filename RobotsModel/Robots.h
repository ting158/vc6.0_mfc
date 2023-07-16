// Robots.h: interface for the CRobots class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ROBOTS_H__7257B901_B68D_41F7_A74E_E7A5284017B4__INCLUDED_)
#define AFX_ROBOTS_H__7257B901_B68D_41F7_A74E_E7A5284017B4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Ado.h"

enum MoveType
{
	WALK, JUMP, WAVE, WINK
};

class CRobots
{
public:
	void MoveWave();
	void MoveWink();
	void MoveJump();
	void MoveWalk();
	void Move();
	void InitRobot(int id);
	void DrawRobot();
	void Draw(CDC *p);
	CRobots();
	virtual ~CRobots();
	
	CDC *pDC;

	CAdo m_ado;

	CPoint m_YD;
	float m_kx, m_ky;
	float m_deltaT;

	int m_MoveType;

	float m_v;

	int m_eyeflag;   //���۱��۵ı�ǣ�Ϊ��ʵ��գ�۲���
	float m_t; //���ڸ���ʵ�ֻ��ֽǶȵ����ұ仯

	int m_id;
	CString m_robotName;   //����������
	float m_x, m_y;        //������ԭ�㣺���������
	float m_wBody, m_hBody;
	float m_wNeck, m_hNeck;
	float m_rHead;
	float m_wEyes, m_hEyes;
	float m_wNose;
	float m_wMouth, m_hMouth;
	float m_wArm, m_hArm, m_AngleArm;
	float m_wLeg, m_hLeg;
	float m_wFoot, m_hFoot;
};

#endif // !defined(AFX_ROBOTS_H__7257B901_B68D_41F7_A74E_E7A5284017B4__INCLUDED_)
