#pragma once


// SelectScrolldownDlg ��ȭ �����Դϴ�.

class SelectScrolldownDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SelectScrolldownDlg)

public:
	SelectScrolldownDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~SelectScrolldownDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_Dlg_Scroll_Down };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
