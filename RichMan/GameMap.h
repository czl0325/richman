#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#define LINE 8
#define COLUMN 8
class CGameMap
{
public:
	int m_nMapArray[LINE][COLUMN];
	string m_strMapArray[LINE][COLUMN];
private:
	BOOL GetMapStart();//��ʼ����ͼ��Ϣ
public:
	CGameMap(void);
	~CGameMap(void);
	
};
