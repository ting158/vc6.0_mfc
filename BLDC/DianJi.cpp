// DianJi.cpp: implementation of the CDianJi class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "BLDC.h"
#include "DianJi.h"
#include "math.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#define Pi 3.1415926
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDianJi::CDianJi()
{
	m_k = 90;

	m_YD.x = 150;
	m_YD.y = 200;

	m_YD_P.x = 800;
	m_YD_P.y = 200;

	m_YD_Clark.x = 150;
	m_YD_Clark.y = 400;

	m_YD_Park.x = 150;
	m_YD_Park.y = 600;

	m_YD_Clark_Reverse.x = 800;
	m_YD_Clark_Reverse.y = 400;

	m_YD_Park_Reverse.x = 800;
	m_YD_Park_Reverse.y = 600;

	m_t = 0;

	m_kp = 0.3;
	m_P[0] = 0;

	m_r  = 3000;
	m_r0 = 3000;
	m_flag = false;
}

CDianJi::~CDianJi()
{

}

void CDianJi::Draw(CDC *pDC)
{
	DrawCoord(pDC);
	DrawThree(pDC);    //三相电流
	DrawCoordClark(pDC);
	DrawCoordClarkReverse(pDC);
	DrawCoordPark(pDC);
	DrawCoordParkReverse(pDC);
	DrawIAIB(pDC);    //经过Clark变换后得到α，β轴，这里是用IAIB表示
	DrawIDIQ(pDC);    //经过Park变换将α，β轴转化为d，q轴
	DrawReversePark(pDC);
	DrawReverseClark(pDC);
	DrawCoordP(pDC);
	DrawControlP(pDC);   //变速调节
}

//Clark变换的曲线
void CDianJi::DrawIAIB(CDC *pDC)
{
	CString str;
	int i;
	CPoint curP,nextP;
	for(i = 0;i<m_t;i++)
	{
		curP.x = i + m_YD_Clark.x;
		curP.y = m_YD_Clark.y + m_A[i];
		nextP.x = i + 1 + m_YD_Clark.x;
		nextP.y = m_YD_Clark.y + m_A[i+1];
		DrawLine(pDC,curP,nextP);

		curP.x = i + m_YD_Clark.x;
		curP.y = m_YD_Clark.y + m_B[i];
		nextP.x = i + 1 + m_YD_Clark.x;
		nextP.y = m_YD_Clark.y + m_B[i+1];
		DrawLine(pDC,curP,nextP);
		
		if(i%60 == 0)
		{
			str.Format("%d",i);
			pDC->TextOut(m_YD_Clark.x+i,m_YD_Clark.y+5,str);
		}
	}

}

void CDianJi::DrawIDIQ(CDC *pDC)
{
	int i;
	CString str;
	CPoint curP,nextP;	
	for(i = 0;i<m_t;i++)
	{
		curP.x = i + m_YD_Park.x;
		curP.y = m_YD_Park.y + m_D[i];
		nextP.x = i + 1 + m_YD_Park.x;
		nextP.y = m_YD_Park.y + m_D[i+1];
		DrawLine(pDC,curP,nextP);

		curP.x = i + m_YD_Park.x;
		curP.y = m_YD_Park.y + m_Q[i];
		nextP.x = i + 1 + m_YD_Park.x;
		nextP.y = m_YD_Park.y + m_Q[i+1];
		DrawLine(pDC,curP,nextP);

		if(i%60 == 0)
		{
			str.Format("%d",i);
			pDC->TextOut(m_YD_Park.x+i,m_YD_Park.y+5,str);
		}
	}
}

void CDianJi::DrawCoord(CDC *pDC)
{
	CString str;
	pDC->MoveTo(m_YD.x-500,m_YD.y);
	pDC->LineTo(m_YD.x+500,m_YD.y);
	pDC->MoveTo(m_YD.x,m_YD.y-300);
	pDC->LineTo(m_YD.x,m_YD.y+300);
	str.Format("三相电流a,b,c");
	pDC->TextOut(m_YD.x-120,m_YD.y-50,str);
}

void CDianJi::DrawCoordClark(CDC *pDC)
{
	pDC->MoveTo(m_YD_Clark.x-500,m_YD_Clark.y);
	pDC->LineTo(m_YD_Clark.x+500,m_YD_Clark.y);
	pDC->MoveTo(m_YD_Clark.x,m_YD_Clark.y-300);
	pDC->LineTo(m_YD_Clark.x,m_YD_Clark.y+300);
	CString str;
	str.Format("Clark变换");
	pDC->TextOut(m_YD_Clark.x-120,m_YD_Clark.y-50,str);
}

