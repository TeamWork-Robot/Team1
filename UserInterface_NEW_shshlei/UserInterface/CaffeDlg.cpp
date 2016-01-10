// CaffeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Test.h"
#include "CaffeDlg.h"

#include <windows.h>
#include <stdio.h>

#include "animate.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define IDC_KABUQINUOXIAO 1
#define IDC_KABUQINUODA   2
#define IDC_NATIEXIAO	  3
#define IDC_NATIEDA	      4
#define IDC_MOKAXIAO	  5
#define IDC_MOKADA	      6
#define IDC_LASHANXIAO	  7
#define IDC_LASHANDA	  8

#define IDC_SHATANG 	  9
#define IDC_FANGTANG 	  10
#define IDC_XIANNAI 	  11
#define IDC_NAIYOU  	  12

#define SmallCup          0   
#define BigCup          1 		
// CCaffeDlg dialog

CCaffeDlg::CCaffeDlg(CWnd* pParent /*=NULL*/)
	: CBCGPDialog(CCaffeDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	EnableVisualManagerStyle(TRUE, TRUE);
	time=_T("");
	
	for(int i=0;i<8;i++)
		caffe[i]=0;
	
	unitPrice[0]=30;
	unitPrice[1]=20;
	unitPrice[2]=25;
	unitPrice[3]=15;
	unitPrice[4]=30;
	unitPrice[5]=20;
	unitPrice[6]=30;
	unitPrice[7]=20;
	
	cup=SmallCup;
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<2;j++)
			joint[i][j]=0;
	}

}

void CCaffeDlg::DoDataExchange(CDataExchange* pDX)
{
	CBCGPDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CAFFE_TYPE_STATIC, m_caffeTypeLocation);
	DDX_Control(pDX, IDC_PEILIAO_STATIC, m_peiliaoLocation);
	//DDX_Control(pDX, IDC_CAFFE_LIST, m_caffeList);
}

BEGIN_MESSAGE_MAP(CCaffeDlg, CBCGPDialog)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_IMAGE_CAFFETYPE, OnClickHotSpotCaffeType)
	ON_BN_CLICKED(IDC_IMAGE_PEILIAO, OnClickHotSpotPeiliao)
	ON_BN_CLICKED(IDC_QUIT_BUTTON, &CCaffeDlg::OnBnClickedQuitButton)
	ON_BN_CLICKED(IDC_START_BUTTON, &CCaffeDlg::OnBnClickedStartButton)
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
	
	InitTime();

	InitImage();
	
	//InitCaffeList();
	//HBITMAP hBitmap;
	//hBitmap = LoadBitmap(AfxGetInstanceHandle(),);
	
	//((CStatic*)GetDlgItem(IDC_STATIC))->SetBitmap();
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCaffeDlg::InitTime()
{
	SYSTEMTIME sys;
	GetLocalTime(&sys);
		
	time.Format(_T("%d-%d-%d"),sys.wYear,sys.wMonth,sys.wDay);
	
}

