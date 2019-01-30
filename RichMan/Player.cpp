#include "StdAfx.h"
#include "Player.h"
#include "DlgHouseNoneMaster.h"
CPlayer::CPlayer(void)
{
}

CPlayer::~CPlayer(void)
{
}
void CPlayer::GameRun(int& nState,HWND hWnd,vector<CRole*>&vpRole,BOOL& bGameEnd)
{
	m_ButtonClkGambleGo.SetcrButton(m_ButtonClkGambleGo.GetcrOriginalButton());
	nState=GAMBLERUN;	
	InvalidateRect(hWnd,NULL,FALSE);
	if (vpRole.size()==1)
	{
		bGameEnd=TRUE;
		nState=ROLEWIN;
		InvalidateRect(hWnd,NULL,FALSE);
	}
}
void CPlayer::UpdateGamble(HWND hWnd,int& nState)
{
	m_nWalk=rand()%6+1;
	InvalidateRect(hWnd,NULL,FALSE);
}
void CPlayer::LButtonDown(HWND hWnd,CPoint ptLClk,int& nState,vector<CRole*>&vpRole,CButtonClk m_ButtonClkSmallRole[],CTool& Tool,BOOL& bGameEnd,BOOL& bRoleLose)
{
	if (nState==GAMBLERUN)
	{
		if (m_bGambleGo==FALSE&&m_bGambleDecide==FALSE)
		{
			if (m_ButtonClkGambleGo.GetcrButton().PtInRect(ptLClk))
			{
				m_bGambleGo=TRUE;
				SetTimer(hWnd,GAMBLERUN,20,NULL);
			}
			if (m_ButtonClkMenu.GetcrButton().PtInRect(ptLClk))
			{
				RoleClear(vpRole);
				Tool.CloseMIDIPlayer();
				nState=GAMEMENU;
				InvalidateRect(hWnd,NULL,FALSE);
				SetTimer(hWnd,GAMEMENU,2000,NULL);
				Tool.PlayMIDISong("Music\\Menu.mid");
			}
			if (m_ButtonClkExit.GetcrButton().PtInRect(ptLClk))
			{
				RoleClear(vpRole);
				Tool.CloseMIDIPlayer();
				PostQuitMessage(0);
			}
			for (int nRoleNum=0;nRoleNum<static_cast<int>(vpRole.size());nRoleNum++)
			{
				if (m_ButtonClkSmallRole[nRoleNum].GetcrButton().PtInRect(ptLClk))
				{
					m_nRoleLookNum=nRoleNum;
					nState=ROLELOOK;
					InvalidateRect(hWnd,NULL,FALSE);
				}
			}
		}
		else if(m_bGambleGo==TRUE&&m_bGambleDecide==FALSE)
		{
			KillTimer(hWnd,GAMBLERUN);
			m_bGambleGo=FALSE;
			m_bGambleDecide=TRUE;
			InvalidateRect(hWnd,NULL,FALSE);
		}
		else if (m_bGambleGo==FALSE&&m_bGambleDecide==TRUE)
		{
			m_bGambleDecide=FALSE;
			nState=ROLEWALK;
			InvalidateRect(hWnd,NULL,FALSE);
			SetTimer(hWnd,ROLEWALK,500,NULL);
			m_nRoleWalk=0;
		}
		else if (m_bGambleGo==TRUE&&m_bGambleDecide==TRUE)
		{
			return;
		}
	} 
	else if(nState==ROLELOOK)
	{
		nState=GAMBLERUN;
		InvalidateRect(hWnd,NULL,FALSE);
	}
	else if (nState==ROLELOSE)
	{
		bRoleLose=FALSE;
		for (int nHouseNum=0;nHouseNum<static_cast<int>(m_vpHouse.size());nHouseNum++)
		{
			m_vpHouse.at(nHouseNum)->m_nHouseMasterID=0;
		}
		vector<CRole*>::iterator itvpRole;
		int nRoleNum;
		for (itvpRole=vpRole.begin(),nRoleNum=0;itvpRole!=vpRole.end();itvpRole++,nRoleNum++)
		{
			if (nRoleNum==m_nRoleOrderCur)
			{
				vpRole.erase(itvpRole);
				m_nRoleOrderCur--;
				break;
			}
		}
		if (m_nRoleOrderCur<static_cast<int>(vpRole.size())-1)
		{
			m_nRoleOrderCur++;
		}
		else
		{
			m_nRoleOrderCur=0;
		}
		vpRole.at(m_nRoleOrderCur)->GameRun(nState,hWnd,vpRole,bGameEnd);
	}
	else if (nState==ROLEWIN)
	{
		bGameEnd=FALSE;
		RoleClear(vpRole);
		Tool.CloseMIDIPlayer();
		PostQuitMessage(0);
		//nState=GAMEMENU;
		//InvalidateRect(hWnd,NULL,FALSE);
		//SetTimer(hWnd,GAMEMENU,2000,NULL);
		//Tool.PlayMIDISong("Music\\Menu.mid");

	}
}

void CPlayer::MouseMove(HWND hWnd,CPoint ptNewMouseMove,CPoint ptOldMouseMove,vector<CRole*>&vpRole,CButtonClk m_ButtonClkSmallRole[])
{
	if (m_bGambleGo==FALSE&&m_bGambleDecide==FALSE)
	{
		m_ButtonClkGambleGo.MouseMove(hWnd,ptNewMouseMove,ptOldMouseMove);
	}
	for (int nRoleNum=0;nRoleNum<static_cast<int>(vpRole.size());nRoleNum++)
	{
		m_ButtonClkSmallRole[nRoleNum].MouseMove(hWnd,ptNewMouseMove,ptOldMouseMove);
	}
	m_ButtonClkMenu.MouseMove(hWnd,ptNewMouseMove,ptOldMouseMove);
	m_ButtonClkExit.MouseMove(hWnd,ptNewMouseMove,ptOldMouseMove);
}
void CPlayer::HouseRun(int nHouseNum,vector<CRole*>&vpRole)
{
	if (m_vpHouse.at(nHouseNum)->m_nHouseMasterID==0)
	{
		CDlgHouseNoneMaster DlgHouseNoneMaster(this,m_vpHouse.at(nHouseNum),vpRole);
		DlgHouseNoneMaster.DoModal();
		if (DlgHouseNoneMaster.m_nHouseRunState==IDBUY)
		{
			m_vpHouse.at(nHouseNum)->m_nHouseMasterID=m_nRoleID;	
			m_nHouseStarsNum[m_vpHouse.at(nHouseNum)->m_nHouseStars-1]+=1;
			m_nCash-=m_vpHouse.at(nHouseNum)->m_nHousePrice;
			m_nHouseProperty+=m_vpHouse.at(nHouseNum)->m_nHousePrice;
			Property();	
		}
	} 
	else if(m_vpHouse.at(nHouseNum)->m_nHouseMasterID==m_nRoleID)
	{
	}
	else
	{

	}
}
