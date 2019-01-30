// DlgHouseNoneMaster.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "RichMan.h"
#include "DlgHouseNoneMaster.h"


// CDlgHouseNoneMaster �Ի���

IMPLEMENT_DYNAMIC(CDlgHouseNoneMaster, CDialog)

CDlgHouseNoneMaster::CDlgHouseNoneMaster(CRole* pRole,CHouse* pHouse,vector<CRole*>vpRole,CWnd* pParent /*=NULL*/)
	: CDialog(CDlgHouseNoneMaster::IDD, pParent)
{
	m_nHouseRunState=-1;
	m_strRoleName.Format("%s",pRole->m_strRoleName.c_str());
	m_nCash=pRole->m_nCash;
	m_nProperty=pRole->m_nProperty;
	m_strHouseName.Format("%s",pRole->m_strPlace.c_str());
	for (int nRoleNum=0;nRoleNum<static_cast<int>(vpRole.size());nRoleNum++)
	{
		if (vpRole.at(nRoleNum)->m_nRoleID==pHouse->m_nHouseMasterID)
		{
			m_strMaster.Format("%s",vpRole.at(nRoleNum)->m_strRoleName);
			break;
		}
	}
	m_nHouseStars=pHouse->m_nHouseStars;
	m_nHousePrice=pHouse->m_nHousePrice;
	m_nUpGradePrice=pHouse->m_nUpGradePrice;
	m_nExpenses=pHouse->m_nExpenses[m_nHouseStars-1];
}

CDlgHouseNoneMaster::~CDlgHouseNoneMaster()
{
}

void CDlgHouseNoneMaster::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_ROLENAME, m_strRoleName);
	DDX_Text(pDX, IDC_CASH, m_nCash);
	DDX_Text(pDX, IDC_PROPERTY, m_nProperty);
	DDX_Text(pDX, IDC_HOUSENAME, m_strHouseName);
	DDX_Text(pDX, IDC_MASTER, m_strMaster);
	DDX_Text(pDX, IDC_STAR, m_nHouseStars);
	DDX_Text(pDX, IDC_PRICE, m_nHousePrice);
	DDX_Text(pDX, IDC_UPGRADE, m_nUpGradePrice);
	DDX_Text(pDX, IDC_EXPENSES, m_nExpenses);
}


BEGIN_MESSAGE_MAP(CDlgHouseNoneMaster, CDialog)
	ON_EN_CHANGE(IDC_PROPERTY, &CDlgHouseNoneMaster::OnEnChangeProperty)
	ON_BN_CLICKED(IDBUY, &CDlgHouseNoneMaster::OnBnClickedBuy)
	ON_BN_CLICKED(IDLEAVE, &CDlgHouseNoneMaster::OnBnClickedLeave)
END_MESSAGE_MAP()


// CDlgHouseNoneMaster ��Ϣ�������

void CDlgHouseNoneMaster::OnEnChangeProperty()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ�������������
	// ���͸�֪ͨ��������д CDialog::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}

void CDlgHouseNoneMaster::OnBnClickedBuy()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_nHouseRunState=IDBUY;
	PostMessage(WM_CLOSE);	
}

void CDlgHouseNoneMaster::OnBnClickedLeave()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_nHouseRunState=IDLEAVE;
	PostMessage(WM_CLOSE);
}
