// SelectEnvironmentSetDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "EyeMakeIt.h"
#include "EyeMakeItDlg.h"
#include "SelectEnvironmentSetDlg.h"
#include "afxdialogex.h"


// SelectEnvironmentSetDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(SelectEnvironmentSetDlg, CDialogEx)

SelectEnvironmentSetDlg::SelectEnvironmentSetDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_Dlg_EnvironmentSet, pParent)
{

}

SelectEnvironmentSetDlg::~SelectEnvironmentSetDlg()
{
}

void SelectEnvironmentSetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(SelectEnvironmentSetDlg, CDialogEx)
	ON_BN_CLICKED(IDC_POS_LEFT, &SelectEnvironmentSetDlg::OnBnClickedPosLeft)
	ON_BN_CLICKED(IDC_POS_RIGHT, &SelectEnvironmentSetDlg::OnBnClickedPosRight)
	ON_BN_CLICKED(IDOK, &SelectEnvironmentSetDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// SelectEnvironmentSetDlg 메시지 처리기입니다.


BOOL SelectEnvironmentSetDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void SelectEnvironmentSetDlg::OnBnClickedPosLeft()
{
	((CEyeMakeItDlg *)GetParent())->ProgramPos = FALSE; // 프로그램 위치 왼쪽으로
}


void SelectEnvironmentSetDlg::OnBnClickedPosRight()
{
	((CEyeMakeItDlg *)GetParent())->ProgramPos = TRUE; // 프로그램 위치 오른쪽으로
}


void SelectEnvironmentSetDlg::OnBnClickedOk()
{
	// UpdateData(TRUE); // 데이터 업데이트
	// Invalidate(TRUE);
	CWnd *pWnd = (CEyeMakeItDlg*)::AfxGetMainWnd();
	HWND hWnd = pWnd->m_hWnd;
	::SendMessage(hWnd, WM_INITDIALOG, 0, 0);
	CDialogEx::OnOK();
}
