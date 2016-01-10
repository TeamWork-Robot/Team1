
// TeeChartDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Test.h"
#include "TuLunDlg.h"
#include "afxdialogex.h"
#include<math.h>

#pragma warning (disable:4018)
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define pi 3.1415926

// CTuLuntDlg 对话框

CTuLuntDlg::CTuLuntDlg(CWnd* pParent /*=NULL*/)
	: CBCGPDialog(CTuLuntDlg::IDD, pParent)
{
	//m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_gan = 80.0;
	m_gunZi = 5.0;
	m_huiCheng = 60.0;
	m_jinXiu = 240.0;
	m_jiYuan = 50.0;
	m_pianJu = 0.0;
	m_tuiCheng = 60.0;
	m_xingCheng = 50.0;
	m_yuanXiu = 0.0;
	m_zhongXin = 100.0;
	m_baiFu = 50.0;
	m_xuanZhuan = 0;
	m_tuiYaLi =0;
	m_yaLiJiao = 0;

	CBCGPVisualManager::SetDefaultManager(RUNTIME_CLASS(CBCGPVisualManager2010));

	// Enable Visual Manager style: 

	EnableVisualManagerStyle();

	//theApp.SetVisualTheme(CBCGPWinApp::BCGP_VISUAL_THEME_VS_2012_LIGHT);
	//SetBackgroundImage(IDB_BACK_BLUE);
}

void CTuLuntDlg::DoDataExchange(CDataExchange* pDX)
{
	CBCGPDialog::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_FANGXIANG_COMBO, m_fangXiang);
	DDX_Text(pDX, IDC_GAN_EDIT, m_gan);
	DDX_Text(pDX, IDC_GUNZI_EDIT, m_gunZi);
	DDX_Control(pDX, IDC_HUI_COMBO, m_hui);
	DDX_Text(pDX, IDC_HUI_EDIT, m_huiCheng);
	DDX_Text(pDX, IDC_JINXIU_EDIT, m_jinXiu);
	DDX_Text(pDX, IDC_JIYUAN_EDIT, m_jiYuan);
	DDX_Control(pDX, IDC_LEIXING_COMBO, m_leiXing);

	DDX_Text(pDX, IDC_PIANJU_EDIT, m_pianJu);
	DDX_Control(pDX, IDC_TUI_COMBO, m_tui);
	DDX_Text(pDX, IDC_TUI_EDIT, m_tuiCheng);
	DDX_Text(pDX, IDC_XINCHENG_EDIT, m_xingCheng);
	DDX_Text(pDX, IDC_YUANXIU_EDIT, m_yuanXiu);
	DDX_Text(pDX, IDC_ZHONGXIN_EDIT, m_zhongXin);
	DDX_Control(pDX, IDC_PIANJU_COMBO, m_pian);
	DDX_Text(pDX, IDC_BAIFU_EDIT, m_baiFu);
	DDX_Text(pDX, IDC_XUANZHUAN_EDIT, m_xuanZhuan);
	DDX_Text(pDX, IDC_TUIYALI_EDIT, m_tuiYaLi);
	DDX_Text(pDX, IDC_YALIJIAO_EDIT, m_yaLiJiao);
	DDX_Control(pDX, IDC_TCHART1, m_Chart);
}

BEGIN_MESSAGE_MAP(CTuLuntDlg, CBCGPDialog)
//	ON_WM_SYSCOMMAND()
//	ON_WM_PAINT()
//	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_LEIXING_COMBO, &CTuLuntDlg::OnSelchangeLeixingCombo)
	ON_EN_CHANGE(IDC_TUI_EDIT, &CTuLuntDlg::OnChangeTuiEdit)
	ON_EN_CHANGE(IDC_YUANXIU_EDIT, &CTuLuntDlg::OnChangeYuanxiuEdit)
	ON_EN_CHANGE(IDC_HUI_EDIT, &CTuLuntDlg::OnChangeHuiEdit)
	ON_EN_CHANGE(IDC_XINCHENG_EDIT, &CTuLuntDlg::OnChangeXinchengEdit)
	ON_EN_CHANGE(IDC_JIYUAN_EDIT, &CTuLuntDlg::OnChangeJiyuanEdit)
	ON_EN_CHANGE(IDC_PIANJU_EDIT, &CTuLuntDlg::OnChangePianjuEdit)
	ON_NOTIFY(UDN_DELTAPOS, IDC_BAIFU_SPIN, &CTuLuntDlg::OnDeltaposBaifuSpin)
	ON_NOTIFY(UDN_DELTAPOS, IDC_GAN_SPIN, &CTuLuntDlg::OnDeltaposGanSpin)
	ON_NOTIFY(UDN_DELTAPOS, IDC_GUNZI_SPIN, &CTuLuntDlg::OnDeltaposGunziSpin)
	ON_NOTIFY(UDN_DELTAPOS, IDC_HUI_SPIN, &CTuLuntDlg::OnDeltaposHuiSpin)
	ON_NOTIFY(UDN_DELTAPOS, IDC_JIYUAN_SPIN, &CTuLuntDlg::OnDeltaposJiyuanSpin)
	ON_NOTIFY(UDN_DELTAPOS, IDC_PIANJU_SPIN, &CTuLuntDlg::OnDeltaposPianjuSpin)
	ON_NOTIFY(UDN_DELTAPOS, IDC_TUI_SPIN, &CTuLuntDlg::OnDeltaposTuiSpin)
	ON_NOTIFY(UDN_DELTAPOS, IDC_YUANXIU__SPIN, &CTuLuntDlg::OnDeltaposYuanxiuSpin)
	ON_NOTIFY(UDN_DELTAPOS, IDC_ZHONGXIN_SPIN, &CTuLuntDlg::OnDeltaposZhongxinSpin)
	ON_NOTIFY(UDN_DELTAPOS, IDC_XINGCHENG_SPIN, &CTuLuntDlg::OnDeltaposXingchengSpin)
	ON_BN_CLICKED(IDC_LUNKUO_CHECK, &CTuLuntDlg::OnClickedLunkuoCheck)
	ON_BN_CLICKED(IDC_JIYUAN_CHECK, &CTuLuntDlg::OnClickedJiyuanCheck)
	ON_BN_CLICKED(IDC_NEIKUO_CHECK, &CTuLuntDlg::OnClickedNeikuoCheck)
	ON_BN_CLICKED(IDC_WAIKUO_CHECK, &CTuLuntDlg::OnClickedWaikuoCheck)
	ON_BN_CLICKED(IDC_SHIKUO_CHECK, &CTuLuntDlg::OnClickedShikuoCheck)
	ON_BN_CLICKED(IDC_ZHONGXIN_CHECK, &CTuLuntDlg::OnClickedZhongxinCheck)
	ON_BN_CLICKED(IDC_CONG_CHECK, &CTuLuntDlg::OnClickedCongCheck)
	ON_BN_CLICKED(IDC_ZANTING_BUTTON, &CTuLuntDlg::OnClickedZantingButton)
	ON_BN_CLICKED(IDC_XUANZHUAN_BUTTON, &CTuLuntDlg::OnClickedXuanzhuanButton)
	ON_WM_TIMER()
	ON_CBN_SELCHANGE(IDC_TUI_COMBO, &CTuLuntDlg::OnSelchangeTuiCombo)
	ON_CBN_SELCHANGE(IDC_HUI_COMBO, &CTuLuntDlg::OnSelchangeHuiCombo)
	ON_EN_CHANGE(IDC_GUNZI_EDIT, &CTuLuntDlg::OnChangeGunziEdit)
	ON_EN_CHANGE(IDC_ZHONGXIN_EDIT, &CTuLuntDlg::OnChangeZhongxinEdit)
	ON_EN_CHANGE(IDC_GAN_EDIT, &CTuLuntDlg::OnChangeGanEdit)
	ON_EN_CHANGE(IDC_BAIFU_EDIT, &CTuLuntDlg::OnChangeBaifuEdit)
	ON_NOTIFY(UDN_DELTAPOS, IDC_XUANZHUAJIAO_SPIN, &CTuLuntDlg::OnDeltaposXuanzhuajiaoSpin)
	ON_CBN_SELCHANGE(IDC_FANGXIANG_COMBO, &CTuLuntDlg::OnCbnSelchangeFangxiangCombo)
	ON_EN_CHANGE(IDC_XUANZHUAN_EDIT, &CTuLuntDlg::OnChangeXuanzhuanEdit)
	ON_BN_CLICKED(IDC_FUWEI_BUTTON, &CTuLuntDlg::OnBnClickedFuweiButton)
END_MESSAGE_MAP()


// CTuLuntDlg 消息处理程序

