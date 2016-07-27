
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
#include "SelectScrolldownDlg.h"
#include "SelectScrollupDlg.h"
#include "SelectSettingDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//mouse click message �������� ���
#define LCLICKED 0
#define RCLICKED 1
#define DOUBLECLICKED 2

//spacebar click message hooking�� ���� �Լ� & ����
//Ű���� hooking�� �߻����� ��� ȣ��Ǵ� �Լ�
LRESULT CALLBACK  MakeMouseMsg(int nCode, WPARAM wParam, LPARAM lParam);
HHOOK m_hook = NULL;

//���!
EyeXGaze g_EyeXGaze;	// �ν��Ͻ� �����ϸ鼭 ������ �����.


/* global  */
int selectMouseEvent;


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.



/* ���� ȭ��ǥ�� ���콺�� � ������ �ұ��? */

LRESULT CALLBACK MakeMouseMsg(int nCode, WPARAM wParam, LPARAM lParam)
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

				return 1;
			case DOUBLECLICKED:

				::mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_ABSOLUTE, point.x, point.y, 0, ::GetMessageExtraInfo());
				::mouse_event(MOUSEEVENTF_LEFTUP | MOUSEEVENTF_ABSOLUTE, point.x, point.y, 0, ::GetMessageExtraInfo());
				Sleep(10);
				::mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_ABSOLUTE, point.x, point.y, 0, ::GetMessageExtraInfo());
				::mouse_event(MOUSEEVENTF_LEFTUP | MOUSEEVENTF_ABSOLUTE, point.x, point.y, 0, ::GetMessageExtraInfo());

				return 1;
			}
		}
		return 0;
	}
}





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

	//initialize EyeXGaze				status-> ������ �����°�? focus -> ���� activated -> Ȱ��
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
	/* ��ư Ŭ�� �ѹ��� �ϴ� �޼��� ���� */
	ON_COMMAND_RANGE(IDC_BT_Mouse, IDC_BT_Setting, CEyeMakeItDlg::OnBtnClick)
END_MESSAGE_MAP()


// CEyeMakeItDlg �޽��� ó����

BOOL CEyeMakeItDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	//keyboard message hooking ���� �ʱ�ȭ
	m_hook = SetWindowsHookEx(WH_KEYBOARD_LL, MakeMouseMsg, NULL, 0);

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
			SelectScrollupDlg *m_pScrollupDlg;
			m_pScrollupDlg = new SelectScrollupDlg();
			m_pScrollupDlg->Create(IDD_Dlg_Scroll_Up, this);
			m_pScrollupDlg->ShowWindow(SW_SHOW);
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
			SelectScrolldownDlg *m_pScrolldownDlg;
			m_pScrolldownDlg = new SelectScrolldownDlg();
			m_pScrolldownDlg->Create(IDD_Dlg_Scroll_Down, this);
			m_pScrolldownDlg->ShowWindow(SW_SHOW);
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

