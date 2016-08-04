
// EyeMakeItDlg.h : ��� ����
//

#pragma once
#include "xSkinButton.h"
#include "afxwin.h"

/* global  */
extern int selectMouseEvent;

static BOOL CALLBACK EnumWindowCallBack(HWND hwnd, LPARAM lParam); // �ݹ��Լ�

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
	HWND m_hForegroundWnd;
	// ������ �޽��� �� �Լ�
	void CEyeMakeItDlg::OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);

	// ������ ������� ��ư ������ ���� �Է¹ޱ� ���� ����
	SIZE WindowSize;
	SIZE ButtonSize;

	// ���� ��ġ�� �����ϱ� ���� ����
	BOOL ProgramPos;

	CxSkinButton m_btn_mos;
	CxSkinButton m_btn_scu;
	CxSkinButton m_btn_kbd;
	CxSkinButton m_btn_scd;
	CxSkinButton m_btn_set;
	CxSkinButton btn_first_close;
	BOOL PreTranslateMessage(MSG* pMsg);
	void ChangeProgramPos();
};
