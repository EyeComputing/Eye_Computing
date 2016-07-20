// Eye_Computing_DialogDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "Eye_Computing_Dialog.h"
#include "Eye_Computing_DialogDlg.h"
#include "afxdialogex.h"
#include "EyeXGaze.h"
#include "xSkinButton.h"
#include <imm.h>

#pragma comment( lib, "imm32.lib" )

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//spacebar click message hooking�� ���� �Լ� & ����
//Ű���� hooking�� �߻����� ��� ȣ��Ǵ� �Լ�

LRESULT CALLBACK GetMsgProc(int nCode, WPARAM wParam, LPARAM lParam);
HHOOK m_hook = NULL;


//���!
EyeXGaze g_EyeXGaze;	// �ν��Ͻ� �����ϸ鼭 ������ �����.

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


// �ѿ� Ű���� �ٲٱ�
bool clickedKorean = true;
bool clickedEnglish = false;
bool isKorean = false;
bool isEnglish = false;

//cursor ����

HCURSOR m_hCursor, m_hOldCursor;




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










//keyboard hooking �� ȣ��Ǵ� function 
LRESULT CALLBACK GetMsgProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	static int c = 0;
	KBDLLHOOKSTRUCT *pKey = (KBDLLHOOKSTRUCT *)lParam;
	POINT point;//���콺 ��ǥ�� �����ϴ� ����

	char ClassName[128];


	if (nCode < 0)
		return CallNextHookEx(m_hook, nCode, wParam, lParam);

	if (nCode == HC_ACTION)
	{
		if (GetKeyState(VK_CONTROL)& 0x80)
		{
			GetCursorPos(&point); //point ������ ���콺 ��ǥ �� ����
			
			//HWND hWnd = WindowFromPoint(point);  //�ش� ��ǥ�� �����ϴ� window handle ��������

			//GetClassName(hWnd, (LPWSTR)ClassName, 128);

			//if (*ClassName)
				//OutputDebugString((LPWSTR)ClassName);

			//���콺 ��ǥ�� �����ϴ� window�� Ȱ��ȭ ��Ű��
			//EnableWindow(hWnd, true);
		
			//	SendMessage(hWnd, WM_LBUTTONDOWN, false, 0);
			//SendMessage(hWnd, WM_LBUTTONUP, false, 0);

			// ���콺 ���� Ŭ�� ���(�߰�)
			::mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_ABSOLUTE, point.x, point.y, 0, ::GetMessageExtraInfo());
			::mouse_event(MOUSEEVENTF_LEFTUP | MOUSEEVENTF_ABSOLUTE, point.x, point.y, 0, ::GetMessageExtraInfo());

 			return 1;//return 1 : ������ message�� space Ŭ�� �޽����� �ش� application�� message queue�� ���޵��� ����
					 //return �� ���� ������ queue�� �����Ͽ� message ó����.
		}
		return 0;
	}
}



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
	DDX_Control(pDX, IDC_CPT_A, m_btn_cptA);
	DDX_Control(pDX, IDC_CPT_C, m_btn_cptC);
	DDX_Control(pDX, IDC_CPT_B, m_btn_cptB);
	DDX_Control(pDX, IDC_CPT_D, m_btn_cptD);
	DDX_Control(pDX, IDC_CPT_E, m_btn_cptE);
	DDX_Control(pDX, IDC_CPT_F, m_btn_cptF);
	DDX_Control(pDX, IDC_CPT_G, m_btn_cptG);
	DDX_Control(pDX, IDC_CPT_H, m_btn_cptH);
	DDX_Control(pDX, IDC_CPT_I, m_btn_cptI);
	DDX_Control(pDX, IDC_CPT_J, m_btn_cptJ);
	DDX_Control(pDX, IDC_CPT_K, m_btn_cptK);
	DDX_Control(pDX, IDC_CPT_M, m_btn_cptM);
	DDX_Control(pDX, IDC_CPT_L, m_btn_cptL);
	DDX_Control(pDX, IDC_CPT_N, m_btn_cptN);
	DDX_Control(pDX, IDC_CPT_P, m_btn_cptP);
	DDX_Control(pDX, IDC_CPT_O, m_btn_cptO);
	DDX_Control(pDX, IDC_CPT_R, m_btn_cptR);
	DDX_Control(pDX, IDC_CPT_Q, m_btn_cptQ);
	DDX_Control(pDX, IDC_CPT_S, m_btn_cptS);
	DDX_Control(pDX, IDC_CPT_T, m_btn_cptT);
	DDX_Control(pDX, IDC_CPT_U, m_btn_cptU);
	DDX_Control(pDX, IDC_CPT_V, m_btn_cptV);
	DDX_Control(pDX, IDC_CPT_W, m_btn_cptW);
	DDX_Control(pDX, IDC_CPT_X, m_btn_cptX);
	DDX_Control(pDX, IDC_CPT_Y, m_btn_cptY);
	DDX_Control(pDX, IDC_CPT_Z, m_btn_cptZ);
	DDX_Control(pDX, IDC_KOREAN, m_btn_Korean);
	DDX_Control(pDX, IDC_ENGLISH, m_btn_English);
	DDX_Control(pDX, IDC_NUMBER, m_btn_Number);
	DDX_Control(pDX, IDC_ACCENT, m_btn_Accent);
	DDX_Control(pDX, IDC_ONE, m_btn_One);
	DDX_Control(pDX, IDC_TWO, m_btn_Two);
	DDX_Control(pDX, IDC_THREE, m_btn_Three);
	DDX_Control(pDX, IDC_FOUR, m_btn_Four);
	DDX_Control(pDX, IDC_FIVE, m_btn_Five);
	DDX_Control(pDX, IDC_SIX, m_btn_Six);
	DDX_Control(pDX, IDC_SEVEN, m_btn_Seven);
	DDX_Control(pDX, IDC_EIGHT, m_btn_Eight);
	DDX_Control(pDX, IDC_NINE, m_btn_Nine);
	DDX_Control(pDX, IDC_ZERO, m_btn_Zero);
	DDX_Control(pDX, IDC_BKSLASH, m_btn_BkSlash);
	DDX_Control(pDX, IDC_COMMA, m_btn_Comma);
	DDX_Control(pDX, IDC_DOT, m_btn_Dot);
	DDX_Control(pDX, IDC_EQUAL, m_btn_Equal);
	DDX_Control(pDX, IDC_EXCLAIM, m_btn_Exclaim);
	DDX_Control(pDX, IDC_HYPHEN, m_btn_Hyphen);
	DDX_Control(pDX, IDC_QUESTION, m_btn_Question);
	DDX_Control(pDX, IDC_SEMICOLON, m_btn_Semicolon);
	DDX_Control(pDX, IDC_SGQUOT, m_btn_SgQuot);
	DDX_Control(pDX, IDC_SLASH, m_btn_Slash);
	DDX_Control(pDX, IDC_SQBRACKET_CLOSE, m_btn_SqBracketClosed);
	DDX_Control(pDX, IDC_SQBRACKET_OPEN, m_btn_SqBracketOpened);
	DDX_Control(pDX, IDC_CAPSLOCK, m_btn_Capslock);
	DDX_Control(pDX, IDC_AtMark, m_btn_AtMark);
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
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_KOREAN, &CEye_Computing_DialogDlg::OnBnClickedKorean)
	ON_BN_CLICKED(IDC_ENGLISH, &CEye_Computing_DialogDlg::OnBnClickedEnglish)
	ON_BN_CLICKED(IDC_CPT_A, &CEye_Computing_DialogDlg::OnBnClickedCptA)
	ON_BN_CLICKED(IDC_CPT_C, &CEye_Computing_DialogDlg::OnBnClickedCptC)
	ON_BN_CLICKED(IDC_CPT_B, &CEye_Computing_DialogDlg::OnBnClickedCptB)
	ON_BN_CLICKED(IDC_CPT_D, &CEye_Computing_DialogDlg::OnBnClickedCptD)
	ON_BN_CLICKED(IDC_CPT_E, &CEye_Computing_DialogDlg::OnBnClickedCptE)
	ON_BN_CLICKED(IDC_CPT_F, &CEye_Computing_DialogDlg::OnBnClickedCptF)
	ON_BN_CLICKED(IDC_CPT_G, &CEye_Computing_DialogDlg::OnBnClickedCptG)
	ON_BN_CLICKED(IDC_CPT_H, &CEye_Computing_DialogDlg::OnBnClickedCptH)
	ON_BN_CLICKED(IDC_CPT_I, &CEye_Computing_DialogDlg::OnBnClickedCptI)
	ON_BN_CLICKED(IDC_CPT_J, &CEye_Computing_DialogDlg::OnBnClickedCptJ)
	ON_BN_CLICKED(IDC_CPT_K, &CEye_Computing_DialogDlg::OnBnClickedCptK)
	ON_BN_CLICKED(IDC_CPT_L, &CEye_Computing_DialogDlg::OnBnClickedCptL)
	ON_BN_CLICKED(IDC_CPT_M, &CEye_Computing_DialogDlg::OnBnClickedCptM)
	ON_BN_CLICKED(IDC_CPT_N, &CEye_Computing_DialogDlg::OnBnClickedCptN)
	ON_BN_CLICKED(IDC_CPT_O, &CEye_Computing_DialogDlg::OnBnClickedCptO)
	ON_BN_CLICKED(IDC_CPT_P, &CEye_Computing_DialogDlg::OnBnClickedCptP)
	ON_BN_CLICKED(IDC_CPT_Q, &CEye_Computing_DialogDlg::OnBnClickedCptQ)
	ON_BN_CLICKED(IDC_CPT_R, &CEye_Computing_DialogDlg::OnBnClickedCptR)
	ON_BN_CLICKED(IDC_CPT_S, &CEye_Computing_DialogDlg::OnBnClickedCptS)
	ON_BN_CLICKED(IDC_CPT_T, &CEye_Computing_DialogDlg::OnBnClickedCptT)
	ON_BN_CLICKED(IDC_CPT_U, &CEye_Computing_DialogDlg::OnBnClickedCptU)
	ON_BN_CLICKED(IDC_CPT_V, &CEye_Computing_DialogDlg::OnBnClickedCptV)
	ON_BN_CLICKED(IDC_CPT_W, &CEye_Computing_DialogDlg::OnBnClickedCptW)
	ON_BN_CLICKED(IDC_CPT_X, &CEye_Computing_DialogDlg::OnBnClickedCptX)
	ON_BN_CLICKED(IDC_CPT_Y, &CEye_Computing_DialogDlg::OnBnClickedCptY)
	ON_BN_CLICKED(IDC_CPT_Z, &CEye_Computing_DialogDlg::OnBnClickedCptZ)

	ON_BN_CLICKED(IDC_KOREAN, &CEye_Computing_DialogDlg::OnBnClickedKorean)
	ON_BN_CLICKED(IDC_ENGLISH, &CEye_Computing_DialogDlg::OnBnClickedEnglish)
	ON_BN_CLICKED(IDC_NUMBER, &CEye_Computing_DialogDlg::OnBnClickedNumber)