void CCaffeDlg::InitImage()
{
	//咖啡类型及大小杯
	CRect rectLocation;
	m_caffeTypeLocation.GetWindowRect(&rectLocation);
	ScreenToClient(&rectLocation);

	m_ImageCaffeType.Create(rectLocation, this, IDC_IMAGE_CAFFETYPE);

	m_ImageCaffeType.SetImage(IDB_CAFFE_TYPE_BITMAP);
	m_ImageCaffeType.SetHighlightHotArea(82, 45);

	m_ImageCaffeType.AddHotSpot(IDC_NATIEDA, CRect(CPoint(153, 65), CSize(43, 32)));
	m_ImageCaffeType.AddHotSpot(IDC_NATIEXIAO, CRect(CPoint(160, 110), CSize(25, 25)));
	
	m_ImageCaffeType.AddHotSpot(IDC_MOKADA, CRect(CPoint(153, 178), CSize(43, 30)));
	m_ImageCaffeType.AddHotSpot(IDC_MOKAXIAO, CRect(CPoint(160, 218), CSize(25, 25)));
	
	m_ImageCaffeType.AddHotSpot(IDC_LASHANDA, CRect(CPoint(368, 65), CSize(46, 30)));
	m_ImageCaffeType.AddHotSpot(IDC_LASHANXIAO, CRect(CPoint(375, 110), CSize(30, 25)));
	
	m_ImageCaffeType.AddHotSpot(IDC_KABUQINUODA, CRect(CPoint(368, 178), CSize(46, 30)));
	m_ImageCaffeType.AddHotSpot(IDC_KABUQINUOXIAO, CRect(CPoint(375, 218), CSize(30, 25)));
	//咖啡配料
	m_peiliaoLocation.GetWindowRect(&rectLocation);
	ScreenToClient(&rectLocation);

	m_ImagePeiliao.Create(rectLocation, this, IDC_IMAGE_PEILIAO);

	m_ImagePeiliao.SetImage(IDB_PEILIAO_BITMAP);
	m_ImagePeiliao.SetHighlightHotArea(82, 45);

	m_ImagePeiliao.AddHotSpot(IDC_SHATANG, CRect(CPoint(90, 40), CSize(90, 100)));
	m_ImagePeiliao.AddHotSpot(IDC_FANGTANG, CRect(CPoint(90, 165), CSize(90, 100)));
	m_ImagePeiliao.AddHotSpot(IDC_XIANNAI, CRect(CPoint(270, 55), CSize(90, 100)));
	m_ImagePeiliao.AddHotSpot(IDC_NAIYOU, CRect(CPoint(270, 165), CSize(90, 100)));
	

}

void CCaffeDlg::OnClickHotSpotCaffeType()
{
	switch (m_ImageCaffeType.GetHotSpot())
	{
	case IDC_KABUQINUODA:
	{
		//MessageBox(_T("卡布奇诺大杯咖啡"));
		cup=BigCup;
		joint[0][0]=6.6613;
		joint[0][1]=280.287;
		
		joint[1][0]=65.8738;
		joint[1][1]=273.412;
		
		caffe[0]++;
		
		break;
	}
	case IDC_KABUQINUOXIAO:
	{
		//MessageBox(_T("卡布奇诺小杯咖啡"));
		cup=SmallCup;
		joint[0][0]=23.4266;
		joint[0][1]=352.338;
		
		joint[1][0]=65.8738;
		joint[1][1]=273.412;
		
		caffe[1]++;
		
		break;
	}
	case IDC_MOKADA:
	{
		//MessageBox(_T("魔卡大杯咖啡"));
		cup=BigCup;
		joint[0][0]=6.6613;
		joint[0][1]=280.287;
		
		joint[1][0]=68.6671;
		joint[1][1]=278.213;
		
		caffe[2]++;
		
		break; 
	}
	case IDC_MOKAXIAO:
	{
		//MessageBox(_T("爱尔兰小杯咖啡"));
		cup=SmallCup;
		joint[0][0]=23.4266;
		joint[0][1]=352.338;
		
		joint[1][0]=68.6671;
		joint[1][1]=278.213;
		
		caffe[3]++;
		
		break;
	}

	case IDC_NATIEDA:
	{
		//MessageBox(_T("拿铁大杯咖啡"));
		cup=BigCup;
		joint[0][0]=6.6613;
		joint[0][1]=280.287;
		
		joint[1][0]=70.2257;
		joint[1][1]=284.478;
		
		caffe[4]++;
		
		break;
	}

	case IDC_NATIEXIAO:
	{
		//MessageBox(_T("拿铁小杯咖啡"));
		cup=SmallCup;
		joint[0][0]=23.4266;
		joint[0][1]=352.338;
		
		joint[1][0]=70.2257;
		joint[1][1]=284.478;
		
		caffe[5]++;
		break;
	}
	
	case IDC_LASHANDA:
	{
		cup=BigCup;
		joint[0][0]=6.6613;
		joint[0][1]=280.287;
		
		joint[1][0]=70.442;
		joint[1][1]=292.393;
		
		caffe[6]++;
		break;
	}
	
	case IDC_LASHANXIAO:
	{
		cup=SmallCup;
		joint[0][0]=23.4266;
		joint[0][1]=352.338;
		
		joint[1][0]=70.442;
		joint[1][1]=292.393;
		
		caffe[7]++;
		break;
	}
	
	}
}

