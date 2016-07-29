#pragma once

#include "resource.h"
#include "xSkinButton.h"

// SelectSettingDlg 대화 상자입니다.

class SelectSettingDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SelectSettingDlg)

public:
	SelectSettingDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~SelectSettingDlg();

	/* 사용자 정의 함수 */
	void SelectSettingDlg::OnBtnClick(UINT uiID);

	// 윈도우 사이즈와 버튼 사이즈 값을 입력받기 위한 변수
	SIZE WindowSize;
	SIZE ButtonSize;

// 대화 상자 데이터입니다.
	enum { IDD = IDD_Dlg_Setting };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CxSkinButton m_btn_eye;
};
