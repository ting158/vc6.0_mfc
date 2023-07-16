// Robot.cpp: implementation of the CRobot class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SweepingRobot.h"
#include "Robot.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CRobot::CRobot()
{
	m_deltaT = 0.02;

	m_r = 0.2;
	m_x = m_w - m_r - 0.5;
	m_y = m_w - m_r - 0.5;

	m_voltage = 15;
	m_kv = 0.011304;
	m_v = m_kv * m_voltage;  //速度 = kv * 电压


	//初始速度
	srand((int)time(NULL));
	m_angle = rand() % 360;
	m_vx = m_v * cos(m_angle);
	m_vy = m_v * sin(m_angle);
}

CRobot::~CRobot()
{

}

void CRobot::Draw(CDC *p)
{
	int x, y, r;
	pDC = p;

	CBrush b;
	b.CreateSolidBrush(RGB(230, 230, 250));
	pDC->SelectObject(&b);
	x = m_YD.x + m_x * m_kx;
	y = m_YD.y + m_y * m_ky;
	r = m_r * m_kx;
	pDC->Ellipse(x - r, y - r, x + r, y + r);
}

void CRobot::MoveByKey(UINT nChar)
{
	float x = m_x;
	float y = m_y;

	m_v = m_kv * m_voltage;

	switch(nChar)
	{
	case 37:
		x -= m_v * m_deltaT;
		if(!CollisionChecking(x, y))
			m_x = x;
		break;
	case 38:
		y += m_v * m_deltaT;
		if(!CollisionChecking(x, y))
			m_y = y;
		break;
	case 39:
		x += m_v * m_deltaT;
		if(!CollisionChecking(x, y))
			m_x = x;
		break;
	case 40:
		y -= m_v * m_deltaT;
		if(!CollisionChecking(x, y))
			m_y = y;
		break;
	
	
	}
}

int CRobot::CollisionChecking(float x, float y)
{
	int i;
	float x0, y0, w, h, d[4];
	float rec1[4][2];
	float rec2[4][2];

	if (x - m_r < 0 || y + m_r > m_w || x + m_r > m_w || y - m_r < 0)
	{
		if (x - m_r < 0 || x + m_r > m_w)
			m_vx = -m_vx;
		if (y + m_r > m_w || y - m_r < 0)
			m_vy = -m_vy;
		return 1;
	}
	for (i = 0; i < m_nFur; i++)
	{
		rec1[0][0] = m_Fur[i].pos[0][0] - m_r;	rec1[0][1] = m_Fur[i].pos[0][1];
		rec1[1][0] = m_Fur[i].pos[1][0] - m_r;	rec1[1][1] = m_Fur[i].pos[1][1];
		rec1[2][0] = m_Fur[i].pos[2][0] + m_r;	rec1[2][1] = m_Fur[i].pos[2][1];
		rec1[3][0] = m_Fur[i].pos[3][0] + m_r;	rec1[3][1] = m_Fur[i].pos[3][1];
		rec2[0][0] = m_Fur[i].pos[0][0];  rec2[0][1] = m_Fur[i].pos[0][1] + m_r;
		rec2[1][0] = m_Fur[i].pos[1][0];  rec2[1][1] = m_Fur[i].pos[1][1] - m_r;
		rec2[2][0] = m_Fur[i].pos[2][0];  rec2[2][1] = m_Fur[i].pos[2][1] - m_r;
		rec2[3][0] = m_Fur[i].pos[3][0];  rec2[3][1] = m_Fur[i].pos[3][1] + m_r;

		if (isPointInRectangle(x, y, rec1) || isPointInRectangle(x, y, rec2))
		{
			if (x - m_r < m_Fur[i].pos[0][0] || x + m_r > m_Fur[i].pos[3][0])
				m_vx = -m_vx;
			if (y - m_r < m_Fur[i].pos[1][1] || y + m_r > m_Fur[i].pos[0][1])
				m_vy = -m_vy;
			return 1;
		}

		d[0] = sqrt((x - m_Fur[i].pos[0][0]) * (x - m_Fur[i].pos[0][0]) + (y - m_Fur[i].pos[0][1]) * (y - m_Fur[i].pos[0][1]));
		d[1] = sqrt((x - m_Fur[i].pos[1][0]) * (x - m_Fur[i].pos[1][0]) + (y - m_Fur[i].pos[1][1]) * (y - m_Fur[i].pos[1][1]));
		d[2] = sqrt((x - m_Fur[i].pos[2][0]) * (x - m_Fur[i].pos[2][0]) + (y - m_Fur[i].pos[2][1]) * (y - m_Fur[i].pos[2][1]));
		d[3] = sqrt((x - m_Fur[i].pos[3][0]) * (x - m_Fur[i].pos[3][0]) + (y - m_Fur[i].pos[3][1]) * (y - m_Fur[i].pos[3][1]));
		if (d[0] < m_r || d[1] < m_r || d[2] < m_r || d[3] < m_r)
		{
			m_angle += 30;
			m_vx = m_v * cos(m_angle);
			m_vy = m_v * sin(m_angle);

			return 1;
		}
			
	}
	return 0;
}

int CRobot::isPointInRectangle(float x, float y, float rec[][2])
{
	if (x > rec[0][0] && x < rec[3][0] && y > rec[1][1] && y < rec[0][1])
	{
		return 1;
	}
	return 0;
}

void CRobot::Move()
{
	float xtarget = m_x;
	float ytarget = m_y;


	xtarget += m_vx * m_deltaT;
	ytarget += m_vy * m_deltaT;

	
	if (!CollisionChecking(xtarget, ytarget))
	{
		m_x = xtarget;
		m_y = ytarget;
	}
}

