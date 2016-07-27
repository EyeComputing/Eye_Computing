// SelectSetCoordinateDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "EyeMakeIt.h"
#include "SelectSetCoordinateDlg.h"
#include "afxdialogex.h"


/* global */
POINT set_user_coordinate;


// SelectSetCoordinateDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(SelectSetCoordinateDlg, CDialogEx)

SelectSetCoordinateDlg::SelectSetCoordinateDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(SelectSetCoordinateDlg::IDD, pParent)
{

}

SelectSetCoordinateDlg::~SelectSetCoordinateDlg()
{
}

void SelectSetCoordinateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(SelectSetCoordinateDlg, CDialogEx)
END_MESSAGE_MAP()


// SelectSetCoordinateDlg 메시지 처리기입니다.




/* 사용자 정의 함수 */


// 키보드 입력 받으면 global 변수 숫자 ++ or -- 시켜주기

