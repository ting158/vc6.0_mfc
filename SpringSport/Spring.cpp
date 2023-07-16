// Spring.cpp: implementation of the CSpring class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SpringSport.h"
#include "Spring.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSpring::CSpring()
{
	m_ZH = 200;

	m_Point.x = 200;
	m_Point.y = 100;
	m_LUp = 0.25;
	m_LDown = 0.14;
	m_L0 = 0.1;
	m_k = 10;
	m_zn = 0.9;
	m_w = 0.25;
	m_m = 0.8;
	m_r = 0.05;
	m_v = 1;
	m_y = 0;
	m_L = 0.5;
	m_nvGJ = 0;
	m_naGJ = 0;
	m_nfGJ = 0;
	m_nyGJ = 0;
}

CSpring::~CSpring()
{

}

void CSpring::initSport()
{
	m_y = 0;

	m_L = 0.5;
	m_nvGJ = 0;
	m_naGJ = 0;
	m_nfGJ = 0;
	m_nyGJ = 0;
}

void CSpring::Draw(CDC *p)
{
	pDC = p;

	DrawSpring();
//	DrawYQuXian();
//	DrawVQuXian();
//	DrawAQuXian();
//	DrawFQuXian();

	DrawQuXian(500, 125, m_yGJ, m_nyGJ, "位移变化曲线", 0.015, 15);
	DrawQuXian(900, 125, m_vGJ, m_nvGJ, "速度变化曲线", 0.15, 20);
	DrawQuXian(500, 425, m_aGJ, m_naGJ, "加速度变化曲线", 7, 15);
	DrawQuXian(900, 425, m_fGJ, m_nfGJ, "受力变化曲线", 3.5, 15);
}

void CSpring::DrawQuXian(int initX, int initY, float gj[], int ngj, CString str, float max, float p)
{
	int i, k = 0;


	pDC->MoveTo(initX, initY);
	pDC->LineTo(initX + 300, initY);
	pDC->MoveTo(initX, initY);
	pDC->LineTo(initX, initY - 75);
	pDC->MoveTo(initX, initY);
	pDC->LineTo(initX, initY + 75);
	pDC->TextOut(initX + 100, initY + 75 + 10, str);
	pDC->TextOut(initX - 15, initY - 8, "0");

	for (i = 0; i < 3; i++)
	{
		k += 20;
		pDC->MoveTo(initX, initY + k);
		pDC->LineTo(initX + 5, initY + k);
	}
	k = 0;
	for (i = 0; i < 3; i++)
	{
		k += 20;
		pDC->MoveTo(initX, initY - k);
		pDC->LineTo(initX + 5, initY - k);
	}
	k = 0;
	for (i = 0; i < 10; i++)
	{
		k += 20;
		pDC->MoveTo(initX + k, initY);
		pDC->LineTo(initX + k, initY - 5);
	}
	k = 0;
	for (i = 1; i < 4; i++)
	{
		k += 20;
		CString str;
		str.Format("%.3f", -max / 3 * i);
		pDC->TextOut(initX - 50, initY  + k - 10, str);
	
	}
	k = 0;
	for (i = 1; i < 4; i++)
	{
		k += 20;
		CString str;
		str.Format("%.3f", max / 3 * i);
		pDC->TextOut(initX - 45, initY  - k - 10, str);
	
	}
	k = 0;
	for (i = 1; i < 4; i++)
	{
		k += 50;
		CString str;
		str.Format("%d", i * 10);
		pDC->TextOut(initX + k, initY + 5, str);
	
	}

	//曲线
	int x = initX;
	int y = initY + gj[0];
	
	pDC->MoveTo(x, y);
	for (i = 1; i < ngj; i++)
	{
		x += 2;
		if (ngj == m_nyGJ)
			y = initY + gj[i] * p;
		if (ngj == m_nvGJ)
			y = initY + m_vGJ[i] * p;
		if (ngj == m_naGJ)
			y = initY + m_aGJ[i] * p;
		if (ngj == m_nfGJ)
			y = initY + m_fGJ[i] * p;
		
		pDC->LineTo(x, y);
	}
}

//画弹簧和小球
void CSpring::DrawSpring()
{
	float x, y, w, h, r;

	x = m_Point.x - 50;
	y = m_Point.y;
	pDC->MoveTo(x, y);
	x = m_Point.x + 50;
	y = m_Point.y;
	pDC->LineTo(x, y);
	pDC->MoveTo(m_Point);
	x = m_Point.x;
	y += m_LUp * m_ZH;
	pDC->LineTo(x, y);

	w = m_w * m_ZH;
	h = m_L * m_ZH;
	x -= w / 2;
	pDC->Rectangle(x, y, x + w, y + h);

	x = m_Point.x;
	y += m_L * m_ZH;
	pDC->MoveTo(x, y);
	y += m_LDown * m_ZH;
	pDC->LineTo(x, y);
	y += m_r * m_ZH;
	r = m_r * m_ZH;
	pDC->Ellipse(x - r, y - r, x + r, y + r);
	
}

void CSpring::DrawYQuXian()
{
	int i, k = 0;;

	//坐标
	int initX = 500;
	int initY = 125;

	pDC->MoveTo(initX, initY);
	pDC->LineTo(initX + 300, initY);
	pDC->MoveTo(initX, initY);
	pDC->LineTo(initX, initY - 75);
	pDC->MoveTo(initX, initY);
	pDC->LineTo(initX, initY + 75);
	pDC->TextOut(initX + 100, initY + 75 + 10, "位移变化曲线");

	pDC->TextOut(initX - 15, initY - 8, "0");
	for (i = 0; i < 3; i++)
	{
		k += 20;
		pDC->MoveTo(initX, initY + k);
		pDC->LineTo(initX + 5, initY + k);
	}
	k = 0;
	for (i = 0; i < 3; i++)
	{
		k += 20;
		pDC->MoveTo(initX, initY - k);
		pDC->LineTo(initX + 5, initY - k);
	}
	k = 0;
	for (i = 0; i < 10; i++)
	{
		k += 20;
		pDC->MoveTo(initX + k, initY);
		pDC->LineTo(initX + k, initY - 5);
	}
	k = 0;
	for (i = 1; i < 4; i++)
	{
		k += 20;
		CString str;
		str.Format("%.3f", -(float)i / 200);
		pDC->TextOut(initX - 50, initY  + k - 10, str);
	
	}
	k = 0;
	for (i = 1; i < 4; i++)
	{
		k += 20;
		CString str;
		str.Format("%.3f", (float)i / 200);
		pDC->TextOut(initX - 45, initY  - k - 10, str);
	
	}
	k = 0;
	for (i = 1; i < 4; i++)
	{
		k += 50;
		CString str;
		str.Format("%d", i * 10);
		pDC->TextOut(initX + k, initY + 5, str);
	
	}


	//曲线
	int x = initX;
	int y = initY + m_yGJ[0];
	
	pDC->MoveTo(x, y);
	for (i = 1; i < m_nyGJ; i++)
	{
		x += 2;
		y = initY + m_yGJ[i] * 200 * 2;
		pDC->LineTo(x, y);
	}

}

void CSpring::DrawVQuXian()
{
	int i, k = 0;

	//坐标
	int initX = 900;
	int initY = 125;

	pDC->MoveTo(initX, initY);
	pDC->LineTo(initX + 300, initY);
	pDC->MoveTo(initX, initY);
	pDC->LineTo(initX, initY - 75);
	pDC->MoveTo(initX, initY);
	pDC->LineTo(initX, initY + 75);
	pDC->TextOut(initX + 100, initY + 75 + 10, "速度变化曲线");

	pDC->TextOut(initX - 15, initY - 8, "0");
	for (i = 0; i < 3; i++)
	{
		k += 20;
		pDC->MoveTo(initX, initY + k);
		pDC->LineTo(initX + 5, initY + k);
	}
	k = 0;
	for (i = 0; i < 3; i++)
	{
		k += 20;
		pDC->MoveTo(initX, initY - k);
		pDC->LineTo(initX + 5, initY - k);
	}
	k = 0;
	for (i = 0; i < 10; i++)
	{
		k += 20;
		pDC->MoveTo(initX + k, initY);
		pDC->LineTo(initX + k, initY - 5);
	}
	k = 0;
	for (i = 1; i < 4; i++)
	{
		k += 20;
		CString str;
		str.Format("%.2f", -(float)i / 20);
		pDC->TextOut(initX - 40, initY  + k - 10, str);
	
	}
	k = 0;
	for (i = 1; i < 4; i++)
	{
		k += 20;
		CString str;
		str.Format("%.2f", (float)i / 20);
		pDC->TextOut(initX - 35, initY  - k - 10, str);
	
	}
	k = 0;
	for (i = 1; i < 4; i++)
	{
		k += 50;
		CString str;
		str.Format("%d", i * 10);
		pDC->TextOut(initX + k, initY + 5, str);
	
	}

	//曲线
	int x = initX;
	int y = initY + m_vGJ[0];
	
	pDC->MoveTo(x, y);
	for (i = 1; i < m_nvGJ; i++)
	{
		x += 2;
		y = initY + m_vGJ[i] * 50;
		pDC->LineTo(x, y);
	}
}

