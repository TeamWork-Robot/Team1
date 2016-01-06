#pragma once


// CLoginDlg dialog

class CLoginDlg : public CBCGPDialog
{
	DECLARE_DYNAMIC(CLoginDlg)

public:
	CLoginDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CLoginDlg();

// Dialog Data
	enum { IDD = IDD_LOGIN_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_passWord;
	CString m_userName;
	CString get_UserName();
	CString get_PassWord();
	
	afx_msg void OnBnClickedOk();
};
