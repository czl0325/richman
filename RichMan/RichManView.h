// RichManView.h : CRichManView 类的接口
//


#pragma once
#include "Game.h"
class CRichManView : public CView
{
protected: // 仅从序列化创建
	CRichManView();
	DECLARE_DYNCREATE(CRichManView)

// 属性
public:
	CRichManDoc* GetDocument() const;
	CGame* pGame;
	HDC m_hOffscreenDC;
	HBITMAP m_hOffScreenBitmap;
// 操作
public:
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
//	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CRichManView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
//	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	virtual void OnInitialUpdate();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

#ifndef _DEBUG  // RichManView.cpp 中的调试版本
inline CRichManDoc* CRichManView::GetDocument() const
   { return reinterpret_cast<CRichManDoc*>(m_pDocument); }
#endif

