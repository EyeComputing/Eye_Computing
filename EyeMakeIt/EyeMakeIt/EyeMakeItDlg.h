
// EyeMakeItDlg.h : ��� ����
//

#pragma once
#include "xSkinButton.h"

/* global  */
extern int selectMouseEvent;

// CEyeMakeItDlg ��ȭ ����
class CEyeMakeItDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CEyeMakeItDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.




/* ����� ���� �Լ� */
	void CEyeMakeItDlg::OnBtnClick(UINT uiID);




// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_EYEMAKEIT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
};
