// WuZiQi.h: interface for the CWuZiQi class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WUZIQI_H__BA2BB1A3_9A7C_4758_A731_82F69F6D03A5__INCLUDED_)
#define AFX_WUZIQI_H__BA2BB1A3_9A7C_4758_A731_82F69F6D03A5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CWuZiQi  
{
public:
	void InitQiPan();
	void DrawBackground();
	void PanDuan();
	void XiaQi(CPoint pt);
	void Draw(CDC *pDC);
	void DrawQiZi();
	void DrawQiPan();
	CWuZiQi();
	virtual ~CWuZiQi();

	//��Ա����
	int m_Qp[19][19]; //���̹��Ϊ 19 * 19
	int m_H, m_L; //����λ��
	int m_Color;  //������ɫ��0Ϊ�����ӣ�1Ϊ���壬2Ϊ����
	int m_Size; //С����ߴ�
	int m_initX, m_initY; //����ԭ�����꣬���Ͻ�
	CDC *pDC;  //��ͼ
};

#endif // !defined(AFX_WUZIQI_H__BA2BB1A3_9A7C_4758_A731_82F69F6D03A5__INCLUDED_)
