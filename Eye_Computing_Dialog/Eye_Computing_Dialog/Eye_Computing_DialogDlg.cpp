// Eye_Computing_DialogDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "Eye_Computing_Dialog.h"
#include "Eye_Computing_DialogDlg.h"
#include "afxdialogex.h"
#include "EyeXGaze.h"
#include "xSkinButton.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//토비!
EyeXGaze g_EyeXGaze;	// 인스턴스 생성하면서 생성자 실행됨.

//시작할 때 한글로 바꿔줄 려고 사용
bool isStart = true;

//천지인 할라고 사용
bool clickedIii = false;
bool clickedZzum = false;
bool clickedEu = false;
bool clickedAaa = false;
bool clickedZzum2 = false;
bool clickedUuu = false;
bool clickedYa = false;
bool clickedEo = false;
bool clickedYeo = false;
bool clickedWe = false;
bool clickedEoh = false;
bool clickedWa = false;
bool clickedUuuAndZzum = false;
bool clickedWo = false;
bool clickedOoo = false;

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
	//initialize EyeXGaze				status-> 나갔다 들어오는거? focus -> 응시 activated -> 활동
	g_EyeXGaze.Init(this->m_hWnd, UM_EYEX_HOST_STATUS_CHANGED, UM_REGION_GOT_ACTIVATION_FOCUS, UM_REGION_ACTIVATED);
}

void CEye_Computing_DialogDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BKSPACE, m_btn_BkSpace);
	DDX_Control(pDX, IDC_Enter, m_btn_Back);
	DDX_Control(pDX, IDC_GiYeok, m_btn_GiYeok);
	DDX_Control(pDX, IDC_NiEun, m_btn_NiEun);
	DDX_Control(pDX, IDC_DiGeut, m_btn_DiGeut);
	DDX_Control(pDX, IDC_Confirm, m_btn_Confirm);
	DDX_Control(pDX, IDC_RIEUL, m_btn_RiEul);
	DDX_Control(pDX, IDC_MIEUM, m_btn_MiEum);
	DDX_Control(pDX, IDC_BIEUP, m_btn_BiEup);
	DDX_Control(pDX, IDC_Zzum, m_btn_Zzum);
	DDX_Control(pDX, IDC_Iii, m_btn_Yi);
	DDX_Control(pDX, IDC_SHIOT, m_btn_ShiOt);
	DDX_Control(pDX, IDC_Eu, m_btn_Eu);
	DDX_Control(pDX, IDC_SPACE, m_btn_Space);
	DDX_Control(pDX, IDC_IEUNG, m_btn_IEung);
	DDX_Control(pDX, IDC_KIEUK, m_btn_KiEuk);
	DDX_Control(pDX, IDC_CHIEUT, m_btn_ChiEut);
	DDX_Control(pDX, IDC_JIEUT, m_btn_JiEut);
	DDX_Control(pDX, IDC_TIEUT, m_btn_TiEut);
	DDX_Control(pDX, IDC_PIEUP, m_btn_PiEup);
	DDX_Control(pDX, IDC_HIEUT, m_btn_HiEut);
	DDX_Control(pDX, IDC_BACKGROUND, m_BkGround);
}

BEGIN_MESSAGE_MAP(CEye_Computing_DialogDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_GiYeok, &CEye_Computing_DialogDlg::OnBnClickedGiyeok)
	ON_WM_NCLBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_NiEun, &CEye_Computing_DialogDlg::OnBnClickedNieun)
	ON_BN_CLICKED(IDC_Zzum, &CEye_Computing_DialogDlg::OnBnClickedZzum)
	ON_BN_CLICKED(IDC_Eu, &CEye_Computing_DialogDlg::OnBnClickedEu)
	ON_MESSAGE(UM_REGION_ACTIVATED, &CEye_Computing_DialogDlg::OnUM_REGION_ACTIVATED)
	ON_MESSAGE(UM_REGION_ACTIVATED, &CEye_Computing_DialogDlg::OnUM_EYEX_HOST_STATUS_CHANGED)
	ON_BN_CLICKED(IDC_Iii, &CEye_Computing_DialogDlg::OnBnClickedIii)
	ON_BN_CLICKED(IDC_DiGeut, &CEye_Computing_DialogDlg::OnBnClickedDigeut)
	ON_BN_CLICKED(IDC_RIEUL, &CEye_Computing_DialogDlg::OnBnClickedRieul)
	ON_BN_CLICKED(IDC_MIEUM, &CEye_Computing_DialogDlg::OnBnClickedMieum)
	ON_BN_CLICKED(IDC_BIEUP, &CEye_Computing_DialogDlg::OnBnClickedBieup)
	ON_BN_CLICKED(IDC_SHIOT, &CEye_Computing_DialogDlg::OnBnClickedShiot)
	ON_BN_CLICKED(IDC_IEUNG, &CEye_Computing_DialogDlg::OnBnClickedIeung)
	ON_BN_CLICKED(IDC_JIEUT, &CEye_Computing_DialogDlg::OnBnClickedJieut)
	ON_BN_CLICKED(IDC_CHIEUT, &CEye_Computing_DialogDlg::OnBnClickedChieut)
	ON_BN_CLICKED(IDC_KIEUK, &CEye_Computing_DialogDlg::OnBnClickedKieuk)
	ON_BN_CLICKED(IDC_TIEUT, &CEye_Computing_DialogDlg::OnBnClickedTieut)
	ON_BN_CLICKED(IDC_PIEUP, &CEye_Computing_DialogDlg::OnBnClickedPieup)
	ON_BN_CLICKED(IDC_HIEUT, &CEye_Computing_DialogDlg::OnBnClickedHieut)
	ON_BN_CLICKED(IDC_SPACE, &CEye_Computing_DialogDlg::OnBnClickedSpace)
	ON_BN_CLICKED(IDC_BKSPACE, &CEye_Computing_DialogDlg::OnBnClickedBkspace)
	ON_BN_CLICKED(IDC_Confirm, &CEye_Computing_DialogDlg::OnBnClickedConfirm)
	ON_BN_CLICKED(IDC_Enter, &CEye_Computing_DialogDlg::OnBnClickedEnter)