BOOL CTuLuntDlg::OnInitDialog()
{
	CBCGPDialog::OnInitDialog();	

	// TODO: 在此添加额外的初始化代码
	UpdateData(TRUE);
	Init_Data();
	UpdateData(FALSE);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CTuLuntDlg::canShu()
{	
	UpdateData(TRUE);
	m_huiChengJiao=m_huiCheng;	
	m_jiYuanBj=m_jiYuan;
	m_pianJ=pianZuoYou*m_pianJu;
	m_tuiChengJiao=m_tuiCheng;
	m_zhongXinJ=m_zhongXin;
	m_ganC=m_gan;
	m_gunZ=m_gunZi;
	m_xuanZhuJ=m_xuanZhuan;
	m_yuanXiuJiao=m_yuanXiu;
	m_yaLiJ=m_yaLiJiao;
	m_tuiYaLiJ=m_tuiYaLi;
	m_jinXiuJiao=360-m_tuiChengJiao-m_yuanXiuJiao-m_huiChengJiao;
	SetDlgItemInt(IDC_JINXIU_EDIT,m_jinXiuJiao,1);
	int mIndex1;
	mIndex1=m_leiXing.GetCurSel();
	switch(mIndex1)
	{			
		case 2:
			m_xingBai=m_baiFu;
			m_s0=acos((m_zhongXinJ*m_zhongXinJ+m_ganC*m_ganC-m_jiYuanBj*m_jiYuanBj)/2/m_zhongXinJ/m_ganC);
			break;
		case 0:case 1:case 3:
			m_xingBai=m_xingCheng;
			m_s0=sqrt(m_jiYuanBj*m_jiYuanBj-m_pianJ*m_pianJ);
	}
}

void CTuLuntDlg::dianShuJu()
{	
	canShu();
	long i(0);	
	int mIndex,mIndex1;	
	mIndex=m_tui.GetCurSel();
	switch(mIndex)
	{ 
		case 0:for (i=0;i<m_tuiChengJiao/2;i++)
				{
						s[i]=2*m_xingBai*i*i/m_tuiChengJiao/m_tuiChengJiao;
						ss[i]=4*m_xingBai*i/m_tuiChengJiao/m_tuiChengJiao;
						sss[i]=4*m_xingBai/m_tuiChengJiao/m_tuiChengJiao;
				}
				for (i=m_tuiChengJiao/2;i<m_tuiChengJiao;i++)
				{
						s[i]=m_xingBai-2*m_xingBai*(m_tuiChengJiao-i)*(m_tuiChengJiao-i)/m_tuiChengJiao/m_tuiChengJiao;
						ss[i]=4*m_xingBai*(m_tuiChengJiao-i)/m_tuiChengJiao/m_tuiChengJiao;
						sss[i]=-4*m_xingBai/m_tuiChengJiao/m_tuiChengJiao;
				} break;
		case 1:for (i=0;i<m_tuiChengJiao;i++)
				{
						s[i]=m_xingBai*i/m_tuiChengJiao;
						ss[i]=m_xingBai/m_tuiChengJiao;
						sss[i]=0;
				}break;
		case 2:for (i=0;i<m_tuiChengJiao;i++)
				{
						s[i]=m_xingBai*(1-cos(pi*i/m_tuiChengJiao))/2;
						ss[i]=pi*m_xingBai*sin(pi*i/m_tuiChengJiao)/m_tuiChengJiao/2;
						sss[i]=pi*pi*m_xingBai*cos(pi*i/m_tuiChengJiao)/m_tuiChengJiao/m_tuiChengJiao/2;
				}break;
		case 3:for (i=0;i<m_tuiChengJiao;i++)
				{
						s[i]=m_xingBai*(i/m_tuiChengJiao-sin(2*pi*i/m_tuiChengJiao)/2/pi);
						ss[i]=m_xingBai*(1-cos(2*pi*i/m_tuiChengJiao))/m_tuiChengJiao;
						sss[i]=2*pi*m_xingBai*sin(2*pi*i/m_tuiChengJiao)/m_tuiChengJiao/m_tuiChengJiao;
				}break;
	}
	for (i=m_tuiChengJiao;i<m_tuiChengJiao+m_yuanXiuJiao;i++)
	{
		s[i]=m_xingBai;
		ss[i]=0;
		sss[i]=0;
	}	
	mIndex=m_hui.GetCurSel();	
	switch(mIndex)
	{
		case 0:for (i=m_tuiChengJiao+m_yuanXiuJiao;i<m_tuiChengJiao+m_yuanXiuJiao+m_huiChengJiao/2;i++)
				{
						s[i]=m_xingBai-2*m_xingBai*(i-m_tuiChengJiao-m_yuanXiuJiao)*(i-m_tuiChengJiao-m_yuanXiuJiao)/m_huiChengJiao/m_huiChengJiao;
						ss[i]=-4*m_xingBai*(i-m_tuiChengJiao-m_yuanXiuJiao)/m_huiChengJiao/m_huiChengJiao;
						sss[i]=-4*m_xingBai/m_huiChengJiao/m_huiChengJiao;
				}
				for (i=m_tuiChengJiao+m_yuanXiuJiao+m_huiChengJiao/2;i<m_tuiChengJiao+m_yuanXiuJiao+m_huiChengJiao;i++)
				{
						s[i]=2*m_xingBai*(m_huiChengJiao-(i-m_tuiChengJiao-m_yuanXiuJiao))*(m_huiChengJiao-(i-m_tuiChengJiao-m_yuanXiuJiao))/m_huiChengJiao/m_huiChengJiao;
						ss[i]=-4*m_xingBai*(m_huiChengJiao-(i-m_tuiChengJiao-m_yuanXiuJiao))/m_huiChengJiao/m_huiChengJiao;
						sss[i]=4*m_xingBai/m_huiChengJiao/m_huiChengJiao;
				} break;
		case 1:for (i=m_tuiChengJiao+m_yuanXiuJiao;i<(unsigned)m_tuiChengJiao+m_yuanXiuJiao+m_huiChengJiao;i++)
				{
						s[i]=m_xingBai*(1-(i-m_tuiChengJiao-m_yuanXiuJiao)/m_huiChengJiao);
						ss[i]=-m_xingBai/m_huiChengJiao;
						sss[i]=0;
				} break;
		case 2:for (i=m_tuiChengJiao+m_yuanXiuJiao;i<(unsigned)m_tuiChengJiao+m_yuanXiuJiao+m_huiChengJiao;i++)
				{
						s[i]=m_xingBai*(1+cos(pi*(i-m_tuiChengJiao-m_yuanXiuJiao)/m_huiChengJiao))/2;
						ss[i]=-pi*m_xingBai*sin(pi*(i-m_tuiChengJiao-m_yuanXiuJiao)/m_huiChengJiao)/m_huiChengJiao/2;
						sss[i]=-pi*pi*m_xingBai*cos(pi*(i-m_tuiChengJiao-m_yuanXiuJiao)/m_huiChengJiao)/m_huiChengJiao/m_huiChengJiao/2;
				}break;                                        
		case 3:for (i=m_tuiChengJiao+m_yuanXiuJiao;i<(unsigned)m_tuiChengJiao+m_yuanXiuJiao+m_huiChengJiao;i++)
				{
						s[i]=m_xingBai*(1-(i-m_tuiChengJiao-m_yuanXiuJiao)/m_huiChengJiao+sin(2*pi*(i-m_tuiChengJiao-m_yuanXiuJiao)/m_huiChengJiao)/2/pi);
						ss[i]=m_xingBai*(-1+cos(2*pi*(i-m_tuiChengJiao-m_yuanXiuJiao)/m_huiChengJiao))/m_huiChengJiao;
						sss[i]=-2*pi*m_xingBai*sin(2*pi*(i-m_tuiChengJiao-m_yuanXiuJiao)/m_huiChengJiao)/m_huiChengJiao/m_huiChengJiao;
				}break;
	}
	for (i=m_tuiChengJiao+m_yuanXiuJiao+m_huiChengJiao;i<(unsigned)360;i++)
	{
		s[i]=0;
		ss[i]=0;
		sss[i]=0;
	}
	mIndex1=m_leiXing.GetCurSel();
	//fangxiang=1;
	for (i=0;i<(unsigned)360;i++)
	 {
		 switch(mIndex1)
		{			
			case 2:
				m_valX[i]=m_zhongXinJ*fangxiang*sin(i*pi/180)+m_ganC*sin(m_s0+(s[i]-i*fangxiang)*pi/180);
				m_valY[i]=m_zhongXinJ*cos(i*pi/180)-m_ganC*cos(m_s0+(s[i]-i*fangxiang)*pi/180);
			break;
			case 0:case 1:
				m_valX[i]=m_pianJ*cos(i*pi/180)+(m_s0+s[i])*fangxiang*sin(i*pi/180);
				m_valY[i] =-m_pianJ*fangxiang*sin(i*pi/180)+(m_s0+s[i])*cos(i*pi/180);
			break;
			case 3:
				m_valX[i]=ss[i]*cos(i*pi/180)+(m_jiYuanBj+s[i])*fangxiang*sin(i*pi/180);
				m_valY[i]=-ss[i]*fangxiang*sin(i*pi/180)+(m_jiYuanBj+s[i])*cos(i*pi/180);
			break;
		 }
	 }
	xieLv();
	for (i=0;i<(unsigned)360;i++)
	{
		m_valX1[i]=m_valX[i]-m_gunZ*cos(m_theta[i]);
		m_valY1[i]=m_valY[i]-m_gunZ*sin(m_theta[i]);
		m_valX2[i]=m_valX[i]+m_gunZ*cos(m_theta[i]);
		m_valY2[i]=m_valY[i]+m_gunZ*sin(m_theta[i]);
	}
	yaLiJiao();
}

void CTuLuntDlg::putDian()
{
	for(long i=0;i<360;i++)
	{
		XValues.PutElement(&i, &m_valX[i]);
		YValues.PutElement(&i, &m_valY[i]);
		XValues1.PutElement(&i, &m_valX1[i]);
		YValues1.PutElement(&i, &m_valY1[i]);
		XValues2.PutElement(&i, &m_valX2[i]);
		YValues2.PutElement(&i, &m_valY2[i]);
	}
}

void CTuLuntDlg::xieLv()
{
	double dX[360],dY[360];
	long i(0);
	int mIndex1;
	mIndex1=m_leiXing.GetCurSel();
	switch(mIndex1)
	{			
		case 2:
			for(i=0;i<360;i++)
			{
				dX[i]=m_zhongXinJ*cos(i*pi/180)-m_ganC*cos(m_s0+(s[i]-i)*pi/180)+m_ganC*cos(m_s0+(s[i]-i)*pi/180)*ss[i];
				dY[i]=-m_zhongXinJ*sin(i*pi/180)-m_ganC*sin(m_s0+(s[i]-i)*pi/180)+m_ganC*sin(m_s0+(s[i]-i)*pi/180)*ss[i];
			}
			break;
		case 0:case 1:
			for(i=0;i<360;i++)
			{
				dX[i]=-m_pianJ*sin(i*pi/180)+(m_s0+s[i])*cos(i*pi/180)+ss[i]*sin(i*pi/180);
				dY[i]=-m_pianJ*cos(i*pi/180)-(m_s0+s[i])*sin(i*pi/180)+ss[i]*cos(i*pi/180);
			}
			break;
		case 3:
			for(i=0;i<360;i++)
			{
				dX[i]=sss[i]*cos(i*pi/180)+(m_jiYuanBj+s[i])*cos(i*pi/180);
				dY[i]=-sss[i]*sin(i*pi/180)-(m_jiYuanBj+s[i])*sin(i*pi/180);
			}
			break;
	}
	for(i=0;i<360;i++)
	{
		
		if ((-dX[i]/dY[i])>0)
		{
		   if (m_valX[i]>0)
				m_theta[i]=atan(-dX[i]/dY[i]);
		   else
				m_theta[i]=atan(-dX[i]/dY[i])+pi;
		}
		 else
		 {
			   if (m_valX[i]>0)
				   m_theta[i]=atan(-dX[i]/dY[i])+2*pi;   
			   else
					m_theta[i]=atan(-dX[i]/dY[i])+pi;
		}
	}
}

void CTuLuntDlg::yaLiJiao()
{
	double temp;
	long i(0);
	CString str(_T(""));
	int mindex;
	mindex=m_leiXing.GetCurSel();
	m_tuiYaLiJ=m_yaLiJ=0;
	switch(mindex)
	{
	case 2:
		for(i=0;i<=(unsigned)m_tuiChengJiao;i++)
		{
			temp=atan(m_ganC*(abs(ss[i])+1)/(m_zhongXinJ*sin(m_s0+i*pi/180))-1/tan(m_s0+i*pi/180))*180/pi;
			if(temp>m_tuiYaLiJ) m_tuiYaLiJ=temp;
		}
		for(i=0;i<360;i++)
		{
			temp=atan(m_ganC*(abs(ss[i])+1)/(m_zhongXinJ*sin(m_s0+i*pi/180))-1/tan(m_s0+i*pi/180))*180/pi;
			if(temp>m_yaLiJ) m_yaLiJ=temp;
		}
		break;
	case 1:case 0:
		for(i=0;i<=(unsigned)m_tuiChengJiao;i++)
		{
			temp=atan((ss[i]-m_pianJ)/(m_s0+s[i]))*180/pi;
			if(temp>m_tuiYaLiJ) m_tuiYaLiJ=temp;
		}
		for(i=0;i<360;i++)
		{
			temp=atan((ss[i]-m_pianJ)/(m_s0+s[i]))*180/pi;
			if(temp>m_yaLiJ) m_yaLiJ=temp;
		}
		break;
	case 3:
			m_tuiYaLiJ=0;
			m_yaLiJ=0;
			break;
	}
	UpdateData(TRUE);
	str.Format(_T("%.4f"),m_tuiYaLiJ);
	SetDlgItemText(IDC_TUIYALI_EDIT,str);
	str.Format(_T("%.4f"),m_yaLiJ);
	SetDlgItemText(IDC_YALIJIAO_EDIT,str);
}

void CTuLuntDlg::drawLunKuo()
{
	putDian();
	CSeries ChartSpeed = (CSeries)m_Chart.Series(0);
	UpdateData(TRUE);	
	ChartSpeed.Clear();
	ChartSpeed.AddArray(360,YValues,XValues);
	UpdateData(FALSE);	
}

void CTuLuntDlg::drawJiYuan()
{
	UpdateData(TRUE);	
	m_jiYuanBj=m_jiYuan;	
	CSeries ChartSpeed = (CSeries)m_Chart.Series(1);
	CString str(_T(""));
	long i(0);
	double val[360];
	COleSafeArray XValues1;    
	COleSafeArray YValues1;
	DWORD pNumElements[] = {360};
	XValues1.Create(VT_R8, 1, pNumElements);    
	YValues1.Create(VT_R8, 1, pNumElements);
	for (i=0;i<(unsigned)360;i++)
	{
		val[i]=m_jiYuanBj*sin(i*pi/180);
		XValues1.PutElement(&i, &val[i]);
		val[i] = m_jiYuanBj*cos(i*pi/180);
		YValues1.PutElement(&i, &val[i]);
	}
	//由于需要计算时间，画图就不在第一个for循环里实现了
	ChartSpeed.Clear();
	ChartSpeed.AddArray(360,YValues1,XValues1);
	UpdateData(FALSE);	
}

void CTuLuntDlg::drawNeiWaiKuo()
{
	CWnd *pEditFile = NULL;	
	pEditFile     =GetDlgItem(IDC_NEIKUO_CHECK); 
	if(pEditFile->IsWindowEnabled()==TRUE&&BST_CHECKED==((CButton*)GetDlgItem(IDC_NEIKUO_CHECK))->GetCheck())  drawNeiKuo();
	pEditFile     =GetDlgItem(IDC_WAIKUO_CHECK);
	if(pEditFile->IsWindowEnabled()==TRUE&&BST_CHECKED==((CButton*)GetDlgItem(IDC_WAIKUO_CHECK))->GetCheck())  drawWaiKuo();

}

void CTuLuntDlg::drawNeiKuo()
{
	CSeries ChartSpeed = (CSeries)m_Chart.Series(2);
	UpdateData(TRUE);
	//putDian();
	//由于需要计算时间，画图就不在第一个for循环里实现了
	ChartSpeed.Clear();
	ChartSpeed.AddArray(360,YValues1,XValues1);
	UpdateData(FALSE);	
}

void CTuLuntDlg::drawWaiKuo()
{
	CSeries ChartSpeed = (CSeries)m_Chart.Series(3);
	UpdateData(TRUE);
	//putDian();
	//由于需要计算时间，画图就不在第一个for循环里实现了
	ChartSpeed.Clear();
	ChartSpeed.AddArray(360,YValues2,XValues2);
	UpdateData(FALSE);	
}

void CTuLuntDlg::drawHuiZhZhXin()
{
	drawHuiZhZhXin1();
	CSeries ChartSpeed = (CSeries)m_Chart.Series(4);
	UpdateData(TRUE);
	CString str(_T(""));
	long i(0);
	double val1[360];
	COleSafeArray XValues1;    
	COleSafeArray YValues1;
	DWORD pNumElements[] = {360};
	XValues1.Create(VT_R8, 1, pNumElements);    
	YValues1.Create(VT_R8, 1, pNumElements);
	for(i=0;i<360;i++)
	{
		val1[i]=4*cos(i*pi/180);
		XValues1.PutElement(&i, &val1[i]);
		val1[i]=4*sin(i*pi/180);
		YValues1.PutElement(&i, &val1[i]);
	}
	//由于需要计算时间，画图就不在第一个for循环里实现了
	ChartSpeed.Clear();
	ChartSpeed.AddArray(360,YValues1,XValues1);
	UpdateData(FALSE);	
}

void CTuLuntDlg::drawHuiZhZhXin1()
{
	CSeries ChartSpeed = (CSeries)m_Chart.Series(5);
	UpdateData(TRUE);
	CString str(_T(""));
	long i(0);
	double val1[9];
	COleSafeArray XValues1;    
	COleSafeArray YValues1;
	DWORD pNumElements[] = {9};
	XValues1.Create(VT_R8, 1, pNumElements);    
	YValues1.Create(VT_R8, 1, pNumElements);
	
	val1[0]=-8;val1[1]=-4;
	val1[2]=-8;val1[3]=0;
	val1[4]=4;val1[5]=0;
	val1[6]=4;val1[7]=8;
	val1[8]=-8;
	for(i=0;i<9;i++)
	{
		XValues1.PutElement(&i, &val1[i]);
	}
	val1[0]=-7;val1[1]=-7;
	val1[2]=-11;val1[3]=-3;
	val1[4]=-7;val1[5]=-11;
	val1[6]=-7;val1[7]=-7;
	val1[8]=-7;
	for(i=0;i<9;i++)
	{
		YValues1.PutElement(&i, &val1[i]);
	}
	//由于需要计算时间，画图就不在第一个for循环里实现了
	ChartSpeed.Clear();
	ChartSpeed.AddArray(9,YValues1,XValues1);
	UpdateData(FALSE);	
}

void CTuLuntDlg::drawConDonYi()
{
	canShu();
	drawConDonYi1();
	CSeries ChartSpeed = (CSeries)m_Chart.Series(6);
	UpdateData(TRUE);
	CString str(_T(""));
	long i(0);
	double val1[2];
	COleSafeArray XValues1;    
	COleSafeArray YValues1;
	DWORD pNumElements[] = {2};
	XValues1.Create(VT_R8, 1, pNumElements);    
	YValues1.Create(VT_R8, 1, pNumElements);

	val1[0]=m_pianJ;
	val1[1]=m_pianJ;
	for(i=0;i<2;i++)
	{
		XValues1.PutElement(&i, &val1[i]);
	}
	val1[0]=m_s0+s[m_xuanZhuJ];
	val1[1]=m_s0+40+s[m_xuanZhuJ];
	for(i=0;i<2;i++)
	{
		YValues1.PutElement(&i, &val1[i]);
	}
	//由于需要计算时间，画图就不在第一个for循环里实现了
	ChartSpeed.Clear();
	ChartSpeed.AddArray(2,YValues1,XValues1);
	UpdateData(FALSE);	
}

void CTuLuntDlg::drawConDonYi1()
{
	canShu();
	CSeries ChartSpeed = (CSeries)m_Chart.Series(7);
	UpdateData(TRUE);
	CString str(_T(""));
	long i(0);
	double val1[8];
	COleSafeArray XValues1;    
	COleSafeArray YValues1;
	DWORD pNumElements[] = {8};
	XValues1.Create(VT_R8, 1, pNumElements);    
	YValues1.Create(VT_R8, 1, pNumElements);
	
	val1[0]=m_pianJ-3;val1[1]=m_pianJ-3;
	val1[2]=m_pianJ-6;val1[3]=m_pianJ-3;
	val1[4]=m_pianJ-3;val1[5]=m_pianJ-6;
	val1[6]=m_pianJ-3;val1[7]=m_pianJ-3;
	for(i=0;i<8;i++)
	{
		XValues1.PutElement(&i, &val1[i]);
	}
	val1[0]=m_s0+35;val1[1]=m_s0+29;
	val1[2]=m_s0+32;val1[3]=m_s0+29;
	val1[4]=m_s0+23;val1[5]=m_s0+26;
	val1[6]=m_s0+23;val1[7]=m_s0+17;
	for(i=0;i<8;i++)
	{
		YValues1.PutElement(&i, &val1[i]);
	}
	//由于需要计算时间，画图就不在第一个for循环里实现了
	ChartSpeed.Clear();
	ChartSpeed.AddArray(8,YValues1,XValues1);
	UpdateData(FALSE);
}

void CTuLuntDlg::drawConDonYi2()
{
	canShu();
	CSeries ChartSpeed = (CSeries)m_Chart.Series(8);
	UpdateData(TRUE);
	CString str(_T(""));
	long i(0);
	double val1[720];
	COleSafeArray XValues1;    
	COleSafeArray YValues1;
	DWORD pNumElements[] = {720};
	XValues1.Create(VT_R8, 1, pNumElements);    
	YValues1.Create(VT_R8, 1, pNumElements);

	for(i=0;i<360;i++)
	{
		val1[i]=m_pianJ+m_gunZ*cos(i*pi/180);
		XValues1.PutElement(&i, &val1[i]);
		val1[i]=m_s0+s[m_xuanZhuJ]+m_gunZ*sin(i*pi/180);
		YValues1.PutElement(&i, &val1[i]);
	}
	for(i=360;i<720;i++)
	{
		val1[i]=m_pianJ+0.4*m_gunZ*cos(i*pi/180);
		XValues1.PutElement(&i, &val1[i]);
		val1[i]=m_s0+s[m_xuanZhuJ]+0.4*m_gunZ*sin(i*pi/180);
		YValues1.PutElement(&i, &val1[i]);
	}
	//由于需要计算时间，画图就不在第一个for循环里实现了
	ChartSpeed.Clear();
	ChartSpeed.AddArray(720,YValues1,XValues1);
	UpdateData(FALSE);
}

void CTuLuntDlg::drawConDonBai()
{
	canShu();
	drawConDonBai1();
	drawConDonBai2();
	CSeries ChartSpeed = (CSeries)m_Chart.Series(9);
	UpdateData(TRUE);
	CString str(_T(""));
	long i(0);
	double val1[2];
	COleSafeArray XValues1;    
	COleSafeArray YValues1;
	DWORD pNumElements[] = {2};
	XValues1.Create(VT_R8, 1, pNumElements);    
	YValues1.Create(VT_R8, 1, pNumElements);
	
	val1[0]=0;
	val1[1]=m_ganC*sin(m_s0+s[m_xuanZhuJ]*pi/180);
	
	for(i=0;i<2;i++)
	{
		XValues1.PutElement(&i, &val1[i]);
	}
	val1[0]=m_zhongXinJ;
	val1[1]=m_zhongXinJ-m_ganC*cos(m_s0+s[m_xuanZhuJ]*pi/180);
	
	for(i=0;i<2;i++)
	{
		YValues1.PutElement(&i, &val1[i]);
	}
	//由于需要计算时间，画图就不在第一个for循环里实现了
	ChartSpeed.Clear();
	ChartSpeed.AddArray(2,YValues1,XValues1);
	UpdateData(FALSE);
}

void CTuLuntDlg::drawConDonBai1()
{
	canShu();
	CSeries ChartSpeed = (CSeries)m_Chart.Series(10);
	UpdateData(TRUE);
	CString str(_T(""));
	long i(0);
	double val1[9];
	COleSafeArray XValues1;    
	COleSafeArray YValues1;
	DWORD pNumElements[] = {9};
	XValues1.Create(VT_R8, 1, pNumElements);    
	YValues1.Create(VT_R8, 1, pNumElements);
	
	val1[0]=-8;val1[1]=-4;
	val1[2]=-8;val1[3]=0;
	val1[4]=4;val1[5]=0;
	val1[6]=4;val1[7]=8;
	val1[8]=-8;
	for(i=0;i<9;i++)
	{
		XValues1.PutElement(&i, &val1[i]);
	}
	val1[0]=-7+m_zhongXinJ;val1[1]=-7+m_zhongXinJ;
	val1[2]=-11+m_zhongXinJ;val1[3]=-3+m_zhongXinJ;
	val1[4]=-7+m_zhongXinJ;val1[5]=-11+m_zhongXinJ;
	val1[6]=-7+m_zhongXinJ;val1[7]=-7+m_zhongXinJ;
	val1[8]=-7+m_zhongXinJ;
	for(i=0;i<9;i++)
	{
		YValues1.PutElement(&i, &val1[i]);
	}
	//由于需要计算时间，画图就不在第一个for循环里实现了
	ChartSpeed.Clear();
	ChartSpeed.AddArray(9,YValues1,XValues1);
	UpdateData(FALSE);
}

void CTuLuntDlg::drawConDonBai2()
{
	canShu();
	CSeries ChartSpeed = (CSeries)m_Chart.Series(11);
	UpdateData(TRUE);
	CString str(_T(""));
	long i(0);
	double val1[360];
	COleSafeArray XValues1;    
	COleSafeArray YValues1;
	DWORD pNumElements[] = {360};
	XValues1.Create(VT_R8, 1, pNumElements);    
	YValues1.Create(VT_R8, 1, pNumElements);
	for(i=0;i<360;i++)
	{
		val1[i]=4*cos(i*pi/180);
		XValues1.PutElement(&i, &val1[i]);
		val1[i]=m_zhongXinJ+4*sin(i*pi/180);
		YValues1.PutElement(&i, &val1[i]);
	}
	//由于需要计算时间，画图就不在第一个for循环里实现了
	ChartSpeed.Clear();
	ChartSpeed.AddArray(360,YValues1,XValues1);
	UpdateData(FALSE);
}

void CTuLuntDlg::drawConDonBai3()
{
	canShu();
	CSeries ChartSpeed = (CSeries)m_Chart.Series(12);
	UpdateData(TRUE);
	CString str(_T(""));
	long i(0);
	double val1[720];
	COleSafeArray XValues1;    
	COleSafeArray YValues1;
	DWORD pNumElements[] = {720};
	XValues1.Create(VT_R8, 1, pNumElements);    
	YValues1.Create(VT_R8, 1, pNumElements);

	for(i=0;i<360;i++)
	{
		val1[i]=m_ganC*sin(m_s0+s[m_xuanZhuJ]*pi/180)+m_gunZ*cos(i*pi/180);
		XValues1.PutElement(&i, &val1[i]);
		val1[i]=m_zhongXinJ-m_ganC*cos(m_s0+s[m_xuanZhuJ]*pi/180)+m_gunZ*sin(i*pi/180);
		YValues1.PutElement(&i, &val1[i]);
	}
	for(i=360;i<720;i++)
	{
		val1[i]=m_ganC*sin(m_s0+s[m_xuanZhuJ]*pi/180)+0.4*m_gunZ*cos(i*pi/180);
		XValues1.PutElement(&i, &val1[i]);
		val1[i]=m_zhongXinJ-m_ganC*cos(m_s0+s[m_xuanZhuJ]*pi/180)+0.4*m_gunZ*sin(i*pi/180);
		YValues1.PutElement(&i, &val1[i]);
	}
	//由于需要计算时间，画图就不在第一个for循环里实现了
	ChartSpeed.Clear();
	ChartSpeed.AddArray(720,YValues1,XValues1);
	UpdateData(FALSE);
}

void CTuLuntDlg::drawConDonPinDi()
{
	canShu();
	drawConDonPinDi1();
	CSeries ChartSpeed = (CSeries)m_Chart.Series(13);
	UpdateData(TRUE);
	CString str(_T(""));
	long i(0);
	double val1[4];
	COleSafeArray XValues1;    
	COleSafeArray YValues1;
	DWORD pNumElements[] = {4};
	XValues1.Create(VT_R8, 1, pNumElements);    
	YValues1.Create(VT_R8, 1, pNumElements);
	
	val1[0]=-m_jiYuanBj-5+m_pianJ;val1[1]=m_jiYuanBj+5+m_pianJ;
	val1[2]=m_pianJ;val1[3]=m_pianJ;
	for(i=0;i<4;i++)
	{
		XValues1.PutElement(&i, &val1[i]);
	}
	val1[0]=m_jiYuanBj+s[m_xuanZhuJ];val1[1]=m_jiYuanBj+s[m_xuanZhuJ];
	val1[2]=m_jiYuanBj+s[m_xuanZhuJ];val1[3]=m_jiYuanBj+s[m_xuanZhuJ]+40;
	
	for(i=0;i<4;i++)
	{
		YValues1.PutElement(&i, &val1[i]);
	}
	//由于需要计算时间，画图就不在第一个for循环里实现了
	ChartSpeed.Clear();
	ChartSpeed.AddArray(4,YValues1,XValues1);
	UpdateData(FALSE);
}

void CTuLuntDlg::drawConDonPinDi1()
{
	canShu();
	CSeries ChartSpeed = (CSeries)m_Chart.Series(14);
	UpdateData(TRUE);
	CString str(_T(""));
	long i(0);
	double val1[8];
	COleSafeArray XValues1;    
	COleSafeArray YValues1;
	DWORD pNumElements[] = {8};
	XValues1.Create(VT_R8, 1, pNumElements);    
	YValues1.Create(VT_R8, 1, pNumElements);
	
	val1[0]=-3+m_pianJ;val1[1]=-3+m_pianJ;
	val1[2]=-6+m_pianJ;val1[3]=-3+m_pianJ;
	val1[4]=-3+m_pianJ;val1[5]=-6+m_pianJ;
	val1[6]=-3+m_pianJ;val1[7]=-3+m_pianJ;
	for(i=0;i<8;i++)
	{
		XValues1.PutElement(&i, &val1[i]);
	}
	val1[0]=m_jiYuanBj+35;val1[1]=m_jiYuanBj+29;
	val1[2]=m_jiYuanBj+32;val1[3]=m_jiYuanBj+29;
	val1[4]=m_jiYuanBj+23;val1[5]=m_jiYuanBj+26;
	val1[6]=m_jiYuanBj+23;val1[7]=m_jiYuanBj+17;
	for(i=0;i<8;i++)
	{
		YValues1.PutElement(&i, &val1[i]);
	}
	//由于需要计算时间，画图就不在第一个for循环里实现了
	ChartSpeed.Clear();
	ChartSpeed.AddArray(8,YValues1,XValues1);
	UpdateData(FALSE);
}

void CTuLuntDlg::clearAllConDon()
{
	UpdateData(TRUE);
	for(int i=6;i<15;i++)
		{
			CSeries ChartSpeed = (CSeries)m_Chart.Series(i);
			ChartSpeed.Clear();
		}
	UpdateData(FALSE);
}

void CTuLuntDlg::clearNeiWai()
{
	UpdateData(TRUE);
	for(int i=2;i<4;i++)
		{
			CSeries ChartSpeed = (CSeries)m_Chart.Series(i);
			ChartSpeed.Clear();
		}
	UpdateData(FALSE);
}

void CTuLuntDlg::clearJiYuan()
{
	UpdateData(TRUE);
	CSeries ChartSpeed = (CSeries)m_Chart.Series(1);
	ChartSpeed.Clear();
	UpdateData(FALSE);
}

void CTuLuntDlg::zuoBiaoDian()
{
	UpdateData(TRUE);
	SetDlgItemInt(IDC_XUANZHUAN_EDIT,0,1);
	CString tt(_T(""));	
	m_zuoB.Format(_T("%.4f"),m_valX[0]);
	tt=m_zuoB;
	m_zuoB.Format(_T("%.4f"),m_valY[0]);
	tt=tt+","+m_zuoB;
	SetDlgItemText(IDC_ZUOBIAO_EDIT,tt);

	m_neiB.Format(_T("%.4f"),m_valX1[0]);
	tt=m_neiB;
	m_neiB.Format(_T("%.4f"),m_valY1[0]);
	tt=tt+","+m_neiB;
	SetDlgItemText(IDC_NEIBIAO_EDIT,tt);

	/*m_waiB.Format(_T("%.4f"),m_valX2[0]);
	tt=m_waiB;
	m_waiB.Format(_T("%.4f"),m_valY2[0]);
	tt=tt+","+m_waiB;
	SetDlgItemText(IDC_WAIBIAO_EDIT,tt);*/
	UpdateData(FALSE);
}

void CTuLuntDlg::zuoBiaoDianUpd()
{
	double val1[2];
	double temp=0,temp1=0;
	m_xuanZhuJ++;
	for(int i=0;i<360;i++)
	{
		temp=m_valX[i]*cos(1*pi/180)-m_valY[i]*fangxiang*sin(1*pi/180);
		temp1=m_valX[i]*fangxiang*sin(1*pi/180)+m_valY[i]*cos(1*pi/180);
		m_valX[i]=temp;
		m_valY[i]=temp1;
		temp=m_valX1[i]*cos(1*pi/180)-m_valY1[i]*fangxiang*sin(1*pi/180);
		temp1=m_valX1[i]*fangxiang*sin(1*pi/180)+m_valY1[i]*cos(1*pi/180);
		m_valX1[i]=temp;
		m_valY1[i]=temp1;
		temp=m_valX2[i]*cos(1*pi/180)-m_valY2[i]*fangxiang*sin(1*pi/180);
		temp1=m_valX2[i]*fangxiang*sin(1*pi/180)+m_valY2[i]*cos(1*pi/180);
		m_valX2[i]=temp;
		m_valY2[i]=temp1;
		temp=0;
		temp1=0;
	}
	putDian();
	SetDlgItemInt(IDC_XUANZHUAN_EDIT,m_xuanZhuJ,1);
	val1[0]=m_valX[m_xuanZhuJ];
	val1[1]=m_valY[m_xuanZhuJ];
	CString tt(_T(""));	
	m_zuoB.Format(_T("%.4f"),val1[0]);
	tt=m_zuoB;
	m_zuoB.Format(_T("%.4f"),val1[1]);
	tt=tt+","+m_zuoB;
	SetDlgItemText(IDC_ZUOBIAO_EDIT,tt);

	val1[0]=m_valX1[m_xuanZhuJ];
	val1[1]=m_valY1[m_xuanZhuJ];
	m_neiB.Format(_T("%.4f"),val1[0]);
	tt=m_neiB;
	m_neiB.Format(_T("%.4f"),val1[1]);
	tt=tt+","+m_neiB;
	SetDlgItemText(IDC_NEIBIAO_EDIT,tt);

	val1[0]=m_valX2[m_xuanZhuJ];
	val1[1]=m_valY2[m_xuanZhuJ];
	m_waiB.Format(_T("%.4f"),val1[0]);
	tt=m_waiB;
	m_waiB.Format(_T("%.4f"),val1[1]);
	tt=tt+","+m_waiB;
	SetDlgItemText(IDC_WAIBIAO_EDIT,tt);
}

void CTuLuntDlg::showYiDong()
{
	CWnd *pEditFile = NULL;	
	pEditFile     = GetDlgItem(IDC_BAIFU_EDIT); 
	if (pEditFile  != NULL)
	{
		pEditFile->ShowWindow(SW_HIDE);
	}
	pEditFile     = GetDlgItem(IDC_BAIFU_STATIC); 
	if (pEditFile  != NULL)
	{
		pEditFile->ShowWindow(SW_HIDE);
	}
	pEditFile     = GetDlgItem(IDC_BAIFU_SPIN); 
	if (pEditFile  != NULL)
	{
		pEditFile->ShowWindow(SW_HIDE);
	}

	pEditFile= GetDlgItem(IDC_GAN_EDIT);
	if (pEditFile  != NULL)
	{
		pEditFile->ShowWindow(SW_HIDE);
	}
	pEditFile       = GetDlgItem(IDC_ZHONGXIN_EDIT);
	if (pEditFile  != NULL)
	{
		pEditFile->ShowWindow(SW_HIDE);
	}
	pEditFile= GetDlgItem(IDC_GAN_STATIC);
	if (pEditFile  != NULL)
	{
		pEditFile->ShowWindow(SW_HIDE);
	}
	pEditFile       = GetDlgItem(IDC_ZHONGXIN_STATIC);
	if (pEditFile  != NULL)
	{
		pEditFile->ShowWindow(SW_HIDE);
	}
	pEditFile     = GetDlgItem(IDC_ZHONGXIN_SPIN); 
	if (pEditFile  != NULL)
	{
		pEditFile->ShowWindow(SW_HIDE);
	}
	pEditFile     = GetDlgItem(IDC_GAN_SPIN); 
	if (pEditFile  != NULL)
	{
		pEditFile->ShowWindow(SW_HIDE);
	}
	pEditFile     = GetDlgItem(IDC_XINCHENG_EDIT); 
	if (pEditFile  != NULL)
	{
		pEditFile->ShowWindow(SW_SHOW);
	}
	pEditFile     = GetDlgItem(IDC_XINGCHENG_STATIC); 
	if (pEditFile  != NULL)
	{
		pEditFile->ShowWindow(SW_SHOW);
	}
	pEditFile     = GetDlgItem(IDC_XINGCHENG_SPIN); 
	if (pEditFile  != NULL)
	{
		pEditFile->ShowWindow(SW_SHOW);
	}
	pEditFile     = GetDlgItem(IDC_PIANJU_STATIC); 
	if (pEditFile  != NULL)
	{
		pEditFile->ShowWindow(SW_SHOW);
	}
	pEditFile     = GetDlgItem(IDC_PIANJU_COMBO); 
	if (pEditFile  != NULL)
	{
		pEditFile->ShowWindow(SW_SHOW);
	}
	pEditFile     = GetDlgItem(IDC_PIANJU_EDIT); 
	if (pEditFile  != NULL)
	{
		pEditFile->ShowWindow(SW_SHOW);
	}
	pEditFile     = GetDlgItem(IDC_PIANJU_SPIN); 
	if (pEditFile  != NULL)
	{
		pEditFile->ShowWindow(SW_SHOW);
	}
	 pEditFile = NULL;
}

void CTuLuntDlg::showBaiDong()
{
	CWnd *pEditFile = NULL;
	pEditFile     = GetDlgItem(IDC_XINCHENG_EDIT); 
	if (pEditFile  != NULL)
	{
		pEditFile->ShowWindow(SW_HIDE);
	}
	pEditFile     = GetDlgItem(IDC_XINGCHENG_STATIC); 
	if (pEditFile  != NULL)
	{
		pEditFile->ShowWindow(SW_HIDE);
	}
	pEditFile     = GetDlgItem(IDC_XINGCHENG_SPIN); 
	if (pEditFile  != NULL)
	{
		pEditFile->ShowWindow(SW_HIDE);
	}
	pEditFile     = GetDlgItem(IDC_BAIFU_EDIT); 
	if (pEditFile  != NULL)
	{
		pEditFile->ShowWindow(SW_SHOW);
	}
	pEditFile     = GetDlgItem(IDC_BAIFU_STATIC); 
	if (pEditFile  != NULL)
	{
		pEditFile->ShowWindow(SW_SHOW);
	}
	pEditFile     = GetDlgItem(IDC_BAIFU_SPIN); 
	if (pEditFile  != NULL)
	{
		pEditFile->ShowWindow(SW_SHOW);
	}

	pEditFile= GetDlgItem(IDC_GAN_EDIT);
	if (pEditFile  != NULL)
	{
		pEditFile->ShowWindow(SW_SHOW);
	}
	pEditFile       = GetDlgItem(IDC_ZHONGXIN_EDIT);
	if (pEditFile  != NULL)
	{
		pEditFile->ShowWindow(SW_SHOW);
	}
	pEditFile= GetDlgItem(IDC_GAN_STATIC);
	if (pEditFile  != NULL)
	{
		pEditFile->ShowWindow(SW_SHOW);
	}
	pEditFile       = GetDlgItem(IDC_ZHONGXIN_STATIC);
	if (pEditFile  != NULL)
	{
		pEditFile->ShowWindow(SW_SHOW);
	}
	pEditFile     = GetDlgItem(IDC_ZHONGXIN_SPIN); 
	if (pEditFile  != NULL)
	{
		pEditFile->ShowWindow(SW_SHOW);
	}
	pEditFile     = GetDlgItem(IDC_GAN_SPIN); 
	if (pEditFile  != NULL)
	{
		pEditFile->ShowWindow(SW_SHOW);
	}
	pEditFile     = GetDlgItem(IDC_PIANJU_STATIC); 
	if (pEditFile  != NULL)
	{
		pEditFile->ShowWindow(SW_HIDE);
	}
	pEditFile     = GetDlgItem(IDC_PIANJU_COMBO); 
	if (pEditFile  != NULL)
	{
		pEditFile->ShowWindow(SW_HIDE);
	}
	pEditFile     = GetDlgItem(IDC_PIANJU_EDIT); 
	if (pEditFile  != NULL)
	{
		pEditFile->ShowWindow(SW_HIDE);
	}
	pEditFile     = GetDlgItem(IDC_PIANJU_SPIN); 
	if (pEditFile  != NULL)
	{
		pEditFile->ShowWindow(SW_HIDE);
	}
	pEditFile = NULL;
}

void CTuLuntDlg::showGunZi()
{
	CWnd *pEditFile = NULL;
	pEditFile= GetDlgItem(IDC_GUNZI_EDIT);
	if (pEditFile  != NULL)
	{
		pEditFile->ShowWindow(SW_SHOW);
	}
	pEditFile= GetDlgItem(IDC_GUNZI_STATIC);
	if (pEditFile  != NULL)
	{
		pEditFile->ShowWindow(SW_SHOW);
	}
	pEditFile     = GetDlgItem(IDC_GUNZI_SPIN); 
	if (pEditFile  != NULL)
	{
		pEditFile->ShowWindow(SW_SHOW);
	}

	pEditFile     = GetDlgItem(IDC_NEIKUO_CHECK); 
	if (pEditFile  != NULL)
	{
		pEditFile->ShowWindow(SW_SHOW);
		pEditFile->EnableWindow(TRUE);
		((CButton*)pEditFile)->SetCheck(1);
	}
	pEditFile     = GetDlgItem(IDC_WAIKUO_CHECK); 
	if (pEditFile  != NULL)
	{
		pEditFile->ShowWindow(SW_SHOW);
		pEditFile->EnableWindow(TRUE);
		((CButton*)pEditFile)->SetCheck(0);
	}
	pEditFile     = GetDlgItem(IDC_LUNKUO_CHECK); 
	if (pEditFile  != NULL)
	{
		pEditFile->ShowWindow(SW_HIDE);
	}
	pEditFile     = GetDlgItem(IDC_SHIKUO_CHECK); 
	if (pEditFile  != NULL)
	{
		pEditFile->ShowWindow(SW_SHOW);
		pEditFile->EnableWindow(TRUE);
		((CButton*)pEditFile)->SetCheck(1);
	}
	pEditFile     = GetDlgItem(IDC_NEIBIAO_EDIT); 
	if (pEditFile  != NULL)
	{
		pEditFile->ShowWindow(SW_SHOW);
	}
	pEditFile     = GetDlgItem(IDC_NEIBIAO_STATIC); 
	if (pEditFile  != NULL)
	{
		pEditFile->ShowWindow(SW_SHOW);
	}
	pEditFile     = GetDlgItem(IDC_WAIBIAO_EDIT); 
	if (pEditFile  != NULL)
	{
		pEditFile->ShowWindow(SW_SHOW);
	}
	pEditFile     = GetDlgItem(IDC_WAIBIAO_STATIC); 
	if (pEditFile  != NULL)
	{
		pEditFile->ShowWindow(SW_SHOW);
	}
	pEditFile     = GetDlgItem(IDC_CONG_CHECK); 
	if (pEditFile  != NULL)
	{
		pEditFile->ShowWindow(SW_SHOW);
		pEditFile->EnableWindow(TRUE);
		((CButton*)pEditFile)->SetCheck(1);
	}
	pEditFile     = GetDlgItem(IDC_ZHONGXIN_CHECK); 
	if (pEditFile  != NULL)
	{
		pEditFile->ShowWindow(SW_SHOW);
		pEditFile->EnableWindow(TRUE);
		((CButton*)pEditFile)->SetCheck(1);
	}
	pEditFile     = GetDlgItem(IDC_JIYUAN_CHECK); 
	if (pEditFile  != NULL)
	{
		pEditFile->ShowWindow(SW_SHOW);
		pEditFile->EnableWindow(TRUE);
		((CButton*)pEditFile)->SetCheck(0);
	}
	pEditFile = NULL;
}

void CTuLuntDlg::showNotGunZi()
{
	CWnd *pEditFile = NULL;
	pEditFile= GetDlgItem(IDC_GUNZI_EDIT);
	if (pEditFile  != NULL)
	{
		pEditFile->ShowWindow(SW_HIDE);
	}
	pEditFile= GetDlgItem(IDC_GUNZI_STATIC);
	if (pEditFile  != NULL)
	{
		pEditFile->ShowWindow(SW_HIDE);
	}
	pEditFile     = GetDlgItem(IDC_GUNZI_SPIN); 
	if (pEditFile  != NULL)
	{
		pEditFile->ShowWindow(SW_HIDE);
	}


	pEditFile     = GetDlgItem(IDC_NEIKUO_CHECK); 
	if (pEditFile  != NULL)
	{
		pEditFile->EnableWindow(FALSE);
	}
	pEditFile     = GetDlgItem(IDC_WAIKUO_CHECK); 
	if (pEditFile  != NULL)
	{
		pEditFile->EnableWindow(FALSE);
	}
	pEditFile     = GetDlgItem(IDC_LUNKUO_CHECK); 
	if (pEditFile  != NULL)
	{
		pEditFile->ShowWindow(SW_SHOW);
		pEditFile->EnableWindow(TRUE);
		((CButton*)pEditFile)->SetCheck(1);
	}
	pEditFile     = GetDlgItem(IDC_SHIKUO_CHECK); 
	if (pEditFile  != NULL)
	{
		pEditFile->ShowWindow(SW_HIDE);
	}
	pEditFile     = GetDlgItem(IDC_NEIBIAO_EDIT); 
	if (pEditFile  != NULL)
	{
		pEditFile->ShowWindow(SW_HIDE);
	}
	pEditFile     = GetDlgItem(IDC_NEIBIAO_STATIC); 
	if (pEditFile  != NULL)
	{
		pEditFile->ShowWindow(SW_HIDE);
	}
	pEditFile     = GetDlgItem(IDC_WAIBIAO_EDIT); 
	if (pEditFile  != NULL)
	{
		pEditFile->ShowWindow(SW_HIDE);
	}
	pEditFile     = GetDlgItem(IDC_WAIBIAO_STATIC); 
	if (pEditFile  != NULL)
	{
		pEditFile->ShowWindow(SW_HIDE);
	}
	pEditFile     = GetDlgItem(IDC_CONG_CHECK); 
	if (pEditFile  != NULL)
	{
		pEditFile->ShowWindow(SW_SHOW);
		pEditFile->EnableWindow(TRUE);
		((CButton*)pEditFile)->SetCheck(1);
	}
	pEditFile     = GetDlgItem(IDC_ZHONGXIN_CHECK); 
	if (pEditFile  != NULL)
	{
		pEditFile->ShowWindow(SW_SHOW);
		pEditFile->EnableWindow(TRUE);
		((CButton*)pEditFile)->SetCheck(1);
	}
	pEditFile     = GetDlgItem(IDC_JIYUAN_CHECK); 
	if (pEditFile  != NULL)
	{
		pEditFile->ShowWindow(SW_SHOW);
		pEditFile->EnableWindow(TRUE);
		((CButton*)pEditFile)->SetCheck(0);
	}
	pEditFile = NULL;
}

void CTuLuntDlg::weiWanCheng()
{
	CWnd *pEditFile = NULL;
	pEditFile= GetDlgItem(IDC_XUANZHUANJIAO_STATIC);
	if (pEditFile  != NULL)
	{
		pEditFile->EnableWindow(FALSE);
	}
	pEditFile= GetDlgItem(IDC_XUANZHUAN_EDIT);
	if (pEditFile  != NULL)
	{
		pEditFile->EnableWindow(FALSE);
	}
	pEditFile= GetDlgItem(IDC_XUANZHUAJIAO_SPIN);
	if (pEditFile  != NULL)
	{
		pEditFile->EnableWindow(FALSE);
	}
	pEditFile= GetDlgItem(IDC_LUOBIAO_STATIC);
	if (pEditFile  != NULL)
	{
		pEditFile->EnableWindow(FALSE);
	}
	pEditFile= GetDlgItem(IDC_ZUOBIAO_EDIT);
	if (pEditFile  != NULL)
	{
		pEditFile->EnableWindow(FALSE);
	}
	pEditFile= GetDlgItem(IDC_NEIBIAO_STATIC);
	if (pEditFile  != NULL)
	{
		pEditFile->EnableWindow(FALSE);
	}
	pEditFile= GetDlgItem(IDC_NEIBIAO_EDIT);
	if (pEditFile  != NULL)
	{
		pEditFile->EnableWindow(FALSE);
	}
	pEditFile= GetDlgItem(IDC_WAIBIAO_STATIC);
	if (pEditFile  != NULL)
	{
		pEditFile->EnableWindow(FALSE);
	}
	pEditFile= GetDlgItem(IDC_WAIBIAO_EDIT);
	if (pEditFile  != NULL)
	{
		pEditFile->EnableWindow(FALSE);
	}
	pEditFile= GetDlgItem(IDC_XUANZHUAN_BUTTON);
	if (pEditFile  != NULL)
	{
		pEditFile->EnableWindow(FALSE);
	}
	pEditFile= GetDlgItem(IDC_ZANTING_BUTTON);
	if (pEditFile  != NULL)
	{
		pEditFile->EnableWindow(FALSE);
	}
	pEditFile= GetDlgItem(IDC_SUOXIAO_BUTTON);
	if (pEditFile  != NULL)
	{
		pEditFile->EnableWindow(FALSE);
	}
	pEditFile= GetDlgItem(IDC_FANGDA_BUTTON);
	if (pEditFile  != NULL)
	{
		pEditFile->EnableWindow(FALSE);
	}
	pEditFile= GetDlgItem(IDC_FUWEI_BUTTON);
	if (pEditFile  != NULL)
	{
		pEditFile->EnableWindow(FALSE);
	}
	pEditFile= GetDlgItem(IDC_SHUAXIN_BUTTON);
	if (pEditFile  != NULL)
	{
		pEditFile->EnableWindow(FALSE);
	}
	pEditFile=NULL;
}

void CTuLuntDlg::Init_Data()
{
	fangxiang=1;
	pianZuoYou=1;
	DWORD pNumElements[] = {360};
	XValues.Create(VT_R8, 1, pNumElements);    
	YValues.Create(VT_R8, 1, pNumElements);
	XValues1.Create(VT_R8, 1, pNumElements);    
	YValues1.Create(VT_R8, 1, pNumElements);
	XValues2.Create(VT_R8, 1, pNumElements);    
	YValues2.Create(VT_R8, 1, pNumElements);
	m_leiXing.ResetContent();
	m_leiXing.AddString(_T("尖顶移动-盘形凸轮"));
	m_leiXing.AddString(_T("滚子移动-盘形凸轮"));
	m_leiXing.AddString(_T("尖顶摆动-盘形凸轮"));
	//m_leiXing.AddString(_T("滚子摆动-盘形凸轮"));
	m_leiXing.AddString(_T("平底移动-盘形凸轮"));
	m_leiXing.SetCurSel(0);

	m_fangXiang.ResetContent();
	m_fangXiang.AddString(_T("逆时针"));
	//m_fangXiang.AddString(_T("顺时针"));
	m_fangXiang.SetCurSel(0);

	m_pian.ResetContent();
	//m_pian.AddString(_T("偏左"));
	m_pian.AddString(_T("偏右"));
	m_pian.SetCurSel(0);

	m_tui.ResetContent();
	m_tui.AddString(_T("等速"));
	m_tui.AddString(_T("等加速等减速"));
	m_tui.AddString(_T("余弦加速度"));
	m_tui.AddString(_T("正弦加速度"));
	m_tui.SetCurSel(0);
	
	m_hui.ResetContent();
	m_hui.AddString(_T("等速"));
	m_hui.AddString(_T("等加速等减速"));
	m_hui.AddString(_T("余弦加速度"));
	m_hui.AddString(_T("正弦加速度"));
	m_hui.SetCurSel(0);
	dianShuJu();
	showYiDong();
	showNotGunZi();
	drawLunKuo();
	drawConDonYi();
	drawHuiZhZhXin();
	zuoBiaoDian();
	

	//weiWanCheng();
}

void CTuLuntDlg::OnSelchangeLeixingCombo()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_xuanZhuan=0;
	m_fangXiang.SetCurSel(0);
	fangxiang=1;
	UpdateData(FALSE);
	dianShuJu();
	int mIndex;
	mIndex=m_leiXing.GetCurSel();	
	switch(mIndex)
	{
	/*case 0:
		showBaiDong();
		showGunZi();
		clearAllConDon();
		clearNeiWai();
		clearJiYuan();
		drawLunKuo();
		drawConDonBai();
		drawConDonBai3();
		drawNeiKuo();
		zuoBiaoDian();
	break;*/
	case 1:		
		showGunZi();
		showYiDong();
		clearAllConDon();
		clearNeiWai();
		clearJiYuan();
		drawLunKuo();
		drawNeiKuo();
		drawConDonYi();
		drawConDonYi2();
		zuoBiaoDian();
	break;
	case 2:
		showBaiDong();
		showNotGunZi();
		clearAllConDon();
		clearNeiWai();
		clearJiYuan();
		drawLunKuo();
		drawConDonBai();
		zuoBiaoDian();
	break;
	case 0:
		showNotGunZi();
		showYiDong();
		clearAllConDon();
		clearNeiWai();
		clearJiYuan();
		drawLunKuo();
		drawConDonYi();
		zuoBiaoDian();
	break;
	case 3:
		showYiDong();
		showNotGunZi();
		clearAllConDon();
		clearNeiWai();
		clearJiYuan();
		drawLunKuo();
		drawConDonPinDi();
		zuoBiaoDian();
	break;
	}
}

