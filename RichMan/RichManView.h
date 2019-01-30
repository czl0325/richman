// RichManView.h : CRichManView ��Ľӿ�
//


#pragma once
#include "Game.h"
class CRichManView : public CView
{
protected: // �������л�����
	CRichManView();
	DECLARE_DYNCREATE(CRichManView)

// ����
public:
	CRichManDoc* GetDocument() const;
	CGame* pGame;
	HDC m_hOffscreenDC;
	HBITMAP m_hOffScreenBitmap;
// ����
public:
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
//	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CRichManView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
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

#ifndef _DEBUG  // RichManView.cpp �еĵ��԰汾
inline CRichManDoc* CRichManView::GetDocument() const
   { return reinterpret_cast<CRichManDoc*>(m_pDocument); }
#endif

