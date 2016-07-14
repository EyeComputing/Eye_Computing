// Eye_Computing_DialogDlg.cpp : ���� ����
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

//���!
EyeXGaze g_EyeXGaze;	// �ν��Ͻ� �����ϸ鼭 ������ �����.

//������ �� �ѱ۷� �ٲ��� ���� ���
bool isStart = true;

//õ���� �Ҷ�� ���
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


// CEye_Computing_DialogDlg ��ȭ ����

CEye_Computing_DialogDlg::CEye_Computing_DialogDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CEye_Computing_DialogDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_hForegroundWnd = NULL;
	//initialize EyeXGaze				status-> ������ �����°�? focus -> ���� activated -> Ȱ��
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







// ���������� ���콺 �ű�� �Լ�..?
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













// CEye_Computing_DialogDlg �޽��� ó����

BOOL CEye_Computing_DialogDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ������ ������ ���� �� ����(�ٽ� �׸��� �ʴ´�)
	SetWindowPos(NULL, 0, 0, 625, 650, SWP_NOREDRAW);

	// ��ư �̹��� ����
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

	// ��ư ��ǥ �밡��
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

	//
	SetWindowText(_T("EYE MAKE IT"));

	//�׻� �ֻ��� window�� �ǵ��� ����
	SetWindowPos((const CWnd*)&(this->m_hWnd), (int)(HWND_TOPMOST), 0, 0, 0, (UINT)(SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW));
	
	// windowâ �������ϰ� ����
	LONG ExtendedStyle = GetWindowLong(GetSafeHwnd(), GWL_EXSTYLE);
	SetWindowLong(GetSafeHwnd(), GWL_EXSTYLE, ExtendedStyle | WS_EX_LAYERED);
	BYTE byAlphaValue = 200; // 0 - 255 (Transparent Range)
	::SetLayeredWindowAttributes(GetSafeHwnd(),0,byAlphaValue,LWA_ALPHA);

	

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CEye_Computing_DialogDlg::OnPaint()
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

		// Ű���� ��� �̹��� ���
		HBITMAP hbit;
		hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BACKGROUND));
		m_BkGround.SetBitmap(hbit);
		
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CEye_Computing_DialogDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


// Enter ������ â�� �ݱ��� �ʵ���  �մϴ�.
void CEye_Computing_DialogDlg::OnOK()
{
	return;
}


