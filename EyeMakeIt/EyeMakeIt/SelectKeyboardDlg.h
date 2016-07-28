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
	HWND m_hForegroundWnd;

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();

	/*��ư �Է� �޴� �Լ�*/
	void SelectKeyboardDlg::OnBtnClick(UINT uiID);

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
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};
