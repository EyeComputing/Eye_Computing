#pragma once
#include "xSkinButton.h"
#include "afxwin.h"


// SelectKeyboardDlg 대화 상자입니다.

class SelectKeyboardDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SelectKeyboardDlg)

public:
	SelectKeyboardDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~SelectKeyboardDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_Dlg_Keyboard };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	HWND m_hForegroundWnd;

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();

	/*버튼 입력 받는 함수*/
	void SelectKeyboardDlg::OnBtnClick(UINT uiID);
	
	// 버튼 스킨 씌우는 함수
	void SelectKeyboardDlg::SetImgNumBtn();
	void SelectKeyboardDlg::SetImgSysBtn();
	void SelectKeyboardDlg::SetImgKorBtn();
	void SelectKeyboardDlg::SetImgSmallEngBtn();
	void SetImgBigEngBtn();
	void SelectKeyboardDlg::SetImgSpecialBtn();
	void SelectKeyboardDlg::SetPosBtn();

	void ShowKorBtn();
	void HideKorBtn();
	void ShowSmallEngBtn();
	void HideSmallEngBtn();
	void ShowBigEngBtn();
	void HideBigEngBtn();
	void ShowSpecialBtn();
	void HideSpecialBtn();

	// 윈도우 사이즈와 버튼 사이즈 값을 입력받기 위한 변수
	SIZE WindowSize;
	SIZE ButtonSize;

	// 숫자 버튼 변수
	CxSkinButton n_btn_one;
	CxSkinButton n_btn_two;
	CxSkinButton n_btn_thr;
	CxSkinButton n_btn_fou;
	CxSkinButton n_btn_fiv;
	CxSkinButton n_btn_six;
	CxSkinButton n_btn_sev;
	CxSkinButton n_btn_eig;
	CxSkinButton n_btn_nin;
	CxSkinButton n_btn_zer;
	CxSkinButton s_btn_shf;
	CxSkinButton s_btn_bks;
	CxSkinButton s_btn_ent;
	CxSkinButton s_btn_spe;
	CxSkinButton s_btn_con;
	CxSkinButton k_btn_bie;
	CxSkinButton k_btn_jie;
	CxSkinButton k_btn_dig;
	CxSkinButton k_btn_giy;
	CxSkinButton k_btn_shi;
	CxSkinButton k_btn_yyo;
	CxSkinButton k_btn_yeo;
	CxSkinButton k_btn_yya;
	CxSkinButton k_btn_aee;
	CxSkinButton k_btn_eee;
	CxSkinButton k_btn_mie;
	CxSkinButton k_btn_nie;
	CxSkinButton k_btn_ieu;
	CxSkinButton k_btn_rie;
	CxSkinButton k_btn_hie;
	CxSkinButton k_btn_ooo;
	CxSkinButton k_btn_eoo;
	CxSkinButton k_btn_aaa;
	CxSkinButton k_btn_yii;
	CxSkinButton k_btn_kie;
	CxSkinButton k_btn_tie;
	CxSkinButton k_btn_chi;
	CxSkinButton k_btn_pie;
	CxSkinButton k_btn_yuu;
	CxSkinButton k_btn_uuu;
	CxSkinButton k_btn_euu;
	CxSkinButton s_btn_kng;
	CxSkinButton s_btn_spc;
	CxSkinButton s_btn_dot;

	CxSkinButton e_btn_smq;
	CxSkinButton e_btn_smw;
	CxSkinButton e_btn_sme;
	CxSkinButton e_btn_smr;
	CxSkinButton e_btn_smt;
	CxSkinButton e_btn_smy;
	CxSkinButton e_btn_smu;
	CxSkinButton e_btn_smi;
	CxSkinButton e_btn_smo;
	CxSkinButton e_btn_smp;
	CxSkinButton e_btn_sma;
	CxSkinButton e_btn_sms;
	CxSkinButton e_btn_smd;
	CxSkinButton e_btn_smf;
	CxSkinButton e_btn_smg;
	CxSkinButton e_btn_smh;
	CxSkinButton e_btn_smj;
	CxSkinButton e_btn_smk;
	CxSkinButton e_btn_sml;
	CxSkinButton e_btn_smz;
	CxSkinButton e_btn_smx;
	CxSkinButton e_btn_smc;
	CxSkinButton e_btn_smv;
	CxSkinButton e_btn_smb;
	CxSkinButton e_btn_smn;
	CxSkinButton e_btn_smm;
	CxSkinButton s_btn_eng;
	CxSkinButton s_btn_kor;

	CxSkinButton p_btn_exc;
	CxSkinButton p_btn_gol;
	CxSkinButton p_btn_shp;
	CxSkinButton p_btn_dol;
	CxSkinButton p_btn_per;
	CxSkinButton p_btn_cir;
	CxSkinButton p_btn_and;
	CxSkinButton p_btn_ast;
	CxSkinButton p_btn_osg;
	CxSkinButton p_btn_csg;
	CxSkinButton p_btn_wav;
	CxSkinButton p_btn_hyp;
	CxSkinButton p_btn_eql;
	CxSkinButton p_btn_pls;
	CxSkinButton p_btn_odg;
	CxSkinButton p_btn_cdg;
	CxSkinButton p_btn_okg;
	CxSkinButton p_btn_ckg;
	CxSkinButton p_btn_qst;
	CxSkinButton p_btn_col;
	CxSkinButton p_btn_scl;
	CxSkinButton p_btn_sdd;
	CxSkinButton p_btn_bdd;
	CxSkinButton p_btn_bsl;
	CxSkinButton p_btn_sls;
	CxSkinButton p_btn_cmm;

	CxSkinButton e_btn_bgq;
	CxSkinButton e_btn_bgw;
	CxSkinButton e_btn_bge;
	CxSkinButton e_btn_bgr;
	CxSkinButton e_btn_bgt;
	CxSkinButton e_btn_bgy;
	CxSkinButton e_btn_bgu;
	CxSkinButton e_btn_bgi;
	CxSkinButton e_btn_bgo;
	CxSkinButton e_btn_bgp;
	CxSkinButton e_btn_bga;
	CxSkinButton e_btn_bgs;
	CxSkinButton e_btn_bgd;
	CxSkinButton e_btn_bgf;
	CxSkinButton e_btn_bgg;
	CxSkinButton e_btn_bgh;
	CxSkinButton e_btn_bgj;
	CxSkinButton e_btn_bgk;
	CxSkinButton e_btn_bgl;
	CxSkinButton e_btn_bgz;
	CxSkinButton e_btn_bgx;
	CxSkinButton e_btn_bgc;
	CxSkinButton e_btn_bgv;
	CxSkinButton e_btn_bgb;
	CxSkinButton e_btn_bgn;
	CxSkinButton e_btn_bgm;

	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedSKor();
	afx_msg void OnBnClickedSEng();



//	afx_msg void OnPaint();
	afx_msg void OnClose();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);

};
