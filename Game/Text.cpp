#include "StdAfx.h"
#include "Text.h"

CText::CText(int x,int y)
{
	m_ptPos.x=x;
	m_ptPos.y=y;
}
CText::CText(int x,int y,CString str)
{
	m_ptPos.x=x;
	m_ptPos.y=y;
	this->str = str;
}

CText::~CText(void)
{

}
BOOL CText::Draw(CDC* pDC,BOOL bPause)
{
	//CString str("Game Over");
	pDC->SetTextColor(RGB(0,0,255));
	pDC->TextOut(m_ptPos.x,m_ptPos.y,str);
	return TRUE;
}