END_MESSAGE_MAP()



// CEye_Computing_DialogDlg �޽��� ó����

BOOL CEye_Computing_DialogDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ������ ������ ���� �� ����
	initWindowSize();
	m_hook = SetWindowsHookEx(WH_KEYBOARD_LL, GetMsgProc, NULL, 0);

	if (!m_hook)
		TRACE("HOOKING ERROR");

	// ������ ������ ���� �� ����(�ٽ� �׸��� �ʴ´�)
	SetWindowPos(NULL, 0, 0, 625, 650, SWP_NOREDRAW);
	GetDlgItem(IDC_BACKGROUND)->SetWindowPos(NULL, 0, 0, 150, 150, SWP_NOSIZE);

	// ������ ������ ���� �� ����
	initWindowSize();
	// �ý��� ��ư �̹��� ����
	setImgSysBtn();
	// �ý��� ��ư ��ǥ ����
	setPosSysBtn();
	// �ѱ� ��ư �̹��� ����
	setImgKorBtn();
	// �ѱ� ��ư ��ǥ ����
	setPosKorBtn();
	// ���� ��ư �̹��� ����
	setImgEngBtn();
	// ���� ��ư ��ǥ ����
	setPosEngBtn();
	// ���� ��ư �̹��� ����
	setImgNumBtn();
	// ���� ��ư ��ǥ ����
	setPosNumBtn();
	// ����, ���� ��ư �����
	hideEngBtn();
	hideNumBtn();

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
	

	
	//cursor variable initialize
	m_hCursor = NULL;
	m_hOldCursor = NULL;

	m_hOldCursor = LoadCursor(NULL, IDC_ARROW);
	m_hOldCursor = CopyCursor(m_hOldCursor);

	m_hCursor = (HCURSOR)LoadImage(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDC_CURSOR1), IMAGE_CURSOR, 256, 256, LR_DEFAULTCOLOR);
	m_hCursor = CopyCursor(m_hCursor);


	::SetSystemCursor(m_hCursor, 32512);

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

		m_hForegroundWnd = NULL;

	}

	CDialog::OnMouseMove(nFlags, point);
}


void CEye_Computing_DialogDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	::SetSystemCursor(m_hOldCursor, 32512);
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


//�ѿ� ��ư ������
void CEye_Computing_DialogDlg::CheckKorEng()
{

	if (clickedKorean)
	{
		if (isKorean == false)
		{
			INPUT InputHE;
			::ZeroMemory(&InputHE, sizeof(INPUT));
			InputHE.type = INPUT_KEYBOARD;

			InputHE.ki.wVk = 0x15;
			::SendInput(1, &InputHE, sizeof(INPUT));
			InputHE.ki.dwFlags = KEYEVENTF_KEYUP;
			::SendInput(1, &InputHE, sizeof(INPUT));

			isKorean = true;
			isEnglish = false;
			clickedEnglish = false;
		}
	}
	else if (clickedEnglish)
	{
		if (isEnglish == false)
		{
			INPUT InputHE;
			::ZeroMemory(&InputHE, sizeof(INPUT));
			InputHE.type = INPUT_KEYBOARD;

			InputHE.ki.wVk = 0x15;
			::SendInput(1, &InputHE, sizeof(INPUT));
			InputHE.ki.dwFlags = KEYEVENTF_KEYUP;
			::SendInput(1, &InputHE, sizeof(INPUT));

			isKorean = false;
			isEnglish = true;
			clickedKorean = false;
		}
	}
	/*
	INPUT InputHE;
	::ZeroMemory(&InputHE, sizeof(INPUT));
	InputHE.type = INPUT_KEYBOARD;

	InputHE.ki.wVk = 0x15;
	::SendInput(1, &InputHE, sizeof(INPUT));
	InputHE.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &InputHE, sizeof(INPUT));
	*/

	/*
	DWORD conVersion, senTence;
	//DWORD Temp;
	//HIMC hIMC = ImmGetContext(::GetActiveWindow());
	HIMC hIMC = ImmGetContext(GetSafeHwnd());

	ImmNotifyIME(hIMC, NI_COMPOSITIONSTR, CPS_CANCEL, 0);
	ImmGetConversionStatus(hIMC, &conVersion, &senTence);
	//Temp = conVersion & ~IME_CMODE_LANGUAGE;

	INPUT InputHE;
	::ZeroMemory(&InputHE, sizeof(INPUT));
	InputHE.type = INPUT_KEYBOARD;

	if (conVersion == 0)
	{
		if (clickedKorean)
		{
			//conVersion = 1;
			//::ImmSetConversionStatus(hIMC, conVersion, senTence);

			InputHE.ki.wVk = 0x15;
			::SendInput(1, &InputHE, sizeof(INPUT));
			InputHE.ki.dwFlags = KEYEVENTF_KEYUP;
			::SendInput(1, &InputHE, sizeof(INPUT));
		}
	}
	else
	{
		if (clickedEnglish)
		{
			//conVersion = 0;
			//::ImmSetConversionStatus(hIMC, conVersion, senTence);
			InputHE.ki.wVk = 0x15;
			::SendInput(1, &InputHE, sizeof(INPUT));
			InputHE.ki.dwFlags = KEYEVENTF_KEYUP;
			::SendInput(1, &InputHE, sizeof(INPUT));
		}
	}*/
}


/*
void CEye_Computing_DialogDlg::Input_Key()
{

}
*/












































// ������ ������ ���� �� ����(�ٽ� �׸��� �ʴ´�)
void CEye_Computing_DialogDlg::initWindowSize()
{
	SetWindowPos(NULL, 0, 0, 625, 650, SWP_NOREDRAW);
	GetDlgItem(IDC_BACKGROUND)->SetWindowPos(NULL, 0, 0, 150, 150, SWP_NOSIZE);
}

