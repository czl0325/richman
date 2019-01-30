// DlgGameChoose.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "RichMan.h"
#include "DlgGameChoose.h"


// CDlgGameChoose �Ի���

IMPLEMENT_DYNAMIC(CDlgGameChoose, CDialog)

CDlgGameChoose::CDlgGameChoose(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgGameChoose::IDD, pParent)
	, m_nRoleNum(4)
	, m_nPlayerNum(1)
	, m_nStartCash(10000)
	, m_nWinProperty(30000)
{

}

CDlgGameChoose::~CDlgGameChoose()
{
}

void CDlgGameChoose::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_ROLENUM, m_nRoleNum);
	DDV_MinMaxInt(pDX, m_nRoleNum, 2, 4);
	DDX_Text(pDX, IDC_PLAYERNUM, m_nPlayerNum);
	DDV_MinMaxInt(pDX, m_nPlayerNum, 1, m_nRoleNum);
	DDX_Text(pDX, IDC_STARTCASH, m_nStartCash);
	DDV_MinMaxInt(pDX, m_nStartCash, 0, 20000);
	DDX_Text(pDX, IDC_WINPROPERTY, m_nWinProperty);
	DDV_MinMaxInt(pDX, m_nWinProperty, 1000, 60000);
}


BEGIN_MESSAGE_MAP(CDlgGameChoose, CDialog)
	ON_BN_CLICKED(IDOK, &CDlgGameChoose::OnBnClickedOk)
END_MESSAGE_MAP()


// CDlgGameChoose ��Ϣ�������

void CDlgGameChoose::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData();
	OnOK();
}
