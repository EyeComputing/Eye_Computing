// TextOn.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Eye_Computing_Dialog.h"
#include "TextOn.h"
#include "afxdialogex.h"
//#include "Eye_Computing_DialogDlg.h"

// TextOn ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(TextOn, CDialog)

TextOn::TextOn(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOG1, pParent)
{
	/*
	m_p = new CEye_Computing_DialogDlg();
	m_p->Create(IDD_EYE_COMPUTING_DIALOG_DIALOG, this);
	m_p->ShowWindow(SW_SHOW);

	Create(IDD_DIALOG1, this);
	ShowWindow(SW_SHOW);
	*/
}

TextOn::~TextOn()
{
}

void TextOn::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(TextOn, CDialog)
	ON_EN_CHANGE(IDC_EDIT1, &TextOn::OnEnChangeEdit1)
END_MESSAGE_MAP()


// TextOn �޽��� ó�����Դϴ�.


void TextOn::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialog::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}
