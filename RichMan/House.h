#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class CHouse
{
public:
	int m_nHouseID;//����ID
	int m_nHouseStars;//�����Ǽ�
	int m_nHousePrice;//���Ӽ�ֵ
	int m_nUpGradePrice;//������������
	int m_nExpenses[5];//���Ӷ�Ӧ�Ǽ���·��
	int m_nHouseMasterID;//��������
protected:
	BOOL GetHouseBasic();
public:
	CHouse(void);
	~CHouse(void);
};
