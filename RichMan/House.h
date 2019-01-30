#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class CHouse
{
public:
	int m_nHouseID;//房子ID
	int m_nHouseStars;//房子星级
	int m_nHousePrice;//房子价值
	int m_nUpGradePrice;//房子升级费用
	int m_nExpenses[5];//房子对应星级过路费
	int m_nHouseMasterID;//房子主人
protected:
	BOOL GetHouseBasic();
public:
	CHouse(void);
	~CHouse(void);
};
