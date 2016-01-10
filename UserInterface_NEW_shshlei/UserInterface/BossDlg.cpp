// BossDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Test.h"
#include "BossDlg.h"
#include "afxdialogex.h"

#include "CaffeDlg.h"
#include "SellDlg.h"
#include "EmlpoyeeDlg.h"
// CBossDlg dialog

IMPLEMENT_DYNAMIC(CBossDlg, CBCGPDialog)

CBossDlg::CBossDlg(CWnd* pParent /*=NULL*/)
	: CBCGPDialog(CBossDlg::IDD, pParent)
{
	EnableVisualManagerStyle(TRUE, TRUE);
}

CBossDlg::~CBossDlg()
{
}

void CBossDlg::DoDataExchange(CDataExchange* pDX)
{
	CBCGPDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CBossDlg, CBCGPDialog)
	ON_BN_CLICKED(IDC_CAFFE_BUTTON, &CBossDlg::OnBnClickedCaffeButton)
	ON_BN_CLICKED(IDC_SELL_BUTTON, &CBossDlg::OnBnClickedSellButton)
	ON_BN_CLICKED(IDC_MAN_BUTTON, &CBossDlg::OnBnClickedManButton)
END_MESSAGE_MAP()


// CBossDlg message handlers


void CBossDlg::OnBnClickedCaffeButton()
{
	// TODO: Add your control notification handler code here
	CCaffeDlg dlg;
	dlg.DoModal();
}


void CBossDlg::OnBnClickedSellButton()
{
	// TODO: Add your control notification handler code here
	CSellDlg dlg;
	dlg.DoModal();
}


void CBossDlg::OnBnClickedManButton()
{
	// TODO: Add your control notification handler code here
	CEmlpoyeeDlg dlg;
	dlg.DoModal();
}
