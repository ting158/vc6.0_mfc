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

	//成员变量
	int m_Qp[19][19]; //棋盘规格为 19 * 19
	int m_H, m_L; //落子位置
	int m_Color;  //棋子颜色，0为无棋子，1为白棋，2为黑棋
	int m_Size; //小方格尺寸
	int m_initX, m_initY; //棋盘原点坐标，左上角
	CDC *pDC;  //画图
};

#endif // !defined(AFX_WUZIQI_H__BA2BB1A3_9A7C_4758_A731_82F69F6D03A5__INCLUDED_)