void CDianJi::DrawLine(CDC *pDC, CPoint p1, CPoint p2)
{
	pDC->MoveTo(p1.x,p1.y);
	pDC->LineTo(p2.x,p2.y);	
}

void CDianJi::DrawCoordPark(CDC *pDC)
{
	pDC->MoveTo(m_YD_Park.x-500,m_YD_Park.y);
	pDC->LineTo(m_YD_Park.x+500,m_YD_Park.y);
	pDC->MoveTo(m_YD_Park.x,m_YD_Park.y-300);
	pDC->LineTo(m_YD_Park.x,m_YD_Park.y+300);
	CString str;
	str.Format("Park变换");
	pDC->TextOut(m_YD_Park.x-120,m_YD_Park.y-50,str);
}

void CDianJi::DrawCoordClarkReverse(CDC *pDC)
{
	pDC->MoveTo(m_YD_Clark_Reverse.x-500,m_YD_Clark_Reverse.y);
	pDC->LineTo(m_YD_Clark_Reverse.x+500,m_YD_Clark_Reverse.y);
	pDC->MoveTo(m_YD_Clark_Reverse.x,m_YD_Clark_Reverse.y-200);
	pDC->LineTo(m_YD_Clark_Reverse.x,m_YD_Clark_Reverse.y+200);
	CString str;
	str.Format("Reverse_Clark变换");
	pDC->TextOut(m_YD_Clark_Reverse.x-150,m_YD_Clark_Reverse.y-50,str);
}

void CDianJi::DrawCoordParkReverse(CDC *pDC)
{
	pDC->MoveTo(m_YD_Park_Reverse.x-500,m_YD_Park_Reverse.y);
	pDC->LineTo(m_YD_Park_Reverse.x+500,m_YD_Park_Reverse.y);
	pDC->MoveTo(m_YD_Park_Reverse.x,m_YD_Park_Reverse.y-300);
	pDC->LineTo(m_YD_Park_Reverse.x,m_YD_Park_Reverse.y+300);
	CString str;
	str.Format("Reverse_Park变换");
	pDC->TextOut(m_YD_Park_Reverse.x-150,m_YD_Park_Reverse.y-50,str);
}

void CDianJi::DrawThree(CDC *pDC)
{
	CString str;
	int i;
	CPoint curP,nextP;
	for(i = 0;i<m_t;i++)
	{
		curP.x = i + m_YD.x;
		curP.y = m_YD.y + m_a[i];
		nextP.x = i + 1 + m_YD.x;
		nextP.y = m_YD.y + m_a[i+1];		
		DrawLine(pDC,curP,nextP);

		curP.x = i + m_YD.x;
		curP.y = m_YD.y + m_b[i];
		nextP.x = i + 1 + m_YD.x;
		nextP.y = m_YD.y + m_b[i+1];
		DrawLine(pDC,curP,nextP);

		curP.x = i + m_YD.x;
		curP.y = m_c[i] + m_YD.y;
		nextP.x = i + 1 + m_YD.x;
		nextP.y = m_c[i+1] + m_YD.y;
		DrawLine(pDC,curP,nextP);

		if(i%60 == 0)
		{
			str.Format("%d",i);
			pDC->TextOut(m_YD.x+i,m_YD.y+5,str);
		}
	}
}

void CDianJi::DrawReversePark(CDC *pDC)
{
	CString str;
	int i;
	CPoint curP,nextP;
	for(i = 0;i<m_t;i++)
	{
		curP.x = i + m_YD_Park_Reverse.x;
		curP.y = m_YD_Park_Reverse.y + m_A_Reverse[i];
		nextP.x = i + 1 + m_YD_Park_Reverse.x;
		nextP.y = m_YD_Park_Reverse.y + m_A_Reverse[i+1];
		DrawLine(pDC,curP,nextP);

		curP.x = i + m_YD_Park_Reverse.x;
		curP.y = m_YD_Park_Reverse.y + m_B_Reverse[i];
		nextP.x = i + 1 + m_YD_Park_Reverse.x;
		nextP.y = m_YD_Park_Reverse.y + m_B_Reverse[i+1];
		DrawLine(pDC,curP,nextP);

		if(i%60 == 0)
		{
			str.Format("%d",i);
			pDC->TextOut(m_YD_Park_Reverse.x+i,m_YD_Park_Reverse.y+5,str);
		}
	}
}

