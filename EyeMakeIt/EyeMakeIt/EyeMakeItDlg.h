
// EyeMakeItDlg.h : 헤더 파일
//

#pragma once
#include "xSkinButton.h"

/* global  */
extern int selectMouseEvent;

// CEyeMakeItDlg 대화 상자
class CEyeMakeItDlg : public CDialogEx
{
// 생성입니다.
public:
	CEyeMakeItDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.




/* 사용자 정의 함수 */
	void CEyeMakeItDlg::OnBtnClick(UINT uiID);




// 대화 상자 데이터입니다.
	enum { IDD = IDD_EYEMAKEIT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
};
