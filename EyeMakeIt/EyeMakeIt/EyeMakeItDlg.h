
// EyeMakeItDlg.h : 헤더 파일
//

#pragma once
#include "xSkinButton.h"
#include "afxwin.h"

/* global  */
extern int selectMouseEvent;

static BOOL CALLBACK EnumWindowCallBack(HWND hwnd, LPARAM lParam); // 콜백함수

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
	HWND m_hForegroundWnd;
	// 생성된 메시지 맵 함수
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

	// 윈도우 사이즈와 버튼 사이즈 값을 입력받기 위한 변수
	SIZE WindowSize;
	SIZE ButtonSize;

	// 툴바 위치를 결정하기 위한 변수
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
