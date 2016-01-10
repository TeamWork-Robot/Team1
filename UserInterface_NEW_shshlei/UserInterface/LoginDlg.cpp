// LoginDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Test.h"
#include "LoginDlg.h"
#include "afxdialogex.h"


// CLoginDlg dialog

IMPLEMENT_DYNAMIC(CLoginDlg, CBCGPDialog)

CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CBCGPDialog(CLoginDlg::IDD, pParent)
	, m_passWord(_T(""))
	, m_userName(_T(""))
{
	EnableVisualManagerStyle(TRUE, TRUE);
}

CLoginDlg::~CLoginDlg()
{
}

void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CBCGPDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CLoginDlg, CBCGPDialog)
	ON_BN_CLICKED(IDOK, &CLoginDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CLoginDlg message handlers


void CLoginDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	
	GetDlgItem(IDC_PASSWORD_EDIT)->GetWindowText(m_passWord);
	GetDlgItem(IDC_USERNAME_EDIT)->GetWindowText(m_userName);
	CBCGPDialog::OnOK();
}
CString CLoginDlg::get_UserName()
{
	return m_userName;
}

CString CLoginDlg::get_PassWord()
{
	return m_passWord;
}
