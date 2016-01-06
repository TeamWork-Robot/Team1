// CaffeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Test.h"
#include "CaffeDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define IDC_KABUQINUOXIAO 1
#define IDC_KABUQINUODA   2
#define IDC_NATIEXIAO	  3
#define IDC_NATIEDA	      4
#define IDC_AIERLANXIAO	  5
#define IDC_AIERLANDA	  6
#define IDC_BAITANG 	  7


// CCaffeDlg dialog

CCaffeDlg::CCaffeDlg(CWnd* pParent /*=NULL*/)
	: CBCGPDialog(CCaffeDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	EnableVisualManagerStyle(TRUE, TRUE);
}

void CCaffeDlg::DoDataExchange(CDataExchange* pDX)
{
	CBCGPDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CAFFE_TYPE_STATIC, m_caffeTypeLocation);
	DDX_Control(pDX, IDC_PEILIAO_STATIC, m_peiliaoLocation);
}

BEGIN_MESSAGE_MAP(CCaffeDlg, CBCGPDialog)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_IMAGE_CAFFETYPE, OnClickHotSpotCaffeType)
	ON_BN_CLICKED(IDC_IMAGE_PEILIAO, OnClickHotSpotPeiliao)
END_MESSAGE_MAP()


// CCaffeDlg message handlers

BOOL CCaffeDlg::OnInitDialog()
{
	CBCGPDialog::OnInitDialog();


	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	
	InitImage();
	HBITMAP hBitmap;
	//hBitmap = LoadBitmap(AfxGetInstanceHandle(),);
	
	//((CStatic*)GetDlgItem(IDC_STATIC))->SetBitmap();
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCaffeDlg::InitImage()
{
	//øß∑»¿‡–Õº∞¥Û–°±≠
	CRect rectLocation;
	m_caffeTypeLocation.GetWindowRect(&rectLocation);
	ScreenToClient(&rectLocation);

	m_ImageCaffeType.Create(rectLocation, this, IDC_IMAGE_CAFFETYPE);

	m_ImageCaffeType.SetImage(IDB_CAFFE_TYPE_BITMAP);
	m_ImageCaffeType.SetHighlightHotArea(82, 45);

	
	m_ImageCaffeType.AddHotSpot(IDC_AIERLANDA, CRect(CPoint(112, 28), CSize(42, 40)));
	m_ImageCaffeType.AddHotSpot(IDC_AIERLANXIAO, CRect(CPoint(115, 70), CSize(40, 30)));
	m_ImageCaffeType.AddHotSpot(IDC_NATIEDA, CRect(CPoint(115, 120), CSize(40, 45)));
	m_ImageCaffeType.AddHotSpot(IDC_NATIEXIAO, CRect(CPoint(115, 175), CSize(40, 30)));
	m_ImageCaffeType.AddHotSpot(IDC_KABUQINUODA, CRect(CPoint(280, 27), CSize(50, 40)));
	m_ImageCaffeType.AddHotSpot(IDC_KABUQINUOXIAO, CRect(CPoint(290, 70), CSize(40, 30)));
	
	//øß∑»≈‰¡œ
	m_peiliaoLocation.GetWindowRect(&rectLocation);
	ScreenToClient(&rectLocation);

	m_ImagePeiliao.Create(rectLocation, this, IDC_IMAGE_PEILIAO);

	m_ImagePeiliao.SetImage(IDB_PEILIAO_BITMAP);
	m_ImagePeiliao.SetHighlightHotArea(82, 45);

	
	m_ImagePeiliao.AddHotSpot(IDC_BAITANG, CRect(CPoint(20, 30), CSize(100, 83)));
	/*m_ImagePeiliao.AddHotSpot(IDC_AIERLANXIAO, CRect(CPoint(105, 70), CSize(40, 30)));
	m_ImagePeiliao.AddHotSpot(IDC_NATIEDA, CRect(CPoint(105,120), CSize(40, 45)));
	m_ImagePeiliao.AddHotSpot(IDC_NATIEXIAO, CRect(CPoint(105, 175), CSize(40, 30)));
	m_ImagePeiliao.AddHotSpot(IDC_KABUQINUODA, CRect(CPoint(250, 27), CSize(50, 40)));
	m_ImagePeiliao.AddHotSpot(IDC_KABUQINUOXIAO, CRect(CPoint(260, 70), CSize(40, 30)));*/

}

void CCaffeDlg::OnClickHotSpotCaffeType()
{
	switch (m_ImageCaffeType.GetHotSpot())
	{
	case IDC_AIERLANDA:
	{
		MessageBox(_T("∞Æ∂˚¿º¥Û±≠øß∑»"));
		
		break; 
	}
	case IDC_AIERLANXIAO:
	{
		MessageBox(_T("∞Æ∂˚¿º–°±≠øß∑»"));
		break;
	}

	case IDC_NATIEDA:
	{
		MessageBox(_T("ƒ√Ã˙¥Û±≠øß∑»"));

		break;
	}

	case IDC_NATIEXIAO:
	{
		MessageBox(_T("ƒ√Ã˙–°±≠øß∑»"));

		break;
	}
	case IDC_KABUQINUODA:
	{
		MessageBox(_T("ø®≤º∆Ê≈µ¥Û±≠øß∑»"));

		break;
	}
	case IDC_KABUQINUOXIAO:
	{
		MessageBox(_T("ø®≤º∆Ê≈µ–°±≠øß∑»"));

		break;
	}
	
		
	}
}

void CCaffeDlg::OnClickHotSpotPeiliao()
{
	switch (m_ImagePeiliao.GetHotSpot())
	{
	case IDC_BAITANG:
	{
		MessageBox(_T("ÃÌº”¡À∞◊Ã«"));
		break;
	}
	/*case IDC_AIERLANXIAO:
	{
		MessageBox(_T("∞Æ∂˚¿º–°±≠øß∑»"));
		break;
	}

	case IDC_NATIEDA:
	{
		MessageBox(_T("ƒ√Ã˙¥Û±≠øß∑»"));

		break;
	}

	case IDC_NATIEXIAO:
	{
		MessageBox(_T("ƒ√Ã˙–°±≠øß∑»"));

		break;
	}
	case IDC_KABUQINUODA:
	{
		MessageBox(_T("ø®≤º∆Ê≈µ¥Û±≠øß∑»"));

		break;
	}
	case IDC_KABUQINUOXIAO:
	{
		MessageBox(_T("ø®≤º∆Ê≈µ–°±≠øß∑»"));

		break;
	}*/
	
		
	}
}

