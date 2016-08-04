// SelectSettingDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "EyeMakeIt.h"
#include "EyeMakeItDlg.h"
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
	DDX_Control(pDX, IDC_BT_SettingClose, m_btn_cls);
	DDX_Control(pDX, IDC_BT_EnvironmentSet, m_btn_env);
}


BEGIN_MESSAGE_MAP(SelectSettingDlg, CDialogEx)
	/* 버튼 클릭 한번에 하는 메세지 매핑 */
	ON_COMMAND_RANGE(IDC_BT_coordinate, IDC_BT_EnvironmentSet, SelectSettingDlg::OnBtnClick)
END_MESSAGE_MAP()


// SelectSettingDlg 메시지 처리기입니다.

/* 사용자 정의 함수 */
void SelectSettingDlg::OnBtnClick(UINT uiID)
{
	switch (uiID)
	{
		case IDC_BT_EnvironmentSet:
		{
			// 툴바 위치 변경
			((CEyeMakeItDlg *)GetTopLevelParent())->ProgramPos = !(((CEyeMakeItDlg *)GetTopLevelParent())->ProgramPos); // 토글
			UpdateData(TRUE);
			ChangeProgramPos(); // 다이얼로그 자신 위치 변경
			((CEyeMakeItDlg *)GetTopLevelParent())->ChangeProgramPos(); // 부모 다이얼로그 위치 변경


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

	// 윈도우 사이즈를 입력받고 그에 맞추어 버튼 사이즈 결정
	ZeroMemory(&WindowSize, sizeof(SIZE));
	WindowSize.cx = (LONG)::GetSystemMetrics(SM_CXFULLSCREEN);
	WindowSize.cy = (LONG)::GetSystemMetrics(SM_CYFULLSCREEN);
	ButtonSize.cx = (WindowSize.cx / 9);
	ButtonSize.cy = (WindowSize.cy / 5);

	// 프로그램 위치 설정
	ChangeProgramPos();



	// 버튼 좌표 설정
	GetDlgItem(IDC_BT_EnvironmentSet)->SetWindowPos(NULL, 0, ButtonSize.cy * 0, ButtonSize.cx, ButtonSize.cy, SWP_NOZORDER);
	GetDlgItem(IDC_BT_coordinate)->SetWindowPos(NULL, 0, ButtonSize.cy * 1, ButtonSize.cx, ButtonSize.cy, SWP_NOZORDER);
	GetDlgItem(IDC_BT_SettingClose)->SetWindowPos(NULL, 0, ButtonSize.cy * 2, ButtonSize.cx, ButtonSize.cy, SWP_NOZORDER);


	if (((CEyeMakeItDlg *)GetParent())->ProgramPos)
	{
		// true 일 땐 오른쪽 화살표 버튼 스킨
		m_btn_env.SetSkin(IDB_M_LFT, IDB_M_LFT, IDB_M_LFT_OVER, 0, 0, IDB_MASK, 1, 0, 4); // 버튼 이미지 변경
	}
	else
	{
		// false 일 땐 왼쪽 화살표 버튼 스킨
		m_btn_env.SetSkin(IDB_M_RGT, IDB_M_RGT, IDB_M_RGT_OVER, 0, 0, IDB_MASK, 1, 0, 4); // 버튼 이미지 변경
	}
	m_btn_eye.SetSkin(IDB_M_EYE, IDB_M_EYE, IDB_M_EYE_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	m_btn_cls.SetSkin(IDB_BTN_CLOSE, IDB_BTN_CLOSE, IDB_BTN_CLOSE_OVER, 0, 0, IDB_MASK, 1, 0, 4);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.

}

void SelectSettingDlg::ChangeProgramPos()
{
	if (((CEyeMakeItDlg *)GetParent())->ProgramPos)
	{
		// true 이면 우측
		m_btn_env.SetSkin(IDB_M_LFT, IDB_M_LFT, IDB_M_LFT_OVER, 0, 0, IDB_MASK, 1, 0, 4); // 버튼 이미지 변경
		SetWindowPos(NULL, ButtonSize.cx * 7, 0, ButtonSize.cx + 10, ButtonSize.cy * 3 + 50, SWP_NOZORDER);
	}
	else
	{
		// false 면 좌측
		m_btn_env.SetSkin(IDB_M_RGT, IDB_M_RGT, IDB_M_RGT_OVER, 0, 0, IDB_MASK, 1, 0, 4); // 버튼 이미지 변경
		SetWindowPos(NULL, ButtonSize.cx * 1, 0, ButtonSize.cx + 10, ButtonSize.cy * 3 + 50, SWP_NOZORDER);
	}
	Invalidate(TRUE);
}