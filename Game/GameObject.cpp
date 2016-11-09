#include "StdAfx.h"
#include "GameObject.h"


CGameObject::~CGameObject(void)
{
}
CGameObject::CGameObject(int x,int y):m_ptPos(x,y)
{
	
}
BOOL CGameObject::LoadImage(CImageList& imgList,UINT bmpID,COLORREF crMask,int cx,int cy,int nInitial)
{
	CBitmap bmp;
	if(!bmp.LoadBitmap(bmpID))
		return FALSE;

	if(!imgList.Create(cx, cy, ILC_COLOR8|ILC_MASK, nInitial, 0))
		return FALSE;
	

	imgList.Add(&bmp, crMask);

	return TRUE;
}
