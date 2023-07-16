// Control.cpp: implementation of the CControl class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Control_System.h"
#include "Control.h"

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

CControl::CControl()
{
	m_YD.x = 100;
	m_YD.y = 800;
	m_kx = 1920 / 1000;
	m_ky = -1080 / 1000;
	m_deltaT = 0.1;

	m_CarMB.w = 20;   //米
	m_CarKZX.w = 20;   //米
	m_CarKZV.w = 20;   //米
	m_CarKZA.w = 20;   //米

	m_mode = YunSu;
	m_bjCurveDraw = -1;
	

	initMove();

	m_CarKZX.kp = 1;
	m_CarKZV.kp = 7;
	m_CarKZA.kp = 0.5;

	m_CarKZX.ki = 0.1;
	m_CarKZV.ki = 5;
	m_CarKZA.ki = 0.2;

	m_CarKZX.kd = 0.001;
	m_CarKZV.kd = 0.01;
	m_CarKZA.kd = 10;

	m_CDXL = 1;
	
}

CControl::~CControl()
{

}

void CControl::initMove()
{
	m_CarKZX.jfx = 0;
	m_CarKZV.jfx = 0;
	m_CarKZA.jfx = 0;

	m_CarKZX.preerror = 0;
	m_CarKZV.preerror = 0;
	m_CarKZA.preerror = 0;


	m_CarMB.x = 0;
	m_CarMB.v = 100;
	m_CarMB.a = 100;
	m_CarMB.nxGJ = 0;
	m_CarMB.nvGJ = 0;
	m_CarMB.xGJ[m_CarMB.nxGJ] = m_CarMB.x;
	m_CarMB.nxGJ++;
	m_CarMB.vGJ[m_CarMB.nvGJ] = m_CarMB.x;
	m_CarMB.nvGJ++;

	m_CarKZX.x = 0;
	m_CarKZX.v = 0;
	m_CarKZX.nxGJ = 0;
	m_CarKZX.xGJ[m_CarKZX.nxGJ] = m_CarKZX.x;
	m_CarKZX.nxGJ++;

	m_CarKZV.x = 0;
	m_CarKZV.v = 0;
	m_CarKZV.nxGJ = 0;
	m_CarKZV.nvGJ = 0;
	m_CarKZV.xGJ[m_CarKZV.nxGJ] = m_CarKZV.x;
	m_CarKZV.nxGJ++;
	m_CarKZV.vGJ[m_CarKZV.nvGJ] = m_CarKZV.v;
	m_CarKZV.nvGJ++;

	m_CarKZA.x = 0;
	m_CarKZA.v = 0;
	m_CarKZA.a = 10;
	m_CarKZA.nxGJ = 0;
	m_CarKZA.nvGJ = 0;
	m_CarKZA.naGJ = 0;
	m_CarKZA.xGJ[m_CarKZA.nxGJ] = m_CarKZA.x;
	m_CarKZA.nxGJ++;
	m_CarKZA.vGJ[m_CarKZA.nvGJ] = m_CarKZA.v;
	m_CarKZA.nvGJ++;
	m_CarKZA.aGJ[m_CarKZA.naGJ] = m_CarKZA.a;
	m_CarKZA.naGJ++;

	m_t = - PI / 2;
}

void CControl::Draw(CDC *p)
{
	int x, y;
	CString str;

	pDC = p;

	x = 10;
	y = 10;
	str.Format("kp:    %.3f      %.3f      %.3f", m_CarKZX.kp, m_CarKZV.kp, m_CarKZA.kp);
	pDC->TextOut(x, y, str);
	y += 20;
	str.Format("ki:      %.3f      %.3f      %.3f", m_CarKZX.ki, m_CarKZV.ki, m_CarKZA.ki);
	pDC->TextOut(x, y, str);
	y += 20;
	str.Format("kd:    %.3f      %.3f      %.3f", m_CarKZX.kd, m_CarKZV.kd, m_CarKZA.kd);
	pDC->TextOut(x, y, str);

	DrawCar();

	DrawGJ();
}

