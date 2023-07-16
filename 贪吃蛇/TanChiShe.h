// TanChiShe.h: interface for the CTanChiShe class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TANCHISHE_H__3CDD100F_7CBE_4B8D_8F87_679931563E20__INCLUDED_)
#define AFX_TANCHISHE_H__3CDD100F_7CBE_4B8D_8F87_679931563E20__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define WIN 100  //ʤ������
#define INITLEN 3   //�ߵĳ�ʼ����

class CTanChiShe  
{
public:
	void DrawHelp();
	void DrawFood();
	int isOver();
	void Move();
	void initSnake();
	void DrawAll(CDC *p);
	void DrawSnake();
	void DrawDiTu();
	CTanChiShe();
	virtual ~CTanChiShe();


	CDC *pDC;

	//��ͼ�ı���
	int m_X, m_Y;  //��ͼ���Ͻ�����
	int m_Size;  //��ͼ�ߴ�
	int m_Num;   //��ͼ��һ�е�С��������
	             //   m_Size / m_Num ����С����ߴ�

	//�ߵı���		
	int m_nlen;  //�ߵĳ���
	int m_initX;
	int m_initY;  //�ߵĳ�ʼ����
	CPoint m_Body[WIN]; //��������
	int m_Dir;  //����

	//ʳ��ı���
	CPoint m_Food; // ʳ������
};

#endif // !defined(AFX_TANCHISHE_H__3CDD100F_7CBE_4B8D_8F87_679931563E20__INCLUDED_)
