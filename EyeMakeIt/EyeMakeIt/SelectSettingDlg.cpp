// SelectSettingDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "EyeMakeIt.h"
#include "EyeMakeItDlg.h"
#include "SelectSettingDlg.h"
#include "afxdialogex.h"
#include "SelectSetCoordinateDlg.h"
#include "SelectEnvironmentSetDlg.h"


// SelectSettingDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(SelectSettingDlg, CDialogEx)

SelectSettingDlg::SelectSettingDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(SelectSettingDlg::IDD, pParent)
{

}

SelectSettingDlg::~SelectSettingDlg()
{
}

void SelectSettingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BT_coordinate, m_btn_eye);
	DDX_Control(pDX, IDC_BT_SettingClose, m_btn_cls);
	DDX_Control(pDX, IDC_BT_EnvironmentSet, m_btn_env);
}


BEGIN_MESSAGE_MAP(SelectSettingDlg, CDialogEx)
	/* ��ư Ŭ�� �ѹ��� �ϴ� �޼��� ���� */
	ON_COMMAND_RANGE(IDC_BT_coordinate, IDC_BT_EnvironmentSet, SelectSettingDlg::OnBtnClick)
END_MESSAGE_MAP()


// SelectSettingDlg �޽��� ó�����Դϴ�.

/* ����� ���� �Լ� */
void SelectSettingDlg::OnBtnClick(UINT uiID)
{
	switch (uiID)
	{
		case IDC_BT_EnvironmentSet:
		{
			SelectEnvironmentSetDlg *m_penvironmentDlg;
			m_penvironmentDlg = new SelectEnvironmentSetDlg();
			m_penvironmentDlg->Create(IDD_Dlg_EnvironmentSet, this);
			m_penvironmentDlg->ShowWindow(SW_SHOW);
			break;
		}
		case IDC_BT_coordinate:
		{
			SelectSetCoordinateDlg *m_pcoordinateDlg;
			m_pcoordinateDlg = new SelectSetCoordinateDlg();
			m_pcoordinateDlg->Create(IDD_Dlg_CoordinateSet, this);
			m_pcoordinateDlg->ShowWindow(SW_SHOW);
			break;
		}
		case IDC_BT_SettingClose:
		{
			::SendMessage(GetSafeHwnd(), WM_CLOSE, NULL, NULL);
			break;
		}
	}

}

BOOL SelectSettingDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ������ ����� �Է¹ް� �׿� ���߾� ��ư ������ ����
	ZeroMemory(&WindowSize, sizeof(SIZE));
	WindowSize.cx = (LONG)::GetSystemMetrics(SM_CXFULLSCREEN);
	WindowSize.cy = (LONG)::GetSystemMetrics(SM_CYFULLSCREEN);
	ButtonSize.cx = (WindowSize.cx / 9);
	ButtonSize.cy = (WindowSize.cy / 5);

	// ���α׷� ��ġ ����
	if (((CEyeMakeItDlg *)GetParent())->ProgramPos)
	{
		// true �̸� ����
		SetWindowPos(NULL, ButtonSize.cx * 7, 0, ButtonSize.cx + 10, ButtonSize.cy * 3 + 50, SWP_NOZORDER);
	}
	else
	{
		// false �� ����
		SetWindowPos(NULL, ButtonSize.cx * 1, 0, ButtonSize.cx + 10, ButtonSize.cy * 3 + 50, SWP_NOZORDER);
	}


	// ��ư ��ǥ ����
	GetDlgItem(IDC_BT_EnvironmentSet)->SetWindowPos(NULL, 0, ButtonSize.cy * 0, ButtonSize.cx, ButtonSize.cy, SWP_NOZORDER);
	GetDlgItem(IDC_BT_coordinate)->SetWindowPos(NULL, 0, ButtonSize.cy * 1, ButtonSize.cx, ButtonSize.cy, SWP_NOZORDER);
	GetDlgItem(IDC_BT_SettingClose)->SetWindowPos(NULL, 0, ButtonSize.cy * 2, ButtonSize.cx, ButtonSize.cy, SWP_NOZORDER);

	m_btn_env.SetSkin(IDB_M_ENV, IDB_M_ENV, IDB_M_ENV_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	m_btn_eye.SetSkin(IDB_M_EYE, IDB_M_EYE, IDB_M_EYE_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	m_btn_cls.SetSkin(IDB_BTN_CLOSE, IDB_BTN_CLOSE, IDB_BTN_CLOSE_OVER, 0, 0, IDB_MASK, 1, 0, 4);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.

}