void CCaffeDlg::OnClickHotSpotPeiliao()
{
	switch (m_ImagePeiliao.GetHotSpot())
	{
		case IDC_SHATANG:
		
		joint[2][0]=46.4808;
		joint[2][1]=300.292;
		//MessageBox(_T("添加了砂糖"));
		break;
		
		case IDC_FANGTANG:
		
		joint[3][0]=47.9967;
		joint[3][1]=308.247;
		//MessageBox(_T("添加了方糖"));
		break;
		
		case IDC_XIANNAI:
		
		joint[4][0]=47.9148;
		joint[4][1]=316.568;
		//MessageBox(_T("添加了鲜奶"));
		break;
		
		case IDC_NAIYOU:
		
		joint[5][0]=45.334;
		joint[5][1]=328.997;
		//MessageBox(_T("添加了奶油"));
		break;
	
			
	}
}



void CCaffeDlg::OnBnClickedQuitButton()
{
	// TODO: Add your control notification handler code here
	BOOL success;
	success = excelFileSell.OpenExcelFile(_T("D:\\sell.xlsx"));
	if(success==FALSE) 
	{
		AfxMessageBox(_T("打开销售表失败"));
	}
	else
	{
		for(int j=1;j<=6;j++)
		{
			success = excelFileSell.LoadSheet(j,true);
			if(success==FALSE)
			{
				CString str;
				str.Format(_T("打开销售表sheet %d 失败"), j);
				AfxMessageBox(str);
			}				
			else
			{
				int row=excelFileSell.GetRowCount();
				if(row>=2)
				{
					CString currentTime=_T("");
					currentTime=excelFileSell.GetCellString(row,1);
					if(currentTime!=time)
					{
						excelFileSell.SetCellString(row+1,1,time);
						excelFileSell.SetCellInt(row+1,2,caffe[j-1]);
						excelFileSell.SetCellInt(row+1,3,unitPrice[j-1]*caffe[j-1]);
					}
					else
					{
						int cup=excelFileSell.GetCellInt(row,2);
						int price=excelFileSell.GetCellInt(row,3);
						excelFileSell.SetCellInt(row,2,cup+caffe[j-1]);
						excelFileSell.SetCellInt(row,3,price+unitPrice[j-1]*caffe[j-1]);
					}
					
				}
				
			}
		}
			
		excelFileSell.SaveasXSLFile(_T("D:\\sell.xlsx"));
		excelFileSell.CloseExcelFile();
		CBCGPDialog::OnOK();
	}
	
}

/*void CCaffeDlg::InitCaffeList()
{
	//CString str;
	
	CRect rect;
	m_caffeList.GetClientRect(&rect);
	m_caffeList.SetExtendedStyle(m_caffeList.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_caffeList.InsertColumn(0, _T("#"), LVCFMT_CENTER, rect.Width() / 9);
	m_caffeList.InsertColumn (1, _T("咖啡"), LVCFMT_CENTER, 	  4*rect.Width()/9);
	m_caffeList.InsertColumn(2, _T("配料"), LVCFMT_CENTER, 4 * rect.Width() / 9);
	
	/*if(row>=2)
	{
		for(int i=2;i<=row;i++)
		{
			str.Format(_T("%d"), i - 1);
			m_caffeList.InsertItem(i - 1, str);
			m_caffeList.SetItemData(i - 1, i - 1);
			for(int j=1;j<=col;j++)
			{
				str=excelFileEmployee.GetCellString(i,j);
			
				m_caffeList.SetItemText(i - 2, j, str);
			}
			
		}
	}*/
	
//}

float CCaffeDlg::GetJoint(int i,int j) const
{
	return joint[i][j];
}

void CCaffeDlg::OnBnClickedStartButton()
{
	// TODO: Add your control notification handler code here
	
    // Initialize glut and opengl
    //glutInit(&argc, argv);
	windowSize[0] = 600;
	windowSize[1] = 400;
    initGlut("Caffe Window");
  
    initGl();
	glutMainLoop();
}
