#pragma once

#include "resource.h"

// SelectSettingDlg ��ȭ �����Դϴ�.

class SelectSettingDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SelectSettingDlg)

public:
	SelectSettingDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~SelectSettingDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_Dlg_Setting };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
