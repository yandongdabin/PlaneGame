#pragma once
#pragma comment(lib, "winmm.lib")
#include "MyPlane.h"
#include "Enemy.h"
#include "Ball.h"
#include "Explosion.h"
#include "Text.h"
#include "Bomb.h"
#include "GameChange.h"
#include "PlaneBoss.h"
#include "BossBomb.h"
#include "Mmsystem.h"


class CPlaneGame
{
public:
	void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	CPlaneGame(void);
	~CPlaneGame(void);

protected:
	//�ڴ�DC
	CDC        m_pMemDC;
	//�豸DC
	//CClientDC  m_pDC;
	//�ڴ�λͼ
	CBitmap    m_pMemBitmap;
	CBitmap    *oldBit;

protected:
	
	void CheckOver();
	//void AI();

	//��ü���״̬1->down
	int GetKey(int nVirtKey)
	{
		return (GetKeyState(nVirtKey) & 0x8000)? 1 : 0;
	}

	CMyPlane   m_Me[2];
	CPlaneBoss m_Boss;
	int Status;// 1 ��ʼ 2 ��ͣ 3����
	long long Score[2];//��¼��ֵ
	//int Result; // 0 ���� 1ʤ�� 2ʧ��
	int pass;//��¼�ؿ�
	int flag_show_next;//��¼�ؿ�ת���ı��
	CObList    m_ObjList[7]; //��������������Ϸ����
	// 0 Enemy
	// 1 bomb
	// 2 ball
	// 3 explosion
	// 4 GameChange
	// 5 BossBomb
	// 6 Boss

	POINT m_LifePt[20],m_LifePt1[20];
	int shutdown;
public:
	void SetMeMotion(int type,int motion,int index = 0);//�����һ���λ��
	void SetEnemyPosition(); //���õл���λ��
	void SetBallPosition();
	void SetBombPosition();
	void SetChangePositoin();
	void SetBossPosition();
	void SetBossBombPosition();
	//��ʼ����Ϸ
	void Fire(int i);//��������
	BOOL InitGame();
	//ˢ����Ϸ��֡����
	void UpdateFrame(HWND hwnd,CDC *pDC);
	//������Ϸ
	void StopGame();//��ͣ��Ϸ
	void ResumeGame();//�ָ���Ϸ
	void GameOver();//��Ϸ����
	void CheckFire();//����
	int  GetStatus();//������Ϸ״̬
	void SetScore(int index);//���÷���
	void GotoNext();//������һ��
	void NextGame();//������һ�ؿ�
	void StartFromOver();//���¿�ʼ��Ϸ
	void StaBigFire(int index);//����ȫ������
	void SetSingle(BOOL single);
	void Destroy();
	BOOL Single;
	int  GetPass()
	{
		return pass;
	}
	BOOL getSingle()
	{
		return Single;
	}
	void Set_Status(int s)
	{
		Status = s;
	}

};
