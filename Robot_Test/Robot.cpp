// Robot.cpp: implementation of the CRobot class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Robot_Test.h"
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
	m_kx = 100;//1m = 100px
	m_ky = -m_kx;

	//初始化选择的机器人为robot1
	m_CurRobotName.Format("robot1");

}

CRobot::~CRobot()
{

}

void CRobot::Draw(CDC *DC)
{
	pDC = DC;
	DrawRobot();

}

void CRobot::DrawRobot()
{//根据各项数据画出机器人
	int x,y,r;
	CPoint point[3];//用于存储三角形顶点
	int a,b;//椭圆的长轴和短轴
	int w,h;//矩形的宽和高


	
	//画头
	x = m_X + m_Xhead*m_kx;
	y = m_Y + m_Yhead*m_ky;
	r = m_Rhead*m_kx;
	pDC->Ellipse(x-r,y-r,x+r,y+r);
	//画左眼睛
	x = m_X + m_Xlefteye*m_kx;
	y = m_Y + m_Ylefteye*m_ky;
	r = m_Rlefteye*m_kx;
	pDC->Ellipse(x-r,y-r,x+r,y+r);
	//画右眼睛
	x = m_X + m_Xrighteye*m_kx;
	y = m_Y + m_Yrighteye*m_ky;
	r = m_Rrighteye*m_kx;
	pDC->Ellipse(x-r,y-r,x+r,y+r);
	//画鼻子
	point[0].x = m_X + m_Xnose*m_kx;
	point[0].y = m_Y + m_Ynose*m_ky;
	point[1].x = m_X + (m_Xnose-m_Lnose/2.0)*m_kx;
	point[1].y = m_Y + (m_Ynose-m_Lnose/2.0)*m_ky;
	point[2].x = m_X + (m_Xnose+m_Lnose/2.0)*m_kx;
	point[2].y = m_Y + (m_Ynose-m_Lnose/2.0)*m_ky;
	pDC->Polygon(point, 3);
	//画嘴巴
	x = m_X + m_Xmouth*m_kx;
	y = m_Y + m_Ymouth*m_ky;
	a = m_Lmouth*m_kx/2.0;//长轴的一半
	b = m_Smouth*m_kx/2.0;//短轴的一半
	pDC->Ellipse(x-a,y-b,x+a,y+b);
	//画脖子
	x = m_X + m_Xneck*m_kx;
	y = m_Y + m_Yneck*m_ky;
	w = m_Wneck*m_kx;
	h = m_Hneck*m_kx;
	pDC->Rectangle(x,y,x+w,y+h);
	//画左臂
	x = m_X + m_Xleftarm*m_kx;
	y = m_Y + m_Yleftarm*m_ky;
	w = m_Wleftarm*m_kx;
	h = m_Hleftarm*m_kx;
	pDC->Rectangle(x,y,x+w,y+h);
	//画右臂
	x = m_X + m_Xrightarm*m_kx;
	y = m_Y + m_Yrightarm*m_ky;
	w = m_Wrightarm*m_kx;
	h = m_Hrightarm*m_kx;
	pDC->Rectangle(x,y,x+w,y+h);
	//画身体
	x = m_X + m_Xbody*m_kx;
	y = m_Y + m_Ybody*m_ky;
	w = m_Wbody*m_kx;
	h = m_Hbody*m_kx;
	pDC->Rectangle(x,y,x+w,y+h);
	//画左腿
	x = m_X + m_Xleftleg*m_kx;
	y = m_Y + m_Yleftleg*m_ky;
	w = m_Wleftleg*m_kx;
	h = m_Hleftleg*m_kx;
	pDC->Rectangle(x,y,x+w,y+h);
	//画右腿
	x = m_X + m_Xrightleg*m_kx;
	y = m_Y + m_Yrightleg*m_ky;
	w = m_Wrightleg*m_kx;
	h = m_Hrightleg*m_kx;
	pDC->Rectangle(x,y,x+w,y+h);
	//画左脚
	x = m_X + m_Xleftfoot*m_kx;
	y = m_Y + m_Yleftfoot*m_ky;
	w = m_Wleftfoot*m_kx;
	h = m_Hleftfoot*m_kx;
	pDC->Rectangle(x,y,x+w,y+h);
	//画右脚
	x = m_X + m_Xrightfoot*m_kx;
	y = m_Y + m_Yrightfoot*m_ky;
	w = m_Wrightfoot*m_kx;
	h = m_Hrightfoot*m_kx;
	pDC->Rectangle(x,y,x+w,y+h);

	//写机器人名字
	x = m_X + 30;
	y = m_Y + 20;
	pDC->TextOut(x,y,m_CurRobotName);



	

}

