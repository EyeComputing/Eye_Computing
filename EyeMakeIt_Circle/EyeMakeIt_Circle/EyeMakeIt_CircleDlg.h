
// EyeMakeIt_CircleDlg.h : ��� ����
//

#pragma once


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


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};
