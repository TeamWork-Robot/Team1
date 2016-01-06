#pragma once

#include "tchart1.h"
#include "CSeries.h"
#include "afxwin.h"

#include "excel.h"
// CSellDlg dialog

class CSellDlg : public CBCGPDialog
{
	DECLARE_DYNAMIC(CSellDlg)

public:
	CSellDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CSellDlg();

// Dialog Data
	enum { IDD = IDD_SELL_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:

	virtual BOOL OnInitDialog();
	CTchart1 m_barChart;
	CComboBox m_year;
	CComboBox m_month;

	CExcelFile excelFileSell;
	int row;
	void calcuSell();
	void showBarSell();
	void showPieSell();
	COleSafeArray XValuesBar[6];
	COleSafeArray YValuesBar[6];
	int kabuqinuoDa;
	int kabuqinuoXiao;
	int aierlanDa;
	int aierlanXiao;
	int natieDa;
	int natieXiao;
	CComboBox m_barPie;
	afx_msg void OnSelchangeYearCombo();
	afx_msg void OnSelchangeMonthCombo();
	afx_msg void OnSelchangeBarpieCombo();
};
