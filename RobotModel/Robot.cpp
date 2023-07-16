// Robot.cpp: implementation of the CRobot class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "RobotModel.h"
#include "Robot.h"

#include "math.h"

#define PI 3.1415926

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CRobot::CRobot()
{
	m_nBody = 0;

	m_YD.x = 500;
	m_YD.y = 300;

	m_kx = 5;
	m_ky = -m_kx;

	m_deltaT = 0.1;
	m_v = 10;
	m_vJump = 5;
	m_eyeOper = 0;
	m_Angle = 0;
	m_t = 0;

	m_MoveType = -1;
}

CRobot::~CRobot()
{

}

void CRobot::CreateRobot()
{
	CString type, name, x, y, r, w, h;

	this->OnInitADOConn();

	try
    {
        // ����ADO��¼������
        m_pRecordset.CreateInstance(__uuidof(Recordset));

        // ִ��SQL��ѯ���
        CString strSQL = _T("select * from Robot");
        m_pRecordset->Open((_bstr_t)strSQL, m_pConnection.GetInterfacePtr(), adOpenStatic, adLockOptimistic, adCmdText);

        // ������¼��
        while (!m_pRecordset->adoEOF)
        {
            // ��ȡ�ֶ�ֵ
			type = this->GetCollect("type");
			name = this->GetCollect("name");
			x = this->GetCollect("x");
			y = this->GetCollect("y");
			r = this->GetCollect("r");
			w = this->GetCollect("w");
			h = this->GetCollect("h");

			// ����ת��
			m_Body[m_nBody].type = atoi(type);
			m_Body[m_nBody].name = name;
			m_Body[m_nBody].x = atof(x);
			m_Body[m_nBody].y = atof(y);
			m_Body[m_nBody].r = atof(r);
			m_Body[m_nBody].w = atof(w);
			m_Body[m_nBody].h = atof(h);

            // �ƶ�����һ����¼
            m_pRecordset->MoveNext();

			m_nBody++;
        }
        // �رռ�¼��
        m_pRecordset->Close();
    }
    catch (_com_error& e)
    {
        CString strError = e.ErrorMessage();
        AfxMessageBox(strError);
    }

	this->ExitConnect();
}

void CRobot::Draw(CDC *p)
{
	pDC = p;

	DrawRobot();
}

void CRobot::DrawRobot()
{
	int i;
	int x, y, r, w, h;

	for (i = 0; i < m_nBody; i++)
	{
		if (m_Body[i].type == CRICLE)
		{
			x = m_YD.x + m_Body[i].x * m_kx;
			y = m_YD.y + m_Body[i].y * m_ky;
			r = m_Body[i].r * m_kx;
			pDC->Ellipse(x - r, y - r, x + r, y + r);
		}
		if (m_Body[i].type == TRIANGLE)
		{
			CPoint pos[3];
			pos[0].x = m_YD.x + m_Body[i].x * m_kx;
			pos[0].y = m_YD.y + m_Body[i].y * m_ky;
			pos[1].x = pos[0].x + m_Body[i].w * m_kx;
			pos[1].y = pos[0].y;
			pos[2].x = pos[0].x + m_Body[i].w * cos(60 / 180.0 * PI) * m_kx;
			pos[2].y = pos[0].y + m_Body[i].w * sin(60 / 180.0 * PI) * m_ky;
			pDC->Polygon(pos, 3);
		}
		if (m_Body[i].type == ELLIPTIC)
		{
			x = m_YD.x + m_Body[i].x * m_kx;
			y = m_YD.y + m_Body[i].y * m_ky;
			w = m_Body[i].w * m_kx;
			h = m_Body[i].h * m_kx;
			pDC->Ellipse(x - w, y - h, x + w, y + h);
		}
		if (m_Body[i].type == RECTANGLE)
		{
			DrawArm(m_Body[i], m_Angle);
		}
	}
}

