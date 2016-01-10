// CaffeDlg.h : header file
//

#pragma once
#include "afxwin.h"

#include "excel.h"
#include "afxcmn.h"

// CCaffeDlg dialog
class CCaffeDlg : public CBCGPDialog
{
// Construction
public:
	CCaffeDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_CAFFE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	CBCGPHotSpotImageCtrl	m_ImageCaffeType;
	CBCGPHotSpotImageCtrl	m_ImagePeiliao;
	
	// Generated message map functions
	virtual BOOL OnInitDialog();
	
	afx_msg void OnClickHotSpotCaffeType();
	afx_msg void OnClickHotSpotPeiliao();
	DECLARE_MESSAGE_MAP()

	void InitImage();
	void InitTime();
	//void InitCaffeList();
	
	CStatic m_caffeTypeLocation;
	CStatic m_peiliaoLocation;
	CExcelFile excelFileSell;
	
	CString time;
	
	//CBCGPListCtrl m_caffeList;
	int m_itemDelteOrModify;
public:
	int caffe[8];
	int unitPrice[8];
	
	int cup;
	float joint[9][2];
	
	float GetJoint(int i,int j) const;
	
	afx_msg void OnBnClickedQuitButton();
	afx_msg void OnBnClickedStartButton();
};
