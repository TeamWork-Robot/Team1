#pragma once

#include "excel.h"
// CUserDlg dialog

class CUserDlg : public CBCGPDialog
{
	DECLARE_DYNAMIC(CUserDlg)

public:
	CUserDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CUserDlg();

	CBCGPRibbonBar* GetRibbonBar()
	{
		return &m_wndRibbonDlgBar.GetRibbon();
	}

// Dialog Data
	enum { IDD = IDD_JIXIESHEJI_DIALOG };

protected:
	HICON m_hIcon;
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
private:
	CBCGPRibbonDialogBar	m_wndRibbonDlgBar;
	CBCGPToolBarImages		m_PanelImages;	// Ribbon panel images
	// (appear when pane is collapsed)
	CBCGPToolBarImages		m_Header;

public:
	CExcelFile excelFile;
	
	afx_msg void OnImagesGallery();
};
