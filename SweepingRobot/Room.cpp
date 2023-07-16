// Room.cpp: implementation of the CRoom class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SweepingRobot.h"
#include "Room.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CRoom::CRoom()
{
	m_kx = 150;
	m_ky = -m_kx;
	m_YD.x = 500;
	m_YD.y = 800;

	m_w = 4.8;


	m_nFur = 0;

	InitFurniture();
}

CRoom::~CRoom()
{

}

void CRoom::InitFurniture()
{
	FILE *pf = fopen("furniture.txt", "r");

	if (pf == NULL)
		return;

	while(!feof(pf))
	{
		fscanf(pf, "%s %f %f %f %f %f %f %f %f", 
			m_Fur[m_nFur].name,
			&(m_Fur[m_nFur].pos[0][0]), &(m_Fur[m_nFur].pos[0][1]), 
			&(m_Fur[m_nFur].pos[1][0]), &(m_Fur[m_nFur].pos[1][1]), 
			&(m_Fur[m_nFur].pos[2][0]), &(m_Fur[m_nFur].pos[2][1]), 
			&(m_Fur[m_nFur].pos[3][0]), &(m_Fur[m_nFur].pos[3][1]));
		m_nFur++;
	}

}

void CRoom::Draw(CDC *p)
{
	int x, y, w, i;
	CPoint pos[4];
	pDC = p;

	x = m_YD.x;
	y = m_YD.y + m_w * m_ky;
	w = m_w * m_kx;
	pDC->Rectangle(x, y, x + w, y + w);

	for (i = 0; i < m_nFur; i++)
	{
		pos[0].x = m_YD.x + m_Fur[i].pos[0][0] * m_kx;
		pos[0].y = m_YD.y + m_Fur[i].pos[0][1] * m_ky;
		pos[1].x = m_YD.x + m_Fur[i].pos[1][0] * m_kx;
		pos[1].y = m_YD.y + m_Fur[i].pos[1][1] * m_ky;
		pos[2].x = m_YD.x + m_Fur[i].pos[2][0] * m_kx;
		pos[2].y = m_YD.y + m_Fur[i].pos[2][1] * m_ky;
		pos[3].x = m_YD.x + m_Fur[i].pos[3][0] * m_kx;
		pos[3].y = m_YD.y + m_Fur[i].pos[3][1] * m_ky;

		pDC->Polygon(pos, 4);
	}

}
