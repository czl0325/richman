// RichManView.cpp : CRichManView ���ʵ��
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

// CRichManView ����/����

CRichManView::CRichManView()
{
	// TODO: �ڴ˴���ӹ������
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
//	// TODO: �ڴ˴�ͨ���޸�
//	//  CREATESTRUCT cs ���޸Ĵ��������ʽ
//	return CView::PreCreateWindow(cs);
//}

// CRichManView ����

void CRichManView::OnDraw(CDC* pDC)
{
	CRichManDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CRect crClient;
	GetClientRect(crClient);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���	
	ASSERT(pGame);
	pGame->Draw();
	SelectObject(m_hOffscreenDC,m_hOffScreenBitmap);
	pDC->StretchBlt(0,0,crClient.Width(),crClient.Height(),CDC::FromHandle(pGame->GethOffscreenDC()),0,0,1024,768,SRCCOPY);
}


// CRichManView ���

#ifdef _DEBUG
void CRichManView::AssertValid() const
{
	CView::AssertValid();
}

void CRichManView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRichManDoc* CRichManView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRichManDoc)));
	return (CRichManDoc*)m_pDocument;
}
#endif //_DEBUG


// CRichManView ��Ϣ�������

int CRichManView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	SetTimer(GAMEMENU,2000,NULL);
	return 0;
}

void CRichManView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	pGame->Timer(nIDEvent);
	CView::OnTimer(nIDEvent);
}

//void CRichManView::OnShowWindow(BOOL bShow, UINT nStatus)
//{
//	CView::OnShowWindow(bShow, nStatus);
//	// TODO: �ڴ˴������Ϣ����������
//}

void CRichManView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: �ڴ����ר�ô����/����û���
	CClientDC DC(this);
	m_hOffscreenDC=CreateCompatibleDC(DC.m_hDC);
	m_hOffScreenBitmap=CreateCompatibleBitmap(DC.m_hDC,1024,768);
	SelectObject(m_hOffscreenDC,m_hOffScreenBitmap);
	pGame=new CGame(m_hOffscreenDC,this->m_hWnd);
}

void CRichManView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (nChar==VK_ESCAPE)
	{
		PostQuitMessage(0);
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CRichManView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CView::OnRButtonDown(nFlags, point);
	CClientDC DC(this);
	CString str;
	str.Format("%d,%d",point.x,point.y);
	AfxMessageBox(str);
}

void CRichManView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	return TRUE;
}
