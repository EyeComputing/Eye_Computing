
// EyeMakeItDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "EyeMakeIt.h"
#include "EyeMakeItDlg.h"
#include "afxdialogex.h"
#include "EyeXGaze.h"


/* ������� ��Ŭ��� */
#include "SelectKeyboardDlg.h"
#include "SelectMouseDlg.h"
#include "SelectSettingDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//mouse click message �������� ���
#define LCLICKED 0
#define RCLICKED 1
#define DOUBLECLICKED 2
#define DRAGCLICKED 3
#define DRAGSTOP 4

//spacebar click message hooking�� ���� �Լ� & ����
//Ű���� hooking�� �߻����� ��� ȣ��Ǵ� �Լ�
LRESULT CALLBACK  GetKeyMsg(int nCode, WPARAM wParam, LPARAM lParam);
HHOOK m_hook = NULL;

//���!
EyeXGaze g_EyeXGaze;	// �ν��Ͻ� �����ϸ鼭 ������ �����.

/* global */
int selectMouseEvent;
SelectKeyboardDlg *m_pKeyboardDlg;

//�� ���α׷��� ��ġ RECT
RECT limit_region;

// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };



	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
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


// CEyeMakeItDlg ��ȭ ����

CEyeMakeItDlg::CEyeMakeItDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CEyeMakeItDlg::IDD, pParent)
{


	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_hForegroundWnd = NULL;

	//initialize EyeXGaze				status-> ������ �����°�? focus -> ���� activated -> Ȱ��
	g_EyeXGaze.Init(this->m_hWnd, UM_EYEX_HOST_STATUS_CHANGED, UM_REGION_GOT_ACTIVATION_FOCUS, UM_REGION_ACTIVATED);
}

// Enter ������ â�� �ݱ��� �ʵ���  �մϴ�.
void  CEyeMakeItDlg::OnOK()
{
	return;
}


void CEyeMakeItDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BT_Mouse, m_btn_mos);
	DDX_Control(pDX, IDC_BT_Scroll_Up, m_btn_scu);
	DDX_Control(pDX, IDC_BT_Keyboard, m_btn_kbd);
	DDX_Control(pDX, IDC_BT_Scroll_Down, m_btn_scd);
	DDX_Control(pDX, IDC_BT_Setting, m_btn_set);
	DDX_Control(pDX, IDC_FIRST_CLOSE, btn_first_close);
}

