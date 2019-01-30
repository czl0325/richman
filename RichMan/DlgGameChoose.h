#pragma once

// CDlgGameChoose 对话框

class CDlgGameChoose : public CDialog
{
	DECLARE_DYNAMIC(CDlgGameChoose)

public:
	CDlgGameChoose(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgGameChoose();

// 对话框数据
	enum { IDD = IDD_GAMECHOOSE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_nRoleNum;
	int m_nPlayerNum;
	int m_nStartCash;
	int m_nWinProperty;
	
public:
	afx_msg void OnBnClickedOk();
};
