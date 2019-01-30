#include "StdAfx.h"
#include "ButtonClk.h"

CButtonClk::CButtonClk(void)
{
	CRect cr(0,0,0,0);
	m_crButton=cr;
	m_crOriginalButton=cr;
	m_crLastButton=cr;
}

CButtonClk::~CButtonClk(void)
{
}
void CButtonClk::SetcrButton(CRect crButton)
{
	m_crButton=crButton;
}
void CButtonClk::SetcrOriginalButton()
{
	m_crOriginalButton=m_crButton;
}
void CButtonClk::SetcrLastButton()
{
	CRect crTem;
	crTem=m_crOriginalButton;
	InflateRect(&crTem,crTem.Width()/12,crTem.Height()/12);
	m_crLastButton=crTem;
}
void CButtonClk::MouseMove(HWND hWnd,CPoint ptNewMouseMove,CPoint ptOldMouseMove)
{
	if (!m_crButton.PtInRect(ptOldMouseMove))
	{
		if (m_crButton.PtInRect(ptNewMouseMove))
		{
			m_crButton=m_crLastButton;
			InvalidateRect(hWnd,NULL,TRUE);
		}
	} 
	else 
	{
		if (!m_crButton.PtInRect(ptNewMouseMove))
		{
			m_crButton=m_crOriginalButton;
			InvalidateRect(hWnd,NULL,TRUE);
		}	
	}
}
