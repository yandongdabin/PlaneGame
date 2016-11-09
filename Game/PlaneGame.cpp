#include "StdAfx.h"
#include "PlaneGame.h"

CPlaneGame::CPlaneGame(void)
{
	flag_show_next = 0;
	pass = 1;
	Score[0] = 0;//��ֵΪ��
	Score[1] = 0;
	for(int i=0;i<20;i++)
	{
		m_LifePt[i].x = 610-i*20;
		m_LifePt[i].y = 10;
	}
	for(int i=0;i<20;i++)
	{
		m_LifePt1[i].x = 610-i*20;
		m_LifePt1[i].y = 20;
	}
	Single = FALSE;
	CMyPlane::LoadImage();
	CEnemy::LoadImage();
	CBall::LoadImage();
	CExplosion::LoadImage();//���ر�ը����
	CBomb::LoadImage();
	CGameChange::LoadImage();
	CPlaneBoss::LoadImage();
	CBossBomb::_LoadImage();
	
}
void CPlaneGame::SetSingle(BOOL single)
{
	Single = single;
}
CPlaneGame::~CPlaneGame(void)
{
}
BOOL CPlaneGame::InitGame()
{
	
	if(!Single)//���˵�ʱ��
	{
		m_Me[1].SetLife();
	}
	if(Single)//˫��
	{
		m_Me[0].Die(200,350);
		m_Me[1].Die(400,350);
	}
	
	
	for(int i=0;i<2;i++) //���صл�
	{
		m_ObjList[0].AddTail(new CEnemy());
	}
	/*for(int i=0;i<2;i++) //���صл�
	{
		m_ObjList[6].AddTail(new CPlaneBoss());
	}*/
	Status = 1;//��Ϸ״̬Ϊ����̬
	
	shutdown =0;
	//Result = 0;//��Ϸ����ݶ�
	//pass = 30;//��ʼ���ؿ���
	//CString str(m_ObjList[0].GetSize());
	//MessageBox(NULL,str);
	//m_ObjList[1].AddTail(new CBall(100,100,1));
	//CString buffer("open \"../music/1.mp3\" alias file");//���ű�������
	//mciSendString(buffer,NULL,0,NULL);
	//CString buffer1("play file");
	//mciSendString(buffer1,NULL,0,NULL);
	//mciSendCommand(0,MCI_OPEN,MCI_OPEN_TYPE   |   MCI_OPEN_ELEMENT,(DWORD)&mciOpen);    
	return TRUE;

}
void CPlaneGame::NextGame()//������һ����Ϸ
{
	
	
		for(int i=0;i<2*pass;i++) //�л�
			{
				m_ObjList[0].AddTail(new CEnemy());
			}
			Status = 1;
			flag_show_next = 0;//������Ϸͣ�ٵı��
		if(pass/10)
		{
			for(int i=0;i<pass/10*2;i++)
			m_ObjList[6].AddTail(new CPlaneBoss());
		}
			//Result = 0;//�þ���Ϸ����ݶ�
	
}
void CPlaneGame::StopGame()
{
	Status = 2;//����״̬��ͣ
}
void CPlaneGame::ResumeGame()
{
	Status = 1;//����״̬��ʼ
}
void CPlaneGame::UpdateFrame(HWND hwnd,CDC *pDC)//��Ϸ��ˢ��֡
{
	CRect rect;
	CEnemy *temp_enemy;
	CBall *temp_ball;
	CExplosion *temp_Ex;
	CBomb *temp_Bomb;
	CPlaneBoss *temp_boss;
	CBossBomb *temp_BossBomb;
	CGameObject *temp_change;
	POSITION pos,pos1,pos2;
	int i;

	//˫����
	GetClientRect(hwnd,&rect);
	m_pMemDC.CreateCompatibleDC(pDC);
	//m_pDC = pDC;

	//m_pMemBitmap.CreateCompatibleBitmap(pDC,rect.Width(),rect.Height());
	m_pMemBitmap.LoadBitmapW(IDB_BACK);
	
	oldBit = m_pMemDC.SelectObject(&m_pMemBitmap);
	//m_pMemDC.
	//m_pMemDC.FillSolidRect(&rect,RGB(0,255,255));//������ɫ
	CFont font;
	HGDIOBJ oldfont;//��������
	COLORREF oldcolor;//������ɫ
	font.CreateFont(20,0,0,0,FW_NORMAL,FALSE,FALSE,0,ANSI_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH | FF_SWISS,_T("Times New Roman")); 
	m_pMemDC.SetBkMode(TRANSPARENT);
	oldfont =m_pMemDC.SelectObject(font);
	oldcolor = m_pMemDC.SetTextColor(0xFFFF99);
	CString str_pass;
	//if(pass >100) pass=100;
	str_pass.Format(_T("��ǰ�ؿ�:%d"),pass);
	CString str_obj1,str_obj2,str_obj3,str_obj4,str_obj5,str_obj6,str_obj7;
	
	str_obj1.Format(_T("�л���Ŀ��%d"),m_ObjList[0].GetSize());
	str_obj2.Format(_T("������Ŀ��%d"),m_ObjList[1].GetSize());
	str_obj3.Format(_T("ը����Ŀ��%d"),m_ObjList[2].GetSize());
	str_obj4.Format(_T("��ը��Ŀ��%d"),m_ObjList[3].GetSize());
	str_obj5.Format(_T("������Ŀ: %d"),m_ObjList[4].GetSize());
	str_obj6.Format(_T("1P ������Ŀ: %d"),m_Me[0].GetBig());
	
	str_obj7.Format(_T("2P ������Ŀ: %d"),m_Me[1].GetBig());
	m_pMemDC.TextOutW(0,30,str_obj1);
	//m_pMemDC.TextOutW(0,50,str_obj2);
	//m_pMemDC.TextOutW(0,70,str_obj3);
	//m_pMemDC.TextOutW(0,90,str_obj4);
	//m_pMemDC.TextOutW(0,110,str_obj5);
	m_pMemDC.TextOutW(0,50,str_obj6);
	if(Single)
	m_pMemDC.TextOutW(0,100,str_obj7);
	font.DeleteObject();
	font.CreateFont(25,0,0,0,FW_NORMAL,FALSE,FALSE,0,ANSI_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH | FF_SWISS,_T("Arial")); 
	m_pMemDC.SelectObject(font);
	m_pMemDC.SetTextColor(0x00CCFF);//��ǰ�ؿ���ɫ
	m_pMemDC.TextOut(290,10,str_pass);
	font.DeleteObject();
	m_pMemDC.SelectObject(oldfont);
	m_pMemDC.SetTextColor(oldcolor);
	
	if(m_Me[0].GetLife() >0)//��Ѫ������0ʱ�����ҷ��ɻ�
	{
		m_Me[0].Draw(&m_pMemDC,TRUE); //�����ҷ��ɻ�
	}
	if(Single)
	{
		if(m_Me[1].GetLife() >0)//��Ѫ������0ʱ�����ҷ��ɻ�
		{
			m_Me[1].Draw(&m_pMemDC,TRUE); //�����ҷ��ɻ�
		}
	}
	int size = m_ObjList[0].GetSize();
	pos=m_ObjList[0].GetHeadPosition();
	for(i =0 ;i<m_ObjList[0].GetSize();i++)//���Ƶл�
	{
		
		temp_enemy = (CEnemy*)m_ObjList[0].GetNext(pos);
		//temp->SetPos();
		temp_enemy->Draw(&m_pMemDC,TRUE);
	}
	pos=m_ObjList[6].GetHeadPosition();
	for(i =0 ;i<m_ObjList[6].GetSize();i++)//����BOSS
	{
		
		temp_boss = (CPlaneBoss*)m_ObjList[6].GetNext(pos);
		//temp->SetPos();
		temp_boss->Draw(&m_pMemDC,TRUE);
	}
	pos=m_ObjList[2].GetHeadPosition();
	if(pos != NULL)
	{
		for(i =0 ;i<m_ObjList[2].GetSize();i++)//����ը��
		{
			
			temp_ball = (CBall*)m_ObjList[2].GetNext(pos);
			//temp_ball->SetPos();
			temp_ball->Draw(&m_pMemDC,TRUE);
		}
	}
	if(m_Me[0].GetLife()>0 ||m_Me[1].GetLife()>0)
	{
		for(pos1=m_ObjList[3].GetHeadPosition();(pos2=pos1)!=NULL;)//���Ʊ�ը
		{
			
			temp_Ex = (CExplosion*)m_ObjList[3].GetNext(pos1);
			//temp_ball->SetPos();
			temp_Ex->Draw(&m_pMemDC,TRUE);
			if(temp_Ex->GetIndex()>7)
			{
			m_ObjList[3].RemoveAt(pos2);
			delete(temp_Ex);
			}
		}
	}
	
		
		for(pos1=m_ObjList[1].GetHeadPosition();(pos2=pos1)!=NULL;)//���Ƶ���
		{
			
			temp_Bomb = (CBomb*)m_ObjList[1].GetNext(pos1);
			temp_Bomb->Draw(&m_pMemDC,TRUE);
		}
		for(pos1=m_ObjList[4].GetHeadPosition();(pos2=pos1)!=NULL;)//���Ƶ���
		{
			
			temp_change = (CGameChange*)m_ObjList[4].GetNext(pos1);
			temp_change->Draw(&m_pMemDC,TRUE);
		}
		for(pos1=m_ObjList[5].GetHeadPosition();(pos2=pos1)!=NULL;)//����boss����
		{
			
		temp_BossBomb = (CBossBomb*)m_ObjList[5].GetNext(pos1);
		temp_BossBomb->Draw(&m_pMemDC,TRUE);
		}
	if(Status == 3)
	{
		font.CreateFont(50,0,0,0,FW_NORMAL,FALSE,FALSE,0,ANSI_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH | FF_SWISS,_T("Arial")); 
		CString str("Game Over");
		CString str1("Press Enter to Continue...");
		CString str2("�ս���:");
		//CString buffer1("stop file1");
		CBitmap bmp;
		CImageList imgList;
		POINT pt;
		pt.x =300;
		pt.y =350;
		//bitmap.LoadBitmap(
		//bitmap.CreateCompatibleBitmap(m_pMemDC);
		
		//mciSendString(buffer1,NULL,0,NULL);
		m_pMemDC.SetTextColor(0xFFFF00);
		CText text(230,250,str);
		//�������������壬�������
		CText text1(240,300,str1);
		CText text2(220,350,str2);
		oldfont = m_pMemDC.SelectObject(font);
		text.Draw(&m_pMemDC,TRUE);
		m_pMemDC.SelectObject(oldfont);
		font.DeleteObject();
		font.CreateFont(15,0,0,0,FW_NORMAL,FALSE,FALSE,0,ANSI_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH | FF_SWISS,_T("����")); 
		oldfont = m_pMemDC.SelectObject(font);
		oldcolor = m_pMemDC.SetTextColor(0xFFFF00);
		text1.Draw(&m_pMemDC,TRUE);
		m_pMemDC.SetTextColor(0x000000);
		text2.Draw(&m_pMemDC,TRUE);
		/*bmp.LoadBitmap(IDB_ENEMY);
		imgList.Create(35, 35, ILC_COLOR8|ILC_MASK, 1, 0);
		imgList.Add(&bmp, RGB(0,0,0));
		imgList.Draw(&m_pMemDC,1,pt,ILD_TRANSPARENT);*/

		//�����ս��ߣ����������Ϸ�����ĵз�
		if(shutdown ==0)
		{
			bmp.LoadBitmap(IDB_ENEMY);
			imgList.Create(35, 35, ILC_COLOR8|ILC_MASK, 1, 0);
			imgList.Add(&bmp, RGB(0,0,0));
			imgList.Draw(&m_pMemDC,1,pt,ILD_TRANSPARENT);
		}
		else if(shutdown ==1)
		{
			bmp.LoadBitmap(IDB_ANGEL);
			imgList.Create(70, 90, ILC_COLOR8|ILC_MASK, 1, 0);
			imgList.Add(&bmp, RGB(255,0,0));
			imgList.Draw(&m_pMemDC,0,pt,ILD_TRANSPARENT);
		}
		else if(shutdown ==2)
		{
			bmp.LoadBitmap(IDB_GAR);
			imgList.Create(70, 90, ILC_COLOR8|ILC_MASK, 1, 0);
			imgList.Add(&bmp, RGB(255,0,0));
			imgList.Draw(&m_pMemDC,0,pt,ILD_TRANSPARENT);
		}
		else if(shutdown ==3)
		{
			bmp.LoadBitmap(IDB_SKE);
			imgList.Create(70, 90, ILC_COLOR8|ILC_MASK, 1, 0);
			imgList.Add(&bmp, RGB(255,0,0));
			imgList.Draw(&m_pMemDC,0,pt,ILD_TRANSPARENT);
		}
		//imgList.DeleteImageList();
		//bmp.DeleteObject();
		font.DeleteObject();
		m_pMemDC.SelectObject(oldfont);
		m_pMemDC.SetTextColor(oldcolor);
	}
	if(Status == 2)//��ͣ
	{
		font.CreateFont(25,0,0,0,FW_NORMAL,FALSE,FALSE,0,ANSI_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH | FF_SWISS,_T("����")); 
		CString str("��ͣ");
		COLORREF old;
		old=m_pMemDC.SetTextColor(RGB(255,0,0));
		oldfont = m_pMemDC.SelectObject(font);
		m_pMemDC.TextOutW(300,200,str);
		m_pMemDC.SetTextColor(old);
		font.DeleteObject();
		m_pMemDC.SelectObject(oldfont);

	}
	//��������ʾ˫���ĵ÷�
	CString str,str1;
	font.CreateFont(20,0,0,0,FW_NORMAL,FALSE,FALSE,0,ANSI_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH | FF_SWISS,_T("����")); 
	oldfont = m_pMemDC.SelectObject(font);
	oldcolor = m_pMemDC.SetTextColor(0xFFFF00);
	str.Format(_T("1P �÷�:%d"),Score[0]);
	str1.Format(_T("2P �÷�:%d"),Score[1]);
	m_pMemDC.TextOut(0,10,str);
	
	if(Single)
	m_pMemDC.TextOut(150,10,str1);
	font.DeleteObject();
	m_pMemDC.SelectObject(oldfont);
	m_pMemDC.SetTextColor(oldcolor);
	if(flag_show_next == 1)//��ʾ��һ��
	{
		
			font.CreateFont(25,0,0,0,FW_NORMAL,FALSE,FALSE,0,ANSI_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH | FF_SWISS,_T("����")); 
			oldfont = m_pMemDC.SelectObject(font);
			oldcolor = m_pMemDC.SetTextColor(0x3366CC);
			CString str;
			str.Format(_T("��ϲ�������%d��"),pass);
			
			CText text(260,250,str);//CText����
			text.Draw(&m_pMemDC,TRUE);
			m_pMemDC.SelectObject(oldfont);
			m_pMemDC.SetTextColor(oldcolor);
			font.DeleteObject();
	}
	CImageList imgList;
	CBitmap bitmap;
	imgList.Create(20,15,ILC_COLOR24 | ILC_MASK,1,0);
	bitmap.LoadBitmapW(IDB_BITMAP1);
	imgList.Add(&bitmap,RGB(255,255,255));
	for(int i =0;i<m_Me[0].GetLife();i++)//����Ѫ��
	{
		imgList.Draw(&m_pMemDC,0,m_LifePt[i],ILD_TRANSPARENT);
	}
	if(Single)
	{
		for(int i =0;i<m_Me[1].GetLife();i++)//����Ѫ��
		{
			imgList.Draw(&m_pMemDC,0,m_LifePt1[i],ILD_TRANSPARENT);
		}
	}
	pDC->BitBlt(0,0,rect.Width(),rect.Height(),&m_pMemDC,0,0,SRCCOPY);
	bitmap.DeleteObject();
	imgList.DeleteImageList();
	if(flag_show_next ==1)
	{
		flag_show_next = 0;
		Sleep(1000);
		NextGame();
	}
	m_pMemDC.SelectObject(oldBit);
	m_pMemBitmap.DeleteObject();
	m_pMemDC.DeleteDC();
}