void CRobot::InitRobot()
{//从数据库获取数据初始化机器人

	//获取连接
	m_Ado.OnInitADOConn(".\\Robots.mdb");
	CString sql,value;
	float a;

	sql.Format("select * from Robots where RobotName =  ");
	sql += "'";
	sql += m_CurRobotName;
	sql += "'";
	
	//获取记录集
	m_Ado.GetRecordSet(sql);
	if(!m_Ado.m_pRecordset->adoEOF)
	{//m_Ado.m_pRecordset->MoveNext();//移动到下一条记录
		
		//机器人名字
		m_CurRobotName = m_Ado.GetCollect("RobotName");
		
		value = m_Ado.GetCollect("m_X");
		//CString类型转为int
		m_X = atoi(value);
		value = m_Ado.GetCollect("m_Y");
		m_Y = atoi(value);

		value = m_Ado.GetCollect("m_Xhead");
		//CString类型转为float
		m_Xhead = atof(value);
		value = m_Ado.GetCollect("m_Yhead");
		m_Yhead = atof(value);
		value = m_Ado.GetCollect("m_Rhead");
		m_Rhead = atof(value);

		value = m_Ado.GetCollect("m_Xlefteye");
		m_Xlefteye = atof(value);
		value = m_Ado.GetCollect("m_Ylefteye");
		m_Ylefteye = atof(value);
		value = m_Ado.GetCollect("m_Rlefteye");
		m_Rlefteye = atof(value);

		//右眼
		value = m_Ado.GetCollect("m_Xrighteye");
		m_Xrighteye = atof(value);
		value = m_Ado.GetCollect("m_Yrighteye");
		m_Yrighteye = atof(value);
		value = m_Ado.GetCollect("m_Rrighteye");
		m_Rrighteye = atof(value);

		//鼻子
		value = m_Ado.GetCollect("m_Xnose");
		m_Xnose = atof(value);
		value = m_Ado.GetCollect("m_Ynose");
		m_Ynose = atof(value);
		value = m_Ado.GetCollect("m_Lnose");
		m_Lnose = atof(value);

		//嘴巴
		value = m_Ado.GetCollect("m_Xmouth");
		m_Xmouth = atof(value);
		value = m_Ado.GetCollect("m_Ymouth");
		m_Ymouth = atof(value);
		value = m_Ado.GetCollect("m_Lmouth");
		m_Lmouth = atof(value);
		value = m_Ado.GetCollect("m_Smouth");
		m_Smouth = atof(value);

		//脖子
		value = m_Ado.GetCollect("m_Xneck");
		m_Xneck = atof(value);
		value = m_Ado.GetCollect("m_Yneck");
		m_Yneck = atof(value);
		value = m_Ado.GetCollect("m_Wneck");
		m_Wneck = atof(value);
		value = m_Ado.GetCollect("m_Hneck");
		m_Hneck = atof(value);

		//左臂
		value = m_Ado.GetCollect("m_Xleftarm");
		m_Xleftarm = atof(value);
		value = m_Ado.GetCollect("m_Yleftarm");
		m_Yleftarm = atof(value);
		value = m_Ado.GetCollect("m_Wleftarm");
		m_Wleftarm = atof(value);
		value = m_Ado.GetCollect("m_Hleftarm");
		m_Hleftarm = atof(value);

		//右臂
		value = m_Ado.GetCollect("m_Xrightarm");
		m_Xrightarm = atof(value);
		value = m_Ado.GetCollect("m_Yrightarm");
		m_Yrightarm = atof(value);
		value = m_Ado.GetCollect("m_Wrightarm");
		m_Wrightarm = atof(value);
		value = m_Ado.GetCollect("m_Hrightarm");
		m_Hrightarm = atof(value);

		//身体
		value = m_Ado.GetCollect("m_Xbody");
		m_Xbody = atof(value);
		value = m_Ado.GetCollect("m_Ybody");
		m_Ybody = atof(value);
		value = m_Ado.GetCollect("m_Wbody");
		m_Wbody = atof(value);
		value = m_Ado.GetCollect("m_Hbody");
		m_Hbody = atof(value);

		//左腿
		value = m_Ado.GetCollect("m_Xleftleg");
		m_Xleftleg = atof(value);
		value = m_Ado.GetCollect("m_Yleftleg");
		m_Yleftleg = atof(value);
		value = m_Ado.GetCollect("m_Wleftleg");
		m_Wleftleg = atof(value);
		value = m_Ado.GetCollect("m_Hleftleg");
		m_Hleftleg = atof(value);

		//右腿
		value = m_Ado.GetCollect("m_Xrightleg");
		m_Xrightleg = atof(value);
		value = m_Ado.GetCollect("m_Yrightleg");
		m_Yrightleg = atof(value);
		value = m_Ado.GetCollect("m_Wrightleg");
		m_Wrightleg = atof(value);
		value = m_Ado.GetCollect("m_Hrightleg");
		m_Hrightleg = atof(value);

		//左脚
		value = m_Ado.GetCollect("m_Xleftfoot");
		m_Xleftfoot = atof(value);
		value = m_Ado.GetCollect("m_Yleftfoot");
		m_Yleftfoot = atof(value);
		value = m_Ado.GetCollect("m_Wleftfoot");
		m_Wleftfoot = atof(value);
		value = m_Ado.GetCollect("m_Hleftfoot");
		m_Hleftfoot = atof(value);

		//右脚
		value = m_Ado.GetCollect("m_Xrightfoot");
		m_Xrightfoot = atof(value);
		value = m_Ado.GetCollect("m_Yrightfoot");
		m_Yrightfoot = atof(value);
		value = m_Ado.GetCollect("m_Wrightfoot");
		m_Wrightfoot = atof(value);
		value = m_Ado.GetCollect("m_Hrightfoot");
		m_Hrightfoot = atof(value);

	}


	m_Ado.ExitConnect();


}

