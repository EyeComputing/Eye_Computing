
// EyeMakeIt_CircleDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "EyeMakeIt_Circle.h"
#include "EyeMakeIt_CircleDlg.h"
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
	ON_COMMAND_RANGE(IDC_K_GIY, IDC_K_ZUM, CEyeMakeIt_CircleDlg::OnBtnClick)
	//ON_WM_LBUTTONDOWN()
	//ON_WM_MOUSEMOVE()
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



// hangeul input 함수
void CEyeMakeIt_CircleDlg::InputHangeul(int textCode)
{
	hangeulInput.SetHangeulCode(textCode);

	CString complete_text = hangeulInput.completeText;

	if (hangeulInput.ingWord != NULL)
		complete_text += hangeulInput.ingWord;


	SetDlgItemText(IDC_MAINEDIT, complete_text); // mainEdit에 띄움
	
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

	CEdit * pEdit = ((CEdit*)GetDlgItem(IDC_MAINEDIT));
	pEdit->SetSel(pEdit->GetWindowTextLength(), pEdit->GetWindowTextLength());
	pEdit->SetFocus();

}


// 맨 위에 있게 하는 함수
BOOL CEyeMakeIt_CircleDlg::PreTranslateMessage(MSG* pMsg)
{
	if ((pMsg->message == WM_LBUTTONDOWN) || (pMsg->message == WM_RBUTTONDOWN))
		/* 항상 맨 위에 */
		SetWindowPos((const CWnd*)&(this->m_hWnd), (int)(HWND_TOPMOST), 0, 0, 0, (UINT)(SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW));

	return CDialogEx::PreTranslateMessage(pMsg);
}




//버튼 클릭 함수

void CEyeMakeIt_CircleDlg::OnBtnClick(UINT uiID)
{
	switch (uiID)
	{
	case IDC_K_GIY:
	{
		//if (clickedShift)
			//InputHangeul(1);
		//else
			InputHangeul(0);

		break;
	}
	case IDC_K_YII:
	{
		InputHangeul(39);
		break;
	}
	case IDC_K_ZUM:
	{
		InputHangeul(40);
		break;
	}/*
	 case :
	 {
	 break;
	 }
	 case :
	 {
	 break;
	 }
	 case :
	 {
	 break;
	 }*/

	}
}



