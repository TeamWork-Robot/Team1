#pragma once
#include "afxwin.h"


// CAddEmployeDlg dialog

class CAddEmployeDlg : public CBCGPDialog
{
	DECLARE_DYNAMIC(CAddEmployeDlg)

public:
	CAddEmployeDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CAddEmployeDlg();

// Dialog Data
	enum { IDD = IDD_ADDEMPLOY_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	
	CString m_passWord;
	CString m_userName;
	CString m_zhiWei;

	CString get_UserName();
	CString get_PassWord();
	CString get_ZhiWei();
	afx_msg void OnBnClickedOk();
};