void CControl::DrawCoordinateAxis(int X, int Y, float Max, float k, CString name)
{
	int x, y, i;
	CString str;

	x = m_YD.x + X;
	y = m_YD.y - Y - Max * k;
	pDC->MoveTo(x, y);
	y += 2 * Max * k;
	pDC->LineTo(x, y);
	y -= Max * k;
	pDC->MoveTo(x, y);
	x += 150 * 5;
	pDC->LineTo(x, y);

	for (i = 1; i <= 4; i++)
	{
		x = m_YD.x + X;
		y = m_YD.y - (Y + i * Max * k / 4);
		pDC->MoveTo(x, y);
		x += 10;
		pDC->LineTo(x, y);
		x -= 50;
		y -= 8;
		str.Format("%.0f", Max / 4 * i);
		pDC->TextOut(x, y, str);
	}
	for (i = 1; i <= 4; i++)
	{
		x = m_YD.x + X;
		y = m_YD.y - (Y - i * Max * k / 4);
		pDC->MoveTo(x, y);
		x += 10;
		pDC->LineTo(x, y);
		x -= 55;
		y -= 8;
		str.Format("%.0f", -Max / 4 * i);
		pDC->TextOut(x, y, str);
	}
	for (i = 1; i <= 15; i++)
	{
		x = m_YD.x + X + i * 50;
		y = m_YD.y - Y;
		pDC->MoveTo(x, y);
		y -= 10;
		pDC->LineTo(x, y);
		x -= 5;
		y += 15;
		str.Format("%d", i);
		pDC->TextOut(x, y, str);
	}
	x = m_YD.x + X - 30;
	y = m_YD.y - Y - 5;
	str.Format("0");
	pDC->TextOut(x, y, str);

	x = m_YD.x + X + 150 * 5 / 2;
	y = m_YD.y - Y + Max * k;
	pDC->TextOut(x, y, name);
}

void CControl::DrawCurve(int X, int Y, float arr[], int n, float k)
{
	int x, y, i;

	x = m_YD.x + X;
	y = m_YD.y - Y - arr[0] * k;
	pDC->MoveTo(x, y);
	for (i = 1; i < n; i++)
	{
		x = m_YD.x + X + 5 * i;
		y = m_YD.y - Y - arr[i] * k;
		pDC->LineTo(x, y);
	}
}

void CControl::DrawCar()
{
	int x, y, w, h, r;

	//目标小车
	CBrush b1;
	b1.CreateSolidBrush(RGB(0, 0, 0));
	pDC->SelectObject(&b1);
	x = m_YD.x + m_CarMB.x * m_kx;
	y = m_YD.y + 650 * m_ky;
	r = m_CarMB.w * m_kx / 2;
	pDC->Ellipse(x - r, y - r, x + r, y + r);

	//控制小车

	//位移
	CBrush b2;
	b2.CreateSolidBrush(RGB(255, 0, 0));
	pDC->SelectObject(&b2);
	w = m_CarKZX.w * m_kx;
	h = m_CarKZX.w * m_ky;
	x = m_YD.x + m_CarKZX.x * m_kx - w / 2;
	y = m_YD.y + 600 * m_ky;	
	pDC->Rectangle(x, y, x + w, y + h);

	//速度
	CBrush b3;
	b3.CreateSolidBrush(RGB(0, 255, 0));
	pDC->SelectObject(&b3);
	w = m_CarKZV.w * m_kx;
	h = m_CarKZV.w * m_ky;
	x = m_YD.x + m_CarKZV.x * m_kx - w / 2;
	y = m_YD.y + 550 * m_ky;	
	pDC->Rectangle(x, y, x + w, y + h);

	//加速度
	CBrush b4;
	b4.CreateSolidBrush(RGB(0, 0, 255));
	pDC->SelectObject(&b4);
	w = m_CarKZA.w * m_kx;
	h = m_CarKZA.w * m_ky;
	x = m_YD.x + m_CarKZA.x * m_kx - w / 2;
	y = m_YD.y + 500 * m_ky;	
	pDC->Rectangle(x, y, x + w, y + h);

}

