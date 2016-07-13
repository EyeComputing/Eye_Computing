
// Eye_Computing_DialogDlg.h : 헤더 파일
//

#pragma once
#include "afxwin.h"
#include "xSkinButton.h"


// CEye_Computing_DialogDlg 대화 상자
class CEye_Computing_DialogDlg : public CDialogEx
{
// 생성입니다.
public:
	CEye_Computing_DialogDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_EYE_COMPUTING_DIALOG_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;
	HWND m_hForegroundWnd;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();

	//모음 상태 초기화 함수
	afx_msg void CEye_Computing_DialogDlg::initHanguel();

	//afx_msg LRESULT OnUM_EYEX_HOST_STATUS_CHANGED(WPARAM wParam, LPARAM IParam);
	afx_msg LRESULT OnUM_REGION_ACTIVATED(WPARAM wParam, LPARAM IParam);

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedGiyeok();
	afx_msg void OnNcLButtonDown(UINT nHitTest, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedNieun();
	afx_msg void OnBnClickedAh();
	afx_msg void OnBnClickedYee();
	afx_msg void OnBnClickedZzum();
	afx_msg void OnBnClickedEu();
	CxSkinButton m_btn_BkSpace;
	CxSkinButton m_btn_Back;
	CxSkinButton m_btn_GiYeok;
	CxSkinButton m_btn_NiEun;
	CxSkinButton m_btn_DiGeut;
	CxSkinButton m_btn_Confirm;
	CxSkinButton m_btn_RiEul;
	CxSkinButton m_btn_MiEum;
	CxSkinButton m_btn_BiEup;
	CxSkinButton m_btn_Zzum;
	CxSkinButton m_btn_Yi;
	CxSkinButton m_btn_ShiOt;
	CxSkinButton m_btn_Eu;
	CxSkinButton m_btn_Space;
	CxSkinButton m_btn_IEung;
	CxSkinButton m_btn_KiEuk;
	CxSkinButton m_btn_ChiEut;
	CxSkinButton m_btn_JiEut;
	CxSkinButton m_btn_TiEut;
	CxSkinButton m_btn_PiEup;
	CxSkinButton m_btn_HiEut;
	CStatic m_BkGround;
	afx_msg void OnBnClickedIii();
	afx_msg void OnBnClickedDigeut();
	afx_msg void OnBnClickedRieul();
	afx_msg void OnBnClickedMieum();
	afx_msg void OnBnClickedBieup();
	afx_msg void OnBnClickedShiot();
	afx_msg void OnBnClickedIeung();
	afx_msg void OnBnClickedJieut();
	afx_msg void OnBnClickedChieut();
	afx_msg void OnBnClickedKieuk();
	afx_msg void OnBnClickedTieut();
	afx_msg void OnBnClickedPieup();
	afx_msg void OnBnClickedHieut();
	afx_msg void OnBnClickedSpace();
	afx_msg void OnBnClickedBkspace();
	afx_msg void OnBnClickedConfirm();
	afx_msg void OnBnClickedEnter();
};
