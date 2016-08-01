#pragma once
#include "afxwin.h"


// SelectMouseDlg 대화 상자입니다.

class SelectMouseDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SelectMouseDlg)

public:
	SelectMouseDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~SelectMouseDlg();

	/* 설정 */
	void SelectMouseDlg::OnBtnClick(UINT uiID);

// 대화 상자 데이터입니다.
	enum { IDD = IDD_Dlg_Mouse };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();

	// 윈도우 사이즈와 버튼 사이즈 값을 입력받기 위한 변수
	SIZE WindowSize;
	SIZE ButtonSize;
	CxSkinButton m_btn_lcl;
	CxSkinButton m_btn_rcl;
	CxSkinButton m_btn_dcl;
	CxSkinButton m_btn_rag;
	CButton btn_close;
};
