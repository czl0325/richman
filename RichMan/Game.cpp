#include "StdAfx.h"
#include "Game.h"

CGame::CGame(HDC hDC,HWND hWnd):
m_hOffscreenDC(hDC),m_hWnd(hWnd)
{
	m_Tool.PlayMIDISong("Music\\Menu.mid");
	srand(GetTickCount());
	m_hMemDC=CreateCompatibleDC(m_hOffscreenDC);
	m_hOldBitmap=NULL;
	m_nState=GAMEMENU;
	m_nIndexBkGameMenu=0;
	m_Tool.FileToBitmap(m_hBitmapBkGameMenu[0],"bmp\\GameMenu\\GameMenu0.bmp",1024,768);
	m_Tool.FileToBitmap(m_hBitmapBkGameMenu[1],"bmp\\GameMenu\\GameMenu1.bmp",1024,768);
	m_Tool.FileToBitmap(m_hBitmapBkGameMenu[2],"bmp\\GameMenu\\GameMenu2.bmp",1024,768);
	m_Tool.FileToBitmap(m_hBitmapStart,"bmp\\GameMenu\\GameStartButton.bmp",75,150);
	CRect crButtonStart(250,550,250+75,550+150);
	m_ButtonClkStart.SetcrButton(crButtonStart);
	m_ButtonClkStart.SetcrOriginalButton();
	m_ButtonClkStart.SetcrLastButton();
	m_Tool.FileToBitmap(m_hBitmapLoad,"bmp\\GameMenu\\GameLoadButton.bmp",75,150);
	CRect crButtonLoad(500,550,500+75,550+150);
	m_ButtonClkLoad.SetcrButton(crButtonLoad);
	m_ButtonClkLoad.SetcrOriginalButton();
	m_ButtonClkLoad.SetcrLastButton();
	m_Tool.FileToBitmap(m_hBitmapExit,"bmp\\GameMenu\\GameExitButton.bmp",75,150);
	CRect crButtonExit(750,550,750+75,550+150);
	m_ButtonClkExit.SetcrButton(crButtonExit);
	m_ButtonClkExit.SetcrOriginalButton();
	m_ButtonClkExit.SetcrLastButton();
	m_ptOldMouseMove.x=0;
	m_ptOldMouseMove.y=0;
	m_nWinProperty=30000;
	m_Tool.FileToBitmap(m_hBitmapBkChoose,"bmp\\GameChoose\\BkChoose.bmp",1024,768);
	string str;
	str="金贝贝";
	m_vstrRoleName.push_back(str);
	str="阿隆巴斯";
	m_vstrRoleName.push_back(str);
	str="孙小美";
	m_vstrRoleName.push_back(str);
	str="阿土伯";
	m_vstrRoleName.push_back(str);
	m_Tool.FileToBitmap(m_hBitmapRole,"bmp\\GameChoose\\Role.bmp",800,280);
	CRect crRole0(30,100,30+200,100+280);
	CRect crRole1(260,100,260+200,100+280);
	CRect crRole2(490,100,490+200,100+280);
	CRect crRole3(720,100,720+200,100+280);
	m_ButtonClkRole[0].SetcrButton(crRole0);
	m_ButtonClkRole[1].SetcrButton(crRole1);
	m_ButtonClkRole[2].SetcrButton(crRole2);
	m_ButtonClkRole[3].SetcrButton(crRole3);
	for (int i=0;i<4;i++)
	{
		m_ButtonClkRole[i].SetcrOriginalButton();
		m_ButtonClkRole[i].SetcrLastButton();
	}
	m_bRoleChoose[0]=FALSE;
	m_bRoleChoose[1]=FALSE;
	m_bRoleChoose[2]=FALSE;
	m_bRoleChoose[3]=FALSE;
	m_bPlayerChooseEnd=FALSE;
	m_Tool.FileToBitmap(m_hBitmapBkGameLoading,"bmp\\GameLoading\\BkGameLoading.bmp",1024,768);
	m_Tool.FileToBitmap(m_hBitmapLoading,"bmp\\GameLoading\\Loading.bmp",1024,180);
	CRect crLoading(0,450,0,630);
	m_crLoading=crLoading;
	m_Tool.FileToBitmap(m_hBitmapBkGameRun,"bmp\\GameRun\\BkGameRun.bmp",1024,768);
	m_Tool.FileToBitmap(m_hBitmapGameState,"bmp\\GameRun\\GameState.bmp",800,70);
	m_Tool.FileToBitmap(m_hBitmapHouse,"bmp\\GameRun\\House.bmp",500,350);
	m_Tool.FileToBitmap(m_hBitmapGamble,"bmp\\GameRun\\Gamble.bmp",900,150);
	m_Tool.FileToBitmap(m_hBitmapGambleGo,"bmp\\GameRun\\GambleGo.bmp",150,150);
	m_pGameMap=NULL;
	CRect crSmallRole0(230,250,230+50,250+70);
	CRect crSmallRole1(510,250,510+50,250+70);
	CRect crSmallRole2(230,330,230+50,330+70);
	CRect crSmallRole3(510,330,510+50,330+70);
	m_ButtonClkSmallRole[0].SetcrButton(crSmallRole0);
	m_ButtonClkSmallRole[1].SetcrButton(crSmallRole1);
	m_ButtonClkSmallRole[2].SetcrButton(crSmallRole2);
	m_ButtonClkSmallRole[3].SetcrButton(crSmallRole3);
	CPoint ptSmallRoleCash;
	CPoint ptSmallRoleProperty;
	for (int i=0;i<4;i++)
	{
		m_ButtonClkSmallRole[i].SetcrOriginalButton();
		m_ButtonClkSmallRole[i].SetcrLastButton();
	}

	ptSmallRoleCash.x=310;
	ptSmallRoleCash.y=250;
	ptSmallRoleProperty.x=310;
	ptSmallRoleProperty.y=285;
	m_ptSmallRoleCash[0]=ptSmallRoleCash;
	m_ptSmallRoleProperty[0]=ptSmallRoleProperty;
	ptSmallRoleCash.x=590;
	ptSmallRoleCash.y=250;
	ptSmallRoleProperty.x=590;
	ptSmallRoleProperty.y=285;
	m_ptSmallRoleCash[1]=ptSmallRoleCash;
	m_ptSmallRoleProperty[1]=ptSmallRoleProperty;
	ptSmallRoleCash.x=310;
	ptSmallRoleCash.y=330;
	ptSmallRoleProperty.x=310;
	ptSmallRoleProperty.y=365;
	m_ptSmallRoleCash[2]=ptSmallRoleCash;
	m_ptSmallRoleProperty[2]=ptSmallRoleProperty;
	ptSmallRoleCash.x=590;
	ptSmallRoleCash.y=330;
	ptSmallRoleProperty.x=590;
	ptSmallRoleProperty.y=365;
	m_ptSmallRoleCash[3]=ptSmallRoleCash;
	m_ptSmallRoleProperty[3]=ptSmallRoleProperty;
	m_Tool.FileToBitmap(m_hBitmapBkRoleLook,"bmp\\GameRun\\BkRoleLook.bmp",1024,768);
	m_Tool.FileToBitmap(m_hBitmapMenu,"bmp\\GameMenu\\GameMenuButton.bmp",75,150);
	m_bGameEnd=FALSE;
	m_bRoleLose=FALSE;
}