// ���콺 ���� Ŭ��?
void CEye_Computing_DialogDlg::OnNcLButtonDown(UINT nHitTest, CPoint point)
{
	if (!m_hForegroundWnd)
	{
		m_hForegroundWnd = ::GetForegroundWindow();
		ModifyStyleEx(WS_EX_NOACTIVATE, 0);
		SetForegroundWindow();
	}
	//Ű���尡 �׻� �ֻ����� ��ġ�ϵ���  
	SetWindowPos((const CWnd*)&(this->m_hWnd), (int)(HWND_TOPMOST), 0, 0, 0, (UINT)(SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW));
	
	CDialog::OnNcLButtonDown(nHitTest, point);
}
// ���콺 ������
void CEye_Computing_DialogDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	if (m_hForegroundWnd)
	{
		::SetForegroundWindow(m_hForegroundWnd);
		ModifyStyleEx(0, WS_EX_NOACTIVATE);

		if (isStart)
		{
			//��Ŀ�� Ű����� ���� ��/�� ������ �ѱ۷� �����ϱ�!
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
























































































// ���� - ��
void CEye_Computing_DialogDlg::OnBnClickedIii()
{
	if (clickedZzum)
	{
		INPUT InputEo;
		::ZeroMemory(&InputEo, sizeof(INPUT));
		InputEo.type = INPUT_KEYBOARD;

		//�� ��
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

		//�� ��
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

		//�ѹ� ����
		InputAe.ki.wVk = 0x08;
		::SendInput(1, &InputAe, sizeof(INPUT));
		InputAe.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputAe, sizeof(INPUT));

		//�� ��
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

		//�ѹ� ����
		InputYae.ki.wVk = 0x08;
		::SendInput(1, &InputYae, sizeof(INPUT));
		InputYae.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputYae, sizeof(INPUT));

		//�� ��
		//����Ʈ �������ְ�
		InputYae.ki.wVk = 0x10;
		InputYae.ki.dwFlags = 0;
		::SendInput(1, &InputYae, sizeof(INPUT));
		//�� ħ
		InputYae.ki.wVk = 0x4F;
		::SendInput(1, &InputYae, sizeof(INPUT));
		InputYae.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputYae, sizeof(INPUT));
		// ����Ʈ ��
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

		//�ѹ� ����
		InputEee.ki.wVk = 0x08;
		::SendInput(1, &InputEee, sizeof(INPUT));
		InputEee.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputEee, sizeof(INPUT));

		//�� ��
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

		//�ѹ� ����
		InputYe.ki.wVk = 0x08;
		::SendInput(1, &InputYe, sizeof(INPUT));
		InputYe.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputYe, sizeof(INPUT));

		//�� ��
		//����Ʈ �������ְ�
		InputYe.ki.wVk = 0x10;
		InputYe.ki.dwFlags = 0;
		::SendInput(1, &InputYe, sizeof(INPUT));
		//�� ħ
		InputYe.ki.wVk = 0x50;
		::SendInput(1, &InputYe, sizeof(INPUT));
		InputYe.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputYe, sizeof(INPUT));
		// ����Ʈ ��
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

		//�ѹ� ����
		InputWae.ki.wVk = 0x08;
		::SendInput(1, &InputWae, sizeof(INPUT));
		InputWae.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputWae, sizeof(INPUT));

		//�� ��
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

		//�ѹ� ����
		InputWo.ki.wVk = 0x08;
		::SendInput(1, &InputWo, sizeof(INPUT));
		InputWo.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputWo, sizeof(INPUT));

		//�� ��
		//��
		InputWo.ki.wVk = 0x4E;
		InputWo.ki.dwFlags = 0;
		::SendInput(1, &InputWo, sizeof(INPUT));
		InputWo.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputWo, sizeof(INPUT));
		//��
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

		//�ѹ� ����
		InputWe.ki.wVk = 0x08;
		::SendInput(1, &InputWe, sizeof(INPUT));
		InputWe.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputWe, sizeof(INPUT));

		//�� ��
		InputWe.ki.wVk = 0x50;
		InputWe.ki.dwFlags = 0;
		::SendInput(1, &InputWe, sizeof(INPUT));
		InputWe.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputWe, sizeof(INPUT));
		clickedWo = false;
	}
	else if (clickedOoo)
	{
		//�� �Է�
		INPUT InputWe;
		//initialize
		::ZeroMemory(&InputWe, sizeof(INPUT));
		//keyboard�� �Է��ϰڴ�.
		InputWe.type = INPUT_KEYBOARD;
		//���ư��������
		InputWe.ki.wVk = 0x4C;
		//�ѹ������ֱ�
		::SendInput(1, &InputWe, sizeof(INPUT));
		//������ Ǯ���ֱ�
		InputWe.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputWe, sizeof(INPUT));
		// �� �����ְ�, �� Ǯ���ֱ�
		clickedWe = true;
		clickedOoo = false;
	}
	else
	{
		INPUT InputYee;
		//initialize
		::ZeroMemory(&InputYee, sizeof(INPUT));
		//keyboard�� �Է��ϰڴ�.
		InputYee.type = INPUT_KEYBOARD;
		//���ư��������
		InputYee.ki.wVk = 0x4C;
		//�ѹ������ֱ�
		::SendInput(1, &InputYee, sizeof(INPUT));
		//������ Ǯ���ֱ�
		InputYee.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputYee, sizeof(INPUT));
		// �� �������·� ������ֱ�
		clickedIii = true;
	}
}

