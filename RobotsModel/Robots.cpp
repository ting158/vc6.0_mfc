// Robots.cpp: implementation of the CRobots class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "RobotsModel.h"
#include "Robots.h"

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

CRobots::CRobots()
{
	m_YD.x = 500;
	m_YD.y = 500;

	m_kx = 5;
	m_ky = -m_kx;

	m_MoveType = -1;
	m_deltaT = 0.1;
	m_v = 100;
	m_t = 0;

	m_eyeflag = 0;
}

CRobots::~CRobots()
{

}

void CRobots::Draw(CDC *p)
{
	pDC = p;

	DrawRobot();
}

void CRobots::DrawRobot()
{
	float x, y, r, w, h, angle;
	CPoint pos[4];

	//头
	x = m_YD.x + m_x * m_kx;
	y = m_YD.y + (m_y + m_hBody / 2 + m_hNeck + m_rHead) * m_ky;
	r = m_rHead * m_kx;
	pDC->Ellipse(x - r, y - r, x + r, y + r);

	//眼睛
	x = m_YD.x + (m_x - m_rHead * 0.3) * m_kx;
	y = m_YD.y + (m_y + m_hBody / 2 + m_hNeck + m_rHead * 1.3) * m_ky;
	w = m_wEyes * m_kx;
	h = m_hEyes * m_kx;
	pDC->Ellipse(x - w, y - h, x + w, y + h);     //左
	x = m_YD.x + (m_x + m_rHead * 0.3) * m_kx;
	y = m_YD.y + (m_y + m_hBody / 2 + m_hNeck + m_rHead * 1.3) * m_ky;
	w = m_wEyes * m_kx;
	h = m_hEyes * m_kx;
	pDC->Ellipse(x - w, y - h, x + w, y + h);     //右

	//鼻子
	x = m_YD.x + (m_x - m_wNose / 2) * m_kx;
	y = m_YD.y + (m_y + m_hBody / 2 + m_wNeck + m_rHead * 0.8) * m_ky;
	w = m_wNose * m_kx;
	pos[0].x = x;
	pos[0].y = y;
	pos[1].x = x + w;
	pos[1].y = y;
	pos[2].x = (x + x + w) / 2;
	pos[2].y = y - w * sin(60 / 180.0 * PI);
	pDC->Polygon(pos, 3);

	//嘴巴
	x = m_YD.x + m_x * m_kx;
	y = m_YD.y + (m_y + m_hBody / 2 + m_wNeck + m_rHead * 0.5) * m_ky;
	w = m_wMouth * m_kx;
	h = m_hMouth * m_kx;
	pDC->Ellipse(x - w, y - h, x + w, y + h);

	//脖子
	x = m_YD.x - m_wNeck / 2 * m_kx + m_x * m_kx;
	y = m_YD.y + (m_y + m_hBody / 2 + m_hNeck) * m_ky;
	w = m_wNeck * m_kx;
	h = m_hNeck * m_kx;
	pDC->Rectangle(x, y, x + w, y + h);

	//身体
	x = m_YD.x - m_wBody / 2 * m_kx + m_x * m_kx;
	y = m_YD.y + (m_y + m_hBody / 2) * m_ky;
	w = m_wBody * m_kx;
	h = m_hBody * m_kx;
	pDC->Rectangle(x, y, x + w, y + h);

	//胳膊
	x = m_YD.x + (m_x - m_wBody / 2 - m_wArm) * m_kx;
	y = m_YD.y + (m_y + m_hBody / 2) * m_ky;
	w = m_wArm * m_kx;
	h = m_hArm * m_kx;
	angle = m_AngleArm;
	pos[0].x = x;                pos[0].y = y;
	pos[1].x = pos[0].x;		 pos[1].y = pos[0].y + h;  
	pos[2].x = pos[0].x + w;	 pos[2].y = pos[0].y + h;
	pos[3].x = pos[0].x + w;	 pos[3].y = pos[0].y;
	pos[1].x = (pos[1].x - pos[3].x) * cos(angle / 180.0 * PI) - (pos[1].y - pos[3].y) * sin(angle / 180.0 * PI) + pos[3].x;
	pos[1].y = (pos[1].x - pos[3].x) * sin(angle / 180.0 * PI) + (pos[1].y - pos[3].y) * cos(angle / 180.0 * PI) + pos[3].y;
	pos[2].x = (pos[2].x - pos[3].x) * cos(angle / 180.0 * PI) - (pos[2].y - pos[3].y) * sin(angle / 180.0 * PI) + pos[3].x;
	pos[2].y = (pos[2].x - pos[3].x) * sin(angle / 180.0 * PI) + (pos[2].y - pos[3].y) * cos(angle / 180.0 * PI) + pos[3].y;
	pos[0].x = (pos[0].x - pos[3].x) * cos(angle / 180.0 * PI) - (pos[0].y - pos[3].y) * sin(angle / 180.0 * PI) + pos[3].x;
	pos[0].y = (pos[0].x - pos[3].x) * sin(angle / 180.0 * PI) + (pos[0].y - pos[3].y) * cos(angle / 180.0 * PI) + pos[3].y;	
	pDC->Polygon(pos, 4);  //左

	x = m_YD.x + (m_x + m_wBody / 2) * m_kx;
	y = m_YD.y + (m_y + m_hBody / 2) * m_ky;
	w = m_wArm * m_kx;
	h = m_hArm * m_kx;
	angle = m_AngleArm;
	pos[0].x = x;                pos[0].y = y;
	pos[1].x = pos[0].x;		 pos[1].y = pos[0].y + h;  
	pos[2].x = pos[0].x + w;	 pos[2].y = pos[0].y + h;
	pos[3].x = pos[0].x + w;	 pos[3].y = pos[0].y;
	pos[1].x = (pos[1].x - pos[0].x) * cos(-angle / 180.0 * PI) - (pos[1].y - pos[0].y) * sin(-angle / 180.0 * PI) + pos[0].x;
	pos[1].y = (pos[1].x - pos[0].x) * sin(-angle / 180.0 * PI) + (pos[1].y - pos[0].y) * cos(-angle / 180.0 * PI) + pos[0].y;
	pos[2].x = (pos[2].x - pos[0].x) * cos(-angle / 180.0 * PI) - (pos[2].y - pos[0].y) * sin(-angle / 180.0 * PI) + pos[0].x;
	pos[2].y = (pos[2].x - pos[0].x) * sin(-angle / 180.0 * PI) + (pos[2].y - pos[0].y) * cos(-angle / 180.0 * PI) + pos[0].y;
	pos[3].x = (pos[3].x - pos[0].x) * cos(-angle / 180.0 * PI) - (pos[3].y - pos[0].y) * sin(-angle / 180.0 * PI) + pos[0].x;
	pos[3].y = (pos[3].x - pos[0].x) * sin(-angle / 180.0 * PI) + (pos[3].y - pos[0].y) * cos(-angle / 180.0 * PI) + pos[0].y;
	pDC->Polygon(pos, 4);  //右

	//腿
	x = m_YD.x - m_wBody / 2 * 0.8 * m_kx + m_x * m_kx;
	y = m_YD.y + (m_y - m_hBody / 2) * m_ky;
	w = m_wLeg * m_kx;
	h = m_hLeg * m_kx;
	pDC->Rectangle(x, y, x + w, y + h);   //左
	x = m_YD.x + (m_wBody / 2 * 0.8 - m_wLeg) * m_kx + m_x * m_kx;
	pDC->Rectangle(x, y, x + w, y + h);   //右

	//脚
	x = m_YD.x - m_wBody / 2 * 0.8 * m_kx + m_x * m_kx;
	y = m_YD.y + (m_y - m_hBody / 2 - m_hLeg) * m_ky;
	w = m_wFoot * m_kx;
	h = m_hFoot * m_kx;
	pDC->Rectangle(x, y, x + w, y + h);   //左
	x = m_YD.x + (m_wBody / 2 * 0.8 - m_wLeg) * m_kx + m_x * m_kx;
	pDC->Rectangle(x, y, x + w, y + h);   //右
}