void CControl::MoveMB()
{
	if (m_mode == YunSu)
	{
		m_CarMB.x += m_CarMB.v * m_deltaT;
	}
	if (m_mode == YunJiaSu)
	{
		m_CarMB.v += m_CarMB.a * m_deltaT;
		m_CarMB.x += m_CarMB.v * m_deltaT;
	}
	if (m_mode == ZhengXian)
	{
		float x0 = m_CarMB.x;
		m_CarMB.x = 250 * sin(m_t) + 250;
		m_CarMB.v = (m_CarMB.x - x0) / m_deltaT;
	}

	m_t += m_deltaT;

	if (m_CarMB.x > 500 || m_CarMB.x < 0)
	{
		m_CarMB.v *= -1;
		m_CarMB.a *= -1;
	}
	
	m_CarMB.xGJ[m_CarMB.nxGJ] = m_CarMB.x;
	m_CarMB.nxGJ++;
	m_CarMB.vGJ[m_CarMB.nvGJ] = m_CarMB.v;
	m_CarMB.nvGJ++;

	int i;
	if (m_CarMB.nxGJ > 150)
	{
		for (i = 0; i < m_CarMB.nxGJ - 1; i++)
			m_CarMB.xGJ[i] = m_CarMB.xGJ[i + 1];
		m_CarMB.nxGJ--;
	}
	if (m_CarMB.nvGJ > 150)
	{
		for (i = 0; i < m_CarMB.nvGJ - 1; i++)
			m_CarMB.vGJ[i] = m_CarMB.vGJ[i + 1];
		m_CarMB.nvGJ--;
	}
}

void CControl::MoveKZ()
{
	MoveKZ_X();
	MoveKZ_V();
	MoveKZ_A();
}

void CControl::MoveKZ_X()
{
	m_CarKZX.error = m_CarMB.x - m_CarKZX.x;
	m_CarKZX.jfx += m_CarKZX.error * m_deltaT;
	m_CarKZX.wfx = (m_CarKZX.error - m_CarKZX.preerror) / m_deltaT;
	m_CarKZX.preerror = m_CarKZX.error;

	m_CarKZX.x += m_CarKZX.kp * m_CarKZX.error + m_CarKZX.ki * m_CarKZX.jfx + m_CarKZX.kd * m_CarKZX.wfx;
	
	m_CarKZX.xGJ[m_CarKZX.nxGJ] = m_CarKZX.x;
	m_CarKZX.nxGJ++;
	
	int i;
	if (m_CarKZX.nxGJ > 150)
	{
		for (i = 0; i < m_CarKZX.nxGJ - 1; i++)
			m_CarKZX.xGJ[i] = m_CarKZX.xGJ[i + 1];
		m_CarKZX.nxGJ--;
	}
}

void CControl::MoveKZ_V()
{
	m_CarKZV.error = m_CarMB.x - m_CarKZV.x;
	m_CarKZV.jfx += m_CarKZV.error * m_deltaT;
	m_CarKZV.wfx = (m_CarKZV.error - m_CarKZV.preerror) / m_deltaT;
	m_CarKZV.preerror = m_CarKZV.error;

	m_CarKZV.v = 10 + m_CarKZV.kp * m_CarKZV.error + m_CarKZV.ki * m_CarKZV.jfx + m_CarKZV.kd * m_CarKZV.wfx;

	m_CarKZV.x += m_CarKZV.v * m_deltaT;

	m_CarKZV.xGJ[m_CarKZV.nxGJ] = m_CarKZV.x;
	m_CarKZV.nxGJ++;
	m_CarKZV.vGJ[m_CarKZV.nvGJ] = m_CarKZV.v;
	m_CarKZV.nvGJ++;

	int i;
	if (m_CarKZV.nxGJ > 150)
	{
		for (i = 0; i < m_CarKZV.nxGJ - 1; i++)
			m_CarKZV.xGJ[i] = m_CarKZV.xGJ[i + 1];
		m_CarKZV.nxGJ--;
	}
	if (m_CarKZV.nvGJ > 150)
	{
		for (i = 0; i < m_CarKZV.nvGJ - 1; i++)
			m_CarKZV.vGJ[i] = m_CarKZV.vGJ[i + 1];
		m_CarKZV.nvGJ--;
	}
}

