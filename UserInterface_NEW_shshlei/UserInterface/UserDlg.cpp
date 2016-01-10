// JiXieSheJi.cpp : implementation file
//

#include "stdafx.h"
#include "Test.h"
#include "UserDlg.h"
#include "CaffeDlg.h"
#include "MainFrm.h"
#include "TestDoc.h"
#include "TestView.h"
#include "resource.h"

#include "LoginDlg.h"
#include "BossDlg.h"
// CUserDlg dialog

IMPLEMENT_DYNAMIC(CUserDlg, CBCGPDialog)

CUserDlg::CUserDlg(CWnd* pParent /*=NULL*/)
	: CBCGPDialog(CUserDlg::IDD, pParent)
{
	EnableVisualManagerStyle(TRUE, TRUE);
	
	BOOL success=excelFile.InitExcel();
}

CUserDlg::~CUserDlg()
{
}

void CUserDlg::DoDataExchange(CDataExchange* pDX)
{
	CBCGPDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CUserDlg, CBCGPDialog)
	ON_WM_CREATE()
	ON_COMMAND(ID_IMAGES_GALLERY, &CUserDlg::OnImagesGallery)
END_MESSAGE_MAP()


// CUserDlg message handlers

int CUserDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CBCGPDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	// Load control bar icons:
	CBCGPToolBar::EnableQuickCustomization();

	if (!m_wndRibbonDlgBar.Create(_T(""), this, CRect(0, 0, 3000, 5000),
		0, 0, TRUE, 0,
		WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | CBRS_LEFT | CBRS_FLOAT_MULTI))
	{
		TRACE0("Failed to create Workspace bar\n");
		return -1;      // fail to create
	}

	m_wndRibbonDlgBar.EnableDocking(CBRS_ALIGN_ANY);
	
	m_PanelImages.SetImageSize(CSize(500, 500));
	/*if (!m_PanelImages.Load(IDR_ICONS))
	{
		TRACE0("Failed to load panel images\n");
		return FALSE;
	}*/

	//CBCGPRibbonPanel* pPanelImages = m_wndRibbonDlgBar.AddPanel(_T("Images"), m_PanelImages.ExtractIcon(1));
	CBCGPRibbonPanel* pPanelImages = m_wndRibbonDlgBar.AddPanel(_T("Images"));
	CBCGPRibbonPaletteButton* pPaletteButton = new CBCGPRibbonPaletteButton(
		ID_IMAGES_GALLERY, _T("Images"), -1, 1, IDR_IMAGES,130);

	pPaletteButton->EnableMenuResize();
	pPaletteButton->SetStretchedOnDialogBar();
	pPaletteButton->SelectItem(-1);

	pPanelImages->Add(pPaletteButton);

	m_wndRibbonDlgBar.GetRibbon().RecalcLayout();

	return 0;
}


void CUserDlg::OnImagesGallery()
{
	// TODO: Add your command handler code here
	//CBCGPRibbonBar* pRibbon = ((CMainFrame*)GetTopLevelFrame())->GetRibbonBar();
	CBCGPRibbonBar* pRibbon = GetRibbonBar();
	ASSERT_VALID(pRibbon);

	CBCGPRibbonPaletteButton* pPaletteButton;
	if(!(pPaletteButton = DYNAMIC_DOWNCAST(
		CBCGPRibbonPaletteButton, pRibbon->FindByID(ID_IMAGES_GALLERY))))
	{
		MessageBox(_T("Error"));
		return;
	}

	BOOL success;
	int images = pPaletteButton->GetSelectedItem();
	
	switch (images)
	{
		case 0:
		{
			CBCGPDialog::OnOK();
			CLoginDlg dlg;
			dlg.DoModal();
			CString pass=dlg.get_PassWord();
			CString user=dlg.get_UserName();
			
			success = excelFile.OpenExcelFile(_T("D:\\man.xlsx"));
			success = excelFile.LoadSheet(1,true);
			int row=excelFile.GetRowCount();
			int col=excelFile.GetColumnCount();
			CString userIn,passIN,bossIN;
			BOOL bossBool=FALSE;
			for(int i=2;i<=row;i++)
			{
				userIn=excelFile.GetCellString(i,2);
				if(userIn==user)
				{
					passIN=excelFile.GetCellString(i,3);
					if(passIN==pass)
					{
						bossIN=excelFile.GetCellString(i,1);
						if (bossIN != _T("boss")) AfxMessageBox(_T("您没有权限访问"));
						else bossBool=TRUE;
						break;
					}
				}
			}
			excelFile.CloseExcelFile();
			
			if(bossBool==TRUE)
			{
				CBossDlg dlg;
				dlg.DoModal();
			}
			break;
		}		
		case 1:
		{
			CBCGPDialog::OnOK();
			CLoginDlg dlg;
			dlg.DoModal();
			CString pass=dlg.get_PassWord();
			CString user=dlg.get_UserName();
			
			success = excelFile.OpenExcelFile(_T("D:\\man.xlsx"));
			success = excelFile.LoadSheet(1,true);
			int row=excelFile.GetRowCount();
			int col=excelFile.GetColumnCount();
			CString userIn,passIN,bossIN;
			BOOL bossBool=FALSE;
			for(int i=2;i<=row;i++)
			{
				userIn=excelFile.GetCellString(i,2);
				if(userIn==user)
				{
					passIN=excelFile.GetCellString(i,3);
					if(passIN==pass)
					{
						bossIN=excelFile.GetCellString(i,1);
						if (bossIN != _T("boss")) AfxMessageBox(_T("您没有权限访问"));
						else bossBool=TRUE;
						break;
					}
				}
			}
			excelFile.CloseExcelFile();
			
			if(bossBool==TRUE)
			{
				CCaffeDlg dlg;
				dlg.DoModal();
			}
			break;
		}
		case 2:
		{
			CWnd::ShowWindow(SW_HIDE);
			
			CWnd::ShowWindow(SW_SHOW);
			break;
		}
		case 3:
		{
			CWnd::ShowWindow(SW_HIDE);
			
			CWnd::ShowWindow(SW_SHOW);
			break;
		}
	}
}
