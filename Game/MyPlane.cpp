#include "StdAfx.h"
#include "MyPlane.h"
#include "Resource.h"
CImageList CMyPlane::m_Images;
CMyPlane::CMyPlane(void)
{
	m_ptPos.x = 300;
	m_ptPos.y = 300;
	m_nHorMotion = 0;
	m_nVerMotion = 0;
	me_Life = 8;
	BigFire = 5;
}

CMyPlane::~CMyPlane(void)
{
}
BOOL CMyPlane::Draw(CDC* pDC,BOOL bPause)
{
	
	m_ptPos.x = m_ptPos.x + m_nHorMotion * 10;
	m_ptPos.y = m_ptPos.y + m_nVerMotion * 10;
	if(m_ptPos.x <0)
		m_ptPos.x = 0;
	else if(m_ptPos.x>590)
		m_ptPos.x = 590;
	if(m_ptPos.y<0)
		m_ptPos.y=0;
	else if(m_ptPos.y>690)
	{
		m_ptPos.y=690;
	}
		
	m_Images.Draw(pDC,0,m_ptPos,ILD_TRANSPARENT);
	return TRUE;
}
BOOL CMyPlane::LoadImage()
{
	CBitmap bmp;
	if(!bmp.LoadBitmap(IDB_ME))
		return FALSE;

	if(!m_Images.Create(PLANE_WIDTH, PLANE_HEIGHT, ILC_COLOR8|ILC_MASK, 1, 0))
		return FALSE;
	

	m_Images.Add(&bmp, RGB(0,0,0));

	return TRUE;
}