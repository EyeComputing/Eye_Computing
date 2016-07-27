#pragma once


// SelectScrollupDlg 대화 상자입니다.

class SelectScrollupDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SelectScrollupDlg)

public:
	SelectScrollupDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~SelectScrollupDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_Dlg_Scroll_Up };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
