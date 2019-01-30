// RichManView.cpp : CRichManView 类的实现
//

#include "stdafx.h"
#include "RichMan.h"

#include "RichManDoc.h"
#include "RichManView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRichManView

IMPLEMENT_DYNCREATE(CRichManView, CView)

BEGIN_MESSAGE_MAP(CRichManView, CView)
	ON_WM_CREATE()
	ON_WM_TIMER()
//	ON_WM_SHOWWINDOW()
ON_WM_KEYDOWN()
ON_WM_RBUTTONDOWN()
ON_WM_LBUTTONDOWN()
ON_WM_MOUSEMOVE()
ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

// CRichManView 构造/析构

CRichManView::CRichManView()
{
	// TODO: 在此处添加构造代码
	pGame=NULL;
	m_hOffScreenBitmap=NULL;
}

CRichManView::~CRichManView()
{
	delete pGame;
	pGame=NULL;
	DeleteDC(m_hOffscreenDC);
	DeleteObject(m_hOffScreenBitmap);
	m_hOffScreenBitmap=NULL;
}

//BOOL CRichManView::PreCreateWindow(CREATESTRUCT& cs)
//{
//	// TODO: 在此处通过修改
//	//  CREATESTRUCT cs 来修改窗口类或样式
//	return CView::PreCreateWindow(cs);
//}

// CRichManView 绘制

void CRichManView::OnDraw(CDC* pDC)
{
	CRichManDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CRect crClient;
	GetClientRect(crClient);
	// TODO: 在此处为本机数据添加绘制代码	
	ASSERT(pGame);
	pGame->Draw();
	SelectObject(m_hOffscreenDC,m_hOffScreenBitmap);
	pDC->StretchBlt(0,0,crClient.Width(),crClient.Height(),CDC::FromHandle(pGame->GethOffscreenDC()),0,0,1024,768,SRCCOPY);
}


// CRichManView 诊断

#ifdef _DEBUG
void CRichManView::AssertValid() const
{
	CView::AssertValid();
}

void CRichManView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRichManDoc* CRichManView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRichManDoc)));
	return (CRichManDoc*)m_pDocument;
}
#endif //_DEBUG


// CRichManView 消息处理程序

int CRichManView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	SetTimer(GAMEMENU,2000,NULL);
	return 0;
}

void CRichManView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	pGame->Timer(nIDEvent);
	CView::OnTimer(nIDEvent);
}

//void CRichManView::OnShowWindow(BOOL bShow, UINT nStatus)
//{
//	CView::OnShowWindow(bShow, nStatus);
//	// TODO: 在此处添加消息处理程序代码
//}

void CRichManView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	CClientDC DC(this);
	m_hOffscreenDC=CreateCompatibleDC(DC.m_hDC);
	m_hOffScreenBitmap=CreateCompatibleBitmap(DC.m_hDC,1024,768);
	SelectObject(m_hOffscreenDC,m_hOffScreenBitmap);
	pGame=new CGame(m_hOffscreenDC,this->m_hWnd);
}

void CRichManView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (nChar==VK_ESCAPE)
	{
		PostQuitMessage(0);
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CRichManView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CView::OnRButtonDown(nFlags, point);
	CClientDC DC(this);
	CString str;
	str.Format("%d,%d",point.x,point.y);
	AfxMessageBox(str);
}

void CRichManView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CRect crClient;
	GetClientRect(crClient);
	CPoint ptPoint;
	ptPoint.x=int(point.x*1024.0/crClient.Width());
	ptPoint.y=int(point.y*768.0/crClient.Height());
	pGame->LButtonDown(ptPoint);
	CView::OnLButtonDown(nFlags, point);
}

void CRichManView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CRect crClient;
	GetClientRect(crClient);
	CPoint ptPoint;
	ptPoint.x=int(point.x*1024.0/crClient.Width());
	ptPoint.y=int(point.y*768.0/crClient.Height());
	pGame->MouseMove(ptPoint);
	CView::OnMouseMove(nFlags, point);
}

BOOL CRichManView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	return TRUE;
}
