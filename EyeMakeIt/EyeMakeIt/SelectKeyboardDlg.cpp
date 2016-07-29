// SelectKeyboardDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "EyeMakeIt.h"
#include "SelectKeyboardDlg.h"
#include "afxdialogex.h"


/* global var */
bool clickedShift = false;
INPUT InputShift;

// SelectKeyboardDlg ��ȭ �����Դϴ�.

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
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	/* ��ư Ŭ�� �ѹ��� �ϴ� �޼��� ���� */
	ON_COMMAND_RANGE(IDC_N_ONE, IDC_N_ONE, SelectKeyboardDlg::OnBtnClick)
	ON_COMMAND_RANGE(IDC_N_ONE, IDC_S_DOT, SelectKeyboardDlg::OnBtnClick)
	ON_BN_CLICKED(IDC_S_KOR, &SelectKeyboardDlg::OnBnClickedSKor)
END_MESSAGE_MAP()


// SelectKeyboardDlg �޽��� ó�����Դϴ�.


BOOL SelectKeyboardDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	ZeroMemory(&WindowSize, sizeof(SIZE));
	WindowSize.cx = (LONG)::GetSystemMetrics(SM_CXFULLSCREEN);
	WindowSize.cy = (LONG)::GetSystemMetrics(SM_CYFULLSCREEN);

	ButtonSize.cx = (WindowSize.cx / 10);
	ButtonSize.cy = (WindowSize.cy / 6);
	

	// ��üȭ�� ����
	ShowWindow(SW_SHOWMAXIMIZED);

	// ��ư �̹��� �����
	SetImgNumBtn();
	SetImgSysBtn();
	SetImgKorBtn();
	SetImgSmallEngBtn();

	// ��ư ��ǥ ����
	SetPosBtn();
	
	// ���� �����
	HideEngBtn();

	




	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}








/* ����� ���� �Լ� */

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
}


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


