
// Eye_Computing_DialogDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "Eye_Computing_Dialog.h"
#include "Eye_Computing_DialogDlg.h"
#include "afxdialogex.h"
#include "xSkinButton.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//������ �� �ѱ۷� �ٲ��� ���� ���
bool isStart = true;



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
}

void CEye_Computing_DialogDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BKSPACE, m_btn_BkSpace);
	DDX_Control(pDX, IDC_BACK, m_btn_Back);
	DDX_Control(pDX, IDC_GiYeok, m_btn_GiYeok);
	DDX_Control(pDX, IDC_NiEun, m_btn_NiEun);
	DDX_Control(pDX, IDC_DiGeut, m_btn_DiGeut);
	DDX_Control(pDX, IDC_Confirm, m_btn_Confirm);
	DDX_Control(pDX, IDC_RIEUL, m_btn_RiEul);
	DDX_Control(pDX, IDC_MIEUM, m_btn_MiEum);
	DDX_Control(pDX, IDC_BIEUP, m_btn_BiEup);
	DDX_Control(pDX, IDC_Zzum, m_btn_Zzum);
	DDX_Control(pDX, IDC_YI, m_btn_Yi);
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
	ON_BN_CLICKED(IDC_Yee, &CEye_Computing_DialogDlg::OnBnClickedYee)
	ON_BN_CLICKED(IDC_Zzum, &CEye_Computing_DialogDlg::OnBnClickedZzum)
	ON_BN_CLICKED(IDC_Eu, &CEye_Computing_DialogDlg::OnBnClickedEu)
END_MESSAGE_MAP()


// CEye_Computing_DialogDlg �޽��� ó����

BOOL CEye_Computing_DialogDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();


	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.
	m_btn_BkSpace.SetSkin(IDB_BKSPACE, IDB_BKSPACE, IDB_BKSPACE, IDB_BKSPACE, 0, IDB_BKSPACE, 0, 0, 0);
	m_btn_Back.SetSkin(IDB_BACK, IDB_BACK, IDB_BACK, IDB_BACK, 0, IDB_BACK, 0, 0, 0);
	m_btn_GiYeok.SetSkin(IDB_GIYEOK, IDB_GIYEOK, IDB_GIYEOK, IDB_GIYEOK, 0, IDB_GIYEOK, 0, 0, 0);
	m_btn_NiEun.SetSkin(IDB_NIEUN, IDB_NIEUN, IDB_NIEUN, IDB_NIEUN, 0, IDB_NIEUN, 0, 0, 0);
	m_btn_DiGeut.SetSkin(IDB_DIGEUT, IDB_DIGEUT, IDB_DIGEUT, IDB_DIGEUT, 0, IDB_DIGEUT, 0, 0, 0);
	m_btn_Confirm.SetSkin(IDB_CONFIRM, IDB_CONFIRM, IDB_CONFIRM, IDB_CONFIRM, 0, IDB_CONFIRM, 0, 0, 0);
	m_btn_RiEul.SetSkin(IDB_RIEUL, IDB_RIEUL, IDB_RIEUL, IDB_RIEUL, 0, IDB_RIEUL, 0, 0, 0);
	m_btn_MiEum.SetSkin(IDB_MIEUM, IDB_MIEUM, IDB_MIEUM, IDB_MIEUM, 0, IDB_MIEUM, 0, 0, 0);
	m_btn_BiEup.SetSkin(IDB_BIEUP, IDB_BIEUP, IDB_BIEUP, IDB_BIEUP, 0, IDB_BIEUP, 0, 0, 0);
	m_btn_Zzum.SetSkin(IDB_ZZUM, IDB_ZZUM, IDB_ZZUM, IDB_ZZUM, 0, IDB_ZZUM, 0, 0, 0);
	m_btn_Yi.SetSkin(IDB_YI, IDB_YI, IDB_YI, IDB_YI, 0, IDB_YI, 0, 0, 0);
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
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CEye_Computing_DialogDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CEye_Computing_DialogDlg::OnBnClickedOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CDialogEx::OnOK();
}


void CEye_Computing_DialogDlg::OnBnClickedCancel()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CDialogEx::OnCancel();
}


void CEye_Computing_DialogDlg::OnBnClickedGiyeok()
{
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


void CEye_Computing_DialogDlg::OnBnClickedNieun()
{
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


void CEye_Computing_DialogDlg::OnBnClickedAh()
{
	INPUT InputAh;
	//initialize
	::ZeroMemory(&InputAh, sizeof(INPUT));
	//keyboard�� �Է��ϰڴ�.
	InputAh.type = INPUT_KEYBOARD;
	//���ư��������
	InputAh.ki.wVk = 0x4B;
	//�ѹ������ֱ�
	::SendInput(1, &InputAh, sizeof(INPUT));
	//������ Ǯ���ֱ�
	InputAh.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &InputAh, sizeof(INPUT));
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CEye_Computing_DialogDlg::OnBnClickedYee()
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CEye_Computing_DialogDlg::OnBnClickedZzum()
{

}


void CEye_Computing_DialogDlg::OnBnClickedEu()
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}
