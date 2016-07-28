#pragma once

#include "resource.h"

// SelectKeyboardDlg_text 대화 상자입니다.

class SelectKeyboardDlg_text : public CDialogEx
{
	DECLARE_DYNAMIC(SelectKeyboardDlg_text)

public:
	SelectKeyboardDlg_text(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~SelectKeyboardDlg_text();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_Dlg_Show_Text };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