// ���� - ��
void CEye_Computing_DialogDlg::OnBnClickedZzum()
{
	if (clickedIii)
	{
		INPUT InputAh;
		::ZeroMemory(&InputAh, sizeof(INPUT));
		InputAh.type = INPUT_KEYBOARD;

		//�ѹ� ����
		InputAh.ki.wVk = 0x08;
		::SendInput(1, &InputAh, sizeof(INPUT));
		InputAh.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputAh, sizeof(INPUT));

		//�� ��
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

		//�ѹ� ����
		InputYa.ki.wVk = 0x08;
		::SendInput(1, &InputYa, sizeof(INPUT));
		InputYa.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputYa, sizeof(INPUT));

		//�� ��
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

		//�ѹ� ����
		InputUuu.ki.wVk = 0x08;
		::SendInput(1, &InputUuu, sizeof(INPUT));
		InputUuu.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputUuu, sizeof(INPUT));

		//�� ��
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

		//�ѹ� ����
		InputYu.ki.wVk = 0x08;
		::SendInput(1, &InputYu, sizeof(INPUT));
		InputYu.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputYu, sizeof(INPUT));

		//�� ��
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

		//�ѹ� ����
		InputWa.ki.wVk = 0x08;
		::SendInput(1, &InputWa, sizeof(INPUT));
		InputWa.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputWa, sizeof(INPUT));

		//�� ��
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

// ���� - ��
void CEye_Computing_DialogDlg::OnBnClickedEu()
{
	if (clickedZzum)
	{
		INPUT InputOoo;
		::ZeroMemory(&InputOoo, sizeof(INPUT));
		InputOoo.type = INPUT_KEYBOARD;

		//�� ��
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

		//�� ��
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
		//keyboard�� �Է��ϰڴ�.
		InputEu.type = INPUT_KEYBOARD;
		//���ư��������
		InputEu.ki.wVk = 0x4D;
		//�ѹ������ֱ�
		::SendInput(1, &InputEu, sizeof(INPUT));
		//������ Ǯ���ֱ�
		InputEu.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputEu, sizeof(INPUT));
		//�� �������·� �������
		clickedEu = true;
	}
}

// ���� ���� �ʱ�ȭ
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