// �ý��� ��ư �̹��� ����
void CEye_Computing_DialogDlg::setImgSysBtn()
{
	m_btn_BkSpace.SetSkin(IDB_BKSPACE, IDB_BKSPACE, IDB_BKSPACE_OVER, IDB_BKSPACE, 0, IDB_BKSPACE, 0, 0, 0);
	m_btn_Back.SetSkin(IDB_Enter, IDB_Enter, IDB_ENTER_OVER, IDB_Enter, 0, IDB_Enter, 0, 0, 0);
	m_btn_Space.SetSkin(IDB_SPACE, IDB_SPACE, IDB_SPACE_OVER, IDB_SPACE, 0, IDB_SPACE, 0, 0, 0);
	m_btn_Confirm.SetSkin(IDB_CONFIRM, IDB_CONFIRM, IDB_CONFIRM_OVER, IDB_CONFIRM, 0, IDB_CONFIRM, 0, 0, 0);
	m_btn_Korean.SetSkin(IDB_KOREAN, IDB_KOREAN, IDB_KOREAN_OVER, IDB_KOREAN, 0, IDB_KOREAN, 0, 0, 0);
	m_btn_English.SetSkin(IDB_ENGLISH, IDB_ENGLISH, IDB_ENGLISH_OVER, IDB_ENGLISH, 0, IDB_ENGLISH, 0, 0, 0);
	m_btn_Number.SetSkin(IDB_NUMBER, IDB_NUMBER, IDB_NUMBER_OVER, IDB_NUMBER, 0, IDB_NUMBER, 0, 0, 0);
	m_btn_Capslock.SetSkin(IDB_CAPSLOCK, IDB_CAPSLOCK, IDB_CAPSLOCK_OVER, IDB_CAPSLOCK, 0, IDB_CAPSLOCK, 0, 0, 0);
}

// �ý��� ��ư ��ǥ ����
void CEye_Computing_DialogDlg::setPosSysBtn()
{
	GetDlgItem(IDC_BKSPACE)->SetWindowPos(NULL, 186, 12, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_Enter)->SetWindowPos(NULL, 106, 46, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_SPACE)->SetWindowPos(NULL, 228, 287, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_Confirm)->SetWindowPos(NULL, 185, 92, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_KOREAN)->SetWindowPos(NULL, 394, 495, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_ENGLISH)->SetWindowPos(NULL, 447, 453, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_NUMBER)->SetWindowPos(NULL, 490, 399, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_CAPSLOCK)->SetWindowPos(NULL, 303, 106, 150, 150, SWP_NOSIZE);
}

// �ѱ� ��ư �̹��� ����
void CEye_Computing_DialogDlg::setImgKorBtn()
{
	m_btn_GiYeok.SetSkin(IDB_GIYEOK, IDB_GIYEOK, IDB_GIYEOK_OVER, IDB_GIYEOK, 0, IDB_GIYEOK, 0, 0, 0);
	m_btn_NiEun.SetSkin(IDB_NIEUN, IDB_NIEUN, IDB_NIEUN_OVER, IDB_NIEUN, 0, IDB_NIEUN, 0, 0, 0);
	m_btn_DiGeut.SetSkin(IDB_DIGEUT, IDB_DIGEUT, IDB_DIGEUT_OVER, IDB_DIGEUT, 0, IDB_DIGEUT, 0, 0, 0);
	m_btn_RiEul.SetSkin(IDB_RIEUL, IDB_RIEUL, IDB_RIEUL_OVER, IDB_RIEUL, 0, IDB_RIEUL, 0, 0, 0);
	m_btn_MiEum.SetSkin(IDB_MIEUM, IDB_MIEUM, IDB_MIEUM_OVER, IDB_MIEUM, 0, IDB_MIEUM, 0, 0, 0);
	m_btn_BiEup.SetSkin(IDB_BIEUP, IDB_BIEUP, IDB_BIEUP_OVER, IDB_BIEUP, 0, IDB_BIEUP, 0, 0, 0);
	m_btn_Zzum.SetSkin(IDB_ZZUM, IDB_ZZUM, IDB_ZZUM_OVER, IDB_ZZUM, 0, IDB_ZZUM, 0, 0, 0);
	m_btn_Yi.SetSkin(IDB_Iii, IDB_Iii, IDB_YI_OVER, IDB_Iii, 0, IDB_Iii, 0, 0, 0);
	m_btn_ShiOt.SetSkin(IDB_SHIOT, IDB_SHIOT, IDB_SHIOT_OVER, IDB_SHIOT, 0, IDB_SHIOT, 0, 0, 0);
	m_btn_Eu.SetSkin(IDB_EU, IDB_EU, IDB_EU_OVER, IDB_EU, 0, IDB_EU, 0, 0, 0);
	m_btn_IEung.SetSkin(IDB_IEUNG, IDB_IEUNG, IDB_IEUNG_OVER, IDB_IEUNG, 0, IDB_IEUNG, 0, 0, 0);
	m_btn_KiEuk.SetSkin(IDB_KIEUK, IDB_KIEUK, IDB_KIEUK_OVER, IDB_KIEUK, 0, IDB_KIEUK, 0, 0, 0);
	m_btn_ChiEut.SetSkin(IDB_CHIEUT, IDB_CHIEUT, IDB_CHIEUT_OVER, IDB_CHIEUT, 0, IDB_CHIEUT, 0, 0, 0);
	m_btn_JiEut.SetSkin(IDB_JIEUT, IDB_JIEUT, IDB_JIEUT_OVER, IDB_JIEUT, 0, IDB_JIEUT, 0, 0, 0);
	m_btn_TiEut.SetSkin(IDB_TIEUT, IDB_TIEUT, IDB_TIEUT_OVER, IDB_TIEUT, 0, IDB_TIEUT, 0, 0, 0);
	m_btn_PiEup.SetSkin(IDB_PIEUP, IDB_PIEUP, IDB_PIEUP_OVER, IDB_PIEUP, 0, IDB_PIEUP, 0, 0, 0);
	m_btn_HiEut.SetSkin(IDB_HIEUT, IDB_HIEUT, IDB_HIEUT_OVER, IDB_HIEUT, 0, IDB_HIEUT, 0, 0, 0);
}

// �ѱ� ��ư ��ǥ ����
void CEye_Computing_DialogDlg::setPosKorBtn()
{
	GetDlgItem(IDC_GiYeok)->SetWindowPos(NULL, 43, 105, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_NiEun)->SetWindowPos(NULL, 14, 185, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_DiGeut)->SetWindowPos(NULL, 16, 278, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_RIEUL)->SetWindowPos(NULL, 117, 136, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_MIEUM)->SetWindowPos(NULL, 88, 217, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_BIEUP)->SetWindowPos(NULL, 103, 307, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_Zzum)->SetWindowPos(NULL, 227, 175, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_Iii)->SetWindowPos(NULL, 168, 235, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_SHIOT)->SetWindowPos(NULL, 159, 363, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_Eu)->SetWindowPos(NULL, 281, 232, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_IEUNG)->SetWindowPos(NULL, 244, 376, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_KIEUK)->SetWindowPos(NULL, 369, 188, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_CHIEUT)->SetWindowPos(NULL, 368, 280, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_JIEUT)->SetWindowPos(NULL, 326, 346, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_TIEUT)->SetWindowPos(NULL, 445, 191, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_PIEUP)->SetWindowPos(NULL, 443, 279, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_HIEUT)->SetWindowPos(NULL, 412, 357, 150, 150, SWP_NOSIZE);
}

