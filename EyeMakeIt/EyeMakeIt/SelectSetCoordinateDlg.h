#pragma once

#include "resource.h"

/* global */
extern POINT set_user_coordinate;


// SelectSetCoordinateDlg ��ȭ �����Դϴ�.

class SelectSetCoordinateDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SelectSetCoordinateDlg)

public:
	SelectSetCoordinateDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~SelectSetCoordinateDlg();
	virtual BOOL PreTranslateMessage(MSG* pMsg);

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_Dlg_CoordinateSet };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
