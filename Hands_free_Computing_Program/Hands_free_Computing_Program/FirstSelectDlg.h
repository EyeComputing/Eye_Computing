#pragma once


// CFirstSelectDlg ��ȭ �����Դϴ�.

class CFirstSelectDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CFirstSelectDlg)

public:
	CFirstSelectDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CFirstSelectDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_FirstSelect };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedKeyboard();
};
