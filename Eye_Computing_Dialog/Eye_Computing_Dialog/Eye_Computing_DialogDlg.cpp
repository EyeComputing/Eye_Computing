
// Eye_Computing_DialogDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "Eye_Computing_Dialog.h"
#include "Eye_Computing_DialogDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


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
	HWND m_hForegroundWnd;
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
//	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()


// CEye_Computing_DialogDlg 대화 상자



CEye_Computing_DialogDlg::CEye_Computing_DialogDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CEye_Computing_DialogDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_hForegroundWnd = NULL;
}

void CEye_Computing_DialogDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CEye_Computing_DialogDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CEye_Computing_DialogDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CEye_Computing_DialogDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_GiYeok, &CEye_Computing_DialogDlg::OnBnClickedGiyeok)
	ON_WM_NCLBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_NiEun, &CEye_Computing_DialogDlg::OnBnClickedNieun)
	ON_BN_CLICKED(IDC_Ah, &CEye_Computing_DialogDlg::OnBnClickedAh)
END_MESSAGE_MAP()


// CEye_Computing_DialogDlg 메시지 처리기

BOOL CEye_Computing_DialogDlg::OnInitDialog()
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

	//항상 최상위 window가 되도록 설정
	SetWindowPos((const CWnd*)&(this->m_hWnd), (int)(HWND_TOPMOST), 0, 0, 0, (UINT)(SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW));

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CEye_Computing_DialogDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CEye_Computing_DialogDlg::OnPaint()
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
HCURSOR CEye_Computing_DialogDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CEye_Computing_DialogDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnOK();
}


void CEye_Computing_DialogDlg::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnCancel();
}


void CEye_Computing_DialogDlg::OnBnClickedGiyeok()
{
	/*https://msdn.microsoft.com/en-us/library/windows/desktop/ms646270(v=vs.85).aspx */
	INPUT InputGiYeok;
	//initialize
	::ZeroMemory(&InputGiYeok, sizeof(INPUT));
	//keyboard로 입력하겠다.
	InputGiYeok.type = INPUT_KEYBOARD;
	//어떤버튼누를건지
	InputGiYeok.ki.wVk = 0x52;
	//한번눌러주기
	::SendInput(1, &InputGiYeok, sizeof(INPUT));
	//누른거 풀어주기
	InputGiYeok.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &InputGiYeok, sizeof(INPUT));
}


void CEye_Computing_DialogDlg::OnNcLButtonDown(UINT nHitTest, CPoint point)
{
	if (!m_hForegroundWnd)
	{
		m_hForegroundWnd = ::GetForegroundWindow();
		ModifyStyleEx(WS_EX_NOACTIVATE, 0);
		SetForegroundWindow();
	}

	CDialog::OnNcLButtonDown(nHitTest, point);
}


void CEye_Computing_DialogDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	if (m_hForegroundWnd)
	{
		::SetForegroundWindow(m_hForegroundWnd);
		ModifyStyleEx(0, WS_EX_NOACTIVATE);

		//포커스 키보드로 오면 한/영 눌러서 한글로 시작하기!
		INPUT HanToEng;
		::ZeroMemory(&HanToEng, sizeof(INPUT));
		HanToEng.type = INPUT_KEYBOARD;
		HanToEng.ki.wVk = VK_HANGEUL;
		::SendInput(1, &HanToEng, sizeof(INPUT));
		HanToEng.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &HanToEng, sizeof(INPUT));


		m_hForegroundWnd = NULL;
	}

	CDialog::OnMouseMove(nFlags, point);
}


void CEye_Computing_DialogDlg::OnBnClickedNieun()
{
	INPUT InputNieun;
	//initialize
	::ZeroMemory(&InputNieun, sizeof(INPUT));
	//keyboard로 입력하겠다.
	InputNieun.type = INPUT_KEYBOARD;
	//어떤버튼누를건지
	InputNieun.ki.wVk = 0x53;
	//한번눌러주기
	::SendInput(1, &InputNieun, sizeof(INPUT));
	//누른거 풀어주기
	InputNieun.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &InputNieun, sizeof(INPUT));
}


void CEye_Computing_DialogDlg::OnBnClickedAh()
{
	INPUT InputAh;
	//initialize
	::ZeroMemory(&InputAh, sizeof(INPUT));
	//keyboard로 입력하겠다.
	InputAh.type = INPUT_KEYBOARD;
	//어떤버튼누를건지
	InputAh.ki.wVk = 0x4B;
	//한번눌러주기
	::SendInput(1, &InputAh, sizeof(INPUT));
	//누른거 풀어주기
	InputAh.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &InputAh, sizeof(INPUT));
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
