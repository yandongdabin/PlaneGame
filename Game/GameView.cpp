// GameView.cpp : CGameView ���ʵ��
//

#include "stdafx.h"
#include "Game.h"

#include "GameDoc.h"
#include "GameView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGameView

IMPLEMENT_DYNCREATE(CGameView, CView)

BEGIN_MESSAGE_MAP(CGameView, CView)
	ON_WM_KEYDOWN()
	ON_WM_KEYUP()
	ON_WM_TIMER()
	ON_WM_CREATE()
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDC_SINGLE,OnBtn1Down)
	ON_BN_CLICKED(IDC_MULTIPLE,OnBtn2Down)
	ON_BN_CLICKED(IDC_HELP,OnBtn3Down)
	ON_WM_MOUSEMOVE()
	ON_WM_DESTROY()
END_MESSAGE_MAP()

// CGameView ����/����

CGameView::CGameView()
{
	
	
	
	
}

CGameView::~CGameView()
{
}

BOOL CGameView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CGameView ����

void CGameView::OnDraw(CDC* pDC)
{
	CGameDoc* pDoc = GetDocument();
	
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	theGame.UpdateFrame(m_hWnd,pDC);//ˢ����Ϸ֡
	
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CGameView ���

#ifdef _DEBUG
void CGameView::AssertValid() const
{
	CView::AssertValid();
}

void CGameView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGameDoc* CGameView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGameDoc)));
	return (CGameDoc*)m_pDocument;
}
#endif //_DEBUG


// CGameView ��Ϣ�������

void CGameView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
	int sta=theGame.GetStatus();
	if(sta==1)
	{
			if(theGame.getSingle())
			{
				if(nChar == VK_RIGHT)
				{
					theGame.SetMeMotion(0,1,1);
				}
				else if(nChar == VK_LEFT)
				{
					theGame.SetMeMotion(0,-1,1);
				}
				else if(nChar == VK_UP)
				{
					theGame.SetMeMotion(1,-1,1);
				}
				else if(nChar == VK_DOWN)
				{
					theGame.SetMeMotion(1,1,1);
				}
			}
		
		
			if(nChar == 68)
			{
				theGame.SetMeMotion(0,1);
			}
			else if(nChar == 65)
			{
				theGame.SetMeMotion(0,-1);
			}
			else if(nChar == 87)
			{
				theGame.SetMeMotion(1,-1);
			}
			else if(nChar == 83)
			{
				theGame.SetMeMotion(1,1);
			}
		
		if(nChar ==VK_SPACE)
		{
			theGame.StopGame();
		}

		
	}
	if(sta == 2)
	{
		if(nChar == VK_SPACE)
		{
			theGame.ResumeGame();
		}
	}
	if(sta == 3)
	{
		if(nChar == VK_RETURN)
		{
			
			theGame.Set_Status(1);
			theGame.StartFromOver();
			//theGame.GotoNext();
		}
	}

	InvalidateRect(NULL);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CGameView::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
	int sta=theGame.GetStatus();
	if(sta == 1)
		{
		if(theGame.getSingle())
		{
			if(nChar ==VK_LEFT || nChar == VK_RIGHT)
			{
				theGame.SetMeMotion(0,0,1);
				
			}
			else if(nChar ==VK_UP || nChar ==VK_DOWN)
			{
				theGame.SetMeMotion(1,0,1);
			}
			if(nChar == VK_NUMPAD1)
				theGame.StaBigFire(1);
		}
		
		
			if(nChar == 68 || nChar ==65)
			{
				theGame.SetMeMotion(0,0);
			}
			else if(nChar == 87 || nChar ==83)
			{
				theGame.SetMeMotion(1,0);
			}
			else if(nChar == 75)
				theGame.StaBigFire(0);
		

	}
	if(sta == 3)
	{
		theGame.SetMeMotion(0,0);
		theGame.SetMeMotion(1,0);
		theGame.SetMeMotion(0,0,1);
		theGame.SetMeMotion(1,0,1);
	}
	
	CView::OnKeyUp(nChar, nRepCnt, nFlags);


}
//#include "Winuser.h"
void CGameView::OnTimer(UINT_PTR nIDEvent)
{   
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
	int sta=theGame.GetStatus();
	if(sta == 1)//��Ϸ���� ��ֹ����
	{
		
		if(GetKey(74)==1)//J
		{
			theGame.Fire(0);
		}
	
		if(theGame.getSingle())
		{
			if(GetKey(VK_NUMPAD0)==1) //0
			{
				theGame.Fire(1);
			}
		
		}
		
	}
	
		if(sta == 3 || sta == 1)//��Ϸ��������Ϸ����ʱ���д����ػ�
		{
			theGame.SetEnemyPosition();//
			theGame.SetBallPosition();
			theGame.SetBombPosition();
			theGame.SetChangePositoin();
			theGame.CheckFire();
			theGame.SetBossPosition();
			theGame.SetBossBombPosition();
			
			InvalidateRect(NULL);
		}
	
	
		
	
	CView::OnTimer(nIDEvent);
}