// ���� ��ư �̹��� ����
void CEye_Computing_DialogDlg::setImgEngBtn()
{
	m_btn_cptA.SetSkin(IDB_CPT_A, IDB_CPT_A, IDB_CPT_A_OVER, IDB_CPT_A, 0, IDB_CPT_A, 0, 0, 0);
	m_btn_cptC.SetSkin(IDB_CPT_C, IDB_CPT_C, IDB_CPT_C_OVER, IDB_CPT_C, 0, IDB_CPT_C, 0, 0, 0);
	m_btn_cptB.SetSkin(IDB_CPT_B, IDB_CPT_B, IDB_CPT_B_OVER, IDB_CPT_B, 0, IDB_CPT_B, 0, 0, 0);
	m_btn_cptD.SetSkin(IDB_CPT_D, IDB_CPT_D, IDB_CPT_D_OVER, IDB_CPT_D, 0, IDB_CPT_D, 0, 0, 0);
	m_btn_cptE.SetSkin(IDB_CPT_E, IDB_CPT_E, IDB_CPT_E_OVER, IDB_CPT_E, 0, IDB_CPT_E, 0, 0, 0);
	m_btn_cptF.SetSkin(IDB_CPT_F, IDB_CPT_F, IDB_CPT_F_OVER, IDB_CPT_F, 0, IDB_CPT_F, 0, 0, 0);
	m_btn_cptG.SetSkin(IDB_CPT_G, IDB_CPT_G, IDB_CPT_G_OVER, IDB_CPT_G, 0, IDB_CPT_G, 0, 0, 0);
	m_btn_cptH.SetSkin(IDB_CPT_H, IDB_CPT_H, IDB_CPT_H_OVER, IDB_CPT_H, 0, IDB_CPT_H, 0, 0, 0);
	m_btn_cptI.SetSkin(IDB_CPT_I, IDB_CPT_I, IDB_CPT_I_OVER, IDB_CPT_I, 0, IDB_CPT_I, 0, 0, 0);
	m_btn_cptJ.SetSkin(IDB_CPT_J, IDB_CPT_J, IDB_CPT_J_OVER, IDB_CPT_J, 0, IDB_CPT_J, 0, 0, 0);
	m_btn_cptK.SetSkin(IDB_CPT_K, IDB_CPT_K, IDB_CPT_K_OVER, IDB_CPT_K, 0, IDB_CPT_K, 0, 0, 0);
	m_btn_cptM.SetSkin(IDB_CPT_M, IDB_CPT_M, IDB_CPT_M_OVER, IDB_CPT_M, 0, IDB_CPT_M, 0, 0, 0);
	m_btn_cptL.SetSkin(IDB_CPT_L, IDB_CPT_L, IDB_CPT_L_OVER, IDB_CPT_L, 0, IDB_CPT_L, 0, 0, 0);
	m_btn_cptN.SetSkin(IDB_CPT_N, IDB_CPT_N, IDB_CPT_N_OVER, IDB_CPT_N, 0, IDB_CPT_N, 0, 0, 0);
	m_btn_cptP.SetSkin(IDB_CPT_P, IDB_CPT_P, IDB_CPT_P_OVER, IDB_CPT_P, 0, IDB_CPT_P, 0, 0, 0);
	m_btn_cptO.SetSkin(IDB_CPT_O, IDB_CPT_O, IDB_CPT_O_OVER, IDB_CPT_O, 0, IDB_CPT_O, 0, 0, 0);
	m_btn_cptR.SetSkin(IDB_CPT_R, IDB_CPT_R, IDB_CPT_R_OVER, IDB_CPT_R, 0, IDB_CPT_R, 0, 0, 0);
	m_btn_cptQ.SetSkin(IDB_CPT_Q, IDB_CPT_Q, IDB_CPT_Q_OVER, IDB_CPT_Q, 0, IDB_CPT_Q, 0, 0, 0);
	m_btn_cptS.SetSkin(IDB_CPT_S, IDB_CPT_S, IDB_CPT_S_OVER, IDB_CPT_S, 0, IDB_CPT_S, 0, 0, 0);
	m_btn_cptT.SetSkin(IDB_CPT_T, IDB_CPT_T, IDB_CPT_T_OVER, IDB_CPT_T, 0, IDB_CPT_T, 0, 0, 0);
	m_btn_cptU.SetSkin(IDB_CPT_U, IDB_CPT_U, IDB_CPT_U_OVER, IDB_CPT_U, 0, IDB_CPT_U, 0, 0, 0);
	m_btn_cptV.SetSkin(IDB_CPT_V, IDB_CPT_V, IDB_CPT_V_OVER, IDB_CPT_V, 0, IDB_CPT_V, 0, 0, 0);
	m_btn_cptW.SetSkin(IDB_CPT_W, IDB_CPT_W, IDB_CPT_W_OVER, IDB_CPT_W, 0, IDB_CPT_W, 0, 0, 0);
	m_btn_cptX.SetSkin(IDB_CPT_X, IDB_CPT_X, IDB_CPT_X_OVER, IDB_CPT_X, 0, IDB_CPT_X, 0, 0, 0);
	m_btn_cptY.SetSkin(IDB_CPT_Y, IDB_CPT_Y, IDB_CPT_Y_OVER, IDB_CPT_Y, 0, IDB_CPT_Y, 0, 0, 0);
	m_btn_cptZ.SetSkin(IDB_CPT_Z, IDB_CPT_Z, IDB_CPT_Z_OVER, IDB_CPT_Z, 0, IDB_CPT_Z, 0, 0, 0);
}													  

// ���� ��ư ��ǥ ����
void CEye_Computing_DialogDlg::setPosEngBtn()
{
	GetDlgItem(IDC_CPT_A)->SetWindowPos(NULL, 173, 255, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_CPT_C)->SetWindowPos(NULL, 171, 367, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_CPT_B)->SetWindowPos(NULL, 310, 357, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_CPT_D)->SetWindowPos(NULL, 241, 378, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_CPT_E)->SetWindowPos(NULL, 178, 196, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_CPT_F)->SetWindowPos(NULL, 89, 196, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_CPT_G)->SetWindowPos(NULL, 443, 279, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_CPT_H)->SetWindowPos(NULL, 373, 242, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_CPT_I)->SetWindowPos(NULL, 228, 172, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_CPT_J)->SetWindowPos(NULL, 14, 185, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_CPT_K)->SetWindowPos(NULL, 105, 416, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_CPT_L)->SetWindowPos(NULL, 87, 264, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_CPT_M)->SetWindowPos(NULL, 272, 449, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_CPT_N)->SetWindowPos(NULL, 185, 448, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_CPT_P)->SetWindowPos(NULL, 412, 357, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_CPT_O)->SetWindowPos(NULL, 281, 196, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_CPT_R)->SetWindowPos(NULL, 116, 326, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_CPT_Q)->SetWindowPos(NULL, 43, 105, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_CPT_S)->SetWindowPos(NULL, 361, 172, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_CPT_T)->SetWindowPos(NULL, 354, 310, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_CPT_U)->SetWindowPos(NULL, 289, 255, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_CPT_V)->SetWindowPos(NULL, 47, 356, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_CPT_W)->SetWindowPos(NULL, 121, 134, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_CPT_X)->SetWindowPos(NULL, 352, 417, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_CPT_Y)->SetWindowPos(NULL, 445, 191, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_CPT_Z)->SetWindowPos(NULL, 16, 278, 150, 150, SWP_NOSIZE);
}

// ����, Ư������ ��ư �̹��� ����
void CEye_Computing_DialogDlg::setImgNumBtn()
{
	m_btn_Accent.SetSkin(IDB_ACCENT, IDB_ACCENT, IDB_ACCENT_OVER, IDB_ACCENT, 0, IDB_ACCENT, 0, 0, 0);
	m_btn_One.SetSkin(IDB_ONE, IDB_ONE, IDB_ONE_OVER, IDB_ONE, 0, IDB_ONE, 0, 0, 0);
	m_btn_Two.SetSkin(IDB_TWO, IDB_TWO, IDB_TWO_OVER, IDB_TWO, 0, IDB_TWO, 0, 0, 0);
	m_btn_Three.SetSkin(IDB_THREE, IDB_THREE, IDB_THREE_OVER, IDB_THREE, 0, IDB_THREE, 0, 0, 0);
	m_btn_Four.SetSkin(IDB_FOUR, IDB_FOUR, IDB_FOUR_OVER, IDB_FOUR, 0, IDB_FOUR, 0, 0, 0);
	m_btn_Five.SetSkin(IDB_FIVE, IDB_FIVE, IDB_FIVE_OVER, IDB_FIVE, 0, IDB_FIVE, 0, 0, 0);
	m_btn_Six.SetSkin(IDB_SIX, IDB_SIX, IDB_SIX_OVER, IDB_SIX, 0, IDB_SIX, 0, 0, 0);
	m_btn_Seven.SetSkin(IDB_SEVEN, IDB_SEVEN, IDB_SEVEN_OVER, IDB_SEVEN, 0, IDB_SEVEN, 0, 0, 0);
	m_btn_Eight.SetSkin(IDB_EIGHT, IDB_EIGHT, IDB_EIGHT_OVER, IDB_EIGHT, 0, IDB_EIGHT, 0, 0, 0);
	m_btn_Nine.SetSkin(IDB_NINE, IDB_NINE, IDB_NINE_OVER, IDB_NINE, 0, IDB_NINE, 0, 0, 0);
	m_btn_Zero.SetSkin(IDB_ZERO, IDB_ZERO, IDB_ZERO_OVER, IDB_ZERO, 0, IDB_ZERO, 0, 0, 0);
	m_btn_BkSlash.SetSkin(IDB_BKSLASH, IDB_BKSLASH, IDB_BKSLASH_OVER, IDB_BKSLASH, 0, IDB_BKSLASH, 0, 0, 0);
	m_btn_Comma.SetSkin(IDB_COMMA, IDB_COMMA, IDB_COMMA_OVER, IDB_COMMA, 0, IDB_COMMA, 0, 0, 0);
	m_btn_Dot.SetSkin(IDB_DOT, IDB_DOT, IDB_DOT_OVER, IDB_DOT, 0, IDB_DOT, 0, 0, 0);
	m_btn_Equal.SetSkin(IDB_EQUAL, IDB_EQUAL, IDB_EQUAL_OVER, IDB_EQUAL, 0, IDB_EQUAL, 0, 0, 0);
	m_btn_Exclaim.SetSkin(IDB_EXCLAIM, IDB_EXCLAIM, IDB_EXCLAIM_OVER, IDB_EXCLAIM, 0, IDB_EXCLAIM, 0, 0, 0);
	m_btn_Hyphen.SetSkin(IDB_HYPHEN, IDB_HYPHEN, IDB_HYPHEN_OVER, IDB_HYPHEN, 0, IDB_HYPHEN, 0, 0, 0);
	m_btn_Question.SetSkin(IDB_QUESTION, IDB_QUESTION, IDB_QUESTION_OVER, IDB_QUESTION, 0, IDB_QUESTION, 0, 0, 0);
	m_btn_Semicolon.SetSkin(IDB_SEMICOLON, IDB_SEMICOLON, IDB_SEMICOLON_OVER, IDB_SEMICOLON, 0, IDB_SEMICOLON, 0, 0, 0);
	m_btn_SgQuot.SetSkin(IDB_SGQUOT, IDB_SGQUOT, IDB_SGQUOT_OVER, IDB_SGQUOT, 0, IDB_SGQUOT, 0, 0, 0);
	m_btn_Slash.SetSkin(IDB_SLASH, IDB_SLASH, IDB_SLASH_OVER, IDB_SLASH, 0, IDB_SLASH, 0, 0, 0);
	m_btn_SqBracketClosed.SetSkin(IDB_SQBRACKET_CLOSE, IDB_SQBRACKET_CLOSE, IDB_SQBRACKET_CLOSE_OVER, IDB_SQBRACKET_CLOSE, 0, IDB_SQBRACKET_CLOSE, 0, 0, 0);
	m_btn_SqBracketOpened.SetSkin(IDB_SQBRACKET_OPEN, IDB_SQBRACKET_OPEN, IDB_SQBRACKET_OPEN_OVER, IDB_SQBRACKET_OPEN, 0, IDB_SQBRACKET_OPEN, 0, 0, 0);
	m_btn_AtMark.SetSkin(IDB_ATMARK, IDB_ATMARK, IDB_ATMARK_OVER, IDB_ATMARK, 0, IDB_ATMARK, 0, 0, 0);
}