void CTuLuntDlg::OnChangeTuiEdit()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CBCGPDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	dianShuJu();
	drawLunKuo();	
	drawNeiWaiKuo();
	yaLiJiao();
}

void CTuLuntDlg::OnChangeYuanxiuEdit()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CBCGPDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	dianShuJu();
	drawLunKuo();	
	drawNeiWaiKuo();	
	yaLiJiao();
}

void CTuLuntDlg::OnChangeHuiEdit()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CBCGPDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	dianShuJu();
	drawLunKuo();	
	drawNeiWaiKuo();
	yaLiJiao();
}

void CTuLuntDlg::OnChangeXinchengEdit()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CBCGPDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	dianShuJu();
	drawLunKuo();	
	drawNeiWaiKuo();	
	yaLiJiao();
}

void CTuLuntDlg::OnChangeBaifuEdit()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CBCGPDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	dianShuJu();
	drawLunKuo();	
	drawNeiWaiKuo();	
	yaLiJiao();
}

void CTuLuntDlg::OnChangeJiyuanEdit()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CBCGPDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	dianShuJu();
	drawLunKuo();	
	drawNeiWaiKuo();
	drawConDon();
	yaLiJiao();
}

void CTuLuntDlg::OnChangePianjuEdit()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CBCGPDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	dianShuJu();
	drawLunKuo();	
	drawNeiWaiKuo();
	drawConDon();
	yaLiJiao();
}

