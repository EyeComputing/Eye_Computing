// SelectSettingDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "EyeMakeIt.h"
#include "SelectSettingDlg.h"
#include "afxdialogex.h"


#include "SelectSetCoordinateDlg.h"


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
}


BEGIN_MESSAGE_MAP(SelectSettingDlg, CDialogEx)
	/* ��ư Ŭ�� �ѹ��� �ϴ� �޼��� ���� */
	ON_COMMAND_RANGE(IDC_BT_coordinate, IDC_BT_coordinate, SelectSettingDlg::OnBtnClick)
END_MESSAGE_MAP()


// SelectSettingDlg �޽��� ó�����Դϴ�.

/* ����� ���� �Լ� */
void SelectSettingDlg::OnBtnClick(UINT uiID)
{
	switch (uiID)
	{
		case IDC_BT_coordinate:
		{
			SelectSetCoordinateDlg *m_pcoordinateDlg;
			m_pcoordinateDlg = new SelectSetCoordinateDlg();
			m_pcoordinateDlg->Create(IDD_Dlg_CoordinateSet, this);
			m_pcoordinateDlg->ShowWindow(SW_SHOW);
			break;
		}/*
		case :
		{
			break;
		}
		case :
		{
			break;
		}
		case :
		{
			break;
		}*/

	}

}