// ���� - ��
void CEye_Computing_DialogDlg::OnBnClickedGiyeok()
{
	initHanguel();
	/*https://msdn.microsoft.com/en-us/library/windows/desktop/ms646270(v=vs.85).aspx */
	INPUT InputGiYeok;
	//initialize
	::ZeroMemory(&InputGiYeok, sizeof(INPUT));
	//keyboard�� �Է��ϰڴ�.
	InputGiYeok.type = INPUT_KEYBOARD;
	//���ư��������
	InputGiYeok.ki.wVk = 0x52;
	//�ѹ������ֱ�
	::SendInput(1, &InputGiYeok, sizeof(INPUT));
	//������ Ǯ���ֱ�
	InputGiYeok.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &InputGiYeok, sizeof(INPUT));
}
// ���� - ��
void CEye_Computing_DialogDlg::OnBnClickedNieun()
{
	initHanguel();
	INPUT InputNieun;
	//initialize
	::ZeroMemory(&InputNieun, sizeof(INPUT));
	//keyboard�� �Է��ϰڴ�.
	InputNieun.type = INPUT_KEYBOARD;
	//���ư��������
	InputNieun.ki.wVk = 0x53;
	//�ѹ������ֱ�
	::SendInput(1, &InputNieun, sizeof(INPUT));
	//������ Ǯ���ֱ�
	InputNieun.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &InputNieun, sizeof(INPUT));
}
// ���� - ��
void CEye_Computing_DialogDlg::OnBnClickedDigeut()
{
	initHanguel();
	INPUT InputDigeut;
	//initialize
	::ZeroMemory(&InputDigeut, sizeof(INPUT));
	//keyboard�� �Է��ϰڴ�.
	InputDigeut.type = INPUT_KEYBOARD;
	//���ư��������
	InputDigeut.ki.wVk = 0x45;
	//�ѹ������ֱ�
	::SendInput(1, &InputDigeut, sizeof(INPUT));
	//������ Ǯ���ֱ�
	InputDigeut.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &InputDigeut, sizeof(INPUT));
}
//���� - ��
void CEye_Computing_DialogDlg::OnBnClickedRieul()
{
	initHanguel();
	INPUT InputRieul;
	//initialize
	::ZeroMemory(&InputRieul, sizeof(INPUT));
	//keyboard�� �Է��ϰڴ�.
	InputRieul.type = INPUT_KEYBOARD;
	//���ư��������
	InputRieul.ki.wVk = 0x46;
	//�ѹ������ֱ�
	::SendInput(1, &InputRieul, sizeof(INPUT));
	//������ Ǯ���ֱ�
	InputRieul.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &InputRieul, sizeof(INPUT));
}
//���� - ��
void CEye_Computing_DialogDlg::OnBnClickedMieum()
{
	initHanguel();
	INPUT InputMiEum;
	//initialize
	::ZeroMemory(&InputMiEum, sizeof(INPUT));
	//keyboard�� �Է��ϰڴ�.
	InputMiEum.type = INPUT_KEYBOARD;
	//���ư��������
	InputMiEum.ki.wVk = 0x41;
	//�ѹ������ֱ�
	::SendInput(1, &InputMiEum, sizeof(INPUT));
	//������ Ǯ���ֱ�
	InputMiEum.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &InputMiEum, sizeof(INPUT));
}
// ���� - ��
void CEye_Computing_DialogDlg::OnBnClickedBieup()
{
	initHanguel();
	INPUT InputBiEup;
	//initialize
	::ZeroMemory(&InputBiEup, sizeof(INPUT));
	//keyboard�� �Է��ϰڴ�.
	InputBiEup.type = INPUT_KEYBOARD;
	//���ư��������
	InputBiEup.ki.wVk = 0x51;
	//�ѹ������ֱ�
	::SendInput(1, &InputBiEup, sizeof(INPUT));
	//������ Ǯ���ֱ�
	InputBiEup.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &InputBiEup, sizeof(INPUT));
}
// ���� - ��
void CEye_Computing_DialogDlg::OnBnClickedShiot()
{
	initHanguel();
	INPUT InputShiOt;
	//initialize
	::ZeroMemory(&InputShiOt, sizeof(INPUT));
	//keyboard�� �Է��ϰڴ�.
	InputShiOt.type = INPUT_KEYBOARD;
	//���ư��������
	InputShiOt.ki.wVk = 0x54;
	//�ѹ������ֱ�
	::SendInput(1, &InputShiOt, sizeof(INPUT));
	//������ Ǯ���ֱ�
	InputShiOt.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &InputShiOt, sizeof(INPUT));
}
// ���� - ��
void CEye_Computing_DialogDlg::OnBnClickedIeung()
{
	initHanguel();
	INPUT InputIeung;
	//initialize
	::ZeroMemory(&InputIeung, sizeof(INPUT));
	//keyboard�� �Է��ϰڴ�.
	InputIeung.type = INPUT_KEYBOARD;
	//���ư��������
	InputIeung.ki.wVk = 0x44;
	//�ѹ������ֱ�
	::SendInput(1, &InputIeung, sizeof(INPUT));
	//������ Ǯ���ֱ�
	InputIeung.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &InputIeung, sizeof(INPUT));
}
// ���� - ��
void CEye_Computing_DialogDlg::OnBnClickedJieut()
{
	initHanguel();
	INPUT InputJiEut;
	//initialize
	::ZeroMemory(&InputJiEut, sizeof(INPUT));
	//keyboard�� �Է��ϰڴ�.
	InputJiEut.type = INPUT_KEYBOARD;
	//���ư��������
	InputJiEut.ki.wVk = 0x57;
	//�ѹ������ֱ�
	::SendInput(1, &InputJiEut, sizeof(INPUT));
	//������ Ǯ���ֱ�
	InputJiEut.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &InputJiEut, sizeof(INPUT));
}
//���� - ��
void CEye_Computing_DialogDlg::OnBnClickedChieut()
{
	initHanguel();
	INPUT InputChiEut;
	//initialize
	::ZeroMemory(&InputChiEut, sizeof(INPUT));
	//keyboard�� �Է��ϰڴ�.
	InputChiEut.type = INPUT_KEYBOARD;
	//���ư��������
	InputChiEut.ki.wVk = 0x43;
	//�ѹ������ֱ�
	::SendInput(1, &InputChiEut, sizeof(INPUT));
	//������ Ǯ���ֱ�
	InputChiEut.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &InputChiEut, sizeof(INPUT));
}
// ���� - ��
void CEye_Computing_DialogDlg::OnBnClickedKieuk()
{
	initHanguel();
	INPUT InputKieuk;
	//initialize
	::ZeroMemory(&InputKieuk, sizeof(INPUT));
	//keyboard�� �Է��ϰڴ�.
	InputKieuk.type = INPUT_KEYBOARD;
	//���ư��������
	InputKieuk.ki.wVk = 0x5A;
	//�ѹ������ֱ�
	::SendInput(1, &InputKieuk, sizeof(INPUT));
	//������ Ǯ���ֱ�
	InputKieuk.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &InputKieuk, sizeof(INPUT));
}
// ���� - ��
void CEye_Computing_DialogDlg::OnBnClickedTieut()
{
	initHanguel();
	INPUT InputTieut;
	//initialize
	::ZeroMemory(&InputTieut, sizeof(INPUT));
	//keyboard�� �Է��ϰڴ�.
	InputTieut.type = INPUT_KEYBOARD;
	//���ư��������
	InputTieut.ki.wVk = 0x59;
	//�ѹ������ֱ�
	::SendInput(1, &InputTieut, sizeof(INPUT));
	//������ Ǯ���ֱ�
	InputTieut.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &InputTieut, sizeof(INPUT));
}
// ���� - ��
void CEye_Computing_DialogDlg::OnBnClickedPieup()
{
	initHanguel();
	INPUT InputPieup;
	//initialize
	::ZeroMemory(&InputPieup, sizeof(INPUT));
	//keyboard�� �Է��ϰڴ�.
	InputPieup.type = INPUT_KEYBOARD;
	//���ư��������
	InputPieup.ki.wVk = 0x56;
	//�ѹ������ֱ�
	::SendInput(1, &InputPieup, sizeof(INPUT));
	//������ Ǯ���ֱ�
	InputPieup.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &InputPieup, sizeof(INPUT));
}
// ���� - ��
void CEye_Computing_DialogDlg::OnBnClickedHieut()
{
	initHanguel();
	INPUT InputHieut;
	//initialize
	::ZeroMemory(&InputHieut, sizeof(INPUT));
	//keyboard�� �Է��ϰڴ�.
	InputHieut.type = INPUT_KEYBOARD;
	//���ư��������
	InputHieut.ki.wVk = 0x47;
	//�ѹ������ֱ�
	::SendInput(1, &InputHieut, sizeof(INPUT));
	//������ Ǯ���ֱ�
	InputHieut.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &InputHieut, sizeof(INPUT));
}
// �����̽���
void CEye_Computing_DialogDlg::OnBnClickedSpace()
{
	initHanguel();
	INPUT InputSpace;
	//initialize
	::ZeroMemory(&InputSpace, sizeof(INPUT));
	//keyboard�� �Է��ϰڴ�.
	InputSpace.type = INPUT_KEYBOARD;
	//���ư��������
	InputSpace.ki.wVk = 0x20;
	//�ѹ������ֱ�
	::SendInput(1, &InputSpace, sizeof(INPUT));
	//������ Ǯ���ֱ�
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
	//keyboard�� �Է��ϰڴ�.
	InputBackSpace.type = INPUT_KEYBOARD;
	//���ư��������
	InputBackSpace.ki.wVk = 0x08;
	//�ѹ������ֱ�
	::SendInput(1, &InputBackSpace, sizeof(INPUT));
	//������ Ǯ���ֱ�
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
	//keyboard�� �Է��ϰڴ�.
	InputEnter.type = INPUT_KEYBOARD;
	//���ư��������
	InputEnter.ki.wVk = 0x0D;
	//�ѹ������ֱ�
	::SendInput(1, &InputEnter, sizeof(INPUT));
	//������ Ǯ���ֱ�
	InputEnter.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &InputEnter, sizeof(INPUT));

}
