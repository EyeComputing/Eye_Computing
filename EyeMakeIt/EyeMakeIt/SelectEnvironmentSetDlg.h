#pragma once

#include "resource.h"

// SelectEnvironmentSetDlg 대화 상자입니다.

class SelectEnvironmentSetDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SelectEnvironmentSetDlg)

public:
	SelectEnvironmentSetDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~SelectEnvironmentSetDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Dlg_EnvironmentSet };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedPosLeft();
	afx_msg void OnBnClickedPosRight();
	afx_msg void OnBnClickedOk();
};
