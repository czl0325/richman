#pragma once

// CDlgGameChoose �Ի���

class CDlgGameChoose : public CDialog
{
	DECLARE_DYNAMIC(CDlgGameChoose)

public:
	CDlgGameChoose(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgGameChoose();

// �Ի�������
	enum { IDD = IDD_GAMECHOOSE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int m_nRoleNum;
	int m_nPlayerNum;
	int m_nStartCash;
	int m_nWinProperty;
	
public:
	afx_msg void OnBnClickedOk();
};
