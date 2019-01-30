#pragma once
#include "resource.h"
#include "DlgGameChoose.h"
#include "ButtonClk.h"
#include "Player.h"
#include "GameMap.h"
#include "House.h"
#include "Computer.h"
#include "Tool.h"
#include "RoleLook.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define GAMEMENU 1
#define GAMELOADING 2
#define GAMECHOOSE 3
#define ROLECHOOSE 4
#define GAMBLERUN 5
#define ROLEWALK 6
#define ROLELOOK 7
#define ROLELOSE 8
#define ROLEWIN 9
#define PLAYERTYPE 0
#define COMPUTERTYPE 1
#define LINE 8
#define COLUMN 8
#define MAPLEFTTOPX 100
#define MAPLEFTTOPY 150
#define GAMBLEX 640
#define GAMBLEY 450
class CGame
{
private:
	CTool m_Tool;
	HWND m_hWnd;
	HDC m_hOffscreenDC;
	HDC m_hMemDC;
	HBITMAP m_hOldBitmap;
	int m_nState;
	HBITMAP m_hBitmapBkGameMenu[3];
	int m_nIndexBkGameMenu;
	HBITMAP m_hBitmapStart;
	CButtonClk m_ButtonClkStart;
	HBITMAP m_hBitmapLoad;
	CButtonClk m_ButtonClkLoad;
	HBITMAP m_hBitmapExit;
	CButtonClk m_ButtonClkExit;
	CPoint m_ptOldMouseMove;
	HBITMAP m_hBitmapBkChoose;
	vector<string>m_vstrRoleName;
	HBITMAP m_hBitmapRole;
	CButtonClk m_ButtonClkRole[4];
	BOOL m_bRoleChoose[4];
	BOOL m_bPlayerChooseEnd;
	vector<CPlayer*>m_vpPlayer;
	vector<CComputer*>m_vpComputer;
	vector<CRole*>m_vpRole;
	int m_nWinProperty;
	HBITMAP m_hBitmapBkGameLoading;
	HBITMAP m_hBitmapLoading;
	CRect m_crLoading;
	HBITMAP m_hBitmapBkGameRun;
	HBITMAP m_hBitmapGameState;
	HBITMAP m_hBitmapHouse;
	HBITMAP m_hBitmapGamble;
	HBITMAP m_hBitmapGambleGo;
	CGameMap* m_pGameMap;
	CButtonClk m_ButtonClkSmallRole[4];
	CPoint m_ptSmallRoleCash[4];
	CPoint m_ptSmallRoleProperty[4];
	HBITMAP m_hBitmapBkRoleLook;
	HBITMAP m_hBitmapMenu;
	BOOL m_bGameEnd;
	BOOL m_bRoleLose;
private:
	void UpdateGameMenu();
	void UpdatecrLoading();
	void GameBegin();
	void GameLoading();
	void GameChoose();
	void RoleChoose();
	void GameRunInitialize();
	BOOL GetHouseAll();
	void RolePlaceInitialize();
	void RolePathInitialize(int nRoleNum,int nRoleptX,int nRoleptY);
	void DrawGameMap();
	void DrawGameRole();
	void DrawGameRunRoleCur();
	void DrawGambleGo();
	void DrawGamble();
	void DrawGameRunRoleAllBasic();
	void DrawRunButton();
	void DrawRoleLook(int nRoleLookNum);
	void GameLoad();
	void GameExit();
public:
	HDC GethOffscreenDC()
	{
		return m_hOffscreenDC;
	};
public:
	CGame(HDC hDC,HWND hWnd);
	~CGame(void);
	void Draw();
	void MouseMove(CPoint ptNewMouseMove);
	void LButtonDown(CPoint ptLClk);
	void Timer(UINT_PTR nIDEvent);
};
