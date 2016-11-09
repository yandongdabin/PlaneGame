#include "StdAfx.h"
#include "PlaneBoss.h"
CImageList CPlaneBoss::m_Images[3];
CPlaneBoss::CPlaneBoss()
{
	
	m_ptPos.x = rand() %650;
	m_ptPos.y = rand() %100;
	
	m_V = 5;
	pri_pt[0].x=100;
	pri_pt[0].y=100;
	pri_pt[1].x=100;
	pri_pt[1].y=100;
	index =abs(rand()%3);
	if(index ==0)
		me_Life = 50;
	else if(index ==1)
		me_Life = 100;
	else if(index == 2)
		me_Life = 150;
}

CPlaneBoss::~CPlaneBoss(void)
{
}
BOOL CPlaneBoss::Draw(CDC* pDC,BOOL bPause)
{
	m_Images[index].Draw(pDC,0,m_ptPos,ILD_TRANSPARENT);
	
	return TRUE;
}
BOOL CPlaneBoss::LoadImage()
{
	
	/*CBitmap bmp;
	if(!bmp.LoadBitmap(IDB_BOSS))
		return FALSE;

	if(!m_Images.Create(BOSS_WIDTH, BOSS_HEIGHT, ILC_COLOR8|ILC_MASK, 1, 0))
		return FALSE;
	

	m_Images.Add(&bmp,RGB(255,255,255));*/
	//return CGameObject::LoadImage(m_Images,IDB_BOSS2,RGB(255,255,255),BOSS_WIDTH,BOSS_HEIGHT,1);
	CGameObject::LoadImage(m_Images[0],IDB_ANGEL,RGB(255,0,0),BOSS_WIDTH,BOSS_HEIGHT,1);
	CGameObject::LoadImage(m_Images[1],IDB_GAR,RGB(255,0,0),BOSS_WIDTH,BOSS_HEIGHT,1);
	CGameObject::LoadImage(m_Images[2],IDB_SKE,RGB(255,0,0),BOSS_WIDTH,BOSS_HEIGHT,1);
	return TRUE;
}
BOOL CPlaneBoss::Fired()
{
	
	return FALSE;
}
void CPlaneBoss::AI(CPoint me_point,CPoint me_point1,int x,int y)
{
	int index;
	if(abs(me_point.x-m_ptPos.x)<abs(me_point1.x-m_ptPos.x)&& x >0)
		index=0;
	else index = 1;
	if(y<=0)index = 0;
	if(x <=0)index =1;
	if(index == 0)
	{
		if(pri_pt[0].x !=me_point.x || pri_pt[0].y !=me_point.y)
		{
			if(m_ptPos.y > 0 && m_ptPos.y <50)
			{
				m_ptPos.y +=rand()%10;
			}
			pri_pt[0].x = me_point.x;
			pri_pt[0].y = me_point.y;
		}
		if(me_point.x - m_ptPos.x > 0)
		{
			m_ptPos.x +=abs(rand()%m_V);
		}
		else if(me_point.x - m_ptPos.x <= -10)
		{
			m_ptPos.x -=abs(rand()%m_V);
		}
	}
	if(index ==1)
	{
		if(pri_pt[1].x !=me_point1.x || pri_pt[1].y !=me_point1.y)
		{
			if(m_ptPos.y > 0 && m_ptPos.y <50)
			{
				m_ptPos.y +=rand()%10;
			}
			pri_pt[1].x = me_point1.x;
			pri_pt[1].y = me_point1.y;
		}
		if(me_point1.x - m_ptPos.x > 0)
		{
			m_ptPos.x +=abs(rand()%m_V);
		}
		else if(me_point1.x - m_ptPos.x <= -10)
		{
			m_ptPos.x -=abs(rand()%m_V);
		}
	}
	
	if(m_ptPos.y < 0 )
	{
		m_ptPos.y +=rand()%10;
	}
	if(m_ptPos.y >=50)
	{
		m_ptPos.y -=abs(rand()%10);
	}
}