void CControl::MoveKZ_A()
{
	m_CarKZA.error = m_CarMB.x - m_CarKZA.x;
	m_CarKZA.jfx += m_CarKZA.error * m_deltaT;
	m_CarKZA.wfx = (m_CarKZA.error - m_CarKZA.preerror) / m_deltaT;
	m_CarKZA.preerror = m_CarKZA.error;

	m_CarKZA.a = 10 + m_CarKZA.kp * m_CarKZA.error + m_CarKZA.ki * m_CarKZA.jfx + m_CarKZA.kd * m_CarKZA.wfx;

	m_CarKZA.v += m_CarKZA.a * m_deltaT;
	m_CarKZA.x += m_CarKZA.v * m_deltaT;

	m_CarKZA.xGJ[m_CarKZA.nxGJ] = m_CarKZA.x;
	m_CarKZA.nxGJ++;
	m_CarKZA.vGJ[m_CarKZA.nvGJ] = m_CarKZA.v;
	m_CarKZA.nvGJ++;
	m_CarKZA.aGJ[m_CarKZA.naGJ] = m_CarKZA.a;
	m_CarKZA.naGJ++;

	int i;
	if (m_CarKZA.nxGJ > 150)
	{
		for (i = 0; i < m_CarKZA.nxGJ - 1; i++)
			m_CarKZA.xGJ[i] = m_CarKZA.xGJ[i + 1];
		m_CarKZA.nxGJ--;
	}
	if (m_CarKZA.nvGJ > 150)
	{
		for (i = 0; i < m_CarKZA.nvGJ - 1; i++)
			m_CarKZA.vGJ[i] = m_CarKZA.vGJ[i + 1];
		m_CarKZA.nvGJ--;
	}
	if (m_CarKZA.naGJ > 150)
	{
		for (i = 0; i < m_CarKZA.naGJ - 1; i++)
			m_CarKZA.aGJ[i] = m_CarKZA.aGJ[i + 1];
		m_CarKZA.naGJ--;
	}
}

void CControl::DrawGJ()
{
	CPen p1;
	p1.CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	CPen p2;
	p2.CreatePen(PS_SOLID, 2, RGB(255, 0 ,0));
	CPen p3;
	p3.CreatePen(PS_SOLID, 2, RGB(0, 255 ,0));
	CPen p4;
	p4.CreatePen(PS_SOLID, 2, RGB(0, 0, 255));

	//坐标轴
	pDC->SelectObject(&p1);
	DrawCoordinateAxis(850, 600, 500, 0.35, "位移");
	DrawCoordinateAxis(850, 100, 500, 0.35, "速度");
	DrawCoordinateAxis(0, 100, 2000, 0.0875, "加速度");

	//目标小车
	DrawCurve(850, 600, m_CarMB.xGJ, m_CarMB.nxGJ, 0.35);  //位移
	DrawCurve(850, 100, m_CarMB.vGJ, m_CarMB.nvGJ, 0.35);  //速度

	if (m_bjCurveDraw == WeiYi)
	{
		pDC->SelectObject(&p2);
		DrawCurve(850, 600, m_CarKZX.xGJ, m_CarKZX.nxGJ, 0.35); //位移
	}
	else if (m_bjCurveDraw == SuDu)
	{
		pDC->SelectObject(&p3);
		DrawCurve(850, 600, m_CarKZV.xGJ, m_CarKZV.nvGJ, 0.35); //位移
		DrawCurve(850, 100, m_CarKZV.vGJ, m_CarKZV.nvGJ, 0.35); //速度
	}
	else if (m_bjCurveDraw == JiaSuDu)
	{
		pDC->SelectObject(&p4);
		DrawCurve(850, 600, m_CarKZA.xGJ, m_CarKZA.naGJ, 0.35); //位移
		DrawCurve(850, 100, m_CarKZA.vGJ, m_CarKZA.nvGJ, 0.35); //速度
		DrawCurve(0, 100, m_CarKZA.aGJ, m_CarKZA.naGJ, 0.0875);  //加速度
	}
	else
	{
		//控制位移小车
		pDC->SelectObject(&p2);
		DrawCurve(850, 600, m_CarKZX.xGJ, m_CarKZX.nxGJ, 0.35); //位移
		//控制速度小车
		pDC->SelectObject(&p3);
		DrawCurve(850, 600, m_CarKZV.xGJ, m_CarKZV.nvGJ, 0.35); //位移
		DrawCurve(850, 100, m_CarKZV.vGJ, m_CarKZV.nvGJ, 0.35); //速度
		//控制加速度小车
		pDC->SelectObject(&p4);
		DrawCurve(850, 600, m_CarKZA.xGJ, m_CarKZA.naGJ, 0.35); //位移
		DrawCurve(850, 100, m_CarKZA.vGJ, m_CarKZA.nvGJ, 0.35); //速度
		DrawCurve(0, 100, m_CarKZA.aGJ, m_CarKZA.naGJ, 0.0875);  //加速度
	}
}
