#include "StdAfx.h"
#include "Enemy.h"
#include "Resource.h"
CImageList CEnemy::m_Images;
CEnemy::CEnemy()
{
	
	m_V = abs(rand() % 5)+2;
	m_nMotion = rand()%2 ? 1 : -1;
	if(m_nMotion == 1)
	{
		m_ptPos.y = -1*abs(rand()%100);
	}
	else
	{
		m_ptPos.y = 850+abs(rand()%100);
	}
	m_ptPos.x = rand()%600;
}

CEnemy::~CEnemy(void)
{
}
BOOL CEnemy::Draw(CDC* pDC,BOOL bPause)
{
	//m_ptPos.x = m_ptPos.x + m_nMotion* 10;
	//m_ptPos.y = m_ptPos.y + m_nMotion* 10;
	if(m_ptPos.y > 900)
	{
		m_ptPos.y=-1*abs(rand()%50);
	}
	else if(m_ptPos.y<-100)
	{
		m_ptPos.y =800+abs(rand()%50);
	}
	if(m_nMotion == 1)
		m_Images.Draw(pDC,0,m_ptPos,ILD_TRANSPARENT);
	else if(m_nMotion == -1)
		m_Images.Draw(pDC,1,m_ptPos,ILD_TRANSPARENT);
	return TRUE;
}
BOOL CEnemy::LoadImage()
{
	return CGameObject::LoadImage(m_Images,IDB_ENEMY,RGB(0,0,0),ENEMY_HEIGHT,ENEMY_HEIGHT,1);
}
BOOL CEnemy::Fired()
{
	
	return FALSE;
}