void CRobots::InitRobot(int id)
{
	m_ado.OnInitADOConn(".\\Robots.mdb");

	CString sql;
	sql.Format("select * from Robots where ID = %d", id);

	m_ado.GetRecordSet(sql);

	m_robotName = m_ado.GetCollect("robotName");
 	m_AngleArm = atof(m_ado.GetCollect("AngleArm"));
 	m_hArm = atof(m_ado.GetCollect("hArm"));
 	m_wArm = atof(m_ado.GetCollect("wArm"));
 	m_hBody = atof(m_ado.GetCollect("hBody"));
 	m_wBody = atof(m_ado.GetCollect("wBody"));
 	m_hEyes = atof(m_ado.GetCollect("hEyes"));
 	m_wEyes = atof(m_ado.GetCollect("wEyes"));
 	m_hFoot = atof(m_ado.GetCollect("hFoot"));
 	m_wFoot = atof(m_ado.GetCollect("wFoot"));
 	m_hLeg = atof(m_ado.GetCollect("hLeg"));
 	m_wLeg = atof(m_ado.GetCollect("wLeg"));
 	m_hNeck = atof(m_ado.GetCollect("hNeck"));
 	m_wNeck = atof(m_ado.GetCollect("wNeck"));
 	m_rHead = atof(m_ado.GetCollect("rHead"));
	m_wMouth = atof(m_ado.GetCollect("wMouth"));
 	m_hMouth = atof(m_ado.GetCollect("hMouth"));
 	m_x = atof(m_ado.GetCollect("x"));
 	m_y = atof(m_ado.GetCollect("y"));
 	m_wNose = atof(m_ado.GetCollect("wNose"));

	m_ado.ExitConnect();
}

void CRobots::Move()
{
	switch(m_MoveType)
	{
	case WALK:
		MoveWalk();
		break;
	case JUMP:
		MoveJump();
		break;
	case WINK:
		MoveWink();
		break;
	case WAVE:
		MoveWave();
		break;
	}
}

