// Robot.h: interface for the CRobot class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ROBOT_H__6A26F2A6_69EE_45A9_B812_3FEAA0281F0A__INCLUDED_)
#define AFX_ROBOT_H__6A26F2A6_69EE_45A9_B812_3FEAA0281F0A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Ado.h"
#include "DlgCSSZ.h"


class CRobot  
{
public:
	void DeleteRobot();
	void CreateRobot();
	void UpdateRobot();
	void InitRobot();
	void DrawRobot();
	float m_kx,m_ky;//比例尺

	//当前选择的机器人
	CString m_CurRobotName;

	//机器人矩形身体的的左上角像素点位置作为原点
	int m_X,m_Y;
	
	
	//机器人圆形头的圆心位置(距坐标原点，单位：m)
	float m_Xhead,m_Yhead;
	//机器人头的半径
	float m_Rhead;
	
	//机器人左眼睛的圆心位置(距坐标原点，单位：m)
	float m_Xlefteye,m_Ylefteye;
	//机器人左眼睛的半径
	float m_Rlefteye;

	//机器人右眼睛的圆心位置(距坐标原点，单位：m)
	float m_Xrighteye,m_Yrighteye;
	//机器人左眼睛的半径
	float m_Rrighteye;

	//机器人鼻子(等边三角形)顶点的位置(距坐标原点，单位：m)
	float m_Xnose,m_Ynose;
	//机器人鼻子(等边三角形)边长
	float m_Lnose;

	//机器人嘴巴(椭圆)圆心的位置(距坐标原点，单位：m)
	float m_Xmouth,m_Ymouth;
	//机器人嘴巴(椭圆)长轴与短轴
	float m_Lmouth,m_Smouth;

	//机器人脖子(矩形)左上角点的位置(距坐标原点，单位：m)
	float m_Xneck,m_Yneck;
	//机器人脖子(矩形)宽与高
	float m_Wneck,m_Hneck;

	//机器人左臂(矩形)左上角点的位置(距坐标原点，单位：m)
	float m_Xleftarm,m_Yleftarm;
	//机器人左臂(矩形)宽与高
	float m_Wleftarm,m_Hleftarm;

	//机器人右臂(矩形)左上角点的位置(距坐标原点，单位：m)
	float m_Xrightarm,m_Yrightarm;
	//机器人右臂(矩形)宽与高
	float m_Wrightarm,m_Hrightarm;

	//机器人身体(矩形)左上角点的位置(距坐标原点，单位：m)
	float m_Xbody,m_Ybody;
	//机器人身体(矩形)宽与高
	float m_Wbody,m_Hbody;

	//机器人左腿(矩形)左上角点的位置(距坐标原点，单位：m)
	float m_Xleftleg,m_Yleftleg;
	//机器人左腿(矩形)宽与高
	float m_Wleftleg,m_Hleftleg;

	//机器人右腿(矩形)左上角点的位置(距坐标原点，单位：m)
	float m_Xrightleg,m_Yrightleg;
	//机器人右腿(矩形)宽与高
	float m_Wrightleg,m_Hrightleg;

	//机器人左脚(矩形)左上角点的位置(距坐标原点，单位：m)
	float m_Xleftfoot,m_Yleftfoot;
	//机器人左脚(矩形)宽与高
	float m_Wleftfoot,m_Hleftfoot;

	//机器人右脚(矩形)左上角点的位置(距坐标原点，单位：m)
	float m_Xrightfoot,m_Yrightfoot;
	//机器人右脚(矩形)宽与高
	float m_Wrightfoot,m_Hrightfoot;


	CAdo m_Ado;
	CDlgCSSZ m_dlg;
	CDC* pDC;
	void Draw(CDC* DC);
	CRobot();
	virtual ~CRobot();

};

#endif // !defined(AFX_ROBOT_H__6A26F2A6_69EE_45A9_B812_3FEAA0281F0A__INCLUDED_)
