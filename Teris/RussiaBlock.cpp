// RussiaBlock.cpp: implementation of the CRussiaBlock class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Teris.h"
#include "RussiaBlock.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CRussiaBlock::CRussiaBlock()
{
	m_s = 0;
	m_r = 40;
	m_cret = 0;
	m_key = 0;
	flag1 = 0;
	flag2 = 0;
	m_score = 0;
	begPos.x = 100;
	begPos.y = 100;
	endPos.x =500;
	endPos.y = 900;//游戏区域
	for(int i = 0; i < Max; i++)
		for(int j = 0; j < Max; j++)
			FK[i][j] = 0;
}

CRussiaBlock::~CRussiaBlock()
{

}

void CRussiaBlock::Draw(CDC *pDC)
{
	CString str;
	CFont ft;
	DrawArea();
	DrawBlock();

	str.Format("得分：%d 分",m_score);
	pDC->SelectObject(&ft);
	pDC->SetTextColor(RGB(0,0,0));
	pDC->TextOut(600,200,str);	
}

void CRussiaBlock::DrawArea()
{
	int i,j;
	pDC->Rectangle(100,100,500,900);//游戏区域

	for(i = 0; i < 10; i++)
		for(j = 0; j < 20; j++)
			if (1 == FK[i][j])//该处有方块则填充颜色
			{
				begPos.x = 100 + m_r*i;
				begPos.y = 100 + m_r*j;
				endPos.x = 100 + m_r*(i + 1);
				endPos.y = 100 + m_r*(j + 1);
				CBrush brush,*pOldBrush;
				brush.CreateSolidBrush(RGB(255,0,0));
				pOldBrush = pDC->SelectObject(&brush);
				pDC->Rectangle(begPos.x,begPos.y,endPos.x,endPos.y);
				brush.DeleteObject();
				pDC->SelectObject(pOldBrush);
			}
}

void CRussiaBlock::DrawBlock()
{
	

	begPos.x = m_Block.p1.x - flag1*m_r;
	begPos.y = m_Block.p1.y - flag2*m_r;
	endPos.x = begPos.x + m_r;
	endPos.y = begPos.y + m_r;
	pDC->Rectangle(begPos.x,begPos.y,endPos.x,endPos.y);

	begPos.x = m_Block.p2.x - flag1*m_r;
	begPos.y = m_Block.p2.y - flag2*m_r;
	endPos.x = begPos.x + m_r;
	endPos.y = begPos.y + m_r;
	pDC->Rectangle(begPos.x,begPos.y,endPos.x,endPos.y);

	begPos.x = m_Block.p3.x - flag1*m_r;
	begPos.y = m_Block.p3.y - flag2*m_r;
	endPos.x = begPos.x + m_r;
	endPos.y = begPos.y + m_r;
	pDC->Rectangle(begPos.x,begPos.y,endPos.x,endPos.y);

	begPos.x = m_Block.p4.x - flag1*m_r;
	begPos.y = m_Block.p4.y - flag2*m_r;
	endPos.x = begPos.x + m_r;
	endPos.y = begPos.y + m_r;
	pDC->Rectangle(begPos.x,begPos.y,endPos.x,endPos.y);
}