BEGIN_MESSAGE_MAP(CEyeMakeItDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	/* ��ư Ŭ�� �ѹ��� �ϴ� �޼��� ���� */
	ON_COMMAND_RANGE(IDC_BT_Mouse, IDC_FIRST_CLOSE, CEyeMakeItDlg::OnBtnClick)
//	ON_WM_MOUSEWHEEL()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()


// CEyeMakeItDlg �޽��� ó����

BOOL CEyeMakeItDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();



	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// ������ ����� �Է¹ް� �׿� ���߾� ��ư ������ ����
	ZeroMemory(&WindowSize, sizeof(SIZE));
	WindowSize.cx = (LONG)::GetSystemMetrics(SM_CXFULLSCREEN);
	WindowSize.cy = (LONG)::GetSystemMetrics(SM_CYFULLSCREEN);
	ButtonSize.cx = (WindowSize.cx / 9);
	ButtonSize.cy = (WindowSize.cy / 6);

	/* �׻� �� ���� */
	SetWindowPos((const CWnd*)&(this->m_hWnd), (int)(HWND_TOPMOST), 0, 0, 0, (UINT)(SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW));
	
	limit_region.top = 0;
	limit_region.left = ButtonSize.cx * 8;
	limit_region.bottom = WindowSize.cy + 50;
	limit_region.right = ButtonSize.cx * 8 + ButtonSize.cx + 10;

	// ���α׷� ��ġ ����(����)
	SetWindowPos(NULL, ButtonSize.cx * 8, 0, ButtonSize.cx + 10, WindowSize.cy + 50, SWP_NOZORDER);

	// ��ư ��ǥ ����
	GetDlgItem(IDC_BT_Mouse)->SetWindowPos(NULL, 0, ButtonSize.cy * 0, ButtonSize.cx, ButtonSize.cy, SWP_NOZORDER);
	GetDlgItem(IDC_BT_Scroll_Up)->SetWindowPos(NULL, 0, ButtonSize.cy * 1, ButtonSize.cx, ButtonSize.cy, SWP_NOZORDER);
	GetDlgItem(IDC_BT_Keyboard)->SetWindowPos(NULL, 0, ButtonSize.cy * 2, ButtonSize.cx, ButtonSize.cy, SWP_NOZORDER);
	GetDlgItem(IDC_BT_Scroll_Down)->SetWindowPos(NULL, 0, ButtonSize.cy * 3, ButtonSize.cx, ButtonSize.cy, SWP_NOZORDER);
	GetDlgItem(IDC_BT_Setting)->SetWindowPos(NULL, 0, ButtonSize.cy * 4, ButtonSize.cx, ButtonSize.cy, SWP_NOZORDER);
	GetDlgItem(IDC_FIRST_CLOSE)->SetWindowPos(NULL, 0, ButtonSize.cy * 5, ButtonSize.cx, ButtonSize.cy, SWP_NOZORDER);

	// ��ư �̹��� �����
	m_btn_mos.SetSkin(IDB_M_MOS, IDB_M_MOS, IDB_M_MOS_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	m_btn_scu.SetSkin(IDB_M_SCU, IDB_M_SCU, IDB_M_SCU_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	m_btn_kbd.SetSkin(IDB_M_KBD, IDB_M_KBD, IDB_M_KBD_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	m_btn_scd.SetSkin(IDB_M_SCD, IDB_M_SCD, IDB_M_SCD_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	m_btn_set.SetSkin(IDB_M_SET, IDB_M_SET, IDB_M_SET_OVER, 0, 0, IDB_MASK, 1, 0, 4);
	btn_first_close.SetSkin(IDB_FIRST_CLOSE, IDB_FIRST_CLOSE, IDB_FIRST_CLOSE_OVER, 0, 0, IDB_MASK, 1, 0, 4);

	// Ű���带 �̸� �������� ���´�

	m_pKeyboardDlg = new SelectKeyboardDlg();
	m_pKeyboardDlg->Create(IDD_Dlg_Keyboard, this);



	//keyboard message hooking ���� �ʱ�ȭ
	m_hook = SetWindowsHookEx(WH_KEYBOARD_LL, GetKeyMsg, NULL, 0);

	if (!m_hook)
		TRACE("HOOKING ERROR");

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
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

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CEyeMakeItDlg::OnPaint()
{
	/* �׻� �� ���� */
	SetWindowPos((const CWnd*)&(this->m_hWnd), (int)(HWND_TOPMOST), 0, 0, 0, (UINT)(SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW));

	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CEyeMakeItDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}










/* ����� ���� �Լ� */

LRESULT CALLBACK GetKeyMsg(int nCode, WPARAM wParam, LPARAM lParam)
{
	static int c = 0;
	POINT point;//���콺 ��ǥ�� �����ϴ� ����
	KBDLLHOOKSTRUCT kbdStruct;
	kbdStruct = *((KBDLLHOOKSTRUCT*)lParam);

	if (nCode < 0)
		return CallNextHookEx(m_hook, nCode, wParam, lParam);

	//alt key press �ÿ� ���콺 Ŭ�� message �߻�
	if (wParam == WM_KEYDOWN)
	{
		//alt key press �ÿ� ���콺 Ŭ�� message �߻�
		if (kbdStruct.vkCode == VK_UP)
		{
			GetCursorPos(&point); //point ������ ���콺 ��ǥ �� 
			switch (selectMouseEvent)
			{
			case LCLICKED:
				TRACE("Left mouse ����");

				// ���콺 ���� Ŭ�� ���(�߰�)
				::mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_ABSOLUTE, point.x, point.y, 0, ::GetMessageExtraInfo());
				::mouse_event(MOUSEEVENTF_LEFTUP | MOUSEEVENTF_ABSOLUTE, point.x, point.y, 0, ::GetMessageExtraInfo());

				return 1;//return 1 : ������ message�� space Ŭ�� �޽����� �ش� application�� message queue�� ���޵��� ����
						 //return �� ���� ������ queue�� �����Ͽ� ���������� message ó����.
			case RCLICKED:
				//���콺 ������ Ŭ�� EVENT �߻�
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

// �� ��ư Ŭ�� 
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
			//keyboard�� �Է��ϰڴ�.
			InputButton.type = INPUT_KEYBOARD;
			//���ư��������
			InputButton.ki.wVk = 0x21;
			//�ѹ������ֱ�
			::SendInput(1, &InputButton, sizeof(INPUT));
			//������ Ǯ���ֱ�
			InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
			::SendInput(1, &InputButton, sizeof(INPUT));

			break;
		}
		case IDC_BT_Keyboard:
		{

			m_pKeyboardDlg->ShowWindow(SW_SHOWMAXIMIZED); // Ű���带 ��üȭ������ ����
			
			break;
		}
		case IDC_BT_Scroll_Down:
		{
			INPUT InputButton;
			//initialize
			::ZeroMemory(&InputButton, sizeof(INPUT));
			//keyboard�� �Է��ϰڴ�.
			InputButton.type = INPUT_KEYBOARD;
			//���ư��������
			InputButton.ki.wVk = 0x22;
			//�ѹ������ֱ�
			::SendInput(1, &InputButton, sizeof(INPUT));
			//������ Ǯ���ֱ�
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
		case IDC_FIRST_CLOSE:
		{
			::SendMessage(GetSafeHwnd(), WM_CLOSE, NULL, NULL);
			break;
		}
	}
		
}



// ��Ŀ�� �̵�!

void CEyeMakeItDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	TRACE("Lbutton clicked");
	if (!m_hForegroundWnd)
	{
		m_hForegroundWnd = ::GetForegroundWindow();
		ModifyStyleEx(WS_EX_NOACTIVATE, 0);
		SetForegroundWindow();
	}
	//Ű���尡 �׻� �ֻ����� ��ġ�ϵ���  
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


BOOL CEyeMakeItDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if((pMsg->message == WM_LBUTTONDOWN )|| (pMsg->message == WM_RBUTTONDOWN))
		/* �׻� �� ���� */
		SetWindowPos((const CWnd*)&(this->m_hWnd), (int)(HWND_TOPMOST), 0, 0, 0, (UINT)(SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW));
	
	return CDialogEx::PreTranslateMessage(pMsg);
}

BOOL CALLBACK EnumWindowCallBack(HWND hwnd, LPARAM lParam)
{
	RECT region;
	int limit_width = (limit_region.right) - (limit_region.left);
	
	GetWindowRect(hwnd, &region);
	if ((limit_width < (region.left))
		|| ((region.right) > (limit_region.left)))
	{
		MoveWindow(hwnd,0,0,)
	}
}