#pragma once


// TextOn 대화 상자입니다.

//#include "Eye_Computing_DialogDlg.h"

class TextOn : public CDialog
{
	DECLARE_DYNAMIC(TextOn)

public:
	TextOn(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~TextOn();

	//CEye_Computing_DialogDlg *m_p;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
};
