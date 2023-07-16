// DianJi.h: interface for the CDianJi class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DIANJI_H__75834190_10AD_4585_ADFA_A3EB15C752BA__INCLUDED_)
#define AFX_DIANJI_H__75834190_10AD_4585_ADFA_A3EB15C752BA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CDianJi  
{
public:
	int Move();
	void DrawControlP(CDC *pDC);
	void DrawCoordP(CDC *pDC);
	void DrawReverseClark(CDC *pDC);
	void DrawReversePark(CDC *pDC);
	void DrawThree(CDC *pDC);
	void DrawCoordParkReverse(CDC *pDC);
	void DrawCoordClarkReverse(CDC *pDC);
	void DrawCoordPark(CDC *pDC);
	void DrawLine(CDC *pDC,CPoint p1,CPoint p2);
	void DrawCoordClark(CDC *pDC);
	void DrawCoord(CDC *pDC);
	void DrawIDIQ(CDC *pDC);
	void DrawIAIB(CDC *pDC);
	void Draw(CDC *pDC);
	CDianJi();
	virtual ~CDianJi();

	float m_k;
	float m_A[5000],m_B[5000],m_D[5000],m_Q[5000];
	float m_A_Reverse[5000],m_B_Reverse[5000];

	float m_a[2000],m_b[2000],m_c[2000];
	float m_a_Reverse[5000],m_b_Reverse[5000],m_c_Reverse[5000];

	CPoint m_YD,m_YD_Clark,m_YD_Park;
	CPoint m_YD_Clark_Reverse,m_YD_Park_Reverse;
	CPoint m_YD_P;

	int m_t;

	/**************************/
	int m_P0;
	float m_P[5000];

	float m_kp;

	float m_r,m_r0;

	bool m_flag;

};

#endif // !defined(AFX_DIANJI_H__75834190_10AD_4585_ADFA_A3EB15C752BA__INCLUDED_)