void CRobot::UpdateRobot()
{

	//获取连接
	m_Ado.OnInitADOConn(".\\Robots.mdb");
	CString sql;

	sql.Format("update Robots set RobotName = '%s', m_X = '%s', m_Y = '%s', m_Xhead = '%s', m_Yhead = '%s', m_Rhead = '%s', m_Xlefteye = '%s', m_Ylefteye = '%s', m_Rlefteye = '%s', m_Xrighteye = '%s', m_Yrighteye = '%s', m_Rrighteye = '%s', m_Xnose = '%s', m_Ynose = '%s', m_Lnose = '%s', m_Xmouth = '%s', m_Ymouth = '%s', m_Lmouth = '%s', m_Smouth = '%s', m_Xneck = '%s', m_Yneck = '%s', m_Wneck = '%s', m_Hneck = '%s', m_Xleftarm = '%s', m_Yleftarm = '%s', m_Wleftarm = '%s', m_Hleftarm = '%s', m_Xrightarm = '%s', m_Yrightarm = '%s', m_Wrightarm = '%s', m_Hrightarm = '%s', m_Xbody = '%s', m_Ybody = '%s', m_Wbody = '%s', m_Hbody = '%s', m_Xleftleg = '%s', m_Yleftleg = '%s', m_Wleftleg = '%s', m_Hleftleg = '%s', m_Xrightleg = '%s', m_Yrightleg = '%s', m_Wrightleg = '%s', m_Hrightleg = '%s', m_Xleftfoot = '%s', m_Yleftfoot = '%s', m_Wleftfoot = '%s', m_Hleftfoot = '%s', m_Xrightfoot = '%s', m_Yrightfoot = '%s', m_Wrightfoot = '%s', m_Hrightfoot = '%s' where RobotName = '%s'",
		m_dlg.m_RobotName, m_dlg.m_X, m_dlg.m_Y, m_dlg.m_Xhead, m_dlg.m_Yhead, m_dlg.m_Rhead, m_dlg.m_Xlefteye, m_dlg.m_Ylefteye, m_dlg.m_Rlefteye, m_dlg.m_Xrighteye, m_dlg.m_Yrighteye, m_dlg.m_Rrighteye, m_dlg.m_Xnose, m_dlg.m_Ynose, m_dlg.m_Lnose, m_dlg.m_Xmouth, m_dlg.m_Ymouth, m_dlg.m_Lmouth, m_dlg.m_Smouth, m_dlg.m_Xneck, m_dlg.m_Yneck, m_dlg.m_Wneck, m_dlg.m_Hneck, m_dlg.m_Xleftarm, m_dlg.m_Yleftarm, m_dlg.m_Wleftarm, m_dlg.m_Hleftarm, m_dlg.m_Xrightarm, m_dlg.m_Yrightarm, m_dlg.m_Wrightarm, m_dlg.m_Hrightarm, m_dlg.m_Xbody, m_dlg.m_Ybody, m_dlg.m_Wbody, m_dlg.m_Hbody, m_dlg.m_Xleftleg, m_dlg.m_Yleftleg, m_dlg.m_Wleftleg, m_dlg.m_Hleftleg, m_dlg.m_Xrightleg, m_dlg.m_Yrightleg, m_dlg.m_Wrightleg, m_dlg.m_Hrightleg, m_dlg.m_Xleftfoot, m_dlg.m_Yleftfoot, m_dlg.m_Wleftfoot, m_dlg.m_Hleftfoot, m_dlg.m_Xrightfoot, m_dlg.m_Yrightfoot, m_dlg.m_Wrightfoot, m_dlg.m_Hrightfoot, m_CurRobotName);


	m_Ado.ExecuteSQL(sql);

	//关闭连接
	m_Ado.ExitConnect();
	

}

