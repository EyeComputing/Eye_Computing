#pragma once
#include "afxwin.h"


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
public:
	virtual BOOL OnInitDialog();

	// ������ ������� ��ư ������ ���� �Է¹ޱ� ���� ����
	SIZE WindowSize;
	SIZE ButtonSize;
	CxSkinButton m_btn_lcl;
	CxSkinButton m_btn_rcl;
	CxSkinButton m_btn_dcl;
	CxSkinButton m_btn_rag;
	CButton btn_close;
};
