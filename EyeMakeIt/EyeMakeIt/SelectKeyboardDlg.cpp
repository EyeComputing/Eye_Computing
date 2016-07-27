// SelectKeyboardDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "EyeMakeIt.h"
#include "SelectKeyboardDlg.h"
#include "afxdialogex.h"


// SelectKeyboardDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(SelectKeyboardDlg, CDialogEx)

SelectKeyboardDlg::SelectKeyboardDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(SelectKeyboardDlg::IDD, pParent)
{

}

SelectKeyboardDlg::~SelectKeyboardDlg()
{
}

void SelectKeyboardDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(SelectKeyboardDlg, CDialogEx)
END_MESSAGE_MAP()


// SelectKeyboardDlg 메시지 처리기입니다.