void CTuLuntDlg::OnChangeGunziEdit()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CBCGPDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	dianShuJu();
	drawLunKuo();	
	drawNeiWaiKuo();
	drawConDon();
	yaLiJiao();
}

void CTuLuntDlg::OnChangeZhongxinEdit()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CBCGPDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	dianShuJu();
	drawLunKuo();	
	drawNeiWaiKuo();
	drawConDon();
	yaLiJiao();
}

void CTuLuntDlg::OnChangeGanEdit()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CBCGPDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	dianShuJu();
	drawLunKuo();	
	drawNeiWaiKuo();
	drawConDon();
	yaLiJiao();
}

void CTuLuntDlg::OnDeltaposBaifuSpin(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: Add your control notification handler code here
	if(pNMUpDown->iDelta == -1)  // 如果此值为-1 , 说明点击了Spin的往上箭头
	{
		m_xingBai++;
	}
    else if(pNMUpDown->iDelta == 1)  // 如果此值为, 说明点击了Spin的往下箭头
	{
		m_xingBai--;
	}
	UpdateData(TRUE);
    SetDlgItemInt(IDC_BAIFU_EDIT,m_xingBai,1);
	UpdateData(FALSE);
	*pResult = 0;
}

void CTuLuntDlg::OnDeltaposGanSpin(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: Add your control notification handler code here
	if(pNMUpDown->iDelta == -1)  // 如果此值为-1 , 说明点击了Spin的往上箭头
	{
		m_ganC++;
	}
    else if(pNMUpDown->iDelta == 1)  // 如果此值为, 说明点击了Spin的往下箭头
	{
		m_ganC--;
	}
	UpdateData(TRUE);
    SetDlgItemInt(IDC_GAN_EDIT,m_ganC,1);
	*pResult = 0;
}

