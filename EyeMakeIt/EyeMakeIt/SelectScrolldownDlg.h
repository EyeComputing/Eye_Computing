#pragma once


// SelectScrolldownDlg 대화 상자입니다.

class SelectScrolldownDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SelectScrolldownDlg)

public:
	SelectScrolldownDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~SelectScrolldownDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_Dlg_Scroll_Down };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
