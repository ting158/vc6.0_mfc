// Ball.cpp: implementation of the CBall class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "pingpang_Sport.h"
#include "Ball.h"

#include "math.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CBall::CBall()
{
	m_k = 100;   //100像素 = 1米

	m_YD_CST.x = 200;
	m_YD_CST.y = 100;

	m_YD_FST.x = 1100;
	m_YD_FST.y = 100;

	m_L = 2.7;  // m
	m_W = 1.5;  // m
	m_H = 0.15; // m

	m_r = 0.05;  // m

	m_vx0 = 5;      // m/s 
	m_vy0 = 1;      // m/s
	m_vz0 = -1.5;   // m/s

	m_x0 = -0.2;
	m_y0 = 0;
	m_z0 = 0.3;

	initState();
}

CBall::~CBall()
{

}

void CBall::initState()
{
	m_x = m_x0;
	m_y = m_y0;
	m_z = m_z0;

	m_vx = m_vx0; 
	m_vy = m_vy0;
	m_vz = m_vz0;

	m_nxGJ = 0;
	m_nyGJ = 0;
	m_nzGJ = 0;
	m_nvxGJ = 0;
	m_nvyGJ = 0;
	m_nvzGJ = 0;

	m_xGJ[m_nxGJ] = m_x;
	m_nxGJ++;
	m_yGJ[m_nyGJ] = m_y;
	m_nyGJ++;
	m_zGJ[m_nzGJ] = m_z;
	m_nzGJ++;
	m_vxGJ[m_nxGJ] = m_vx;
	m_nvxGJ++;
	m_vyGJ[m_nxGJ] = m_vy;
	m_nvyGJ++;
	m_vzGJ[m_nxGJ] = m_vz;
	m_nvzGJ++;

}


void CBall::Draw(CDC *p)
{
	pDC = p;

	DrawCST();
	DrawFST();
	DrawXCurve();
	DrawVCurve();
}

void CBall::DrawCST()
{
	int x, y, r;

	//桌子
	x = m_YD_CST.x;
	y = m_YD_CST.y;
	pDC->MoveTo(x, y);
	x += m_L * m_k;
	pDC->LineTo(x, y);

	x = m_YD_CST.x + m_L / 2 * m_k;
	y = m_YD_CST.y;
	pDC->MoveTo(x, y);
	y -= m_H * m_k;
	pDC->LineTo(x, y);
	
	//球
	x = m_YD_CST.x + m_x * m_k;
	y = m_YD_CST.y - m_z * m_k;
	r = m_r * m_k;
	pDC->Ellipse(x - r, y - r, x + r, y + r);
}

void CBall::DrawFST()
{
	int x, y, w, h, r;

	//桌子
	x = m_YD_FST.x - m_W / 2 * m_k;
	y = m_YD_FST.y;
	w = m_W * m_k;
	h = m_L * m_k;
	pDC->Rectangle(x, y, x + w, y + h);
	x = m_YD_FST.x - m_W / 2 * m_k;
	y += m_L * m_k / 2;
	pDC->MoveTo(x, y);
	x += m_W * m_k;
	pDC->LineTo(x, y);

	//球
	x = m_YD_FST.x - m_y * m_k;
	y = m_YD_FST.y + m_x * m_k;
	r = m_r * m_k;
	pDC->Ellipse(x - r, y - r, x + r, y + r);
}


void CBall::DrawXCurve()
{
	int i;
	float x, y;
	float initX, initY;
	CString str;

	initX = m_YD_CST.x;
	initY = m_YD_CST.y + 200;
	x = initX;
	y = initY;
	pDC->MoveTo(initX, initY);
	x += 500;
	pDC->LineTo(x, y);
	x = initX;
	y = initY - 130;
	pDC->MoveTo(x, y);
	y += 260;
	pDC->LineTo(x, y);
	x = initX - 15;
	y = initY - 10;
	pDC->TextOut(x, y, "0");

	x = initX + 150;
	y = initY + 130;
	pDC->TextOut(x, y, "运动轨迹");

	for (i = 1; i <= 3; i++)
	{
		x = initX;
		y = initY - i * m_k / 3;
		pDC->MoveTo(x, y);
		x += 10;
		pDC->LineTo(x, y);
		x = initX - 15;
		y -= 10;
		str.Format("%d", i);
		pDC->TextOut(x, y, str);
	}
	for (i = 1; i <= 3; i++)
	{
		x = initX;
		y = initY + i * m_k / 3;
		pDC->MoveTo(x, y);
		x += 10;
		pDC->LineTo(x, y);
		x = initX - 20;
		y -= 10;
		str.Format("%d", -i);
		pDC->TextOut(x, y, str);	
	}
	for (i = 1; i <= 8; i++)
	{
		x = initX + i *  60;
		y = initY;
		pDC->MoveTo(x, y);
		y -= 10;
		pDC->LineTo(x, y);
		str.Format("%d", i);
		x -= 5;
		y += 16;
		pDC->TextOut(x, y, str);	
	}

	CPen cPen1;
	cPen1.CreatePen(PS_SOLID,1,RGB(255,0,0));
	pDC->SelectObject(&cPen1);
	pDC->MoveTo(initX, initY);
	for (i = 0; i < m_nxGJ; i++)
	{
		x = initX + i * 3;
		y = initY - m_xGJ[i] * m_k / 3;
		pDC->LineTo(x, y);
	}
	x = initX - 150;
	y = initY - 130;
	pDC->MoveTo(x, y);
	x += 20;
	pDC->LineTo(x, y);
	x += 15;
	y -= 10;
	pDC->TextOut(x, y, "x方向");

	CPen cPen2;
	cPen2.CreatePen(PS_SOLID,1,RGB(0,255,0));
	pDC->SelectObject(&cPen2);
	pDC->MoveTo(initX, initY);
	for (i = 0; i < m_nyGJ; i++)
	{
		x = initX + i * 3;
		y = initY - m_yGJ[i] * m_k / 3;
		pDC->LineTo(x, y);
	}
	x = initX - 150;
	y = initY - 90;
	pDC->MoveTo(x, y);
	x += 20;
	pDC->LineTo(x, y);
	x += 15;
	y -= 10;
	pDC->TextOut(x, y, "y方向");

	CPen cPen3;
	cPen3.CreatePen(PS_SOLID,1,RGB(0,0,0));
	pDC->SelectObject(&cPen3);
	pDC->MoveTo(initX, initY);
	for (i = 0; i < m_nzGJ; i++)
	{
		x = initX + i * 3;
		y = initY - m_zGJ[i] * m_k / 3;
		pDC->LineTo(x, y);
	}
	x = initX - 150;
	y = initY - 50;
	pDC->MoveTo(x, y);
	x += 20;
	pDC->LineTo(x, y);
	x += 15;
	y -= 10;
	pDC->TextOut(x, y, "z方向");
}

