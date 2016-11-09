// GameView.h : CGameView ��Ľӿ�
//


#pragma once
#include "MyPlane.h"
#include "Enemy.h"
#include "PlaneGame.h"
class CGameView : public CView
{
protected: // �������л�����
	CGameView();
	DECLARE_DYNCREATE(CGameView)

private:
	//CMyPlane myPlane;
	//CEnemy enemy[10];
	CPlaneGame theGame;//��Ϸ��ȫ�ֶ���
	CButton btn1,btn2,btn3;

// ����
public:
	CGameDoc* GetDocument() const;
	int GetKey(int nVirtKey)
	{
		return (GetKeyState(nVirtKey) & 0x8000)? 1 : 0;
	}

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CGameView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnBtn1Down();
	afx_msg void OnBtn2Down();
	afx_msg void OnBtn3Down();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnDestroy();
};

#ifndef _DEBUG  // GameView.cpp �еĵ��԰汾
inline CGameDoc* CGameView::GetDocument() const
   { return reinterpret_cast<CGameDoc*>(m_pDocument); }
#endif

