// SinCos.cpp: implementation of the CSinCos class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SinCosMove.h"
#include "SinCos.h"

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

CSinCos::CSinCos()
{
	m_Center.x = 200;  //ÏñËØ
	m_Center.y = 200;  //ÏñËØ
	m_R = 1;  //m

	m_ZH = 50;   //1m = 50ÏñËØ

	m_Angle = 0;  // rad
	m_vAngle = 72 / 180.0 * PI;  // rad/s

	initCurve();

	m_Origin.x = 500;  //ÏñËØ
	m_Origin.y = 150;  //ÏñËØ
}

CSinCos::~CSinCos()
{

}

void CSinCos::initCurve()
{
	m_x = m_R * cos(m_Angle);
	m_y = m_R * sin(m_Angle);

	m_nxGJ = 0;
	m_nyGJ = 0;
	m_nvxGJ = 0;
	m_nvyGJ = 0;
	m_naxGJ = 0;
	m_nayGJ = 0;

	m_xGJ[m_nxGJ] = m_x;
	m_yGJ[m_nyGJ] = m_y;
	m_nxGJ++;
	m_nyGJ++;
}

void CSinCos::Draw(CDC *p)
{
	pDC = p;

	DrawBackground();
	DrawSin();
	DrawCos();

	DrawCurve(100, 450, m_vxGJ, m_nvxGJ, "vx");
	DrawCurve(600, 450, m_vyGJ, m_nvyGJ, "vy");
	DrawCurve(100, 750, m_axGJ, m_naxGJ, "ax");
	DrawCurve(600, 750, m_ayGJ, m_nayGJ, "ay");
}

void CSinCos::DrawBackground()
{
	float x, y, r;
    
	//Ô²
	x = m_Center.x;
	y = m_Center.y;
	r = m_R * m_ZH;
	pDC->Ellipse(x - r, y - r, x + r, y + r);

	//ÉÏºáÏß
	x = m_Center.x - m_R * m_ZH;
	y = m_Center.y - m_R * 1.5 * m_ZH;
	pDC->MoveTo(x, y);
	x += m_R * m_ZH * 2;
	pDC->LineTo(x, y);

	//×óÊúÏß
	x = m_Center.x - m_R * 1.5 * m_ZH;
	y = m_Center.y - m_R * m_ZH;
	pDC->MoveTo(x, y);
	y += m_R * m_ZH * 2;
	pDC->LineTo(x, y);

	//°ë¾¶
	pDC->MoveTo(m_Center);
	x = m_Center.x - m_x * m_ZH;
	y = m_Center.y - m_y * m_ZH;
	pDC->LineTo(x, y);

	x = m_Center.x - m_R * 1.5 * m_ZH;
	pDC->LineTo(x, y);

	x = m_Center.x - m_x * m_ZH;
	y = m_Center.y - m_y * m_ZH;
	pDC->MoveTo(x ,y);
	y = m_Center.y - m_R * 1.5 * m_ZH;
	pDC->LineTo(x, y);

	//×ø±êÖá
	pDC->MoveTo(m_Origin);
	x = m_Origin.x;
	y = m_Origin.y - 50 * 2.5;
	pDC->LineTo(x, y);
	y = m_Origin.y + 50 * 2.5;
	pDC->LineTo(x, y);
	pDC->MoveTo(m_Origin);
	x = m_Origin.x + 500;
	y = m_Origin.y;
	pDC->LineTo(x, y);

	//¿Ì¶È
	int i;
	CString str;
	
	x = m_Origin.x - 15;
	y = m_Origin.y - 10;
	pDC->TextOut(x, y, "0");

	for (i = 1; i <= 2; i++)
	{
		x = m_Origin.x;
		y = m_Origin.y - 50 * i;
		pDC->MoveTo(x, y);
		x += 8;
		pDC->LineTo(x, y);

		x = m_Origin.x - 15;
		y -= 10;
		str.Format("%d", i);
		pDC->TextOut(x, y, str);
	}
	for (i = 1; i <= 2; i++)
	{
		x = m_Origin.x;
		y = m_Origin.y + 50 * i;
		pDC->MoveTo(x, y);
		x += 8;
		pDC->LineTo(x, y);

		x = m_Origin.x - 20;
		y -= 10;
		str.Format("%d", -i);
		pDC->TextOut(x, y, str);
	}
	for (i = 1; i <= 8; i++)
	{
		x = m_Origin.x + 60 * i;  //60ÏñËØÎª1Ãë
		y = m_Origin.y;
		pDC->MoveTo(x, y);
		y -= 8;
		pDC->LineTo(x, y);

		x -= 4;
		y += 8 + 3;
		str.Format("%d", i);
		pDC->TextOut(x, y, str);
	}
}

