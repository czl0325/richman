// DlgHouseNoneMaster.cpp : 实现文件
//

#include "stdafx.h"
#include "RichMan.h"
#include "DlgHouseNoneMaster.h"


// CDlgHouseNoneMaster 对话框

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


// CDlgHouseNoneMaster 消息处理程序

void CDlgHouseNoneMaster::OnEnChangeProperty()
{
	// TODO:  如果该控件是 RICHEDIT 控件，则它将不会
	// 发送该通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

void CDlgHouseNoneMaster::OnBnClickedBuy()
{
	// TODO: 在此添加控件通知处理程序代码
	m_nHouseRunState=IDBUY;
	PostMessage(WM_CLOSE);	
}

void CDlgHouseNoneMaster::OnBnClickedLeave()
{
	// TODO: 在此添加控件通知处理程序代码
	m_nHouseRunState=IDLEAVE;
	PostMessage(WM_CLOSE);
}