//����
void CRobot::MoveWalk()
{
	CString  type, name, x, y, r, w, h;
	CString sql;
	int i = 0;

	this->OnInitADOConn();

	try
    {
        // ����ADO��¼������
        m_pRecordset.CreateInstance(__uuidof(Recordset));

        // ִ��SQL��ѯ���
        CString strSQL = _T("select * from Robot");
        m_pRecordset->Open((_bstr_t)strSQL, m_pConnection.GetInterfacePtr(), adOpenStatic, adLockOptimistic, adCmdText);


        // ������¼��
        while (!m_pRecordset->adoEOF)
        {
            // ��ȡ�ֶ�ֵ
			type = this->GetCollect("type");
			name = this->GetCollect("name");
			x = this->GetCollect("x");
			y = this->GetCollect("y");
			r = this->GetCollect("r");
			w = this->GetCollect("w");
			h = this->GetCollect("h");

			//�޸��ֶ�ֵ
			float x_f = atof(x);
			x_f += m_v * m_deltaT * m_kx;

			m_Body[i].x = x_f;

			if ((x_f > 100 || x_f < 0) && i == 0)
			{
				m_v = -m_v;
				x_f = atof(x);
				x_f += m_v * m_deltaT * m_kx;
				m_Body[0].x = x_f;
			}
				
			x.Format("%f", x_f);

			sql.Format("update Robot set type = '%s', name = '%s', x = '%s', y = '%s', r = '%s', w = '%s', h = '%s'\
				where name = '%s'", type, name, x, y, r, w, h, name);
			this->ExecuteSQL(sql);

            // �ƶ�����һ����¼
            m_pRecordset->MoveNext();

			i++;
        }

        // �رռ�¼��
        m_pRecordset->Close();
    }
    catch (_com_error& e)
    {
        CString strError = e.ErrorMessage();
        AfxMessageBox(strError);
    }

	this->ExitConnect();

}

//��Ծ
void CRobot::MoveJump()
{
	CString  type, name, x, y, r, w, h;
	CString sql;
	int i = 0;

	this->OnInitADOConn();

	try
    {
        // ����ADO��¼������
        m_pRecordset.CreateInstance(__uuidof(Recordset));

        // ִ��SQL��ѯ���
        CString strSQL = _T("select * from Robot");
        m_pRecordset->Open((_bstr_t)strSQL, m_pConnection.GetInterfacePtr(), adOpenStatic, adLockOptimistic, adCmdText);


        // ������¼��
        while (!m_pRecordset->adoEOF)
        {
            // ��ȡ�ֶ�ֵ
			type = this->GetCollect("type");
			name = this->GetCollect("name");
			x = this->GetCollect("x");
			y = this->GetCollect("y");
			r = this->GetCollect("r");
			w = this->GetCollect("w");
			h = this->GetCollect("h");

			//�޸��ֶ�ֵ
			float y_f = atof(y);
			y_f += -m_vJump * m_deltaT * m_kx;

			m_Body[i].y = y_f;

			if ((y_f > 20 || y_f < 0) && i == 0)
			{
				m_vJump = -m_vJump;
				y_f = atof(y);
				y_f += -m_vJump * m_deltaT * m_kx;
				m_Body[0].y = y_f;
			}
				
			y.Format("%f", y_f);

			sql.Format("update Robot set type = '%s', name = '%s', x = '%s', y = '%s', r = '%s', w = '%s', h = '%s'\
				where name = '%s'", type, name, x, y, r, w, h, name);
			this->ExecuteSQL(sql);

            // �ƶ�����һ����¼
            m_pRecordset->MoveNext();

			i++;
        }

        // �رռ�¼��
        m_pRecordset->Close();
    }
    catch (_com_error& e)
    {
        CString strError = e.ErrorMessage();
        AfxMessageBox(strError);
    }

	this->ExitConnect();
}

//����
void CRobot::MoveWave()
{
	m_Angle = 22.5 * sin(m_t) + 22.5;
	m_t += m_deltaT * 4;
}

//գ�۾�
void CRobot::MoveWink()
{
	if (m_eyeOper % 2 == 0)
		this->ModifyEyesHigh("2");
	else
		this->ModifyEyesHigh("1");
	m_eyeOper++;
}

void CRobot::Move()
{

	switch(m_MoveType)
	{
	case WALK:
		MoveWalk();
		break;
	case JUMP:
		MoveJump();
		break;
	case WAVE:
		MoveWave();
		break;
	case WINK:
		MoveWink();
		break;
	}
}

