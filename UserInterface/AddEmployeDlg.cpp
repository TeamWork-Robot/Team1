// AddEmployeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Test.h"
#include "AddEmployeDlg.h"
#include "afxdialogex.h"


// CAddEmployeDlg dialog

IMPLEMENT_DYNAMIC(CAddEmployeDlg, CBCGPDialog)

CAddEmployeDlg::CAddEmployeDlg(CWnd* pParent /*=NULL*/)
	: CBCGPDialog(CAddEmployeDlg::IDD, pParent)
	, m_passWord(_T(""))
	, m_userName(_T(""))
	, m_zhiWei(_T(""))
{

}

CAddEmployeDlg::~CAddEmployeDlg()
{
}

void CAddEmployeDlg::DoDataExchange(CDataExchange* pDX)
{
	CBCGPDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAddEmployeDlg, CBCGPDialog)
	ON_BN_CLICKED(IDOK, &CAddEmployeDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CAddEmployeDlg message handlers

CString CAddEmployeDlg::get_UserName()
{
	return m_userName;
}

CString CAddEmployeDlg::get_PassWord()
{
	return m_passWord;
}

CString CAddEmployeDlg::get_ZhiWei()
{
	return m_zhiWei;
}

void CAddEmployeDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_PASSWORD_EDIT)->GetWindowText(m_passWord); 
	GetDlgItem(IDC_USERNAME_EDIT)->GetWindowText(m_userName);
	GetDlgItem(IDC_ZHIWEI_EDIT)->GetWindowText(m_zhiWei);
	CBCGPDialog::OnOK();
}
