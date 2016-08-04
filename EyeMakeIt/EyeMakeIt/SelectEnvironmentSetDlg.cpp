// SelectEnvironmentSetDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "EyeMakeIt.h"
#include "EyeMakeItDlg.h"
#include "SelectEnvironmentSetDlg.h"
#include "afxdialogex.h"


// SelectEnvironmentSetDlg ��ȭ �����Դϴ�.

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


// SelectEnvironmentSetDlg �޽��� ó�����Դϴ�.


BOOL SelectEnvironmentSetDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void SelectEnvironmentSetDlg::OnBnClickedPosLeft()
{
	((CEyeMakeItDlg *)GetParent())->ProgramPos = FALSE; // ���α׷� ��ġ ��������
}


void SelectEnvironmentSetDlg::OnBnClickedPosRight()
{
	((CEyeMakeItDlg *)GetParent())->ProgramPos = TRUE; // ���α׷� ��ġ ����������
}


void SelectEnvironmentSetDlg::OnBnClickedOk()
{
	// UpdateData(TRUE); // ������ ������Ʈ
	// Invalidate(TRUE);
	CWnd *pWnd = (CEyeMakeItDlg*)::AfxGetMainWnd();
	HWND hWnd = pWnd->m_hWnd;
	::SendMessage(hWnd, WM_INITDIALOG, 0, 0);
	CDialogEx::OnOK();
}
