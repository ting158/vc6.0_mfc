// WuZiQi.cpp: implementation of the CWuZiQi class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "五子棋.h"
#include "WuZiQi.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CWuZiQi::CWuZiQi()
{
	//初始化成员变量
	m_Size = 30;  //小方格尺寸设为30
	m_initX = 100;  //棋盘左上角坐标（100，100）
	m_initY = 100;
	m_Color = 1;  //黑子先下
	//将整个棋盘初始化为无子
	InitQiPan();
}

CWuZiQi::~CWuZiQi()
{

}

//画棋盘和九个星位
void CWuZiQi::DrawQiPan()
{
	int i, j;
	//背景
	DrawBackground();
	//棋盘
	for (i = 0; i < 19; i++) {
		pDC->MoveTo(m_initX, m_initY + i * m_Size);
		pDC->LineTo(m_initX + 18 * m_Size, m_initY + i * m_Size);
	}
	for (i = 0; i < 19; i++) {
		pDC->MoveTo(m_initX + i * m_Size, m_initY);
		pDC->LineTo(m_initX + i * m_Size, m_initY + 18 * m_Size);
	}
	//星位
	int xw_x = m_initX + 3 * m_Size;
	int xw_y = m_initY + 3 * m_Size;   //左上角第一个星位坐标
	int r = m_Size / 5; //星位半径
	CBrush Brush;
	Brush.CreateSolidBrush(RGB(0, 0, 0));  //黑色星位
	pDC->SelectObject(&Brush);
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			pDC->Ellipse(xw_x + i * m_Size * 6 - r, xw_y + j * m_Size * 6 - r,
						 xw_x + i * m_Size * 6 + r, xw_x + j * m_Size * 6 + r);
		}
	}
	pDC->EndPath();          
	pDC->FillPath();

}

//画棋子
void CWuZiQi::DrawQiZi()
{
	int i, j;
	int r = m_Size / 3;

	for (i = 0; i < 19; i++) {
		for (j = 0; j < 19; j++) {
			if (m_Qp[i][j] != 0) {
				if (m_Qp[i][j] == 1) {  //黑棋
					CBrush Brush;
					Brush.CreateSolidBrush(RGB(0, 0, 0));
					pDC->SelectObject(&Brush);
					pDC->Ellipse(m_initX + i * m_Size - r, m_initY + j * m_Size - r, 
								 m_initX + i * m_Size + r, m_initY + j * m_Size + r);
					pDC->EndPath();          
					pDC->FillPath();
				}
				else if (m_Qp[i][j] == 2) {  //白棋
					CBrush Brush;
					Brush.CreateSolidBrush(RGB(255, 255, 255));
					pDC->SelectObject(&Brush);
					pDC->Ellipse(m_initX + i * m_Size - r, m_initY + j * m_Size - r, 
								 m_initX + i * m_Size + r, m_initY + j * m_Size + r);
					pDC->EndPath();          
					pDC->FillPath();
				}
			}
		}
	}
}

//画棋盘和棋子
void CWuZiQi::Draw(CDC *p)
{
	pDC = p;
	DrawQiPan();
	DrawQiZi();
}

//下棋
void CWuZiQi::XiaQi(CPoint p)
{
	//确保落子位置在棋盘上，m_Size / 3 为棋子半径
	if (p.x >= m_initX - m_Size / 3 && p.x <= m_initX + 18 * m_Size &&
		p.y >= m_initY - m_Size / 3 && p.y <= m_initY + 18 * m_Size)
	{
		//保存落子位置
		m_H = (p.x - m_initX + m_Size / 3) / m_Size;
		m_L = (p.y - m_initY + m_Size / 3) / m_Size;
	}

	//无子时才能落子
	if (m_Qp[m_H][m_L] == 0 && m_Color == 1) 
	{
		m_Qp[m_H][m_L] = 1;
		PanDuan();  //判断输赢
		m_Color = 2;  //改为白子下棋
	}
	else if (m_Qp[m_H][m_L] == 0 && m_Color == 2) 
	{
		m_Qp[m_H][m_L] = 2;
		PanDuan();  //判断输赢
		m_Color = 1;  //改为黑子下棋
	}
}

//判断输赢，以落子位置为中心分别向八个方向判断
void CWuZiQi::PanDuan()
{
	int i;

	//八个方向相同颜色棋子的数量
	int up = 0, down = 0;
	int left = 0, right = 0;
	int leftup = 0, rightdown = 0;
	int leftdown = 0, rightup = 0;

	//计算数量

	//上下方向
	for (i = 1; i <= 5; i++) {
		if (m_Qp[m_H - i][m_L] == m_Color)
			up++;
		else
			break;
	}
	for (i = 1; i <= 5; i++) {
		if (m_Qp[m_H + i][m_L] == m_Color)
			down++;
		else
			break;
	}
	//左右方向
	for (i = 1; i <= 5; i++) {
		if (m_Qp[m_H][m_L - i] == m_Color)
			left++;
		else
			break;
	}
	for (i = 1; i <= 5; i++) {
		if (m_Qp[m_H][m_L + i] == m_Color)
			right++;
		else
			break;
	}
	//左上右下方向
	for (i = 1; i <= 5; i++) {
		if (m_Qp[m_H - i][m_L - i] == m_Color)
			leftup++;
		else
			break;
	}
	for (i = 1; i <= 5; i++) {
		if (m_Qp[m_H + i][m_L + i] == m_Color)
			rightdown++;
		else
			break;
	}
	//左下右上方向
	for (i = 1; i <= 5; i++) {
		if (m_Qp[m_H + i][m_L - i] == m_Color)
			leftdown++;
		else
			break;
	}
	for (i = 1; i <= 5; i++) {
		if (m_Qp[m_H - i][m_L + i] == m_Color)
			rightup++;
		else
			break;
	}

	//判断输赢
	if (up + down >= 4 || left + right >= 4 || leftup + rightdown >= 4 || leftdown + rightup >= 4) {
		if (m_Color == 1) {
			AfxMessageBox("黑棋获胜！\n点确定重新开始");
			InitQiPan();
		}
		if (m_Color == 2) {
			AfxMessageBox("白棋获胜！\n点确定重新开始");
			InitQiPan();
		}
	}
}



//画棋盘背景
void CWuZiQi::DrawBackground()
{
	CBrush Brush;
	Brush.CreateSolidBrush(RGB(255, 222, 173));
	pDC->SelectObject(&Brush);
	pDC->Rectangle(m_initX, m_initY, m_initX + 18 * m_Size, m_initY + 18 * m_Size);
	pDC->EndPath();          
	pDC->FillPath();
}

//将棋盘初始化为无棋子
void CWuZiQi::InitQiPan()
{
	int i, j;
	for (i = 0; i < 19; i++) 
	{
		for (j = 0; j < 19; j++) 
		{
			m_Qp[i][j] = 0;
		}
	}
}
