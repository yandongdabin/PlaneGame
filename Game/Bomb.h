#pragma once
#include "gameobject.h"
#include "Resource.h"
class CBomb :
	public CGameObject
{
public:
	CBomb(int x,int y,int index);
	CBomb();
	~CBomb(void);

	BOOL Draw(CDC* pDC,BOOL bPause);

	static BOOL LoadImage();
	static int m_V;
	static int m_Count;//表示一次发出的数目

	//子弹的加减速
	static void Add_V()
	{
		m_V+=20;
	}
	static void Sub_V()
	{
		m_V-=5;
	}
	//单发子弹的数目
	static void Add_Count()
	{
		m_Count ++;
	}
	static void Sub_Count()
	{
		m_Count --;
	}
	static int Get_Count()
	{
		return m_Count;
	}
	//用于游戏的初始化
	static void Resume_Count()
	{
		m_Count = 2;
	}
	CRect GetRect()
	{
		return CRect(m_ptPos,CPoint(m_ptPos.x+10,m_ptPos.y+BOMB_HEIGHT));
	}
	void SetPos()
	{
		m_ptPos.y -= m_V;
	}
	int GetIndex()
	{
		return index;
	}
	static int GetType()//得到类型
	{
		return bombtype;
	}
	static void ResumeBomb()
	{
		bombtype = 0;
	}
	static int getHurt()//得到伤害
	{
		return bombtype+1;
	}
	static void setType()//设置类型
	{
		bombtype+=1;
		if(bombtype>4)bombtype=3;
	}
private:
	static const int BOMB_HEIGHT = 20;
	static const int BOMB_WIDTH = 10;
	static CImageList m_Images[4];
	int n_Motion;//表示炸弹的方向
	int index;//记录who
	static int bombtype;//用在升级上

};
