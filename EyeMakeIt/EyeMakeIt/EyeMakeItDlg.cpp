
// EyeMakeItDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "EyeMakeIt.h"
#include "EyeMakeItDlg.h"
#include "afxdialogex.h"
#include "EyeXGaze.h"


/* 헤더파일 인클루드 */
#include "SelectKeyboardDlg.h"
#include "SelectMouseDlg.h"
#include "SelectSettingDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//mouse click message 구분위한 상수
#define LCLICKED 0
#define RCLICKED 1
#define DOUBLECLICKED 2
#define DRAGCLICKED 3
#define DRAGSTOP 4

//spacebar click message hooking을 위한 함수 & 변수
//키보드 hooking이 발생했을 경우 호출되는 함수
LRESULT CALLBACK  GetKeyMsg(int nCode, WPARAM wParam, LPARAM lParam);
HHOOK m_hook = NULL;

//토비!
EyeXGaze g_EyeXGaze;	// 인스턴스 생성하면서 생성자 실행됨.

/* global */
int selectMouseEvent;

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


// CEyeMakeItDlg 대화 상자

CEyeMakeItDlg::CEyeMakeItDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CEyeMakeItDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_hForegroundWnd = NULL;

	//initialize EyeXGaze				status-> 나갔다 들어오는거? focus -> 응시 activated -> 활동
	g_EyeXGaze.Init(this->m_hWnd, UM_EYEX_HOST_STATUS_CHANGED, UM_REGION_GOT_ACTIVATION_FOCUS, UM_REGION_ACTIVATED);
}

void CEyeMakeItDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CEyeMakeItDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	/* 버튼 클릭 한번에 하는 메세지 매핑 */
	ON_COMMAND_RANGE(IDC_BT_Mouse, IDC_BT_Setting, CEyeMakeItDlg::OnBtnClick)
//	ON_WM_MOUSEWHEEL()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()


// CEyeMakeItDlg 메시지 처리기

BOOL CEyeMakeItDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	/* 항상 맨 위에 */
	SetWindowPos((const CWnd*)&(this->m_hWnd), (int)(HWND_TOPMOST), 0, 0, 0, (UINT)(SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW));



	//keyboard message hooking 위한 초기화
	m_hook = SetWindowsHookEx(WH_KEYBOARD_LL, GetKeyMsg, NULL, 0);

	if (!m_hook)
		TRACE("HOOKING ERROR");

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

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CEyeMakeItDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CEyeMakeItDlg::OnPaint()
{
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
HCURSOR CEyeMakeItDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}










/* 사용자 정의 함수 */

LRESULT CALLBACK GetKeyMsg(int nCode, WPARAM wParam, LPARAM lParam)
{
	static int c = 0;
	POINT point;//마우스 좌표값 저장하는 변수
	KBDLLHOOKSTRUCT kbdStruct;
	kbdStruct = *((KBDLLHOOKSTRUCT*)lParam);

	if (nCode < 0)
		return CallNextHookEx(m_hook, nCode, wParam, lParam);

	//alt key press 시에 마우스 클릭 message 발생
	if (wParam == WM_KEYDOWN)
	{
		//alt key press 시에 마우스 클릭 message 발생
		if (kbdStruct.vkCode == VK_UP)
		{
			GetCursorPos(&point); //point 변수에 마우스 좌표 점 
			switch (selectMouseEvent)
			{
			case LCLICKED:
				TRACE("Left mouse 누름");

				// 마우스 왼쪽 클릭 명령(추가)
				::mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_ABSOLUTE, point.x, point.y, 0, ::GetMessageExtraInfo());
				::mouse_event(MOUSEEVENTF_LEFTUP | MOUSEEVENTF_ABSOLUTE, point.x, point.y, 0, ::GetMessageExtraInfo());

				return 1;//return 1 : 원래의 message인 space 클릭 메시지가 해당 application의 message queue로 전달되지 않음
						 //return 을 하지 않으면 queue로 전달하여 정상적으로 message 처리됨.
			case RCLICKED:
				//마우스 오른쪽 클릭 EVENT 발생
				::mouse_event(MOUSEEVENTF_RIGHTDOWN | MOUSEEVENTF_ABSOLUTE, point.x, point.y, 0, ::GetMessageExtraInfo());
				::mouse_event(MOUSEEVENTF_RIGHTUP | MOUSEEVENTF_ABSOLUTE, point.x, point.y, 0, ::GetMessageExtraInfo());

				selectMouseEvent = LCLICKED;
				return 1;
			case DOUBLECLICKED:

				::mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_ABSOLUTE, point.x, point.y, 0, ::GetMessageExtraInfo());
				::mouse_event(MOUSEEVENTF_LEFTUP | MOUSEEVENTF_ABSOLUTE, point.x, point.y, 0, ::GetMessageExtraInfo());
				Sleep(10);
				::mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_ABSOLUTE, point.x, point.y, 0, ::GetMessageExtraInfo());
				::mouse_event(MOUSEEVENTF_LEFTUP | MOUSEEVENTF_ABSOLUTE, point.x, point.y, 0, ::GetMessageExtraInfo());

				selectMouseEvent = LCLICKED;
				return 1;
			case DRAGCLICKED:
				::mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_ABSOLUTE, point.x, point.y, 0, ::GetMessageExtraInfo());

				selectMouseEvent = DRAGSTOP;
				return 1;
			case DRAGSTOP:
				::mouse_event(MOUSEEVENTF_LEFTUP | MOUSEEVENTF_ABSOLUTE, point.x, point.y, 0, ::GetMessageExtraInfo());
				selectMouseEvent = LCLICKED;

				return 1;
			}
		}

		return 0;
	}

}

