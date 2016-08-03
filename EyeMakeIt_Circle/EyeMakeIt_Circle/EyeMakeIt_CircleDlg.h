
// EyeMakeIt_CircleDlg.h : 헤더 파일
//

#pragma once

#include "Hangeul.h"

// CEyeMakeIt_CircleDlg 대화 상자
class CEyeMakeIt_CircleDlg : public CDialogEx
{
// 생성입니다.
public:
	CEyeMakeIt_CircleDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_EYEMAKEIT_CIRCLE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


	void CEyeMakeIt_CircleDlg::OnBtnClick(UINT uiID);
	void CEyeMakeIt_CircleDlg::InputHangeul(int textCode);
	void CEyeMakeIt_CircleDlg::InputText(CString text);

	Hangeul hangeulInput;


// 구현입니다.
protected:
	HICON m_hIcon;
	HWND m_hForegroundWnd;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