CGame::~CGame(void)
{
	delete m_pGameMap;
	m_pGameMap=NULL;
	DeleteDC(m_hOffscreenDC);
	DeleteDC(m_hMemDC);
	DeleteObject(m_hOldBitmap);
	m_hOldBitmap=NULL;
	DeleteObject(m_hBitmapBkGameMenu[0]);
	DeleteObject(m_hBitmapBkGameMenu[1]);
	DeleteObject(m_hBitmapBkGameMenu[2]);
	memset(m_hBitmapBkGameMenu,NULL,3);
	DeleteObject(m_hBitmapStart);
	m_hBitmapStart=NULL;
	DeleteObject(m_hBitmapLoad);
	m_hBitmapLoad=NULL;
	DeleteObject(m_hBitmapExit);
	m_hBitmapExit=NULL;
	DeleteObject(m_hBitmapBkGameLoading);
	m_hBitmapBkGameLoading=NULL;
	DeleteObject(m_hBitmapLoading);
	m_hBitmapLoading=NULL;
	DeleteObject(m_hBitmapBkChoose);
	m_hBitmapBkChoose=NULL;
	DeleteObject(m_hBitmapRole);
	m_hBitmapRole=NULL;
	DeleteObject(m_hBitmapBkGameRun);
	m_hBitmapBkGameRun=NULL;
	DeleteObject(m_hBitmapGameState);
	m_hBitmapGameState=NULL;
	DeleteObject(m_hBitmapHouse);
	m_hBitmapBkGameRun=NULL;
	DeleteObject(m_hBitmapGamble);
	m_hBitmapGamble=NULL;
	DeleteObject(m_hBitmapGambleGo);
	m_hBitmapGambleGo=NULL;
	m_vstrRoleName.clear();
	DeleteObject(m_hBitmapBkRoleLook);
	m_hBitmapBkRoleLook=NULL;
	DeleteObject(m_hBitmapMenu);
	m_hBitmapMenu=NULL;
	

}
void CGame::Draw()
{
	if (m_nState==GAMEMENU)
	{
		m_hOldBitmap=(HBITMAP)SelectObject(m_hMemDC,m_hBitmapBkGameMenu[m_nIndexBkGameMenu]);
		BitBlt(m_hOffscreenDC,0,0,1024,768,m_hMemDC,0,0,SRCCOPY);
		SelectObject(m_hMemDC,m_hOldBitmap);
		m_hOldBitmap=(HBITMAP)SelectObject(m_hMemDC,m_hBitmapStart);
		StretchBlt(m_hOffscreenDC,m_ButtonClkStart.GetcrButton().left,m_ButtonClkStart.GetcrButton().top,m_ButtonClkStart.GetcrButton().Width(),
			m_ButtonClkStart.GetcrButton().Height(),m_hMemDC,0,0,75,150,SRCCOPY);
		SelectObject(m_hMemDC,m_hOldBitmap);
		m_hOldBitmap=(HBITMAP)SelectObject(m_hMemDC,m_hBitmapLoad);
		StretchBlt(m_hOffscreenDC,m_ButtonClkLoad.GetcrButton().left,m_ButtonClkLoad.GetcrButton().top,m_ButtonClkLoad.GetcrButton().Width(),
			m_ButtonClkLoad.GetcrButton().Height(),m_hMemDC,0,0,75,150,SRCCOPY);
		SelectObject(m_hMemDC,m_hOldBitmap);
		m_hOldBitmap=(HBITMAP)SelectObject(m_hMemDC,m_hBitmapExit);
		StretchBlt(m_hOffscreenDC,m_ButtonClkExit.GetcrButton().left,m_ButtonClkExit.GetcrButton().top,m_ButtonClkExit.GetcrButton().Width(),
			m_ButtonClkExit.GetcrButton().Height(),m_hMemDC,0,0,75,150,SRCCOPY);
		SelectObject(m_hMemDC,m_hOldBitmap);
	}
	else if (m_nState==GAMELOADING)
	{
		m_hOldBitmap=(HBITMAP)SelectObject(m_hMemDC,m_hBitmapBkGameLoading);
		BitBlt(m_hOffscreenDC,0,0,1024,768,m_hMemDC,0,0,SRCCOPY);
		SelectObject(m_hMemDC,m_hOldBitmap);
		m_hOldBitmap=(HBITMAP)SelectObject(m_hMemDC,m_hBitmapLoading);
		BitBlt(m_hOffscreenDC,m_crLoading.left,m_crLoading.top,m_crLoading.Width(),m_crLoading.Height(),m_hMemDC,0,0,SRCCOPY);
		SelectObject(m_hMemDC,m_hOldBitmap);
	}
	else if (m_nState==GAMECHOOSE||m_nState==ROLECHOOSE)
	{
		m_hOldBitmap=(HBITMAP)SelectObject(m_hMemDC,m_hBitmapBkChoose);
		BitBlt(m_hOffscreenDC,0,0,1024,768,m_hMemDC,0,0,SRCCOPY);
		SelectObject(m_hMemDC,m_hOldBitmap);
		for (int nRoleNum=0;nRoleNum<4;nRoleNum++)
		{
			m_hOldBitmap=(HBITMAP)SelectObject(m_hMemDC,m_hBitmapRole);
			TransparentBlt(m_hOffscreenDC,m_ButtonClkRole[nRoleNum].GetcrButton().left,m_ButtonClkRole[nRoleNum].GetcrButton().top,
				m_ButtonClkRole[nRoleNum].GetcrButton().Width(),m_ButtonClkRole[nRoleNum].GetcrButton().Height(),m_hMemDC,nRoleNum*200,0,200,280,RGB(255,255,255));
			SelectObject(m_hMemDC,m_hOldBitmap);
		}
		if (m_nState==ROLECHOOSE)
		{
			m_Tool.DrawMapText(m_vstrRoleName[0].c_str(),40,30,RGB(0,0,0),50,m_hOffscreenDC);
			m_Tool.DrawMapText(m_vstrRoleName[1].c_str(),290,30,RGB(0,0,0),50,m_hOffscreenDC);
			m_Tool.DrawMapText(m_vstrRoleName[2].c_str(),540,30,RGB(0,0,0),50,m_hOffscreenDC);
			m_Tool.DrawMapText(m_vstrRoleName[3].c_str(),790,30,RGB(0,0,0),50,m_hOffscreenDC);
			if (m_bPlayerChooseEnd==FALSE)
			{
				m_Tool.DrawMapText("请选择玩家角色",300,520,RGB(0,0,0),50,m_hOffscreenDC);
			}
			else
			{
				m_Tool.DrawMapText("请选择电脑角色",300,520,RGB(0,0,0),50,m_hOffscreenDC);
			}		
		}		
	}
	else if (m_nState==GAMBLERUN||m_nState==ROLEWALK)
	{
		m_hOldBitmap=(HBITMAP)SelectObject(m_hMemDC,m_hBitmapBkGameRun);
		BitBlt(m_hOffscreenDC,0,0,1024,768,m_hMemDC,0,0,SRCCOPY);
		SelectObject(m_hMemDC,m_hOldBitmap);
		DrawGameMap();
		DrawGameRole();
		DrawGameRunRoleCur();
		if (m_nState==GAMBLERUN)
		{
			DrawGambleGo();
			if (CRole::m_bGambleGo==FALSE&&CRole::m_bGambleDecide==FALSE)
			{
				DrawGameRunRoleAllBasic();
				DrawRunButton();
			}
			else if (CRole::m_bGambleGo==TRUE&&CRole::m_bGambleDecide==FALSE)
			{
				DrawGameRunRoleAllBasic();
				DrawGamble();	
			}
			else
			{
				if (CRole::m_bGambleGo==FALSE&&CRole::m_bGambleDecide==TRUE)
				{
					DrawGamble();
					CString str;
					str.Format("%s前进了%d步",(m_vpRole[CRole::m_nRoleOrderCur]->m_strRoleName).c_str(),m_vpRole[CRole::m_nRoleOrderCur]->m_nWalk);
					m_Tool.DrawMapText(str,300,250,RGB(0,0,0),50,m_hOffscreenDC);
				} 
			}
		}
		if (m_nState==ROLEWALK)
		{ 
			DrawGamble();	
			CString str;
			str.Format("%s前进中。。。",(m_vpRole[CRole::m_nRoleOrderCur]->m_strRoleName).c_str());
			m_Tool.DrawMapText(str,300,250,RGB(0,0,0),50,m_hOffscreenDC);
		}
	}
	else if (m_nState==ROLELOOK)
	{
		DrawRoleLook(m_vpRole.at(CRole::m_nRoleOrderCur)->m_nRoleLookNum);
	}
	else if (m_nState==ROLELOSE)
	{
		DrawRoleLook(CRole::m_nRoleOrderCur);
		m_Tool.DrawMapText("破产了！！！",350,300,RGB(255,0,0),100,m_hOffscreenDC);
	}
	else if(m_nState==ROLEWIN)
	{
		DrawRoleLook(CRole::m_nRoleOrderCur);
		m_Tool.DrawMapText("胜利了！！！",350,300,RGB(255,0,0),100,m_hOffscreenDC);
	}
}
void CGame::UpdateGameMenu()
{
	if (m_nIndexBkGameMenu<2)
	{
		m_nIndexBkGameMenu++;
	}
	else 
	{
		m_nIndexBkGameMenu=0;
	}
	InvalidateRect(m_hWnd,NULL,FALSE);
}
void CGame::MouseMove(CPoint ptNewMouseMove)
{
	if (m_nState==GAMEMENU)
	{
		m_ButtonClkStart.MouseMove(m_hWnd,ptNewMouseMove,m_ptOldMouseMove);
		m_ButtonClkLoad.MouseMove(m_hWnd,ptNewMouseMove,m_ptOldMouseMove);
		m_ButtonClkExit.MouseMove(m_hWnd,ptNewMouseMove,m_ptOldMouseMove);
	}
	else if (m_nState==ROLECHOOSE)
	{
		for (int nRoleNum=0;nRoleNum<4;nRoleNum++)
		{
			if (m_bRoleChoose[nRoleNum]==FALSE)
			{
				m_ButtonClkRole[nRoleNum].MouseMove(m_hWnd,ptNewMouseMove,m_ptOldMouseMove);
			}
		}
	}	
	else if (m_nState==GAMBLERUN)
	{	
		m_vpRole.at(CRole::m_nRoleOrderCur)->MouseMove(m_hWnd,ptNewMouseMove,m_ptOldMouseMove,m_vpRole,m_ButtonClkSmallRole);
	}
	m_ptOldMouseMove=ptNewMouseMove;
}
void CGame::LButtonDown(CPoint ptLClk)
{
	static int snRoleNum=0;
	switch (m_nState)
	{
	case GAMEMENU:
		if (m_ButtonClkStart.GetcrButton().PtInRect(ptLClk))
		{
			GameBegin();
		}
		else if (m_ButtonClkLoad.GetcrButton().PtInRect(ptLClk))
		{
			GameLoad();	
		}
		else if (m_ButtonClkExit.GetcrButton().PtInRect(ptLClk))
		{
			GameExit();
		}
		break;
	case ROLECHOOSE:
		for (int nRoleNum=0;nRoleNum<4;nRoleNum++)
		{
			if (m_bRoleChoose[nRoleNum]==FALSE)
			{
				if (m_ButtonClkRole[nRoleNum].GetcrButton().PtInRect(ptLClk))
				{
					if (snRoleNum+1<=static_cast<int>(m_vpPlayer.size()))
					{
						m_vpPlayer.at(snRoleNum)->m_nRoleID=nRoleNum+1;
						m_vpPlayer[snRoleNum]->m_strRoleName=m_vstrRoleName.at(nRoleNum);
						if (snRoleNum+1==static_cast<int>(m_vpPlayer.size()))
						{
							m_bPlayerChooseEnd=TRUE;
						}
					}
					else
					{
						m_vpComputer.at(snRoleNum-m_vpPlayer.size())->m_nRoleID=nRoleNum+1;
						m_vpComputer.at(snRoleNum-m_vpPlayer.size())->m_strRoleName=m_vstrRoleName[nRoleNum];
					}
					snRoleNum++;
					m_bRoleChoose[nRoleNum]=TRUE;
				}
			}
		}			
		if (snRoleNum==m_vpPlayer.size()+m_vpComputer.size())
		{
			m_nState=GAMELOADING;
			m_bRoleChoose[0]=FALSE;
			m_bRoleChoose[1]=FALSE;
			m_bRoleChoose[2]=FALSE;
			m_bRoleChoose[3]=FALSE;
			m_bPlayerChooseEnd=FALSE;
			GameLoading();
		}
		break;
	case GAMBLERUN:
		m_vpRole.at(CRole::m_nRoleOrderCur)->LButtonDown(m_hWnd,ptLClk,m_nState,m_vpRole,m_ButtonClkSmallRole,m_Tool,m_bGameEnd,m_bRoleLose);
		break;
	case ROLELOOK:
		m_vpRole.at(CRole::m_nRoleOrderCur)->LButtonDown(m_hWnd,ptLClk,m_nState,m_vpRole,m_ButtonClkSmallRole,m_Tool,m_bGameEnd,m_bRoleLose);
		break;
	case ROLELOSE:
		m_vpRole.at(CRole::m_nRoleOrderCur)->LButtonDown(m_hWnd,ptLClk,m_nState,m_vpRole,m_ButtonClkSmallRole,m_Tool,m_bGameEnd,m_bRoleLose);
		break;
	case ROLEWIN:
		m_vpRole.at(CRole::m_nRoleOrderCur)->LButtonDown(m_hWnd,ptLClk,m_nState,m_vpRole,m_ButtonClkSmallRole,m_Tool,m_bGameEnd,m_bRoleLose);
		break;
	default:
		break;
	}
}
void CGame::UpdatecrLoading()
{
	GameRunInitialize();
	m_crLoading.right+=1024/16;
	if (m_crLoading.right<1024)
	{
		InvalidateRect(m_hWnd,NULL,FALSE);
	}
	else
	{
		KillTimer(m_hWnd,GAMELOADING);
		CRect crLoading(0,450,0,630);
		m_crLoading=crLoading;
		m_Tool.CloseMIDIPlayer();
		m_Tool.PlayMIDISong("Music\\GameRun.mid");
		m_vpRole.at(CRole::m_nRoleOrderCur)->GameRun(m_nState,m_hWnd,m_vpRole,m_bGameEnd);
	}
}
void CGame::GameBegin()
{
	KillTimer(m_hWnd,GAMEMENU);
	m_Tool.CloseMIDIPlayer();
	m_Tool.PlayMIDISong("Music\\GameChoose.mid");
	m_nState=GAMECHOOSE;
	GameChoose();
	RoleChoose();
}
void CGame::GameLoading()
{
	SetTimer(m_hWnd,GAMELOADING,250,NULL);
	UpdatecrLoading();
}
void CGame::GameChoose()
{
	InvalidateRect(m_hWnd,NULL,FALSE);
	CPlayer* pPlayer;
	CComputer* pComputer;
	CRole* pRole;
	CDlgGameChoose DlgGameChoose;
	if (DlgGameChoose.DoModal()==IDOK)
	{
		m_nWinProperty=DlgGameChoose.m_nWinProperty;
		for (int nPlayerNum=1;nPlayerNum<=DlgGameChoose.m_nPlayerNum;nPlayerNum++)
		{
			pPlayer=new CPlayer;
			pPlayer->m_nRoleType=PLAYERTYPE;
			pPlayer->m_nCash=DlgGameChoose.m_nStartCash;
			pPlayer->m_nProperty=DlgGameChoose.m_nStartCash;
			m_vpPlayer.push_back(pPlayer);
			pRole=pPlayer;
			m_vpRole.push_back(pRole);
		}
		for (int nComputerNum=1;nComputerNum<=DlgGameChoose.m_nRoleNum-DlgGameChoose.m_nPlayerNum;nComputerNum++)
		{
			pComputer=new CComputer;
			pComputer->m_nRoleType=COMPUTERTYPE;
			pComputer->m_nCash=DlgGameChoose.m_nStartCash;
			pComputer->m_nProperty=DlgGameChoose.m_nStartCash;
			m_vpComputer.push_back(pComputer);
			pRole=pComputer;
			m_vpRole.push_back(pRole);
		}
	}
}
void CGame::RoleChoose()
{
	m_nState=ROLECHOOSE;
	InvalidateRect(m_hWnd,NULL,FALSE);
}
void CGame::GameRunInitialize()
{
	m_pGameMap=new CGameMap;
	RolePlaceInitialize();
	GetHouseAll();
	
}
BOOL CGame::GetHouseAll()
{
	ifstream inHouseAll("HouseAllStart.txt");
	if (!inHouseAll)
	{
		AfxMessageBox("读取所有房子初始信息HouseAllStart.txt失败！");
		return FALSE;
	}
	getline(inHouseAll,string());
	CHouse* pHouse;	
	while (!inHouseAll.eof())
	{
		pHouse=new CHouse;
		inHouseAll>>pHouse->m_nHouseID>>pHouse->m_nHouseStars>>pHouse->m_nHousePrice>>pHouse->m_nUpGradePrice
			>>pHouse->m_nExpenses[0]>>pHouse->m_nExpenses[1]>>pHouse->m_nExpenses[2]>>pHouse->m_nExpenses[3]
		>>pHouse->m_nExpenses[4]>>pHouse->m_nHouseMasterID;
		CRole::m_vpHouse.push_back(pHouse);
	}
	inHouseAll.close();
	return TRUE;
}
void CGame::RolePlaceInitialize()
{
	int nLine;
	int nColumn;
	for (int nRoleNum=0;nRoleNum<static_cast<int>(m_vpRole.size());nRoleNum++)
	{
		nLine=rand()%LINE;
		if (nLine<LINE-1&&nLine>0)
		{
			nColumn=rand()%2;
			if (nColumn==1)
			{
				nColumn=COLUMN-1;
			} 	
		} 
		else			
		{
			nColumn=rand()%COLUMN;	
		}		
		m_vpRole.at(nRoleNum)->m_ptPlace.x=nColumn;
		m_vpRole.at(nRoleNum)->m_ptPlace.y=nLine;
		m_vpRole.at(nRoleNum)->m_strPlace=m_pGameMap->m_strMapArray[nColumn][nLine];
		RolePathInitialize(nRoleNum,nColumn,nLine);	
	}
	random_shuffle(m_vpRole.begin(),m_vpRole.end());
}
void CGame::RolePathInitialize(int nRoleNum,int nRoleptX,int nRoleptY)
{
	if (nRoleptY==0)
	{
		m_vpRole.at(nRoleNum)->m_nPath=1;
	}
	else if (nRoleptY==LINE-1)
	{
		m_vpRole.at(nRoleNum)->m_nPath=3;
	}
	else 
	{
		if (nRoleptX==0)
		{
			m_vpRole.at(nRoleNum)->m_nPath=4;
		} 
		else
		{
			m_vpRole.at(nRoleNum)->m_nPath=2;
		}
	}
}