void CRussiaBlock::CreateBlock()
{
	flag1 = 0;
	flag2 = 0;
	m_Block.dir = 0;
	
	srand((int)time(NULL));
	int n = rand() % 7;

	switch(n)
	{
	case 0:
		m_Block.p.x = 320;
		m_Block.p.y = 160;
		m_Block.p1.x = 300;
		m_Block.p1.y = 140;
		m_Block.p2.x = 300;
		m_Block.p2.y = 100;
		m_Block.p3.x = 260;
		m_Block.p3.y = 140;
		m_Block.p4.x = 340;
		m_Block.p4.y = 140;
		break;

	case 1:
		m_Block.p.x = 320;
		m_Block.p.y = 160;
		m_Block.p1.x = 300;
		m_Block.p1.y = 140;
		m_Block.p2.x = 300;
		m_Block.p2.y = 100;
		m_Block.p3.x = 260;
		m_Block.p3.y = 140;
		m_Block.p4.x = 220;
		m_Block.p4.y = 140;
		break;

	case 2:
		m_Block.p.x = 320;
		m_Block.p.y = 160;
		m_Block.p1.x = 300;
		m_Block.p1.y = 140;
		m_Block.p2.x = 300;
		m_Block.p2.y = 100;
		m_Block.p3.x = 340;
		m_Block.p3.y = 140;
		m_Block.p4.x = 380;
		m_Block.p4.y = 140;
		break;

	case 3:
		m_Block.p.x = 320;
		m_Block.p.y = 160;
		m_Block.p1.x = 300;
		m_Block.p1.y = 140;
		m_Block.p2.x = 260;
		m_Block.p2.y = 140;
		m_Block.p3.x = 340;
		m_Block.p3.y = 140;
		m_Block.p4.x = 380;
		m_Block.p4.y = 140;
		break;

	case 4:
		m_Block.p.x = 320;
		m_Block.p.y = 160;
		m_Block.p1.x = 300;
		m_Block.p1.y = 140;
		m_Block.p2.x = 300;
		m_Block.p2.y = 100;
		m_Block.p3.x = 340;
		m_Block.p3.y = 140;
		m_Block.p4.x = 340;
		m_Block.p4.y = 180;
		break;

	case 5://正方形
		m_Block.p.x = 320;
		m_Block.p.y = 160;
		m_Block.p1.x = 300;
		m_Block.p1.y = 100;
		m_Block.p2.x = 300;
		m_Block.p2.y = 140;
		m_Block.p3.x = 340;
		m_Block.p3.y = 100;
		m_Block.p4.x = 340;
		m_Block.p4.y = 140;
		break;

	case 6:
		m_Block.p.x = 320;
		m_Block.p.y = 160;
		m_Block.p1.x = 300;
		m_Block.p1.y = 140;
		m_Block.p2.x = 300;
		m_Block.p2.y = 180;
		m_Block.p3.x = 340;
		m_Block.p3.y = 140;
		m_Block.p4.x = 340;
		m_Block.p4.y = 100;
		break;
	}
}

void CRussiaBlock::Change()
{
	int dx,dy;
	dx = m_Block.p1.x - m_Block.p.x;
	dy = m_Block.p1.y - m_Block.p.y;
	m_Block.p1.x = m_Block.p.x - dy;
	m_Block.p1.y = m_Block.p.y + dx;

	dx = m_Block.p2.x - m_Block.p.x;
	dy = m_Block.p2.y - m_Block.p.y;
	m_Block.p2.x = m_Block.p.x - dy;
	m_Block.p2.y = m_Block.p.y + dx;

	dx = m_Block.p3.x - m_Block.p.x;
	dy = m_Block.p3.y - m_Block.p.y;
	m_Block.p3.x = m_Block.p.x - dy;
	m_Block.p3.y = m_Block.p.y + dx;

	dx = m_Block.p4.x - m_Block.p.x;
	dy = m_Block.p4.y - m_Block.p.y;
	m_Block.p4.x = m_Block.p.x - dy;
	m_Block.p4.y = m_Block.p.y + dx;

	m_Block.dir++;

	if(1 == m_Block.dir%4 || 2 == m_Block.dir%4)
		flag1 = 1;
	if(2 == m_Block.dir%4 || 3 == m_Block.dir%4)
		flag2 = 1;
}

int CRussiaBlock::PengBi()
{
	if(m_Block.p1.x - flag1*m_r >= 100 && m_Block.p1.x - flag1*m_r <= 500 - m_r && m_Block.p1.y - flag2*m_r <= 900 - m_r)
		if(m_Block.p2.x - flag1*m_r >= 100 && m_Block.p2.x - flag1*m_r <= 500 - m_r && m_Block.p2.y - flag2*m_r <= 900 - m_r)
			if(m_Block.p3.x - flag1*m_r >= 100 && m_Block.p3.x - flag1*m_r <= 500 - m_r && m_Block.p3.y - flag2*m_r <= 900 - m_r)
				if(m_Block.p4.x - flag1*m_r >= 100 && m_Block.p4.x - flag1*m_r <= 500 - m_r && m_Block.p4.y - flag2*m_r <= 900 - m_r)
					return 1;
	return 0;
}

int CRussiaBlock::Touch()
{
	int i,j;
	for(i = 0; i < 10; i++)
		for (j = 0; j < 20; j++)
		{
			if (1 == FK[i][j])
			{
				if((i == (m_Block.p1.x - flag1*m_r - 100)/m_r) && (j == (m_Block.p1.y - flag2*m_r - 100)/m_r + 1))
				return 0;
				if((i == (m_Block.p2.x - flag1*m_r - 100)/m_r) && (j == (m_Block.p2.y - flag2*m_r - 100)/m_r + 1))
				return 0;
				if((i == (m_Block.p3.x - flag1*m_r - 100)/m_r) && (j == (m_Block.p3.y - flag2*m_r - 100)/m_r + 1))
				return 0;
				if((i == (m_Block.p4.x - flag1*m_r - 100)/m_r) && (j == (m_Block.p4.y - flag2*m_r - 100)/m_r + 1))
				return 0;
			}
		}
		if(m_Block.p1.y - flag2*m_r < 900 - m_r && m_Block.p2.y - flag2*m_r < 900 - m_r\
			&& m_Block.p3.y - flag2*m_r < 900 - m_r && m_Block.p4.y - flag2*m_r < 900 - m_r)
			return 1;
		return 0;
}

