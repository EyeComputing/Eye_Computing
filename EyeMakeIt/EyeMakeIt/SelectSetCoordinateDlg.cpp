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


// Ű���� �Է� ������ global ���� ���� ++ or -- �����ֱ�

