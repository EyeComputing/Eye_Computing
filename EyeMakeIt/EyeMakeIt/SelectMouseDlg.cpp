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
END_MESSAGE_MAP()


// SelectMouseDlg 메시지 처리기입니다.
