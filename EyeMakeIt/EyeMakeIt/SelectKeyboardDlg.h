#pragma once


// SelectKeyboardDlg ��ȭ �����Դϴ�.

class SelectKeyboardDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SelectKeyboardDlg)

public:
	SelectKeyboardDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~SelectKeyboardDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_Dlg_Keyboard };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
