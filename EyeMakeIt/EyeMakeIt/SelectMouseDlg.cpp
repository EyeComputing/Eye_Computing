// SelectMouseDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "EyeMakeIt.h"
#include "SelectMouseDlg.h"
#include "afxdialogex.h"


// SelectMouseDlg ��ȭ �����Դϴ�.

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


// SelectMouseDlg �޽��� ó�����Դϴ�.

/* ����� ���� �Լ� */

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
