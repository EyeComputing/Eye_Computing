#pragma once


// SelectSetCoordinateDlg ��ȭ �����Դϴ�.

class SelectSetCoordinateDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SelectSetCoordinateDlg)

public:
	SelectSetCoordinateDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~SelectSetCoordinateDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_Dlg_CoordinateSet };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
