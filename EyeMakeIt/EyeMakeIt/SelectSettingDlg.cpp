// SelectSettingDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "EyeMakeIt.h"
#include "SelectSettingDlg.h"
#include "afxdialogex.h"


#include "SelectSetCoordinateDlg.h"


// SelectSettingDlg 대화 상자입니다.

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
	/* 버튼 클릭 한번에 하는 메세지 매핑 */
	ON_COMMAND_RANGE(IDC_BT_coordinate, IDC_BT_coordinate, SelectSettingDlg::OnBtnClick)
END_MESSAGE_MAP()


// SelectSettingDlg 메시지 처리기입니다.

/* 사용자 정의 함수 */
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