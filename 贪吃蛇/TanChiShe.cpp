// TanChiShe.cpp: implementation of the CTanChiShe class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "贪吃蛇.h"
#include "TanChiShe.h"

#include "time.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTanChiShe::CTanChiShe()
{
	//初始化成员变量
	m_X = 100;
	m_Y = 100;
	m_Size = 600;
	m_Num = 20;

	initSnake();
}

CTanChiShe::~CTanChiShe()
{

}


//画地图
void CTanChiShe::DrawDiTu()
{
	//画地图背景
	CBrush   Brush;     
	Brush.CreateSolidBrush(RGB(248,248,255));     
	pDC->SelectObject(&Brush);     
	pDC->Rectangle(m_X, m_Y, m_X + m_Size, m_Y + m_Size);
	pDC->EndPath();          
	pDC->FillPath();

	//画地图边界，用粗线画
	CPen pen1(PS_SOLID,2,RGB(0, 0, 0));// 创建画笔
	CPen *pOldPen1=pDC->SelectObject(&pen1);//原画笔复制
	pDC->Rectangle(m_X, m_Y, m_X + m_Size, m_Y + m_Size);	
	pDC->SelectObject(pOldPen1);//结束，画笔还原

	//画小方格，用细线画
	int i;
	int size = m_Size / m_Num; //小方格尺寸
	CPen pen2(PS_SOLID,1,RGB(0, 0, 0));// 创建画笔
	CPen *pOldPen2=pDC->SelectObject(&pen2);//原画笔复制
	
	for (i = 0; i < m_Num; i++) 
	{
		pDC->MoveTo(m_X, m_Y + i * size);
		pDC->LineTo(m_X + m_Size, m_Y + i * size);

	}
	for (i = 0; i < m_Num; i++) 
	{
		pDC->MoveTo(m_X + i * size, m_Y);
		pDC->LineTo(m_X + i * size, m_Y + m_Size);

	}
	pDC->SelectObject(pOldPen2); //结束，画笔还原
}

//画蛇
void CTanChiShe::DrawSnake()
{
	int i, x, y, r;
	int size = m_Size / m_Num;  //小格子尺寸

	for (i = 0; i < m_nlen; i++) 
	{
		x = m_X + m_Body[i].x * size + size / 2;
		y = m_Y + m_Body[i].y * size + size / 2;
		r = size / 2;
		if (i == 0) 
		{
			CBrush Brush;  
			Brush.CreateSolidBrush(RGB(255, 64, 64));	//蛇头深色		
			pDC->SelectObject(&Brush);
			pDC->Ellipse(x - r, y - r, x + r, y + r);
			pDC->EndPath();          
			pDC->FillPath();
		}
		else 
		{
			CBrush Brush;   
			Brush.CreateSolidBrush(RGB(255, 140, 105));	 //蛇身浅色		
			pDC->SelectObject(&Brush);
			pDC->Ellipse(x - r, y - r, x + r, y + r);
			pDC->EndPath();          
			pDC->FillPath();		
		}
	}
}


//画出蛇，地图，食物，帮助
void CTanChiShe::DrawAll(CDC *p)
{
	pDC = p;

	DrawDiTu();
	DrawSnake();
	DrawFood();
	DrawHelp();
}


//初始化蛇的参数
void CTanChiShe::initSnake()
{
	int i;
	m_nlen = INITLEN;  //初始长度
	m_Dir = 3; //初始方向为右
	//初始化蛇身
	m_Body[0].x = m_Num / 2;
	m_Body[0].y = m_Num / 2;
	for (i = 0; i < m_nlen; i++) 
	{
		//从右往左初始化，蛇头在右
		m_Body[i].x = m_Body[0].x - i;
		m_Body[i].y = m_Body[0].y;
	}
	//初始化食物坐标
	srand(time(NULL));
	m_Food.x = rand() % m_Num;
	m_Food.y = rand() % m_Num;
}

//蛇的移动
//蛇身前一节的坐标赋给后一节，再更新蛇头坐标
void CTanChiShe::Move()
{
	int i;
	for (i = m_nlen - 1; i > 0; i--) 
	{
		m_Body[i] = m_Body[i - 1];
	}

	if (m_Dir == 1) //左
	{  
		m_Body[0].x--;
	}
	else if (m_Dir == 2) //上
	{ 
		m_Body[0].y--;
	}
	else if (m_Dir == 3) //右
	{  
		m_Body[0].x++;
	}
	else if (m_Dir == 4) //下
	{  
		m_Body[0].y++;
	}

	//蛇的头部碰到食物
	if (m_Body[0].x == m_Food.x && m_Body[0].y == m_Food.y) 
	{
		m_nlen++;

		//更新食物坐标
		m_Food.x = rand() % m_Num;
		m_Food.y = rand() % m_Num;
	}
}


//判断游戏是否结束
//返回1表示撞墙，2表示咬到自己，3表示游戏胜利
int CTanChiShe::isOver()
{
	//判断是否撞墙
	int size = m_Size / m_Num;
	int x = m_X + m_Body[0].x * size;
	int y = m_Y + m_Body[0].y * size;
	if (x <= m_X - size || x >= m_X + m_Size || y <= m_Y - size || y >= m_Y + m_Size) 
	{
		return 1;
	}

	//判断是否咬到自己
	//遍历蛇身坐标，与蛇头坐标相同即咬到
	for (int i = 1; i < m_nlen; i++) 
	{
		if (m_Body[0].x == m_Body[i].x && m_Body[0].y == m_Body[i].y) 
		{
			return 2;
		}
	}

	//长度为Finish时胜利
	if (m_nlen == WIN) 
	{
		return 3;
	}
}

///画出食物
void CTanChiShe::DrawFood()
{
	int size = m_Size / m_Num;
	int x, y, r;
	CBrush Brush;  
	Brush.CreateSolidBrush(RGB(138, 43, 226));			
	pDC->SelectObject(&Brush);

	x = m_X + m_Food.x * size + size / 2;
	y = m_Y + m_Food.y * size + size / 2;
	r = size / 2; 
	pDC->Ellipse(x - r, y - r, x + r, y + r);

	pDC->EndPath();          
	pDC->FillPath();
}

//显示操作方式和得分
void CTanChiShe::DrawHelp()
{
	CFont ft;
	ft.CreatePointFont(200,_T("宋体"),NULL);
	pDC->SelectObject(&ft);
	pDC->SetTextColor(RGB(0,0,0));
	pDC->TextOut(m_X + m_Size, m_Y + 150, "  操作方式：");
	pDC->TextOut(m_X + m_Size, m_Y + 200, "  点击上方的开始游戏，");
	pDC->TextOut(m_X + m_Size, m_Y + 250, "  按上下左右键控制蛇的方向");

	//得分
	CString str;
	str.Format("  当前长度：%d", m_nlen);
	pDC->TextOut(m_X + m_Size, m_Y + 500, str);
}
