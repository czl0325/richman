#pragma once
#include <vector>
#include <string>
using namespace std;
#include "Resource.h"
#include "Player.h"
#include "Role.h"


// CDlgHouseNoneMaster �Ի���

class CDlgHouseNoneMaster : public CDialog
{
	DECLARE_DYNAMIC(CDlgHouseNoneMaster)

public:
	CDlgHouseNoneMaster(CRole* pRole,CHouse* pHouse,vector<CRole*>vpRole,CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgHouseNoneMaster();

// �Ի�������
	enum { IDD = IDD_HOUSENONEMASTER};

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int m_nHouseRunState;
	CString m_strRoleName;
	afx_msg void OnEnChangeProperty();
	int m_nCash;
	int m_nProperty;
	CString m_strHouseName;
	CString m_strMaster;
	int m_nHouseStars;
	int m_nHousePrice;
	int m_nUpGradePrice;
	int m_nExpenses;
	afx_msg void OnBnClickedBuy();
	afx_msg void OnBnClickedLeave();
};
