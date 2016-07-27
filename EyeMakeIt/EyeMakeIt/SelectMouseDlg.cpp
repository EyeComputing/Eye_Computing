// SelectMouseDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "EyeMakeIt.h"
#include "SelectMouseDlg.h"
#include "afxdialogex.h"


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
	ON_COMMAND_RANGE(IDC_BT_M_Lclick, IDC_BT_M_Drag, SelectMouseDlg::OnBtnClick)
END_MESSAGE_MAP()


// SelectMouseDlg 메시지 처리기입니다.

/* 사용자 정의 함수 */

void SelectMouseDlg::OnBtnClick(UINT uiID)
{
	switch (uiID)
	{
		case IDC_BT_Mouse:
		{
			break;
		}
		case IDC_BT_Scroll_Up:
		{	
			break;
		}
		case IDC_BT_Keyboard:
		{	
			break;
		}
		case IDC_BT_Scroll_Down:
		{	
			break;
		}

	}

}