//�����һ��ƶ�
void CPlaneGame::SetMeMotion(int type,int motion,int index)
{
	if(type == 0)
	{
		m_Me[index].SetHorMotion(motion);
	}
	else if(type == 1)
	{
		m_Me[index].SetVerMotion(motion);
	}
}
void CPlaneGame::SetBossPosition()
{
	POSITION pos;
	CPlaneBoss *temp;
	pos=m_ObjList[6].GetHeadPosition();
	for(int i =0 ;i<m_ObjList[6].GetSize();i++)
	{
		
		temp = (CPlaneBoss*)m_ObjList[6].GetNext(pos);
		temp->AI(m_Me[0].GetPoint(),m_Me[1].GetPoint(),m_Me[0].GetLife(),m_Me[1].GetLife());
	}
}

//���������ö���λ�ã���OnTimer�������

//���õл�λ��
void CPlaneGame::SetEnemyPosition()
{
	POSITION pos;
	CEnemy *temp;
	pos=m_ObjList[0].GetHeadPosition();
	for(int i =0 ;i<m_ObjList[0].GetSize();i++)
	{
		
		temp = (CEnemy*)m_ObjList[0].GetNext(pos);
		temp->SetPos();
	}
}
//�����ӵ���λ��
void CPlaneGame::SetBallPosition()
{
	POSITION pos;
	CBall *temp;
	pos=m_ObjList[2].GetHeadPosition();
	if(NULL == pos)
	{
		return;
	}
	for(int i =0 ;i<m_ObjList[2].GetSize();i++)
	{
		temp = (CBall*)m_ObjList[2].GetNext(pos);
		temp->SetPos();
	}
}
//���õ���λ��
void CPlaneGame::SetBombPosition()
{
	POSITION pos;
	CBomb *temp;
	pos=m_ObjList[1].GetHeadPosition();
	if(NULL == pos)
	{
		return;
	}
	for(int i =0 ;i<m_ObjList[1].GetSize();i++)
	{
		temp = (CBomb*)m_ObjList[1].GetNext(pos);
		temp->SetPos();
	}
}
//���õ��ߵ�λ��
void CPlaneGame::SetChangePositoin()
{
	POSITION pos;
	CGameChange *temp;
	pos=m_ObjList[4].GetHeadPosition();
	if(NULL == pos)
	{
		return;
	}
	for(int i =0 ;i<m_ObjList[4].GetSize();i++)
	{
		temp = (CGameChange*)m_ObjList[4].GetNext(pos);
		temp->SetPos();
	}

}
//����BOSS������λ��
void CPlaneGame::SetBossBombPosition()
{
	
	POSITION pos;
	CBossBomb *temp;
	pos=m_ObjList[5].GetHeadPosition();
	if(NULL == pos)
	{
		return;
	}
	for(int i =0 ;i<m_ObjList[5].GetSize();i++)
	{
		temp = (CBossBomb*)m_ObjList[5].GetNext(pos);
		temp->SetPos();
	}
}

