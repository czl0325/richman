#pragma once

class CButtonClk
{
private:
	CRect m_crButton;
	CRect m_crOriginalButton;
	CRect m_crLastButton;
public:
	CRect GetcrButton()
	{
		return m_crButton;
	};
	CRect GetcrOriginalButton()
	{
		return m_crOriginalButton;
	};
public:
	CButtonClk(void);
	~CButtonClk(void);
	void SetcrButton(CRect crButton);
	void SetcrOriginalButton();
	void SetcrLastButton();
	void MouseMove(HWND hWnd,CPoint ptNewMouseMove,CPoint ptOldMouseMove);
};
