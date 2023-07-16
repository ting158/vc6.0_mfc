// Robot.cpp: implementation of the CRobot class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Access_Robot.h"
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
}

CRobot::~CRobot()
{
	if (m_pConnection)
    {
        m_pConnection->Close();
        m_pConnection.Release();
    }
}

void CRobot::ConnectDatabase()
{
    // 创建ADO连接对象
    HRESULT hr = m_pConnection.CreateInstance(__uuidof(Connection));
    if (SUCCEEDED(hr))
    {
        try
        {
            // 连接字符串
            CString strConnect;
            strConnect.Format(_T("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=Robot.mdb;"));

            // 打开数据库连接
            m_pConnection->Open((_bstr_t)strConnect, "", "", adModeUnknown);

            // 连接成功
            AfxMessageBox(_T("连接成功！"));
        }
        catch (_com_error& e)
        {
            // 连接失败
            CString strError = e.ErrorMessage();
            AfxMessageBox(strError);
        }
    }
}

void CRobot::InitRobot()
{
	_variant_t type, name, x, y, r, w, h;
	try
    {
        // 创建ADO记录集对象
        m_pRecordset.CreateInstance(__uuidof(Recordset));

        // 执行SQL查询语句
        CString strSQL = _T("SELECT * FROM Robot");
        m_pRecordset->Open((_bstr_t)strSQL, m_pConnection.GetInterfacePtr(), adOpenStatic, adLockOptimistic, adCmdText);

        // 遍历记录集
        while (!m_pRecordset->adoEOF)
        {
            // 读取字段值
            type = m_pRecordset->Fields->GetItem(_variant_t("type"))->Value;
			name = m_pRecordset->Fields->GetItem(_variant_t("name"))->Value;
			x = m_pRecordset->Fields->GetItem(_variant_t("x"))->Value;
			y = m_pRecordset->Fields->GetItem(_variant_t("y"))->Value;
			r = m_pRecordset->Fields->GetItem(_variant_t("r"))->Value;
			w = m_pRecordset->Fields->GetItem(_variant_t("w"))->Value;
			h = m_pRecordset->Fields->GetItem(_variant_t("h"))->Value;

			// 类型转换
			m_Body[m_nBody].type = _ttoi((LPCTSTR)(_bstr_t)type);
			m_Body[m_nBody].x = _ttoi((LPCTSTR)(_bstr_t)x);
			m_Body[m_nBody].y = _ttoi((LPCTSTR)(_bstr_t)y);
			m_Body[m_nBody].r = _ttoi((LPCTSTR)(_bstr_t)r);
			m_Body[m_nBody].w = _ttoi((LPCTSTR)(_bstr_t)w);
			m_Body[m_nBody].h = _ttoi((LPCTSTR)(_bstr_t)h);

			m_Body[m_nBody].name = CString(name.bstrVal);

            // 移动到下一条记录
            m_pRecordset->MoveNext();

			m_nBody++;
        }

        // 关闭记录集
        m_pRecordset->Close();
    }
    catch (_com_error& e)
    {
        CString strError = e.ErrorMessage();
        AfxMessageBox(strError);
    }
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
			x = m_YD.x + m_Body[i].x * m_kx;
			y = m_YD.y + m_Body[i].y * m_ky;
			w = m_Body[i].w * m_kx;
			h = m_Body[i].h * m_kx;
			pDC->Rectangle(x, y, x + w, y + h);
		}
	}
}
