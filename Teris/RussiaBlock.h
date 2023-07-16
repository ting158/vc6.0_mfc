// RussiaBlock.h: interface for the CRussiaBlock class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RUSSIABLOCK_H__5F278F51_D3F9_489A_B870_EC34B844980D__INCLUDED_)
#define AFX_RUSSIABLOCK_H__5F278F51_D3F9_489A_B870_EC34B844980D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define Max 20
typedef struct {
	POINT p1, p2, p3, p4, p;  //方块用的点
	int dir;  //方向
	int type;  //第几种类型
}MyBlock;

class CRussiaBlock  
{
public:
	void PanDuanDeFen();
	void JuLiDian();
	void Move();
	void KeyMove(int n);
	int Touch();
	int PengBi();
	void Change();
	void CreateBlock();
	void DrawBlock();
	void DrawArea();
	void Draw(CDC *pDC);
	CRussiaBlock();
	virtual ~CRussiaBlock();


	CDC *pDC;
	MyBlock m_Block;
	POINT begPos, endPos; //游戏区的左上右下坐标
	int m_s, m_r, m_cret, m_key, m_score;
	int flag1, flag2; //用于旋转
	int FK[Max][Max];  //方块数组
};

#endif // !defined(AFX_RUSSIABLOCK_H__5F278F51_D3F9_489A_B870_EC34B844980D__INCLUDED_)
