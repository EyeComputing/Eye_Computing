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
	CxSkinButton s_btn_bck;
	CxSkinButton s_btn_shf;
	CxSkinButton s_btn_bks;
	CxSkinButton s_btn_ent;
	CxSkinButton s_btn_spe;
	CxSkinButton s_btn_con;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};