// ���� ��ư �̹��� ����
void SelectKeyboardDlg::SetImgNumBtn()
{
	// ���� ��ư ��Ų �����
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

// �ý��� ��ư �̹��� ����
void SelectKeyboardDlg::SetImgSysBtn()
{
	// �ý��� ��ư ��Ų �����
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

// �ѱ� ��ư �̹��� ����
void SelectKeyboardDlg::SetImgKorBtn()
{
	// �ѱ� ��ư ��Ų �����
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

// ���� �ҹ��� ��ư �̹��� ����
void SelectKeyboardDlg::SetImgSmallEngBtn()
{
	// ���� �ҹ��� ��ư ��Ų �����
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

void SelectKeyboardDlg::SetPosBtn()
{
	// �ý���, �ѱ� ��ư ��ǥ �� ũ�� ����
	for (int y = 0; y < 6; y++)
		for (int x = 0; x < 10; x++)
		{
			// ���ҽ� ������ �ޱ� ���� ����
			int order = 2000 + (10 * y) + x;

			// ��ȭ���� �κ��� ����
			if (order > 2010 && order < 2018)	continue;
			else if (order > 2020 && order < 2028)	continue;

			// �����̽� ó��
			else if (order == 2054)
				GetDlgItem(order)->SetWindowPos(NULL, ButtonSize.cx * x, ButtonSize.cy * y, ButtonSize.cx * 2, ButtonSize.cy, SWP_NOZORDER);
			else if (order == 2055)	continue;

			// ���ܻ��� �ƴ� ��� x, y ��ǥ�� ��ư ũ�� ��ŭ ���
			else
				GetDlgItem(order)->SetWindowPos(NULL, ButtonSize.cx * x, ButtonSize.cy * y, ButtonSize.cx, ButtonSize.cy, SWP_NOZORDER);
		}

	

	// ���� ��ư ��ǥ �� ũ�� ����	
	for (int y = 3; y < 6; y++)
		for (int x = 0; x < 10; x++)
		{
			// ���ҽ� ������ �ޱ� ���� ����
			int order = 2030 + (10 * y) + x;

			// �����̽��� ����
			if (order == 2084 || order == 2085)	continue;

			// ��ħǥ ����
			else if (order == 2089)	continue;

			// ���ܻ��� �ƴ� ��� x, y ��ǥ�� ��ư ũ�� ��ŭ ���
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

void SelectKeyboardDlg::ShowEngBtn()
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

void SelectKeyboardDlg::HideEngBtn()
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










// �� ��ư Ŭ�� �Լ�
void SelectKeyboardDlg::OnBtnClick(UINT uiID)
{
	switch (uiID)
	{
	case IDC_N_ONE:
	{
		INPUT InputButton;
		//initialize
		::ZeroMemory(&InputButton, sizeof(INPUT));
		//keyboard�� �Է��ϰڴ�.
		InputButton.type = INPUT_KEYBOARD;
		//���ư��������
		InputButton.ki.wVk = 0x31;
		//�ѹ������ֱ�
		::SendInput(1, &InputButton, sizeof(INPUT));
		//������ Ǯ���ֱ�
		InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputButton, sizeof(INPUT));

		break;
	}
	case IDC_N_TWO:
	{
		INPUT InputButton;
		//initialize
		::ZeroMemory(&InputButton, sizeof(INPUT));
		//keyboard�� �Է��ϰڴ�.
		InputButton.type = INPUT_KEYBOARD;
		//���ư��������
		InputButton.ki.wVk = 0x32;
		//�ѹ������ֱ�
		::SendInput(1, &InputButton, sizeof(INPUT));
		//������ Ǯ���ֱ�
		InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputButton, sizeof(INPUT));
		break;
	}
	case IDC_N_THR:
	{
		INPUT InputButton;
		//initialize
		::ZeroMemory(&InputButton, sizeof(INPUT));
		//keyboard�� �Է��ϰڴ�.
		InputButton.type = INPUT_KEYBOARD;
		//���ư��������
		InputButton.ki.wVk = 0x33;
		//�ѹ������ֱ�
		::SendInput(1, &InputButton, sizeof(INPUT));
		//������ Ǯ���ֱ�
		InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputButton, sizeof(INPUT));
		break;
	}
	case IDC_N_FOU:
	{
		INPUT InputButton;
		//initialize
		::ZeroMemory(&InputButton, sizeof(INPUT));
		//keyboard�� �Է��ϰڴ�.
		InputButton.type = INPUT_KEYBOARD;
		//���ư��������
		InputButton.ki.wVk = 0x34;
		//�ѹ������ֱ�
		::SendInput(1, &InputButton, sizeof(INPUT));
		//������ Ǯ���ֱ�
		InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputButton, sizeof(INPUT));
		break;
	}
	case IDC_N_FIV:
	{
		INPUT InputButton;
		//initialize
		::ZeroMemory(&InputButton, sizeof(INPUT));
		//keyboard�� �Է��ϰڴ�.
		InputButton.type = INPUT_KEYBOARD;
		//���ư��������
		InputButton.ki.wVk = 0x35;
		//�ѹ������ֱ�
		::SendInput(1, &InputButton, sizeof(INPUT));
		//������ Ǯ���ֱ�
		InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputButton, sizeof(INPUT));
		break;
	}
	case IDC_N_SIX:
	{
		INPUT InputButton;
		//initialize
		::ZeroMemory(&InputButton, sizeof(INPUT));
		//keyboard�� �Է��ϰڴ�.
		InputButton.type = INPUT_KEYBOARD;
		//���ư��������
		InputButton.ki.wVk = 0x36;
		//�ѹ������ֱ�
		::SendInput(1, &InputButton, sizeof(INPUT));
		//������ Ǯ���ֱ�
		InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputButton, sizeof(INPUT));
		break;
	}
	case IDC_N_SEV:
	{
		INPUT InputButton;
		//initialize
		::ZeroMemory(&InputButton, sizeof(INPUT));
		//keyboard�� �Է��ϰڴ�.
		InputButton.type = INPUT_KEYBOARD;
		//���ư��������
		InputButton.ki.wVk = 0x37;
		//�ѹ������ֱ�
		::SendInput(1, &InputButton, sizeof(INPUT));
		//������ Ǯ���ֱ�
		InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputButton, sizeof(INPUT));
		break;
	}
	case IDC_N_EIG:
	{
		INPUT InputButton;
		//initialize
		::ZeroMemory(&InputButton, sizeof(INPUT));
		//keyboard�� �Է��ϰڴ�.
		InputButton.type = INPUT_KEYBOARD;
		//���ư��������
		InputButton.ki.wVk = 0x38;
		//�ѹ������ֱ�
		::SendInput(1, &InputButton, sizeof(INPUT));
		//������ Ǯ���ֱ�
		InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputButton, sizeof(INPUT));
		break;
	}
	case IDC_N_NIN:
	{
		INPUT InputButton;
		//initialize
		::ZeroMemory(&InputButton, sizeof(INPUT));
		//keyboard�� �Է��ϰڴ�.
		InputButton.type = INPUT_KEYBOARD;
		//���ư��������
		InputButton.ki.wVk = 0x39;
		//�ѹ������ֱ�
		::SendInput(1, &InputButton, sizeof(INPUT));
		//������ Ǯ���ֱ�
		InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputButton, sizeof(INPUT));
		break;
	}
	case IDC_N_ZER:
	{
		INPUT InputButton;
		//initialize
		::ZeroMemory(&InputButton, sizeof(INPUT));
		//keyboard�� �Է��ϰڴ�.
		InputButton.type = INPUT_KEYBOARD;
		//���ư��������
		InputButton.ki.wVk = 0x30;
		//�ѹ������ֱ�
		::SendInput(1, &InputButton, sizeof(INPUT));
		//������ Ǯ���ֱ�
		InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputButton, sizeof(INPUT));
		break;
	}
	case IDC_S_BKS:
	{
		INPUT InputButton;
		//initialize
		::ZeroMemory(&InputButton, sizeof(INPUT));
		//keyboard�� �Է��ϰڴ�.
		InputButton.type = INPUT_KEYBOARD;
		//���ư��������
		InputButton.ki.wVk = 0x08;
		//�ѹ������ֱ�
		::SendInput(1, &InputButton, sizeof(INPUT));
		//������ Ǯ���ֱ�
		InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputButton, sizeof(INPUT));
		break;
	}
	case IDC_S_SPE:
	{
		// Ư������
		break;
	}
	case IDC_S_SHF:
	{
		clickedShift = !clickedShift;

		if (clickedShift)
		{
			//initialize
			::ZeroMemory(&InputShift, sizeof(INPUT));
			//keyboard�� �Է��ϰڴ�.
			InputShift.type = INPUT_KEYBOARD;
			//���ư��������
			InputShift.ki.wVk = 0x10;
			//�ѹ������ֱ�
			::SendInput(1, &InputShift, sizeof(INPUT));
		}
		else
		{
			//������ Ǯ���ֱ�
			InputShift.ki.dwFlags = KEYEVENTF_KEYUP;
			::SendInput(1, &InputShift, sizeof(INPUT));
		}
		break;
	}
	case IDC_S_ENT:
	{
		INPUT InputButton;
		//initialize
		::ZeroMemory(&InputButton, sizeof(INPUT));
		//keyboard�� �Է��ϰڴ�.
		InputButton.type = INPUT_KEYBOARD;
		//���ư��������
		InputButton.ki.wVk = 0x0D;
		//�ѹ������ֱ�
		::SendInput(1, &InputButton, sizeof(INPUT));
		//������ Ǯ���ֱ�
		InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputButton, sizeof(INPUT));
		break;
	}
	case IDC_S_CON:
	{
		// �����ϴ°�..
		break;
	}
	case IDC_K_BIE:
	{
		INPUT InputButton;
		//initialize
		::ZeroMemory(&InputButton, sizeof(INPUT));
		//keyboard�� �Է��ϰڴ�.
		InputButton.type = INPUT_KEYBOARD;
		//���ư��������
		InputButton.ki.wVk = 0x51;
		//�ѹ������ֱ�
		::SendInput(1, &InputButton, sizeof(INPUT));
		//������ Ǯ���ֱ�
		InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputButton, sizeof(INPUT));
		break;
	}
	case IDC_K_JIE:
	{
		INPUT InputButton;
		//initialize
		::ZeroMemory(&InputButton, sizeof(INPUT));
		//keyboard�� �Է��ϰڴ�.
		InputButton.type = INPUT_KEYBOARD;
		//���ư��������
		InputButton.ki.wVk = 0x57;
		//�ѹ������ֱ�
		::SendInput(1, &InputButton, sizeof(INPUT));
		//������ Ǯ���ֱ�
		InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputButton, sizeof(INPUT));
		break;
	}
	case IDC_K_DIG:
	{
		INPUT InputButton;
		//initialize
		::ZeroMemory(&InputButton, sizeof(INPUT));
		//keyboard�� �Է��ϰڴ�.
		InputButton.type = INPUT_KEYBOARD;
		//���ư��������
		InputButton.ki.wVk = 0x45;
		//�ѹ������ֱ�
		::SendInput(1, &InputButton, sizeof(INPUT));
		//������ Ǯ���ֱ�
		InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputButton, sizeof(INPUT));
		break;
	}
	case IDC_K_GIY:
	{
		INPUT InputButton;
		//initialize
		::ZeroMemory(&InputButton, sizeof(INPUT));
		//keyboard�� �Է��ϰڴ�.
		InputButton.type = INPUT_KEYBOARD;
		//���ư��������
		InputButton.ki.wVk = 0x52;
		//�ѹ������ֱ�
		::SendInput(1, &InputButton, sizeof(INPUT));
		//������ Ǯ���ֱ�
		InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputButton, sizeof(INPUT));
		break;
	}
	case IDC_K_SHI:
	{
		INPUT InputButton;
		//initialize
		::ZeroMemory(&InputButton, sizeof(INPUT));
		//keyboard�� �Է��ϰڴ�.
		InputButton.type = INPUT_KEYBOARD;
		//���ư��������
		InputButton.ki.wVk = 0x54;
		//�ѹ������ֱ�
		::SendInput(1, &InputButton, sizeof(INPUT));
		//������ Ǯ���ֱ�
		InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputButton, sizeof(INPUT));
		break;
	}
	case IDC_K_YYO:
	{
		INPUT InputButton;
		//initialize
		::ZeroMemory(&InputButton, sizeof(INPUT));
		//keyboard�� �Է��ϰڴ�.
		InputButton.type = INPUT_KEYBOARD;
		//���ư��������
		InputButton.ki.wVk = 0x59;
		//�ѹ������ֱ�
		::SendInput(1, &InputButton, sizeof(INPUT));
		//������ Ǯ���ֱ�
		InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputButton, sizeof(INPUT));
		break;
	}
	case IDC_K_YEO:
	{
		INPUT InputButton;
		//initialize
		::ZeroMemory(&InputButton, sizeof(INPUT));
		//keyboard�� �Է��ϰڴ�.
		InputButton.type = INPUT_KEYBOARD;
		//���ư��������
		InputButton.ki.wVk = 0x55;
		//�ѹ������ֱ�
		::SendInput(1, &InputButton, sizeof(INPUT));
		//������ Ǯ���ֱ�
		InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputButton, sizeof(INPUT));
		break;
	}
	case IDC_K_YYA:
	{
		INPUT InputButton;
		//initialize
		::ZeroMemory(&InputButton, sizeof(INPUT));
		//keyboard�� �Է��ϰڴ�.
		InputButton.type = INPUT_KEYBOARD;
		//���ư��������
		InputButton.ki.wVk = 0x49;
		//�ѹ������ֱ�
		::SendInput(1, &InputButton, sizeof(INPUT));
		//������ Ǯ���ֱ�
		InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputButton, sizeof(INPUT));
		break;
	}
	case IDC_K_AEE:
	{
		INPUT InputButton;
		//initialize
		::ZeroMemory(&InputButton, sizeof(INPUT));
		//keyboard�� �Է��ϰڴ�.
		InputButton.type = INPUT_KEYBOARD;
		//���ư��������
		InputButton.ki.wVk = 0x4F;
		//�ѹ������ֱ�
		::SendInput(1, &InputButton, sizeof(INPUT));
		//������ Ǯ���ֱ�
		InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputButton, sizeof(INPUT));
		break;
	}
	case IDC_K_EEE:
	{
		INPUT InputButton;
		//initialize
		::ZeroMemory(&InputButton, sizeof(INPUT));
		//keyboard�� �Է��ϰڴ�.
		InputButton.type = INPUT_KEYBOARD;
		//���ư��������
		InputButton.ki.wVk = 0x50;
		//�ѹ������ֱ�
		::SendInput(1, &InputButton, sizeof(INPUT));
		//������ Ǯ���ֱ�
		InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputButton, sizeof(INPUT));
		break;
	}
	case IDC_K_MIE:
	{
		INPUT InputButton;
		//initialize
		::ZeroMemory(&InputButton, sizeof(INPUT));
		//keyboard�� �Է��ϰڴ�.
		InputButton.type = INPUT_KEYBOARD;
		//���ư��������
		InputButton.ki.wVk = 0x41;
		//�ѹ������ֱ�
		::SendInput(1, &InputButton, sizeof(INPUT));
		//������ Ǯ���ֱ�
		InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputButton, sizeof(INPUT));
		break;
	}
	case IDC_K_NIE:
	{
		INPUT InputButton;
		//initialize
		::ZeroMemory(&InputButton, sizeof(INPUT));
		//keyboard�� �Է��ϰڴ�.
		InputButton.type = INPUT_KEYBOARD;
		//���ư��������
		InputButton.ki.wVk = 0x53;
		//�ѹ������ֱ�
		::SendInput(1, &InputButton, sizeof(INPUT));
		//������ Ǯ���ֱ�
		InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputButton, sizeof(INPUT));
		break;
	}
	case IDC_K_IEU:
	{
		INPUT InputButton;
		//initialize
		::ZeroMemory(&InputButton, sizeof(INPUT));
		//keyboard�� �Է��ϰڴ�.
		InputButton.type = INPUT_KEYBOARD;
		//���ư��������
		InputButton.ki.wVk = 0x44;
		//�ѹ������ֱ�
		::SendInput(1, &InputButton, sizeof(INPUT));
		//������ Ǯ���ֱ�
		InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputButton, sizeof(INPUT));
		break;
	}
	case IDC_K_RIE:
	{
		INPUT InputButton;
		//initialize
		::ZeroMemory(&InputButton, sizeof(INPUT));
		//keyboard�� �Է��ϰڴ�.
		InputButton.type = INPUT_KEYBOARD;
		//���ư��������
		InputButton.ki.wVk = 0x46;
		//�ѹ������ֱ�
		::SendInput(1, &InputButton, sizeof(INPUT));
		//������ Ǯ���ֱ�
		InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputButton, sizeof(INPUT));
		break;
	}
	case IDC_K_HIE:
	{
		INPUT InputButton;
		//initialize
		::ZeroMemory(&InputButton, sizeof(INPUT));
		//keyboard�� �Է��ϰڴ�.
		InputButton.type = INPUT_KEYBOARD;
		//���ư��������
		InputButton.ki.wVk = 0x47;
		//�ѹ������ֱ�
		::SendInput(1, &InputButton, sizeof(INPUT));
		//������ Ǯ���ֱ�
		InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputButton, sizeof(INPUT));
		break;
	}
	case IDC_K_OOO:
	{
		INPUT InputButton;
		//initialize
		::ZeroMemory(&InputButton, sizeof(INPUT));
		//keyboard�� �Է��ϰڴ�.
		InputButton.type = INPUT_KEYBOARD;
		//���ư��������
		InputButton.ki.wVk = 0x48;
		//�ѹ������ֱ�
		::SendInput(1, &InputButton, sizeof(INPUT));
		//������ Ǯ���ֱ�
		InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputButton, sizeof(INPUT));
		break;
	}
	case IDC_K_EOO:
	{
		INPUT InputButton;
		//initialize
		::ZeroMemory(&InputButton, sizeof(INPUT));
		//keyboard�� �Է��ϰڴ�.
		InputButton.type = INPUT_KEYBOARD;
		//���ư��������
		InputButton.ki.wVk = 0x4A;
		//�ѹ������ֱ�
		::SendInput(1, &InputButton, sizeof(INPUT));
		//������ Ǯ���ֱ�
		InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputButton, sizeof(INPUT));
		break;
	}
	case IDC_K_AAA:
	{
		INPUT InputButton;
		//initialize
		::ZeroMemory(&InputButton, sizeof(INPUT));
		//keyboard�� �Է��ϰڴ�.
		InputButton.type = INPUT_KEYBOARD;
		//���ư��������
		InputButton.ki.wVk = 0x4B;
		//�ѹ������ֱ�
		::SendInput(1, &InputButton, sizeof(INPUT));
		//������ Ǯ���ֱ�
		InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputButton, sizeof(INPUT));
		break;
	}
	case IDC_K_YII:
	{
		INPUT InputButton;
		//initialize
		::ZeroMemory(&InputButton, sizeof(INPUT));
		//keyboard�� �Է��ϰڴ�.
		InputButton.type = INPUT_KEYBOARD;
		//���ư��������
		InputButton.ki.wVk = 0x4C;
		//�ѹ������ֱ�
		::SendInput(1, &InputButton, sizeof(INPUT));
		//������ Ǯ���ֱ�
		InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputButton, sizeof(INPUT));
		break;
	}
	case IDC_S_KNG:
	{
		INPUT InputButton;
		//initialize
		::ZeroMemory(&InputButton, sizeof(INPUT));
		//keyboard�� �Է��ϰڴ�.
		InputButton.type = INPUT_KEYBOARD;
		//���ư��������
		InputButton.ki.wVk = 0x15;
		//�ѹ������ֱ�
		::SendInput(1, &InputButton, sizeof(INPUT));
		//������ Ǯ���ֱ�
		InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputButton, sizeof(INPUT));

		break;
	}
	case IDC_K_KIE:
	{
		INPUT InputButton;
		//initialize
		::ZeroMemory(&InputButton, sizeof(INPUT));
		//keyboard�� �Է��ϰڴ�.
		InputButton.type = INPUT_KEYBOARD;
		//���ư��������
		InputButton.ki.wVk = 0x5A;
		//�ѹ������ֱ�
		::SendInput(1, &InputButton, sizeof(INPUT));
		//������ Ǯ���ֱ�
		InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputButton, sizeof(INPUT));
		break;
	}
	case IDC_K_TIE:
	{
		INPUT InputButton;
		//initialize
		::ZeroMemory(&InputButton, sizeof(INPUT));
		//keyboard�� �Է��ϰڴ�.
		InputButton.type = INPUT_KEYBOARD;
		//���ư��������
		InputButton.ki.wVk = 0x58;
		//�ѹ������ֱ�
		::SendInput(1, &InputButton, sizeof(INPUT));
		//������ Ǯ���ֱ�
		InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputButton, sizeof(INPUT));
		break;
	}
	case IDC_K_CHI:
	{
		INPUT InputButton;
		//initialize
		::ZeroMemory(&InputButton, sizeof(INPUT));
		//keyboard�� �Է��ϰڴ�.
		InputButton.type = INPUT_KEYBOARD;
		//���ư��������
		InputButton.ki.wVk = 0x43;
		//�ѹ������ֱ�
		::SendInput(1, &InputButton, sizeof(INPUT));
		//������ Ǯ���ֱ�
		InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputButton, sizeof(INPUT));
		break;
	}
	case IDC_K_PIE:
	{
		INPUT InputButton;
		//initialize
		::ZeroMemory(&InputButton, sizeof(INPUT));
		//keyboard�� �Է��ϰڴ�.
		InputButton.type = INPUT_KEYBOARD;
		//���ư��������
		InputButton.ki.wVk = 0x56;
		//�ѹ������ֱ�
		::SendInput(1, &InputButton, sizeof(INPUT));
		//������ Ǯ���ֱ�
		InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputButton, sizeof(INPUT));
		break;
	}
	case IDC_S_SPC:
	{
		INPUT InputButton;
		//initialize
		::ZeroMemory(&InputButton, sizeof(INPUT));
		//keyboard�� �Է��ϰڴ�.
		InputButton.type = INPUT_KEYBOARD;
		//���ư��������
		InputButton.ki.wVk = 0x20;
		//�ѹ������ֱ�
		::SendInput(1, &InputButton, sizeof(INPUT));
		//������ Ǯ���ֱ�
		InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputButton, sizeof(INPUT));
		break;
	}
	case IDC_K_YUU:
	{
		INPUT InputButton;
		//initialize
		::ZeroMemory(&InputButton, sizeof(INPUT));
		//keyboard�� �Է��ϰڴ�.
		InputButton.type = INPUT_KEYBOARD;
		//���ư��������
		InputButton.ki.wVk = 0x42;
		//�ѹ������ֱ�
		::SendInput(1, &InputButton, sizeof(INPUT));
		//������ Ǯ���ֱ�
		InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputButton, sizeof(INPUT));
		break;
	}
	case IDC_K_UUU:
	{
		INPUT InputButton;
		//initialize
		::ZeroMemory(&InputButton, sizeof(INPUT));
		//keyboard�� �Է��ϰڴ�.
		InputButton.type = INPUT_KEYBOARD;
		//���ư��������
		InputButton.ki.wVk = 0x4E;
		//�ѹ������ֱ�
		::SendInput(1, &InputButton, sizeof(INPUT));
		//������ Ǯ���ֱ�
		InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputButton, sizeof(INPUT));
		break;
	}
	case IDC_K_EUU:
	{
		INPUT InputButton;
		//initialize
		::ZeroMemory(&InputButton, sizeof(INPUT));
		//keyboard�� �Է��ϰڴ�.
		InputButton.type = INPUT_KEYBOARD;
		//���ư��������
		InputButton.ki.wVk = 0x4D;
		//�ѹ������ֱ�
		::SendInput(1, &InputButton, sizeof(INPUT));
		//������ Ǯ���ֱ�
		InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputButton, sizeof(INPUT));
		break;
	}
	case IDC_S_DOT:
	{
		INPUT InputButton;
		//initialize
		::ZeroMemory(&InputButton, sizeof(INPUT));
		//keyboard�� �Է��ϰڴ�.
		InputButton.type = INPUT_KEYBOARD;
		//���ư��������
		InputButton.ki.wVk = 0xBE;
		//�ѹ������ֱ�
		::SendInput(1, &InputButton, sizeof(INPUT));
		//������ Ǯ���ֱ�
		InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputButton, sizeof(INPUT));
		break;
	}
	case IDC_S_ENG:
	{
		INPUT InputButton;
		//initialize
		::ZeroMemory(&InputButton, sizeof(INPUT));
		//keyboard�� �Է��ϰڴ�.
		InputButton.type = INPUT_KEYBOARD;
		//���ư��������
		InputButton.ki.wVk = 0x15;
		//�ѹ������ֱ�
		::SendInput(1, &InputButton, sizeof(INPUT));
		//������ Ǯ���ֱ�
		InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputButton, sizeof(INPUT));

		ShowEngBtn();
		HideKorBtn();
		Invalidate(TRUE);
		
		break;
	}
	}
}



// ���� -> �ѱ�
void SelectKeyboardDlg::OnBnClickedSKor()
{

	INPUT InputButton;
	//initialize
	::ZeroMemory(&InputButton, sizeof(INPUT));
	//keyboard�� �Է��ϰڴ�.
	InputButton.type = INPUT_KEYBOARD;
	//���ư��������
	InputButton.ki.wVk = 0x15;
	//�ѹ������ֱ�
	::SendInput(1, &InputButton, sizeof(INPUT));
	//������ Ǯ���ֱ�
	InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &InputButton, sizeof(INPUT));
	
	ShowKorBtn();
	HideEngBtn();
	Invalidate(TRUE);

}
