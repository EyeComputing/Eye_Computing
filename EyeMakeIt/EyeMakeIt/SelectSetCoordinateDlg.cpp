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
END_MESSAGE_MAP()


// SelectSetCoordinateDlg �޽��� ó�����Դϴ�.




/* ����� ���� �Լ� */

//���콺 ��ǥ �����ϴ� �Լ�
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

// Ű���� �Է� ������ global ���� ���� ++ or -- �����ֱ�

