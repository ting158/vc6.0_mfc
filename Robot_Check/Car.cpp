// Car.cpp: implementation of the CCar class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Robot_Check.h"
#include "Car.h"

#include "math.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

#define PI 3.1415926

CCar::CCar()
{
	m_kx = 1920 / 1000.0;
	m_ky = -1080 / 1000.0;
	m_YD.x = 700;
	m_YD.y = 800;

	m_nd = 0;

	m_x = 0;
	m_y = 0;
	

	m_MBx = 0;
	m_MBy = 0;
	m_v = 80;
	m_w = 10;
	m_mode = ShunYi;
	m_sn = -1;
	m_dir = 0;
	m_r = 50;
	m_vJD = 50;

	m_nGJ = 0;
	m_bjCreate = 0;

	m_nd_max = 0;


	m_ndCir.jd = 0;
	m_ndCir.r = 50;
	m_ndCir.omg = 100;
}

CCar::~CCar()
{

}

void CCar::Draw(CDC *p)
{
	pDC = p;

	//显示浓度
	int x, y;
	CString str;
	str.Format("小车附近浓度：%d", m_nd);
	x = 1600;
	y = 10;
	pDC->TextOut(x, y, str);


//	DrawNDMaxMin();
	DrawCar();
	DrawLuJing();
}

void CCar::DrawCar()
{
	int x, y, r, w, h;
	CBrush   Brush;     
	Brush.CreateSolidBrush(RGB(64, 224, 208));     
	pDC->SelectObject(&Brush);     

	x = m_YD.x + m_x * m_kx;
	y = m_YD.y + m_y * m_ky;
	r = m_w / 3 * m_kx;
	pDC->Ellipse(x - r, y - r, x + r, y + r);

	x = x - r - m_w * m_kx + 2;
	y = y - r;
	w = m_w * m_kx;
	h = r * 2;
	pDC->Rectangle(x, y, x + w, y + h);

	pDC->EndPath();        
	pDC->FillPath();
}

void CCar::DrawLuJing()
{
	int i, x, y;

	x = m_YD.x + m_GJ[0][0] * m_kx;
	y = m_YD.y + m_GJ[0][1] * m_ky;
	pDC->MoveTo(x, y);
	for (i = 1; i < m_nGJ; i++)
	{
		x = m_YD.x + m_GJ[i][0] * m_kx;
		y = m_YD.y + m_GJ[i][1] * m_ky;
		pDC->LineTo(x, y);
	}
}

void CCar::Move()
{
	if (m_mode == YunSu)
		MoveYunSuDaoMuBiaoDian();
	if (m_mode == ZhuanQuan)
		MoveZhuanQuan();
	if (m_mode == LuJing)
		MoveGuiJi();
	if (m_mode == FindXieLou)
		//MoveFindXieLouDian();
		MoveZhuanQuanChaZhaoXieLouDian();
}

void CCar::MoveDianNaDaoNa()
{
	m_x = m_MBx;
	m_y = m_MBy;
}

void CCar::MoveYunSuDaoMuBiaoDian()
{
	float deltat = 0.1;

	m_d = sqrt((m_MBx - m_x) * (m_MBx - m_x) + (m_MBy - m_y) * (m_MBy - m_y));
	m_vx = m_v * (m_MBx - m_x) / m_d;
	m_vy = m_v * (m_MBy - m_y) / m_d;

	if (m_d > 5)
	{
		m_x += m_vx * deltat;
		m_y += m_vy * deltat;
	}
}

void CCar::MoveZhuanQuan()
{
	float deltat = 0.1;

	m_x = m_YXx + m_r * cos(m_JD / 180 * PI);
	m_y = m_YXy + m_r * sin(m_JD / 180 * PI);
	m_JD += m_vJD * m_sn * deltat;
}

void CCar::ZhuanHuaMuBiaoDian(CPoint p)
{
	m_MBx = (p.x - m_YD.x) / m_kx;
	m_MBy = (p.y - m_YD.y) / m_ky;

	if (m_mode == ShunYi)
		MoveDianNaDaoNa();
}

void CCar::ChuLiYuanXinCanShu()
{
	m_JD = (12 + 3 - m_dir) * 30;
	m_YXx = m_x - m_r * cos((180 - m_JD) / 180 * PI);
	m_YXy = m_y - m_r * sin((180 - m_JD) / 180 * PI);

	m_initJD = m_JD;
}

void CCar::MoveGuiJi()
{
	m_MBx = m_GJ[m_nowMB][0];
	m_MBy = m_GJ[m_nowMB][1];

	MoveYunSuDaoMuBiaoDian();

	if (m_d <= 5 && m_nowMB < m_nGJ)
		m_nowMB++;
}

void CCar::ChuLiGuiJiZuoBiao(CPoint p)
{
	ZhuanHuaMuBiaoDian(p);

	m_GJ[m_nGJ][0] = m_MBx;
	m_GJ[m_nGJ][1] = m_MBy;
	m_nGJ++;

	if (m_mode == LuJing && m_nGJ == 1)
	{
		m_x = m_GJ[0][0];
		m_y = m_GJ[0][1];
	}
}

int CCar::isOverLuJing()
{
	if (m_nowMB > m_nGJ - 1)
	{
		m_nowMB = 1;
		m_nGJ = 0;
		return 1;
	}	
	else
	{
		return 0;
	}	
}

//转圈，记录最大的浓度点，然后匀速运动到这个点，再转圈匀速。。。
void CCar::MoveFindXieLouDian()
{
	if (fabs(m_JD - m_initJD) < 360)
	{
		if (m_JD == m_initJD)
		{
			ChuLiYuanXinCanShu();
		}
		m_r *= 1.01;

		MoveZhuanQuan();

		if (m_nd_max < m_nd)
		{
			m_nd_max = m_nd;
			m_x_max = m_x;
			m_y_max = m_y;
		}
	}
	else
	{
		m_MBx = m_x_max;
		m_MBy = m_y_max;
		MoveYunSuDaoMuBiaoDian();

		if (m_d < 5)
		{
			m_JD = m_initJD;

			m_r *= 0.4;
		}
	}
	
}

void CCar::MoveZhuanQuanChaZhaoXieLouDian()
{
	float deltat = 0.1;

	if (m_ndCir.jd < 360)
	{	
		//转圈
		m_x = m_ndCir.x + m_ndCir.r * cos(m_ndCir.jd / 180 * PI);
		m_y = m_ndCir.y + m_ndCir.r * sin(m_ndCir.jd / 180 * PI);
		m_ndCir.jd += m_ndCir.omg * deltat;

		//保存最大浓度点和最小浓度点
		if (m_ndCir.Max < m_nd)
		{
			m_ndCir.Max = m_nd;
			m_ndCir.Max_x = m_x;
			m_ndCir.Max_y = m_y;
		}
		if (m_ndCir.Min > m_nd)
		{
			m_ndCir.Min = m_nd;
			m_ndCir.Min_x = m_x;
			m_ndCir.Min_y = m_y;
		}
	}
	else
	{
		//计算目标点坐标
		m_MBx = m_ndCir.x - 2 * (m_ndCir.x - m_ndCir.Max_x);
		m_MBy = m_ndCir.y - 2 * (m_ndCir.y - m_ndCir.Max_y);

		//匀速运动到目标点
		MoveYunSuDaoMuBiaoDian();

		//到达目标点
		if (m_d < 5)
		{
			m_ndCir.jd = 0;  //初始化角度
			m_ndCir.r *= 0.9;    //半径减小

			//初始化圆
			initCircleNDTest();
		}
	}
}

void CCar::DrawNDMaxMin()
{
	int x, y, r = 10;
	CString str;

	CBrush   Brush1;     
	Brush1.CreateSolidBrush(RGB(255,0,0));     
	pDC->SelectObject(&Brush1); 
	x = m_YD.x + m_ndCir.Max_x * m_kx;
	y = m_YD.y + m_ndCir.Max_y * m_ky;
	pDC->Ellipse(x - r, y - r, x + r, y + r);
	pDC->EndPath();      
	pDC->FillPath();
     
	CBrush   Brush2;  
	Brush2.CreateSolidBrush(RGB(0,255,0));     
	pDC->SelectObject(&Brush2);     
	x = m_YD.x + m_ndCir.Min_x * m_kx;
	y = m_YD.y + m_ndCir.Min_y * m_ky;
	pDC->Ellipse(x - r, y - r, x + r, y + r);
	pDC->EndPath();          
	pDC->FillPath(); 
}

void CCar::initCircleNDTest()
{
	m_ndCir.x = m_x - m_ndCir.r * cos(m_ndCir.jd / 180 * PI);
	m_ndCir.y = m_y - m_ndCir.r * sin(m_ndCir.jd / 180 * PI);
	m_ndCir.Max = 0;
	m_ndCir.Min = 10000000;
	m_ndCir.Max_x = m_x;
	m_ndCir.Max_y = m_y;
	m_ndCir.Min_x = m_x;
	m_ndCir.Min_y = m_y;
}
