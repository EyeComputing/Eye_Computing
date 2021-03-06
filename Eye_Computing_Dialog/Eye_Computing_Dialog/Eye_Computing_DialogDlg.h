
// Eye_Computing_DialogDlg.h : 헤더 파일
//

#pragma once
#include "afxwin.h"
#include "xSkinButton.h"


// CEye_Computing_DialogDlg 대화 상자
class CEye_Computing_DialogDlg : public CDialogEx
{
// 생성입니다.
public:
	CEye_Computing_DialogDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_EYE_COMPUTING_DIALOG_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.
	
	void CEye_Computing_DialogDlg::OnOK();
	

// 구현입니다.
protected:
	HICON m_hIcon;
	HWND m_hForegroundWnd;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();

	//모음 상태 초기화 함수
	afx_msg void CEye_Computing_DialogDlg::initHanguel();
	afx_msg void CEye_Computing_DialogDlg::initWindowSize();
	afx_msg void CEye_Computing_DialogDlg::setImgSysBtn();
	afx_msg void CEye_Computing_DialogDlg::setPosSysBtn();
	afx_msg void CEye_Computing_DialogDlg::setImgKorBtn();
	afx_msg void CEye_Computing_DialogDlg::setPosKorBtn();
	afx_msg void CEye_Computing_DialogDlg::setImgEngBtn();
	afx_msg void CEye_Computing_DialogDlg::setPosEngBtn();
	afx_msg void CEye_Computing_DialogDlg::setImgNumBtn();
	afx_msg void CEye_Computing_DialogDlg::setPosNumBtn();
	afx_msg void CEye_Computing_DialogDlg::showKorBtn();
	afx_msg void CEye_Computing_DialogDlg::hideKorBtn();
	afx_msg void CEye_Computing_DialogDlg::showEngBtn();
	afx_msg void CEye_Computing_DialogDlg::hideEngBtn();
	afx_msg void CEye_Computing_DialogDlg::showNumBtn();
	afx_msg void CEye_Computing_DialogDlg::hideNumBtn();
	afx_msg void CEye_Computing_DialogDlg::capsNumBtn();

	afx_msg void CEye_Computing_DialogDlg::CheckKorEng();

