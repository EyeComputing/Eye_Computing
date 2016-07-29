// TextOn.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Eye_Computing_Dialog.h"
#include "TextOn.h"
#include "afxdialogex.h"
//#include "Eye_Computing_DialogDlg.h"

// TextOn 대화 상자입니다.

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


// TextOn 메시지 처리기입니다.


void TextOn::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialog::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
