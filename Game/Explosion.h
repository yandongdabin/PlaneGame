#pragma once
#include "gameobject.h"

class CExplosion :public CGameObject
{
public:
	CExplosion(int x,int y);
	~CExplosion(void);

	BOOL Draw(CDC* pDC,BOOL bPause);

	static BOOL LoadImage();

	CRect GetRect()
	{
		return CRect(m_ptPos,CPoint(m_ptPos.x+EXPLOSION_WIDTH,m_ptPos.y+EXPLOSION_WIDTH));
	}
	int GetIndex();
private:
	//炸弹的图片列表
	static CImageList m_Images;

	int m_index;//图像索引
	//图像索引的步进计数
	int   m_nProcess;
public:
	static const int  EXPLOSION_WIDTH = 66;

};
