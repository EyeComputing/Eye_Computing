#pragma once


// SelectScrollupDlg ��ȭ �����Դϴ�.

class SelectScrollupDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SelectScrollupDlg)

public:
	SelectScrollupDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~SelectScrollupDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_Dlg_Scroll_Up };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
