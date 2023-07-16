// Tetris.cpp: implementation of the CTetris class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "俄罗斯方块.h"
#include "Tetris.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTetris::CTetris()
{
	GameInit();




	m_Block[0][0][0] = 0; m_Block[0][0][1] = 1; m_Block[0][0][2] = 1; m_Block[0][0][3] = 0;  //■■
	m_Block[0][1][0] = 0; m_Block[0][1][1] = 1; m_Block[0][1][2] = 1; m_Block[0][1][3] = 0;  //■■
	m_Block[0][2][0] = 0; m_Block[0][2][1] = 0; m_Block[0][2][2] = 0; m_Block[0][2][3] = 0;
	m_Block[0][3][0] = 0; m_Block[0][3][1] = 0; m_Block[0][3][2] = 0; m_Block[0][3][3] = 0;
	m_Block[1][0][0] = 0; m_Block[1][0][1] = 1; m_Block[1][0][2] = 1; m_Block[1][0][3] = 0;  //■■
	m_Block[1][1][0] = 0; m_Block[1][1][1] = 1; m_Block[1][1][2] = 1; m_Block[1][1][3] = 0;  //■■
	m_Block[1][2][0] = 0; m_Block[1][2][1] = 0; m_Block[1][2][2] = 0; m_Block[1][2][3] = 0;
	m_Block[1][3][0] = 0; m_Block[1][3][1] = 0; m_Block[1][3][2] = 0; m_Block[1][3][3] = 0;
	m_Block[2][0][0] = 0; m_Block[2][0][1] = 1; m_Block[2][0][2] = 1; m_Block[2][0][3] = 0;  //■■
	m_Block[2][1][0] = 0; m_Block[2][1][1] = 1; m_Block[2][1][2] = 1; m_Block[2][1][3] = 0;  //■■
	m_Block[2][2][0] = 0; m_Block[2][2][1] = 0; m_Block[2][2][2] = 0; m_Block[2][2][3] = 0;
	m_Block[2][3][0] = 0; m_Block[2][3][1] = 0; m_Block[2][3][2] = 0; m_Block[2][3][3] = 0;
	m_Block[3][0][0] = 0; m_Block[3][0][1] = 1; m_Block[3][0][2] = 1; m_Block[3][0][3] = 0;  //■■
	m_Block[3][1][0] = 0; m_Block[3][1][1] = 1; m_Block[3][1][2] = 1; m_Block[3][1][3] = 0;  //■■
	m_Block[3][2][0] = 0; m_Block[3][2][1] = 0; m_Block[3][2][2] = 0; m_Block[3][2][3] = 0;
	m_Block[3][3][0] = 0; m_Block[3][3][1] = 0; m_Block[3][3][2] = 0; m_Block[3][3][3] = 0;

	m_Block[4][0][0] = 1; m_Block[4][0][1] = 1; m_Block[4][0][2] = 1; m_Block[4][0][3] = 1;  
	m_Block[4][1][0] = 0; m_Block[4][1][1] = 0; m_Block[4][1][2] = 0; m_Block[4][1][3] = 9;  //■■■■
	m_Block[4][2][0] = 0; m_Block[4][2][1] = 0; m_Block[4][2][2] = 0; m_Block[4][2][3] = 0;  
	m_Block[4][3][0] = 0; m_Block[4][3][1] = 0; m_Block[4][3][2] = 0; m_Block[4][3][3] = 0;  
	m_Block[5][0][0] = 0; m_Block[5][0][1] = 1; m_Block[5][0][2] = 0; m_Block[5][0][3] = 0;  //■
	m_Block[5][1][0] = 0; m_Block[5][1][1] = 1; m_Block[5][1][2] = 0; m_Block[5][1][3] = 0;  //■
	m_Block[5][2][0] = 0; m_Block[5][2][1] = 1; m_Block[5][2][2] = 0; m_Block[5][2][3] = 0;  //■
	m_Block[5][3][0] = 0; m_Block[5][3][1] = 1; m_Block[5][3][2] = 0; m_Block[5][3][3] = 0;  //■
	m_Block[6][0][0] = 1; m_Block[6][0][1] = 1; m_Block[6][0][2] = 1; m_Block[6][0][3] = 1;  
	m_Block[6][1][0] = 0; m_Block[6][1][1] = 0; m_Block[6][1][2] = 0; m_Block[6][1][3] = 0;  //■■■■
	m_Block[6][2][0] = 0; m_Block[6][2][1] = 0; m_Block[6][2][2] = 0; m_Block[6][2][3] = 0;  
	m_Block[6][3][0] = 0; m_Block[6][3][1] = 0; m_Block[6][3][2] = 0; m_Block[6][3][3] = 0;  
	m_Block[7][0][0] = 0; m_Block[7][0][1] = 1; m_Block[7][0][2] = 0; m_Block[7][0][3] = 0;  //■
	m_Block[7][1][0] = 0; m_Block[7][1][1] = 1; m_Block[7][1][2] = 0; m_Block[7][1][3] = 0;  //■
	m_Block[7][2][0] = 0; m_Block[7][2][1] = 1; m_Block[7][2][2] = 0; m_Block[7][2][3] = 0;  //■
	m_Block[7][3][0] = 0; m_Block[7][3][1] = 1; m_Block[7][3][2] = 0; m_Block[7][3][3] = 0;  //■

	m_Block[8][0][0] = 0; m_Block[8][0][1] = 1; m_Block[8][0][2] = 1; m_Block[8][0][3] = 0;  //■■
	m_Block[8][1][0] = 0; m_Block[8][1][1] = 0; m_Block[8][1][2] = 1; m_Block[8][1][3] = 1;  //  ■■
	m_Block[8][2][0] = 0; m_Block[8][2][1] = 0; m_Block[8][2][2] = 0; m_Block[8][2][3] = 0;
	m_Block[8][3][0] = 0; m_Block[8][3][1] = 0; m_Block[8][3][2] = 0; m_Block[8][3][3] = 0;
	m_Block[9][0][0] = 0; m_Block[9][0][1] = 0; m_Block[9][0][2] = 0; m_Block[9][0][3] = 1;  //  ■
	m_Block[9][1][0] = 0; m_Block[9][1][1] = 0; m_Block[9][1][2] = 1; m_Block[9][1][3] = 1;  //■■
	m_Block[9][2][0] = 0; m_Block[9][2][1] = 0; m_Block[9][2][2] = 1; m_Block[9][2][3] = 0;  //■
	m_Block[9][3][0] = 0; m_Block[9][3][1] = 0; m_Block[9][3][2] = 0; m_Block[9][3][3] = 0;
	m_Block[10][0][0] = 0; m_Block[10][0][1] = 1; m_Block[10][0][2] = 1; m_Block[10][0][3] = 0;  //■■
	m_Block[10][1][0] = 0; m_Block[10][1][1] = 0; m_Block[10][1][2] = 1; m_Block[10][1][3] = 1;  //  ■■
	m_Block[10][2][0] = 0; m_Block[10][2][1] = 0; m_Block[10][2][2] = 0; m_Block[10][2][3] = 0;
	m_Block[10][3][0] = 0; m_Block[10][3][1] = 0; m_Block[10][3][2] = 0; m_Block[10][3][3] = 0;
	m_Block[11][0][0] = 0; m_Block[11][0][1] = 0; m_Block[11][0][2] = 0; m_Block[11][0][3] = 1;  //  ■
	m_Block[11][1][0] = 0; m_Block[11][1][1] = 0; m_Block[11][1][2] = 1; m_Block[11][1][3] = 1;  //■■
	m_Block[11][2][0] = 0; m_Block[11][2][1] = 0; m_Block[11][2][2] = 1; m_Block[11][2][3] = 0;  //■
	m_Block[11][3][0] = 0; m_Block[11][3][1] = 0; m_Block[11][3][2] = 0; m_Block[11][3][3] = 0;

	m_Block[12][0][0] = 0; m_Block[12][0][1] = 0; m_Block[12][0][2] = 1; m_Block[12][0][3] = 1;  //  ■■
	m_Block[12][1][0] = 0; m_Block[12][1][1] = 1; m_Block[12][1][2] = 1; m_Block[12][1][3] = 0;  //■■
	m_Block[12][2][0] = 0; m_Block[12][2][1] = 0; m_Block[12][2][2] = 0; m_Block[12][2][3] = 0;
	m_Block[12][3][0] = 0; m_Block[12][3][1] = 0; m_Block[12][3][2] = 0; m_Block[12][3][3] = 0;
	m_Block[13][0][0] = 0; m_Block[13][0][1] = 1; m_Block[13][0][2] = 0; m_Block[13][0][3] = 0;  //■
	m_Block[13][1][0] = 0; m_Block[13][1][1] = 1; m_Block[13][1][2] = 1; m_Block[13][1][3] = 0;  //■■
	m_Block[13][2][0] = 0; m_Block[13][2][1] = 0; m_Block[13][2][2] = 1; m_Block[13][2][3] = 0;  //  ■
	m_Block[13][3][0] = 0; m_Block[13][3][1] = 0; m_Block[13][3][2] = 0; m_Block[13][3][3] = 0;
	m_Block[14][0][0] = 0; m_Block[14][0][1] = 0; m_Block[14][0][2] = 1; m_Block[14][0][3] = 1;  //  ■■
	m_Block[14][1][0] = 0; m_Block[14][1][1] = 1; m_Block[14][1][2] = 1; m_Block[14][1][3] = 0;  //■■
	m_Block[14][2][0] = 0; m_Block[14][2][1] = 0; m_Block[14][2][2] = 0; m_Block[14][2][3] = 0;
	m_Block[14][3][0] = 0; m_Block[14][3][1] = 0; m_Block[14][3][2] = 0; m_Block[14][3][3] = 0;
	m_Block[15][0][0] = 0; m_Block[15][0][1] = 1; m_Block[15][0][2] = 0; m_Block[15][0][3] = 0;  //■
	m_Block[15][1][0] = 0; m_Block[15][1][1] = 1; m_Block[15][1][2] = 1; m_Block[15][1][3] = 0;  //■■
	m_Block[15][2][0] = 0; m_Block[15][2][1] = 0; m_Block[15][2][2] = 1; m_Block[15][2][3] = 0;  //  ■
	m_Block[15][3][0] = 0; m_Block[15][3][1] = 0; m_Block[15][3][2] = 0; m_Block[15][3][3] = 0;

	m_Block[16][0][0] = 0; m_Block[16][0][1] = 0; m_Block[16][0][2] = 0; m_Block[16][0][3] = 1;  //    ■
	m_Block[16][1][0] = 0; m_Block[16][1][1] = 1; m_Block[16][1][2] = 1; m_Block[16][1][3] = 1;  //■■■
	m_Block[16][2][0] = 0; m_Block[16][2][1] = 0; m_Block[16][2][2] = 0; m_Block[16][2][3] = 0;
	m_Block[16][3][0] = 0; m_Block[16][3][1] = 0; m_Block[16][3][2] = 0; m_Block[16][3][3] = 0;
	m_Block[17][0][0] = 0; m_Block[17][0][1] = 0; m_Block[17][0][2] = 1; m_Block[17][0][3] = 0;  //■
	m_Block[17][1][0] = 0; m_Block[17][1][1] = 0; m_Block[17][1][2] = 1; m_Block[17][1][3] = 0;  //■
	m_Block[17][2][0] = 0; m_Block[17][2][1] = 0; m_Block[17][2][2] = 1; m_Block[17][2][3] = 1;  //■■
	m_Block[17][3][0] = 0; m_Block[17][3][1] = 0; m_Block[17][3][2] = 0; m_Block[17][3][3] = 0;
	m_Block[18][0][0] = 0; m_Block[18][0][1] = 1; m_Block[18][0][2] = 1; m_Block[18][0][3] = 1;  //■■■
	m_Block[18][1][0] = 0; m_Block[18][1][1] = 1; m_Block[18][1][2] = 0; m_Block[18][1][3] = 0;  //■
	m_Block[18][2][0] = 0; m_Block[18][2][1] = 0; m_Block[18][2][2] = 0; m_Block[18][2][3] = 0;
	m_Block[18][3][0] = 0; m_Block[18][3][1] = 0; m_Block[18][3][2] = 0; m_Block[18][3][3] = 0;
	m_Block[19][0][0] = 0; m_Block[19][0][1] = 1; m_Block[19][0][2] = 1; m_Block[19][0][3] = 0;  //■■
	m_Block[19][1][0] = 0; m_Block[19][1][1] = 0; m_Block[19][1][2] = 1; m_Block[19][1][3] = 0;  //  ■
	m_Block[19][2][0] = 0; m_Block[19][2][1] = 0; m_Block[19][2][2] = 1; m_Block[19][2][3] = 0;  //  ■
	m_Block[19][3][0] = 0; m_Block[19][3][1] = 0; m_Block[19][3][2] = 0; m_Block[19][3][3] = 0;

	m_Block[20][0][0] = 0; m_Block[20][0][1] = 1; m_Block[20][0][2] = 0; m_Block[20][0][3] = 0;  //■
	m_Block[20][1][0] = 0; m_Block[20][1][1] = 1; m_Block[20][1][2] = 1; m_Block[20][1][3] = 1;  //■■■
	m_Block[20][2][0] = 0; m_Block[20][2][1] = 0; m_Block[20][2][2] = 0; m_Block[20][2][3] = 0;
	m_Block[20][3][0] = 0; m_Block[20][3][1] = 0; m_Block[20][3][2] = 0; m_Block[20][3][3] = 0;
	m_Block[21][0][0] = 0; m_Block[21][0][1] = 0; m_Block[21][0][2] = 1; m_Block[21][0][3] = 1;  //■■
	m_Block[21][1][0] = 0; m_Block[21][1][1] = 0; m_Block[21][1][2] = 1; m_Block[21][1][3] = 0;  //■
	m_Block[21][2][0] = 0; m_Block[21][2][1] = 0; m_Block[21][2][2] = 1; m_Block[21][2][3] = 0;  //■
	m_Block[21][3][0] = 0; m_Block[21][3][1] = 0; m_Block[21][3][2] = 0; m_Block[21][3][3] = 0;
	m_Block[22][0][0] = 0; m_Block[22][0][1] = 1; m_Block[22][0][2] = 1; m_Block[22][0][3] = 1;  //■■■
	m_Block[22][1][0] = 0; m_Block[22][1][1] = 0; m_Block[22][1][2] = 0; m_Block[22][1][3] = 1;  //    ■
	m_Block[22][2][0] = 0; m_Block[22][2][1] = 0; m_Block[22][2][2] = 0; m_Block[22][2][3] = 0;
	m_Block[22][3][0] = 0; m_Block[22][3][1] = 0; m_Block[22][3][2] = 0; m_Block[22][3][3] = 0;
	m_Block[23][0][0] = 0; m_Block[23][0][1] = 0; m_Block[23][0][2] = 0; m_Block[23][0][3] = 1;  //■■
	m_Block[23][1][0] = 0; m_Block[23][1][1] = 0; m_Block[23][1][2] = 0; m_Block[23][1][3] = 1;  //  ■
	m_Block[23][2][0] = 0; m_Block[23][2][1] = 0; m_Block[23][2][2] = 1; m_Block[23][2][3] = 1;  //  ■
	m_Block[23][3][0] = 0; m_Block[23][3][1] = 0; m_Block[23][3][2] = 0; m_Block[23][3][3] = 0;

	m_Block[24][0][0] = 0; m_Block[24][0][1] = 1; m_Block[24][0][2] = 0; m_Block[24][0][3] = 0;  //  ■
	m_Block[24][1][0] = 1; m_Block[24][1][1] = 1; m_Block[24][1][2] = 1; m_Block[24][1][3] = 0;  //■■■
	m_Block[24][2][0] = 0; m_Block[24][2][1] = 0; m_Block[24][2][2] = 0; m_Block[24][2][3] = 0;
	m_Block[24][3][0] = 0; m_Block[24][3][1] = 0; m_Block[24][3][2] = 0; m_Block[24][3][3] = 0;
	m_Block[25][0][0] = 0; m_Block[25][0][1] = 1; m_Block[25][0][2] = 0; m_Block[25][0][3] = 0;  //■
	m_Block[25][1][0] = 0; m_Block[25][1][1] = 1; m_Block[25][1][2] = 1; m_Block[25][1][3] = 0;  //■■
	m_Block[25][2][0] = 0; m_Block[25][2][1] = 1; m_Block[25][2][2] = 0; m_Block[25][2][3] = 0;  //■
	m_Block[25][3][0] = 0; m_Block[25][3][1] = 0; m_Block[25][3][2] = 0; m_Block[25][3][3] = 0;
	m_Block[26][0][0] = 1; m_Block[26][0][1] = 1; m_Block[26][0][2] = 1; m_Block[26][0][3] = 0;  //■■■
	m_Block[26][1][0] = 0; m_Block[26][1][1] = 1; m_Block[26][1][2] = 0; m_Block[26][1][3] = 0;  //  ■
	m_Block[26][2][0] = 0; m_Block[26][2][1] = 0; m_Block[26][2][2] = 0; m_Block[26][2][3] = 0;
	m_Block[26][3][0] = 0; m_Block[26][3][1] = 0; m_Block[26][3][2] = 0; m_Block[26][3][3] = 0;
	m_Block[27][0][0] = 0; m_Block[27][0][1] = 1; m_Block[27][0][2] = 0; m_Block[27][0][3] = 0;  //  ■
	m_Block[27][1][0] = 1; m_Block[27][1][1] = 1; m_Block[27][1][2] = 0; m_Block[27][1][3] = 0;  //■■
	m_Block[27][2][0] = 0; m_Block[27][2][1] = 1; m_Block[27][2][2] = 0; m_Block[27][2][3] = 0;  //  ■
	m_Block[27][3][0] = 0; m_Block[27][3][1] = 0; m_Block[27][3][2] = 0; m_Block[27][3][3] = 0;
}

