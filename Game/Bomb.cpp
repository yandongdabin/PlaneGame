#include "StdAfx.h"
#include "Bomb.h"
CImageList CBomb::m_Images[4];
int CBomb::m_V =10;
int CBomb::m_Count = 2;
int CBomb::bombtype = 0;
CBomb::CBomb(int x,int y,int index)
{
	m_ptPos.x = x;
	m_ptPos.y = y;
	this->index = index;
	//m_V = 20;
}
CBomb::CBomb()
{
	
}
CBomb::~CBomb(void)
{
}
BOOL CBomb::Draw(CDC* pDC,BOOL bPause)
{
	m_Images[bombtype].Draw(pDC,0,m_ptPos,ILD_TRANSPARENT);
	return TRUE;
}
BOOL CBomb::LoadImage()
{
	CGameObject::LoadImage(m_Images[0],IDB_BOMB,RGB(0,0,0),BOMB_WIDTH,BOMB_HEIGHT,1);
	CGameObject::LoadImage(m_Images[1],IDB_BOMB2,RGB(0,0,0),BOMB_WIDTH,BOMB_HEIGHT,1);
	CGameObject::LoadImage(m_Images[2],IDB_BOMB3,RGB(0,0,0),BOMB_WIDTH,BOMB_HEIGHT,1);
	CGameObject::LoadImage(m_Images[3],IDB_BOMB4,RGB(255,255,255),BOMB_WIDTH,BOMB_HEIGHT,1);
	return TRUE;
}