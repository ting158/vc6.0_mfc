// Room.h: interface for the CRoom class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ROOM_H__11C791E2_0D1B_485A_A3BE_234D62F78E18__INCLUDED_)
#define AFX_ROOM_H__11C791E2_0D1B_485A_A3BE_234D62F78E18__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


//家具结构体
typedef struct
{
	char name[20];
	float pos[4][2];
}SFurniture;

//房间类
class CRoom  
{
public:
	void Draw(CDC *p);
	void InitFurniture();
	CRoom();
	virtual ~CRoom();

	
	CDC *pDC;
	float m_kx, m_ky;
	CPoint m_YD;

	float m_w;

	SFurniture m_Fur[20];
	int m_nFur;
};

#endif // !defined(AFX_ROOM_H__11C791E2_0D1B_485A_A3BE_234D62F78E18__INCLUDED_)
