#pragma once


// TextOn ��ȭ �����Դϴ�.

//#include "Eye_Computing_DialogDlg.h"

class TextOn : public CDialog
{
	DECLARE_DYNAMIC(TextOn)

public:
	TextOn(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~TextOn();

	//CEye_Computing_DialogDlg *m_p;

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
};
