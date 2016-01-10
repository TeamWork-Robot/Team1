
// TeeChartDlg.h : 头文件
//

#pragma once
#include "tchart1.h"
#include "CSeries.h"

// CTuLuntDlg 对话框
class CTuLuntDlg : public CBCGPDialog
{
// 构造
public:
	CTuLuntDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_TULUN_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	
	CComboBox m_fangXiang;
	double m_gan;
	double m_gunZi;
	CComboBox m_hui;
	double m_huiCheng;
	double m_jinXiu;
	double m_jiYuan;
	CComboBox m_leiXing;
	double m_pianJu;
	CComboBox m_tui;
	CComboBox m_pian;
	double m_tuiCheng;
	double m_xingCheng;
	double m_yuanXiu;
	double m_zhongXin;
	double m_baiFu;
	int m_xuanZhuan;
	float m_tuiYaLi;
	float m_yaLiJiao;
private:
	void Init_Data();
	void canShu();
	void dianShuJu();
	void putDian();
	void xieLv();
	void yaLiJiao();
	void drawLunKuo();
	void drawJiYuan();
	void drawNeiWaiKuo();
	void drawNeiKuo();
	void drawWaiKuo();
	void drawHuiZhZhXin();
	void drawHuiZhZhXin1();
	void drawConDon();
	void drawConDonYi();
	void drawConDonYi1();
	void drawConDonYi2();
	void drawConDonBai();
	void drawConDonBai1();
	void drawConDonBai2();
	void drawConDonBai3();
	void drawConDonPinDi();
	void drawConDonPinDi1();
	void clearAllConDon();
	void clearNeiWai();
	void clearJiYuan();
	void zuoBiaoDian();
	void zuoBiaoDianUpd();
	void showYiDong();
	void showBaiDong();
	void showGunZi();
	void showNotGunZi();
	void weiWanCheng();

	COleSafeArray XValues,XValues1,XValues2;    
	COleSafeArray YValues,YValues1,YValues2;
	double s[360],ss[360],sss[360],m_theta[360];
	double m_huiChengJiao;
	double m_jinXiuJiao;
	double m_jiYuanBj;
	double m_pianJ;
	double m_tuiChengJiao;
	double m_xingBai;
	double m_s0;
	double m_valX[360],m_valY[360];
	double m_valX1[360],m_valY1[360];
	double m_valX2[360],m_valY2[360];
	double m_yuanXiuJiao;
	double m_zhongXinJ;
	double m_ganC;
	double m_gunZ;
	int m_xuanZhuJ;
	double m_tuiYaLiJ;
	double m_yaLiJ;
	int fangxiang;
	int pianZuoYou;
	CString m_neiB;
	CString m_waiB;
	CString m_zuoB;
public:
	afx_msg void OnSelchangeLeixingCombo();
	afx_msg void OnChangeTuiEdit();
	afx_msg void OnChangeYuanxiuEdit();
	afx_msg void OnChangeHuiEdit();
	afx_msg void OnChangeXinchengEdit();
	afx_msg void OnChangeBaifuEdit();
	afx_msg void OnChangeJiyuanEdit();
	afx_msg void OnChangePianjuEdit();
	afx_msg void OnChangeGunziEdit();
	afx_msg void OnChangeZhongxinEdit();
	afx_msg void OnChangeGanEdit();
	afx_msg void OnDeltaposBaifuSpin(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposGanSpin(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposGunziSpin(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposHuiSpin(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposJiyuanSpin(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposPianjuSpin(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposTuiSpin(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposYuanxiuSpin(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposZhongxinSpin(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposXingchengSpin(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnClickedLunkuoCheck();
	afx_msg void OnClickedJiyuanCheck();
	afx_msg void OnClickedNeikuoCheck();
	afx_msg void OnClickedWaikuoCheck();
	afx_msg void OnClickedShikuoCheck();
	afx_msg void OnClickedZhongxinCheck();
	afx_msg void OnClickedCongCheck();
	afx_msg void OnClickedZantingButton();
	afx_msg void OnClickedXuanzhuanButton();
	afx_msg void OnSelchangePianjuCombo();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnSelchangeTuiCombo();
	afx_msg void OnSelchangeHuiCombo();
	
	afx_msg void OnDeltaposXuanzhuajiaoSpin(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnCbnSelchangeFangxiangCombo();
	
	afx_msg void OnChangeXuanzhuanEdit();
	afx_msg void OnBnClickedFuweiButton();
	CTchart1 m_Chart;
};
