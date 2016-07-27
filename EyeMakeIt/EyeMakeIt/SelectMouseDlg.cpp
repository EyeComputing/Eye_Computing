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