void CBall::DrawVCurve()
{
	int i;
	float x, y;
	float initX, initY;
	CString str;


	initX = m_YD_CST.x;
	initY = m_YD_CST.y + 550;
	x = initX;
	y = initY;
	pDC->MoveTo(initX, initY);
	x += 500;
	pDC->LineTo(x, y);
	x = initX;
	y = initY - 150;
	pDC->MoveTo(x, y);
	y += 300;
	pDC->LineTo(x, y);
	x = initX - 15;
	y = initY - 10;
	pDC->TextOut(x, y, "0");
	x = initX + 150;
	y = initY + 130;
	pDC->TextOut(x, y, "速度轨迹");

	for (i = 1; i <= 2; i++)
	{
		x = initX;
		y = initY - i * 5 * m_k / 8;
		pDC->MoveTo(x, y);
		x += 10;
		pDC->LineTo(x, y);
		x = initX - 25;
		y -= 10;
		str.Format("%d", i * 5);
		pDC->TextOut(x, y, str);
	}
	for (i = 1; i <= 2; i++)
	{
		x = initX;
		y = initY + i * 5 * m_k / 8;
		pDC->MoveTo(x, y);
		x += 10;
		pDC->LineTo(x, y);
		x = initX - 30;
		y -= 10;
		str.Format("%d", -i * 5);
		pDC->TextOut(x, y, str);		
	}
	for (i = 1; i <= 8; i++)
	{
		x = initX + i *  60;
		y = initY;
		pDC->MoveTo(x, y);
		y -= 10;
		pDC->LineTo(x, y);
		str.Format("%d", i);
		x -= 5;
		y += 16;
		pDC->TextOut(x, y, str);	
	}

	CPen cPen1;
	cPen1.CreatePen(PS_SOLID,1,RGB(255,0,0));
	pDC->SelectObject(&cPen1);
	x = initX;
	y = initY;
	pDC->MoveTo(x, y);
	for (i = 0; i < m_nvxGJ; i++)
	{
		x = initX + i * 3;
		y = initY - m_vxGJ[i] * m_k / 8;
		pDC->LineTo(x, y);
	}

	CPen cPen2;
	cPen2.CreatePen(PS_SOLID,1,RGB(0,255,0));
	pDC->SelectObject(&cPen2);
	x = initX;
	y = initY;
	pDC->MoveTo(x, y);
	for (i = 0; i < m_nvyGJ; i++)
	{
		x = initX + i * 3;
		y = initY - m_vyGJ[i] * m_k / 8;
		pDC->LineTo(x, y);
	}

	CPen cPen3;
	cPen3.CreatePen(PS_SOLID,1,RGB(0,0,0));
	pDC->SelectObject(&cPen3);
	x = initX;
	y = initY;
	pDC->MoveTo(x, y);
	for (i = 0; i < m_nvzGJ; i++)
	{
		x = initX + i * 3;
		y = initY - m_vzGJ[i] * m_k / 8;
		pDC->LineTo(x, y);
	}
}

void CBall::Move()
{
	float t = 0.01;

	if (m_z - m_r <= 0)  //碰到桌面反弹
		m_vz = fabs(m_vz);
	m_vz += -9.8 * t;

	if (m_z - m_r <= m_H && m_z + m_r <= 0 && m_x - m_r <= m_L / 2 && m_x + m_r >= m_L / 2) //碰到球网反弹
		m_vx = -m_vx;

	m_x += m_vx * t;
	m_y += m_vy * t;
	m_z += m_vz * t;



	//保存数据
	m_xGJ[m_nxGJ] = m_x;
	m_nxGJ++;
	m_yGJ[m_nyGJ] = m_y;
	m_nyGJ++;
	m_zGJ[m_nzGJ] = m_z;
	m_nzGJ++;
	m_vxGJ[m_nxGJ] = m_vx;
	m_nvxGJ++;
	m_vyGJ[m_nxGJ] = m_vy;
	m_nvyGJ++;
	m_vzGJ[m_nxGJ] = m_vz;
	m_nvzGJ++;

}