	//afx_msg void CEye_Computing_DialogDlg::Input_Key();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedGiyeok();
	afx_msg void OnNcLButtonDown(UINT nHitTest, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedNieun();
	afx_msg void OnBnClickedAh();
	afx_msg void OnBnClickedYee();
	afx_msg void OnBnClickedZzum();
	afx_msg void OnBnClickedEu();
	// 영문 버튼 변수
	CxSkinButton m_btn_BkSpace;
	CxSkinButton m_btn_Back;
	CxSkinButton m_btn_GiYeok;
	CxSkinButton m_btn_NiEun;
	CxSkinButton m_btn_DiGeut;
	CxSkinButton m_btn_Confirm;
	CxSkinButton m_btn_RiEul;
	CxSkinButton m_btn_MiEum;
	CxSkinButton m_btn_BiEup;
	CxSkinButton m_btn_Zzum;
	CxSkinButton m_btn_Yi;
	CxSkinButton m_btn_ShiOt;
	CxSkinButton m_btn_Eu;
	CxSkinButton m_btn_Space;
	CxSkinButton m_btn_IEung;
	CxSkinButton m_btn_KiEuk;
	CxSkinButton m_btn_ChiEut;
	CxSkinButton m_btn_JiEut;
	CxSkinButton m_btn_TiEut;
	CxSkinButton m_btn_PiEup;
	CxSkinButton m_btn_HiEut;
	CStatic m_BkGround;
	afx_msg void OnBnClickedIii();
	afx_msg void OnBnClickedDigeut();
	afx_msg void OnBnClickedRieul();
	afx_msg void OnBnClickedMieum();
	afx_msg void OnBnClickedBieup();
	afx_msg void OnBnClickedShiot();
	afx_msg void OnBnClickedIeung();
	afx_msg void OnBnClickedJieut();
	afx_msg void OnBnClickedChieut();
	afx_msg void OnBnClickedKieuk();
	afx_msg void OnBnClickedTieut();
	afx_msg void OnBnClickedPieup();
	afx_msg void OnBnClickedHieut();
	afx_msg void OnBnClickedSpace();
	afx_msg void OnBnClickedBkspace();
	afx_msg void OnBnClickedConfirm();
	afx_msg void OnBnClickedEnter();

	// 한글 버튼 변수
	CxSkinButton m_btn_cptA;
	CxSkinButton m_btn_cptC;
	CxSkinButton m_btn_cptB;
	CxSkinButton m_btn_cptD;
	CxSkinButton m_btn_cptE;
	CxSkinButton m_btn_cptF;
	CxSkinButton m_btn_cptG;
	CxSkinButton m_btn_cptH;
	CxSkinButton m_btn_cptI;
	CxSkinButton m_btn_cptJ;
	CxSkinButton m_btn_cptK;
	CxSkinButton m_btn_cptM;
	CxSkinButton m_btn_cptL;
	CxSkinButton m_btn_cptN;
	CxSkinButton m_btn_cptP;
	CxSkinButton m_btn_cptO;
	CxSkinButton m_btn_cptR;
	CxSkinButton m_btn_cptQ;
	CxSkinButton m_btn_cptS;
	CxSkinButton m_btn_cptT;
	CxSkinButton m_btn_cptU;
	CxSkinButton m_btn_cptV;
	CxSkinButton m_btn_cptW;
	CxSkinButton m_btn_cptX;
	CxSkinButton m_btn_cptY;
	CxSkinButton m_btn_cptZ;

	afx_msg void OnDestroy();


	CxSkinButton m_btn_Korean;
	CxSkinButton m_btn_English;
	CxSkinButton m_btn_Number;
	afx_msg void OnBnClickedKorean();
	afx_msg void OnBnClickedEnglish();
	afx_msg void OnBnClickedCptA();
	afx_msg void OnBnClickedCptC();
	afx_msg void OnBnClickedCptB();
	afx_msg void OnBnClickedCptD();
	afx_msg void OnBnClickedCptE();
	afx_msg void OnBnClickedCptF();
	afx_msg void OnBnClickedCptG();
	afx_msg void OnBnClickedCptH();
	afx_msg void OnBnClickedCptI();
	afx_msg void OnBnClickedCptJ();
	afx_msg void OnBnClickedCptK();
	afx_msg void OnBnClickedCptL();
	afx_msg void OnBnClickedCptM();
	afx_msg void OnBnClickedCptN();
	afx_msg void OnBnClickedCptO();
	afx_msg void OnBnClickedCptP();
	afx_msg void OnBnClickedCptQ();
	afx_msg void OnBnClickedCptR();
	afx_msg void OnBnClickedCptS();
	afx_msg void OnBnClickedCptT();
	afx_msg void OnBnClickedCptU();
	afx_msg void OnBnClickedCptV();
	afx_msg void OnBnClickedCptW();
	afx_msg void OnBnClickedCptX();
	afx_msg void OnBnClickedCptY();
	afx_msg void OnBnClickedCptZ();

	CxSkinButton m_btn_One;
	CxSkinButton m_btn_Two;
	CxSkinButton m_btn_Three;
	CxSkinButton m_btn_Four;
	CxSkinButton m_btn_Five;
	CxSkinButton m_btn_Six;
	CxSkinButton m_btn_Seven;
	CxSkinButton m_btn_Eight;
	CxSkinButton m_btn_Nine;
	CxSkinButton m_btn_Zero;
	CxSkinButton m_btn_Comma;
	CxSkinButton m_btn_Dot;
	CxSkinButton m_btn_Exclaim;
	CxSkinButton m_btn_Hyphen;
	CxSkinButton m_btn_Question;
	CxSkinButton m_btn_Semicolon;
	CxSkinButton m_btn_SgQuot;
	CxSkinButton m_btn_Slash;
	CxSkinButton m_btn_SqBracketClosed;
	CxSkinButton m_btn_SqBracketOpened;
	afx_msg void OnBnClickedNumber();
	CxSkinButton m_btn_Capslock;
	CxSkinButton m_btn_AtMark;
	afx_msg void OnBnClickedCapslock();
//	afx_msg void OnSysKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
//	afx_msg void OnSysKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
//	afx_msg void OnSysKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
//	afx_msg void OnSysChar(UINT nChar, UINT nRepCnt, UINT nFlags);
//	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnBnClickedAtmark();
	afx_msg void OnBnClickedSqbracketOpen();
	afx_msg void OnBnClickedSqbracketClose();
	afx_msg void OnBnClickedSlash();
	afx_msg void OnBnClickedQuestion();
	afx_msg void OnBnClickedSemicolon();
	afx_msg void OnBnClickedSgquot();
	afx_msg void OnBnClickedAccent();
	afx_msg void OnBnClickedExclaim();
	afx_msg void OnBnClickedHyphen();
	afx_msg void OnBnClickedDot();
	afx_msg void OnBnClickedEqual();
	afx_msg void OnBnClickedBkslash();
	afx_msg void OnBnClickedComma();
	afx_msg void OnBnClickedNine();
	afx_msg void OnBnClickedZero();
	afx_msg void OnBnClickedSeven();
	afx_msg void OnBnClickedEight();
	afx_msg void OnBnClickedSix();
	afx_msg void OnBnClickedFive();
	afx_msg void OnBnClickedThree();
	afx_msg void OnBnClickedFour();
	afx_msg void OnBnClickedOne();
	afx_msg void OnBnClickedTwo();
	afx_msg void OnBnClickedWave();
	afx_msg void OnBnClickedAdd();
	CxSkinButton m_btn_Accent;
	CxSkinButton m_btn_Equal;
	CxSkinButton m_btn_BkSlash;
	CxSkinButton m_btn_Minus;
	CxSkinButton m_btn_Plus;
	CxSkinButton m_btn_KorEng;
	afx_msg void OnBnClickedKoreng();
};
