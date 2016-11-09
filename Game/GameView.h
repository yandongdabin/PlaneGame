// GameView.h : CGameView 类的接口
//


#pragma once
#include "MyPlane.h"
#include "Enemy.h"
#include "PlaneGame.h"
class CGameView : public CView
{
protected: // 仅从序列化创建
	CGameView();
	DECLARE_DYNCREATE(CGameView)

private:
	//CMyPlane myPlane;
	//CEnemy enemy[10];
	CPlaneGame theGame;//游戏的全局对象
	CButton btn1,btn2,btn3;

// 属性
public:
	CGameDoc* GetDocument() const;
	int GetKey(int nVirtKey)
	{
		return (GetKeyState(nVirtKey) & 0x8000)? 1 : 0;
	}

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CGameView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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

#ifndef _DEBUG  // GameView.cpp 中的调试版本
inline CGameDoc* CGameView::GetDocument() const
   { return reinterpret_cast<CGameDoc*>(m_pDocument); }
#endif

