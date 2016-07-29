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
	DDX_Control(pDX, IDC_BT_M_Lclick, m_btn_lcl);
	DDX_Control(pDX, IDC_BT_M_Rclick, m_btn_rcl);
	DDX_Control(pDX, IDC_BT_M_DBclick, m_btn_dcl);
	DDX_Control(pDX, IDC_BT_M_Drag, m_btn_rag);
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


BOOL SelectMouseDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ������ ����� �Է¹ް� �׿� ���߾� ��ư ������ ����
	ZeroMemory(&WindowSize, sizeof(SIZE));
	WindowSize.cx = (LONG)::GetSystemMetrics(SM_CXFULLSCREEN);
	WindowSize.cy = (LONG)::GetSystemMetrics(SM_CYFULLSCREEN);
	ButtonSize.cx = (WindowSize.cx / 9);
	ButtonSize.cy = (WindowSize.cy / 5);

	// ���α׷� ��ġ ����(����)
	SetWindowPos(NULL, ButtonSize.cx * 7, 0, ButtonSize.cx + 10, ButtonSize.cy * 4 + 50, SWP_NOZORDER);

	// ��ư ��ǥ ����
	GetDlgItem(IDC_BT_M_Lclick)->SetWindowPos(NULL, 0, ButtonSize.cy * 0, ButtonSize.cx, ButtonSize.cy, SWP_NOZORDER);
	GetDlgItem(IDC_BT_M_Rclick)->SetWindowPos(NULL, 0, ButtonSize.cy * 1, ButtonSize.cx, ButtonSize.cy, SWP_NOZORDER);
	GetDlgItem(IDC_BT_M_DBclick)->SetWindowPos(NULL, 0, ButtonSize.cy * 2, ButtonSize.cx, ButtonSize.cy, SWP_NOZORDER);
	GetDlgItem(IDC_BT_M_Drag)->SetWindowPos(NULL, 0, ButtonSize.cy * 3, ButtonSize.cx, ButtonSize.cy, SWP_NOZORDER);

	m_btn_lcl.SetSkin(IDB_M_LCL, IDB_M_LCL, IDB_M_LCL_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	m_btn_rcl.SetSkin(IDB_M_RCL, IDB_M_RCL, IDB_M_RCL_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	m_btn_dcl.SetSkin(IDB_M_DCL, IDB_M_DCL, IDB_M_DCL_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	m_btn_rag.SetSkin(IDB_M_RAG, IDB_M_RAG, IDB_M_RAG_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}
