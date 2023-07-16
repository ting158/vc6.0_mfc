// Tetris.h: interface for the CTetris class.
//
//////////////////////////////////////////////////////////////////////

#include "time.h"

#if !defined(AFX_TETRIS_H__FD57DFDE_BC4F_44BE_9B9E_FFBCBAFA7BBF__INCLUDED_)
#define AFX_TETRIS_H__FD57DFDE_BC4F_44BE_9B9E_FFBCBAFA7BBF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define Size 30  //小方块的边长

/*
用三维数组定义方块
为了方便编写，将每种方块都设置为4个方向
4 * 4 的数组可以画出任何方块的状态
*/

//游戏区尺寸为 25 * 15

class CTetris  
{
public:
	void GameInit();
	int isOver();
	void DropDown();
	int isokChange();
	int isToRight(int id);
	int isToLeft(int id);
	void Clear();
	void Change();
	void AddToMap();
	void UpdateBlock();
	int isDown();
	void Drop();
	void DrawNext(CDC *pDC);
	void DrawNow(CDC *pDC);
	void CreateBlock(int &id);
	void DrawMap(CDC *pDC);
	void DrawBackground(CDC *pDC);
	CTetris();
	virtual ~CTetris();

	CDC *pDC;
	int map_X;
	int map_Y;  //地图左上角坐标
	int m_Block[28][4][4];  //每种方块和各个方块的所有方向
	int m_map[30][15]; //已经下落的方块
	int m_nowid; //目前的方块
	int m_nextid; //下一个方块
	int m_score; //得分
};

#endif // !defined(AFX_TETRIS_H__FD57DFDE_BC4F_44BE_9B9E_FFBCBAFA7BBF__INCLUDED_)
