#include "StdAfx.h"
#include "BossBomb.h"
CImageList CBossBomb::me_Images[3];
CBossBomb::CBossBomb(int x,int y,int motion,int wh,int in)
{
	m_ptPos.x = x;
	m_ptPos.y = y;
	m_motion = motion;
	index =in;
	who =wh;//¼ÇÂ¼·¢ÉäÕß
}

CBossBomb::~CBossBomb(void)
{
}
void CBossBomb::SetPos()
{
	m_ptPos.y +=m_V;
	m_ptPos.x +=m_motion*2;
}
BOOL CBossBomb::_LoadImage()
{
	CGameObject::LoadImage(me_Images[0],IDB_BOSSBOMB3,RGB(255,255,255),BOSSBOMB_WIDTH,BOSSBOMB_HEIGHT,1);
	CGameObject::LoadImage(me_Images[1],IDB_BOSSBOMB2,RGB(0,0,0),BOSSBOMB_WIDTH,BOSSBOMB_HEIGHT,1);
	CGameObject::LoadImage(me_Images[2],IDB_BOSSBOMB1,RGB(255,255,255),BOSSBOMB_WIDTH,BOSSBOMB_HEIGHT,1);
	return TRUE;
}
BOOL CBossBomb::Draw(CDC* pDC,BOOL bPause)
{
	me_Images[index].Draw(pDC,0,m_ptPos,ILD_TRANSPARENT);
	return TRUE;
}
//int CBossBomb::m_V = 5;