// ����, Ư������ ��ư ��ǥ ����
void CEye_Computing_DialogDlg::setPosNumBtn()
{

	GetDlgItem(IDC_ZERO)->SetWindowPos(NULL, 171, 367, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_EQUAL)->SetWindowPos(NULL, 310, 357, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_HYPHEN)->SetWindowPos(NULL, 241, 378, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_SEVEN)->SetWindowPos(NULL, 89, 196, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_SLASH)->SetWindowPos(NULL, 443, 279, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_SGQUOT)->SetWindowPos(NULL, 373, 242, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_ONE)->SetWindowPos(NULL, 14, 185, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_FOUR)->SetWindowPos(NULL, 105, 416, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_EIGHT)->SetWindowPos(NULL, 87, 264, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_SQBRACKET_OPEN)->SetWindowPos(NULL, 272, 449, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_FIVE)->SetWindowPos(NULL, 185, 448, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_BKSLASH)->SetWindowPos(NULL, 412, 357, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_NINE)->SetWindowPos(NULL, 116, 326, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_ACCENT)->SetWindowPos(NULL, 43, 105, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_COMMA)->SetWindowPos(NULL, 361, 172, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_SEMICOLON)->SetWindowPos(NULL, 354, 310, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_THREE)->SetWindowPos(NULL, 47, 356, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_SIX)->SetWindowPos(NULL, 121, 134, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_SQBRACKET_CLOSE)->SetWindowPos(NULL, 352, 417, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_DOT)->SetWindowPos(NULL, 445, 191, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_TWO)->SetWindowPos(NULL, 16, 278, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_EXCLAIM)->SetWindowPos(NULL, 168, 235, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_QUESTION)->SetWindowPos(NULL, 281, 232, 150, 150, SWP_NOSIZE);
	GetDlgItem(IDC_AtMark)->SetWindowPos(NULL, 227, 175, 150, 150, SWP_NOSIZE);
}


// �ѱ� ��ư ���̱�
void CEye_Computing_DialogDlg::showKorBtn()
{
	GetDlgItem(IDC_GiYeok)->ShowWindow(TRUE);
	GetDlgItem(IDC_NiEun)->ShowWindow(TRUE);
	GetDlgItem(IDC_DiGeut)->ShowWindow(TRUE);
	GetDlgItem(IDC_RIEUL)->ShowWindow(TRUE);
	GetDlgItem(IDC_MIEUM)->ShowWindow(TRUE);
	GetDlgItem(IDC_BIEUP)->ShowWindow(TRUE);
	GetDlgItem(IDC_Zzum)->ShowWindow(TRUE);
	GetDlgItem(IDC_Iii)->ShowWindow(TRUE);
	GetDlgItem(IDC_SHIOT)->ShowWindow(TRUE);
	GetDlgItem(IDC_Eu)->ShowWindow(TRUE);
	GetDlgItem(IDC_IEUNG)->ShowWindow(TRUE);
	GetDlgItem(IDC_KIEUK)->ShowWindow(TRUE);
	GetDlgItem(IDC_CHIEUT)->ShowWindow(TRUE);
	GetDlgItem(IDC_JIEUT)->ShowWindow(TRUE);
	GetDlgItem(IDC_TIEUT)->ShowWindow(TRUE);
	GetDlgItem(IDC_PIEUP)->ShowWindow(TRUE);
	GetDlgItem(IDC_HIEUT)->ShowWindow(TRUE);
}

// �ѱ� ��ư �����
void CEye_Computing_DialogDlg::hideKorBtn()
{
	GetDlgItem(IDC_GiYeok)->ShowWindow(FALSE);
	GetDlgItem(IDC_NiEun)->ShowWindow(FALSE);
	GetDlgItem(IDC_DiGeut)->ShowWindow(FALSE);
	GetDlgItem(IDC_RIEUL)->ShowWindow(FALSE);
	GetDlgItem(IDC_MIEUM)->ShowWindow(FALSE);
	GetDlgItem(IDC_BIEUP)->ShowWindow(FALSE);
	GetDlgItem(IDC_Zzum)->ShowWindow(FALSE);
	GetDlgItem(IDC_Iii)->ShowWindow(FALSE);
	GetDlgItem(IDC_SHIOT)->ShowWindow(FALSE);
	GetDlgItem(IDC_Eu)->ShowWindow(FALSE);
	GetDlgItem(IDC_IEUNG)->ShowWindow(FALSE);
	GetDlgItem(IDC_KIEUK)->ShowWindow(FALSE);
	GetDlgItem(IDC_CHIEUT)->ShowWindow(FALSE);
	GetDlgItem(IDC_JIEUT)->ShowWindow(FALSE);
	GetDlgItem(IDC_TIEUT)->ShowWindow(FALSE);
	GetDlgItem(IDC_PIEUP)->ShowWindow(FALSE);
	GetDlgItem(IDC_HIEUT)->ShowWindow(FALSE);
}

// ���� ��ư ���̱�
void CEye_Computing_DialogDlg::showEngBtn()
{
	GetDlgItem(IDC_CPT_A)->ShowWindow(TRUE);
	GetDlgItem(IDC_CPT_C)->ShowWindow(TRUE);
	GetDlgItem(IDC_CPT_B)->ShowWindow(TRUE);
	GetDlgItem(IDC_CPT_D)->ShowWindow(TRUE);
	GetDlgItem(IDC_CPT_E)->ShowWindow(TRUE);
	GetDlgItem(IDC_CPT_F)->ShowWindow(TRUE);
	GetDlgItem(IDC_CPT_G)->ShowWindow(TRUE);
	GetDlgItem(IDC_CPT_H)->ShowWindow(TRUE);
	GetDlgItem(IDC_CPT_I)->ShowWindow(TRUE);
	GetDlgItem(IDC_CPT_J)->ShowWindow(TRUE);
	GetDlgItem(IDC_CPT_K)->ShowWindow(TRUE);
	GetDlgItem(IDC_CPT_L)->ShowWindow(TRUE);
	GetDlgItem(IDC_CPT_M)->ShowWindow(TRUE);
	GetDlgItem(IDC_CPT_N)->ShowWindow(TRUE);
	GetDlgItem(IDC_CPT_P)->ShowWindow(TRUE);
	GetDlgItem(IDC_CPT_O)->ShowWindow(TRUE);
	GetDlgItem(IDC_CPT_R)->ShowWindow(TRUE);
	GetDlgItem(IDC_CPT_Q)->ShowWindow(TRUE);
	GetDlgItem(IDC_CPT_S)->ShowWindow(TRUE);
	GetDlgItem(IDC_CPT_T)->ShowWindow(TRUE);
	GetDlgItem(IDC_CPT_U)->ShowWindow(TRUE);
	GetDlgItem(IDC_CPT_V)->ShowWindow(TRUE);
	GetDlgItem(IDC_CPT_W)->ShowWindow(TRUE);
	GetDlgItem(IDC_CPT_X)->ShowWindow(TRUE);
	GetDlgItem(IDC_CPT_Y)->ShowWindow(TRUE);
	GetDlgItem(IDC_CPT_Z)->ShowWindow(TRUE);
}

