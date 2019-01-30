#include "StdAfx.h"
#include "Role.h"


int CRole::m_nRoleOrderCur=0;
BOOL CRole::m_bGambleGo=FALSE;
BOOL CRole::m_bRoleWaleEnd=FALSE;
BOOL CRole::m_bGambleDecide=FALSE;
vector<CHouse*>CRole::m_vpHouse;
CRole::CRole(void)
{
	GetRoleStart();
	CRect crButtonGambleGo(BUTTONGAMBLEGOX,BUTTONGAMBLEGOY,BUTTONGAMBLEGOX+150,BUTTONGAMBLEGOY+150);
	m_ButtonClkGambleGo.SetcrButton(crButtonGambleGo);
	m_ButtonClkGambleGo.SetcrOriginalButton();
	m_ButtonClkGambleGo.SetcrLastButton();
	m_nWalk=0;
	m_nRoleWalk=0;
	m_nRoleLookNum=-1;
	CRect crButtonExit(BUTTONEXITX,BUTTONEXITY,BUTTONEXITX+75,BUTTONEXITY+150);
	m_ButtonClkExit.SetcrButton(crButtonExit);
	m_ButtonClkExit.SetcrOriginalButton();
	m_ButtonClkExit.SetcrLastButton();
	CRect crButtonMenu(BUTTONMENUX,BUTTONMENUY,BUTTONMENUX+75,BUTTONMENUY+150);
	m_ButtonClkMenu.SetcrButton(crButtonMenu);
	m_ButtonClkMenu.SetcrOriginalButton();
	m_ButtonClkMenu.SetcrLastButton();

}

CRole::~CRole(void)
{
}
BOOL CRole::Lose()
{
	if (m_nCash<0||m_nProperty<=0)
	{
		return TRUE;
	} 
	else
	{
		return FALSE;
	}
}
BOOL CRole::Win(int nPropertyWin)
{
	if (m_nProperty>=nPropertyWin)
	{
		return TRUE;
	} 
	else
	{
		return FALSE;
	}
}
void CRole::Property()
{
	m_nProperty=m_nCash+m_nDeposit-m_nLend+m_nHouseProperty+m_nStockProperty;
}
BOOL CRole::GetRoleStart()
{
	ifstream inRoleStart("RoleStart.txt");
	if (!inRoleStart)
	{
		AfxMessageBox("读取玩家信息RoleStart.txt失败！");
		return FALSE;
	}
	getline(inRoleStart,string());
	getline(inRoleStart,string());
	getline(inRoleStart,string());
	getline(inRoleStart,string());
	int nStockNum,nStockPriceBuy;
	inRoleStart>>m_nRoleID>>m_nRoleType>>m_strRoleName>>m_ptPlace.x>>m_ptPlace.y>>m_strPlace
		>>m_nPath>>m_nCash>>m_nDeposit>>m_nLend>>m_nHouseStarsNum[0]>>m_nHouseStarsNum[1]
	>>m_nHouseStarsNum[2]>>m_nHouseStarsNum[3]>>m_nHouseStarsNum[4]>>m_nHouseProperty
		>>m_nStockProperty>>m_nProperty;
	while (!inRoleStart.eof())
	{
		inRoleStart>>nStockNum>>nStockPriceBuy;
		m_vnStockNum.push_back(nStockNum);
		m_vnStockPriceBuy.push_back(nStockPriceBuy);
	}
	inRoleStart.close();
	return TRUE;
}
void CRole::UpdateRoleWalk(HWND hWnd,int& nState,vector<CRole*>&vpRole,CGameMap* pGameMap,int nWinProperty,BOOL& bGameEnd,BOOL& bRoleLose)
{
	if (m_nRoleWalk<m_nWalk&&m_bRoleWaleEnd==FALSE)
	{
		m_nRoleWalk++;
		PathJudge(pGameMap);
		InvalidateRect(hWnd,NULL,FALSE);
		if (m_nRoleWalk==m_nWalk)
		{
			m_bRoleWaleEnd=TRUE;
			m_nRoleWalk=0;
			KillTimer(hWnd,ROLEWALK);
			AffairJudge(vpRole,pGameMap);
			m_bRoleWaleEnd=FALSE;
			AfterWalk(vpRole,nState,hWnd,nWinProperty,bGameEnd,bRoleLose);
		}
	}
}
void CRole::PathJudge(CGameMap* pGameMap)
{
	switch (m_nPath)
	{
	case 1:
		m_ptPlace.x+=1;
		if (m_ptPlace.x>COLUMN-1)
		{
			m_ptPlace.y+=1;
			m_ptPlace.x=COLUMN-1;
			m_nPath=2;
		}
		break;
	case 2:
		m_ptPlace.y+=1;
		if (m_ptPlace.y>LINE-1)
		{
			m_ptPlace.x-=1;
			m_ptPlace.y=LINE-1;
			m_nPath=3;
		}
		break;
	case 3:
		m_ptPlace.x-=1;
		if (m_ptPlace.x<0)
		{
			m_ptPlace.y-=1;
			m_ptPlace.x=0;
			m_nPath=4;
		}
		break;
	case 4:
		m_ptPlace.y-=1;
		if (m_ptPlace.y<0)
		{
			m_ptPlace.x+=1;
			m_ptPlace.y=0;
			m_nPath=1;
		}
		break;
	default:
		break;
	}
	m_strPlace=pGameMap->m_strMapArray[m_ptPlace.y][m_ptPlace.x];
}

void CRole::AfterWalk(vector<CRole*>&vpRole,int& nState,HWND hWnd,int nWinProperty,BOOL& bGameEnd,BOOL& bRoleLose)
{
	if (Lose())
	{		
		bRoleLose=TRUE;
		nState=ROLELOSE;
		InvalidateRect(hWnd,NULL,FALSE);
	}
	if (Win(nWinProperty))
	{
		bGameEnd=TRUE;
		nState=ROLEWIN;
		InvalidateRect(hWnd,NULL,FALSE);
	}
	if (bGameEnd==FALSE&&bRoleLose==FALSE)
	{
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
}
void CRole::AffairJudge(vector<CRole*>&vpRole,CGameMap* pGameMap)
{
	int nAffairValue=pGameMap->m_nMapArray[m_ptPlace.y][m_ptPlace.x];
	if (nAffairValue<0)
	{
		HouseRun((-nAffairValue)-1,vpRole);
	}
}
void CRole::RoleClear(vector<CRole*>vpRole)
{
	//vector<CRole*>::iterator itvpRole;
	//for (itvpRole=vpRole.begin();itvpRole!=vpRole.end();itvpRole++)
	//{
	//	delete(*itvpRole);
	//	*itvpRole=NULL;
	//	itvpRole=vpRole.erase(itvpRole);
	//}
	vector<CHouse*>::iterator itvpHouse;
	for (itvpHouse=CRole::m_vpHouse.begin();itvpHouse!=CRole::m_vpHouse.end();itvpHouse++)
	{
		delete(*itvpHouse);
		*itvpHouse=NULL;
		itvpHouse=CRole::m_vpHouse.erase(itvpHouse);
	}
}
