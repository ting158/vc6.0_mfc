// WRJ.cpp: implementation of the CWRJ class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Robot_Check.h"
#include "WRJ.h"

#include "math.h"
#define PI 3.1415926

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CWRJ::CWRJ()
{
	m_x = 0;
	m_y = 0;
	m_r = m_w / 2;
	m_JDlxj = m_w;
	m_nd = 0;
}

CWRJ::~CWRJ()
{

}

void CWRJ::Draw(CDC *p)
{
	int x, y;
	CString str;

	pDC = p;

	DrawWuRenJi();

	//无人机浓度
	x = 1600;
	y = 50;
	str.Format("无人机附近浓度：%d", m_nd);
	pDC->TextOut(x, y, str);
}

void CWRJ::DrawWuRenJi()
{
	int x, y, r, w;

	x = m_YD.x + m_x * m_kx;
	y = m_YD.y + m_y * m_ky;
	r = m_r * m_kx;
	pDC->Ellipse(x - r, y - r, x + r, y + r);
	
	w = m_w * m_kx;
	x -= w;
	pDC->MoveTo(x, y);
	x += 2 * w;
	pDC->LineTo(x, y);

	x = m_YD.x + m_x * m_kx;
	y -= w;
	pDC->MoveTo(x, y);
	y += 2 * w;
	pDC->LineTo(x, y);

	//螺旋桨
	x = m_YD.x + m_x * m_kx;
	y = m_YD.y + m_y * m_ky;
	x -= w;
	DrawLuoXuanJiang(x, y);
	x += 2 * w;
	DrawLuoXuanJiang(x, y);
	x = m_YD.x + m_x * m_kx;
	y = m_YD.y + m_y * m_ky;
	y -= w;
	DrawLuoXuanJiang(x, y);
	y += 2 * w;
	DrawLuoXuanJiang(x, y);
}

void CWRJ::DrawLuoXuanJiang(int x0, int y0)
{
	int x, y, w = m_w * m_kx;

	int i;
	for (i = 0; i < 4; i++)
	{
		pDC->MoveTo(x0, y0);
		x = x0 + w / 2 * cos(m_JDlxj + 90 * i / 180.0 * PI);
		y = y0 + w / 2 * sin(m_JDlxj + 90 * i / 180.0 * PI);
		pDC->LineTo(x, y);
	}
}

void CWRJ::Move(UINT nChar)
{
	float deltat = 0.1;

	switch (nChar)
	{
	case 37:  //左
		m_x -= m_v * deltat;
		break;
	case 38:  //上
		m_y += m_v * deltat;
		break;
	case 39:  //右
		m_x += m_v * deltat;
		break;
	case 40:  //下
		m_y -= m_v * deltat;
		break;
	}

}

void CWRJ::LuoXuanJiangXuanZhuan()
{
	m_JDlxj += m_vJD * 0.1;
}
