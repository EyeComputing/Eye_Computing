#pragma once


// CFirstSelectDlg 대화 상자입니다.

class CFirstSelectDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CFirstSelectDlg)

public:
	CFirstSelectDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CFirstSelectDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_FirstSelect };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedKeyboard();
};
