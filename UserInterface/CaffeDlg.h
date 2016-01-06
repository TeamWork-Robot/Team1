// CaffeDlg.h : header file
//

#pragma once
#include "afxwin.h"


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
public:
	CStatic m_caffeTypeLocation;
	CStatic m_peiliaoLocation;
	
};
