#pragma once

#include "resource.h"

// SelectKeyboardDlg_text ��ȭ �����Դϴ�.

class SelectKeyboardDlg_text : public CDialogEx
{
	DECLARE_DYNAMIC(SelectKeyboardDlg_text)

public:
	SelectKeyboardDlg_text(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~SelectKeyboardDlg_text();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_Dlg_Show_Text };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
