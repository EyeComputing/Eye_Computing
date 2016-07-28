#pragma once
#include "xSkinButton.h"
#include "afxwin.h"


// SelectKeyboardDlg ��ȭ �����Դϴ�.

class SelectKeyboardDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SelectKeyboardDlg)

public:
	SelectKeyboardDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~SelectKeyboardDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_Dlg_Keyboard };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();

	// ������ ������� ��ư ������ ���� �Է¹ޱ� ���� ����
	SIZE WindowSize;
	SIZE ButtonSize;

	// ���� ��ư ����
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
	CxSkinButton s_btn_bck;
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
};
