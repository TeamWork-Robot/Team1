#pragma once


// CBossDlg dialog

class CBossDlg : public CBCGPDialog
{
	DECLARE_DYNAMIC(CBossDlg)

public:
	CBossDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CBossDlg();

// Dialog Data
	enum { IDD = IDD_BOSS_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCaffeButton();
	afx_msg void OnBnClickedSellButton();
};
