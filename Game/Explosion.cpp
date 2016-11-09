#include "StdAfx.h"
#include "Explosion.h"
#include "Resource.h"
CImageList CExplosion::m_Images;
CExplosion::CExplosion(int x,int y)
{
	m_ptPos.x=x;
	m_ptPos.y=y;
	m_index = 0;
}

CExplosion::~CExplosion(void)
{
}
BOOL CExplosion::Draw(CDC* pDC,BOOL bPause)
{
	//for(int i=0;i<8;i++)
	m_Images.Draw(pDC,m_index++,m_ptPos,ILD_TRANSPARENT);

	return TRUE;
}
BOOL CExplosion::LoadImage()
{
	return CGameObject::LoadImage(m_Images,IDB_EXPLOSION,RGB(0,0,0),EXPLOSION_WIDTH,EXPLOSION_WIDTH,1);
}
int CExplosion::GetIndex()
{
	return m_index;
}