void CRussiaBlock::KeyMove(int n)
{
	switch(n)
	{
	case 37://向左
		m_Block.p1.x -= m_r;
		m_Block.p2.x -= m_r;
		m_Block.p3.x -= m_r;
		m_Block.p4.x -= m_r;
		m_Block.p.x -= m_r;
		if (m_Block.p1.x - flag1*m_r  < 100 || m_Block.p2.x - flag1*m_r < 100\
			|| m_Block.p3.x - flag1*m_r  < 100 || m_Block.p4.x - flag1*m_r < 100)
		{
			m_Block.p1.x += m_r;
			m_Block.p2.x += m_r;
			m_Block.p3.x += m_r;
			m_Block.p4.x += m_r;
			m_Block.p.x += m_r;
		}
		break;
	case 38://向上变形
		Change();
		if (0 == PengBi())
		{
			Change();
			Change();
			Change();
		}
		break;
	case 39://向右
		if (m_Block.p1.x - flag1*m_r < 500 - m_r && m_Block.p2.x - flag1*m_r < 500 - m_r &&\
			m_Block.p3.x - flag1*m_r < 500 - m_r && m_Block.p4.x - flag1*m_r < 500 - m_r)
		{
			m_Block.p1.x += m_r;
			m_Block.p2.x += m_r;
			m_Block.p3.x += m_r;
			m_Block.p4.x += m_r;
			m_Block.p.x += m_r;
		}
		break;

	case 40://向下
		if (Touch())
		{
			m_Block.p1.y += m_r;
			m_Block.p2.y += m_r;
			m_Block.p3.y += m_r;
			m_Block.p4.y += m_r;
			m_Block.p.y += m_r;
		}
		break;
	}
}

void CRussiaBlock::Move()
{
	int i,j;
	if (1 == Touch())
	{
		m_Block.p1.y += m_r;
		m_Block.p2.y += m_r;
		m_Block.p3.y += m_r;
		m_Block.p4.y += m_r;
		m_Block.p.y += m_r;
	}
	else
	{
		m_cret = 0;
		//JuLiDian();
		i = (m_Block.p1.x - flag1*m_r - 100)/m_r;
		j = (m_Block.p1.y - flag2*m_r - 100)/m_r;
		FK[i][j] = 1;

		i = (m_Block.p2.x - flag1*m_r - 100)/m_r;
		j = (m_Block.p2.y - flag2*m_r - 100)/m_r;
		FK[i][j] = 1;

		i = (m_Block.p3.x - flag1*m_r - 100)/m_r;
		j = (m_Block.p3.y - flag2*m_r - 100)/m_r;
		FK[i][j] = 1;

		i = (m_Block.p4.x - flag1*m_r - 100)/m_r;
		j = (m_Block.p4.y - flag2*m_r - 100)/m_r;
		FK[i][j] = 1;
		flag1 = 0;
		flag2 = 0;
	}
}

void CRussiaBlock::JuLiDian()
{
	int i,j;
	i = (m_Block.p1.x - flag1*m_r - 100)/m_r;
	j = (m_Block.p1.y - flag2*m_r - 100)/m_r;
	FK[i][j] = 1;
	
	i = (m_Block.p2.x - flag1*m_r - 100)/m_r;
	j = (m_Block.p2.y - flag2*m_r - 100)/m_r;
	FK[i][j] = 1;
	
	i = (m_Block.p3.x - flag1*m_r - 100)/m_r;
	j = (m_Block.p3.y - flag2*m_r - 100)/m_r;
	FK[i][j] = 1;
	
	i = (m_Block.p4.x - flag1*m_r - 100)/m_r;
	j = (m_Block.p4.y - flag2*m_r - 100)/m_r;
	FK[i][j] = 1;
	flag1 = 0;
	flag2 = 0;
}

void CRussiaBlock::PanDuanDeFen()
{
	int i,j,k,s;
	for (j = Max - 1; j > 0; j--)
	{
		s = 0;
		for(i = 0; i < 10; i++)
			s += FK[i][j];
		if (s == 10)
		{
			m_score++;
			for (k = j; k > 0; k--)
			{
				for(i = 0; i < 10; i++)
					FK[i][k] = FK[i][k - 1];
			}
		}
	}
}
