// TanChiShe.cpp: implementation of the CTanChiShe class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "̰����.h"
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
	//��ʼ����Ա����
	m_X = 100;
	m_Y = 100;
	m_Size = 600;
	m_Num = 20;

	initSnake();
}

CTanChiShe::~CTanChiShe()
{

}


//����ͼ
void CTanChiShe::DrawDiTu()
{
	//����ͼ����
	CBrush   Brush;     
	Brush.CreateSolidBrush(RGB(248,248,255));     
	pDC->SelectObject(&Brush);     
	pDC->Rectangle(m_X, m_Y, m_X + m_Size, m_Y + m_Size);
	pDC->EndPath();          
	pDC->FillPath();

	//����ͼ�߽磬�ô��߻�
	CPen pen1(PS_SOLID,2,RGB(0, 0, 0));// ��������
	CPen *pOldPen1=pDC->SelectObject(&pen1);//ԭ���ʸ���
	pDC->Rectangle(m_X, m_Y, m_X + m_Size, m_Y + m_Size);	
	pDC->SelectObject(pOldPen1);//���������ʻ�ԭ

	//��С������ϸ�߻�
	int i;
	int size = m_Size / m_Num; //С����ߴ�
	CPen pen2(PS_SOLID,1,RGB(0, 0, 0));// ��������
	CPen *pOldPen2=pDC->SelectObject(&pen2);//ԭ���ʸ���
	
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
	pDC->SelectObject(pOldPen2); //���������ʻ�ԭ
}

//����
void CTanChiShe::DrawSnake()
{
	int i, x, y, r;
	int size = m_Size / m_Num;  //С���ӳߴ�

	for (i = 0; i < m_nlen; i++) 
	{
		x = m_X + m_Body[i].x * size + size / 2;
		y = m_Y + m_Body[i].y * size + size / 2;
		r = size / 2;
		if (i == 0) 
		{
			CBrush Brush;  
			Brush.CreateSolidBrush(RGB(255, 64, 64));	//��ͷ��ɫ		
			pDC->SelectObject(&Brush);
			pDC->Ellipse(x - r, y - r, x + r, y + r);
			pDC->EndPath();          
			pDC->FillPath();
		}
		else 
		{
			CBrush Brush;   
			Brush.CreateSolidBrush(RGB(255, 140, 105));	 //����ǳɫ		
			pDC->SelectObject(&Brush);
			pDC->Ellipse(x - r, y - r, x + r, y + r);
			pDC->EndPath();          
			pDC->FillPath();		
		}
	}
}


//�����ߣ���ͼ��ʳ�����
void CTanChiShe::DrawAll(CDC *p)
{
	pDC = p;

	DrawDiTu();
	DrawSnake();
	DrawFood();
	DrawHelp();
}


//��ʼ���ߵĲ���
void CTanChiShe::initSnake()
{
	int i;
	m_nlen = INITLEN;  //��ʼ����
	m_Dir = 3; //��ʼ����Ϊ��
	//��ʼ������
	m_Body[0].x = m_Num / 2;
	m_Body[0].y = m_Num / 2;
	for (i = 0; i < m_nlen; i++) 
	{
		//���������ʼ������ͷ����
		m_Body[i].x = m_Body[0].x - i;
		m_Body[i].y = m_Body[0].y;
	}
	//��ʼ��ʳ������
	srand(time(NULL));
	m_Food.x = rand() % m_Num;
	m_Food.y = rand() % m_Num;
}

//�ߵ��ƶ�
//����ǰһ�ڵ����긳����һ�ڣ��ٸ�����ͷ����
void CTanChiShe::Move()
{
	int i;
	for (i = m_nlen - 1; i > 0; i--) 
	{
		m_Body[i] = m_Body[i - 1];
	}

	if (m_Dir == 1) //��
	{  
		m_Body[0].x--;
	}
	else if (m_Dir == 2) //��
	{ 
		m_Body[0].y--;
	}
	else if (m_Dir == 3) //��
	{  
		m_Body[0].x++;
	}
	else if (m_Dir == 4) //��
	{  
		m_Body[0].y++;
	}

	//�ߵ�ͷ������ʳ��
	if (m_Body[0].x == m_Food.x && m_Body[0].y == m_Food.y) 
	{
		m_nlen++;

		//����ʳ������
		m_Food.x = rand() % m_Num;
		m_Food.y = rand() % m_Num;
	}
}


//�ж���Ϸ�Ƿ����
//����1��ʾײǽ��2��ʾҧ���Լ���3��ʾ��Ϸʤ��
int CTanChiShe::isOver()
{
	//�ж��Ƿ�ײǽ
	int size = m_Size / m_Num;
	int x = m_X + m_Body[0].x * size;
	int y = m_Y + m_Body[0].y * size;
	if (x <= m_X - size || x >= m_X + m_Size || y <= m_Y - size || y >= m_Y + m_Size) 
	{
		return 1;
	}

	//�ж��Ƿ�ҧ���Լ�
	//�����������꣬����ͷ������ͬ��ҧ��
	for (int i = 1; i < m_nlen; i++) 
	{
		if (m_Body[0].x == m_Body[i].x && m_Body[0].y == m_Body[i].y) 
		{
			return 2;
		}
	}

	//����ΪFinishʱʤ��
	if (m_nlen == WIN) 
	{
		return 3;
	}
}

///����ʳ��
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

//��ʾ������ʽ�͵÷�
void CTanChiShe::DrawHelp()
{
	CFont ft;
	ft.CreatePointFont(200,_T("����"),NULL);
	pDC->SelectObject(&ft);
	pDC->SetTextColor(RGB(0,0,0));
	pDC->TextOut(m_X + m_Size, m_Y + 150, "  ������ʽ��");
	pDC->TextOut(m_X + m_Size, m_Y + 200, "  ����Ϸ��Ŀ�ʼ��Ϸ��");
	pDC->TextOut(m_X + m_Size, m_Y + 250, "  ���������Ҽ������ߵķ���");

	//�÷�
	CString str;
	str.Format("  ��ǰ���ȣ�%d", m_nlen);
	pDC->TextOut(m_X + m_Size, m_Y + 500, str);
}