int CGameView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	
	//CFont font;
	//font.CreateFont(20,0,0,0,FW_NORMAL,FALSE,FALSE,0,ANSI_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH | FF_SWISS,_T("����")); 
	//btn1.SetFont(&font);
	btn1.Create(_T("������Ϸ"),WS_CHILD | WS_VISIBLE |BS_PUSHBUTTON,CRect(280,300,380,330),this,IDC_SINGLE);
	//::SetTextColor(btn1.GetSafeHwnd()
	/*if (btn1.GetBitmap() == NULL)
		btn1.SetBitmap(::LoadBitmap(NULL, MAKEINTRESOURCE(IDB_SINGLE)));*/
	

	
	//btn1.SetIcon(AfxGetApp()->LoadIcon(ICON_SAVE));  
	btn1.ShowWindow(SW_SHOWNORMAL);
	//btn2.SetFont(&font);
	btn2.Create(_T("˫����Ϸ"),WS_CHILD | WS_VISIBLE |BS_PUSHBUTTON,CRect(280,335,380,365),this,IDC_MULTIPLE);
	if (btn2.GetBitmap() == NULL)
	btn2.SetBitmap(::LoadBitmap(NULL, MAKEINTRESOURCE(IDB_MULTIPLE)));

	btn3.Create(_T("�鿴����"),WS_CHILD | WS_VISIBLE |BS_PUSHBUTTON,CRect(280,380,380,410),this,IDC_HELP);
	//if (btn3.GetCursor() == NULL)
	//btn3.SetCursor(::LoadCursor(NULL,LPCWSTR(IDC_HELP)));


	//if (btn3.GetBitmap() == NULL)
	//btn3.SetBitmap(::LoadBitmap(NULL, MAKEINTRESOURCE(IDB_MULTIPLE)));
	//btn2.SetIcon(::LoadIcon(NULL, IDI_ERROR));


	btn3.ShowWindow(SW_SHOWNORMAL);
	SetTimer(2,30,NULL);
	return 0;
}

BOOL CGameView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	return /*CView::OnEraseBkgnd(pDC)*/TRUE;
}
void CGameView::OnBtn1Down()
{
	theGame.SetSingle(FALSE);
	btn1.DestroyWindow();
	btn2.DestroyWindow();
	btn3.DestroyWindow();
	::ShowCursor(FALSE);
	if(!theGame.InitGame())
	{
		CString str("��ʼ����Ϸʧ��");
		MessageBox(str);
		exit(0);
	}

}
void CGameView::OnBtn2Down()
{
	theGame.SetSingle(TRUE);
	btn1.DestroyWindow();
	btn2.DestroyWindow();
	btn3.DestroyWindow();
	::ShowCursor(FALSE);
	//SetCursor(NULL);
	if(!theGame.InitGame())
	{
		CString str("��ʼ����Ϸʧ��");
		MessageBox(str);
		exit(0);
	}
}
void CGameView::OnBtn3Down()
{
	MessageBox(_T("1P:�ƶ�wsad ��ͨ����j ���� k  2P:�ƶ� �������� ��ͨ����:0 ����:1"),_T("����"),MB_OK);
	
}
void CGameView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	//SetCursor(NULL);
	CView::OnMouseMove(nFlags, point);
}

void CGameView::OnDestroy()
{
	
	CView::OnDestroy();
	theGame.Destroy();
	KillTimer(2);//ɾ����ʱ��
	// TODO: �ڴ˴������Ϣ����������
}
