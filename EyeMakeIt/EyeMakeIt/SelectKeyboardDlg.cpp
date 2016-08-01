// SelectKeyboardDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "EyeMakeIt.h"
#include "SelectKeyboardDlg.h"
#include "afxdialogex.h"

#include "Hangeul.h"

/* global var */
bool clickedShift = false;
INPUT InputShift;
int mousehide_count = 0;

// SelectKeyboardDlg 대화 상자입니다.

CString complete_text;

IMPLEMENT_DYNAMIC(SelectKeyboardDlg, CDialogEx)

SelectKeyboardDlg::SelectKeyboardDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(SelectKeyboardDlg::IDD, pParent)
{
	m_hForegroundWnd = NULL;
}

SelectKeyboardDlg::~SelectKeyboardDlg()
{
}

BEGIN_MESSAGE_MAP(SelectKeyboardDlg, CDialogEx)
	//ON_WM_LBUTTONDOWN()
	//ON_WM_MOUSEMOVE()
	/* 버튼 클릭 한번에 하는 메세지 매핑 */
	ON_COMMAND_RANGE(IDC_N_ONE, IDC_P_CMM, SelectKeyboardDlg::OnBtnClick)
	//ON_BN_CLICKED(IDC_S_KOR, &SelectKeyboardDlg::OnBnClickedSKor)

//	ON_WM_PAINT()
	ON_WM_CLOSE()
	ON_WM_SETCURSOR()

	
	ON_WM_CLOSE()
END_MESSAGE_MAP()

// SelectKeyboardDlg 메시지 처리기입니다.


BOOL SelectKeyboardDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	ZeroMemory(&WindowSize, sizeof(SIZE));
	WindowSize.cx = GetSystemMetrics(SM_CXFULLSCREEN);
	WindowSize.cy = GetSystemMetrics(SM_CYFULLSCREEN);
	// 컴퓨터의 전체 해상도 가져오기

	MoveWindow(0, 0, WindowSize.cx+ GetSystemMetrics(SM_CXEDGE) * 2, WindowSize.cy+ GetSystemMetrics(SM_CYCAPTION)+ GetSystemMetrics(SM_CYEDGE) * 2);
	// 키보드 크기 고정

	ButtonSize.cx = (WindowSize.cx / 10);
	ButtonSize.cy = (WindowSize.cy / 6);
	//버튼 크기 

	// 버튼 이미지 씌우기
	SetImgNumBtn();
	SetImgSysBtn();
	SetImgKorBtn();
	SetImgSmallEngBtn();
	SetImgBigEngBtn();
	SetImgSpecialBtn();

	// 버튼 좌표 설정
	SetPosBtn();
	
	// 영어, 특수문자 버튼 숨기기
	HideSmallEngBtn();
	HideBigEngBtn();
	HideSpecialBtn();

	// 글씨체, 크기 변경
	CFont g_editFont;
	g_editFont.CreatePointFont(200, TEXT("굴림"));
	GetDlgItem(IDC_MAINEDIT)->SetFont(&g_editFont);


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}








/* 사용자 정의 함수 */

void SelectKeyboardDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_N_ONE, n_btn_one);
	DDX_Control(pDX, IDC_N_TWO, n_btn_two);
	DDX_Control(pDX, IDC_N_THR, n_btn_thr);
	DDX_Control(pDX, IDC_N_FOU, n_btn_fou);
	DDX_Control(pDX, IDC_N_FIV, n_btn_fiv);
	DDX_Control(pDX, IDC_N_SIX, n_btn_six);
	DDX_Control(pDX, IDC_N_SEV, n_btn_sev);
	DDX_Control(pDX, IDC_N_EIG, n_btn_eig);
	DDX_Control(pDX, IDC_N_NIN, n_btn_nin);
	DDX_Control(pDX, IDC_N_ZER, n_btn_zer);
	DDX_Control(pDX, IDC_S_SHF, s_btn_shf);
	DDX_Control(pDX, IDC_S_BKS, s_btn_bks);
	DDX_Control(pDX, IDC_S_ENT, s_btn_ent);
	DDX_Control(pDX, IDC_S_SPE, s_btn_spe);
	DDX_Control(pDX, IDC_S_CON, s_btn_con);
	DDX_Control(pDX, IDC_K_BIE, k_btn_bie);
	DDX_Control(pDX, IDC_K_JIE, k_btn_jie);
	DDX_Control(pDX, IDC_K_DIG, k_btn_dig);
	DDX_Control(pDX, IDC_K_GIY, k_btn_giy);
	DDX_Control(pDX, IDC_K_SHI, k_btn_shi);
	DDX_Control(pDX, IDC_K_YYO, k_btn_yyo);
	DDX_Control(pDX, IDC_K_YEO, k_btn_yeo);
	DDX_Control(pDX, IDC_K_YYA, k_btn_yya);
	DDX_Control(pDX, IDC_K_AEE, k_btn_aee);
	DDX_Control(pDX, IDC_K_EEE, k_btn_eee);
	DDX_Control(pDX, IDC_K_MIE, k_btn_mie);
	DDX_Control(pDX, IDC_K_NIE, k_btn_nie);
	DDX_Control(pDX, IDC_K_IEU, k_btn_ieu);
	DDX_Control(pDX, IDC_K_RIE, k_btn_rie);
	DDX_Control(pDX, IDC_K_HIE, k_btn_hie);
	DDX_Control(pDX, IDC_K_OOO, k_btn_ooo);
	DDX_Control(pDX, IDC_K_EOO, k_btn_eoo);
	DDX_Control(pDX, IDC_K_AAA, k_btn_aaa);
	DDX_Control(pDX, IDC_K_YII, k_btn_yii);
	DDX_Control(pDX, IDC_S_KNG, s_btn_kng);
	DDX_Control(pDX, IDC_K_KIE, k_btn_kie);
	DDX_Control(pDX, IDC_K_TIE, k_btn_tie);
	DDX_Control(pDX, IDC_K_CHI, k_btn_chi);
	DDX_Control(pDX, IDC_K_PIE, k_btn_pie);
	DDX_Control(pDX, IDC_S_SPC, s_btn_spc);
	DDX_Control(pDX, IDC_K_YUU, k_btn_yuu);
	DDX_Control(pDX, IDC_K_UUU, k_btn_uuu);
	DDX_Control(pDX, IDC_K_EUU, k_btn_euu);
	DDX_Control(pDX, IDC_S_DOT, s_btn_dot);
	DDX_Control(pDX, IDC_E_SMQ, e_btn_smq);
	DDX_Control(pDX, IDC_E_SMW, e_btn_smw);
	DDX_Control(pDX, IDC_E_SME, e_btn_sme);
	DDX_Control(pDX, IDC_E_SMR, e_btn_smr);
	DDX_Control(pDX, IDC_E_SMT, e_btn_smt);
	DDX_Control(pDX, IDC_E_SMY, e_btn_smy);
	DDX_Control(pDX, IDC_E_SMU, e_btn_smu);
	DDX_Control(pDX, IDC_E_SMI, e_btn_smi);
	DDX_Control(pDX, IDC_E_SMO, e_btn_smo);
	DDX_Control(pDX, IDC_E_SMP, e_btn_smp);
	DDX_Control(pDX, IDC_E_SMA, e_btn_sma);
	DDX_Control(pDX, IDC_E_SMS, e_btn_sms);
	DDX_Control(pDX, IDC_E_SMD, e_btn_smd);
	DDX_Control(pDX, IDC_E_SMF, e_btn_smf);
	DDX_Control(pDX, IDC_E_SMG, e_btn_smg);
	DDX_Control(pDX, IDC_E_SMH, e_btn_smh);
	DDX_Control(pDX, IDC_E_SMJ, e_btn_smj);
	DDX_Control(pDX, IDC_E_SMK, e_btn_smk);
	DDX_Control(pDX, IDC_E_SML, e_btn_sml);
	DDX_Control(pDX, IDC_E_SMZ, e_btn_smz);
	DDX_Control(pDX, IDC_E_SMX, e_btn_smx);
	DDX_Control(pDX, IDC_E_SMC, e_btn_smc);
	DDX_Control(pDX, IDC_E_SMV, e_btn_smv);
	DDX_Control(pDX, IDC_E_SMB, e_btn_smb);
	DDX_Control(pDX, IDC_E_SMN, e_btn_smn);
	DDX_Control(pDX, IDC_E_SMM, e_btn_smm);
	DDX_Control(pDX, IDC_S_ENG, s_btn_eng);
	DDX_Control(pDX, IDC_S_KOR, s_btn_kor);
	DDX_Control(pDX, IDC_P_EXC, p_btn_exc);
	DDX_Control(pDX, IDC_P_GOL, p_btn_gol);
	DDX_Control(pDX, IDC_P_SHP, p_btn_shp);
	DDX_Control(pDX, IDC_P_DOL, p_btn_dol);
	DDX_Control(pDX, IDC_P_PER, p_btn_per);
	DDX_Control(pDX, IDC_P_CIR, p_btn_cir);
	DDX_Control(pDX, IDC_P_AND, p_btn_and);
	DDX_Control(pDX, IDC_P_AST, p_btn_ast);
	DDX_Control(pDX, IDC_P_OSG, p_btn_osg);
	DDX_Control(pDX, IDC_P_CSG, p_btn_csg);
	DDX_Control(pDX, IDC_P_WAV, p_btn_wav);
	DDX_Control(pDX, IDC_P_HYP, p_btn_hyp);
	DDX_Control(pDX, IDC_P_EQL, p_btn_eql);
	DDX_Control(pDX, IDC_P_PLS, p_btn_pls);
	DDX_Control(pDX, IDC_P_ODG, p_btn_odg);
	DDX_Control(pDX, IDC_P_CDG, p_btn_cdg);
	DDX_Control(pDX, IDC_P_OKG, p_btn_okg);
	DDX_Control(pDX, IDC_P_CKG, p_btn_ckg);
	DDX_Control(pDX, IDC_P_QST, p_btn_qst);
	DDX_Control(pDX, IDC_P_COL, p_btn_col);
	DDX_Control(pDX, IDC_P_SCL, p_btn_scl);
	DDX_Control(pDX, IDC_P_SDD, p_btn_sdd);
	DDX_Control(pDX, IDC_P_BDD, p_btn_bdd);
	DDX_Control(pDX, IDC_P_BSL, p_btn_bsl);
	DDX_Control(pDX, IDC_P_SLS, p_btn_sls);
	DDX_Control(pDX, IDC_P_CMM, p_btn_cmm);
	DDX_Control(pDX, IDC_E_BGQ, e_btn_bgq);
	DDX_Control(pDX, IDC_E_BGW, e_btn_bgw);
	DDX_Control(pDX, IDC_E_BGE, e_btn_bge);
	DDX_Control(pDX, IDC_E_BGR, e_btn_bgr);
	DDX_Control(pDX, IDC_E_BGT, e_btn_bgt);
	DDX_Control(pDX, IDC_E_BGY, e_btn_bgy);
	DDX_Control(pDX, IDC_E_BGU, e_btn_bgu);
	DDX_Control(pDX, IDC_E_BGI, e_btn_bgi);
	DDX_Control(pDX, IDC_E_BGO, e_btn_bgo);
	DDX_Control(pDX, IDC_E_BGP, e_btn_bgp);
	DDX_Control(pDX, IDC_E_BGA, e_btn_bga);
	DDX_Control(pDX, IDC_E_BGS, e_btn_bgs);
	DDX_Control(pDX, IDC_E_BGD, e_btn_bgd);
	DDX_Control(pDX, IDC_E_BGF, e_btn_bgf);
	DDX_Control(pDX, IDC_E_BGG, e_btn_bgg);
	DDX_Control(pDX, IDC_E_BGH, e_btn_bgh);
	DDX_Control(pDX, IDC_E_BGJ, e_btn_bgj);
	DDX_Control(pDX, IDC_E_BGK, e_btn_bgk);
	DDX_Control(pDX, IDC_E_BGL, e_btn_bgl);
	DDX_Control(pDX, IDC_E_BGZ, e_btn_bgz);
	DDX_Control(pDX, IDC_E_BGX, e_btn_bgx);
	DDX_Control(pDX, IDC_E_BGC, e_btn_bgc);
	DDX_Control(pDX, IDC_E_BGV, e_btn_bgv);
	DDX_Control(pDX, IDC_E_BGB, e_btn_bgb);
	DDX_Control(pDX, IDC_E_BGN, e_btn_bgn);
	DDX_Control(pDX, IDC_E_BGM, e_btn_bgm);

}