void CTuLuntDlg::OnDeltaposGunziSpin(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: Add your control notification handler code here
	if(pNMUpDown->iDelta == -1)  // 如果此值为-1 , 说明点击了Spin的往上箭头
	{
		m_gunZ++;
	}
    else if(pNMUpDown->iDelta == 1)  // 如果此值为, 说明点击了Spin的往下箭头
	{
		m_gunZ--;
	}
	UpdateData(TRUE);
    SetDlgItemInt(IDC_GUNZI_EDIT,m_gunZ,1);
	UpdateData(FALSE);
	*pResult = 0;
}

void CTuLuntDlg::OnDeltaposHuiSpin(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: Add your control notification handler code here
	if(pNMUpDown->iDelta == -1)  // 如果此值为-1 , 说明点击了Spin的往上箭头
	{
		m_huiChengJiao++;
	}
    else if(pNMUpDown->iDelta == 1)  // 如果此值为, 说明点击了Spin的往下箭头
	{
		m_huiChengJiao--;
	}
	UpdateData(TRUE);
    SetDlgItemInt(IDC_HUI_EDIT,m_huiChengJiao,1);
	*pResult = 0;
}

void CTuLuntDlg::OnDeltaposJiyuanSpin(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: Add your control notification handler code here
	if(pNMUpDown->iDelta == -1)  // 如果此值为-1 , 说明点击了Spin的往上箭头
	{
		m_jiYuanBj++;
	}
    else if(pNMUpDown->iDelta == 1)  // 如果此值为, 说明点击了Spin的往下箭头
	{
		m_jiYuanBj--;
	}
	UpdateData(TRUE);
    SetDlgItemInt(IDC_JIYUAN_EDIT,m_jiYuanBj,1);
	UpdateData(FALSE);
	*pResult = 0;
}