// ���� ��ư �����
void CEye_Computing_DialogDlg::hideEngBtn()
{
	GetDlgItem(IDC_CPT_A)->ShowWindow(FALSE);
	GetDlgItem(IDC_CPT_C)->ShowWindow(FALSE);
	GetDlgItem(IDC_CPT_B)->ShowWindow(FALSE);
	GetDlgItem(IDC_CPT_D)->ShowWindow(FALSE);
	GetDlgItem(IDC_CPT_E)->ShowWindow(FALSE);
	GetDlgItem(IDC_CPT_F)->ShowWindow(FALSE);
	GetDlgItem(IDC_CPT_G)->ShowWindow(FALSE);
	GetDlgItem(IDC_CPT_H)->ShowWindow(FALSE);
	GetDlgItem(IDC_CPT_I)->ShowWindow(FALSE);
	GetDlgItem(IDC_CPT_J)->ShowWindow(FALSE);
	GetDlgItem(IDC_CPT_K)->ShowWindow(FALSE);
	GetDlgItem(IDC_CPT_L)->ShowWindow(FALSE);
	GetDlgItem(IDC_CPT_M)->ShowWindow(FALSE);
	GetDlgItem(IDC_CPT_N)->ShowWindow(FALSE);
	GetDlgItem(IDC_CPT_P)->ShowWindow(FALSE);
	GetDlgItem(IDC_CPT_O)->ShowWindow(FALSE);
	GetDlgItem(IDC_CPT_R)->ShowWindow(FALSE);
	GetDlgItem(IDC_CPT_Q)->ShowWindow(FALSE);
	GetDlgItem(IDC_CPT_S)->ShowWindow(FALSE);
	GetDlgItem(IDC_CPT_T)->ShowWindow(FALSE);
	GetDlgItem(IDC_CPT_U)->ShowWindow(FALSE);
	GetDlgItem(IDC_CPT_V)->ShowWindow(FALSE);
	GetDlgItem(IDC_CPT_W)->ShowWindow(FALSE);
	GetDlgItem(IDC_CPT_X)->ShowWindow(FALSE);
	GetDlgItem(IDC_CPT_Y)->ShowWindow(FALSE);
	GetDlgItem(IDC_CPT_Z)->ShowWindow(FALSE);
}

// ���� ��ư ���̱�
void CEye_Computing_DialogDlg::showNumBtn()
{
	GetDlgItem(IDC_ACCENT)->ShowWindow(TRUE);
	GetDlgItem(IDC_ONE)->ShowWindow(TRUE);
	GetDlgItem(IDC_TWO)->ShowWindow(TRUE);
	GetDlgItem(IDC_THREE)->ShowWindow(TRUE);
	GetDlgItem(IDC_FOUR)->ShowWindow(TRUE);
	GetDlgItem(IDC_FIVE)->ShowWindow(TRUE);
	GetDlgItem(IDC_SIX)->ShowWindow(TRUE);
	GetDlgItem(IDC_SEVEN)->ShowWindow(TRUE);
	GetDlgItem(IDC_EIGHT)->ShowWindow(TRUE);
	GetDlgItem(IDC_NINE)->ShowWindow(TRUE);
	GetDlgItem(IDC_ZERO)->ShowWindow(TRUE);
	GetDlgItem(IDC_BKSLASH)->ShowWindow(TRUE);
	GetDlgItem(IDC_COMMA)->ShowWindow(TRUE);
	GetDlgItem(IDC_DOT)->ShowWindow(TRUE);
	GetDlgItem(IDC_EQUAL)->ShowWindow(TRUE);
	GetDlgItem(IDC_EXCLAIM)->ShowWindow(TRUE);
	GetDlgItem(IDC_HYPHEN)->ShowWindow(TRUE);
	GetDlgItem(IDC_QUESTION)->ShowWindow(TRUE);
	GetDlgItem(IDC_SEMICOLON)->ShowWindow(TRUE);
	GetDlgItem(IDC_SGQUOT)->ShowWindow(TRUE);
	GetDlgItem(IDC_SLASH)->ShowWindow(TRUE);
	GetDlgItem(IDC_SQBRACKET_CLOSE)->ShowWindow(TRUE);
	GetDlgItem(IDC_SQBRACKET_OPEN)->ShowWindow(TRUE);
	GetDlgItem(IDC_AtMark)->ShowWindow(TRUE);
}

// ���� ��ư �����
void CEye_Computing_DialogDlg::hideNumBtn()
{
	GetDlgItem(IDC_ACCENT)->ShowWindow(FALSE);
	GetDlgItem(IDC_ONE)->ShowWindow(FALSE);
	GetDlgItem(IDC_TWO)->ShowWindow(FALSE);
	GetDlgItem(IDC_THREE)->ShowWindow(FALSE);
	GetDlgItem(IDC_FOUR)->ShowWindow(FALSE);
	GetDlgItem(IDC_FIVE)->ShowWindow(FALSE);
	GetDlgItem(IDC_SIX)->ShowWindow(FALSE);
	GetDlgItem(IDC_SEVEN)->ShowWindow(FALSE);
	GetDlgItem(IDC_EIGHT)->ShowWindow(FALSE);
	GetDlgItem(IDC_NINE)->ShowWindow(FALSE);
	GetDlgItem(IDC_ZERO)->ShowWindow(FALSE);
	GetDlgItem(IDC_BKSLASH)->ShowWindow(FALSE);
	GetDlgItem(IDC_COMMA)->ShowWindow(FALSE);
	GetDlgItem(IDC_DOT)->ShowWindow(FALSE);
	GetDlgItem(IDC_EQUAL)->ShowWindow(FALSE);
	GetDlgItem(IDC_EXCLAIM)->ShowWindow(FALSE);
	GetDlgItem(IDC_HYPHEN)->ShowWindow(FALSE);
	GetDlgItem(IDC_QUESTION)->ShowWindow(FALSE);
	GetDlgItem(IDC_SEMICOLON)->ShowWindow(FALSE);
	GetDlgItem(IDC_SGQUOT)->ShowWindow(FALSE);
	GetDlgItem(IDC_SLASH)->ShowWindow(FALSE);
	GetDlgItem(IDC_SQBRACKET_CLOSE)->ShowWindow(FALSE);
	GetDlgItem(IDC_SQBRACKET_OPEN)->ShowWindow(FALSE);
	GetDlgItem(IDC_AtMark)->ShowWindow(FALSE);
}







































// ���� - ��
void CEye_Computing_DialogDlg::OnBnClickedIii()
{
	CheckKorEng();
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
		InputYae.ki.wVk = 0x14;
		::SendInput(1, &InputYae, sizeof(INPUT));
		InputYae.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputYae, sizeof(INPUT));
		//�� ħ
		InputYae.ki.wVk = 0x4F;
		::SendInput(1, &InputYae, sizeof(INPUT));
		InputYae.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputYae, sizeof(INPUT));
		// ����Ʈ ��
		InputYae.ki.wVk = 0x14;
		::SendInput(1, &InputYae, sizeof(INPUT));
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
		//ĸ���� ������
		InputYe.ki.wVk = 0x14;
		::SendInput(1, &InputYe, sizeof(INPUT));
		InputYe.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputYe, sizeof(INPUT));
		//�� ħ
		InputYe.ki.wVk = 0x50;
		::SendInput(1, &InputYe, sizeof(INPUT));
		InputYe.ki.dwFlags = KEYEVENTF_KEYUP;
		::SendInput(1, &InputYe, sizeof(INPUT));
		// ĸ���� �ѹ���
		InputYe.ki.wVk = 0x14;
		::SendInput(1, &InputYe, sizeof(INPUT));
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
	CheckKorEng();
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
	CheckKorEng();
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