CTetris::~CTetris()
{

}

//绘制游戏背景
void CTetris::DrawBackground(CDC *pDC)
{
	pDC->Rectangle(0, 0, Size * 25, Size * 25);

	pDC->MoveTo(Size * 15, 0);
	pDC->LineTo(Size * 15, Size * 25);

	pDC->MoveTo(Size * 15, Size * 6);
	pDC->LineTo(Size * 25, Size * 6);

	pDC->MoveTo(Size * 15, Size * 20);
	pDC->LineTo(Size * 25, Size * 20);

	CFont ft;
	CString str;
	str.Format("得分：%d", m_score);
	ft.CreatePointFont(150,_T("宋体"),NULL);
	pDC->SelectObject(&ft);
	pDC->SetTextColor(RGB(0,0,0));
	pDC->TextOut(550,650,str);

	pDC->TextOut(550,250,"↑：变形");
	pDC->TextOut(550,300,"←：左移");
	pDC->TextOut(550,350,"→：右移");
	pDC->TextOut(550,400,"↓：下落");
	pDC->TextOut(560,450,"P：暂停");
}

//绘制已经落下的方块
void CTetris::DrawMap(CDC *pDC)
{
	CBrush   Brush;     
	Brush.CreateSolidBrush(RGB(0, 229, 238));     
	pDC->SelectObject(&Brush); 
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 15; j++) {
			if (m_map[i][j] == 1) {
				pDC->Rectangle(j * Size + 1, i * Size + 1, (j + 1) * Size - 1, (i + 1) * Size - 1);
			}
		}
	}
	pDC->EndPath();          
	pDC->FillPath();   

}

