
// EyeMakeIt_CircleDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "EyeMakeIt_Circle.h"
#include "EyeMakeIt_CircleDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


/* global var */
bool m_bTrackMouse = false;

bool clickedShift = false;

bool clicked_YII = false;	// ㅣ
bool clicked_ZUM = false;	// 점
bool clicked_ZUM2 = false;	// 점2개
bool clicked_AAA = false;	// ㅏ
bool clicked_YAA = false;	// ㅑ
bool clicked_EOO = false;	// ㅓ
bool clicked_YEO = false;	// ㅕ
bool clicked_OOO = false;	// ㅗ
bool clicked_UUU = false;	// ㅜ
bool clicked_YUU = false;	// ㅠ
bool clicked_EUU = false;	// ㅡ
bool clicked_OEE = false;	// ㅚ
bool clicked_WAA = false;	// ㅘ
bool clicked_WOU = false;	// ㅝ

// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()





// CEyeMakeIt_CircleDlg 대화 상자

CEyeMakeIt_CircleDlg::CEyeMakeIt_CircleDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CEyeMakeIt_CircleDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_hForegroundWnd = NULL;
}

void CEyeMakeIt_CircleDlg::DoDataExchange(CDataExchange* pDX)
{
	if (m_hForegroundWnd)
	{
		::SetForegroundWindow(m_hForegroundWnd);
		ModifyStyleEx(0, WS_EX_NOACTIVATE);

		m_hForegroundWnd = NULL;

	}

	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CEyeMakeIt_CircleDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	/* 버튼 클릭 한번에 하는 메세지 매핑 */
	ON_COMMAND_RANGE(IDC_K_GIY, IDC_K_KIE, CEyeMakeIt_CircleDlg::OnBtnClick)
	//ON_WM_LBUTTONDOWN()
	//ON_WM_MOUSEMOVE()
	ON_BN_SETFOCUS(IDC_K_GIY, &CEyeMakeIt_CircleDlg::OnBnSetfocusKGiy)
	ON_WM_MOUSEHOVER()
END_MESSAGE_MAP()


// CEyeMakeIt_CircleDlg 메시지 처리기

BOOL CEyeMakeIt_CircleDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	//최상위 윈도우로 설정
	SetWindowPos((const CWnd*)&(this->m_hWnd), (int)(HWND_TOPMOST), 0, 0, 0, (UINT)(SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW));

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CEyeMakeIt_CircleDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CEyeMakeIt_CircleDlg::OnPaint()
{

	//최상위 윈도우로 설정
	SetWindowPos((const CWnd*)&(this->m_hWnd), (int)(HWND_TOPMOST), 0, 0, 0, (UINT)(SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW));

	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CEyeMakeIt_CircleDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}





/* 사용자 정의 함수 */


/* 여기서 함수 정의 & 사용 */
int GetFindCharCount(CString parm_string, char parm_find_char)
// 문자열에 어떤 문자가 몇 개 들어 있는지
{

	int length = parm_string.GetLength(), find_count = 0;

	for (int i = 0; i < length; i++)
	{
		if (parm_string[i] == parm_find_char)
		{
			find_count++;
		}
	}

	return find_count;
}

int GetLastCharCount(CString parm_string, char parm_find_char)
// 문자열에 /마지막/문자가 어디에 위치해있는지
{

	int length = parm_string.GetLength(), find_final = 0;

	for (int i = 0; i < length; i++)
	{
		if (parm_string[i] == parm_find_char)
		{
			find_final = i;
		}
	}

	return find_final;
}

// 모음 초기화
void initButtonState()
{
	clicked_YII = false;	// ㅣ
	clicked_ZUM = false;	// 점
	clicked_ZUM2 = false;	// 점2개
	clicked_AAA = false;	// ㅏ
	clicked_YAA = false;	// ㅑ
	clicked_EOO = false;	// ㅓ
	clicked_YEO = false;	// ㅕ
	clicked_OOO = false;	// ㅗ
	clicked_UUU = false;	// ㅜ
	clicked_YUU = false;	// ㅠ
	clicked_EUU = false;	// ㅡ
	clicked_OEE = false;	// ㅚ
	clicked_WAA = false;	// ㅘ
	clicked_WOU = false;	// ㅝ
}





BOOL CEyeMakeIt_CircleDlg::PreTranslateMessage(MSG* pMsg)
{

	if (!m_bTrackMouse)
	{

		TRACKMOUSEEVENT tme;
		::ZeroMemory(&tme, sizeof(tme));

		tme.cbSize = sizeof(tme);
		tme.hwndTrack = GetDlgItem(IDC_K_GIY)->m_hWnd;
		tme.dwFlags = TME_HOVER;
		tme.dwHoverTime = 2;

		m_bTrackMouse = ::_TrackMouseEvent(&tme);
		m_bTrackMouse = false;
	}
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	return CDialogEx::PreTranslateMessage(pMsg);
}



// 안됨..ㅠ
void CEyeMakeIt_CircleDlg::OnBnSetfocusKGiy()
{
	TRACE("focus");

	if (!m_bTrackMouse)
	{
		TRACKMOUSEEVENT tme;
		::ZeroMemory(&tme, sizeof(tme));

		tme.cbSize = sizeof(tme);
		tme.hwndTrack = GetDlgItem(IDC_K_GIY)->m_hWnd;
		tme.dwFlags = TME_HOVER;
		tme.dwHoverTime = 3000;
		AfxMessageBox(_T("Good"));

		m_bTrackMouse = ::_TrackMouseEvent(&tme);
	}

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CEyeMakeIt_CircleDlg::OnMouseHover(UINT nFlags, CPoint point)
{
	TRACE("over??");

	::mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_ABSOLUTE, point.x, point.y, 0, ::GetMessageExtraInfo());
	::mouse_event(MOUSEEVENTF_LEFTUP | MOUSEEVENTF_ABSOLUTE, point.x, point.y, 0, ::GetMessageExtraInfo());

	AfxMessageBox(_T("Good"));

	m_bTrackMouse = false;

	CDialogEx::OnMouseHover(nFlags, point);
}




/* 함수 선언 _ .h에 */

// hangeul input 함수
void CEyeMakeIt_CircleDlg::InputHangeul(int textCode)
{
	hangeulInput.SetHangeulCode(textCode);

	CString complete_text = hangeulInput.completeText;

	if (hangeulInput.ingWord != NULL)
		complete_text += hangeulInput.ingWord;


	SetDlgItemText(IDC_MAINEDIT, complete_text); // mainEdit에 띄움
	
	CString sub_text;
	
	int space = GetFindCharCount(complete_text, ' '); // 스페이스바가 몇 개 있는지 찾기
	int enter = GetFindCharCount(complete_text, '\n'); // 엔터가 몇 개 있는지 찾기

	int space_count = GetLastCharCount(complete_text, ' '); // 마지막 스페이스바의 위치
	int enter_count = GetLastCharCount(complete_text, '\n'); // 마지막 엔터의 위치

	if (enter_count > space_count) { // 
		AfxExtractSubString(sub_text, complete_text, enter, '\n'); // 마지막 엔터로부터 문자열을 잘라냄
	}
	else
		AfxExtractSubString(sub_text, complete_text, space, ' '); // 마지막 스페이스로부터 문자열을 잘라냄
		
	//sub_text += hangeulInput.completeText;

	SetDlgItemText(IDC_SUBEDIT, sub_text); // subEdit에 띄움


	CEdit * pEdit = ((CEdit*)GetDlgItem(IDC_MAINEDIT));
	pEdit->SetSel(pEdit->GetWindowTextLength(), pEdit->GetWindowTextLength());
	pEdit->SetFocus();

}

// textinput 함수
void CEyeMakeIt_CircleDlg::InputText(CString text)
{
	hangeulInput.completeText += text;

	CString complete_text = hangeulInput.completeText;

	if (hangeulInput.ingWord != NULL)
		complete_text += hangeulInput.ingWord;

	SetDlgItemText(IDC_MAINEDIT, complete_text);

	CString sub_text;
	int space = GetFindCharCount(complete_text, ' '); // 스페이스바가 몇 개 있는지 찾기
	int enter = GetFindCharCount(complete_text, '\n'); // 엔터가 몇 개 있는지 찾기

	int space_count = GetLastCharCount(complete_text, ' '); // 마지막 스페이스바의 위치
	int enter_count = GetLastCharCount(complete_text, '\n'); // 마지막 엔터의 위치

	if (enter_count > space_count) { // 
		AfxExtractSubString(sub_text, complete_text, enter, '\n'); // 마지막 엔터로부터 문자열을 잘라냄
	}
	else
		AfxExtractSubString(sub_text, complete_text, space, ' '); // 마지막 스페이스로부터 문자열을 잘라냄

	SetDlgItemText(IDC_SUBEDIT, sub_text); // subEdit에 띄움

	CEdit * pEdit = ((CEdit*)GetDlgItem(IDC_MAINEDIT));
	pEdit->SetSel(pEdit->GetWindowTextLength(), pEdit->GetWindowTextLength());
	pEdit->SetFocus();
}




//버튼 클릭 함수

void CEyeMakeIt_CircleDlg::OnBtnClick(UINT uiID)
{
	switch (uiID)
	{
		// ㅣ 누르기
		case IDC_K_YII:
		{
			if (clicked_ZUM)	// · + ㅣ = ㅓ
			{
				InputHangeul(23);
				clicked_ZUM = false;
				clicked_EOO = true;
			}
			else if (clicked_ZUM2)	// ·· + ㅣ = ㅕ
			{
				InputHangeul(25);
				clicked_ZUM2 = false;
				clicked_YEO = true;
			}
			else if (clicked_EOO)	//	ㅓ + ㅣ = ㅔ
			{
				InputHangeul(-3);
				InputHangeul(24);
				clicked_EOO = false;
			}
			else if (clicked_AAA)	// ㅏ + ㅣ = ㅐ
			{
				InputHangeul(-3);
				InputHangeul(20);
				clicked_AAA = false;
			}
			else if (clicked_YAA)	// ㅑ + ㅣ = ㅒ
			{
				InputHangeul(-3);
				InputHangeul(22);
				clicked_YAA = false;
			}
			else if (clicked_OOO)	// ㅗ + ㅣ = ㅚ
			{
				InputHangeul(-3);
				InputHangeul(30);
				clicked_OOO = false;
				clicked_OEE = true;
			}
			else if (clicked_WAA)	// ㅘ + ㅣ = ㅙ
			{
				InputHangeul(-3);
				InputHangeul(29);
				clicked_WAA = false;
			}
			else if (clicked_UUU)	// ㅜ + ㅣ = ㅟ
			{
				InputHangeul(-3);
				InputHangeul(35);
				clicked_UUU = false;
			}
			else if (clicked_YUU)	// ㅠ + ㅣ = ㅝ
			{
				InputHangeul(-3);
				InputHangeul(33);
				clicked_YUU = false;
				clicked_WOU = true;
			}
			else if (clicked_WOU)	// ㅝ + ㅣ = ㅞ
			{
				InputHangeul(-3);
				InputHangeul(34);
				clicked_WOU = false;
			}
			else 					// l = l
			{
				InputHangeul(39);
				clicked_YII = true;
			}
			break;
		}
		// · 누르기
		case IDC_K_ZUM:
		{
			if (clicked_YII)		// ㅣ + · = ㅏ
			{
				InputHangeul(-3);
				InputHangeul(19);
				clicked_YII = false;
				clicked_AAA = true;
			}
			else if (clicked_AAA)	// ㅏ + · = ㅑ
			{
				InputHangeul(-3);
				InputHangeul(21);
				clicked_AAA = false;
				clicked_YAA = true;
			}
			else if (clicked_EUU)	// ㅡ + · = ㅜ
			{
				InputHangeul(-3);
				InputHangeul(32);
				clicked_EUU = false;
				clicked_UUU = true;
			}
			else if (clicked_UUU)	// ㅜ + · = ㅠ
			{
				InputHangeul(-3);
				InputHangeul(36);
				clicked_UUU = false;
				clicked_YUU = true;
			}
			else if (clicked_OEE)	// ㅚ + · = ㅘ
			{
				InputHangeul(-3);
				InputHangeul(28);
				clicked_OEE = false;
				clicked_WAA = true;
			}
			else if (clicked_ZUM)	// · + · = ··
			{
				clicked_ZUM = false;
				clicked_ZUM2 = true;
			}
			else 					// ·
			{
				clicked_ZUM = true;
			}

			break;
		}
		// ㅡ 누르기
		case IDC_K_EUU:
		{
			if (clicked_ZUM)		//· + ㅡ = ㅗ
			{
				InputHangeul(27);
				clicked_ZUM = false;
				clicked_OOO = true;
			}
			else if (clicked_ZUM2)	//·· + ㅡ = ㅛ
			{
				InputHangeul(31);
				clicked_ZUM2 = false;
			}
			else 					// ㅡ = ㅡ
			{
				InputHangeul(37);
				clicked_EUU = true;
			}
			break;
		}


		// 자음

		case IDC_K_GIY:		// ㄱ
		{
			initButtonState();
			if (clickedShift)
				InputHangeul(1);
			else
				InputHangeul(0);

			break;
		}
		case IDC_K_NIE:		// ㄴ
		{
			initButtonState();

			InputHangeul(2);

			break;
		}
	}
}