END_MESSAGE_MAP()







// 응시점으로 마우스 옮기는 함수..?
LRESULT CEye_Computing_DialogDlg::OnUM_REGION_ACTIVATED(WPARAM wParam, LPARAM IParam)
{
	
	POINT gazePoint;
	gazePoint.x = (LONG)g_EyeXGaze.getFixEye_X();
	gazePoint.y = (LONG)g_EyeXGaze.getFixEye_Y();

	//SetCursorPos(gazePoint.x, gazePoint.y);

	SetCursorPos(200, 200);

	return 0;
}

LRESULT CEye_Computing_DialogDlg::OnUM_EYEX_HOST_STATUS_CHANGED(WPARAM wParam, LPARAM IParam)
{
	POINT gazePoint;
	gazePoint.x = (LONG)g_EyeXGaze.getFixEye_X();
	gazePoint.y = (LONG)g_EyeXGaze.getFixEye_Y();

	//SetCursorPos(gazePoint.x, gazePoint.y);

	SetCursorPos(200, 200);

	return 0;
}













// CEye_Computing_DialogDlg 메시지 처리기

BOOL CEye_Computing_DialogDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 윈도우 사이즈 지정 및 고정(다시 그리지 않는다)
	SetWindowPos(NULL, 0, 0, 625, 650, SWP_NOREDRAW);

	// 버튼 이미지 삽입
	m_btn_BkSpace.SetSkin(IDB_BKSPACE, IDB_BKSPACE, IDB_BKSPACE, IDB_BKSPACE, 0, IDB_BKSPACE, 0, 0, 0);
	m_btn_Back.SetSkin(IDB_Enter, IDB_Enter, IDB_Enter, IDB_Enter, 0, IDB_Enter, 0, 0, 0);
	m_btn_GiYeok.SetSkin(IDB_GIYEOK, IDB_GIYEOK, IDB_GIYEOK, IDB_GIYEOK, 0, IDB_GIYEOK, 0, 0, 0);
	m_btn_NiEun.SetSkin(IDB_NIEUN, IDB_NIEUN, IDB_NIEUN, IDB_NIEUN, 0, IDB_NIEUN, 0, 0, 0);
	m_btn_DiGeut.SetSkin(IDB_DIGEUT, IDB_DIGEUT, IDB_DIGEUT, IDB_DIGEUT, 0, IDB_DIGEUT, 0, 0, 0);
	m_btn_Confirm.SetSkin(IDB_CONFIRM, IDB_CONFIRM, IDB_CONFIRM, IDB_CONFIRM, 0, IDB_CONFIRM, 0, 0, 0);
	m_btn_RiEul.SetSkin(IDB_RIEUL, IDB_RIEUL, IDB_RIEUL, IDB_RIEUL, 0, IDB_RIEUL, 0, 0, 0);
	m_btn_MiEum.SetSkin(IDB_MIEUM, IDB_MIEUM, IDB_MIEUM, IDB_MIEUM, 0, IDB_MIEUM, 0, 0, 0);
	m_btn_BiEup.SetSkin(IDB_BIEUP, IDB_BIEUP, IDB_BIEUP, IDB_BIEUP, 0, IDB_BIEUP, 0, 0, 0);
	m_btn_Zzum.SetSkin(IDB_ZZUM, IDB_ZZUM, IDB_ZZUM, IDB_ZZUM, 0, IDB_ZZUM, 0, 0, 0);
	m_btn_Yi.SetSkin(IDB_Iii, IDB_Iii, IDB_Iii, IDB_Iii, 0, IDB_Iii, 0, 0, 0);
	m_btn_ShiOt.SetSkin(IDB_SHIOT, IDB_SHIOT, IDB_SHIOT, IDB_SHIOT, 0, IDB_SHIOT, 0, 0, 0);
	m_btn_Eu.SetSkin(IDB_EU, IDB_EU, IDB_EU, IDB_EU, 0, IDB_EU, 0, 0, 0);
	m_btn_Space.SetSkin(IDB_SPACE, IDB_SPACE, IDB_SPACE, IDB_SPACE, 0, IDB_SPACE, 0, 0, 0);
	m_btn_IEung.SetSkin(IDB_IEUNG, IDB_IEUNG, IDB_IEUNG, IDB_IEUNG, 0, IDB_IEUNG, 0, 0, 0);
	m_btn_KiEuk.SetSkin(IDB_KIEUK, IDB_KIEUK, IDB_KIEUK, IDB_KIEUK, 0, IDB_KIEUK, 0, 0, 0);
	m_btn_ChiEut.SetSkin(IDB_CHIEUT, IDB_CHIEUT, IDB_CHIEUT, IDB_CHIEUT, 0, IDB_CHIEUT, 0, 0, 0);
	m_btn_JiEut.SetSkin(IDB_JIEUT, IDB_JIEUT, IDB_JIEUT, IDB_JIEUT, 0, IDB_JIEUT, 0, 0, 0);
	m_btn_TiEut.SetSkin(IDB_TIEUT, IDB_TIEUT, IDB_TIEUT, IDB_TIEUT, 0, IDB_TIEUT, 0, 0, 0);
	m_btn_PiEup.SetSkin(IDB_PIEUP, IDB_PIEUP, IDB_PIEUP, IDB_PIEUP, 0, IDB_PIEUP, 0, 0, 0);
	m_btn_HiEut.SetSkin(IDB_HIEUT, IDB_HIEUT, IDB_HIEUT, IDB_HIEUT, 0, IDB_HIEUT, 0, 0, 0);

	// 버튼 좌표 노가다
	GetDlgItem(IDC_BACKGROUND)->SetWindowPos(NULL, 0, 0, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_BKSPACE)->SetWindowPos(NULL, 186, 12, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_Enter)->SetWindowPos(NULL, 106, 46, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_GiYeok)->SetWindowPos(NULL, 43, 105, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_NiEun)->SetWindowPos(NULL, 14, 185, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_DiGeut)->SetWindowPos(NULL, 16, 278, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_Confirm)->SetWindowPos(NULL, 185, 92, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_RIEUL)->SetWindowPos(NULL, 117, 136, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_MIEUM)->SetWindowPos(NULL, 88, 217, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_BIEUP)->SetWindowPos(NULL, 103, 307, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_Zzum)->SetWindowPos(NULL, 227, 175, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_Iii)->SetWindowPos(NULL, 168, 235, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_SHIOT)->SetWindowPos(NULL, 159, 363, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_Eu)->SetWindowPos(NULL, 281, 232, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_SPACE)->SetWindowPos(NULL, 228, 287, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_IEUNG)->SetWindowPos(NULL, 244, 376, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_KIEUK)->SetWindowPos(NULL, 369, 188, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_CHIEUT)->SetWindowPos(NULL, 368, 280, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_JIEUT)->SetWindowPos(NULL, 326, 346, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_TIEUT)->SetWindowPos(NULL, 445, 191, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_PIEUP)->SetWindowPos(NULL, 443, 279, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_HIEUT)->SetWindowPos(NULL, 412, 357, 150, 150, SWP_NOSIZE);
			 

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

	//
	SetWindowText(_T("EYE MAKE IT"));

	//항상 최상위 window가 되도록 설정
	SetWindowPos((const CWnd*)&(this->m_hWnd), (int)(HWND_TOPMOST), 0, 0, 0, (UINT)(SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW));
	
	// window창 반투명하게 설정
	LONG ExtendedStyle = GetWindowLong(GetSafeHwnd(), GWL_EXSTYLE);
	SetWindowLong(GetSafeHwnd(), GWL_EXSTYLE, ExtendedStyle | WS_EX_LAYERED);
	BYTE byAlphaValue = 200; // 0 - 255 (Transparent Range)
	::SetLayeredWindowAttributes(GetSafeHwnd(),0,byAlphaValue,LWA_ALPHA);

	

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

		// 키보드 배경 이미지 출력
		HBITMAP hbit;
		hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BACKGROUND));
		m_BkGround.SetBitmap(hbit);
		
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CEye_Computing_DialogDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