// ���� - ��
void CEye_Computing_DialogDlg::OnBnClickedGiyeok()
{
	CheckKorEng();
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
	CheckKorEng();
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
	CheckKorEng();
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
	CheckKorEng();
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
	CheckKorEng();
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
	CheckKorEng();
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
// ���� - 
void CEye_Computing_DialogDlg::OnBnClickedShiot()
{
	CheckKorEng();
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
	CheckKorEng();
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
	CheckKorEng();
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
	CheckKorEng();
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
	CheckKorEng();
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
	CheckKorEng();
	initHanguel();
	INPUT InputTieut;
	//initialize
	::ZeroMemory(&InputTieut, sizeof(INPUT));
	//keyboard�� �Է��ϰڴ�.
	InputTieut.type = INPUT_KEYBOARD;
	//���ư��������
	InputTieut.ki.wVk = 0x58;
	//�ѹ������ֱ�
	::SendInput(1, &InputTieut, sizeof(INPUT));
	//������ Ǯ���ֱ�
	InputTieut.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &InputTieut, sizeof(INPUT));
}
// ���� - ��
void CEye_Computing_DialogDlg::OnBnClickedPieup()
{
	CheckKorEng();
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
	CheckKorEng();
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


void CEye_Computing_DialogDlg::OnBnClickedKorean()
{

	
	isKorean = true;

	hideEngBtn();
	showKorBtn();

	INPUT InputHE;
	::ZeroMemory(&InputHE, sizeof(INPUT));
	InputHE.type = INPUT_KEYBOARD;

	InputHE.ki.wVk = 0x15;
	::SendInput(1, &InputHE, sizeof(INPUT));
	InputHE.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &InputHE, sizeof(INPUT));


	clickedKorean = true;
	clickedEnglish = false;


	INPUT HanToEng;
	::ZeroMemory(&HanToEng, sizeof(INPUT));
	HanToEng.type = INPUT_KEYBOARD;
	HanToEng.ki.wVk = VK_HANGEUL;
	::SendInput(1, &HanToEng, sizeof(INPUT));
	HanToEng.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &HanToEng, sizeof(INPUT));

	showKorBtn();
	hideNumBtn();
	hideEngBtn();
	
	Invalidate(TRUE);

}

void CEye_Computing_DialogDlg::OnBnClickedEnglish()
{
	hideKorBtn();
	showEngBtn();

	INPUT InputHE;
	::ZeroMemory(&InputHE, sizeof(INPUT));
	InputHE.type = INPUT_KEYBOARD;

	InputHE.ki.wVk = 0x15;
	::SendInput(1, &InputHE, sizeof(INPUT));
	InputHE.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &InputHE, sizeof(INPUT));

	clickedEnglish = true;
	clickedKorean = false;


	hideKorBtn();
	hideNumBtn();
	showEngBtn();

	Invalidate(TRUE);
}

void CEye_Computing_DialogDlg::OnBnClickedNumber()
{
	hideKorBtn();
	hideEngBtn();
	showNumBtn();
	Invalidate(TRUE);
}

void CEye_Computing_DialogDlg::OnBnClickedCptA()
{
	CheckKorEng();
	initHanguel();
	INPUT InputButton;
	//initialize
	::ZeroMemory(&InputButton, sizeof(INPUT));
	//keyboard�� �Է��ϰڴ�.
	InputButton.type = INPUT_KEYBOARD;
	//���ư��������
	InputButton.ki.wVk = 0x41;
	//�ѹ������ֱ�
	::SendInput(1, &InputButton, sizeof(INPUT));
	//������ Ǯ���ֱ�
	InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &InputButton, sizeof(INPUT));
}

void CEye_Computing_DialogDlg::OnBnClickedCptB()
{
	CheckKorEng();
	initHanguel();
	INPUT InputButton;
	//initialize
	::ZeroMemory(&InputButton, sizeof(INPUT));
	//keyboard�� �Է��ϰڴ�.
	InputButton.type = INPUT_KEYBOARD;
	//���ư��������
	InputButton.ki.wVk = 0x42;
	//�ѹ������ֱ�
	::SendInput(1, &InputButton, sizeof(INPUT));
	//������ Ǯ���ֱ�
	InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &InputButton, sizeof(INPUT));
}

void CEye_Computing_DialogDlg::OnBnClickedCptC()
{
	CheckKorEng();
	initHanguel();
	INPUT InputButton;
	//initialize
	::ZeroMemory(&InputButton, sizeof(INPUT));
	//keyboard�� �Է��ϰڴ�.
	InputButton.type = INPUT_KEYBOARD;
	//���ư��������
	InputButton.ki.wVk = 0x43;
	//�ѹ������ֱ�
	::SendInput(1, &InputButton, sizeof(INPUT));
	//������ Ǯ���ֱ�
	InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &InputButton, sizeof(INPUT));
}

void CEye_Computing_DialogDlg::OnBnClickedCptD()
{
	CheckKorEng();
	initHanguel();
	INPUT InputButton;
	//initialize
	::ZeroMemory(&InputButton, sizeof(INPUT));
	//keyboard�� �Է��ϰڴ�.
	InputButton.type = INPUT_KEYBOARD;
	//���ư��������
	InputButton.ki.wVk = 0x44;
	//�ѹ������ֱ�
	::SendInput(1, &InputButton, sizeof(INPUT));
	//������ Ǯ���ֱ�
	InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &InputButton, sizeof(INPUT));
}

void CEye_Computing_DialogDlg::OnBnClickedCptE()
{
	CheckKorEng();
	initHanguel();
	INPUT InputButton;
	//initialize
	::ZeroMemory(&InputButton, sizeof(INPUT));
	//keyboard�� �Է��ϰڴ�.
	InputButton.type = INPUT_KEYBOARD;
	//���ư��������
	InputButton.ki.wVk = 0x45;
	//�ѹ������ֱ�
	::SendInput(1, &InputButton, sizeof(INPUT));
	//������ Ǯ���ֱ�
	InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &InputButton, sizeof(INPUT));
}

void CEye_Computing_DialogDlg::OnBnClickedCptF()
{
	CheckKorEng();
	initHanguel();
	INPUT InputButton;
	//initialize
	::ZeroMemory(&InputButton, sizeof(INPUT));
	//keyboard�� �Է��ϰڴ�.
	InputButton.type = INPUT_KEYBOARD;
	//���ư��������
	InputButton.ki.wVk = 0x46;
	//�ѹ������ֱ�
	::SendInput(1, &InputButton, sizeof(INPUT));
	//������ Ǯ���ֱ�
	InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &InputButton, sizeof(INPUT));
}

void CEye_Computing_DialogDlg::OnBnClickedCptG()
{
	CheckKorEng();
	initHanguel();
	INPUT InputButton;
	//initialize
	::ZeroMemory(&InputButton, sizeof(INPUT));
	//keyboard�� �Է��ϰڴ�.
	InputButton.type = INPUT_KEYBOARD;
	//���ư��������
	InputButton.ki.wVk = 0x47;
	//�ѹ������ֱ�
	::SendInput(1, &InputButton, sizeof(INPUT));
	//������ Ǯ���ֱ�
	InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &InputButton, sizeof(INPUT));
}

void CEye_Computing_DialogDlg::OnBnClickedCptH()
{
	CheckKorEng();
	initHanguel();
	INPUT InputButton;
	//initialize
	::ZeroMemory(&InputButton, sizeof(INPUT));
	//keyboard�� �Է��ϰڴ�.
	InputButton.type = INPUT_KEYBOARD;
	//���ư��������
	InputButton.ki.wVk = 0x48;
	//�ѹ������ֱ�
	::SendInput(1, &InputButton, sizeof(INPUT));
	//������ Ǯ���ֱ�
	InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &InputButton, sizeof(INPUT));
}

void CEye_Computing_DialogDlg::OnBnClickedCptI()
{
	CheckKorEng();
	initHanguel();
	INPUT InputButton;
	//initialize
	::ZeroMemory(&InputButton, sizeof(INPUT));
	//keyboard�� �Է��ϰڴ�.
	InputButton.type = INPUT_KEYBOARD;
	//���ư��������
	InputButton.ki.wVk = 0x49;
	//�ѹ������ֱ�
	::SendInput(1, &InputButton, sizeof(INPUT));
	//������ Ǯ���ֱ�
	InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &InputButton, sizeof(INPUT));
}

void CEye_Computing_DialogDlg::OnBnClickedCptJ()
{
	CheckKorEng();
	initHanguel();
	INPUT InputButton;
	//initialize
	::ZeroMemory(&InputButton, sizeof(INPUT));
	//keyboard�� �Է��ϰڴ�.
	InputButton.type = INPUT_KEYBOARD;
	//���ư��������
	InputButton.ki.wVk = 0x4A;
	//�ѹ������ֱ�
	::SendInput(1, &InputButton, sizeof(INPUT));
	//������ Ǯ���ֱ�
	InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &InputButton, sizeof(INPUT));
}

void CEye_Computing_DialogDlg::OnBnClickedCptK()
{
	CheckKorEng();
	initHanguel();
	INPUT InputButton;
	//initialize
	::ZeroMemory(&InputButton, sizeof(INPUT));
	//keyboard�� �Է��ϰڴ�.
	InputButton.type = INPUT_KEYBOARD;
	//���ư��������
	InputButton.ki.wVk = 0x4B;
	//�ѹ������ֱ�
	::SendInput(1, &InputButton, sizeof(INPUT));
	//������ Ǯ���ֱ�
	InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &InputButton, sizeof(INPUT));
}

