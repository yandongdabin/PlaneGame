#pragma once
#include "gameobject.h"

class CBall :public CGameObject
{
public:
	CBall(int x,int y,int nMontion,int who = 0);//0����л�
	~CBall(void);

	BOOL Draw(CDC* pDC,BOOL bPause);

	static BOOL LoadImage();

	CRect GetRect()
	{
		return CRect(m_ptPos,CPoint(m_ptPos.x+BALL_HEIGHT,m_ptPos.y+BALL_HEIGHT));
	}
	void SetPos()
	{
		m_ptPos.y +=m_nMotion * 10;//�ӵ����ٶ�
	}
	int getWho()
	{
		return who;
	}
private:
	static const int BALL_HEIGHT=8;
	static CImageList m_Images;
	int    m_nMotion;
	int who;
};