// Enter 눌러도 창이 닫기지 않도록  합니다.
void CEye_Computing_DialogDlg::OnOK()
{
	return;
}


// 마우스 왼쪽 클릭?
void CEye_Computing_DialogDlg::OnNcLButtonDown(UINT nHitTest, CPoint point)
{
	if (!m_hForegroundWnd)
	{
		m_hForegroundWnd = ::GetForegroundWindow();
		ModifyStyleEx(WS_EX_NOACTIVATE, 0);
		SetForegroundWindow();
	}
	//키보드가 항상 최상위에 위치하도록  
	SetWindowPos((const CWnd*)&(this->m_hWnd), (int)(HWND_TOPMOST), 0, 0, 0, (UINT)(SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW));
	
	CDialog::OnNcLButtonDown(nHitTest, point);
}
// 마우스 움직임
void CEye_Computing_DialogDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	if (m_hForegroundWnd)
	{
		::SetForegroundWindow(m_hForegroundWnd);
		ModifyStyleEx(0, WS_EX_NOACTIVATE);

		if (isStart)
		{
			//포커스 키보드로 오면 한/영 눌러서 한글로 시작하기!
			INPUT HanToEng;
			::ZeroMemory(&HanToEng, sizeof(INPUT));
			HanToEng.type = INPUT_KEYBOARD;
			HanToEng.ki.wVk = VK_HANGEUL;
			::SendInput(1, &HanToEng, sizeof(INPUT));
			HanToEng.ki.dwFlags = KEYEVENTF_KEYUP;
			::SendInput(1, &HanToEng, sizeof(INPUT));
			isStart = FALSE;
		}
		m_hForegroundWnd = NULL;
	}

	CDialog::OnMouseMove(nFlags, point);
}
























































