void CDianJi::DrawReverseClark(CDC *pDC)
{
	CString str;
	int i;
	CPoint curP,nextP;
	for(i = 0;i<m_t;i++)
	{
		curP.x = i + m_YD_Clark_Reverse.x;
		curP.y = m_YD_Clark_Reverse.y + m_a_Reverse[i];
		nextP.x = i + 1 + m_YD_Clark_Reverse.x;
		nextP.y = m_YD_Clark_Reverse.y + m_a_Reverse[i+1];
		DrawLine(pDC,curP,nextP);

		curP.x = i + m_YD_Clark_Reverse.x;
		curP.y = m_YD_Clark_Reverse.y + m_b_Reverse[i];
		nextP.x = i + 1 + m_YD_Clark_Reverse.x;
		nextP.y = m_YD_Clark_Reverse.y + m_b_Reverse[i+1];
		DrawLine(pDC,curP,nextP);

		curP.x = i + m_YD_Clark_Reverse.x;
		curP.y = m_YD_Clark_Reverse.y + m_c_Reverse[i];
		nextP.x = i + 1 + m_YD_Clark_Reverse.x;
		nextP.y = m_YD_Clark_Reverse.y + m_c_Reverse[i+1];
		DrawLine(pDC,curP,nextP);

		if(i%60 == 0)
		{
			str.Format("%d",i);
			pDC->TextOut(m_YD_Clark_Reverse.x+i,m_YD_Clark_Reverse.y+5,str);
		}
	}
}

void CDianJi::DrawCoordP(CDC *pDC)
{
	pDC->MoveTo(m_YD_P.x-500,m_YD_P.y);
	pDC->LineTo(m_YD_P.x+500,m_YD_P.y);
	pDC->MoveTo(m_YD_P.x,m_YD_P.y-300);
	pDC->LineTo(m_YD_P.x,m_YD_P.y+300);
	CString str;
	str.Format("变速调节");
	pDC->TextOut(m_YD_P.x-120,m_YD_P.y-50,str);
}

void CDianJi::DrawControlP(CDC *pDC)
{
	CString str;
	int i;
	CPoint curP,nextP;
	for(i = 0;i<m_t;i++)
	{
		curP.x = i + m_YD_P.x;
		curP.y = m_YD_P.y - m_P[i];
		nextP.x = i + 1 + m_YD_P.x;
		nextP.y = m_YD_P.y - m_P[i+1];
		DrawLine(pDC,curP,nextP);

		if(i%60 == 0)
		{
			str.Format("%d",i);
			pDC->TextOut(m_YD_P.x+i,m_YD_P.y+5,str);
		}
	}
}

int CDianJi::Move()
{
	m_a[m_t] = m_k * sin(m_t/180.0*Pi);
	m_b[m_t] = m_k * sin((m_t+120)/180.0*Pi);
	m_c[m_t] = -m_a[m_t] - m_b[m_t];

	m_A[m_t] = m_a[m_t];
	m_B[m_t] = 1/pow(3,0.5)*(m_a[m_t] + 2*m_b[m_t]);

	m_D[m_t] = m_A[m_t]*cos((360-m_t)/180.0*Pi) + m_B[m_t]*sin((360-m_t)/180.0*Pi);
	m_Q[m_t] = -m_A[m_t]*sin((360-m_t)/180.0*Pi) + m_B[m_t]*cos((360-m_t)/180.0*Pi);
	
	m_A_Reverse[m_t] = m_D[m_t]*cos((360-m_t)/180.0*Pi) - m_Q[m_t]*sin((360-m_t)/180.0*Pi);
	m_B_Reverse[m_t] = m_D[m_t]*sin((360-m_t)/180.0*Pi) + m_Q[m_t]*cos((360-m_t)/180.0*Pi);

	m_a_Reverse[m_t] = m_A_Reverse[m_t];
	m_b_Reverse[m_t] = -0.5 * m_A_Reverse[m_t] + pow(3,0.5)/2 * m_B_Reverse[m_t];
	m_c_Reverse[m_t] = -0.5 * m_A_Reverse[m_t] - pow(3,0.5)/2 * m_B_Reverse[m_t];

	m_P[m_t+1] = m_P[m_t] + (m_k*(m_r/m_r0)-m_P[m_t])*m_kp;

	m_t ++;

	if(fabs(m_P[m_t]-m_k) == 5)
		return 1;

	if(m_t<=361)
	{
		m_flag = true;
		return 1;
	}
	else
	{
		m_flag = false;
	}
	return 0;
}
