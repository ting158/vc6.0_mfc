// WuZiQi.cpp: implementation of the CWuZiQi class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "������.h"
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
	//��ʼ����Ա����
	m_Size = 30;  //С����ߴ���Ϊ30
	m_initX = 100;  //�������Ͻ����꣨100��100��
	m_initY = 100;
	m_Color = 1;  //��������
	//���������̳�ʼ��Ϊ����
	InitQiPan();
}

CWuZiQi::~CWuZiQi()
{

}

//�����̺;Ÿ���λ
void CWuZiQi::DrawQiPan()
{
	int i, j;
	//����
	DrawBackground();
	//����
	for (i = 0; i < 19; i++) {
		pDC->MoveTo(m_initX, m_initY + i * m_Size);
		pDC->LineTo(m_initX + 18 * m_Size, m_initY + i * m_Size);
	}
	for (i = 0; i < 19; i++) {
		pDC->MoveTo(m_initX + i * m_Size, m_initY);
		pDC->LineTo(m_initX + i * m_Size, m_initY + 18 * m_Size);
	}
	//��λ
	int xw_x = m_initX + 3 * m_Size;
	int xw_y = m_initY + 3 * m_Size;   //���Ͻǵ�һ����λ����
	int r = m_Size / 5; //��λ�뾶
	CBrush Brush;
	Brush.CreateSolidBrush(RGB(0, 0, 0));  //��ɫ��λ
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

//������
void CWuZiQi::DrawQiZi()
{
	int i, j;
	int r = m_Size / 3;

	for (i = 0; i < 19; i++) {
		for (j = 0; j < 19; j++) {
			if (m_Qp[i][j] != 0) {
				if (m_Qp[i][j] == 1) {  //����
					CBrush Brush;
					Brush.CreateSolidBrush(RGB(0, 0, 0));
					pDC->SelectObject(&Brush);
					pDC->Ellipse(m_initX + i * m_Size - r, m_initY + j * m_Size - r, 
								 m_initX + i * m_Size + r, m_initY + j * m_Size + r);
					pDC->EndPath();          
					pDC->FillPath();
				}
				else if (m_Qp[i][j] == 2) {  //����
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

//�����̺�����
void CWuZiQi::Draw(CDC *p)
{
	pDC = p;
	DrawQiPan();
	DrawQiZi();
}

//����
void CWuZiQi::XiaQi(CPoint p)
{
	//ȷ������λ���������ϣ�m_Size / 3 Ϊ���Ӱ뾶
	if (p.x >= m_initX - m_Size / 3 && p.x <= m_initX + 18 * m_Size &&
		p.y >= m_initY - m_Size / 3 && p.y <= m_initY + 18 * m_Size)
	{
		//��������λ��
		m_H = (p.x - m_initX + m_Size / 3) / m_Size;
		m_L = (p.y - m_initY + m_Size / 3) / m_Size;
	}

	//����ʱ��������
	if (m_Qp[m_H][m_L] == 0 && m_Color == 1) 
	{
		m_Qp[m_H][m_L] = 1;
		PanDuan();  //�ж���Ӯ
		m_Color = 2;  //��Ϊ��������
	}
	else if (m_Qp[m_H][m_L] == 0 && m_Color == 2) 
	{
		m_Qp[m_H][m_L] = 2;
		PanDuan();  //�ж���Ӯ
		m_Color = 1;  //��Ϊ��������
	}
}

//�ж���Ӯ��������λ��Ϊ���ķֱ���˸������ж�
void CWuZiQi::PanDuan()
{
	int i;

	//�˸�������ͬ��ɫ���ӵ�����
	int up = 0, down = 0;
	int left = 0, right = 0;
	int leftup = 0, rightdown = 0;
	int leftdown = 0, rightup = 0;

	//��������

	//���·���
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
	//���ҷ���
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
	//�������·���
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
	//�������Ϸ���
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

	//�ж���Ӯ
	if (up + down >= 4 || left + right >= 4 || leftup + rightdown >= 4 || leftdown + rightup >= 4) {
		if (m_Color == 1) {
			AfxMessageBox("�����ʤ��\n��ȷ�����¿�ʼ");
			InitQiPan();
		}
		if (m_Color == 2) {
			AfxMessageBox("�����ʤ��\n��ȷ�����¿�ʼ");
			InitQiPan();
		}
	}
}



//�����̱���
void CWuZiQi::DrawBackground()
{
	CBrush Brush;
	Brush.CreateSolidBrush(RGB(255, 222, 173));
	pDC->SelectObject(&Brush);
	pDC->Rectangle(m_initX, m_initY, m_initX + 18 * m_Size, m_initY + 18 * m_Size);
	pDC->EndPath();          
	pDC->FillPath();
}

//�����̳�ʼ��Ϊ������
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
