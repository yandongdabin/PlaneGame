#include "StdAfx.h"
#include "Ball.h"
#include "Resource.h"
CImageList CBall::m_Images;
CBall::CBall(int x,int y,int nMontion,int wh)
{
	m_ptPos.x = x;
	m_ptPos.y = y;
	m_nMotion = nMontion;
	who = wh;
}

CBall::~CBall(void)
{
}
BOOL CBall::Draw(CDC* pDC,BOOL bPause)
{
	m_Images.Draw(pDC,0,m_ptPos,ILD_TRANSPARENT);
	return TRUE;
}
BOOL CBall::LoadImage()
{
	return CGameObject::LoadImage(m_Images,IDB_BALL,RGB(0,0,0),BALL_HEIGHT,BALL_HEIGHT,1);
}
