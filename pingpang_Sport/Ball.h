// Ball.h: interface for the CBall class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BALL_H__FC358460_38A8_4D54_9BD4_B2EF64C7BD31__INCLUDED_)
#define AFX_BALL_H__FC358460_38A8_4D54_9BD4_B2EF64C7BD31__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CBall  
{
public:
	void DrawFST();
	void initState();
	void Move();
	void DrawVCurve();
	void DrawXCurve();
	void DrawCST();
	void Draw(CDC *p);
	CBall();
	virtual ~CBall();



	CDC *pDC;
	float m_k;  //  像素/米

	CPoint m_YD_CST;
	CPoint m_YD_FST;

	float m_L;  //桌子长度
	float m_W;  //桌子宽度
	float m_H;  //球网高度

	float m_r;  //半径

	//位置
	float m_x0, m_x;
	float m_y0, m_y;
	float m_z0, m_z;

	//速度
	float m_vx0, m_vx; 
	float m_vy0, m_vy;
	float m_vz0, m_vz;

	//轨迹数组
	float m_xGJ[1000];
	float m_yGJ[1000];
	float m_zGJ[1000];
	float m_vxGJ[1000];
	float m_vyGJ[1000];
	float m_vzGJ[1000];

	int m_nxGJ;
	int m_nyGJ;
	int m_nzGJ;
	int m_nvxGJ;
	int m_nvyGJ;
	int m_nvzGJ;
};

#endif // !defined(AFX_BALL_H__FC358460_38A8_4D54_9BD4_B2EF64C7BD31__INCLUDED_)
