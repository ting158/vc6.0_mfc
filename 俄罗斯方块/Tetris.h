// Tetris.h: interface for the CTetris class.
//
//////////////////////////////////////////////////////////////////////

#include "time.h"

#if !defined(AFX_TETRIS_H__FD57DFDE_BC4F_44BE_9B9E_FFBCBAFA7BBF__INCLUDED_)
#define AFX_TETRIS_H__FD57DFDE_BC4F_44BE_9B9E_FFBCBAFA7BBF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define Size 30  //С����ı߳�

/*
����ά���鶨�巽��
Ϊ�˷����д����ÿ�ַ��鶼����Ϊ4������
4 * 4 ��������Ի����κη����״̬
*/

//��Ϸ���ߴ�Ϊ 25 * 15

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
	int map_Y;  //��ͼ���Ͻ�����
	int m_Block[28][4][4];  //ÿ�ַ���͸�����������з���
	int m_map[30][15]; //�Ѿ�����ķ���
	int m_nowid; //Ŀǰ�ķ���
	int m_nextid; //��һ������
	int m_score; //�÷�
};

#endif // !defined(AFX_TETRIS_H__FD57DFDE_BC4F_44BE_9B9E_FFBCBAFA7BBF__INCLUDED_)