// 모음 - ㅣ
void CEye_Computing_DialogDlg::OnBnClickedIii()
{
	if (clickedZzum)
	{
		INPUT InputEo;
		::ZeroMemory(&InputEo, sizeof(INPUT));
		InputEo.type = INPUT_KEYBOARD;

		//ㅓ 씀
		InputEo.ki.wVk = 0x4A;
		::SendInput(1, &InputEo, sizeof(INPUT));
		InputEo.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputEo, sizeof(INPUT));
		clickedEo = true;
		clickedZzum = false;
	}
	else if (clickedZzum2)
	{
		INPUT InputYeo;
		::ZeroMemory(&InputYeo, sizeof(INPUT));
		InputYeo.type = INPUT_KEYBOARD;

		//ㅕ 씀
		InputYeo.ki.wVk = 0x55;
		::SendInput(1, &InputYeo, sizeof(INPUT));
		InputYeo.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputYeo, sizeof(INPUT));
		clickedYeo = true;
		clickedZzum2 = false;
	}
	else if (clickedAaa)
	{
		INPUT InputAe;
		::ZeroMemory(&InputAe, sizeof(INPUT));
		InputAe.type = INPUT_KEYBOARD;

		//한번 지움
		InputAe.ki.wVk = 0x08;
		::SendInput(1, &InputAe, sizeof(INPUT));
		InputAe.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputAe, sizeof(INPUT));

		//ㅐ 씀
		InputAe.ki.wVk = 0x4F;
		InputAe.ki.dwFlags = 0;
		::SendInput(1, &InputAe, sizeof(INPUT));
		InputAe.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputAe, sizeof(INPUT));
		clickedAaa = false;
	}
	else if (clickedYa)
	{
		INPUT InputYae;
		::ZeroMemory(&InputYae, sizeof(INPUT));
		InputYae.type = INPUT_KEYBOARD;

		//한번 지움
		InputYae.ki.wVk = 0x08;
		::SendInput(1, &InputYae, sizeof(INPUT));
		InputYae.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputYae, sizeof(INPUT));

		//ㅒ 씀
		//시프트 누르고있고
		InputYae.ki.wVk = 0x10;
		InputYae.ki.dwFlags = 0;
		::SendInput(1, &InputYae, sizeof(INPUT));
		//ㅐ 침
		InputYae.ki.wVk = 0x4F;
		::SendInput(1, &InputYae, sizeof(INPUT));
		InputYae.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputYae, sizeof(INPUT));
		// 시프트 땜
		InputYae.ki.wVk = 0x10;
		InputYae.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputYae, sizeof(INPUT));
		clickedYa = false;
	}
	else if (clickedEo)
	{
		INPUT InputEee;
		::ZeroMemory(&InputEee, sizeof(INPUT));
		InputEee.type = INPUT_KEYBOARD;

		//한번 지움
		InputEee.ki.wVk = 0x08;
		::SendInput(1, &InputEee, sizeof(INPUT));
		InputEee.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputEee, sizeof(INPUT));

		//ㅔ 씀
		InputEee.ki.wVk = 0x50;
		InputEee.ki.dwFlags = 0;
		::SendInput(1, &InputEee, sizeof(INPUT));
		InputEee.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputEee, sizeof(INPUT));
		clickedEo = false;
	}
	else if (clickedYeo)
	{
		INPUT InputYe;
		::ZeroMemory(&InputYe, sizeof(INPUT));
		InputYe.type = INPUT_KEYBOARD;

		//한번 지움
		InputYe.ki.wVk = 0x08;
		::SendInput(1, &InputYe, sizeof(INPUT));
		InputYe.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputYe, sizeof(INPUT));

		//ㅖ 씀
		//시프트 누르고있고
		InputYe.ki.wVk = 0x10;
		InputYe.ki.dwFlags = 0;
		::SendInput(1, &InputYe, sizeof(INPUT));
		//ㅔ 침
		InputYe.ki.wVk = 0x50;
		::SendInput(1, &InputYe, sizeof(INPUT));
		InputYe.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputYe, sizeof(INPUT));
		// 시프트 땜
		InputYe.ki.wVk = 0x10;
		InputYe.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputYe, sizeof(INPUT));
		clickedYeo = false;
	}
	else if (clickedWa)
	{
		INPUT InputWae;
		::ZeroMemory(&InputWae, sizeof(INPUT));
		InputWae.type = INPUT_KEYBOARD;

		//한번 지움
		InputWae.ki.wVk = 0x08;
		::SendInput(1, &InputWae, sizeof(INPUT));
		InputWae.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputWae, sizeof(INPUT));

		//ㅙ 씀
		InputWae.ki.wVk = 0x4F;
		InputWae.ki.dwFlags = 0;
		::SendInput(1, &InputWae, sizeof(INPUT));
		InputWae.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputWae, sizeof(INPUT));
		clickedWa = false;
	}
	else if (clickedUuuAndZzum)
	{
		INPUT InputWo;
		::ZeroMemory(&InputWo, sizeof(INPUT));
		InputWo.type = INPUT_KEYBOARD;

		//한번 지움
		InputWo.ki.wVk = 0x08;
		::SendInput(1, &InputWo, sizeof(INPUT));
		InputWo.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputWo, sizeof(INPUT));

		//ㅝ 씀
		//ㅜ
		InputWo.ki.wVk = 0x4E;
		InputWo.ki.dwFlags = 0;
		::SendInput(1, &InputWo, sizeof(INPUT));
		InputWo.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputWo, sizeof(INPUT));
		//ㅓ
		InputWo.ki.wVk = 0x4A;
		InputWo.ki.dwFlags = 0;
		::SendInput(1, &InputWo, sizeof(INPUT));
		InputWo.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputWo, sizeof(INPUT));
		clickedWo = true;
		clickedUuuAndZzum = false;
	}
	else if (clickedWo)
	{

		INPUT InputWe;
		::ZeroMemory(&InputWe, sizeof(INPUT));
		InputWe.type = INPUT_KEYBOARD;

		//한번 지움
		InputWe.ki.wVk = 0x08;
		::SendInput(1, &InputWe, sizeof(INPUT));
		InputWe.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputWe, sizeof(INPUT));

		//ㅞ 씀
		InputWe.ki.wVk = 0x50;
		InputWe.ki.dwFlags = 0;
		::SendInput(1, &InputWe, sizeof(INPUT));
		InputWe.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputWe, sizeof(INPUT));
		clickedWo = false;
	}
	else if (clickedOoo)
	{
		//ㅚ 입력
		INPUT InputWe;
		//initialize
		::ZeroMemory(&InputWe, sizeof(INPUT));
		//keyboard로 입력하겠다.
		InputWe.type = INPUT_KEYBOARD;
		//어떤버튼누를건지
		InputWe.ki.wVk = 0x4C;
		//한번눌러주기
		::SendInput(1, &InputWe, sizeof(INPUT));
		//누른거 풀어주기
		InputWe.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputWe, sizeof(INPUT));
		// ㅚ 눌러주고, ㅗ 풀어주기
		clickedWe = true;
		clickedOoo = false;
	}
	else
	{
		INPUT InputYee;
		//initialize
		::ZeroMemory(&InputYee, sizeof(INPUT));
		//keyboard로 입력하겠다.
		InputYee.type = INPUT_KEYBOARD;
		//어떤버튼누를건지
		InputYee.ki.wVk = 0x4C;
		//한번눌러주기
		::SendInput(1, &InputYee, sizeof(INPUT));
		//누른거 풀어주기
		InputYee.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputYee, sizeof(INPUT));
		// ㅣ 누른상태로 만들어주기
		clickedIii = true;
	}
}