/*
// 포커스 함수 2개.
void SelectKeyboardDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	if (!m_hForegroundWnd)
	{
		m_hForegroundWnd = ::GetForegroundWindow();
		ModifyStyleEx(WS_EX_NOACTIVATE, 0);
		SetForegroundWindow();
	}


	CDialogEx::OnLButtonDown(nFlags, point);
}

void SelectKeyboardDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	if (m_hForegroundWnd)
	{
		::SetForegroundWindow(m_hForegroundWnd);
		ModifyStyleEx(0, WS_EX_NOACTIVATE);

		m_hForegroundWnd = NULL;

	}

	CDialogEx::OnMouseMove(nFlags, point);
}
*/

// 숫자 버튼 이미지 삽입
void SelectKeyboardDlg::SetImgNumBtn()
{
	// 숫자 버튼 스킨 씌우기
	n_btn_one.SetSkin(IDB_N_ONE, IDB_N_ONE, IDB_N_ONE_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	n_btn_two.SetSkin(IDB_N_TWO, IDB_N_TWO, IDB_N_TWO_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	n_btn_thr.SetSkin(IDB_N_THR, IDB_N_THR, IDB_N_THR_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	n_btn_fou.SetSkin(IDB_N_FOU, IDB_N_FOU, IDB_N_FOU_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	n_btn_fiv.SetSkin(IDB_N_FIV, IDB_N_FIV, IDB_N_FIV_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	n_btn_six.SetSkin(IDB_N_SIX, IDB_N_SIX, IDB_N_SIX_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	n_btn_sev.SetSkin(IDB_N_SEV, IDB_N_SEV, IDB_N_SEV_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	n_btn_eig.SetSkin(IDB_N_EIG, IDB_N_EIG, IDB_N_EIG_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	n_btn_nin.SetSkin(IDB_N_NIN, IDB_N_NIN, IDB_N_NIN_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	n_btn_zer.SetSkin(IDB_N_ZER, IDB_N_ZER, IDB_N_ZER_OVER, 0, 0, IDB_MASK, 1, 0, 4);
}

// 시스템 버튼 이미지 삽입
void SelectKeyboardDlg::SetImgSysBtn()
{
	// 시스템 버튼 스킨 씌우기
	s_btn_shf.SetSkin(IDB_S_SHF, IDB_S_SHF, IDB_S_SHF_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	s_btn_bks.SetSkin(IDB_S_BKS, IDB_S_BKS, IDB_S_BKS_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	s_btn_ent.SetSkin(IDB_S_ENT, IDB_S_ENT, IDB_S_ENT_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	s_btn_spe.SetSkin(IDB_S_SPE, IDB_S_SPE, IDB_S_SPE_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	s_btn_con.SetSkin(IDB_S_CON, IDB_S_CON, IDB_S_CON_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	s_btn_kng.SetSkin(IDB_S_KNG, IDB_S_KNG, IDB_S_KNG_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	s_btn_spc.SetSkin(IDB_S_SPC, IDB_S_SPC, IDB_S_SPC_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	s_btn_dot.SetSkin(IDB_S_DOT, IDB_S_DOT, IDB_S_DOT_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	s_btn_kor.SetSkin(IDB_S_KOR, IDB_S_KOR, IDB_S_KOR_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	s_btn_eng.SetSkin(IDB_S_ENG, IDB_S_ENG, IDB_S_ENG_OVER, 0, 0, IDB_MASK, 1, 0, 4);
}

// 한글 버튼 이미지 삽입
void SelectKeyboardDlg::SetImgKorBtn()
{
	// 한글 버튼 스킨 씌우기
	k_btn_bie.SetSkin(IDB_K_BIE, IDB_K_BIE, IDB_K_BIE_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	k_btn_jie.SetSkin(IDB_K_JIE, IDB_K_JIE, IDB_K_JIE_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	k_btn_dig.SetSkin(IDB_K_DIG, IDB_K_DIG, IDB_K_DIG_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	k_btn_giy.SetSkin(IDB_K_GIY, IDB_K_GIY, IDB_K_GIY_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	k_btn_shi.SetSkin(IDB_K_SHI, IDB_K_SHI, IDB_K_SHI_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	k_btn_yyo.SetSkin(IDB_K_YYO, IDB_K_YYO, IDB_K_YYO_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	k_btn_yeo.SetSkin(IDB_K_YEO, IDB_K_YEO, IDB_K_YEO_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	k_btn_yya.SetSkin(IDB_K_YYA, IDB_K_YYA, IDB_K_YYA_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	k_btn_aee.SetSkin(IDB_K_AEE, IDB_K_AEE, IDB_K_AEE_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	k_btn_eee.SetSkin(IDB_K_EEE, IDB_K_EEE, IDB_K_EEE_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	k_btn_mie.SetSkin(IDB_K_MIE, IDB_K_MIE, IDB_K_MIE_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	k_btn_nie.SetSkin(IDB_K_NIE, IDB_K_NIE, IDB_K_NIE_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	k_btn_ieu.SetSkin(IDB_K_IEU, IDB_K_IEU, IDB_K_IEU_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	k_btn_rie.SetSkin(IDB_K_RIE, IDB_K_RIE, IDB_K_RIE_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	k_btn_hie.SetSkin(IDB_K_HIE, IDB_K_HIE, IDB_K_HIE_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	k_btn_ooo.SetSkin(IDB_K_OOO, IDB_K_OOO, IDB_K_OOO_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	k_btn_eoo.SetSkin(IDB_K_EOO, IDB_K_EOO, IDB_K_EOO_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	k_btn_aaa.SetSkin(IDB_K_AAA, IDB_K_AAA, IDB_K_AAA_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	k_btn_yii.SetSkin(IDB_K_YII, IDB_K_YII, IDB_K_YII_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	k_btn_kie.SetSkin(IDB_K_KIE, IDB_K_KIE, IDB_K_KIE_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	k_btn_tie.SetSkin(IDB_K_TIE, IDB_K_TIE, IDB_K_TIE_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	k_btn_chi.SetSkin(IDB_K_CHI, IDB_K_CHI, IDB_K_CHI_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	k_btn_pie.SetSkin(IDB_K_PIE, IDB_K_PIE, IDB_K_PIE_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	k_btn_yuu.SetSkin(IDB_K_YUU, IDB_K_YUU, IDB_K_YUU_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	k_btn_uuu.SetSkin(IDB_K_UUU, IDB_K_UUU, IDB_K_UUU_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	k_btn_euu.SetSkin(IDB_K_EUU, IDB_K_EUU, IDB_K_EUU_OVER, 0, 0, IDB_MASK, 1, 0, 4);
}

// 영어 소문자 버튼 이미지 삽입
void SelectKeyboardDlg::SetImgSmallEngBtn()
{
	// 영어 소문자 버튼 스킨 씌우기
	e_btn_smq.SetSkin(IDB_E_SMQ, IDB_E_SMQ, IDB_E_SMQ_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	e_btn_smw.SetSkin(IDB_E_SMW, IDB_E_SMW, IDB_E_SMW_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	e_btn_sme.SetSkin(IDB_E_SME, IDB_E_SME, IDB_E_SME_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	e_btn_smr.SetSkin(IDB_E_SMR, IDB_E_SMR, IDB_E_SMR_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	e_btn_smt.SetSkin(IDB_E_SMT, IDB_E_SMT, IDB_E_SMT_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	e_btn_smy.SetSkin(IDB_E_SMY, IDB_E_SMY, IDB_E_SMY_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	e_btn_smu.SetSkin(IDB_E_SMU, IDB_E_SMU, IDB_E_SMU_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	e_btn_smi.SetSkin(IDB_E_SMI, IDB_E_SMI, IDB_E_SMI_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	e_btn_smo.SetSkin(IDB_E_SMO, IDB_E_SMO, IDB_E_SMO_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	e_btn_smp.SetSkin(IDB_E_SMP, IDB_E_SMP, IDB_E_SMP_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	e_btn_sma.SetSkin(IDB_E_SMA, IDB_E_SMA, IDB_E_SMA_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	e_btn_sms.SetSkin(IDB_E_SMS, IDB_E_SMS, IDB_E_SMS_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	e_btn_smd.SetSkin(IDB_E_SMD, IDB_E_SMD, IDB_E_SMD_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	e_btn_smf.SetSkin(IDB_E_SMF, IDB_E_SMF, IDB_E_SMF_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	e_btn_smg.SetSkin(IDB_E_SMG, IDB_E_SMG, IDB_E_SMG_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	e_btn_smh.SetSkin(IDB_E_SMH, IDB_E_SMH, IDB_E_SMH_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	e_btn_smj.SetSkin(IDB_E_SMJ, IDB_E_SMJ, IDB_E_SMJ_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	e_btn_smk.SetSkin(IDB_E_SMK, IDB_E_SMK, IDB_E_SMK_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	e_btn_sml.SetSkin(IDB_E_SML, IDB_E_SML, IDB_E_SML_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	e_btn_smz.SetSkin(IDB_E_SMZ, IDB_E_SMZ, IDB_E_SMZ_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	e_btn_smx.SetSkin(IDB_E_SMX, IDB_E_SMX, IDB_E_SMX_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	e_btn_smc.SetSkin(IDB_E_SMC, IDB_E_SMC, IDB_E_SMC_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	e_btn_smv.SetSkin(IDB_E_SMV, IDB_E_SMV, IDB_E_SMV_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	e_btn_smb.SetSkin(IDB_E_SMB, IDB_E_SMB, IDB_E_SMB_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	e_btn_smn.SetSkin(IDB_E_SMN, IDB_E_SMN, IDB_E_SMN_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	e_btn_smm.SetSkin(IDB_E_SMM, IDB_E_SMM, IDB_E_SMM_OVER, 0, 0, IDB_MASK, 1, 0, 4);

}

void SelectKeyboardDlg::SetImgBigEngBtn()
{
	// 영어 대문자 버튼 스킨 씌우기
	e_btn_bgq.SetSkin(IDB_E_BGQ, IDB_E_BGQ, IDB_E_BGQ_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	e_btn_bgw.SetSkin(IDB_E_BGW, IDB_E_BGW, IDB_E_BGW_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	e_btn_bge.SetSkin(IDB_E_BGE, IDB_E_BGE, IDB_E_BGE_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	e_btn_bgr.SetSkin(IDB_E_BGR, IDB_E_BGR, IDB_E_BGR_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	e_btn_bgt.SetSkin(IDB_E_BGT, IDB_E_BGT, IDB_E_BGT_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	e_btn_bgy.SetSkin(IDB_E_BGY, IDB_E_BGY, IDB_E_BGY_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	e_btn_bgu.SetSkin(IDB_E_BGU, IDB_E_BGU, IDB_E_BGU_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	e_btn_bgi.SetSkin(IDB_E_BGI, IDB_E_BGI, IDB_E_BGI_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	e_btn_bgo.SetSkin(IDB_E_BGO, IDB_E_BGO, IDB_E_BGO_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	e_btn_bgp.SetSkin(IDB_E_BGP, IDB_E_BGP, IDB_E_BGP_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	e_btn_bga.SetSkin(IDB_E_BGA, IDB_E_BGA, IDB_E_BGA_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	e_btn_bgs.SetSkin(IDB_E_BGS, IDB_E_BGS, IDB_E_BGS_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	e_btn_bgd.SetSkin(IDB_E_BGD, IDB_E_BGD, IDB_E_BGD_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	e_btn_bgf.SetSkin(IDB_E_BGF, IDB_E_BGF, IDB_E_BGF_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	e_btn_bgg.SetSkin(IDB_E_BGG, IDB_E_BGG, IDB_E_BGG_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	e_btn_bgh.SetSkin(IDB_E_BGH, IDB_E_BGH, IDB_E_BGH_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	e_btn_bgj.SetSkin(IDB_E_BGJ, IDB_E_BGJ, IDB_E_BGJ_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	e_btn_bgk.SetSkin(IDB_E_BGK, IDB_E_BGK, IDB_E_BGK_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	e_btn_bgl.SetSkin(IDB_E_BGL, IDB_E_BGL, IDB_E_BGL_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	e_btn_bgz.SetSkin(IDB_E_BGZ, IDB_E_BGZ, IDB_E_BGZ_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	e_btn_bgx.SetSkin(IDB_E_BGX, IDB_E_BGX, IDB_E_BGX_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	e_btn_bgc.SetSkin(IDB_E_BGC, IDB_E_BGC, IDB_E_BGC_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	e_btn_bgv.SetSkin(IDB_E_BGV, IDB_E_BGV, IDB_E_BGV_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	e_btn_bgb.SetSkin(IDB_E_BGB, IDB_E_BGB, IDB_E_BGB_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	e_btn_bgn.SetSkin(IDB_E_BGN, IDB_E_BGN, IDB_E_BGN_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	e_btn_bgm.SetSkin(IDB_E_BGM, IDB_E_BGM, IDB_E_BGM_OVER, 0, 0, IDB_MASK, 1, 0, 4);
}

// 특수문자 버튼 이미지 삽입
void SelectKeyboardDlg::SetImgSpecialBtn()
{
	// 특수문자 버튼 스킨 씌우기
	p_btn_exc.SetSkin(IDB_P_EXC, IDB_P_EXC, IDB_P_EXC_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	p_btn_gol.SetSkin(IDB_P_GOL, IDB_P_GOL, IDB_P_GOL_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	p_btn_shp.SetSkin(IDB_P_SHP, IDB_P_SHP, IDB_P_SHP_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	p_btn_dol.SetSkin(IDB_P_DOL, IDB_P_DOL, IDB_P_DOL_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	p_btn_per.SetSkin(IDB_P_PER, IDB_P_PER, IDB_P_PER_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	p_btn_cir.SetSkin(IDB_P_CIR, IDB_P_CIR, IDB_P_CIR_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	p_btn_and.SetSkin(IDB_P_AND, IDB_P_AND, IDB_P_AND_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	p_btn_ast.SetSkin(IDB_P_AST, IDB_P_AST, IDB_P_AST_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	p_btn_osg.SetSkin(IDB_P_OSG, IDB_P_OSG, IDB_P_OSG_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	p_btn_csg.SetSkin(IDB_P_CSG, IDB_P_CSG, IDB_P_CSG_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	p_btn_wav.SetSkin(IDB_P_WAV, IDB_P_WAV, IDB_P_WAV_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	p_btn_hyp.SetSkin(IDB_P_HYP, IDB_P_HYP, IDB_P_HYP_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	p_btn_eql.SetSkin(IDB_P_EQL, IDB_P_EQL, IDB_P_EQL_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	p_btn_pls.SetSkin(IDB_P_PLS, IDB_P_PLS, IDB_P_PLS_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	p_btn_odg.SetSkin(IDB_P_ODG, IDB_P_ODG, IDB_P_ODG_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	p_btn_cdg.SetSkin(IDB_P_CDG, IDB_P_CDG, IDB_P_CDG_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	p_btn_okg.SetSkin(IDB_P_OKG, IDB_P_OKG, IDB_P_OKG_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	p_btn_ckg.SetSkin(IDB_P_CKG, IDB_P_CKG, IDB_P_CKG_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	p_btn_qst.SetSkin(IDB_P_QST, IDB_P_QST, IDB_P_QST_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	p_btn_col.SetSkin(IDB_P_COL, IDB_P_COL, IDB_P_COL_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	p_btn_scl.SetSkin(IDB_P_SCL, IDB_P_SCL, IDB_P_SCL_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	p_btn_sdd.SetSkin(IDB_P_SDD, IDB_P_SDD, IDB_P_SDD_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	p_btn_bdd.SetSkin(IDB_P_BDD, IDB_P_BDD, IDB_P_BDD_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	p_btn_bsl.SetSkin(IDB_P_BSL, IDB_P_BSL, IDB_P_BSL_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	p_btn_sls.SetSkin(IDB_P_SLS, IDB_P_SLS, IDB_P_SLS_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	p_btn_cmm.SetSkin(IDB_P_CMM, IDB_P_CMM, IDB_P_CMM_OVER, 0, 0, IDB_MASK, 1, 0, 4);

}

void SelectKeyboardDlg::SetPosBtn()
{
	// 시스템, 한글 버튼 좌표 및 크기 설정
	for (int y = 0; y < 6; y++)
		for (int x = 0; x < 10; x++)
		{
			// 리소스 순서를 받기 위한 변수
			int order = 2000 + (10 * y) + x;

			// 대화상자 부분은 생략
			if (order > 2010 && order < 2018)	continue;
			else if (order > 2020 && order < 2028)	continue;

			// 스페이스 처리
			else if (order == 2054)
				GetDlgItem(order)->SetWindowPos(NULL, ButtonSize.cx * x, ButtonSize.cy * y, ButtonSize.cx * 2, ButtonSize.cy, SWP_NOZORDER);
			else if (order == 2055)	continue;

			// 예외사항 아닐 경우 x, y 좌표에 버튼 크기 만큼 출력
			else
				GetDlgItem(order)->SetWindowPos(NULL, ButtonSize.cx * x, ButtonSize.cy * y, ButtonSize.cx, ButtonSize.cy, SWP_NOZORDER);
		}
	// IDC_MAINEDIT 크기, 위치 변경
	GetDlgItem(IDC_MAINEDIT)->SetWindowPos(NULL, ButtonSize.cx * 1, ButtonSize.cy * 1, ButtonSize.cx * 7, ButtonSize.cy * 2, SWP_NOZORDER);
	

	// 영어 소문자 버튼 좌표 및 크기 설정	
	for (int y = 3; y < 6; y++)
		for (int x = 0; x < 10; x++)
		{
			// 리소스 순서를 받기 위한 변수
			int order = 2030 + (10 * y) + x;

			// 스페이스바 생략
			if (order == 2084 || order == 2085)	continue;

			// 마침표 생략
			else if (order == 2089)	continue;

			// 예외사항 아닐 경우 x, y 좌표에 버튼 크기 만큼 출력
			else
				GetDlgItem(order)->SetWindowPos(NULL, ButtonSize.cx * x, ButtonSize.cy * y, ButtonSize.cx, ButtonSize.cy, SWP_NOZORDER);
		}

	// 영어 대문자 버튼 좌표 및 크기 설정	
	for (int y = 3; y < 6; y++)
		for (int x = 0; x < 10; x++)
		{
			// 리소스 순서를 받기 위한 변수
			int order = 2090 + (10 * y) + x;

			// 스페이스바 생략
			if (order == 2144 || order == 2145)	continue;

			else if(order == 2139)	continue;

			// 마침표 생략
			else if (order == 2149)	continue;

			// 예외사항 아닐 경우 x, y 좌표에 버튼 크기 만큼 출력
			else
				GetDlgItem(order)->SetWindowPos(NULL, ButtonSize.cx * x, ButtonSize.cy * y, ButtonSize.cx, ButtonSize.cy, SWP_NOZORDER);
		}

	// 특수문자 버튼 좌표 및 크기 설정	
	for (int y = 3; y < 6; y++)
		for (int x = 0; x < 10; x++)
		{
			// 리소스 순서를 받기 위한 변수
			int order = 2060 + (10 * y) + x;

			// 한, 영 키 생략
			if (order == 2109)	continue;

			// 스페이스바 생략
			else if (order == 2114 || order == 2115)	continue;

			// 마침표 생략
			else if (order == 2119)	continue;

			// 예외사항 아닐 경우 x, y 좌표에 버튼 크기 만큼 출력
			else
				GetDlgItem(order)->SetWindowPos(NULL, ButtonSize.cx * x, ButtonSize.cy * y, ButtonSize.cx, ButtonSize.cy, SWP_NOZORDER);
		}
}

void SelectKeyboardDlg::ShowKorBtn()
{
	GetDlgItem(IDC_K_BIE)->ShowWindow(TRUE);
	GetDlgItem(IDC_K_JIE)->ShowWindow(TRUE);
	GetDlgItem(IDC_K_DIG)->ShowWindow(TRUE);
	GetDlgItem(IDC_K_GIY)->ShowWindow(TRUE);
	GetDlgItem(IDC_K_SHI)->ShowWindow(TRUE);
	GetDlgItem(IDC_K_YYO)->ShowWindow(TRUE);
	GetDlgItem(IDC_K_YEO)->ShowWindow(TRUE);
	GetDlgItem(IDC_K_YYA)->ShowWindow(TRUE);
	GetDlgItem(IDC_K_AEE)->ShowWindow(TRUE);
	GetDlgItem(IDC_K_EEE)->ShowWindow(TRUE);
	GetDlgItem(IDC_K_MIE)->ShowWindow(TRUE);
	GetDlgItem(IDC_K_NIE)->ShowWindow(TRUE);
	GetDlgItem(IDC_K_IEU)->ShowWindow(TRUE);
	GetDlgItem(IDC_K_RIE)->ShowWindow(TRUE);
	GetDlgItem(IDC_K_HIE)->ShowWindow(TRUE);
	GetDlgItem(IDC_K_OOO)->ShowWindow(TRUE);
	GetDlgItem(IDC_K_EOO)->ShowWindow(TRUE);
	GetDlgItem(IDC_K_AAA)->ShowWindow(TRUE);
	GetDlgItem(IDC_K_YII)->ShowWindow(TRUE);
	GetDlgItem(IDC_K_KIE)->ShowWindow(TRUE);
	GetDlgItem(IDC_K_TIE)->ShowWindow(TRUE);
	GetDlgItem(IDC_K_CHI)->ShowWindow(TRUE);
	GetDlgItem(IDC_K_PIE)->ShowWindow(TRUE);
	GetDlgItem(IDC_K_YUU)->ShowWindow(TRUE);
	GetDlgItem(IDC_K_UUU)->ShowWindow(TRUE);
	GetDlgItem(IDC_K_EUU)->ShowWindow(TRUE);
	GetDlgItem(IDC_S_ENG)->ShowWindow(TRUE);
}

void SelectKeyboardDlg::HideKorBtn()
{
	GetDlgItem(IDC_K_BIE)->ShowWindow(FALSE);
	GetDlgItem(IDC_K_JIE)->ShowWindow(FALSE);
	GetDlgItem(IDC_K_DIG)->ShowWindow(FALSE);
	GetDlgItem(IDC_K_GIY)->ShowWindow(FALSE);
	GetDlgItem(IDC_K_SHI)->ShowWindow(FALSE);
	GetDlgItem(IDC_K_YYO)->ShowWindow(FALSE);
	GetDlgItem(IDC_K_YEO)->ShowWindow(FALSE);
	GetDlgItem(IDC_K_YYA)->ShowWindow(FALSE);
	GetDlgItem(IDC_K_AEE)->ShowWindow(FALSE);
	GetDlgItem(IDC_K_EEE)->ShowWindow(FALSE);
	GetDlgItem(IDC_K_MIE)->ShowWindow(FALSE);
	GetDlgItem(IDC_K_NIE)->ShowWindow(FALSE);
	GetDlgItem(IDC_K_IEU)->ShowWindow(FALSE);
	GetDlgItem(IDC_K_RIE)->ShowWindow(FALSE);
	GetDlgItem(IDC_K_HIE)->ShowWindow(FALSE);
	GetDlgItem(IDC_K_OOO)->ShowWindow(FALSE);
	GetDlgItem(IDC_K_EOO)->ShowWindow(FALSE);
	GetDlgItem(IDC_K_AAA)->ShowWindow(FALSE);
	GetDlgItem(IDC_K_YII)->ShowWindow(FALSE);
	GetDlgItem(IDC_K_KIE)->ShowWindow(FALSE);
	GetDlgItem(IDC_K_TIE)->ShowWindow(FALSE);
	GetDlgItem(IDC_K_CHI)->ShowWindow(FALSE);
	GetDlgItem(IDC_K_PIE)->ShowWindow(FALSE);
	GetDlgItem(IDC_K_YUU)->ShowWindow(FALSE);
	GetDlgItem(IDC_K_UUU)->ShowWindow(FALSE);
	GetDlgItem(IDC_K_EUU)->ShowWindow(FALSE);
	GetDlgItem(IDC_S_ENG)->ShowWindow(FALSE);
}

void SelectKeyboardDlg::ShowSmallEngBtn()
{

	GetDlgItem(IDC_E_SMQ)->ShowWindow(TRUE);
	GetDlgItem(IDC_E_SMW)->ShowWindow(TRUE);
	GetDlgItem(IDC_E_SME)->ShowWindow(TRUE);
	GetDlgItem(IDC_E_SMR)->ShowWindow(TRUE);
	GetDlgItem(IDC_E_SMT)->ShowWindow(TRUE);
	GetDlgItem(IDC_E_SMY)->ShowWindow(TRUE);
	GetDlgItem(IDC_E_SMU)->ShowWindow(TRUE);
	GetDlgItem(IDC_E_SMI)->ShowWindow(TRUE);
	GetDlgItem(IDC_E_SMO)->ShowWindow(TRUE);
	GetDlgItem(IDC_E_SMP)->ShowWindow(TRUE);
	GetDlgItem(IDC_E_SMA)->ShowWindow(TRUE);
	GetDlgItem(IDC_E_SMS)->ShowWindow(TRUE);
	GetDlgItem(IDC_E_SMD)->ShowWindow(TRUE);
	GetDlgItem(IDC_E_SMF)->ShowWindow(TRUE);
	GetDlgItem(IDC_E_SMG)->ShowWindow(TRUE);
	GetDlgItem(IDC_E_SMH)->ShowWindow(TRUE);
	GetDlgItem(IDC_E_SMJ)->ShowWindow(TRUE);
	GetDlgItem(IDC_E_SMK)->ShowWindow(TRUE);
	GetDlgItem(IDC_E_SML)->ShowWindow(TRUE);
	GetDlgItem(IDC_E_SMZ)->ShowWindow(TRUE);
	GetDlgItem(IDC_E_SMX)->ShowWindow(TRUE);
	GetDlgItem(IDC_E_SMC)->ShowWindow(TRUE);
	GetDlgItem(IDC_E_SMV)->ShowWindow(TRUE);
	GetDlgItem(IDC_E_SMB)->ShowWindow(TRUE);
	GetDlgItem(IDC_E_SMN)->ShowWindow(TRUE);
	GetDlgItem(IDC_E_SMM)->ShowWindow(TRUE);
	GetDlgItem(IDC_S_KOR)->ShowWindow(TRUE);
}

void SelectKeyboardDlg::HideSmallEngBtn()
{

	GetDlgItem(IDC_E_SMQ)->ShowWindow(FALSE);
	GetDlgItem(IDC_E_SMW)->ShowWindow(FALSE);
	GetDlgItem(IDC_E_SME)->ShowWindow(FALSE);
	GetDlgItem(IDC_E_SMR)->ShowWindow(FALSE);
	GetDlgItem(IDC_E_SMT)->ShowWindow(FALSE);
	GetDlgItem(IDC_E_SMY)->ShowWindow(FALSE);
	GetDlgItem(IDC_E_SMU)->ShowWindow(FALSE);
	GetDlgItem(IDC_E_SMI)->ShowWindow(FALSE);
	GetDlgItem(IDC_E_SMO)->ShowWindow(FALSE);
	GetDlgItem(IDC_E_SMP)->ShowWindow(FALSE);
	GetDlgItem(IDC_E_SMA)->ShowWindow(FALSE);
	GetDlgItem(IDC_E_SMS)->ShowWindow(FALSE);
	GetDlgItem(IDC_E_SMD)->ShowWindow(FALSE);
	GetDlgItem(IDC_E_SMF)->ShowWindow(FALSE);
	GetDlgItem(IDC_E_SMG)->ShowWindow(FALSE);
	GetDlgItem(IDC_E_SMH)->ShowWindow(FALSE);
	GetDlgItem(IDC_E_SMJ)->ShowWindow(FALSE);
	GetDlgItem(IDC_E_SMK)->ShowWindow(FALSE);
	GetDlgItem(IDC_E_SML)->ShowWindow(FALSE);
	GetDlgItem(IDC_E_SMZ)->ShowWindow(FALSE);
	GetDlgItem(IDC_E_SMX)->ShowWindow(FALSE);
	GetDlgItem(IDC_E_SMC)->ShowWindow(FALSE);
	GetDlgItem(IDC_E_SMV)->ShowWindow(FALSE);
	GetDlgItem(IDC_E_SMB)->ShowWindow(FALSE);
	GetDlgItem(IDC_E_SMN)->ShowWindow(FALSE);
	GetDlgItem(IDC_E_SMM)->ShowWindow(FALSE);
	GetDlgItem(IDC_S_KOR)->ShowWindow(FALSE);
}

void SelectKeyboardDlg::ShowBigEngBtn()
{

	GetDlgItem(IDC_E_BGQ)->ShowWindow(TRUE);
	GetDlgItem(IDC_E_BGW)->ShowWindow(TRUE);
	GetDlgItem(IDC_E_BGE)->ShowWindow(TRUE);
	GetDlgItem(IDC_E_BGR)->ShowWindow(TRUE);
	GetDlgItem(IDC_E_BGT)->ShowWindow(TRUE);
	GetDlgItem(IDC_E_BGY)->ShowWindow(TRUE);
	GetDlgItem(IDC_E_BGU)->ShowWindow(TRUE);
	GetDlgItem(IDC_E_BGI)->ShowWindow(TRUE);
	GetDlgItem(IDC_E_BGO)->ShowWindow(TRUE);
	GetDlgItem(IDC_E_BGP)->ShowWindow(TRUE);
	GetDlgItem(IDC_E_BGA)->ShowWindow(TRUE);
	GetDlgItem(IDC_E_BGS)->ShowWindow(TRUE);
	GetDlgItem(IDC_E_BGD)->ShowWindow(TRUE);
	GetDlgItem(IDC_E_BGF)->ShowWindow(TRUE);
	GetDlgItem(IDC_E_BGG)->ShowWindow(TRUE);
	GetDlgItem(IDC_E_BGH)->ShowWindow(TRUE);
	GetDlgItem(IDC_E_BGJ)->ShowWindow(TRUE);
	GetDlgItem(IDC_E_BGK)->ShowWindow(TRUE);
	GetDlgItem(IDC_E_BGL)->ShowWindow(TRUE);
	GetDlgItem(IDC_E_BGZ)->ShowWindow(TRUE);
	GetDlgItem(IDC_E_BGX)->ShowWindow(TRUE);
	GetDlgItem(IDC_E_BGC)->ShowWindow(TRUE);
	GetDlgItem(IDC_E_BGV)->ShowWindow(TRUE);
	GetDlgItem(IDC_E_BGB)->ShowWindow(TRUE);
	GetDlgItem(IDC_E_BGN)->ShowWindow(TRUE);
	GetDlgItem(IDC_E_BGM)->ShowWindow(TRUE);
	GetDlgItem(IDC_S_KOR)->ShowWindow(TRUE);
}

void SelectKeyboardDlg::HideBigEngBtn()
{

	GetDlgItem(IDC_E_BGQ)->ShowWindow(FALSE);
	GetDlgItem(IDC_E_BGW)->ShowWindow(FALSE);
	GetDlgItem(IDC_E_BGE)->ShowWindow(FALSE);
	GetDlgItem(IDC_E_BGR)->ShowWindow(FALSE);
	GetDlgItem(IDC_E_BGT)->ShowWindow(FALSE);
	GetDlgItem(IDC_E_BGY)->ShowWindow(FALSE);
	GetDlgItem(IDC_E_BGU)->ShowWindow(FALSE);
	GetDlgItem(IDC_E_BGI)->ShowWindow(FALSE);
	GetDlgItem(IDC_E_BGO)->ShowWindow(FALSE);
	GetDlgItem(IDC_E_BGP)->ShowWindow(FALSE);
	GetDlgItem(IDC_E_BGA)->ShowWindow(FALSE);
	GetDlgItem(IDC_E_BGS)->ShowWindow(FALSE);
	GetDlgItem(IDC_E_BGD)->ShowWindow(FALSE);
	GetDlgItem(IDC_E_BGF)->ShowWindow(FALSE);
	GetDlgItem(IDC_E_BGG)->ShowWindow(FALSE);
	GetDlgItem(IDC_E_BGH)->ShowWindow(FALSE);
	GetDlgItem(IDC_E_BGJ)->ShowWindow(FALSE);
	GetDlgItem(IDC_E_BGK)->ShowWindow(FALSE);
	GetDlgItem(IDC_E_BGL)->ShowWindow(FALSE);
	GetDlgItem(IDC_E_BGZ)->ShowWindow(FALSE);
	GetDlgItem(IDC_E_BGX)->ShowWindow(FALSE);
	GetDlgItem(IDC_E_BGC)->ShowWindow(FALSE);
	GetDlgItem(IDC_E_BGV)->ShowWindow(FALSE);
	GetDlgItem(IDC_E_BGB)->ShowWindow(FALSE);
	GetDlgItem(IDC_E_BGN)->ShowWindow(FALSE);
	GetDlgItem(IDC_E_BGM)->ShowWindow(FALSE);
	GetDlgItem(IDC_S_KOR)->ShowWindow(FALSE);
}

void SelectKeyboardDlg::ShowSpecialBtn()
{
	GetDlgItem(IDC_P_EXC)->ShowWindow(TRUE);
	GetDlgItem(IDC_P_GOL)->ShowWindow(TRUE);
	GetDlgItem(IDC_P_SHP)->ShowWindow(TRUE);
	GetDlgItem(IDC_P_DOL)->ShowWindow(TRUE);
	GetDlgItem(IDC_P_PER)->ShowWindow(TRUE);
	GetDlgItem(IDC_P_CIR)->ShowWindow(TRUE);
	GetDlgItem(IDC_P_AND)->ShowWindow(TRUE);
	GetDlgItem(IDC_P_AST)->ShowWindow(TRUE);
	GetDlgItem(IDC_P_OSG)->ShowWindow(TRUE);
	GetDlgItem(IDC_P_CSG)->ShowWindow(TRUE);
	GetDlgItem(IDC_P_WAV)->ShowWindow(TRUE);
	GetDlgItem(IDC_P_HYP)->ShowWindow(TRUE);
	GetDlgItem(IDC_P_EQL)->ShowWindow(TRUE);
	GetDlgItem(IDC_P_PLS)->ShowWindow(TRUE);
	GetDlgItem(IDC_P_ODG)->ShowWindow(TRUE);
	GetDlgItem(IDC_P_CDG)->ShowWindow(TRUE);
	GetDlgItem(IDC_P_OKG)->ShowWindow(TRUE);
	GetDlgItem(IDC_P_CKG)->ShowWindow(TRUE);
	GetDlgItem(IDC_P_QST)->ShowWindow(TRUE);
	GetDlgItem(IDC_P_COL)->ShowWindow(TRUE);
	GetDlgItem(IDC_P_SCL)->ShowWindow(TRUE);
	GetDlgItem(IDC_P_SDD)->ShowWindow(TRUE);
	GetDlgItem(IDC_P_BDD)->ShowWindow(TRUE);
	GetDlgItem(IDC_P_BSL)->ShowWindow(TRUE);
	GetDlgItem(IDC_P_SLS)->ShowWindow(TRUE);
	GetDlgItem(IDC_P_CMM)->ShowWindow(TRUE);
}

void SelectKeyboardDlg::HideSpecialBtn()
{
	GetDlgItem(IDC_P_EXC)->ShowWindow(FALSE);
	GetDlgItem(IDC_P_GOL)->ShowWindow(FALSE);
	GetDlgItem(IDC_P_SHP)->ShowWindow(FALSE);
	GetDlgItem(IDC_P_DOL)->ShowWindow(FALSE);
	GetDlgItem(IDC_P_PER)->ShowWindow(FALSE);
	GetDlgItem(IDC_P_CIR)->ShowWindow(FALSE);
	GetDlgItem(IDC_P_AND)->ShowWindow(FALSE);
	GetDlgItem(IDC_P_AST)->ShowWindow(FALSE);
	GetDlgItem(IDC_P_OSG)->ShowWindow(FALSE);
	GetDlgItem(IDC_P_CSG)->ShowWindow(FALSE);
	GetDlgItem(IDC_P_WAV)->ShowWindow(FALSE);
	GetDlgItem(IDC_P_HYP)->ShowWindow(FALSE);
	GetDlgItem(IDC_P_EQL)->ShowWindow(FALSE);
	GetDlgItem(IDC_P_PLS)->ShowWindow(FALSE);
	GetDlgItem(IDC_P_ODG)->ShowWindow(FALSE);
	GetDlgItem(IDC_P_CDG)->ShowWindow(FALSE);
	GetDlgItem(IDC_P_OKG)->ShowWindow(FALSE);
	GetDlgItem(IDC_P_CKG)->ShowWindow(FALSE);
	GetDlgItem(IDC_P_QST)->ShowWindow(FALSE);
	GetDlgItem(IDC_P_COL)->ShowWindow(FALSE);
	GetDlgItem(IDC_P_SCL)->ShowWindow(FALSE);
	GetDlgItem(IDC_P_SDD)->ShowWindow(FALSE);
	GetDlgItem(IDC_P_BDD)->ShowWindow(FALSE);
	GetDlgItem(IDC_P_BSL)->ShowWindow(FALSE);
	GetDlgItem(IDC_P_SLS)->ShowWindow(FALSE);
	GetDlgItem(IDC_P_CMM)->ShowWindow(FALSE);
}


int GetFindCharCount(CString parm_string, char parm_find_char)
// 문자열에 어떤 문자가 몇 개 들어 있는지
{

	int length = parm_string.GetLength(), find_count = 0;

	for (int i = 0; i < length; i++)
	{
		if (parm_string[i] == parm_find_char)
		{
			find_count++;
		}
	}

	return find_count;
}

void SelectKeyboardDlg::InputHangeul(int textCode)
{
	hangeulInput.SetHangeulCode(textCode);
	
	CString complete_text = hangeulInput.completeText;

	if (hangeulInput.ingWord != NULL)
		complete_text += hangeulInput.ingWord;


	SetDlgItemText(IDC_MAINEDIT, complete_text); // mainEdit에 띄움

	CString sub_text;
	int cut = GetFindCharCount(complete_text, ' '); // 스페이스바가 몇 개 있는지 찾아서
	AfxExtractSubString(sub_text, complete_text, cut, ' '); // 마지막 스페이스로부터 문자열을 잘라냄
	SetDlgItemText(IDC_SUBEDIT, sub_text); // subEdit에 띄움
	
	CEdit * pEdit = ((CEdit*)GetDlgItem(IDC_MAINEDIT));
	pEdit->SetSel(pEdit->GetWindowTextLength(), pEdit->GetWindowTextLength());
	pEdit->SetFocus();
	
}

void SelectKeyboardDlg::InputText(CString text)
{
	hangeulInput.completeText += text;

	CString complete_text = hangeulInput.completeText;

	if (hangeulInput.ingWord != NULL)
		complete_text += hangeulInput.ingWord;

	SetDlgItemText(IDC_MAINEDIT, complete_text);

	CString sub_text;
	int cut = GetFindCharCount(complete_text, ' ');
	AfxExtractSubString(sub_text, complete_text, cut, ' ');
	SetDlgItemText(IDC_SUBEDIT, sub_text);


	CEdit * pEdit = ((CEdit*)GetDlgItem(IDC_MAINEDIT));
	pEdit->SetSel(pEdit->GetWindowTextLength(), pEdit->GetWindowTextLength());
	pEdit->SetFocus();

}





// 각 버튼 클릭 함수
void SelectKeyboardDlg::OnBtnClick(UINT uiID)
{
	switch (uiID)
	{
	case IDC_N_ONE:
	{
		if (hangeulInput.ingWord != NULL)
			InputHangeul(-1);
		if (clickedShift)
			InputText(_T("!"));
		else
			InputText(_T("1"));

		GetDlgItem(IDC_SUBEDIT)->SetWindowPos(&wndTop, ButtonSize.cx * 0, ButtonSize.cy * 0.8, ButtonSize.cx * 1, ButtonSize.cy * 0.2, NULL);

		break;
	}
	case IDC_N_TWO:
	{
		if (hangeulInput.ingWord != NULL)
			InputHangeul(-1);
		if (clickedShift)
			InputText(_T("@"));
		else
			InputText(_T("2"));

		GetDlgItem(IDC_SUBEDIT)->SetWindowPos(&wndTop, ButtonSize.cx * 1, ButtonSize.cy * 0.8, ButtonSize.cx * 1, ButtonSize.cy * 0.2, NULL);

		break;
	}
	case IDC_N_THR:
	{
		if (hangeulInput.ingWord != NULL)
			InputHangeul(-1);
		if (clickedShift)
			InputText(_T("#"));
		else
			InputText(_T("3"));

		GetDlgItem(IDC_SUBEDIT)->SetWindowPos(&wndTop, ButtonSize.cx * 2, ButtonSize.cy * 0.8, ButtonSize.cx * 1, ButtonSize.cy * 0.2, NULL);

		break;
	}
	case IDC_N_FOU:
	{
		if (hangeulInput.ingWord != NULL)
			InputHangeul(-1);
		if (clickedShift)
			InputText(_T("$"));
		else
			InputText(_T("4"));

		GetDlgItem(IDC_SUBEDIT)->SetWindowPos(&wndTop, ButtonSize.cx * 3, ButtonSize.cy * 0.8, ButtonSize.cx * 1, ButtonSize.cy * 0.2, NULL);

		break;
	}
	case IDC_N_FIV:
	{
		if (hangeulInput.ingWord != NULL)
			InputHangeul(-1);
		if (clickedShift)
			InputText(_T("%"));
		else
			InputText(_T("5"));
		
		GetDlgItem(IDC_SUBEDIT)->SetWindowPos(&wndTop, ButtonSize.cx * 4, ButtonSize.cy * 0.8, ButtonSize.cx * 1, ButtonSize.cy * 0.2, NULL);

		break;
	}
	case IDC_N_SIX:
	{
		if (hangeulInput.ingWord != NULL)
			InputHangeul(-1);
		if (clickedShift)
			InputText(_T("^"));
		else
			InputText(_T("6"));
		
		GetDlgItem(IDC_SUBEDIT)->SetWindowPos(&wndTop, ButtonSize.cx * 5, ButtonSize.cy * 0.8, ButtonSize.cx * 1, ButtonSize.cy * 0.2, NULL);

		break;
	}
	case IDC_N_SEV:
	{
		if (hangeulInput.ingWord != NULL)
			InputHangeul(-1);
		if (clickedShift)
			InputText(_T("&"));
		else
			InputText(_T("7"));

		GetDlgItem(IDC_SUBEDIT)->SetWindowPos(&wndTop, ButtonSize.cx * 6, ButtonSize.cy * 0.8, ButtonSize.cx * 1, ButtonSize.cy * 0.2, NULL);

		break;
	}
	case IDC_N_EIG:
	{
		if (hangeulInput.ingWord != NULL)
			InputHangeul(-1);
		if (clickedShift)
			InputText(_T("*"));
		else
			InputText(_T("8"));
	
		GetDlgItem(IDC_SUBEDIT)->SetWindowPos(&wndTop, ButtonSize.cx * 7, ButtonSize.cy * 0.8, ButtonSize.cx * 1, ButtonSize.cy * 0.2, NULL);

		break;
	}
	case IDC_N_NIN:
	{
		if (hangeulInput.ingWord != NULL)
			InputHangeul(-1);

		if (clickedShift)
			InputText(_T("("));
		else
			InputText(_T("9"));

		GetDlgItem(IDC_SUBEDIT)->SetWindowPos(&wndTop, ButtonSize.cx * 8, ButtonSize.cy * 0.8, ButtonSize.cx * 1, ButtonSize.cy * 0.2, NULL);

		break;
	}
	case IDC_N_ZER:
	{
		if (hangeulInput.ingWord != NULL)
			InputHangeul(-1);
		
		if (clickedShift)
			InputText(_T(")"));
		else
			InputText(_T("0"));
		
		GetDlgItem(IDC_SUBEDIT)->SetWindowPos(&wndTop, ButtonSize.cx * 9, ButtonSize.cy * 0.8, ButtonSize.cx * 1, ButtonSize.cy * 0.2, NULL);

		break;
	}
	case IDC_S_BKS: // backspace
	{
		InputHangeul(-3);

		GetDlgItem(IDC_SUBEDIT)->SetWindowPos(&wndTop, ButtonSize.cx * 8, ButtonSize.cy * 1.8, ButtonSize.cx * 1, ButtonSize.cy * 0.2, NULL);
		
		break;
	}
	case IDC_S_SPE: // 특수문자
	{
		ShowSpecialBtn();
		HideSmallEngBtn();
		HideBigEngBtn();
		HideKorBtn();
		GetDlgItem(IDC_S_KOR)->ShowWindow(TRUE);
		break;
	}
	case IDC_S_SHF: // shift
	{
		clickedShift = !clickedShift;

		break;
	}
	case IDC_S_ENT: // enter
	{
		InputHangeul(-2);

		CString sub_text;
		sub_text = "";
		SetDlgItemText(IDC_SUBEDIT, sub_text);

		break;
	}
	case IDC_S_CON: // 확인
	{
		// 전송하는거..
		//일단 종료되게...
		::SendMessage(GetSafeHwnd(), WM_CLOSE, NULL, NULL);
		break;
	}
	case IDC_K_BIE: // ㅂ
	{
		if (clickedShift)
			InputHangeul(8);
		else
			InputHangeul(7);

		GetDlgItem(IDC_SUBEDIT)->SetWindowPos(&wndTop, ButtonSize.cx * 0, ButtonSize.cy * 3.8, ButtonSize.cx * 1, ButtonSize.cy * 0.2, NULL);

		break;
	}
	case IDC_K_JIE: // ㅈ
	{
		if (clickedShift)
			InputHangeul(13);
		else
			InputHangeul(12);
		
		GetDlgItem(IDC_SUBEDIT)->SetWindowPos(&wndTop, ButtonSize.cx * 1, ButtonSize.cy * 3.8, ButtonSize.cx * 1, ButtonSize.cy * 0.2, NULL);

		break;
	}
	case IDC_K_DIG: // ㄷ
	{
		if (clickedShift)
			InputHangeul(4);
		else
			InputHangeul(3);
		
		GetDlgItem(IDC_SUBEDIT)->SetWindowPos(&wndTop, ButtonSize.cx * 2, ButtonSize.cy * 3.8, ButtonSize.cx * 1, ButtonSize.cy * 0.2, NULL);

		break;
	}
	case IDC_K_GIY: // ㄱ
	{
		if (clickedShift)
			InputHangeul(1);
		else
			InputHangeul(0);
		
		GetDlgItem(IDC_SUBEDIT)->SetWindowPos(&wndTop, ButtonSize.cx * 3, ButtonSize.cy * 3.8, ButtonSize.cx * 1, ButtonSize.cy * 0.2, NULL);

		break;
	}
	case IDC_K_SHI: // ㅅ
	{
		if (clickedShift)
			InputHangeul(10);
		else
			InputHangeul(9);
		
		GetDlgItem(IDC_SUBEDIT)->SetWindowPos(&wndTop, ButtonSize.cx * 4, ButtonSize.cy * 3.8, ButtonSize.cx * 1, ButtonSize.cy * 0.2, NULL);

		break;
	}
	case IDC_K_YYO: // ㅛ
	{
		InputHangeul(31);
		
		GetDlgItem(IDC_SUBEDIT)->SetWindowPos(&wndTop, ButtonSize.cx * 5, ButtonSize.cy * 3.8, ButtonSize.cx * 1, ButtonSize.cy * 0.2, NULL);

		break;
	}
	case IDC_K_YEO: // ㅕ
	{
		InputHangeul(25);
		
		GetDlgItem(IDC_SUBEDIT)->SetWindowPos(&wndTop, ButtonSize.cx * 6, ButtonSize.cy * 3.8, ButtonSize.cx * 1, ButtonSize.cy * 0.2, NULL);

		break;
	}
	case IDC_K_YYA: // ㅑ
	{
		InputHangeul(21);
		
		GetDlgItem(IDC_SUBEDIT)->SetWindowPos(&wndTop, ButtonSize.cx * 7, ButtonSize.cy * 3.8, ButtonSize.cx * 1, ButtonSize.cy * 0.2, NULL);

		break;
	}
	case IDC_K_AEE: // ㅐ
	{
		if (clickedShift)
			InputHangeul(22);
		else
			InputHangeul(20);
		

		GetDlgItem(IDC_SUBEDIT)->SetWindowPos(&wndTop, ButtonSize.cx * 8, ButtonSize.cy * 3.8, ButtonSize.cx * 1, ButtonSize.cy * 0.2, NULL);
		break;
	}
	case IDC_K_EEE: // ㅔ
	{
		if (clickedShift)
			InputHangeul(26);
		else
			InputHangeul(24);

		GetDlgItem(IDC_SUBEDIT)->SetWindowPos(&wndTop, ButtonSize.cx * 9, ButtonSize.cy * 3.8, ButtonSize.cx * 1, ButtonSize.cy * 0.2, NULL);
		break;
	}
 // 한글 첫째줄 끝

	case IDC_K_MIE: // ㅁ
	{
		InputHangeul(6);
		
		GetDlgItem(IDC_SUBEDIT)->SetWindowPos(&wndTop, ButtonSize.cx * 0, ButtonSize.cy * 4.8, ButtonSize.cx * 1, ButtonSize.cy * 0.2, NULL);

		break;
	}
	case IDC_K_NIE: // ㄴ
	{
		InputHangeul(2);
		
		GetDlgItem(IDC_SUBEDIT)->SetWindowPos(&wndTop, ButtonSize.cx * 1, ButtonSize.cy * 4.8, ButtonSize.cx * 1, ButtonSize.cy * 0.2, NULL);

		break;
	}
	case IDC_K_IEU: //ㅇ
	{
		InputHangeul(11);
		
		GetDlgItem(IDC_SUBEDIT)->SetWindowPos(&wndTop, ButtonSize.cx * 2, ButtonSize.cy * 4.8, ButtonSize.cx * 1, ButtonSize.cy * 0.2, NULL);

		break;
	}
	case IDC_K_RIE: //ㄹ
	{
		InputHangeul(5);
		
		GetDlgItem(IDC_SUBEDIT)->SetWindowPos(&wndTop, ButtonSize.cx * 3, ButtonSize.cy * 4.8, ButtonSize.cx * 1, ButtonSize.cy * 0.2, NULL);

		break;
	}
	case IDC_K_HIE: // ㅎ
	{
		InputHangeul(18);
		
		GetDlgItem(IDC_SUBEDIT)->SetWindowPos(&wndTop, ButtonSize.cx * 4, ButtonSize.cy * 4.8, ButtonSize.cx * 1, ButtonSize.cy * 0.2, NULL);

		break;
	}
	case IDC_K_OOO: // ㅗ
	{
		InputHangeul(27);
		
		GetDlgItem(IDC_SUBEDIT)->SetWindowPos(&wndTop, ButtonSize.cx * 5, ButtonSize.cy * 4.8, ButtonSize.cx * 1, ButtonSize.cy * 0.2, NULL);

		break;
	}
	case IDC_K_EOO: // ㅓ
	{
		InputHangeul(23);
		
		GetDlgItem(IDC_SUBEDIT)->SetWindowPos(&wndTop, ButtonSize.cx * 6, ButtonSize.cy * 4.8, ButtonSize.cx * 1, ButtonSize.cy * 0.2, NULL);

		break;
	}
	case IDC_K_AAA: // ㅏ
	{
		InputHangeul(19);
		
		GetDlgItem(IDC_SUBEDIT)->SetWindowPos(&wndTop, ButtonSize.cx * 7, ButtonSize.cy * 4.8, ButtonSize.cx * 1, ButtonSize.cy * 0.2, NULL);

		break;
	}
	case IDC_K_YII: // ㅣ
	{
		InputHangeul(39);
		
		GetDlgItem(IDC_SUBEDIT)->SetWindowPos(&wndTop, ButtonSize.cx * 8, ButtonSize.cy * 4.8, ButtonSize.cx * 1, ButtonSize.cy * 0.2, NULL);

		break;
	}
	case IDC_E_SMQ:
	{
		if (hangeulInput.ingWord != NULL)
			InputHangeul(-1);
		if (clickedShift)
			InputText(_T("Q"));
		else
			InputText(_T("q"));

		GetDlgItem(IDC_SUBEDIT)->SetWindowPos(&wndTop, ButtonSize.cx * 0, ButtonSize.cy * 3.8, ButtonSize.cx * 1, ButtonSize.cy * 0.2, NULL);

		break;
	}
	case IDC_E_SMW:
	{
		if (hangeulInput.ingWord != NULL)
			InputHangeul(-1);
		if (clickedShift)
			InputText(_T("W"));
		else
			InputText(_T("w"));

		GetDlgItem(IDC_SUBEDIT)->SetWindowPos(&wndTop, ButtonSize.cx * 1, ButtonSize.cy * 3.8, ButtonSize.cx * 1, ButtonSize.cy * 0.2, NULL);
		
		break;
	}
	case IDC_E_SME:
	{
		if (hangeulInput.ingWord != NULL)
			InputHangeul(-1);
		if (clickedShift)
			InputText(_T("E"));
		else
			InputText(_T("e"));

		GetDlgItem(IDC_SUBEDIT)->SetWindowPos(&wndTop, ButtonSize.cx * 2, ButtonSize.cy * 3.8, ButtonSize.cx * 1, ButtonSize.cy * 0.2, NULL);

		break;
	}
	case IDC_E_SMR:
	{
		if (hangeulInput.ingWord != NULL)
			InputHangeul(-1);
		if (clickedShift)
			InputText(_T("R"));
		else
			InputText(_T("r"));
		
		break;

		GetDlgItem(IDC_SUBEDIT)->SetWindowPos(&wndTop, ButtonSize.cx * 3, ButtonSize.cy * 3.8, ButtonSize.cx * 1, ButtonSize.cy * 0.2, NULL);

	}
	case IDC_E_SMT:
	{
		if (hangeulInput.ingWord != NULL)
			InputHangeul(-1);
		if (clickedShift)
			InputText(_T("T"));
		else
			InputText(_T("t"));

		GetDlgItem(IDC_SUBEDIT)->SetWindowPos(&wndTop, ButtonSize.cx * 4, ButtonSize.cy * 3.8, ButtonSize.cx * 1, ButtonSize.cy * 0.2, NULL);

		break;
	}
	case IDC_E_SMY:
	{
		if (hangeulInput.ingWord != NULL)
			InputHangeul(-1);
		if (clickedShift)
			InputText(_T("Y"));
		else
			InputText(_T("y"));

		GetDlgItem(IDC_SUBEDIT)->SetWindowPos(&wndTop, ButtonSize.cx * 5, ButtonSize.cy * 3.8, ButtonSize.cx * 1, ButtonSize.cy * 0.2, NULL);

		break;
	}
	case IDC_E_SMU:
	{
		if (hangeulInput.ingWord != NULL)
			InputHangeul(-1);
		if (clickedShift)
			InputText(_T("U"));
		else
			InputText(_T("u"));

		GetDlgItem(IDC_SUBEDIT)->SetWindowPos(&wndTop, ButtonSize.cx * 6, ButtonSize.cy * 3.8, ButtonSize.cx * 1, ButtonSize.cy * 0.2, NULL);
		
		break;
	}
	case IDC_E_SMI:
	{
		if (hangeulInput.ingWord != NULL)
			InputHangeul(-1);
		if (clickedShift)
			InputText(_T("I"));
		else
			InputText(_T("i"));

		GetDlgItem(IDC_SUBEDIT)->SetWindowPos(&wndTop, ButtonSize.cx * 7, ButtonSize.cy * 3.8, ButtonSize.cx * 1, ButtonSize.cy * 0.2, NULL);
		
		break;
	}
	case IDC_E_SMO:
	{
		if (hangeulInput.ingWord != NULL)
			InputHangeul(-1);
		if (clickedShift)
			InputText(_T("O"));
		else
			InputText(_T("o"));
		
		GetDlgItem(IDC_SUBEDIT)->SetWindowPos(&wndTop, ButtonSize.cx * 8, ButtonSize.cy * 3.8, ButtonSize.cx * 1, ButtonSize.cy * 0.2, NULL);
		
		break;
	}
	case IDC_E_SMP:
	{
		if (hangeulInput.ingWord != NULL)
			InputHangeul(-1);
		if (clickedShift)
			InputText(_T("P"));
		else
			InputText(_T("p"));

		GetDlgItem(IDC_SUBEDIT)->SetWindowPos(&wndTop, ButtonSize.cx * 9, ButtonSize.cy * 3.8, ButtonSize.cx * 1, ButtonSize.cy * 0.2, NULL);

		break;
	}
	case IDC_E_SMA:
	{
		if (hangeulInput.ingWord != NULL)
			InputHangeul(-1);
		if (clickedShift)
			InputText(_T("A"));
		else
			InputText(_T("a"));
		break;
	}
	case IDC_E_SMS:
	{
		if (hangeulInput.ingWord != NULL)
			InputHangeul(-1);
		if (clickedShift)
			InputText(_T("S"));
		else
			InputText(_T("s"));
		
		break;
	}
	case IDC_E_SMD:
	{
		if (hangeulInput.ingWord != NULL)
			InputHangeul(-1);
		if (clickedShift)
			InputText(_T("D"));
		else
			InputText(_T("d"));
		break;
	}
	case IDC_E_SMF:
	{
		if (hangeulInput.ingWord != NULL)
			InputHangeul(-1);
		if (clickedShift)
			InputText(_T("F"));
		else
			InputText(_T("f"));
		
		break;
	}
	case IDC_E_SMG:
	{
		if (hangeulInput.ingWord != NULL)
			InputHangeul(-1);
		if (clickedShift)
			InputText(_T("G"));
		else
			InputText(_T("g"));
		
		break;
	}
	case IDC_E_SMH:
	{
		if (hangeulInput.ingWord != NULL)
			InputHangeul(-1);
		if (clickedShift)
			InputText(_T("H"));
		else
			InputText(_T("h"));
		
		break;
	}
	case IDC_E_SMJ:
	{
		if (hangeulInput.ingWord != NULL)
			InputHangeul(-1);
		if (clickedShift)
			InputText(_T("J"));
		else
			InputText(_T("j"));
		
		break;
	}
	case IDC_E_SMK:
	{
		if (hangeulInput.ingWord != NULL)
			InputHangeul(-1);
		if (clickedShift)
			InputText(_T("K"));
		else
			InputText(_T("k"));
		
		break;
	}
	case IDC_E_SML:
	{
		if (hangeulInput.ingWord != NULL)
			InputHangeul(-1);
		if (clickedShift)
			InputText(_T("L"));
		else
			InputText(_T("l"));
		
		break;
	}
	case IDC_S_KNG:
	{
		// 필요없어짐 ㅎㅎ
		break;
	}
	case IDC_S_ENG:
	{
		ShowSmallEngBtn();
		HideKorBtn();
		HideSpecialBtn();

		break;
	}
	case IDC_S_KOR:
	{
		ShowKorBtn();
		HideSmallEngBtn();
		HideSpecialBtn();

		break;
	}
	case IDC_K_KIE: // ㅋ
	{
		InputHangeul(15);

		GetDlgItem(IDC_SUBEDIT)->SetWindowPos(&wndTop, ButtonSize.cx * 0, ButtonSize.cy * 5.8, ButtonSize.cx * 1, ButtonSize.cy * 0.2, NULL);
		
		break;
	}
	case IDC_K_TIE: // ㅌ
	{
		InputHangeul(16);
		
		GetDlgItem(IDC_SUBEDIT)->SetWindowPos(&wndTop, ButtonSize.cx * 1, ButtonSize.cy * 5.8, ButtonSize.cx * 1, ButtonSize.cy * 0.2, NULL);

		break;
	}
	case IDC_K_CHI: // ㅊ
	{
		InputHangeul(14);
		
		GetDlgItem(IDC_SUBEDIT)->SetWindowPos(&wndTop, ButtonSize.cx * 2, ButtonSize.cy * 5.8, ButtonSize.cx * 1, ButtonSize.cy * 0.2, NULL);

		break;
	}
	case IDC_K_PIE: // ㅍ
	{
		InputHangeul(17);
		
		GetDlgItem(IDC_SUBEDIT)->SetWindowPos(&wndTop, ButtonSize.cx * 3, ButtonSize.cy * 5.8, ButtonSize.cx * 1, ButtonSize.cy * 0.2, NULL);

		break;
	}
	case IDC_E_SMZ:
	{

		if (hangeulInput.ingWord != NULL)
			InputHangeul(-1);
		if (clickedShift)
			InputText(_T("Z"));
		else
			InputText(_T("z")); 
		
		break;
	}
	case IDC_E_SMX:
	{
		if (hangeulInput.ingWord != NULL)
			InputHangeul(-1);
		if (clickedShift)
			InputText(_T("X"));
		else
			InputText(_T("x"));
		
		break;
	}
	case IDC_E_SMC:
	{
		if (hangeulInput.ingWord != NULL)
			InputHangeul(-1);
		if (clickedShift)
			InputText(_T("C"));
		else
			InputText(_T("c"));
		
		break;
	}
	case IDC_E_SMV:
	{
		if (hangeulInput.ingWord != NULL)
			InputHangeul(-1);
		if (clickedShift)
			InputText(_T("V"));
		else
			InputText(_T("v"));
		
		break;
	}
	case IDC_S_SPC:
	{
		if (hangeulInput.ingWord != NULL)
			InputHangeul(-1);
		InputHangeul(-1);

		CString sub_text;
		sub_text="";
		SetDlgItemText(IDC_SUBEDIT, sub_text);

		break;
	}
	case IDC_K_YUU: // ㅠ
	{
		InputHangeul(36);

		GetDlgItem(IDC_SUBEDIT)->SetWindowPos(&wndTop, ButtonSize.cx * 6, ButtonSize.cy * 5.8, ButtonSize.cx * 1, ButtonSize.cy * 0.2, NULL);

		break;
	}
	case IDC_K_UUU: // ㅜ
	{
		InputHangeul(32);

		GetDlgItem(IDC_SUBEDIT)->SetWindowPos(&wndTop, ButtonSize.cx * 7, ButtonSize.cy * 5.8, ButtonSize.cx * 1, ButtonSize.cy * 0.2, NULL);

		break;
	}
	case IDC_K_EUU: // ㅡ
	{
		InputHangeul(37);
		
		GetDlgItem(IDC_SUBEDIT)->SetWindowPos(&wndTop, ButtonSize.cx * 8, ButtonSize.cy * 5.8, ButtonSize.cx * 1, ButtonSize.cy * 0.2, NULL);

		break;
	}
	case IDC_E_SMB:
	{
		if (hangeulInput.ingWord != NULL)
			InputHangeul(-1);
		if (clickedShift)
			InputText(_T("B"));
		else
			InputText(_T("b"));

		break;
	}
	case IDC_E_SMN:
	{
		if (hangeulInput.ingWord != NULL)
			InputHangeul(-1);
		if (clickedShift)
			InputText(_T("N"));
		else
			InputText(_T("n"));
		
		break;
	}
	case IDC_E_SMM:
	{
		if (hangeulInput.ingWord != NULL)
			InputHangeul(-1);
		if (clickedShift)
			InputText(_T("M"));
		else
			InputText(_T("m"));
		
		break;
	}
	case IDC_S_DOT:
	{
		if (hangeulInput.ingWord != NULL)
			InputHangeul(-1);
		
		InputText(_T("."));

		GetDlgItem(IDC_SUBEDIT)->SetWindowPos(&wndTop, ButtonSize.cx * 9, ButtonSize.cy * 5.8, ButtonSize.cx * 1, ButtonSize.cy * 0.2, NULL);

		break;
	}
	case IDC_P_EXC:
	{
		if (hangeulInput.ingWord != NULL)
			InputHangeul(-1);
		InputText(_T("!"));

		break;
	}
	case IDC_P_GOL:
	{
		if (hangeulInput.ingWord != NULL)
			InputHangeul(-1);
		InputText(_T("@"));

		break;
	}
	case IDC_P_SHP:
	{
		if (hangeulInput.ingWord != NULL)
			InputHangeul(-1);
		InputText(_T("#"));

		break;
	}
	case IDC_P_DOL:
	{
		if (hangeulInput.ingWord != NULL)
			InputHangeul(-1);
		InputText(_T("$"));

		break;
	}
	case IDC_P_PER:
	{
		if (hangeulInput.ingWord != NULL)
			InputHangeul(-1);
		InputText(_T("%"));

		break;
	}
	case IDC_P_CIR:
	{
		if (hangeulInput.ingWord != NULL)
			InputHangeul(-1);
		InputText(_T("^"));

		break;
	}
	case IDC_P_AND:
	{
		if (hangeulInput.ingWord != NULL)
			InputHangeul(-1);
		InputText(_T("&"));

		break;
	}
	case IDC_P_AST:
	{
		if (hangeulInput.ingWord != NULL)
			InputHangeul(-1);
		InputText(_T("*"));

		break;
	}
	case IDC_P_OSG:
	{
		if (hangeulInput.ingWord != NULL)
			InputHangeul(-1);
		InputText(_T("("));

		break;
	}
	case IDC_P_CSG:
	{
		if (hangeulInput.ingWord != NULL)
			InputHangeul(-1);
		InputText(_T(")"));

		break;
	}
	case IDC_P_WAV:
	{
		if (hangeulInput.ingWord != NULL)
			InputHangeul(-1);
		InputText(_T("~"));

		break;
	}
	case IDC_P_HYP:
	{
		if (hangeulInput.ingWord != NULL)
			InputHangeul(-1);
		InputText(_T("-"));
		
		break;
	}
	case IDC_P_EQL:
	{
		if (hangeulInput.ingWord != NULL)
			InputHangeul(-1);
		InputText(_T("="));
		
		break;
	}
	case IDC_P_PLS:
	{
		if (hangeulInput.ingWord != NULL)
			InputHangeul(-1);
		InputText(_T("+"));

		break;
	}
	case IDC_P_ODG:
	{
		if (hangeulInput.ingWord != NULL)
			InputHangeul(-1);
		InputText(_T("["));
		
		break;
	}
	case IDC_P_CDG:
	{
		if (hangeulInput.ingWord != NULL)
			InputHangeul(-1);
		InputText(_T("]"));
		
		break;
	}
	case IDC_P_OKG:
	{
		if (hangeulInput.ingWord != NULL)
			InputHangeul(-1);
		InputText(_T("<"));

		break;
	}
	case IDC_P_CKG:
	{
		if (hangeulInput.ingWord != NULL)
			InputHangeul(-1);
		InputText(_T(">"));

		break;
	}
	case IDC_P_QST:
	{
		if (hangeulInput.ingWord != NULL)
			InputHangeul(-1);
		InputText(_T("?"));

		break;
	}
	case IDC_P_COL:
	{
		if (hangeulInput.ingWord != NULL)
			InputHangeul(-1);
		InputText(_T(":"));

		break;
	}
	case IDC_P_SCL:
	{
		if (hangeulInput.ingWord != NULL)
			InputHangeul(-1);
		InputText(_T(";"));
		
		break;
	}
	case IDC_P_SDD:
	{
		if (hangeulInput.ingWord != NULL)
			InputHangeul(-1);
		InputText(_T("'"));
		
		break;
	}
	case IDC_P_BDD:
	{
		if (hangeulInput.ingWord != NULL)
			InputHangeul(-1);
		InputText(_T("\""));
		
		break;
	}
	case IDC_P_BSL:
	{
		if (hangeulInput.ingWord != NULL)
			InputHangeul(-1);
		InputText(_T("\\"));
		
		break;
	}
	case IDC_P_SLS:
	{
		if (hangeulInput.ingWord != NULL)
			InputHangeul(-1);
		InputText(_T("/"));
		
		break;
	}
	case IDC_P_CMM:
	{
		if (hangeulInput.ingWord != NULL)
			InputHangeul(-1);
		InputText(_T(","));
		
		break;
	}
	}
}
/*
void SelectKeyboardDlg::OnCancel()
{
	if (mousehide_count == 1)
	{
		TRACE("MOUSE 보이게");
		ShowCursor(true);
		mousehide_count--;
	}
	//return;
}

void SelectKeyboardDlg::OnClose()
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	
	//mouse cursor 다시 보이도록
	if (mousehide_count == 1)
	{
		TRACE("MOUSE 보이게");
		ShowCursor(true);
		mousehide_count--;
	}
	CDialogEx::OnClose();
}


BOOL SelectKeyboardDlg::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (mousehide_count == 0)
	{
		TRACE("MOUSE 사라지게");
		ShowCursor(false);
		mousehide_count++;
	}
	return CDialogEx::OnSetCursor(pWnd, nHitTest, message);
}

*/



void SelectKeyboardDlg::OnClose()
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	// 메인에디트 초기화
	hangeulInput.Clear();
	SetDlgItemText(IDC_MAINEDIT, _T(""));
	// 서브에디트 초기화
	CString sub_text;
	sub_text = "";
	SetDlgItemText(IDC_SUBEDIT, sub_text);
	GetDlgItem(IDC_SUBEDIT)->SetWindowPos(&wndTop, 0, 0, 0, 0, NULL);
	// 영어, 특수문자 버튼 숨기기
	ShowKorBtn();
	HideSmallEngBtn();
	HideBigEngBtn();
	HideSpecialBtn();

	CDialogEx::OnClose();
}
