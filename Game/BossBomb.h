#pragma once
#include "bomb.h"

class CBossBomb :
	public CBomb
{
public:
	CBossBomb(int x,int y,int motion,int who=0,int index=0);
	void SetPos();
	static BOOL _LoadImage();
	BOOL Draw(CDC* pDC,BOOL bPause);
	~CBossBomb(void);
	int getWho()
	{
		return who;
	}
private:
	static CImageList me_Images[3];
	static const int BOSSBOMB_HEIGHT = 20;
	static const int BOSSBOMB_WIDTH = 10;
	int m_motion;
	int index;
	int who;
};