//随机生成方块
void CTetris::CreateBlock(int &id)
{
	srand((int)time(NULL));
	id = rand() % 7 * 4;;
}

//绘制当前正在下降的方块
void CTetris::DrawNow(CDC *pDC)
{
	CBrush   Brush;     
	Brush.CreateSolidBrush(RGB(0, 229, 238));     
	pDC->SelectObject(&Brush);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (m_Block[m_nowid][i][j] == 1){
				//x = 150 + map_X + j * Size;
			//	y = map_Y + i * Size;
				pDC->Rectangle(150 + map_X + j * Size + 1, map_Y + i * Size + 1,
								150 + map_X + j * Size + Size - 1, map_Y + i * Size + Size - 1);
			}
		}
	}
	pDC->EndPath();          
	pDC->FillPath();
}

//绘制下一个方块
void CTetris::DrawNext(CDC *pDC)
{
	CBrush   Brush;     
	Brush.CreateSolidBrush(RGB(0, 229, 238));     
	pDC->SelectObject(&Brush);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (m_Block[m_nextid][i][j] == 1)
				pDC->Rectangle(520 + j * Size + 1, 60 + i * Size + 1, 
							   520 + (j + 1) * Size - 1, 60 + (i + 1) * Size - 1);
		}
	}
	pDC->EndPath();          
	pDC->FillPath();
}

