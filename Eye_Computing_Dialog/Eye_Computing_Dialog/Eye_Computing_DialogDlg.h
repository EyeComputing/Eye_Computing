
// Eye_Computing_DialogDlg.h : ��� ����
//

#pragma once
#include "afxwin.h"
#include "xSkinButton.h"


// CEye_Computing_DialogDlg ��ȭ ����
class CEye_Computing_DialogDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CEye_Computing_DialogDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_EYE_COMPUTING_DIALOG_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;
	HWND m_hForegroundWnd;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();

	//���� ���� �ʱ�ȭ �Լ�
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
