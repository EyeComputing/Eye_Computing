// FirstSelectDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Hands_free_Computing_Program.h"
#include "FirstSelectDlg.h"
#include "afxdialogex.h"

#include "Hands_free_Computing_ProgramDlg.h"


// CFirstSelectDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CFirstSelectDlg, CDialogEx)

CFirstSelectDlg::CFirstSelectDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFirstSelectDlg::IDD, pParent)
{

}

CFirstSelectDlg::~CFirstSelectDlg()
{
}

void CFirstSelectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CFirstSelectDlg, CDialogEx)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_KeyBoard, &CFirstSelectDlg::OnBnClickedKeyboard)
END_MESSAGE_MAP()


// CFirstSelectDlg 메시지 처리기입니다.


void CFirstSelectDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	//CHands_free_Computing_ProgramDlg *m_pHandsDlg;
	//m_pHandsDlg = new CHands_free_Computing_ProgramDlg();
	//m_pHandsDlg->Create(IDD_HANDS_FREE_COMPUTING_PROGRAM_DIALOG, this);
	//m_pHandsDlg->ShowWindow(SW_SHOW);

	::ShowWindow(GetParent()->m_hWnd, SW_SHOWNORMAL);

	//((CHands_free_Computing_ProgramDlg*)GetParent())->ShowWindow(SW_SHOW);	
	

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}


void CFirstSelectDlg::OnBnClickedKeyboard()
{
	ShellExecute(NULL, _T("Open"), _T("C:\\Workspace\\Eye_computing\\Hands_free_Computing_Program\\Hands_free_Computing_Program\\Eye_Computing_Dialog.exe"), NULL, NULL, SW_SHOW);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