void CTuLuntDlg::OnDeltaposPianjuSpin(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: Add your control notification handler code here
	
	if(pNMUpDown->iDelta == -1)  // 如果此值为-1 , 说明点击了Spin的往上箭头
	{
		if(pianZuoYou==1)	m_pianJ++;
		else if(pianZuoYou==-1)	m_pianJ--;
	}
	else if(pNMUpDown->iDelta == 1)  // 如果此值为, 说明点击了Spin的往下箭头
	{
		if(pianZuoYou==1)	m_pianJ--;
		else if(pianZuoYou==-1)	m_pianJ++;
	}
	UpdateData(TRUE);
    SetDlgItemInt(IDC_PIANJU_EDIT,pianZuoYou*m_pianJ,1);
	UpdateData(FALSE);
	*pResult = 0;
}

void CTuLuntDlg::OnDeltaposTuiSpin(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: Add your control notification handler code here
	if(pNMUpDown->iDelta == -1)  // 如果此值为-1 , 说明点击了Spin的往上箭头
	{
		m_tuiChengJiao++;
	}
    else if(pNMUpDown->iDelta == 1)  // 如果此值为, 说明点击了Spin的往下箭头
	{
		m_tuiChengJiao--;
	}
	UpdateData(TRUE);
    SetDlgItemInt(IDC_TUI_EDIT,m_tuiChengJiao,1);
	*pResult = 0;
}

