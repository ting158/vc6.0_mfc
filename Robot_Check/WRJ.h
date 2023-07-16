// WRJ.h: interface for the CWRJ class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WRJ_H__1AB129C6_BBA4_4BB1_9B0F_9B65DFE27521__INCLUDED_)
#define AFX_WRJ_H__1AB129C6_BBA4_4BB1_9B0F_9B65DFE27521__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Car.h"

class CWRJ : public CCar  
{
public:
	void LuoXuanJiangXuanZhuan();
	void DrawLuoXuanJiang(int x, int y);
	void Move(UINT nChar);
	void DrawWuRenJi();
	void Draw(CDC *p);
	CWRJ();
	virtual ~CWRJ();

	float m_x, m_y;
	float m_r;
	float m_JDlxj;  //ÂÝÐý½°½Ç¶È

	int m_nd;
};

#endif // !defined(AFX_WRJ_H__1AB129C6_BBA4_4BB1_9B0F_9B65DFE27521__INCLUDED_)
