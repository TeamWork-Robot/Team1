#pragma once
#include "afxcmn.h"

#include "excel.h"
// CEmlpoyeeDlg dialog

class CEmlpoyeeDlg : public CBCGPDialog
{
	DECLARE_DYNAMIC(CEmlpoyeeDlg)

public:
	CEmlpoyeeDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CEmlpoyeeDlg();

// Dialog Data
	enum { IDD = IDD_EMPLOYEE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedAddButton();
	afx_msg void OnBnClickedModifyButton();
	afx_msg void OnBnClickedDeleteButton();
	CBCGPListCtrl m_employeeList;
	int m_itemDelteOrModify;

	CExcelFile excelFileEmployee;
	int row;
	int col;
	
	virtual BOOL OnInitDialog();
	void InitEmployeeList();
	afx_msg void OnClickEmployeeList(NMHDR *pNMHDR, LRESULT *pResult);
};