//����ѡ��
void CPlaneGame::Fire(int index)
{
	//POSITION pos;
	int count = CBomb::Get_Count();//�õ���ǰ���ε��ӵ��������������ڳ�ȡ����ʱ��ȡ
	for(int i=0;i<count;i++)
	{
 		if(i<count/2)
			m_ObjList[1].AddTail(new CBomb((m_Me[index].GetPoint()).x+15-i*30,(m_Me[index].GetPoint()).y,index));
		else
			m_ObjList[1].AddTail(new CBomb((m_Me[index].GetPoint()).x+15+i*30,(m_Me[index].GetPoint()).y,index));

	}
	PlaySound(_T("../sound/1.wav"), NULL, SND_FILENAME | SND_ASYNC); 
	//m_ObjList[1].AddTail(new CBomb((m_Me.GetPoint()).x+30,(m_Me.GetPoint()).y));
	//int size = m_ObjList[1].GetSize();
}

//��Ϸ��ײ����Լ�ը���Ŀ���ѡ��
void CPlaneGame::CheckFire() //���ը��״̬����ը�� ����ը�� ���ɱ���
{
	POSITION pos;
	POSITION pos1,pos2,pos3,pos4;
	CBall *ball;
	CEnemy *temp;
	CBall *temp_ball;
	CBomb *temp_bomb;
	CPlaneBoss *temp_boss;
	CPoint pt,pt_me,pt_me1;
	CGameChange *temp_change;
	CBossBomb *temp_BossBomb;
	CRect rect;
	pt_me = m_Me[0].GetPoint();
	pt_me1 = m_Me[1].GetPoint();
	pos=m_ObjList[0].GetHeadPosition();
	int size = m_ObjList[2].GetSize();
	if(abs(rand()%20) == 5)//��������
	{
		m_ObjList[4].AddTail(new CGameChange());
	}
	for(int i =0;i<m_ObjList[0].GetSize();i++)//�л�����ը��
	{
		
		temp = (CEnemy*)m_ObjList[0].GetNext(pos);
		pt = temp->GetPoint();
		if(abs(pt.x - pt_me.x)<=10 || abs(pt.x - pt_me1.x)<=10)
		{
			int flag = 0;
			for(pos1=m_ObjList[2].GetHeadPosition();(pos2=pos1)!=NULL;)
			{
				ball = (CBall*)m_ObjList[2].GetNext(pos1); 
				if((ball->GetPoint()).x == pt.x)
				{
					flag = 1;
					break;
				}
			}
			if(!flag)
				m_ObjList[2].AddTail(new CBall(pt.x,pt.y,temp->GetMontion()));
		}
		int size = m_ObjList[2].GetSize();
	}
	
	for(pos1=m_ObjList[2].GetHeadPosition();(pos2=pos1)!=NULL;)//����ը��
	{
		temp_ball = (CBall*)m_ObjList[2].GetNext(pos1); 
		if((temp_ball->GetPoint()).y > 800 ||(temp_ball->GetPoint()).y<-10)
		{
			m_ObjList[2].GetAt(pos2);
			m_ObjList[2].RemoveAt(pos2);
			delete(temp_ball);
		}
	}
	for(pos1=m_ObjList[1].GetHeadPosition();(pos2=pos1)!=NULL;)//���ٵ���
	{
		temp_bomb = (CBomb*)m_ObjList[1].GetNext(pos1); 
		if((temp_bomb->GetPoint()).y > 800 ||(temp_bomb->GetPoint()).y<-10)
		{
			m_ObjList[1].GetAt(pos2);
			m_ObjList[1].RemoveAt(pos2);
			delete(temp_bomb);
		}
	}

	for(pos1=m_ObjList[4].GetHeadPosition();(pos2=pos1)!=NULL;)//���ٵ���
	{
		temp_change= (CGameChange*)m_ObjList[4].GetNext(pos1); 
		if((temp_change->GetPoint()).y > 800 ||(temp_change->GetPoint()).y<-10)
		{
			m_ObjList[4].GetAt(pos2);
			m_ObjList[4].RemoveAt(pos2);
			delete(temp_change);
		}
	}
	for(pos1=m_ObjList[2].GetHeadPosition();(pos2=pos1)!=NULL;)//�ж��Ƿ�ը��ը������
	{
		temp_ball = (CBall*)m_ObjList[2].GetNext(pos1);
		if(rect.IntersectRect(temp_ball->GetRect(),m_Me[0].GetRect())!=0 &&m_Me[0].GetLife()>0)
		{
			if(Status == 1)//�������ʱ
			{
			m_ObjList[3].AddTail(new CExplosion((m_Me[0].GetPoint()).x-20,(m_Me[0].GetPoint()).y-30));
			m_ObjList[2].RemoveAt(pos2);
			
			m_Me[0].GetHurt();
			if(m_Me[0].GetLife()==0)
			{
				m_Me[0].Die(-1000,-1000);
				shutdown = temp_ball->getWho();
			}
			delete(temp_ball);
			/*if(m_Me[0].GetLife()==0 &&m_Me[1].GetLife()==0)
			GameOver();//��Ϸ����*/
			}
			break;
		}
		if(Single)
		{
		if(rect.IntersectRect(temp_ball->GetRect(),m_Me[1].GetRect())!=0&&m_Me[1].GetLife()>0)
		{
			if(Status == 1)//�������ʱ
			{
			m_ObjList[3].AddTail(new CExplosion((m_Me[1].GetPoint()).x-20,(m_Me[1].GetPoint()).y-30));
			m_ObjList[2].RemoveAt(pos2);
			
			m_Me[1].GetHurt();
			if(m_Me[1].GetLife()==0)
			{
				m_Me[1].Die(-1000,-1000);
				shutdown = temp_ball->getWho();
			}
			delete(temp_ball);
			/*if(m_Me[1].GetLife()==0 && m_Me[0].GetLife()==0)
			GameOver();//��Ϸ����*/
			}
			break;
		}
		}
		
	}
	//��Ϸ����*
	if(m_Me[1].GetLife()<=0 && m_Me[0].GetLife()<=0)
	GameOver();


	for(pos1=m_ObjList[5].GetHeadPosition();(pos2=pos1)!=NULL;)//�ж��Ƿ�bossը��ը������
	{
		temp_BossBomb = (CBossBomb*)m_ObjList[5].GetNext(pos1);
		if(rect.IntersectRect(temp_BossBomb->GetRect(),m_Me[0].GetRect())!=0&&m_Me[0].GetLife()>0)
		{
			if(Status == 1)//�������ʱ
			{
			m_ObjList[3].AddTail(new CExplosion((m_Me[0].GetPoint()).x-20,(m_Me[0].GetPoint()).y-30));
			m_ObjList[5].RemoveAt(pos2);
			
			m_Me[0].GetHurt();
			if(m_Me[0].GetLife()==0)
			{
				m_Me[0].Die(-1000,-1000);
				shutdown = temp_BossBomb->getWho();
			}
			delete(temp_BossBomb);
			}

			break;
		}
		if(Single)
		{
			if(rect.IntersectRect(temp_BossBomb->GetRect(),m_Me[1].GetRect())!=0&&m_Me[1].GetLife()>0)
			{
				if(Status == 1)//�������ʱ
				{
				m_ObjList[3].AddTail(new CExplosion((m_Me[1].GetPoint()).x-20,(m_Me[1].GetPoint()).y-30));
				m_ObjList[5].RemoveAt(pos2);
				
				m_Me[1].GetHurt();
				if(m_Me[1].GetLife()==0)
				{	
					m_Me[1].Die(-1000,-1000);
					shutdown = temp_BossBomb->getWho();
				}
				delete(temp_BossBomb);
				}
				break;
			}
		}
		
	}
	if(m_Me[1].GetLife()<=0 && m_Me[0].GetLife()<=0)
	GameOver();//��Ϸ����
	for(pos1=m_ObjList[4].GetHeadPosition();(pos2=pos1)!=NULL;)//�ж��Ƿ���������
	{
		temp_change = (CGameChange*)m_ObjList[4].GetNext(pos1);
		if(rect.IntersectRect(temp_change->GetRect(),m_Me[0].GetRect())!=0 &&m_Me[0].GetLife()>0)
		{
			//m_ObjList[3].AddTail(new CExplosion((m_Me[0].GetPoint()).x,(m_Me[0].GetPoint()).y));
			m_ObjList[4].RemoveAt(pos2);
			
			if((temp_change->GetIndex())==0)
			{
				m_Me[0].GetCure();//��Ѫ
			}
			else if((temp_change->GetIndex())==1)
			{
				CBomb::setType();//�ӵ�
			}
			else if((temp_change->GetIndex() ==2))
			{
				CBomb::Add_Count();//������Ŀ����						
			}
			else if((temp_change->GetIndex()==3))
			{
				m_Me[0].AddBig();//�Ӵ���
			}
			delete(temp_change);
			PlaySound(_T("../sound/3.wav"), NULL, SND_FILENAME | SND_ASYNC); 
			break;
		}
		if(Single)
		{
		if(rect.IntersectRect(temp_change->GetRect(),m_Me[1].GetRect())!=0&&m_Me[1].GetLife()>0)
		{
			//m_ObjList[3].AddTail(new CExplosion((m_Me[0].GetPoint()).x,(m_Me[0].GetPoint()).y));
			m_ObjList[4].RemoveAt(pos2);
			
			if((temp_change->GetIndex())==0)
			{
				m_Me[1].GetCure();//��Ѫ
			}
			else if((temp_change->GetIndex())==1)
			{
				CBomb::Add_V();//�ӵ�����
			}
			else if((temp_change->GetIndex() ==2))
			{
				CBomb::Add_Count();//������Ŀ����						
			}
			else if((temp_change->GetIndex()==3))
			{
				m_Me[1].AddBig();
			}
			delete(temp_change);
			//���ŽӴ����ߵ�����
			PlaySound(_T("../sound/3.wav"), NULL, SND_FILENAME | SND_ASYNC); 
			break;
		}
		}
	}
	
	for(pos1=m_ObjList[1].GetHeadPosition();(pos2=pos1)!=NULL;)//��⵼�� ������ը ���ٵл�
	{
		int size = m_ObjList[1].GetSize();
		int size1 = m_ObjList[0].GetSize();
		if(size <=0 || size1 <=0)break;
		temp_bomb = (CBomb *)m_ObjList[1].GetNext(pos1);
		for(pos3=m_ObjList[0].GetHeadPosition();(pos4=pos3)!=NULL;)
		{
			int size = m_ObjList[0].GetSize();
			if(size<=0)break;
			temp = (CEnemy*)m_ObjList[0].GetNext(pos3);
			if(rect.IntersectRect(temp->GetRect(),temp_bomb->GetRect())!=0)
			{
				m_ObjList[3].AddTail(new CExplosion((temp_bomb->GetPoint()).x-20,(temp_bomb->GetPoint()).y-30));
				m_ObjList[1].RemoveAt(pos2);
				delete(temp);
				
				m_ObjList[0].RemoveAt(pos4);
				//PlaySound(
				if(temp_bomb->GetIndex()==0)
				SetScore(0);//�Ʒ�
				else
				SetScore(1);
				PlaySound(_T("../sound/2.wav"), NULL, SND_FILENAME | SND_ASYNC);
				delete(temp_bomb);//�˴�ע��ɾ��λ��
				break;
			}
		}
	}
	for(pos1=m_ObjList[1].GetHeadPosition();(pos2=pos1)!=NULL;)//��⵼�� ը��BOSS ����BossѪ��
	{
		int size = m_ObjList[1].GetSize();
		int size1 = m_ObjList[6].GetSize();
		if(size <=0 || size1 <=0)break;
		temp_bomb = (CBomb *)m_ObjList[1].GetNext(pos1);
		for(pos3=m_ObjList[6].GetHeadPosition();(pos4=pos3)!=NULL;)
		{
			int size = m_ObjList[6].GetSize();
			if(size<=0)break;
			temp_boss = (CPlaneBoss*)m_ObjList[6].GetNext(pos3);
			if(rect.IntersectRect(temp_boss->GetRect(),temp_bomb->GetRect())!=0)
			{
				m_ObjList[3].AddTail(new CExplosion((temp_bomb->GetPoint()).x-20,(temp_bomb->GetPoint()).y-30));
				m_ObjList[1].RemoveAt(pos2);
				for(int i=0;i<CBomb::getHurt();i++)//��ͬը��Ч����һ��
				temp_boss->GetHurt();//Ѫ����һ
				delete(temp_bomb);//�˴�ע��ɾ��λ��
				if(temp_boss->Get_Life() <=0)
				{
					m_ObjList[6].RemoveAt(pos4);
					delete(temp_boss);
				}
				//PlaySound(
				//SetScore();//�Ʒ�
				PlaySound(_T("../sound/2.wav"), NULL, SND_FILENAME | SND_ASYNC); 
				break;
			}
		}
	}
	pt_me = m_Me[0].GetPoint();
	CPoint pt_me_ = m_Me[1].GetPoint();
	pos=m_ObjList[6].GetHeadPosition();
	for(int i =0;i<m_ObjList[6].GetSize();i++)//boss����ը��
	{
		
		temp_boss = (CPlaneBoss*)m_ObjList[6].GetNext(pos);
		pt = temp_boss->GetPoint();
		if(abs(pt.x - pt_me.x)<=10 &&(pt.y -pt_me.y)<0 ||abs(pt.x - pt_me_.x)<=10 &&(pt.y -pt_me_.y)<0)
		{	
			if(m_Me[0].GetLife()>0 || m_Me[1].GetLife()>0)
			{
				//��һ��BOSS��ʱ��
				if(temp_boss->GetIndex()==0)
				{
					
					m_ObjList[5].AddTail(new CBossBomb(pt.x+30,pt.y,0,1));
					m_ObjList[2].AddTail(new CBall(pt.x+30,pt.y,1));
					
				}
				//�ڶ���BOSS��ʱ��
				else if(temp_boss->GetIndex()==1)
				{
					m_ObjList[5].AddTail(new CBossBomb(pt.x+40,pt.y,-1,2,1));
					m_ObjList[5].AddTail(new CBossBomb(pt.x+60,pt.y,0,2,1));
					m_ObjList[5].AddTail(new CBossBomb(pt.x+80,pt.y,1,2,1));
	
					m_ObjList[2].AddTail(new CBall(pt.x+40,pt.y,1,2));
					m_ObjList[2].AddTail(new CBall(pt.x+60,pt.y,1,2));
					m_ObjList[2].AddTail(new CBall(pt.x+80,pt.y,1,2));
					
				}
				//������BOSS��ʱ��
				else if(temp_boss->GetIndex()==2)
				{
					m_ObjList[5].AddTail(new CBossBomb(pt.x+20,pt.y,-1,3));
					m_ObjList[5].AddTail(new CBossBomb(pt.x+40,pt.y,-1,3));
					m_ObjList[5].AddTail(new CBossBomb(pt.x+60,pt.y,0,3));
					m_ObjList[5].AddTail(new CBossBomb(pt.x+80,pt.y,1,3));
					m_ObjList[5].AddTail(new CBossBomb(pt.x+100,pt.y,1,3));
					m_ObjList[2].AddTail(new CBall(pt.x+20,pt.y,1));
					m_ObjList[2].AddTail(new CBall(pt.x+40,pt.y,1));
					m_ObjList[2].AddTail(new CBall(pt.x+60,pt.y,1));
					m_ObjList[2].AddTail(new CBall(pt.x+80,pt.y,1));
					m_ObjList[2].AddTail(new CBall(pt.x+100,pt.y,1));
				}
			}
		}
	}
	for(pos1=m_ObjList[5].GetHeadPosition();(pos2=pos1)!=NULL;)//����boss����
	{
		temp_BossBomb = (CBossBomb*)m_ObjList[5].GetNext(pos1); 
		if((temp_BossBomb->GetPoint()).y > 800 ||(temp_BossBomb->GetPoint()).y<-10)
		{
			m_ObjList[5].GetAt(pos2);
			m_ObjList[5].RemoveAt(pos2);
			delete(temp_BossBomb);
		}
	}
	
	if(m_ObjList[0].GetSize()==0 && m_ObjList[3].GetSize() ==0 &&m_ObjList[6].GetSize()==0)//����Ƿ������һ��
	{
			//Result = 2;//��ʾʤ��
			//Sleep(1000);
		flag_show_next = 1;//�˴��ñ�־Ϊ1 ��ʾ��Ҫ��ʾ��һ����Ϣ
		pass++;
		GotoNext();//������һ�صĳ�ʼ��
	}
	
}
//���ñ����������
void CPlaneGame::StaBigFire(int index)
{
	if(m_Me[index].GetBig()>0)
	{
		POSITION pos1,pos2;
		CEnemy *temp;
		for(pos1=m_ObjList[0].GetHeadPosition();(pos2=pos1)!=NULL;)//��⵼�� ������ը ���ٵл�
		{
			temp = (CEnemy*)m_ObjList[0].GetNext(pos1);
			if(temp->GetPoint().y>0 &&temp->GetPoint().y<800)
			{
				m_ObjList[3].AddTail(new CExplosion(temp->GetPoint().x-20,temp->GetPoint().y-30));
				delete(temp);
				m_ObjList[0].RemoveAt(pos2);
			}
		}
		m_Me[index].SubBig();
	}
}
//��Ϸ����
void CPlaneGame::GameOver()
{
	Status = 3;
	//CText text(0,0);
	//Result =2;
}
//�õ���ǰ��Ϸ�Ľ���״̬
int CPlaneGame::GetStatus()
{
	return Status;
}
//���÷���
void CPlaneGame::SetScore(int index)
{
	Score[index]+=100;
}

