#pragma once

#include "resource.h"
#include "xSkinButton.h"

// SelectSettingDlg ��ȭ �����Դϴ�.

class SelectSettingDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SelectSettingDlg)

public:
	SelectSettingDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~SelectSettingDlg();

	/* ����� ���� �Լ� */
	void SelectSettingDlg::OnBtnClick(UINT uiID);

	// ������ ������� ��ư ������ ���� �Է¹ޱ� ���� ����
	SIZE WindowSize;
	SIZE ButtonSize;

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_Dlg_Setting };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CxSkinButton m_btn_eye;
};