void CGame::DrawGameMap()
{
	for (int nLine=0;nLine<LINE;nLine++)
	{
		for (int nColumn=0;nColumn<COLUMN;nColumn++)
		{
			if (m_pGameMap->m_nMapArray[nLine][nColumn]<=-1&&m_pGameMap->m_nMapArray[nLine][nColumn]>=-15)
			{
				m_hOldBitmap=(HBITMAP)SelectObject(m_hMemDC,m_hBitmapHouse);
				int nHouseMaseterID=CRole::m_vpHouse[-(m_pGameMap->m_nMapArray[nLine][nColumn])-1]->m_nHouseMasterID;
				int nHouseStarts=CRole::m_vpHouse[-(m_pGameMap->m_nMapArray[nLine][nColumn])-1]->m_nHouseStars;
				BitBlt(m_hOffscreenDC,MAPLEFTTOPX+nColumn*100,MAPLEFTTOPY+nLine*70,100,70,m_hMemDC,(nHouseStarts-1)*100,nHouseMaseterID*70,SRCCOPY);
				SelectObject(m_hMemDC,m_hOldBitmap);		
			} 
			else if(m_pGameMap->m_nMapArray[nLine][nColumn]<=7&&m_pGameMap->m_nMapArray[nLine][nColumn]>=1)
			{
				m_hOldBitmap=(HBITMAP)SelectObject(m_hMemDC,m_hBitmapGameState);
				BitBlt(m_hOffscreenDC,MAPLEFTTOPX+nColumn*100,MAPLEFTTOPY+nLine*70,100,70,m_hMemDC,(m_pGameMap->m_nMapArray[nLine][nColumn]-1)*100,0,SRCCOPY);
				SelectObject(m_hMemDC,m_hOldBitmap);
			}
		}
	}
}
void CGame::DrawGameRole()
{
	m_hOldBitmap=(HBITMAP)SelectObject(m_hMemDC,m_hBitmapRole);
	for (int nRoleNum=0;nRoleNum<static_cast<int>(m_vpRole.size());nRoleNum++)
	{
		TransparentBlt(m_hOffscreenDC,MAPLEFTTOPX+25+(m_vpRole.at(nRoleNum)->m_ptPlace.x)*100,MAPLEFTTOPY+(m_vpRole.at(nRoleNum)->m_ptPlace.y)*70,
			50,70,m_hMemDC,(m_vpRole.at(nRoleNum)->m_nRoleID-1)*200,0,200,280,RGB(255,255,255));
	}
	TransparentBlt(m_hOffscreenDC,MAPLEFTTOPX+25+(m_vpRole.at(CRole::m_nRoleOrderCur)->m_ptPlace.x)*100,MAPLEFTTOPY+(m_vpRole.at(CRole::m_nRoleOrderCur)->m_ptPlace.y)*70,
		50,70,m_hMemDC,(m_vpRole.at(CRole::m_nRoleOrderCur)->m_nRoleID-1)*200,0,200,280,RGB(255,255,255));
	SelectObject(m_hMemDC,m_hOldBitmap);
}
void CGame::DrawGameRunRoleCur()
{
	//char str[100];
	//string str2=m_vpRole[m_nRoleOrderCur]->m_strRoleName;
	//sprintf(str,"轮到你了%s,！",str2.data());
	CString str;
	str.Format("轮到你了,%s！",(m_vpRole[CRole::m_nRoleOrderCur]->m_strRoleName).data());
	m_Tool.DrawMapText(str,20,50,RGB(0,0,0),50,m_hOffscreenDC);
	m_hOldBitmap=(HBITMAP)SelectObject(m_hMemDC,m_hBitmapRole);
	TransparentBlt(m_hOffscreenDC,500,0,100,140,m_hMemDC,(m_vpRole.at(CRole::m_nRoleOrderCur)->m_nRoleID-1)*200,0,200,280,RGB(255,255,255));
	SelectObject(m_hMemDC,m_hOldBitmap);
	str="现金：";
	str.Format("%s %d",str,m_vpRole[CRole::m_nRoleOrderCur]->m_nCash);
	m_Tool.DrawMapText(str,650,10,RGB(0,0,0),50,m_hOffscreenDC);
	str="总资产:";
	str.Format("%s %d",str,m_vpRole[CRole::m_nRoleOrderCur]->m_nProperty);
	m_Tool.DrawMapText(str,650,MAPLEFTTOPY/2+10,RGB(0,0,0),50,m_hOffscreenDC);
}
void CGame::DrawGambleGo()
{
	m_hOldBitmap=(HBITMAP)SelectObject(m_hMemDC,m_hBitmapGambleGo);
	TransparentBlt(m_hOffscreenDC,m_vpRole.at(CRole::m_nRoleOrderCur)->m_ButtonClkGambleGo.GetcrButton().left,m_vpRole.at(CRole::m_nRoleOrderCur)->m_ButtonClkGambleGo.GetcrButton().top
		,m_vpRole.at(CRole::m_nRoleOrderCur)->m_ButtonClkGambleGo.GetcrButton().Width(),m_vpRole.at(CRole::m_nRoleOrderCur)->m_ButtonClkGambleGo.GetcrButton().Height(),m_hMemDC,0,0,150,150,RGB(255,255,255));
	SelectObject(m_hMemDC,m_hOldBitmap);
}
void CGame::DrawGamble()
{
	m_hOldBitmap=(HBITMAP)SelectObject(m_hMemDC,m_hBitmapGamble);
	BitBlt(m_hOffscreenDC,GAMBLEX,GAMBLEY,150,150,m_hMemDC,150*(m_vpRole.at(CRole::m_nRoleOrderCur)->m_nWalk-1),0,SRCCOPY);
	SelectObject(m_hMemDC,m_hOldBitmap);
}
void CGame::DrawGameRunRoleAllBasic()
{
	CString str;
	for (int nRoleNum=1;nRoleNum<=static_cast<int>(m_vpRole.size());nRoleNum++)
	{
		m_hOldBitmap=(HBITMAP)SelectObject(m_hMemDC,m_hBitmapRole);
		TransparentBlt(m_hOffscreenDC,m_ButtonClkSmallRole[nRoleNum-1].GetcrButton().left,m_ButtonClkSmallRole[nRoleNum-1].GetcrButton().top,
			m_ButtonClkSmallRole[nRoleNum-1].GetcrButton().Width(),m_ButtonClkSmallRole[nRoleNum-1].GetcrButton().Height(),m_hMemDC,(m_vpRole.at(nRoleNum-1)->m_nRoleID-1)*200,0,200,280,RGB(255,255,255));
		SelectObject(m_hMemDC,m_hOldBitmap);
		str.Format("现金:%d",m_vpRole.at(nRoleNum-1)->m_nCash);
		m_Tool.DrawMapText(str,m_ptSmallRoleCash[nRoleNum-1].x,m_ptSmallRoleCash[nRoleNum-1].y,RGB(0,0,0),20,m_hOffscreenDC);
		str.Format("总资产:%d",m_vpRole.at(nRoleNum-1)->m_nProperty);
		m_Tool.DrawMapText(str,m_ptSmallRoleProperty[nRoleNum-1].x,m_ptSmallRoleProperty[nRoleNum-1].y,RGB(0,0,0),20,m_hOffscreenDC);
	}	
}
void CGame::DrawRunButton()
{
	m_hOldBitmap=(HBITMAP)SelectObject(m_hMemDC,m_hBitmapExit);
	StretchBlt(m_hOffscreenDC,m_vpRole.at(CRole::m_nRoleOrderCur)->m_ButtonClkExit.GetcrButton().left,m_vpRole.at(CRole::m_nRoleOrderCur)->m_ButtonClkExit.GetcrButton().top
		,m_vpRole.at(CRole::m_nRoleOrderCur)->m_ButtonClkExit.GetcrButton().Width(),m_vpRole.at(CRole::m_nRoleOrderCur)->m_ButtonClkExit.GetcrButton().Height(),m_hMemDC,0,0,75,150,SRCCOPY);
	SelectObject(m_hMemDC,m_hOldBitmap);
	m_hOldBitmap=(HBITMAP)SelectObject(m_hMemDC,m_hBitmapMenu);
	StretchBlt(m_hOffscreenDC,m_vpRole.at(CRole::m_nRoleOrderCur)->m_ButtonClkMenu.GetcrButton().left,m_vpRole.at(CRole::m_nRoleOrderCur)->m_ButtonClkMenu.GetcrButton().top
		,m_vpRole.at(CRole::m_nRoleOrderCur)->m_ButtonClkMenu.GetcrButton().Width(),m_vpRole.at(CRole::m_nRoleOrderCur)->m_ButtonClkMenu.GetcrButton().Height(),m_hMemDC,0,0,75,150,SRCCOPY);
	SelectObject(m_hMemDC,m_hOldBitmap);
}
void CGame::DrawRoleLook(int nRoleLookNum)
{
	m_hOldBitmap=(HBITMAP)SelectObject(m_hMemDC,m_hBitmapBkRoleLook);
	BitBlt(m_hOffscreenDC,0,0,1024,768,m_hMemDC,0,0,SRCCOPY);
	SelectObject(m_hMemDC,m_hOldBitmap);
	m_hOldBitmap=(HBITMAP)SelectObject(m_hMemDC,m_hBitmapRole);
	BitBlt(m_hOffscreenDC,ROLEBITMAPX,ROLEBITMAPY,200,280,m_hMemDC,(m_vpRole.at(nRoleLookNum)->m_nRoleID-1)*200,0,SRCCOPY);
	SelectObject(m_hMemDC,m_hOldBitmap);
	CString str;
	str.Format("%s",m_vpRole.at(nRoleLookNum)->m_strRoleName.c_str());
	m_Tool.DrawMapText(str,ROLENAMEX,ROLECASHY,RGB(0,0,255),50,m_hOffscreenDC);
	str.Format("地点: %s",m_vpRole.at(nRoleLookNum)->m_strPlace.c_str());
	m_Tool.DrawMapText(str,ROLEPLACEX,ROLEPLACEY,RGB(0,0,255),40,m_hOffscreenDC);
	str.Format("现金: %d",m_vpRole.at(nRoleLookNum)->m_nCash);
	m_Tool.DrawMapText(str,ROLECASHX,ROLECASHY,RGB(0,0,255),40,m_hOffscreenDC);
	str.Format("一星级房子数目: %d",m_vpRole.at(nRoleLookNum)->m_nHouseStarsNum[0]);
	m_Tool.DrawMapText(str,ROLEHOUSENUM1X,ROLEHOUSENUM1Y,RGB(0,0,255),40,m_hOffscreenDC);
	str.Format("二星级房子数目: %d",m_vpRole.at(nRoleLookNum)->m_nHouseStarsNum[1]);
	m_Tool.DrawMapText(str,ROLEHOUSENUM2X,ROLEHOUSENUM2Y,RGB(0,0,255),40,m_hOffscreenDC);
	str.Format("三星级房子数目: %d",m_vpRole.at(nRoleLookNum)->m_nHouseStarsNum[2]);
	m_Tool.DrawMapText(str,ROLEHOUSENUM3X,ROLEHOUSENUM3Y,RGB(0,0,255),40,m_hOffscreenDC);
	str.Format("四星级房子数目: %d",m_vpRole.at(nRoleLookNum)->m_nHouseStarsNum[3]);
	m_Tool.DrawMapText(str,ROLEHOUSENUM4X,ROLEHOUSENUM4Y,RGB(0,0,255),40,m_hOffscreenDC);
	str.Format("五星级房子数目: %d",m_vpRole.at(nRoleLookNum)->m_nHouseStarsNum[4]);
	m_Tool.DrawMapText(str,ROLEHOUSENUM5X,ROLEHOUSENUM5Y,RGB(0,0,255),40,m_hOffscreenDC);
	str.Format("房产总额: %d",m_vpRole.at(nRoleLookNum)->m_nHouseProperty);
	m_Tool.DrawMapText(str,ROLEHOUSEPROPERTYX,ROLEHOUSEPROPERTYY,RGB(0,0,255),40,m_hOffscreenDC);
	str.Format("股票总额: %d",m_vpRole.at(nRoleLookNum)->m_nStockProperty);
	m_Tool.DrawMapText(str,ROLESTOCKPROPERTYX,ROLESTOCKPROPERTYY,RGB(0,0,255),40,m_hOffscreenDC);
	str.Format("存款总额: %d",m_vpRole.at(nRoleLookNum)->m_nDeposit);
	m_Tool.DrawMapText(str,ROLEDEPOSITX,ROLEDEPOSITY,RGB(0,0,255),40,m_hOffscreenDC);
	str.Format("贷款总额: %d",m_vpRole.at(nRoleLookNum)->m_nLend);
	m_Tool.DrawMapText(str,ROLELENDX,ROLELENDY,RGB(0,0,255),40,m_hOffscreenDC);
	str.Format("总资产: %d",m_vpRole.at(nRoleLookNum)->m_nProperty);
	m_Tool.DrawMapText(str,ROLEPROPERTYX,ROLEPROPERTYY,RGB(0,0,255),40,m_hOffscreenDC);

}
void CGame::GameLoad()
{
}
void CGame::GameExit()
{
	PostQuitMessage(0);
}
void CGame::Timer(UINT_PTR nIDEvent)
{
	switch (nIDEvent)
	{
	case GAMEMENU:
		UpdateGameMenu();
		break;
	case GAMELOADING:
		UpdatecrLoading();
		break;
	case GAMBLERUN:
		m_vpRole.at(CRole::m_nRoleOrderCur)->UpdateGamble(m_hWnd,m_nState);
		break;
	case ROLEWALK:
		m_vpRole.at(CRole::m_nRoleOrderCur)->UpdateRoleWalk(m_hWnd,m_nState,m_vpRole,m_pGameMap,m_nWinProperty,m_bGameEnd,m_bRoleLose);
		break;
	default:
		break;
	}
}