void CEye_Computing_DialogDlg::OnBnClickedCptL()
{
	CheckKorEng();
	initHanguel();
	INPUT InputButton;
	//initialize
	::ZeroMemory(&InputButton, sizeof(INPUT));
	//keyboard�� �Է��ϰڴ�.
	InputButton.type = INPUT_KEYBOARD;
	//���ư��������
	InputButton.ki.wVk = 0x4C;
	//�ѹ������ֱ�
	::SendInput(1, &InputButton, sizeof(INPUT));
	//������ Ǯ���ֱ�
	InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &InputButton, sizeof(INPUT));
}

void CEye_Computing_DialogDlg::OnBnClickedCptM()
{
	CheckKorEng();
	initHanguel();
	INPUT InputButton;
	//initialize
	::ZeroMemory(&InputButton, sizeof(INPUT));
	//keyboard�� �Է��ϰڴ�.
	InputButton.type = INPUT_KEYBOARD;
	//���ư��������
	InputButton.ki.wVk = 0x4D;
	//�ѹ������ֱ�
	::SendInput(1, &InputButton, sizeof(INPUT));
	//������ Ǯ���ֱ�
	InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &InputButton, sizeof(INPUT));
}

void CEye_Computing_DialogDlg::OnBnClickedCptN()
{
	CheckKorEng();
	initHanguel();
	INPUT InputButton;
	//initialize
	::ZeroMemory(&InputButton, sizeof(INPUT));
	//keyboard�� �Է��ϰڴ�.
	InputButton.type = INPUT_KEYBOARD;
	//���ư��������
	InputButton.ki.wVk = 0x4E;
	//�ѹ������ֱ�
	::SendInput(1, &InputButton, sizeof(INPUT));
	//������ Ǯ���ֱ�
	InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &InputButton, sizeof(INPUT));
}

void CEye_Computing_DialogDlg::OnBnClickedCptO()
{
	CheckKorEng();
	initHanguel();
	INPUT InputButton;
	//initialize
	::ZeroMemory(&InputButton, sizeof(INPUT));
	//keyboard�� �Է��ϰڴ�.
	InputButton.type = INPUT_KEYBOARD;
	//���ư��������
	InputButton.ki.wVk = 0x4F;
	//�ѹ������ֱ�
	::SendInput(1, &InputButton, sizeof(INPUT));
	//������ Ǯ���ֱ�
	InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &InputButton, sizeof(INPUT));
}

void CEye_Computing_DialogDlg::OnBnClickedCptP()
{
	CheckKorEng();
	initHanguel();
	INPUT InputButton;
	//initialize
	::ZeroMemory(&InputButton, sizeof(INPUT));
	//keyboard�� �Է��ϰڴ�.
	InputButton.type = INPUT_KEYBOARD;
	//���ư��������
	InputButton.ki.wVk = 0x50;
	//�ѹ������ֱ�
	::SendInput(1, &InputButton, sizeof(INPUT));
	//������ Ǯ���ֱ�
	InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &InputButton, sizeof(INPUT));
}

void CEye_Computing_DialogDlg::OnBnClickedCptQ()
{
	CheckKorEng();
	initHanguel();
	INPUT InputButton;
	//initialize
	::ZeroMemory(&InputButton, sizeof(INPUT));
	//keyboard�� �Է��ϰڴ�.
	InputButton.type = INPUT_KEYBOARD;
	//���ư��������
	InputButton.ki.wVk = 0x51;
	//�ѹ������ֱ�
	::SendInput(1, &InputButton, sizeof(INPUT));
	//������ Ǯ���ֱ�
	InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &InputButton, sizeof(INPUT));
}

void CEye_Computing_DialogDlg::OnBnClickedCptR()
{
	CheckKorEng();
	initHanguel();
	INPUT InputButton;
	//initialize
	::ZeroMemory(&InputButton, sizeof(INPUT));
	//keyboard�� �Է��ϰڴ�.
	InputButton.type = INPUT_KEYBOARD;
	//���ư��������
	InputButton.ki.wVk = 0x52;
	//�ѹ������ֱ�
	::SendInput(1, &InputButton, sizeof(INPUT));
	//������ Ǯ���ֱ�
	InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &InputButton, sizeof(INPUT));
}

void CEye_Computing_DialogDlg::OnBnClickedCptS()
{
	CheckKorEng();
	initHanguel();
	INPUT InputButton;
	//initialize
	::ZeroMemory(&InputButton, sizeof(INPUT));
	//keyboard�� �Է��ϰڴ�.
	InputButton.type = INPUT_KEYBOARD;
	//���ư��������
	InputButton.ki.wVk = 0x53;
	//�ѹ������ֱ�
	::SendInput(1, &InputButton, sizeof(INPUT));
	//������ Ǯ���ֱ�
	InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &InputButton, sizeof(INPUT));
}

void CEye_Computing_DialogDlg::OnBnClickedCptT()
{
	CheckKorEng();
	initHanguel();
	INPUT InputButton;
	//initialize
	::ZeroMemory(&InputButton, sizeof(INPUT));
	//keyboard�� �Է��ϰڴ�.
	InputButton.type = INPUT_KEYBOARD;
	//���ư��������
	InputButton.ki.wVk = 0x54;
	//�ѹ������ֱ�
	::SendInput(1, &InputButton, sizeof(INPUT));
	//������ Ǯ���ֱ�
	InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &InputButton, sizeof(INPUT));
}

void CEye_Computing_DialogDlg::OnBnClickedCptU()
{
	CheckKorEng();
	initHanguel();
	INPUT InputButton;
	//initialize
	::ZeroMemory(&InputButton, sizeof(INPUT));
	//keyboard�� �Է��ϰڴ�.
	InputButton.type = INPUT_KEYBOARD;
	//���ư��������
	InputButton.ki.wVk = 0x55;
	//�ѹ������ֱ�
	::SendInput(1, &InputButton, sizeof(INPUT));
	//������ Ǯ���ֱ�
	InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &InputButton, sizeof(INPUT));
}

void CEye_Computing_DialogDlg::OnBnClickedCptV()
{
	CheckKorEng();
	initHanguel();
	INPUT InputButton;
	//initialize
	::ZeroMemory(&InputButton, sizeof(INPUT));
	//keyboard�� �Է��ϰڴ�.
	InputButton.type = INPUT_KEYBOARD;
	//���ư��������
	InputButton.ki.wVk = 0x56;
	//�ѹ������ֱ�
	::SendInput(1, &InputButton, sizeof(INPUT));
	//������ Ǯ���ֱ�
	InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &InputButton, sizeof(INPUT));
}

void CEye_Computing_DialogDlg::OnBnClickedCptW()
{
	CheckKorEng();
	initHanguel();
	INPUT InputButton;
	//initialize
	::ZeroMemory(&InputButton, sizeof(INPUT));
	//keyboard�� �Է��ϰڴ�.
	InputButton.type = INPUT_KEYBOARD;
	//���ư��������
	InputButton.ki.wVk = 0x57;
	//�ѹ������ֱ�
	::SendInput(1, &InputButton, sizeof(INPUT));
	//������ Ǯ���ֱ�
	InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &InputButton, sizeof(INPUT));
}

void CEye_Computing_DialogDlg::OnBnClickedCptX()
{
	CheckKorEng();
	initHanguel();
	INPUT InputButton;
	//initialize
	::ZeroMemory(&InputButton, sizeof(INPUT));
	//keyboard�� �Է��ϰڴ�.
	InputButton.type = INPUT_KEYBOARD;
	//���ư��������
	InputButton.ki.wVk = 0x58;
	//�ѹ������ֱ�
	::SendInput(1, &InputButton, sizeof(INPUT));
	//������ Ǯ���ֱ�
	InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &InputButton, sizeof(INPUT));
}

void CEye_Computing_DialogDlg::OnBnClickedCptY()
{
	CheckKorEng();
	initHanguel();
	INPUT InputButton;
	//initialize
	::ZeroMemory(&InputButton, sizeof(INPUT));
	//keyboard�� �Է��ϰڴ�.
	InputButton.type = INPUT_KEYBOARD;
	//���ư��������
	InputButton.ki.wVk = 0x59;
	//�ѹ������ֱ�
	::SendInput(1, &InputButton, sizeof(INPUT));
	//������ Ǯ���ֱ�
	InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &InputButton, sizeof(INPUT));
}

void CEye_Computing_DialogDlg::OnBnClickedCptZ()
{
	CheckKorEng();
	initHanguel();
	INPUT InputButton;
	//initialize
	::ZeroMemory(&InputButton, sizeof(INPUT));
	//keyboard�� �Է��ϰڴ�.
	InputButton.type = INPUT_KEYBOARD;
	//���ư��������
	InputButton.ki.wVk = 0x5A;
	//�ѹ������ֱ�
	::SendInput(1, &InputButton, sizeof(INPUT));
	//������ Ǯ���ֱ�
	InputButton.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &InputButton, sizeof(INPUT));
}