//��Ϸ������һ�ؿ��ĳ�ʼ����ɾ�������ͷ��ڴ棩
void CPlaneGame::GotoNext()
{
	
	CObject *temp;
	for(int i=0;i<7;i++)
	{
		POSITION pos;
		pos=m_ObjList[i].GetHeadPosition();
		while(pos!=NULL)
		{
			temp=m_ObjList[i].GetNext(pos);
			if(temp!=NULL)
			{
			   delete temp;
			   temp=NULL;   
			}
		}
		m_ObjList[i].RemoveAll();
	}
	

	//NextGame();
	//InitGame();
}
//�������´ӱ��ؿ�ʼ
void CPlaneGame::StartFromOver()
{
	m_Me[0].Resume_Life();
	m_Me[0].Die(100,500);
	if(Single)
	m_Me[1].Resume_Life();
	m_Me[1].Die(300,500);
	CBomb::Resume_Count();
	CBomb::ResumeBomb();
	GotoNext();
	flag_show_next = 0;
	NextGame();
}
//����WM_DESTROY��Ϣ�У�������View��OnDestroy�����У����ڻ����ڴ�
void CPlaneGame::Destroy()
{
	CObject *temp;
	for(int i=0;i<7;i++)
	{
		POSITION pos;
		pos=m_ObjList[i].GetHeadPosition();
		while(pos!=NULL)
		{
			temp=m_ObjList[i].GetNext(pos);
			if(temp!=NULL)
			{
			   delete temp;
			   temp=NULL;   
			}
		}
		m_ObjList[i].RemoveAll();
	}
}