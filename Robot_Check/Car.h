// Car.h: interface for the CCar class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CAR_H__F592E093_804C_4E99_B6F4_359B52BFD91B__INCLUDED_)
#define AFX_CAR_H__F592E093_804C_4E99_B6F4_359B52BFD91B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


enum Move_Mode
{
	ShunYi, YunSu, ZhuanQuan, LuJing, FindXieLou
};

typedef struct
{
	float x, y;  //Բ������
	float r;     //תȦ�뾶
	float omg;   //���ٶ�
	float jd;    //��ʼ�ǶȺ�ʵʱ�Ƕ�
	float Max;   //Ũ�����ֵ
	float Min;   //Ũ����Сֵ
	float Max_x, Max_y;  //Ũ�����ֵ����
	float Min_x, Min_y;  //Ũ����Сֵ����
}SCircleNDTest;

class CCar  
{
public:
	void initCircleNDTest();
	void DrawNDMaxMin();
	void MoveZhuanQuanChaZhaoXieLouDian();
	void MoveFindXieLouDian();
	int isOverLuJing();
	void DrawCar();
	void DrawLuJing();
	void ChuLiGuiJiZuoBiao(CPoint p);
	void MoveGuiJi();
	void ChuLiYuanXinCanShu();
	void ZhuanHuaMuBiaoDian(CPoint p);
	void MoveZhuanQuan();
	void MoveYunSuDaoMuBiaoDian();
	void Move();
	void MoveDianNaDaoNa();
	void Draw(CDC *pDC);
	CCar();
	virtual ~CCar();

	CDC *pDC;

	float m_kx;
	float m_ky;
	CPoint m_YD;

	float m_x, m_y;
	float m_v, m_vx, m_vy;
	float m_w;
	float m_MBx, m_MBy;
	float m_d;
	float m_YXx, m_YXy;   //תȦ��Բ��
	float m_JD;  
	float m_vJD;  //���ٶ�
	int m_sn;     //˳ʱ��Ϊ-1����ʱ��Ϊ1
	float m_r;    //תȦ�뾶
	float m_dir;  //Բ�ķ���
	int m_mode;

	int m_nd;  //Ũ��

	float m_GJ[50][2];
	int m_nGJ;
	int m_bjCreate;
	int m_nowMB;

	float m_initJD;  //תȦ��ʼ�Ƕ�
	int m_nd_max;    //תȦ�����Ũ��
	float m_x_max;
	float m_y_max;   //תȦ�����Ũ������

	SCircleNDTest m_ndCir;
};

#endif // !defined(AFX_CAR_H__F592E093_804C_4E99_B6F4_359B52BFD91B__INCLUDED_)