// 모음 - 점
void CEye_Computing_DialogDlg::OnBnClickedZzum()
{
	if (clickedIii)
	{
		INPUT InputAh;
		::ZeroMemory(&InputAh, sizeof(INPUT));
		InputAh.type = INPUT_KEYBOARD;

		//한번 지움
		InputAh.ki.wVk = 0x08;
		::SendInput(1, &InputAh, sizeof(INPUT));
		InputAh.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputAh, sizeof(INPUT));

		//ㅏ 씀
		InputAh.ki.wVk = 0x4B;
		InputAh.ki.dwFlags = 0;
		::SendInput(1, &InputAh, sizeof(INPUT));
		InputAh.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputAh, sizeof(INPUT));
		clickedIii = false;
		clickedAaa = true;
	}
	else if (clickedAaa)
	{
		INPUT InputYa;
		::ZeroMemory(&InputYa, sizeof(INPUT));
		InputYa.type = INPUT_KEYBOARD;

		//한번 지움
		InputYa.ki.wVk = 0x08;
		::SendInput(1, &InputYa, sizeof(INPUT));
		InputYa.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputYa, sizeof(INPUT));

		//ㅑ 씀
		InputYa.ki.wVk = 0x49;
		InputYa.ki.dwFlags = 0;
		::SendInput(1, &InputYa, sizeof(INPUT));
		InputYa.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputYa, sizeof(INPUT));
		clickedAaa = false;
		clickedYa = true;
	}
	else if (clickedEu)
	{
		INPUT InputUuu;
		::ZeroMemory(&InputUuu, sizeof(INPUT));
		InputUuu.type = INPUT_KEYBOARD;

		//한번 지움
		InputUuu.ki.wVk = 0x08;
		::SendInput(1, &InputUuu, sizeof(INPUT));
		InputUuu.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputUuu, sizeof(INPUT));

		//ㅜ 씀
		InputUuu.ki.wVk = 0x4E;
		InputUuu.ki.dwFlags = 0;
		::SendInput(1, &InputUuu, sizeof(INPUT));
		InputUuu.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputUuu, sizeof(INPUT));
		clickedEu = false;
		clickedUuu = true;
	}
	else if (clickedUuu)
	{
		INPUT InputYu;
		::ZeroMemory(&InputYu, sizeof(INPUT));
		InputYu.type = INPUT_KEYBOARD;

		//한번 지움
		InputYu.ki.wVk = 0x08;
		::SendInput(1, &InputYu, sizeof(INPUT));
		InputYu.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputYu, sizeof(INPUT));

		//ㅠ 씀
		InputYu.ki.wVk = 0x42;
		InputYu.ki.dwFlags = 0;
		::SendInput(1, &InputYu, sizeof(INPUT));
		InputYu.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputYu, sizeof(INPUT));
		clickedUuu = false;
		clickedUuuAndZzum = true;
	}
	else if (clickedWe)
	{
		INPUT InputWa;
		::ZeroMemory(&InputWa, sizeof(INPUT));
		InputWa.type = INPUT_KEYBOARD;

		//한번 지움
		InputWa.ki.wVk = 0x08;
		::SendInput(1, &InputWa, sizeof(INPUT));
		InputWa.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputWa, sizeof(INPUT));

		//ㅘ 씀
		InputWa.ki.wVk = 0x4B;
		InputWa.ki.dwFlags = 0;
		::SendInput(1, &InputWa, sizeof(INPUT));
		InputWa.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputWa, sizeof(INPUT));
		clickedWe = false;
		clickedWa = true;
	}
	else if (clickedZzum)
	{
		clickedZzum2 = true;
		clickedZzum = false;
	}
	else
		clickedZzum = true;
}

