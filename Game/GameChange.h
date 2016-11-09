#pragma once
#include "gameobject.h"
#include "Resource.h"
class CGameChange :
	public CGameObject
{
public:
	CGameChange(void);
	~CGameChange(void);

	BOOL Draw(CDC* pDC,BOOL bPause);
	
	static BOOL LoadImage();
	CRect GetRect()
	{
		return CRect(m_ptPos,CPoint(m_ptPos.x+CHANGE_WIDTH,m_ptPos.y+CHANGE_HEIGHT));
	}
	void SetPos()
	{
		m_ptPos.y += 3;
	}
	int GetIndex()
	{
		return index;	
	}
private:
	static const int CHANGE_HEIGHT = 29;
	static const int CHANGE_WIDTH = 43;
	static CImageList m_Images[4];
	int index;

};

