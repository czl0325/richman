#pragma once
#include "Tool.h"
#include "ButtonClk.h"
#include "GameMap.h"
#include "House.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#define WALKRIGHT 1
#define WALKDOWN 2
#define WALKLEFT 3
#define WALKUP 4
#define PLAYER 1
#define COMPUTER 2
#define BUTTONGAMBLEGOX 220
#define BUTTONGAMBLEGOY 450
#define BUTTONEXITX 920
#define BUTTONEXITY 220
#define BUTTONMENUX 920
#define BUTTONMENUY 400
#define GAMEMENU 1
#define GAMBLERUN 5
#define ROLEWALK 6
#define ROLELOOK 7
#define ROLELOSE 8
#define ROLEWIN 9
class CRole
{
public:
	int m_nRoleID;//-1,1~4
	int m_nRoleType;//-1,0~1
	string m_strRoleName;
	CPoint m_ptPlace;
	string m_strPlace;
	int m_nPath;
	int m_nCash;
	int m_nDeposit;
	int m_nLend;
	int m_nHouseStarsNum[5];
	int m_nHouseProperty;
	vector<int>m_vnStockNum;
	vector<int>m_vnStockPriceBuy;
	int m_nStockProperty;
	int m_nProperty;
public:
	int m_nRoleLookNum;
	static int m_nRoleOrderCur;
	static BOOL m_bGambleGo;
	CButtonClk m_ButtonClkGambleGo;
	int m_nWalk;
	int m_nRoleWalk;
	static BOOL m_bRoleWaleEnd;
	static BOOL m_bGambleDecide;
	CButtonClk m_ButtonClkExit;
	CButtonClk m_ButtonClkMenu;
public:
	static vector<CHouse*>m_vpHouse;
protected:
	BOOL GetRoleStart();
public:
	CRole(void);
	~CRole(void);
	BOOL Lose();
	BOOL Win(int nPropertyWin);
	void Property(); 
public:
	virtual void GameRun(int& nState,HWND hWnd,vector<CRole*>&vpRole,BOOL& bGameEnd)=0;
	virtual void UpdateGamble(HWND hWnd,int& nState)=0;
	void UpdateRoleWalk(HWND hWnd,int& nState,vector<CRole*>&vpRole,CGameMap* pGameMap,int nWinProperty,BOOL& bGameEnd,BOOL& bRoleLose);
	void AffairJudge(vector<CRole*>&vpRole,CGameMap* pGameMap);
	void PathJudge(CGameMap* pGameMap);
	void AfterWalk(vector<CRole*>&vpRole,int& nState,HWND hWnd,int nWinProperty,BOOL& bGameEnd,BOOL& bRoleLose);
	virtual void HouseRun(int nHouseNum,vector<CRole*>&vpRole)=0;
	void RoleClear(vector<CRole*>vpRole);
public:
	virtual void LButtonDown(HWND hWnd,CPoint ptLClk,int& nState,vector<CRole*>&vpRole,CButtonClk m_ButtonClkSmallRole[],CTool& Tool,BOOL& bGameEnd,BOOL& bRoleLose)=0;
	virtual void MouseMove(HWND hWnd,CPoint ptNewMouseMove,CPoint ptOldMouseMove,vector<CRole*>&vpRole,CButtonClk m_ButtonClkSmallRole[])=0;
};