// 모음 - ㅡ
void CEye_Computing_DialogDlg::OnBnClickedEu()
{
	if (clickedZzum)
	{
		INPUT InputOoo;
		::ZeroMemory(&InputOoo, sizeof(INPUT));
		InputOoo.type = INPUT_KEYBOARD;

		//ㅗ 씀
		InputOoo.ki.wVk = 0x48;
		::SendInput(1, &InputOoo, sizeof(INPUT));
		InputOoo.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputOoo, sizeof(INPUT));
		clickedOoo = true;
		clickedZzum = false;
	}
	else if (clickedZzum2)
	{
		INPUT InputYo;
		::ZeroMemory(&InputYo, sizeof(INPUT));
		InputYo.type = INPUT_KEYBOARD;

		//ㅛ 씀
		InputYo.ki.wVk = 0x59;
		::SendInput(1, &InputYo, sizeof(INPUT));
		InputYo.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputYo, sizeof(INPUT));
		clickedZzum2 = false;
	}
	else
	{
		INPUT InputEu;
		//initialize
		::ZeroMemory(&InputEu, sizeof(INPUT));
		//keyboard로 입력하겠다.
		InputEu.type = INPUT_KEYBOARD;
		//어떤버튼누를건지
		InputEu.ki.wVk = 0x4D;
		//한번눌러주기
		::SendInput(1, &InputEu, sizeof(INPUT));
		//누른거 풀어주기
		InputEu.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputEu, sizeof(INPUT));
		//ㅡ 누른상태로 만들어줌
		clickedEu = true;
	}
}

// 모음 상태 초기화
void CEye_Computing_DialogDlg::initHanguel()
{
	clickedIii = false;
	clickedZzum = false;
	clickedEu = false;
	clickedAaa = false;
	clickedZzum2 = false;
	clickedUuu = false;
	clickedYa = false;
	clickedEo = false;
	clickedYeo = false;
	clickedWe = false;
	clickedEoh = false;
	clickedWa = false;
	clickedUuuAndZzum = false;
	clickedWo = false;
	clickedOoo = false;
}