//方块下落
void CTetris::Drop()
{
	map_Y = map_Y + Size;
}

//方块是否已经下落
int CTetris::isDown()
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (m_Block[m_nowid][i][j] == 1) {
				if ((map_Y + i * Size) == (25 * Size) || m_map[map_Y / Size + i][map_X / Size + j + 5] == 1) {
					AddToMap(); //在地图中添加方块
					Clear();
					return 1;
				}
			}
		}
	}
	return 0;
}

//更新方块
void CTetris::UpdateBlock()
{
	m_nowid = m_nextid;
	CreateBlock(m_nextid);
	map_X = 0;
	map_Y = 0;
}

//将已落下的方块添加到地图
void CTetris::AddToMap()
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (m_Block[m_nowid][i][j] == 1) {
				m_map[map_Y / Size + i - 1][map_X / Size + j + 5] = 1;
			}
		}
	}
}

//变形
void CTetris::Change()
{
	if (m_nowid == 3 || m_nowid == 7 || m_nowid == 11 || m_nowid == 15 || m_nowid == 19 || m_nowid == 23 || m_nowid == 27) {
		m_nowid -= 3;
	}
	else {
		m_nowid++;
	}
}

//消除方块
void CTetris::Clear()
{
	int i, j;
	for (i = 24; i > 0; i--) {
		for (j = 0; j < 15; j++) {
			if (m_map[i][j] == 0) {
				break;
			}
		}
		if (j == 15) {
			//消除
			for (int x = i; x > 1; x--) {
				for (int y = 0; y < 15; y++) {
					m_map[x][y] = m_map[x - 1][y];
				}
			}
			i++;
			m_score = m_score + 10;
		}
	}
}

