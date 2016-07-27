// SelectScrolldownDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "EyeMakeIt.h"
#include "SelectScrolldownDlg.h"
#include "afxdialogex.h"


// SelectScrolldownDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(SelectScrolldownDlg, CDialogEx)

SelectScrolldownDlg::SelectScrolldownDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(SelectScrolldownDlg::IDD, pParent)
{

}

SelectScrolldownDlg::~SelectScrolldownDlg()
{
}

void SelectScrolldownDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(SelectScrolldownDlg, CDialogEx)
END_MESSAGE_MAP()


// SelectScrolldownDlg 메시지 처리기입니다.