void CSinCos::DrawSin()
{
	int i, x, y;

	x = m_Center.x - m_R * 1.5 * m_ZH - 3 * (m_nyGJ - 1);
	y = m_Center.y - m_yGJ[0] * m_ZH;
	pDC->MoveTo(x, y);
	for (i = 1; i < m_nyGJ; i++)
	{
		x += 3;
		y = m_Center.y - m_yGJ[i] * m_ZH;
		pDC->LineTo(x, y);
	}

	//ÔÚÍ¼ÏñÖÐ»­
	x = m_Origin.x;
	y = m_Origin.y - m_yGJ[0] * m_ZH;
	pDC->MoveTo(x, y);
	for (i = 0; i < m_nyGJ && i < 80; i++)
	{
		x = m_Origin.x + 6 * i;
		y = m_Origin.y - m_yGJ[i] * m_ZH;
		pDC->LineTo(x, y);
	}
}

void CSinCos::DrawCos()
{
	int i, x, y;

	x = m_Center.x - m_xGJ[0] * m_ZH;
	y = m_Center.y - m_R * 1.5 * m_ZH - 3 * (m_nxGJ - 1);
	pDC->MoveTo(x, y);
	for (i = 1; i < m_nyGJ; i++)
	{
		y += 3;
		x = m_Center.x - m_xGJ[i] * m_ZH;
		pDC->LineTo(x, y);
	}

	//ÔÚÍ¼ÏñÖÐ»­
	x = m_Origin.x;
	y = m_Origin.y - m_xGJ[0] * m_ZH;
	pDC->MoveTo(x, y);
	for (i = 1; i < m_nxGJ && i < 80; i++)
	{
		x = m_Origin.x + 6 * i;
		y = m_Origin.y - m_xGJ[i] * m_ZH;
		pDC->LineTo(x, y);
	}
}

void CSinCos::Move()
{
	float t = 0.1;

	m_Angle += m_vAngle * t;

	m_x = m_R * cos(m_Angle);
	m_y = m_R * sin(m_Angle);

	m_xGJ[m_nxGJ] = m_x;
	m_nxGJ++;
	m_yGJ[m_nyGJ] = m_y;
	m_nyGJ++;

	m_vxGJ[m_nvxGJ] = (m_xGJ[m_nxGJ - 1] - m_xGJ[m_nxGJ - 2]) / t;
	m_nvxGJ++;

	m_vyGJ[m_nvyGJ] = (m_yGJ[m_nyGJ - 1] - m_yGJ[m_nyGJ - 2]) / t;
	m_nvyGJ++;

	if (m_nvxGJ >= 2)
	{
		m_axGJ[m_naxGJ] = (m_vxGJ[m_nvxGJ - 1] - m_vxGJ[m_nvxGJ - 2]) / t;
		m_naxGJ++;
	}

	if (m_nvyGJ >= 2)
	{
		m_ayGJ[m_nayGJ] = (m_vyGJ[m_nvyGJ - 1] - m_vyGJ[m_nvyGJ - 2]) / t;
		m_nayGJ++;
	}

}

void CSinCos::DrawCurve(int X, int Y, float arr[], int n, CString str)
{
	float x, y;
	int i;

	x = X;
	y = Y - 100;
	pDC->MoveTo(x, y);
	y += 200;
	pDC->LineTo(x, y);

	x = X;
	y = Y;;
	pDC->MoveTo(x, y);
	x += 400;
	pDC->LineTo(x, y);

	x -= 210;
	y += 110;
	pDC->TextOut(x, y, str);

	str.Format("%d", 0);
	x = X - 15;
	y = Y - 8;
	pDC->TextOut(x, y, str);

	x = X;
	y = Y - 1 * m_ZH;
	pDC->MoveTo(x, y);
	x += 10;
	pDC->LineTo(x, y);
	x -= 25;
	y -= 8;
	str.Format("1");
	pDC->TextOut(x, y, str);

	x = X;
	y = Y + 1 * m_ZH;
	pDC->MoveTo(x, y);
	x += 10;
	pDC->LineTo(x, y);
	x -= 30;
	y -= 8;
	str.Format("-1");
	pDC->TextOut(x, y, str);

	for (i = 1; i <= 13; i++)
	{
		x = X + 30 * i;
		y = Y;
		pDC->MoveTo(x, y);
		y -= 10;
		pDC->LineTo(x, y);
		x -= 5;
		y += 15;
		str.Format("%d", i);
		pDC->TextOut(x, y, str);
	}

	x = X;
	y = Y - arr[0];
	pDC->MoveTo(x, y);
	for (i = 0; i < n && i < 130; i++)
	{
		x = X + 3 * i;
		y = Y - arr[i] * m_ZH;
		pDC->LineTo(x, y);
	}
}
