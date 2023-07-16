// Robot.h: interface for the CRobot class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ROBOT_H__6A26F2A6_69EE_45A9_B812_3FEAA0281F0A__INCLUDED_)
#define AFX_ROBOT_H__6A26F2A6_69EE_45A9_B812_3FEAA0281F0A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Ado.h"
#include "DlgCSSZ.h"


class CRobot  
{
public:
	void DeleteRobot();
	void CreateRobot();
	void UpdateRobot();
	void InitRobot();
	void DrawRobot();
	float m_kx,m_ky;//������

	//��ǰѡ��Ļ�����
	CString m_CurRobotName;

	//�����˾�������ĵ����Ͻ����ص�λ����Ϊԭ��
	int m_X,m_Y;
	
	
	//������Բ��ͷ��Բ��λ��(������ԭ�㣬��λ��m)
	float m_Xhead,m_Yhead;
	//������ͷ�İ뾶
	float m_Rhead;
	
	//���������۾���Բ��λ��(������ԭ�㣬��λ��m)
	float m_Xlefteye,m_Ylefteye;
	//���������۾��İ뾶
	float m_Rlefteye;

	//���������۾���Բ��λ��(������ԭ�㣬��λ��m)
	float m_Xrighteye,m_Yrighteye;
	//���������۾��İ뾶
	float m_Rrighteye;

	//�����˱���(�ȱ�������)�����λ��(������ԭ�㣬��λ��m)
	float m_Xnose,m_Ynose;
	//�����˱���(�ȱ�������)�߳�
	float m_Lnose;

	//���������(��Բ)Բ�ĵ�λ��(������ԭ�㣬��λ��m)
	float m_Xmouth,m_Ymouth;
	//���������(��Բ)���������
	float m_Lmouth,m_Smouth;

	//�����˲���(����)���Ͻǵ��λ��(������ԭ�㣬��λ��m)
	float m_Xneck,m_Yneck;
	//�����˲���(����)�����
	float m_Wneck,m_Hneck;

	//���������(����)���Ͻǵ��λ��(������ԭ�㣬��λ��m)
	float m_Xleftarm,m_Yleftarm;
	//���������(����)�����
	float m_Wleftarm,m_Hleftarm;

	//�������ұ�(����)���Ͻǵ��λ��(������ԭ�㣬��λ��m)
	float m_Xrightarm,m_Yrightarm;
	//�������ұ�(����)�����
	float m_Wrightarm,m_Hrightarm;

	//����������(����)���Ͻǵ��λ��(������ԭ�㣬��λ��m)
	float m_Xbody,m_Ybody;
	//����������(����)�����
	float m_Wbody,m_Hbody;

	//����������(����)���Ͻǵ��λ��(������ԭ�㣬��λ��m)
	float m_Xleftleg,m_Yleftleg;
	//����������(����)�����
	float m_Wleftleg,m_Hleftleg;

	//����������(����)���Ͻǵ��λ��(������ԭ�㣬��λ��m)
	float m_Xrightleg,m_Yrightleg;
	//����������(����)�����
	float m_Wrightleg,m_Hrightleg;

	//���������(����)���Ͻǵ��λ��(������ԭ�㣬��λ��m)
	float m_Xleftfoot,m_Yleftfoot;
	//���������(����)�����
	float m_Wleftfoot,m_Hleftfoot;

	//�������ҽ�(����)���Ͻǵ��λ��(������ԭ�㣬��λ��m)
	float m_Xrightfoot,m_Yrightfoot;
	//�������ҽ�(����)�����
	float m_Wrightfoot,m_Hrightfoot;


	CAdo m_Ado;
	CDlgCSSZ m_dlg;
	CDC* pDC;
	void Draw(CDC* DC);
	CRobot();
	virtual ~CRobot();

};

#endif // !defined(AFX_ROBOT_H__6A26F2A6_69EE_45A9_B812_3FEAA0281F0A__INCLUDED_)
