#pragma once

#include "resource.h"

// SelectSettingDlg 대화 상자입니다.

class SelectSettingDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SelectSettingDlg)

public:
	SelectSettingDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~SelectSettingDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_Dlg_Setting };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
