#pragma once

#include "resource.h"

// SelectEnvironmentSetDlg ��ȭ �����Դϴ�.

class SelectEnvironmentSetDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SelectEnvironmentSetDlg)

public:
	SelectEnvironmentSetDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~SelectEnvironmentSetDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Dlg_EnvironmentSet };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedPosLeft();
	afx_msg void OnBnClickedPosRight();
	afx_msg void OnBnClickedOk();
};