void CRobot::ModifyEyesHigh(CString new_h)
{
	CString  type, name, x, y, r, w, h;
	CString sql;

	this->OnInitADOConn();

	try
    {
        // ����ADO��¼������
        m_pRecordset.CreateInstance(__uuidof(Recordset));

        // ִ��SQL��ѯ���
        CString strSQL = _T("select * from Robot");
        m_pRecordset->Open((_bstr_t)strSQL, m_pConnection.GetInterfacePtr(), adOpenStatic, adLockOptimistic, adCmdText);

		//��ȡ��¼��
		sql.Format("select * from Robot where name = '����'");
		this->GetRecordSet(sql);
        // ��ȡ�ֶ�ֵ
		type = this->GetCollect("type");
		name = this->GetCollect("name");
		x = this->GetCollect("x");
		y = this->GetCollect("y");
		r = this->GetCollect("r");
		w = this->GetCollect("w");
		h = this->GetCollect("h");
		//�޸��ֶ�ֵ
		sql.Format("update Robot set type = '%s', name = '%s', x = '%s', y = '%s', r = '%s', w = '%s', h = '%s'\
			where name = '%s'", type, name, x, y, r, w, new_h, name);
		this->ExecuteSQL(sql);

		/*********************************************************/

		//��ȡ��¼��
		sql.Format("select * from Robot where name = '����'");
		this->GetRecordSet(sql);
        // ��ȡ�ֶ�ֵ
		type = this->GetCollect("type");
		name = this->GetCollect("name");
		x = this->GetCollect("x");
		y = this->GetCollect("y");
		r = this->GetCollect("r");
		w = this->GetCollect("w");
		h = this->GetCollect("h");
		//�޸��ֶ�ֵ
		sql.Format("update Robot set type = '%s', name = '%s', x = '%s', y = '%s', r = '%s', w = '%s', h = '%s'\
			where name = '%s'", type, name, x, y, r, w, new_h, name);
		this->ExecuteSQL(sql);

        // �رռ�¼��
        m_pRecordset->Close();
    }
    catch (_com_error& e)
    {
        CString strError = e.ErrorMessage();
        AfxMessageBox(strError);
    }

	this->ExitConnect();

	int i;
	for (i = 0; i < m_nBody; i++)
	{
		if (strcmp((char*)((LPCTSTR)m_Body[i].name), "����") == 0 || 
			strcmp((char*)((LPCTSTR)m_Body[i].name), "����") == 0)
			m_Body[i].h = atof(new_h);
	}
}

void CRobot::DrawArm(SBody body, float angle)
{
	CPoint pos[4];
	pos[0].x = body.x;              pos[0].y = body.y;
	pos[1].x = body.x;              pos[1].y = body.y - body.h;  
	pos[2].x = body.x + body.w;     pos[2].y = body.y - body.h; 
	pos[3].x = body.x + body.w;     pos[3].y = body.y;

	if (body.name.Compare("�ұ�") == 0)
	{
		pos[1].x = (pos[1].x - pos[0].x) * cos(angle / 180 * PI) - (pos[1].y - pos[0].y) * sin(angle / 180 * PI) + pos[0].x;
		pos[1].y = (pos[1].x - pos[0].x) * sin(angle / 180 * PI) + (pos[1].y - pos[0].y) * cos(angle / 180 * PI) + pos[0].y;
		pos[2].x = (pos[2].x - pos[0].x) * cos(angle / 180 * PI) - (pos[2].y - pos[0].y) * sin(angle / 180 * PI) + pos[0].x;
		pos[2].y = (pos[2].x - pos[0].x) * sin(angle / 180 * PI) + (pos[2].y - pos[0].y) * cos(angle / 180 * PI) + pos[0].y;
		pos[3].x = (pos[3].x - pos[0].x) * cos(angle / 180 * PI) - (pos[3].y - pos[0].y) * sin(angle / 180 * PI) + pos[0].x;
		pos[3].y = (pos[3].x - pos[0].x) * sin(angle / 180 * PI) + (pos[3].y - pos[0].y) * cos(angle / 180 * PI) + pos[0].y;
	}
	if (body.name.Compare("���") == 0)
	{
		angle = - angle;
		pos[1].x = (pos[1].x - pos[3].x) * cos(angle / 180 * PI) - (pos[1].y - pos[3].y) * sin(angle / 180 * PI) + pos[3].x;
		pos[1].y = (pos[1].x - pos[3].x) * sin(angle / 180 * PI) + (pos[1].y - pos[3].y) * cos(angle / 180 * PI) + pos[3].y;
		pos[2].x = (pos[2].x - pos[3].x) * cos(angle / 180 * PI) - (pos[2].y - pos[3].y) * sin(angle / 180 * PI) + pos[3].x;
		pos[2].y = (pos[2].x - pos[3].x) * sin(angle / 180 * PI) + (pos[2].y - pos[3].y) * cos(angle / 180 * PI) + pos[3].y;
		pos[0].x = (pos[0].x - pos[3].x) * cos(angle / 180 * PI) - (pos[0].y - pos[3].y) * sin(angle / 180 * PI) + pos[3].x;
		pos[0].y = (pos[0].x - pos[3].x) * sin(angle / 180 * PI) + (pos[0].y - pos[3].y) * cos(angle / 180 * PI) + pos[3].y;
	}

	pos[0].x = m_YD.x + pos[0].x * m_kx;    pos[0].y = m_YD.y + pos[0].y * m_ky;
	pos[1].x = m_YD.x + pos[1].x * m_kx;    pos[1].y = m_YD.y + pos[1].y * m_ky;
	pos[2].x = m_YD.x + pos[2].x * m_kx;    pos[2].y = m_YD.y + pos[2].y * m_ky;
	pos[3].x = m_YD.x + pos[3].x * m_kx;    pos[3].y = m_YD.y + pos[3].y * m_ky;
	pDC->Polygon(pos, 4);
}
