// Tank.h: interface for the CTank class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TANK_H__4FEF5159_5F5A_4DA1_8DEA_984BFF259660__INCLUDED_)
#define AFX_TANK_H__4FEF5159_5F5A_4DA1_8DEA_984BFF259660__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

typedef struct
{
	float x;
	float y;
	float r;
	float v;
	int score;
}SCircle;

typedef struct
{
	float x;
	float y;
	float w;
	float v;
	int score;
}SSquare;

typedef struct
{
	float x;
	float y;
	float w;
	float h;
	float v;
	int score;
}STriangle;

typedef struct
{
	float x;
	float y;
	float r;
	float v;
}SBullet;

class CTank  
{
public:
	void InitGame();
	int BlockHitTank();
	void BulletHitBlock();
	void DeleteBullet(int n);
	void MoveBullet();
	void CreateBullet();
	void MoveTank(int direction);
	void DeleteTriangle(int n);
	void DeleteSquare(int n);
	void DeleteCircle(int n);
	void DrawTriangle();
	void DrawSquare();
	void DrawCircle();
	void MoveTriangle();
	void MoveSquare();
	void MoveCircle();
	void CreateTriangle();
	void CreateSquare();
	void CreateCircle();
	void MoveBlock();
	void CreateBlock();
	void DrawBullet();
	void DrawTank();
	void DrawBackground();
	void Draw(CDC *p);
	CTank();
	virtual ~CTank();

	CDC *pDC;

	//地图
	CPoint m_BK;
	int m_wBK, m_hBK;

	int m_Score;

	//坦克
	CPoint m_Center;  //坦克中心坐标
	int m_rCenter;
	int m_BodyLen;    //坦克边长
	int m_GunLen;     //炮管长度

	//子弹
	SBullet m_Bul[100];
	int m_nBul;

	//方块
	int m_nCir, m_nSqu, m_nTri;
	SCircle m_Cir[100];
	SSquare m_Squ[100];
	STriangle m_Tri[100];
};

#endif // !defined(AFX_TANK_H__4FEF5159_5F5A_4DA1_8DEA_984BFF259660__INCLUDED_)
