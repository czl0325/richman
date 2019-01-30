#include "StdAfx.h"
#include "Computer.h"

CComputer::CComputer(void)
{
	m_nGambleCount=0;
}

CComputer::~CComputer(void)
{
}
void CComputer::GameRun(int& nState,HWND hWnd,vector<CRole*>&vpRole,BOOL& bGameEnd)
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
	if (bGameEnd==FALSE)
	{
		if (m_bGambleGo==FALSE&&m_bGambleDecide==FALSE)
		{
			m_bGambleGo=TRUE;
			SetTimer(hWnd,GAMBLERUN,20,NULL);
		}
	}
}
void CComputer::UpdateGamble(HWND hWnd,int& nState)
{
	if (m_nGambleCount<12)
	{
		m_nGambleCount++;
		m_nWalk=rand()%6+1;
		InvalidateRect(hWnd,NULL,FALSE);
	} 
	else
	{
		KillTimer(hWnd,GAMBLERUN);
		m_bGambleGo=FALSE;
		m_bGambleDecide=TRUE;
		m_nGambleCount=0;
		InvalidateRect(hWnd,NULL,FALSE);
		m_bGambleDecide=FALSE;
		nState=ROLEWALK;
		InvalidateRect(hWnd,NULL,FALSE);
		SetTimer(hWnd,ROLEWALK,500,NULL);
		m_nRoleWalk=0;
	}
}
void CComputer::LButtonDown(HWND hWnd,CPoint ptLClk,int& nState,vector<CRole*>&vpRole,CButtonClk m_ButtonClkSmallRole[],CTool& Tool,BOOL& bGameEnd,BOOL& bRoleLose)
{
	if (nState==ROLELOSE)
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
void CComputer::MouseMove(HWND hWnd,CPoint ptNewMouseMove,CPoint ptOldMouseMove,vector<CRole*>&vpRole,CButtonClk m_ButtonClkSmallRole[])
{

}
void CComputer::HouseRun(int nHouseNum,vector<CRole*>&vpRole)
{

}
