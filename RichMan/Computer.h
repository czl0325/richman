#pragma once
#include "role.h"

class CComputer :
	public CRole
{
public:
	CComputer(void);
	~CComputer(void);
	int m_nGambleCount;
	void GameRun(int& nState,HWND hWnd,vector<CRole*>&vpRole,BOOL& bGameEnd);
	void UpdateGamble(HWND hWnd,int& nState);
	void LButtonDown(HWND hWnd,CPoint ptLClk,int& nState,vector<CRole*>&vpRole,CButtonClk m_ButtonClkSmallRole[],CTool& Tool,BOOL& bGameEnd,BOOL& bRoleLose);
	void MouseMove(HWND hWnd,CPoint ptNewMouseMove,CPoint ptOldMouseMove,vector<CRole*>&vpRole,CButtonClk m_ButtonClkSmallRole[]);
	void HouseRun(int nHouseNum,vector<CRole*>&vpRole);
};
