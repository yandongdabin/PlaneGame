// MainFrm.cpp : CMainFrame ���ʵ��
//

#include "stdafx.h"
#include "Game.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
END_MESSAGE_MAP()


// CMainFrame ����/����

CMainFrame::CMainFrame()
{
	// TODO: �ڴ���ӳ�Ա��ʼ������
	
}

CMainFrame::~CMainFrame()
{
}


BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ
	cs.style &= ~WS_MAXIMIZEBOX;
	//cs.style &=CS_HREDRAW;
	//cs.style &=CS_VREDRAW;
	//cs.style |=WS_MAXIMIZEBOX;
	cs.style &=~WS_THICKFRAME;
	//cs.style &=~WS_CAPTION;
	cs.cx = 650;
	cs.cy = 800;
	cs.x = 200;
	cs.y = 10;
	//cs.style |=WS_MINIMIZEBOX;
	//cs.style &= ~WS_MINIMIZEBOX;


	return TRUE;
}


// CMainFrame ���

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG


// CMainFrame ��Ϣ�������



