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

	CPoint m_Center;  //Բ��λ��
	float m_R;  //�뾶

	float m_Angle;  //��ת�Ƕ�
	float m_vAngle; //���ٶ�

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

	CPoint m_Origin; //����ԭ��
	float m_ZH;  //�������׵�ת��ϵ��
};

#endif // !defined(AFX_SINCOS_H__2F6B1AF5_3F65_4C34_94AC_9F397A2B1E39__INCLUDED_)