void CSpring::DrawAQuXian()
{
	int i, k = 0;

	//坐标
	int initX = 500;
	int initY = 425;

	pDC->MoveTo(initX, initY);
	pDC->LineTo(initX + 300, initY);
	pDC->MoveTo(initX, initY);
	pDC->LineTo(initX, initY - 150);
	pDC->MoveTo(initX, initY);
	pDC->LineTo(initX, initY + 150);
	pDC->TextOut(initX + 100, initY + 150 + 10, "加速度变化曲线");

	pDC->TextOut(initX - 15, initY - 8, "0");
	for (i = 0; i < 7; i++)
	{
		k += 20;
		pDC->MoveTo(initX, initY + k);
		pDC->LineTo(initX + 5, initY + k);
	}
	k = 0;
	for (i = 0; i < 7; i++)
	{
		k += 20;
		pDC->MoveTo(initX, initY - k);
		pDC->LineTo(initX + 5, initY - k);
	}
	k = 0;
	for (i = 0; i < 10; i++)
	{
		k += 20;
		pDC->MoveTo(initX + k, initY);
		pDC->LineTo(initX + k, initY - 5);
	}
	k = 0;
	for (i = 1; i < 8; i++)
	{
		k += 20;
		CString str;
		str.Format("%d", -i);
		pDC->TextOut(initX - 20, initY  + k - 10, str);
	
	}
	k = 0;
	for (i = 1; i < 8; i++)
	{
		k += 20;
		CString str;
		str.Format("%d", i);
		pDC->TextOut(initX - 15, initY  - k - 10, str);
	
	}
	k = 0;
	for (i = 1; i < 4; i++)
	{
		k += 50;
		CString str;
		str.Format("%d", i * 10);
		pDC->TextOut(initX + k, initY + 5, str);
	
	}

	//曲线
	int x = initX;
	int y = initY + m_aGJ[0];
	
	pDC->MoveTo(x, y);
	for (i = 1; i < m_naGJ; i++)
	{
		x += 2;
		y = initY + m_aGJ[i] * 25;
		pDC->LineTo(x, y);
	}
}

void CSpring::DrawFQuXian()
{
	int i, k = 0;

	//坐标
	int initX = 900;
	int initY = 425;

	pDC->MoveTo(initX, initY);
	pDC->LineTo(initX + 300, initY);
	pDC->MoveTo(initX, initY);
	pDC->LineTo(initX, initY - 150);
	pDC->MoveTo(initX, initY);
	pDC->LineTo(initX, initY + 150);
	pDC->TextOut(initX + 100, initY + 150 + 10, "受力变化曲线");

	pDC->TextOut(initX - 15, initY - 8, "0");
	for (i = 0; i < 7; i++)
	{
		k += 20;
		pDC->MoveTo(initX, initY + k);
		pDC->LineTo(initX + 5, initY + k);
	}
	k = 0;
	for (i = 0; i < 7; i++)
	{
		k += 20;
		pDC->MoveTo(initX, initY - k);
		pDC->LineTo(initX + 5, initY - k);
	}
	k = 0;
	for (i = 0; i < 10; i++)
	{
		k += 20;
		pDC->MoveTo(initX + k, initY);
		pDC->LineTo(initX + k, initY - 5);
	}
	k = 0;
	for (i = 1; i < 8; i++)
	{
		k += 20;
		CString str;
		str.Format("%.1f", -(float)i / 2);
		pDC->TextOut(initX - 40, initY  + k - 10, str);
	
	}
	k = 0;
	for (i = 1; i < 8; i++)
	{
		k += 20;
		CString str;
		str.Format("%.1f", (float)i / 2);
		pDC->TextOut(initX - 35, initY  - k - 10, str);
	
	}
	k = 0;
	for (i = 1; i < 4; i++)
	{
		k += 50;
		CString str;
		str.Format("%d", i * 10);
		pDC->TextOut(initX + k, initY + 5, str);
	
	}

	//曲线
	int x = initX;
	int y = initY + m_fGJ[0];
	
	pDC->MoveTo(x, y);
	for (i = 1; i < m_nfGJ; i++)
	{
		x += 2;
		y = initY + m_fGJ[i] * 35;
		pDC->LineTo(x, y);
	}
}

void CSpring::Move()
{
	m_f = m_m * 9.8 - m_k * (m_L - m_L0);
	m_a = m_f / m_m;
	m_y = m_v * 0.1 + 0.5 * m_a * 0.1 * 0.1;
	m_L += m_y;
	m_v += m_a * 0.1;
	m_v *= m_zn;



	//保存数据
	m_vGJ[m_nvGJ] = m_v;
	m_nvGJ++;
	m_aGJ[m_naGJ] = m_a;
	m_naGJ++;
	m_fGJ[m_nfGJ] = m_f;
	m_nfGJ++;
	m_yGJ[m_nyGJ] = m_y;
	m_nyGJ++;
}




