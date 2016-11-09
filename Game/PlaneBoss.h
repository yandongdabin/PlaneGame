#pragma once
#include "gameobject.h"
#include "Resource.h"
#include "MyPlane.h"

class CPlaneBoss :
	public CGameObject
{
public:
	CPlaneBoss(void);
	~CPlaneBoss(void);
	BOOL Draw(CDC* pDC,BOOL bPause);

	static BOOL LoadImage();
	
	CRect GetRect()
	{
		return CRect(m_ptPos,CPoint(m_ptPos.x+BOSS_HEIGHT,m_ptPos.y+BOSS_HEIGHT));
	}

	/*void SetPos()
	{
		m_ptPos.x + 10;
		m_ptPos.y += rand()%5;
	}*/
	int Get_Life()
	{
		return me_Life;	
	}
	void GetHurt()
	{
		me_Life --;
	}
	int GetIndex()
	{
		return index;
	}
	void AI(CPoint m_Me_Point,CPoint m_Me_Point1,int x,int y);
	//是否可以开火发射子弹
	BOOL Fired();
private:
	static const int BOSS_HEIGHT = 90;
	static const int BOSS_WIDTH = 70;
	static CImageList m_Images[3];
	//static CImageList m_Images;
	CPoint pri_pt[2];//记录战机上一次的位置
	//速度
	int m_V;
	int me_Life;
	int index;
};
