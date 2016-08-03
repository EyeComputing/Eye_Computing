// SelectSetCoordinateDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "EyeMakeIt.h"
#include "SelectSetCoordinateDlg.h"
#include "afxdialogex.h"


/* global */
POINT set_user_coordinate;


// SelectSetCoordinateDlg ��ȭ �����Դϴ�.

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


// SelectSetCoordinateDlg �޽��� ó�����Դϴ�.




/* ����� ���� �Լ� */

// Ű���� �Է� ������ global ���� ���� ++ or -- �����ֱ�

BOOL SelectSetCoordinateDlg::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == WM_KEYDOWN)
	{
		switch (pMsg->wParam)
		{
			//A key- �������� ��ǥ�� �̵���Ű��
		case 0x41:
			set_user_coordinate.x -= 5;
			return 1;
			//D key - ���������� ��ǥ�� �̵���Ű�� 
		case 0x44:
			set_user_coordinate.x += 5;
			return 1;
			//W key - ���� �̵���Ű��
		case 0x57:
			set_user_coordinate.y -= 5;
			return 1;
			//S key - �Ʒ��� �̵���Ű��
		case 0x53:
			set_user_coordinate.y += 5;
			return 1;
		}
	}
	return 0; //�� �̻� message �� ó������ �ʱ� �ٶ��ٸ� 0�� �ƴ� �� return
}


BOOL SelectSetCoordinateDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	// ������ ����� �Է¹ް� �׿� ���߾� ��ư ������ ����
	ZeroMemory(&WindowSize, sizeof(SIZE));
	WindowSize.cx = (LONG)::GetSystemMetrics(SM_CXFULLSCREEN);
	WindowSize.cy = (LONG)::GetSystemMetrics(SM_CYFULLSCREEN);
	DialogSize.cx = (WindowSize.cx / 1.2);
	DialogSize.cy = (WindowSize.cy / 1.2);

	// ���̾�α� ������ ����
	SetWindowPos(NULL, 0, 0, DialogSize.cx, DialogSize.cy, SWP_NOZORDER);
	CenterWindow(CWnd::GetDesktopWindow()); // ȭ���� ��� ��ġ


	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void SelectSetCoordinateDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	CDC MemDC;
	BITMAP bmpInfo;

	// ȭ�� DC�� ȣȯ�Ǵ� �޸� DC�� ����
	MemDC.CreateCompatibleDC(&dc);

	// ��Ʈ�� ���ҽ� �ε�
	CBitmap bmp;
	CBitmap* pOldBmp = NULL;
	bmp.LoadBitmapW(IDB_M_COR);

	// �ε��� ��Ʈ�� ���� Ȯ��
	bmp.GetBitmap(&bmpInfo);

	// �޸� DC�� ����
	pOldBmp = MemDC.SelectObject(&bmp);

	// �޸� DC�� ��� �ִ� ��Ʈ���� ȭ�� DC�� �����Ͽ� ���
	dc.StretchBlt(0, 0, DialogSize.cx, DialogSize.cy, &MemDC, 0, 0, bmpInfo.bmWidth, bmpInfo.bmHeight, SRCCOPY);

	MemDC.SelectObject(pOldBmp);
}