void CTuLuntDlg::OnDeltaposYuanxiuSpin(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: Add your control notification handler code here
	if(pNMUpDown->iDelta == -1)  // 如果此值为-1 , 说明点击了Spin的往上箭头
	{
		m_yuanXiuJiao++;
	}
    else if(pNMUpDown->iDelta == 1)  // 如果此值为, 说明点击了Spin的往下箭头
	{
		m_yuanXiuJiao--;
	}
	UpdateData(TRUE);
    SetDlgItemInt(IDC_YUANXIU_EDIT,m_yuanXiuJiao,1);
	*pResult = 0;
}

void CTuLuntDlg::OnDeltaposZhongxinSpin(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: Add your control notification handler code here
	if(pNMUpDown->iDelta == -1)  // 如果此值为-1 , 说明点击了Spin的往上箭头
	{
		m_zhongXinJ++;
	}
    else if(pNMUpDown->iDelta == 1)  // 如果此值为, 说明点击了Spin的往下箭头
	{
		m_zhongXinJ--;
	}
	UpdateData(TRUE);
    SetDlgItemInt(IDC_ZHONGXIN_EDIT,m_zhongXinJ,1);

	*pResult = 0;
}

void CTuLuntDlg::OnDeltaposXingchengSpin(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: Add your control notification handler code here
	if(pNMUpDown->iDelta == -1)  // 如果此值为-1 , 说明点击了Spin的往上箭头
	{
		m_xingBai++;
	}
    else if(pNMUpDown->iDelta == 1)  // 如果此值为, 说明点击了Spin的往下箭头
	{
		m_xingBai--;
	}
    SetDlgItemInt(IDC_XINCHENG_EDIT,m_xingBai,1);

	*pResult = 0;
}

