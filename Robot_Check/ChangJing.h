// ChangJing.h: interface for the CChangJing class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHANGJING_H__2F9F77A7_D1E9_4065_B961_CB4D969D7610__INCLUDED_)
#define AFX_CHANGJING_H__2F9F77A7_D1E9_4065_B961_CB4D969D7610__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

typedef struct
{
	char name[50];
	float pos[4][2];
	float name_pos[2];
}SBuilding;

typedef struct
{
	char name[50];
	float pos1[20][2];
	float pos2[20][2];
	int n;
	float name_pos[2];
}SRoad;

typedef struct
{
	float x, y;
	float vx, vy;
	float T;
	float t;
}SLiZi;

class CChangJing  
{
public:
	int QiuNongDu(float x, float y);
	void MoveLiZi();
	void DrawChangJing();
	void DrawLiZi();
	void CreateLiZi();
	void Draw(CDC *pDC);
	void InitChangJing();
	CChangJing();
	virtual ~CChangJing();

	CDC *pDC;
	float m_kx;
	float m_ky;
	CPoint m_YD;

	float m_XLDx, m_XLDy;
	int m_nd;  //Å¨¶È

	SBuilding m_JZ[100];
	int m_nJZ;

	SRoad m_LM[100];
	int m_nLM;

	SLiZi m_LZ[100000];
	int m_nLZ;


	bool m_flag_drawlz;

};

#endif // !defined(AFX_CHANGJING_H__2F9F77A7_D1E9_4065_B961_CB4D969D7610__INCLUDED_)