void CRobot::CreateRobot()
{
		//获取连接
	m_Ado.OnInitADOConn(".\\Robots.mdb");
	CString sql;

	sql.Format("INSERT INTO Robots (RobotName, m_X, m_Y, m_Xhead, m_Yhead, m_Rhead, m_Xlefteye, m_Ylefteye, m_Rlefteye, m_Xrighteye, m_Yrighteye, m_Rrighteye, m_Xnose, m_Ynose, m_Lnose, m_Xmouth, m_Ymouth, m_Lmouth, m_Smouth, m_Xneck, m_Yneck, m_Wneck, m_Hneck, m_Xleftarm, m_Yleftarm, m_Wleftarm, m_Hleftarm, m_Xrightarm, m_Yrightarm, m_Wrightarm, m_Hrightarm, m_Xbody, m_Ybody, m_Wbody, m_Hbody, m_Xleftleg, m_Yleftleg, m_Wleftleg, m_Hleftleg, m_Xrightleg, m_Yrightleg, m_Wrightleg, m_Hrightleg, m_Xleftfoot, m_Yleftfoot, m_Wleftfoot, m_Hleftfoot, m_Xrightfoot, m_Yrightfoot, m_Wrightfoot, m_Hrightfoot) VALUES ('%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s')",
	m_dlg.m_RobotName,
	m_dlg.m_X, m_dlg.m_Y,
	m_dlg.m_Xhead, m_dlg.m_Yhead, m_dlg.m_Rhead,
	m_dlg.m_Xlefteye, m_dlg.m_Ylefteye, m_dlg.m_Rlefteye,
	m_dlg.m_Xrighteye, m_dlg.m_Yrighteye, m_dlg.m_Rrighteye,
	m_dlg.m_Xnose, m_dlg.m_Ynose, m_dlg.m_Lnose,
	m_dlg.m_Xmouth, m_dlg.m_Ymouth, m_dlg.m_Lmouth, m_dlg.m_Smouth,
	m_dlg.m_Xneck, m_dlg.m_Yneck, m_dlg.m_Wneck, m_dlg.m_Hneck,
	m_dlg.m_Xleftarm, m_dlg.m_Yleftarm, m_dlg.m_Wleftarm, m_dlg.m_Hleftarm,
	m_dlg.m_Xrightarm, m_dlg.m_Yrightarm, m_dlg.m_Wrightarm, m_dlg.m_Hrightarm,
	m_dlg.m_Xbody, m_dlg.m_Ybody, m_dlg.m_Wbody, m_dlg.m_Hbody,
	m_dlg.m_Xleftleg, m_dlg.m_Yleftleg, m_dlg.m_Wleftleg, m_dlg.m_Hleftleg,
	m_dlg.m_Xrightleg, m_dlg.m_Yrightleg, m_dlg.m_Wrightleg, m_dlg.m_Hrightleg,
	m_dlg.m_Xleftfoot, m_dlg.m_Yleftfoot, m_dlg.m_Wleftfoot, m_dlg.m_Hleftfoot,
	m_dlg.m_Xrightfoot, m_dlg.m_Yrightfoot, m_dlg.m_Wrightfoot, m_dlg.m_Hrightfoot);
	
	AfxMessageBox(sql);
	
	//执行sql
	m_Ado.ExecuteSQL(sql);

	//关闭连接
	m_Ado.ExitConnect();
	

}

void CRobot::DeleteRobot()
{
	//获取连接
	m_Ado.OnInitADOConn(".\\Robots.mdb");
	CString sql;

	sql.Format("delete from Robots where RobotName = '%s'",m_CurRobotName);

		//执行sql
	m_Ado.ExecuteSQL(sql);

	//关闭连接
	m_Ado.ExitConnect();

}