void CTuLuntDlg::OnClickedLunkuoCheck()
{
	// TODO: Add your control notification handler code here	
	int mIndex;
	mIndex=m_leiXing.GetCurSel();	
	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_LUNKUO_CHECK))->GetCheck())
	{		
		drawLunKuo();
	}
	else
	{
		CSeries ChartSpeed = (CSeries)m_Chart.Series(0);
		ChartSpeed.Clear();
	}
}

void CTuLuntDlg::OnClickedJiyuanCheck()
{
	// TODO: Add your control notification handler code here
	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_JIYUAN_CHECK))->GetCheck())
	{
		drawJiYuan();
	}
	else
	{
		clearJiYuan();
	}
}

void CTuLuntDlg::OnClickedNeikuoCheck()
{
	// TODO: Add your control notification handler code here
	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_NEIKUO_CHECK))->GetCheck())
	{
		drawNeiKuo();
	}
	else
	{
		CSeries ChartSpeed = (CSeries)m_Chart.Series(2);
		ChartSpeed.Clear();
	}
}

void CTuLuntDlg::OnClickedWaikuoCheck()
{
	// TODO: Add your control notification handler code here
	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_WAIKUO_CHECK))->GetCheck())
	{
		drawWaiKuo();
	}
	else
	{
		CSeries ChartSpeed = (CSeries)m_Chart.Series(3);
		ChartSpeed.Clear();
	}
}

void CTuLuntDlg::OnClickedShikuoCheck()
{
	// TODO: Add your control notification handler code here
	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_SHIKUO_CHECK))->GetCheck())
	{
		drawLunKuo();
	}
	else
	{
		CSeries ChartSpeed = (CSeries)m_Chart.Series(0);
		ChartSpeed.Clear();
	}
}

void CTuLuntDlg::OnClickedZhongxinCheck()
{
	// TODO: Add your control notification handler code here
	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_ZHONGXIN_CHECK))->GetCheck())
	{
		drawHuiZhZhXin();
	}
	else
	{
		for(int i=4;i<6;i++)
		{
			CSeries ChartSpeed = (CSeries)m_Chart.Series(i);
			ChartSpeed.Clear();
		}
	}
}

void CTuLuntDlg::drawConDon()
{
	int mIndex;
	mIndex=m_leiXing.GetCurSel();	
	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CONG_CHECK))->GetCheck())
	{
		/*if(mIndex==0)
		{
			drawConDonBai();
			drawConDonBai3();
		}*/
		if(mIndex==0) 
		{
			drawConDonYi();
		}
		else if(mIndex==1) 
		{
			drawConDonYi();
			drawConDonYi2();
		}
		if(mIndex==2)
		{
			drawConDonBai();
		} 
		else if(mIndex==3) 
		{
			drawConDonPinDi();
		}
	}
	else
	{
		clearAllConDon();
	}
}

void CTuLuntDlg::OnClickedCongCheck()
{
	// TODO: Add your control notification handler code here
	drawConDon();
}

void CTuLuntDlg::OnClickedZantingButton()
{
	// TODO: Add your control notification handler code here
	CWnd *pEditFile = NULL;	
	pEditFile     = GetDlgItem(IDC_ZANTING_BUTTON); 
	if (pEditFile  != NULL)
	{
		pEditFile->ShowWindow(SW_HIDE);
	}
	pEditFile     = GetDlgItem(IDC_XUANZHUAN_BUTTON); 
	if (pEditFile  != NULL)
	{
		pEditFile->ShowWindow(SW_SHOW);
	}
	pEditFile=NULL;
	KillTimer(1);
}

void CTuLuntDlg::OnClickedXuanzhuanButton()
{
	// TODO: Add your control notification handler code here
	SetTimer(1, 50, NULL);	
	CWnd *pEditFile = NULL;	
	pEditFile     = GetDlgItem(IDC_ZANTING_BUTTON); 
	if (pEditFile  != NULL)
	{
		pEditFile->ShowWindow(SW_SHOW);
	}
	pEditFile     = GetDlgItem(IDC_XUANZHUAN_BUTTON); 
	if (pEditFile  != NULL)
	{
		pEditFile->ShowWindow(SW_HIDE);
	}
	pEditFile=NULL;
}

void CTuLuntDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	zuoBiaoDianUpd();
	drawLunKuo();
	drawNeiWaiKuo();
	drawConDon();
	if(m_xuanZhuJ>359) m_xuanZhuJ=0;
	CBCGPDialog::OnTimer(nIDEvent);
}

void CTuLuntDlg::OnSelchangeTuiCombo()
{
	// TODO: Add your control notification handler code here
	dianShuJu();
	drawLunKuo();	
	drawNeiWaiKuo();
	drawConDon();
}

void CTuLuntDlg::OnSelchangeHuiCombo()
{
	// TODO: Add your control notification handler code here
	dianShuJu();
	drawLunKuo();	
	drawNeiWaiKuo();
	drawConDon();
}

void CTuLuntDlg::OnDeltaposXuanzhuajiaoSpin(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: Add your control notification handler code here
	if(pNMUpDown->iDelta == -1)  // 如果此值为-1 , 说明点击了Spin的往上箭头
	{
		m_xuanZhuan++;
	}
    else if(pNMUpDown->iDelta == 1)  // 如果此值为, 说明点击了Spin的往下箭头
	{
		m_xuanZhuan--;
	}
    SetDlgItemInt(IDC_XUANZHUAN_EDIT,m_xuanZhuan,1);
	*pResult = 0;
}

void CTuLuntDlg::OnCbnSelchangeFangxiangCombo()
{
	// TODO: Add your control notification handler code here
	int mindex;
	mindex=m_fangXiang.GetCurSel();
	if(mindex==0)	fangxiang=1;
	else fangxiang=-1;
	dianShuJu();
	drawLunKuo();	
	drawNeiWaiKuo();
	drawConDon();
}

void CTuLuntDlg::OnChangeXuanzhuanEdit()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CBCGPDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	UpdateData(TRUE);
	m_xuanZhuJ=m_xuanZhuan-m_xuanZhuJ;
	UpdateData(FALSE);
	double val1[2];
	double temp=0,temp1=0;
	for(int i=0;i<360;i++)
	{
		temp=m_valX[i]*cos(m_xuanZhuJ*pi/180)-m_valY[i]*fangxiang*sin(m_xuanZhuJ*pi/180);
		temp1=m_valX[i]*fangxiang*sin(m_xuanZhuJ*pi/180)+m_valY[i]*cos(m_xuanZhuJ*pi/180);
		m_valX[i]=temp;
		m_valY[i]=temp1;
		temp=m_valX1[i]*cos(m_xuanZhuJ*pi/180)-m_valY1[i]*fangxiang*sin(m_xuanZhuJ*pi/180);
		temp1=m_valX1[i]*fangxiang*sin(m_xuanZhuJ*pi/180)+m_valY1[i]*cos(m_xuanZhuJ*pi/180);
		m_valX1[i]=temp;
		m_valY1[i]=temp1;
		temp=m_valX2[i]*cos(m_xuanZhuJ*pi/180)-m_valY2[i]*fangxiang*sin(m_xuanZhuJ*pi/180);
		temp1=m_valX2[i]*fangxiang*sin(m_xuanZhuJ*pi/180)+m_valY2[i]*cos(m_xuanZhuJ*pi/180);
		m_valX2[i]=temp;
		m_valY2[i]=temp1;
		temp=0;
		temp1=0;
	}
	putDian();
	//SetDlgItemInt(IDC_XUANZHUAN_EDIT,m_xuanZhuJ,1);
	val1[0]=m_valX[m_xuanZhuan];
	val1[1]=m_valY[m_xuanZhuan];
	CString tt(_T(""));	
	m_zuoB.Format(_T("%.4f"),val1[0]);
	tt=m_zuoB;
	m_zuoB.Format(_T("%.4f"),val1[1]);
	tt=tt+","+m_zuoB;
	SetDlgItemText(IDC_ZUOBIAO_EDIT,tt);

	val1[0]=m_valX1[m_xuanZhuan];
	val1[1]=m_valY1[m_xuanZhuan];
	m_neiB.Format(_T("%.4f"),val1[0]);
	tt=m_neiB;
	m_neiB.Format(_T("%.4f"),val1[1]);
	tt=tt+","+m_neiB;
	SetDlgItemText(IDC_NEIBIAO_EDIT,tt);

	val1[0]=m_valX2[m_xuanZhuan];
	val1[1]=m_valY2[m_xuanZhuan];
	m_waiB.Format(_T("%.4f"),val1[0]);
	tt=m_waiB;
	m_waiB.Format(_T("%.4f"),val1[1]);
	tt=tt+","+m_waiB;
	SetDlgItemText(IDC_WAIBIAO_EDIT,tt);
	drawLunKuo();	
	drawNeiWaiKuo();
	drawConDon();
}

void CTuLuntDlg::OnBnClickedFuweiButton()
{
	// TODO: Add your control notification handler code here
	SetDlgItemInt(IDC_XUANZHUAN_EDIT,0,1);
	dianShuJu();
	drawLunKuo();	
	drawNeiWaiKuo();
	drawConDon();
	zuoBiaoDian();
}
