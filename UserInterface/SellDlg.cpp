// SellDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Test.h"
#include "SellDlg.h"
#include "afxdialogex.h"

#include "CAxes.h"
#include "CAxis.h"
#include "CAxisTitle.h"
#include "CTitles.h"
#include "CSeries.h"
#include "CTChart.h"
// CSellDlg dialog

IMPLEMENT_DYNAMIC(CSellDlg, CBCGPDialog)

CSellDlg::CSellDlg(CWnd* pParent /*=NULL*/)
	: CBCGPDialog(CSellDlg::IDD, pParent)
{
	EnableVisualManagerStyle(TRUE, TRUE);
	//BOOL success = excelFileSell.InitExcel();
	kabuqinuoDa=0;
	kabuqinuoXiao=0;
	aierlanDa=0;
	aierlanXiao=0;
	natieDa=0;
	natieXiao=0;
	row=0;
}

CSellDlg::~CSellDlg()
{
}

void CSellDlg::DoDataExchange(CDataExchange* pDX)
{
	CBCGPDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BAR_TCHART, m_barChart);
	DDX_Control(pDX, IDC_YEAR_COMBO, m_year);
	DDX_Control(pDX, IDC_MONTH_COMBO, m_month);
	DDX_Control(pDX, IDC_BARPIE_COMBO, m_barPie);
}


BEGIN_MESSAGE_MAP(CSellDlg, CBCGPDialog)
	ON_CBN_SELCHANGE(IDC_YEAR_COMBO, &CSellDlg::OnSelchangeYearCombo)
	ON_CBN_SELCHANGE(IDC_MONTH_COMBO, &CSellDlg::OnSelchangeMonthCombo)
	ON_CBN_SELCHANGE(IDC_BARPIE_COMBO, &CSellDlg::OnSelchangeBarpieCombo)
END_MESSAGE_MAP()


// CSellDlg message handlers


BOOL CSellDlg::OnInitDialog()
{
	CBCGPDialog::OnInitDialog();
	m_year.SetCurSel(0);
	m_month.SetCurSel(0);
	//m_barChart.put_Height(100); //设置图表高度为100
	//long Height_size = m_barChart.get_Height(); //获取当前图表的高度
	//m_barChart.put_Width(100); //设置图表高度为100
	//long Width_size = m_barChart.get_Width(); //获取当前图表的高度

	
	//m_barChart.get_Header().get_Text().SetItem(0, COleVariant(_T("TeeChart 使用范例")));
	//m_barChart.get_Header().get_Text().Add(COleVariant(_T("追加的标题")));

	//m_barChart.get_Axis().GetBottom().GetTitle().SetCaption("X轴的标题");
	//m_barChart.get_Axis().get_Left().get_Title().put_Caption("Y轴的标题");
	//m_barChart.get_Axis().GetBottom().SetMinMax(0, 100);
	
	//m_barChart.get_Legend().SetVisible(FALSE); //隐藏图例
	calcuSell();
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CSellDlg::calcuSell()
{
	long i(0);
	
	//m_barChart.AddSeries(1);
	//m_barChart.AddSeries(2);
	//m_barChart.AddSeries(3);
	
	int value;
	
	BOOL success;
	success = excelFileSell.OpenExcelFile(_T("D:\\sell.xlsx"));
	if(success==FALSE) 
	{
		AfxMessageBox(_T("打开销售表失败"));
	}
	
	int sheetCount=excelFileSell.GetSheetCount();
	if(sheetCount>=1)
	{
		for(int j=1;j<=sheetCount;j++)
		{
			success = excelFileSell.LoadSheet(j,true);
			if(success==FALSE) AfxMessageBox(_T("打开销售表sheet失败"));
			
			row=excelFileSell.GetRowCount();
			int col=excelFileSell.GetColumnCount();
			if(row>=2)
			{
				DWORD pNumElements[] = { row-1 };
				XValuesBar[j-1].Create(VT_INT, 1, pNumElements);
				YValuesBar[j-1].Create(VT_INT, 1, pNumElements);
				
				for(i=0;i<row-1;i++)
				{
					value=i+1;
					XValuesBar[j-1].PutElement(&i, &value);
					
					value=excelFileSell.GetCellInt(value+1,2);
					YValuesBar[j-1].PutElement(&i, &value);
						
					switch (j)
					{
						case 1:
							kabuqinuoDa+=value;
						break;
						case 2:
							kabuqinuoXiao+=value;
						break;
						case 3:
							aierlanDa+=value;
						break;
						case 4:
							aierlanXiao+=value;
						break;
						case 5:
							natieDa+=value;
						break;
						case 6:
							natieXiao+=value;
						break;
					}
					
				}
			}
			
		}
	}
	
	excelFileSell.CloseExcelFile();
	
}

void CSellDlg::showBarSell()
{
	CSeries ChartBar;
	ChartBar = (CSeries)m_barChart.Series(6);
	ChartBar.Clear();
	
	UpdateData(TRUE);
	for(int j=1;j<=6;j++)
	{
		ChartBar = (CSeries)m_barChart.Series(j-1);
		ChartBar.Clear();
		ChartBar.AddArray(row-1, YValuesBar[j-1], XValuesBar[j-1]);
	}
	UpdateData(FALSE);
}

void CSellDlg::showPieSell()
{
	int sum;
	
	CSeries ChartBar;// = (CSeries)m_barChart.Series(6);
	for(int j=0;j<=6;j++)
	{
		ChartBar = (CSeries)m_barChart.Series(j);
		ChartBar.Clear();
	}
		
	double ratio;
	sum=kabuqinuoDa+kabuqinuoXiao+aierlanDa+aierlanXiao+natieDa+natieXiao;
	UpdateData(TRUE);
	ratio = (double)kabuqinuoDa / sum;
	ChartBar.Add(ratio, _T("卡布奇诺大杯月内占比"), 20000);
	ratio = (double)kabuqinuoXiao / sum;
	ChartBar.Add(ratio,_T("卡布奇诺小杯月内占比"),10000);
	ratio = (double)aierlanDa / sum;
	ChartBar.Add(ratio,_T("爱尔兰大杯月内占比"),5000);
	ratio = (double)aierlanXiao / sum;
	ChartBar.Add(ratio,_T("爱尔兰小杯月内占比"),300);
	ratio = (double)natieDa / sum;
	ChartBar.Add(ratio,_T("拿铁大杯月内占比"),170);
	ratio = (double)natieXiao / sum;
	ChartBar.Add(ratio,_T("拿铁小杯月内占比"),10);
	UpdateData(FALSE);
}

void CSellDlg::OnSelchangeYearCombo()
{
	// TODO: Add your control notification handler code here
}


void CSellDlg::OnSelchangeMonthCombo()
{
	// TODO: Add your control notification handler code here
}


void CSellDlg::OnSelchangeBarpieCombo()
{
	// TODO: Add your control notification handler code here
	int mIndex;
	mIndex=m_barPie.GetCurSel();	
	switch(mIndex)
	{
		case 0:
			showBarSell();
		break;
		case 1:
			showPieSell();
		break;
		default:
			showBarSell();
		break;
	}
}
