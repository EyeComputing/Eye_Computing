
// Hands_free_Computing_ProgramDlg.h : ��� ����
//

#pragma once


// CHands_free_Computing_ProgramDlg ��ȭ ����
class CHands_free_Computing_ProgramDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CHands_free_Computing_ProgramDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_HANDS_FREE_COMPUTING_PROGRAM_DIALOG };

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
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedFirstselect();
};
