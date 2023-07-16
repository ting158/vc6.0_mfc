// Control.h: interface for the CControl class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONTROL_H__0581C30E_FC42_4043_B260_66254DCD8644__INCLUDED_)
#define AFX_CONTROL_H__0581C30E_FC42_4043_B260_66254DCD8644__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

enum SportMode
{
	YunSu, YunJiaSu, ZhengXian
};

enum DrawCurveFlag
{
	WeiYi, SuDu, JiaSuDu
};


typedef struct
{
	float x;  //����
	float w;  //���
	float v;  //�ٶ�
	float a;  //���ٶ�

	float kp, ki, kd;
	float error;        //���
	float preerror;     //�ϴ����
	float jfx;          //������
	float wfx;          //΢����

	float xGJ[500], vGJ[500], aGJ[500];
	int nxGJ, nvGJ, naGJ;
}SCar;

class CControl  
{
public:
	void DrawGJ();
	void DrawCoordinateAxis(int X, int Y, float Max, float k, CString name);
	void DrawCurve(int X, int Y, float arr[], int n, float k);
	void MoveKZ_A();
	void MoveKZ_V();
	void MoveKZ_X();
	void initMove();
	void DrawCar();
	void Draw(CDC *p);
	void MoveKZ();
	void MoveMB();
	CControl();
	virtual ~CControl();

	CDC *pDC;
	float m_deltaT;

	SCar m_CarMB;
	SCar m_CarKZX, m_CarKZV, m_CarKZA;

	CPoint m_YD;
	float m_kx, m_ky;

	int m_mode; //Ŀ��С���˶�ģʽ
	float m_t;

	float m_CDXL; //����Ч��

	int m_bjCurveDraw;
};

#endif // !defined(AFX_CONTROL_H__0581C30E_FC42_4043_B260_66254DCD8644__INCLUDED_)
