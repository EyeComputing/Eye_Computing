#pragma once


// SelectMouseDlg ��ȭ �����Դϴ�.

class SelectMouseDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SelectMouseDlg)

public:
	SelectMouseDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~SelectMouseDlg();

	/* ���� */
	void SelectMouseDlg::OnBtnClick(UINT uiID);

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_Dlg_Mouse };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
