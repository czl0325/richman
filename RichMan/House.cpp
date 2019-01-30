#include "StdAfx.h"
#include "House.h"

CHouse::CHouse(void)
{
	GetHouseBasic();
}

CHouse::~CHouse(void)
{
}
BOOL CHouse::GetHouseBasic()
{
	ifstream inHouseBasic("HouseBasic.txt");
	if (!inHouseBasic)
	{
		AfxMessageBox("读取房子基本信息HouseBasic.txt失败！");
		return FALSE;
	}
	getline(inHouseBasic,string());
	inHouseBasic>>m_nHouseID>>m_nHouseStars>>m_nHousePrice>>m_nUpGradePrice
		>>m_nExpenses[0]>>m_nExpenses[1]>>m_nExpenses[2]>>m_nExpenses[3]>>m_nExpenses[4]>>m_nHouseMasterID;
	inHouseBasic.close();
	return TRUE;
}
