// SelectMouseDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "EyeMakeIt.h"
#include "EyeMakeItDlg.h"
#include "SelectMouseDlg.h"
#include "afxdialogex.h"

//mouse click message �������� ���
#define LCLICKED 0
#define RCLICKED 1
#define DOUBLECLICKED 2
#define DRAGCLICKED 3

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
	/* ��ư Ŭ�� �ѹ��� �ϴ� �޼��� ���� */
	ON_COMMAND_RANGE(IDC_BT_M_Lclick, IDC_BT_M_Drag, SelectMouseDlg::OnBtnClick)
END_MESSAGE_MAP()


// SelectMouseDlg �޽��� ó�����Դϴ�.

/* ����� ���� �Լ� */
void SelectMouseDlg::OnBtnClick(UINT uiID)
{
	switch (uiID)
	{
		case IDC_BT_M_Lclick:
		{
			selectMouseEvent = LCLICKED;
			break;
		}
		case IDC_BT_M_Rclick:
		{	
			selectMouseEvent = RCLICKED;
			break;
		}
		case IDC_BT_M_DBclick:
		{	
			selectMouseEvent = DOUBLECLICKED;
			break;
		}
		case IDC_BT_M_Drag:
		{
			selectMouseEvent = DRAGCLICKED;
			break;
		}

	}

}
