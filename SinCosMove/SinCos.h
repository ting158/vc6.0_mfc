// SinCos.h: interface for the CSinCos class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SINCOS_H__2F6B1AF5_3F65_4C34_94AC_9F397A2B1E39__INCLUDED_)
#define AFX_SINCOS_H__2F6B1AF5_3F65_4C34_94AC_9F397A2B1E39__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSinCos  
{
public:
	void initCurve();
	void DrawCurve(int X, int Y, float arr[], int n, CString str);
	void DrawCos();
	void DrawSin();
	void Move();
	void DrawBackground();
	void Draw(CDC *p);
	CSinCos();
	virtual ~CSinCos();


	CDC *pDC;

	CPoint m_Center;  //圆心位置
	float m_R;  //半径

	float m_Angle;  //旋转角度
	float m_vAngle; //角速度

	float m_x;
	float m_y;

	float m_xGJ[1000];
	int m_nxGJ;
	float m_yGJ[1000];
	int m_nyGJ;

	float m_vxGJ[1000];
	int m_nvxGJ;
	float m_vyGJ[1000];
	int m_nvyGJ;
	float m_axGJ[1000];
	int m_naxGJ;
	float m_ayGJ[1000];
	int m_nayGJ;

	CPoint m_Origin; //坐标原点
	float m_ZH;  //像素与米的转换系数
};

#endif // !defined(AFX_SINCOS_H__2F6B1AF5_3F65_4C34_94AC_9F397A2B1E39__INCLUDED_)
