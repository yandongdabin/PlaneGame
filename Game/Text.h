#pragma once
#include "gameobject.h"

class CText :public CGameObject
{
public:
	CText(int x,int y);
	CText(int x,int y,CString str);
	~CText(void);

	BOOL Draw(CDC* pDC,BOOL bPause);
	CString str;
	
	CRect GetRect()
	{
		return CRect(m_ptPos,CPoint(m_ptPos.x,m_ptPos.y));
	}
};

