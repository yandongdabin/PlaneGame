#pragma once
#include "gameobject.h"
//#include "Winuser.h"
class CMyPlane :public CGameObject
{
public:
	CMyPlane(void);
	~CMyPlane(void);
	/*CMyPlane(CMyPlane &plane)
	{
		
	}*/

	BOOL Draw(CDC* pDC,BOOL bPause);

	static BOOL LoadImage();

	void SetHorMotion(int nMotion)
	{
		m_nHorMotion = nMotion;
	}
	int GetHorMotion() const
	{
		return m_nHorMotion;
	}

	void SetVerMotion(int nMotion)
	{
		m_nVerMotion = nMotion;
	}
	int GetVerMotion() const
	{
		return m_nVerMotion;
	}

	CRect GetRect()
	{
		return CRect(m_ptPos,CPoint(m_ptPos.x+PLANE_WIDTH,m_ptPos.y+PLANE_HEIGHT));
	}
	void GetHurt()
	{
		me_Life--;
		/*if(me_Life <=0)
			me_Life = 10;*/
	}
	void GetCure()
	{
		if(me_Life >0)
		me_Life+=1;
		if(me_Life>=20)me_Life=20;
	}
	void SetLife()
	{
		me_Life = 0;
	}
	int GetLife()
	{
		return me_Life;
	}
	void Resume_Life()
	{
		me_Life = 8;
		BigFire = 5;
	}
	int GetBig()
	{
		return BigFire;
	}
	void AddBig()
	{
		BigFire++;
	}
	void SubBig()
	{
		BigFire--;
	}
	void Die(int x,int y)
	{
		m_ptPos.x = x;
		m_ptPos.y = y;
	}

	//�Ƿ���Կ����䵼��
	BOOL Fired();
	int me_Life;//��¼Ѫ��
	int BigFire;//��¼������Ŀ

public:
	static const int PLANE_WIDTH=50;
	static const int PLANE_HEIGHT=60;
private:
	
	static CImageList m_Images;
	int    m_nHorMotion;//�ɻ�ˮƽ���з���0->��ֹ��1->�� -1->��
	int    m_nVerMotion;//�ɻ���ֱ���з���0->��ֹ��1->�� -1->��
	int    m_nWait;//������ʱ
};

