// TanChiShe.h: interface for the CTanChiShe class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TANCHISHE_H__3CDD100F_7CBE_4B8D_8F87_679931563E20__INCLUDED_)
#define AFX_TANCHISHE_H__3CDD100F_7CBE_4B8D_8F87_679931563E20__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define WIN 100  //胜利长度
#define INITLEN 3   //蛇的初始长度

class CTanChiShe  
{
public:
	void DrawHelp();
	void DrawFood();
	int isOver();
	void Move();
	void initSnake();
	void DrawAll(CDC *p);
	void DrawSnake();
	void DrawDiTu();
	CTanChiShe();
	virtual ~CTanChiShe();


	CDC *pDC;

	//地图的变量
	int m_X, m_Y;  //地图左上角坐标
	int m_Size;  //地图尺寸
	int m_Num;   //地图中一行的小方格数量
	             //   m_Size / m_Num 就是小方格尺寸

	//蛇的变量		
	int m_nlen;  //蛇的长度
	int m_initX;
	int m_initY;  //蛇的初始坐标
	CPoint m_Body[WIN]; //蛇身坐标
	int m_Dir;  //方向

	//食物的变量
	CPoint m_Food; // 食物坐标
};

#endif // !defined(AFX_TANCHISHE_H__3CDD100F_7CBE_4B8D_8F87_679931563E20__INCLUDED_)
