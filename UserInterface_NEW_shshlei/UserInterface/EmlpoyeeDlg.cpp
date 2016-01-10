// EmlpoyeeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Test.h"
#include "EmlpoyeeDlg.h"
#include "afxdialogex.h"

#include "AddEmployeDlg.h"

// CEmlpoyeeDlg dialog

IMPLEMENT_DYNAMIC(CEmlpoyeeDlg, CBCGPDialog)

CEmlpoyeeDlg::CEmlpoyeeDlg(CWnd* pParent /*=NULL*/)
	: CBCGPDialog(CEmlpoyeeDlg::IDD, pParent)
{
	EnableVisualManagerStyle(TRUE, TRUE);
	m_itemDelteOrModify = -1;
	row=-1;
	col=-1;
}

CEmlpoyeeDlg::~CEmlpoyeeDlg()
{
}

void CEmlpoyeeDlg::DoDataExchange(CDataExchange* pDX)
{
	CBCGPDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EMPLOYEE_LIST, m_employeeList);
}


BEGIN_MESSAGE_MAP(CEmlpoyeeDlg, CBCGPDialog)
	ON_BN_CLICKED(IDC_ADD_BUTTON, &CEmlpoyeeDlg::OnBnClickedAddButton)
	ON_BN_CLICKED(IDC_MODIFY_BUTTON, &CEmlpoyeeDlg::OnBnClickedModifyButton)
	ON_BN_CLICKED(IDC_DELETE_BUTTON, &CEmlpoyeeDlg::OnBnClickedDeleteButton)
	ON_NOTIFY(NM_CLICK, IDC_EMPLOYEE_LIST, &CEmlpoyeeDlg::OnClickEmployeeList)
END_MESSAGE_MAP()


// CEmlpoyeeDlg message handlers

void CEmlpoyeeDlg::OnBnClickedAddButton()
{
	// TODO: Add your control notification handler code here
	//CWnd::ShowWindow(SW_HIDE);
	CAddEmployeDlg dlg;
	dlg.DoModal();
	//CWnd::ShowWindow(SW_SHOW);
	
	CString pass=dlg.get_PassWord();
	CString user=dlg.get_UserName();
	CString zhiwei=dlg.get_ZhiWei();
	
	if(_T("")!=pass&&_T("")!=user&&_T("")!=zhiwei)
	{
		CString str;
		str.Format(_T("%d"), row);
		m_employeeList.InsertItem(row, str);
		m_employeeList.SetItemData(row, row);
		
		BOOL success;
		success = excelFileEmployee.OpenExcelFile(_T("D:\\man.xlsx"));
		if(success==FALSE) 
		{
			AfxMessageBox(_T("打开员工信息表失败"));
		}
		
		success = excelFileEmployee.LoadSheet(1,true);
		if(success==FALSE) AfxMessageBox(_T("打开员工信息表sheet失败"));
		
		excelFileEmployee.SetCellString((long)row+1, 1, zhiwei);
		excelFileEmployee.SetCellString((long)row + 1, 2, user);
		excelFileEmployee.SetCellString((long)row + 1, 3,pass);

		excelFileEmployee.SaveasXSLFile(_T("D:\\man.xlsx"));
		excelFileEmployee.CloseExcelFile();
		
		m_employeeList.SetItemText(row-1, 1, zhiwei);
		m_employeeList.SetItemText(row-1, 2, user);
		m_employeeList.SetItemText(row-1, 3, pass);
		row++;
	}
	
}

void CEmlpoyeeDlg::OnBnClickedModifyButton()
{
	// TODO: Add your control notification handler code here
	if (-1 != m_itemDelteOrModify)
	{
		//CWnd::ShowWindow(SW_HIDE);
		CAddEmployeDlg dlg;
		dlg.DoModal();
		//CWnd::ShowWindow(SW_SHOW);
		
		CString pass=dlg.get_PassWord();
		CString user=dlg.get_UserName();
		CString zhiwei=dlg.get_ZhiWei();
		
		if(_T("")!=pass&&_T("")!=user&&_T("")!=zhiwei)
		{
			BOOL success;
			success = excelFileEmployee.OpenExcelFile(_T("D:\\man.xlsx"));
			if(success==FALSE) 
			{
				AfxMessageBox(_T("打开员工信息表失败"));
			}
			
			success = excelFileEmployee.LoadSheet(1,true);
			if(success==FALSE) AfxMessageBox(_T("打开员工信息表sheet失败"));
			
			excelFileEmployee.SetCellString((long)m_itemDelteOrModify+2, 1, zhiwei);
			excelFileEmployee.SetCellString((long)m_itemDelteOrModify + 2, 2, user);
			excelFileEmployee.SetCellString((long)m_itemDelteOrModify + 2, 3,pass);

			excelFileEmployee.SaveasXSLFile(_T("D:\\man.xlsx"));
			excelFileEmployee.CloseExcelFile();
			
			m_employeeList.SetItemText(m_itemDelteOrModify, 1, zhiwei);
			m_employeeList.SetItemText(m_itemDelteOrModify, 2, user);
			m_employeeList.SetItemText(m_itemDelteOrModify, 3, pass);
		}
		
	}
	
}


void CEmlpoyeeDlg::OnBnClickedDeleteButton()
{
	// TODO: Add your control notification handler code here
	if (-1 != m_itemDelteOrModify)
		m_employeeList.DeleteItem(m_itemDelteOrModify);
}


BOOL CEmlpoyeeDlg::OnInitDialog()
{
	CBCGPDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	InitEmployeeList();
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CEmlpoyeeDlg::InitEmployeeList()
{
	CString str;
	
	CRect rect;
	m_employeeList.GetClientRect(&rect);
	m_employeeList.SetExtendedStyle(m_employeeList.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_employeeList.InsertColumn(0, _T("#"), LVCFMT_CENTER, rect.Width() / 10);
	m_employeeList.InsertColumn (1, _T("职位"), LVCFMT_CENTER, 	  3*rect.Width()/10);
	m_employeeList.InsertColumn(2, _T("用户名"), LVCFMT_CENTER, 3 * rect.Width() / 10);
	m_employeeList.InsertColumn(3, _T("密码"), LVCFMT_CENTER, 3 * rect.Width() / 10);

	BOOL success;
	success = excelFileEmployee.OpenExcelFile(_T("D:\\man.xlsx"));
	if(success==FALSE) 
	{
		AfxMessageBox(_T("打开员工信息表失败"));
	}
	
	success = excelFileEmployee.LoadSheet(1,true);
	if(success==FALSE) AfxMessageBox(_T("打开员工信息表sheet失败"));
	
	row=excelFileEmployee.GetRowCount();
	col=excelFileEmployee.GetColumnCount();
	if(row>=2)
	{
		for(int i=2;i<=row;i++)
		{
			str.Format(_T("%d"), i - 1);
			m_employeeList.InsertItem(i - 1, str);
			m_employeeList.SetItemData(i - 1, i - 1);
			for(int j=1;j<=col;j++)
			{
				str=excelFileEmployee.GetCellString(i,j);
			
				m_employeeList.SetItemText(i - 2, j, str);
			}
			
		}
	}
	
	excelFileEmployee.CloseExcelFile();
}


void CEmlpoyeeDlg::OnClickEmployeeList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: Add your control notification handler code here
	NMLISTVIEW *pNMListView = (NMLISTVIEW *)pNMHDR;
	if (-1 != pNMListView->iItem)
		m_itemDelteOrModify = pNMListView->iItem;

	*pResult = 0;
}
