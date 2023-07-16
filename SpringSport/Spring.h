// Spring.h: interface for the CSpring class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SPRING_H__A7538479_A130_49B4_9C3E_54F95C9D2570__INCLUDED_)
#define AFX_SPRING_H__A7538479_A130_49B4_9C3E_54F95C9D2570__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CSpring  
{
public:
	void DrawQuXian(int initX, int initY, float gj[], int ngj, CString str, float max, float p);
	void initSport();
	void Move();
	void DrawFQuXian();
	void DrawAQuXian();
	void DrawVQuXian();
	void DrawYQuXian();
	void DrawSpring();
	void Draw(CDC *pDC);
	CSpring();
	virtual ~CSpring();


	CDC *pDC;

	float m_ZH;  //米与像素的转换系数

	//弹簧
	CPoint m_Point;  //弹簧悬挂点
	float m_LUp;       //悬挂弹簧的线长
	float m_LDown;     //悬挂小球线长
	float m_w;  //弹簧宽度
	float m_L;  //弹簧长度
	float m_L0; //弹簧原长
	float m_k;  //弹性系数
	float m_zn; //阻尼系数

	//小球
	float m_m;  //质量
	float m_r;  //半径
	float m_v;  //速度
	float m_f;  //合外力
	float m_a;  //加速度
	float m_y;  //位移

	float m_vGJ[1000];
	float m_fGJ[1000];
	float m_aGJ[1000]; 
	float m_yGJ[1000];

	int m_nvGJ;
	int m_nfGJ;
	int m_naGJ;
	int m_nyGJ;
};

#endif // !defined(AFX_SPRING_H__A7538479_A130_49B4_9C3E_54F95C9D2570__INCLUDED_)