// 각 버튼 클릭 
void CEyeMakeItDlg::OnBtnClick( UINT uiID )
{
	switch (uiID)
	{
		case IDC_BT_Mouse:
		{
			SelectMouseDlg *m_pMouseDlg;
			m_pMouseDlg = new SelectMouseDlg();
			m_pMouseDlg->Create(IDD_Dlg_Mouse, this);
			m_pMouseDlg->ShowWindow(SW_SHOW);
			break;
		}
		case IDC_BT_Scroll_Up:
		{
			INPUT InputButton;
			//initialize
			::ZeroMemory(&InputButton, sizeof(INPUT));
			//keyboard로 입력하겠다.
			InputButton.type = INPUT_KEYBOARD;
			//어떤버튼누를건지
			InputButton.ki.wVk = 0x21;
			//한번눌러주기
			::SendInput(1, &InputButton, sizeof(INPUT));
			//누른거 풀어주기
			InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
			::SendInput(1, &InputButton, sizeof(INPUT));

			break;
		}
		case IDC_BT_Keyboard:
		{
			SelectKeyboardDlg *m_pKeyboardDlg;
			m_pKeyboardDlg = new SelectKeyboardDlg();
			m_pKeyboardDlg->Create(IDD_Dlg_Keyboard, this);
			m_pKeyboardDlg->ShowWindow(SW_SHOW);
			
			break;
		}
		case IDC_BT_Scroll_Down:
		{
			INPUT InputButton;
			//initialize
			::ZeroMemory(&InputButton, sizeof(INPUT));
			//keyboard로 입력하겠다.
			InputButton.type = INPUT_KEYBOARD;
			//어떤버튼누를건지
			InputButton.ki.wVk = 0x22;
			//한번눌러주기
			::SendInput(1, &InputButton, sizeof(INPUT));
			//누른거 풀어주기
			InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
			::SendInput(1, &InputButton, sizeof(INPUT));

			break;
		}
		case IDC_BT_Setting:
		{
			SelectSettingDlg *m_pSettingDlg;
			m_pSettingDlg = new SelectSettingDlg();
			m_pSettingDlg->Create(IDD_Dlg_Setting, this);
			m_pSettingDlg->ShowWindow(SW_SHOW);
			break;
		}
	}
}



// 포커스 이동!

void CEyeMakeItDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	TRACE("Lbutton clicked");
	if (!m_hForegroundWnd)
	{
		m_hForegroundWnd = ::GetForegroundWindow();
		ModifyStyleEx(WS_EX_NOACTIVATE, 0);
		SetForegroundWindow();
	}
	//키보드가 항상 최상위에 위치하도록  
	SetWindowPos((const CWnd*)&(this->m_hWnd), (int)(HWND_TOPMOST), 0, 0, 0, (UINT)(SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW));

	CDialogEx::OnLButtonDown(nFlags, point);
}


void CEyeMakeItDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	TRACE("MOUSE MOVE");
	if (m_hForegroundWnd)
	{
		::SetForegroundWindow(m_hForegroundWnd);
		ModifyStyleEx(0, WS_EX_NOACTIVATE);

		m_hForegroundWnd = NULL;

	}

	CDialogEx::OnMouseMove(nFlags, point);
}
