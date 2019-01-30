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
		AfxMessageBox("��ȡ��Ϸ��ͼ��ϢGameMap.txtʧ��!");
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
				m_strMapArray[nLine][nColumn]="��01";
				break;
			case -2:
				m_strMapArray[nLine][nColumn]="��02";
				break;
			case -3:
				m_strMapArray[nLine][nColumn]="��03";
				break;
			case -4:
				m_strMapArray[nLine][nColumn]="��04";
				break;
			case -5:
				m_strMapArray[nLine][nColumn]="��05";
				break;
			case -6:
				m_strMapArray[nLine][nColumn]="��06";
				break;
			case -7:
				m_strMapArray[nLine][nColumn]="��07";
				break;
			case -8:
				m_strMapArray[nLine][nColumn]="��08";
				break;
			case -9:
				m_strMapArray[nLine][nColumn]="��09";
				break;
			case -10:
				m_strMapArray[nLine][nColumn]="��10";
				break;
			case -11:
				m_strMapArray[nLine][nColumn]="��11";
				break;
			case -12:
				m_strMapArray[nLine][nColumn]="��12";
				break;
			case -13:
				m_strMapArray[nLine][nColumn]="��13";
				break;
			case -14:
				m_strMapArray[nLine][nColumn]="��14";
				break;
			case -15:
				m_strMapArray[nLine][nColumn]="��15";
				break;
			case 1:
				m_strMapArray[nLine][nColumn]="����";
				break;
			case 2:
				m_strMapArray[nLine][nColumn]="��Ʊ";
				break;
			case 3:
				m_strMapArray[nLine][nColumn]="����";
				break;
			case 4:
				m_strMapArray[nLine][nColumn]="���";
				break;
			case 5:
				m_strMapArray[nLine][nColumn]="����";
				break;
			case 6:
				m_strMapArray[nLine][nColumn]="��Ϸ";
				break;
			case 7:
				m_strMapArray[nLine][nColumn]="��͸";
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
