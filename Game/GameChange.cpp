#include "StdAfx.h"
#include "GameChange.h"


CImageList CGameChange::m_Images[4];
CGameChange::CGameChange(void)
{
	m_ptPos.x = rand() % 600;
	m_ptPos.y = -abs(rand()%100);
	index = abs(rand()%4);
}

CGameChange::~CGameChange(void)
{
}
BOOL CGameChange::Draw(CDC* pDC,BOOL bPause)
{
	m_Images[index].Draw(pDC,0,m_ptPos,ILD_TRANSPARENT);
	return TRUE;
}
BOOL CGameChange::LoadImage()
{
	
	CGameObject::LoadImage(m_Images[0],IDB_ADDLIFE,RGB(255,255,255),CHANGE_WIDTH,CHANGE_HEIGHT,1);
	CGameObject::LoadImage(m_Images[1],IDB_SETTYPE,RGB(255,255,255),CHANGE_WIDTH,CHANGE_HEIGHT,1);
	CGameObject::LoadImage(m_Images[2],IDB_CHANGE3,RGB(255,255,255),CHANGE_WIDTH,CHANGE_HEIGHT,1);
	CGameObject::LoadImage(m_Images[3],IDB_CHANGE4,RGB(255,255,255),CHANGE_WIDTH,CHANGE_HEIGHT,1);
	return TRUE;
}


