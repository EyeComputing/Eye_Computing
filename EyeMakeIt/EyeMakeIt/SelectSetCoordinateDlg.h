#pragma once

#include "resource.h"

/* global */
extern POINT set_user_coordinate;


// SelectSetCoordinateDlg 대화 상자입니다.

class SelectSetCoordinateDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SelectSetCoordinateDlg)

public:
	SelectSetCoordinateDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~SelectSetCoordinateDlg();
	virtual BOOL PreTranslateMessage(MSG* pMsg);

// 대화 상자 데이터입니다.
	enum { IDD = IDD_Dlg_CoordinateSet };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