//左边界判断
int CTetris::isToLeft(int id)
{
	int temp = map_X - Size;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (m_Block[id][i][j] == 1) {
				if ((temp + 150 + j * Size) < 0 || m_map[map_Y / Size + i][temp / Size + j + 5] == 1) {
					return 1;
				}
			}
		}
	}
	return 0;
}

//右边界判断
int CTetris::isToRight(int id)
{
	int temp = map_X + Size;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (m_Block[id][i][j] == 1) {
				if ((temp + 150 + j * Size) > 14 * Size || m_map[map_Y / Size + i][temp / Size + j + 5] == 1) {
					return 1;
				}
			}
		}
	}
	return 0;
}

//是否可以变形
int CTetris::isokChange()
{
	int temp;
	if (m_nowid == 3 || m_nowid == 7 || m_nowid == 11 || m_nowid == 15 || m_nowid == 19 || m_nowid == 23 || m_nowid == 27) {
		temp = m_nowid - 3;
	}
	else {
		temp = m_nowid + 1;
	}

	if (!isToLeft(temp) && !isToRight(temp)) {
		return 1;
	}
	return 0;
}

//直接下落方块
void CTetris::DropDown()
{
	while(!isDown()) {
		Drop();
	}
	UpdateBlock();
}

//游戏结束
int CTetris::isOver()
{
	for (int i = 0; i < 15; i++) {
		if (m_map[0][i] == 1) {
			return 1;
		}
	}
	return 0;
}

//初始化游戏
void CTetris::GameInit()
{
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 15; j++) {
			m_map[i][j] = 0;
		}
	}
	CreateBlock(m_nextid);
	CreateBlock(m_nowid);

	map_X = 0;
	map_Y = 0;
	
	m_score = 0;
}
