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
	ON_WM_PAINT()
END_MESSAGE_MAP()


// SelectSetCoordinateDlg 메시지 처리기입니다.




/* 사용자 정의 함수 */

// 키보드 입력 받으면 global 변수 숫자 ++ or -- 시켜주기

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


BOOL SelectSetCoordinateDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	// 윈도우 사이즈를 입력받고 그에 맞추어 버튼 사이즈 결정
	ZeroMemory(&WindowSize, sizeof(SIZE));
	WindowSize.cx = (LONG)::GetSystemMetrics(SM_CXFULLSCREEN);
	WindowSize.cy = (LONG)::GetSystemMetrics(SM_CYFULLSCREEN);
	DialogSize.cx = (WindowSize.cx / 1.2);
	DialogSize.cy = (WindowSize.cy / 1.2);

	// 다이얼로그 사이즈 설정
	SetWindowPos(NULL, 0, 0, DialogSize.cx, DialogSize.cy, SWP_NOZORDER);
	CenterWindow(CWnd::GetDesktopWindow()); // 화면의 가운데 위치


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void SelectSetCoordinateDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	CDC MemDC;
	BITMAP bmpInfo;

	// 화면 DC와 호환되는 메모리 DC를 생성
	MemDC.CreateCompatibleDC(&dc);

	// 비트맵 리소스 로딩
	CBitmap bmp;
	CBitmap* pOldBmp = NULL;
	bmp.LoadBitmapW(IDB_M_COR);

	// 로딩된 비트맵 정보 확인
	bmp.GetBitmap(&bmpInfo);

	// 메모리 DC에 선택
	pOldBmp = MemDC.SelectObject(&bmp);

	// 메모리 DC에 들어 있는 비트맵을 화면 DC로 복사하여 출력
	dc.StretchBlt(0, 0, DialogSize.cx, DialogSize.cy, &MemDC, 0, 0, bmpInfo.bmWidth, bmpInfo.bmHeight, SRCCOPY);

	MemDC.SelectObject(pOldBmp);
}
