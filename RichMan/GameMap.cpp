#include "StdAfx.h"
#include "GameMap.h"

CGameMap::CGameMap(void)
{
	GetMapStart();
}

CGameMap::~CGameMap(void)
{
}
BOOL CGameMap::GetMapStart()
{
	ifstream inGameMap("GameMap.txt");
	int nLine,nColumn;
	if (!inGameMap)
	{
		AfxMessageBox("读取游戏地图信息GameMap.txt失败!");
		return FALSE;
	}
	for (nLine=0;nLine<LINE;nLine++)
	{
		for (nColumn=0;nColumn<COLUMN;nColumn++)
		{
			inGameMap>>m_nMapArray[nLine][nColumn];
		}
	}
	inGameMap.close();
	for (nLine=0;nLine<LINE;nLine++)
	{
		for (nColumn=0;nColumn<COLUMN;nColumn++)
		{
			switch (m_nMapArray[nLine][nColumn])
			{
			case -1:
				m_strMapArray[nLine][nColumn]="房01";
				break;
			case -2:
				m_strMapArray[nLine][nColumn]="房02";
				break;
			case -3:
				m_strMapArray[nLine][nColumn]="房03";
				break;
			case -4:
				m_strMapArray[nLine][nColumn]="房04";
				break;
			case -5:
				m_strMapArray[nLine][nColumn]="房05";
				break;
			case -6:
				m_strMapArray[nLine][nColumn]="房06";
				break;
			case -7:
				m_strMapArray[nLine][nColumn]="房07";
				break;
			case -8:
				m_strMapArray[nLine][nColumn]="房08";
				break;
			case -9:
				m_strMapArray[nLine][nColumn]="房09";
				break;
			case -10:
				m_strMapArray[nLine][nColumn]="房10";
				break;
			case -11:
				m_strMapArray[nLine][nColumn]="房11";
				break;
			case -12:
				m_strMapArray[nLine][nColumn]="房12";
				break;
			case -13:
				m_strMapArray[nLine][nColumn]="房13";
				break;
			case -14:
				m_strMapArray[nLine][nColumn]="房14";
				break;
			case -15:
				m_strMapArray[nLine][nColumn]="房15";
				break;
			case 1:
				m_strMapArray[nLine][nColumn]="银行";
				break;
			case 2:
				m_strMapArray[nLine][nColumn]="股票";
				break;
			case 3:
				m_strMapArray[nLine][nColumn]="命运";
				break;
			case 4:
				m_strMapArray[nLine][nColumn]="金矿";
				break;
			case 5:
				m_strMapArray[nLine][nColumn]="地雷";
				break;
			case 6:
				m_strMapArray[nLine][nColumn]="游戏";
				break;
			case 7:
				m_strMapArray[nLine][nColumn]="乐透";
				break;
			case 0:
				m_strMapArray[nLine][nColumn]="";
				break;
			default:
				break;
			}
		}
	}
	return TRUE;
}
