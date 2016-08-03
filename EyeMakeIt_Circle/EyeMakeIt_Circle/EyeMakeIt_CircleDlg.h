
// EyeMakeIt_CircleDlg.h : ��� ����
//

#pragma once

#include "Hangeul.h"

// CEyeMakeIt_CircleDlg ��ȭ ����
class CEyeMakeIt_CircleDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CEyeMakeIt_CircleDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_EYEMAKEIT_CIRCLE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


	void CEyeMakeIt_CircleDlg::OnBtnClick(UINT uiID);
	void CEyeMakeIt_CircleDlg::InputHangeul(int textCode);
	void CEyeMakeIt_CircleDlg::InputText(CString text);

	Hangeul hangeulInput;


// �����Դϴ�.
protected:
	HICON m_hIcon;
	HWND m_hForegroundWnd;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:

};
