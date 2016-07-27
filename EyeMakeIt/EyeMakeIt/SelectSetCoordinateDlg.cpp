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

//마우스 좌표 조정하는 함수
BOOL SelectSetCoordinateDlg::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == WM_KEYDOWN)
	{
		switch (pMsg->wParam)
		{
			//A key- 왼쪽으로 좌표점 이동시키기
		case 0x41:
			set_user_coordinate.x -= 5;
			return 1;
			//D key - 오른쪽으로 좌표점 이동시키기 
		case 0x44:
			set_user_coordinate.x += 5;
			return 1;
			//W key - 위로 이동시키기
		case 0x57:
			set_user_coordinate.y -= 5;
			return 1;
			//S key - 아래로 이동시키기
		case 0x53:
			set_user_coordinate.y += 5;
			return 1;
		}
	}
	return 0; //더 이상 message 가 처리되지 않길 바란다면 0이 아닌 값 return
}

// 키보드 입력 받으면 global 변수 숫자 ++ or -- 시켜주기