void CRobots::MoveWalk()
{
	CString sql;

	//修改坐标
	m_x += m_v * m_deltaT;

	if (m_x < 0 || m_x > 100)
		m_v = -m_v;

	
	//将新坐标存到数据库中
	m_ado.OnInitADOConn(".\\Robots.mdb");

	sql.Format("update Robots set robotName = '%s', x = '%f', y = '%f', wBody = '%f', hBody = '%f',\
		wNeck = '%f', hNeck = '%f', rHead = '%f', wEyes = '%f', hEyes = '%f', wNose = '%f', wMouth = '%f',\
		hMouth = '%f', wArm = '%f', hArm = '%f', AngleArm = '%f', wLeg = '%f', hLeg = '%f', wFoot = '%f',\
		hFoot = '%f' where ID = %d", 
		m_robotName, m_x, m_y, m_wBody, m_hBody, m_wNeck, m_hNeck, m_rHead, m_wEyes, m_hEyes, m_wNose, m_wMouth,
		m_hMouth, m_wArm, m_hArm, m_AngleArm, m_wLeg, m_hLeg, m_wFoot, m_hFoot, m_id);

	m_ado.ExecuteSQL(sql);

	m_ado.ExitConnect();
}

void CRobots::MoveJump()
{
	CString sql;

	//修改坐标
	m_y += m_v * m_deltaT;

	if (m_y < 0 || m_y > 30)
		m_v = -m_v;

	//将新坐标存到数据库中
	m_ado.OnInitADOConn(".\\Robots.mdb");

	sql.Format("update Robots set robotName = '%s', x = '%f', y = '%f', wBody = '%f', hBody = '%f',\
		wNeck = '%f', hNeck = '%f', rHead = '%f', wEyes = '%f', hEyes = '%f', wNose = '%f', wMouth = '%f',\
		hMouth = '%f', wArm = '%f', hArm = '%f', AngleArm = '%f', wLeg = '%f', hLeg = '%f', wFoot = '%f',\
		hFoot = '%f' where ID = %d", 
		m_robotName, m_x, m_y, m_wBody, m_hBody, m_wNeck, m_hNeck, m_rHead, m_wEyes, m_hEyes, m_wNose, m_wMouth,
		m_hMouth, m_wArm, m_hArm, m_AngleArm, m_wLeg, m_hLeg, m_wFoot, m_hFoot, m_id);

	m_ado.ExecuteSQL(sql);

	m_ado.ExitConnect();
}

void CRobots::MoveWink()
{
	CString sql;

	//修改眼睛的高度
	if (m_eyeflag % 2 == 0)
		m_hEyes = 1;
	else
		m_hEyes = 2;
	m_eyeflag++;

	//将新数据存到数据库中
	m_ado.OnInitADOConn(".\\Robots.mdb");

	sql.Format("update Robots set robotName = '%s', x = '%f', y = '%f', wBody = '%f', hBody = '%f',\
		wNeck = '%f', hNeck = '%f', rHead = '%f', wEyes = '%f', hEyes = '%f', wNose = '%f', wMouth = '%f',\
		hMouth = '%f', wArm = '%f', hArm = '%f', AngleArm = '%f', wLeg = '%f', hLeg = '%f', wFoot = '%f',\
		hFoot = '%f' where ID = %d", 
		m_robotName, m_x, m_y, m_wBody, m_hBody, m_wNeck, m_hNeck, m_rHead, m_wEyes, m_hEyes, m_wNose, m_wMouth,
		m_hMouth, m_wArm, m_hArm, m_AngleArm, m_wLeg, m_hLeg, m_wFoot, m_hFoot, m_id);

	m_ado.ExecuteSQL(sql);

	m_ado.ExitConnect();
}

void CRobots::MoveWave()
{
	CString sql;

	//修改挥手角度
	m_AngleArm = 22.5 * sin(m_t) + 22.5;
	m_t += m_deltaT * 4;

	//将新数据存到数据库中
	m_ado.OnInitADOConn(".\\Robots.mdb");

	sql.Format("update Robots set robotName = '%s', x = '%f', y = '%f', wBody = '%f', hBody = '%f',\
		wNeck = '%f', hNeck = '%f', rHead = '%f', wEyes = '%f', hEyes = '%f', wNose = '%f', wMouth = '%f',\
		hMouth = '%f', wArm = '%f', hArm = '%f', AngleArm = '%f', wLeg = '%f', hLeg = '%f', wFoot = '%f',\
		hFoot = '%f' where ID = %d", 
		m_robotName, m_x, m_y, m_wBody, m_hBody, m_wNeck, m_hNeck, m_rHead, m_wEyes, m_hEyes, m_wNose, m_wMouth,
		m_hMouth, m_wArm, m_hArm, m_AngleArm, m_wLeg, m_hLeg, m_wFoot, m_hFoot, m_id);

	m_ado.ExecuteSQL(sql);

	m_ado.ExitConnect();
}
