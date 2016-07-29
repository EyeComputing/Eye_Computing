// SelectMouseDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "EyeMakeIt.h"
#include "EyeMakeItDlg.h"
#include "SelectMouseDlg.h"
#include "afxdialogex.h"

//mouse click message 구분위한 상수
#define LCLICKED 0
#define RCLICKED 1
#define DOUBLECLICKED 2
#define DRAGCLICKED 3

// SelectMouseDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(SelectMouseDlg, CDialogEx)

SelectMouseDlg::SelectMouseDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(SelectMouseDlg::IDD, pParent)
{

}

SelectMouseDlg::~SelectMouseDlg()
{
}

void SelectMouseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BT_M_Lclick, m_btn_lcl);
	DDX_Control(pDX, IDC_BT_M_Rclick, m_btn_rcl);
	DDX_Control(pDX, IDC_BT_M_DBclick, m_btn_dcl);
	DDX_Control(pDX, IDC_BT_M_Drag, m_btn_rag);
}


BEGIN_MESSAGE_MAP(SelectMouseDlg, CDialogEx)
	/* 버튼 클릭 한번에 하는 메세지 매핑 */
	ON_COMMAND_RANGE(IDC_BT_M_Lclick, IDC_BT_M_Drag, SelectMouseDlg::OnBtnClick)
END_MESSAGE_MAP()


// SelectMouseDlg 메시지 처리기입니다.

/* 사용자 정의 함수 */
void SelectMouseDlg::OnBtnClick(UINT uiID)
{
	switch (uiID)
	{
		case IDC_BT_M_Lclick:
		{
			selectMouseEvent = LCLICKED;
			break;
		}
		case IDC_BT_M_Rclick:
		{	
			selectMouseEvent = RCLICKED;
			break;
		}
		case IDC_BT_M_DBclick:
		{	
			selectMouseEvent = DOUBLECLICKED;
			break;
		}
		case IDC_BT_M_Drag:
		{
			selectMouseEvent = DRAGCLICKED;
			break;
		}

	}

}


BOOL SelectMouseDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 윈도우 사이즈를 입력받고 그에 맞추어 버튼 사이즈 결정
	ZeroMemory(&WindowSize, sizeof(SIZE));
	WindowSize.cx = (LONG)::GetSystemMetrics(SM_CXFULLSCREEN);
	WindowSize.cy = (LONG)::GetSystemMetrics(SM_CYFULLSCREEN);
	ButtonSize.cx = (WindowSize.cx / 9);
	ButtonSize.cy = (WindowSize.cy / 5);

	// 프로그램 위치 설정(우측)
	SetWindowPos(NULL, ButtonSize.cx * 7, 0, ButtonSize.cx + 10, ButtonSize.cy * 4 + 50, SWP_NOZORDER);

	// 버튼 좌표 설정
	GetDlgItem(IDC_BT_M_Lclick)->SetWindowPos(NULL, 0, ButtonSize.cy * 0, ButtonSize.cx, ButtonSize.cy, SWP_NOZORDER);
	GetDlgItem(IDC_BT_M_Rclick)->SetWindowPos(NULL, 0, ButtonSize.cy * 1, ButtonSize.cx, ButtonSize.cy, SWP_NOZORDER);
	GetDlgItem(IDC_BT_M_DBclick)->SetWindowPos(NULL, 0, ButtonSize.cy * 2, ButtonSize.cx, ButtonSize.cy, SWP_NOZORDER);
	GetDlgItem(IDC_BT_M_Drag)->SetWindowPos(NULL, 0, ButtonSize.cy * 3, ButtonSize.cx, ButtonSize.cy, SWP_NOZORDER);

	m_btn_lcl.SetSkin(IDB_M_LCL, IDB_M_LCL, IDB_M_LCL_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	m_btn_rcl.SetSkin(IDB_M_RCL, IDB_M_RCL, IDB_M_RCL_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	m_btn_dcl.SetSkin(IDB_M_DCL, IDB_M_DCL, IDB_M_DCL_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	m_btn_rag.SetSkin(IDB_M_RAG, IDB_M_RAG, IDB_M_RAG_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
