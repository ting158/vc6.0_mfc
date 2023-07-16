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

	float m_ZH;  //�������ص�ת��ϵ��

	//����
	CPoint m_Point;  //�������ҵ�
	float m_LUp;       //���ҵ��ɵ��߳�
	float m_LDown;     //����С���߳�
	float m_w;  //���ɿ��
	float m_L;  //���ɳ���
	float m_L0; //����ԭ��
	float m_k;  //����ϵ��
	float m_zn; //����ϵ��

	//С��
	float m_m;  //����
	float m_r;  //�뾶
	float m_v;  //�ٶ�
	float m_f;  //������
	float m_a;  //���ٶ�
	float m_y;  //λ��

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
