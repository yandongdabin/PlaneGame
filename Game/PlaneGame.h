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
	void OnDraw(CDC* pDC);  // 重写以绘制该视图
	CPlaneGame(void);
	~CPlaneGame(void);

protected:
	//内存DC
	CDC        m_pMemDC;
	//设备DC
	//CClientDC  m_pDC;
	//内存位图
	CBitmap    m_pMemBitmap;
	CBitmap    *oldBit;

protected:
	
	void CheckOver();
	//void AI();

	//获得键的状态1->down
	int GetKey(int nVirtKey)
	{
		return (GetKeyState(nVirtKey) & 0x8000)? 1 : 0;
	}

	CMyPlane   m_Me[2];
	CPlaneBoss m_Boss;
	int Status;// 1 开始 2 暂停 3结束
	long long Score[2];//记录分值
	//int Result; // 0 待定 1胜利 2失败
	int pass;//记录关卡
	int flag_show_next;//记录关卡转换的标记
	CObList    m_ObjList[7]; //用链表来管理游戏对象
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
	void SetMeMotion(int type,int motion,int index = 0);//设置我机的位置
	void SetEnemyPosition(); //设置敌机的位置
	void SetBallPosition();
	void SetBombPosition();
	void SetChangePositoin();
	void SetBossPosition();
	void SetBossBombPosition();
	//初始化游戏
	void Fire(int i);//本机开火
	BOOL InitGame();
	//刷新游戏的帧画面
	void UpdateFrame(HWND hwnd,CDC *pDC);
	//结束游戏
	void StopGame();//暂停游戏
	void ResumeGame();//恢复游戏
	void GameOver();//游戏结束
	void CheckFire();//开火
	int  GetStatus();//返回游戏状态
	void SetScore(int index);//设置分数
	void GotoNext();//进入下一关
	void NextGame();//进入下一关卡
	void StartFromOver();//重新开始游戏
	void StaBigFire(int index);//产生全屏大招
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
