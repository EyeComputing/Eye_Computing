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
	DDX_Control(pDX, IDC_BT_coordinate, m_btn_eye);
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

BOOL SelectSettingDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 윈도우 사이즈를 입력받고 그에 맞추어 버튼 사이즈 결정
	ZeroMemory(&WindowSize, sizeof(SIZE));
	WindowSize.cx = (LONG)::GetSystemMetrics(SM_CXFULLSCREEN);
	WindowSize.cy = (LONG)::GetSystemMetrics(SM_CYFULLSCREEN);
	ButtonSize.cx = (WindowSize.cx / 9);
	ButtonSize.cy = (WindowSize.cy / 5);

	// 프로그램 위치 설정(우측)
	SetWindowPos(NULL, ButtonSize.cx * 7, 0, ButtonSize.cx + 10, ButtonSize.cy + 50, SWP_NOZORDER);
	// 버튼 좌표 설정
	GetDlgItem(IDC_BT_coordinate)->SetWindowPos(NULL, 0, ButtonSize.cy * 0, ButtonSize.cx, ButtonSize.cy, SWP_NOZORDER);

	m_btn_eye.SetSkin(IDB_M_EYE, IDB_M_EYE, IDB_M_EYE_OVER, 0, 0, IDB_MASK, 1, 0, 4);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.

}