// 자음 - ㄱ
void CEye_Computing_DialogDlg::OnBnClickedGiyeok()
{
	initHanguel();
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
// 자음 - ㄴ
void CEye_Computing_DialogDlg::OnBnClickedNieun()
{
	initHanguel();
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
// 자음 - ㄷ
void CEye_Computing_DialogDlg::OnBnClickedDigeut()
{
	initHanguel();
	INPUT InputDigeut;
	//initialize
	::ZeroMemory(&InputDigeut, sizeof(INPUT));
	//keyboard로 입력하겠다.
	InputDigeut.type = INPUT_KEYBOARD;
	//어떤버튼누를건지
	InputDigeut.ki.wVk = 0x45;
	//한번눌러주기
	::SendInput(1, &InputDigeut, sizeof(INPUT));
	//누른거 풀어주기
	InputDigeut.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &InputDigeut, sizeof(INPUT));
}
//자음 - ㄹ
void CEye_Computing_DialogDlg::OnBnClickedRieul()
{
	initHanguel();
	INPUT InputRieul;
	//initialize
	::ZeroMemory(&InputRieul, sizeof(INPUT));
	//keyboard로 입력하겠다.
	InputRieul.type = INPUT_KEYBOARD;
	//어떤버튼누를건지
	InputRieul.ki.wVk = 0x46;
	//한번눌러주기
	::SendInput(1, &InputRieul, sizeof(INPUT));
	//누른거 풀어주기
	InputRieul.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &InputRieul, sizeof(INPUT));
}
//자음 - ㅁ
void CEye_Computing_DialogDlg::OnBnClickedMieum()
{
	initHanguel();
	INPUT InputMiEum;
	//initialize
	::ZeroMemory(&InputMiEum, sizeof(INPUT));
	//keyboard로 입력하겠다.
	InputMiEum.type = INPUT_KEYBOARD;
	//어떤버튼누를건지
	InputMiEum.ki.wVk = 0x41;
	//한번눌러주기
	::SendInput(1, &InputMiEum, sizeof(INPUT));
	//누른거 풀어주기
	InputMiEum.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &InputMiEum, sizeof(INPUT));
}
// 자음 - ㅂ
void CEye_Computing_DialogDlg::OnBnClickedBieup()
{
	initHanguel();
	INPUT InputBiEup;
	//initialize
	::ZeroMemory(&InputBiEup, sizeof(INPUT));
	//keyboard로 입력하겠다.
	InputBiEup.type = INPUT_KEYBOARD;
	//어떤버튼누를건지
	InputBiEup.ki.wVk = 0x51;
	//한번눌러주기
	::SendInput(1, &InputBiEup, sizeof(INPUT));
	//누른거 풀어주기
	InputBiEup.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &InputBiEup, sizeof(INPUT));
}
// 자음 - ㅅ
void CEye_Computing_DialogDlg::OnBnClickedShiot()
{
	initHanguel();
	INPUT InputShiOt;
	//initialize
	::ZeroMemory(&InputShiOt, sizeof(INPUT));
	//keyboard로 입력하겠다.
	InputShiOt.type = INPUT_KEYBOARD;
	//어떤버튼누를건지
	InputShiOt.ki.wVk = 0x54;
	//한번눌러주기
	::SendInput(1, &InputShiOt, sizeof(INPUT));
	//누른거 풀어주기
	InputShiOt.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &InputShiOt, sizeof(INPUT));
}
// 자음 - ㅇ
void CEye_Computing_DialogDlg::OnBnClickedIeung()
{
	initHanguel();
	INPUT InputIeung;
	//initialize
	::ZeroMemory(&InputIeung, sizeof(INPUT));
	//keyboard로 입력하겠다.
	InputIeung.type = INPUT_KEYBOARD;
	//어떤버튼누를건지
	InputIeung.ki.wVk = 0x44;
	//한번눌러주기
	::SendInput(1, &InputIeung, sizeof(INPUT));
	//누른거 풀어주기
	InputIeung.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &InputIeung, sizeof(INPUT));
}
// 자음 - ㅈ
void CEye_Computing_DialogDlg::OnBnClickedJieut()
{
	initHanguel();
	INPUT InputJiEut;
	//initialize
	::ZeroMemory(&InputJiEut, sizeof(INPUT));
	//keyboard로 입력하겠다.
	InputJiEut.type = INPUT_KEYBOARD;
	//어떤버튼누를건지
	InputJiEut.ki.wVk = 0x57;
	//한번눌러주기
	::SendInput(1, &InputJiEut, sizeof(INPUT));
	//누른거 풀어주기
	InputJiEut.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &InputJiEut, sizeof(INPUT));
}
//자음 - ㅊ
void CEye_Computing_DialogDlg::OnBnClickedChieut()
{
	initHanguel();
	INPUT InputChiEut;
	//initialize
	::ZeroMemory(&InputChiEut, sizeof(INPUT));
	//keyboard로 입력하겠다.
	InputChiEut.type = INPUT_KEYBOARD;
	//어떤버튼누를건지
	InputChiEut.ki.wVk = 0x43;
	//한번눌러주기
	::SendInput(1, &InputChiEut, sizeof(INPUT));
	//누른거 풀어주기
	InputChiEut.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &InputChiEut, sizeof(INPUT));
}
// 자음 - ㅋ
void CEye_Computing_DialogDlg::OnBnClickedKieuk()
{
	initHanguel();
	INPUT InputKieuk;
	//initialize
	::ZeroMemory(&InputKieuk, sizeof(INPUT));
	//keyboard로 입력하겠다.
	InputKieuk.type = INPUT_KEYBOARD;
	//어떤버튼누를건지
	InputKieuk.ki.wVk = 0x5A;
	//한번눌러주기
	::SendInput(1, &InputKieuk, sizeof(INPUT));
	//누른거 풀어주기
	InputKieuk.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &InputKieuk, sizeof(INPUT));
}
// 자음 - ㅌ
void CEye_Computing_DialogDlg::OnBnClickedTieut()
{
	initHanguel();
	INPUT InputTieut;
	//initialize
	::ZeroMemory(&InputTieut, sizeof(INPUT));
	//keyboard로 입력하겠다.
	InputTieut.type = INPUT_KEYBOARD;
	//어떤버튼누를건지
	InputTieut.ki.wVk = 0x59;
	//한번눌러주기
	::SendInput(1, &InputTieut, sizeof(INPUT));
	//누른거 풀어주기
	InputTieut.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &InputTieut, sizeof(INPUT));
}
// 자음 - ㅍ
void CEye_Computing_DialogDlg::OnBnClickedPieup()
{
	initHanguel();
	INPUT InputPieup;
	//initialize
	::ZeroMemory(&InputPieup, sizeof(INPUT));
	//keyboard로 입력하겠다.
	InputPieup.type = INPUT_KEYBOARD;
	//어떤버튼누를건지
	InputPieup.ki.wVk = 0x56;
	//한번눌러주기
	::SendInput(1, &InputPieup, sizeof(INPUT));
	//누른거 풀어주기
	InputPieup.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &InputPieup, sizeof(INPUT));
}
// 자음 - ㅎ
void CEye_Computing_DialogDlg::OnBnClickedHieut()
{
	initHanguel();
	INPUT InputHieut;
	//initialize
	::ZeroMemory(&InputHieut, sizeof(INPUT));
	//keyboard로 입력하겠다.
	InputHieut.type = INPUT_KEYBOARD;
	//어떤버튼누를건지
	InputHieut.ki.wVk = 0x47;
	//한번눌러주기
	::SendInput(1, &InputHieut, sizeof(INPUT));
	//누른거 풀어주기
	InputHieut.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &InputHieut, sizeof(INPUT));
}
// 스페이스바
void CEye_Computing_DialogDlg::OnBnClickedSpace()
{
	initHanguel();
	INPUT InputSpace;
	//initialize
	::ZeroMemory(&InputSpace, sizeof(INPUT));
	//keyboard로 입력하겠다.
	InputSpace.type = INPUT_KEYBOARD;
	//어떤버튼누를건지
	InputSpace.ki.wVk = 0x20;
	//한번눌러주기
	::SendInput(1, &InputSpace, sizeof(INPUT));
	//누른거 풀어주기
	InputSpace.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &InputSpace, sizeof(INPUT));
}
// backspace
void CEye_Computing_DialogDlg::OnBnClickedBkspace()
{
	initHanguel();
	INPUT InputBackSpace;
	//initialize
	::ZeroMemory(&InputBackSpace, sizeof(INPUT));
	//keyboard로 입력하겠다.
	InputBackSpace.type = INPUT_KEYBOARD;
	//어떤버튼누를건지
	InputBackSpace.ki.wVk = 0x08;
	//한번눌러주기
	::SendInput(1, &InputBackSpace, sizeof(INPUT));
	//누른거 풀어주기
	InputBackSpace.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &InputBackSpace, sizeof(INPUT));
}
// confirm?
void CEye_Computing_DialogDlg::OnBnClickedConfirm()
{
	CDialogEx::OnOK();
}
// enter
void CEye_Computing_DialogDlg::OnBnClickedEnter()
{
	initHanguel();
	INPUT InputEnter;
	//initialize
	::ZeroMemory(&InputEnter, sizeof(INPUT));
	//keyboard로 입력하겠다.
	InputEnter.type = INPUT_KEYBOARD;
	//어떤버튼누를건지
	InputEnter.ki.wVk = 0x0D;
	//한번눌러주기
	::SendInput(1, &InputEnter, sizeof(INPUT));
	//누른거 풀어주기
	InputEnter.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &InputEnter, sizeof(INPUT));

}
