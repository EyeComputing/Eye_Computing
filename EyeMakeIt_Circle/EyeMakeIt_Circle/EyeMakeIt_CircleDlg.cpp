
// EyeMakeIt_CircleDlg.cpp : ���� ����
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

bool clicked_YII = false;	// ��
bool clicked_ZUM = false;	// ��
bool clicked_ZUM2 = false;	// ��2��
bool clicked_AAA = false;	// ��
bool clicked_YAA = false;	// ��
bool clicked_EOO = false;	// ��
bool clicked_YEO = false;	// ��
bool clicked_OOO = false;	// ��
bool clicked_UUU = false;	// ��
bool clicked_YUU = false;	// ��
bool clicked_EUU = false;	// ��
bool clicked_OEE = false;	// ��
bool clicked_WAA = false;	// ��
bool clicked_WOU = false;	// ��

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





// CEyeMakeIt_CircleDlg ��ȭ ����

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
	/* ��ư Ŭ�� �ѹ��� �ϴ� �޼��� ���� */
	ON_COMMAND_RANGE(IDC_K_GIY, IDC_K_KIE, CEyeMakeIt_CircleDlg::OnBtnClick)
	//ON_WM_LBUTTONDOWN()
	//ON_WM_MOUSEMOVE()
	ON_BN_SETFOCUS(IDC_K_GIY, &CEyeMakeIt_CircleDlg::OnBnSetfocusKGiy)
	ON_WM_MOUSEHOVER()
END_MESSAGE_MAP()


// CEyeMakeIt_CircleDlg �޽��� ó����

BOOL CEyeMakeIt_CircleDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

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

	//�ֻ��� ������� ����
	SetWindowPos((const CWnd*)&(this->m_hWnd), (int)(HWND_TOPMOST), 0, 0, 0, (UINT)(SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW));

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CEyeMakeIt_CircleDlg::OnPaint()
{

	//�ֻ��� ������� ����
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
HCURSOR CEyeMakeIt_CircleDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}





/* ����� ���� �Լ� */


/* ���⼭ �Լ� ���� & ��� */
int GetFindCharCount(CString parm_string, char parm_find_char)
// ���ڿ��� � ���ڰ� �� �� ��� �ִ���
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
// ���ڿ��� /������/���ڰ� ��� ��ġ���ִ���
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

// ���� �ʱ�ȭ
void initButtonState()
{
	clicked_YII = false;	// ��
	clicked_ZUM = false;	// ��
	clicked_ZUM2 = false;	// ��2��
	clicked_AAA = false;	// ��
	clicked_YAA = false;	// ��
	clicked_EOO = false;	// ��
	clicked_YEO = false;	// ��
	clicked_OOO = false;	// ��
	clicked_UUU = false;	// ��
	clicked_YUU = false;	// ��
	clicked_EUU = false;	// ��
	clicked_OEE = false;	// ��
	clicked_WAA = false;	// ��
	clicked_WOU = false;	// ��
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
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.

	return CDialogEx::PreTranslateMessage(pMsg);
}



// �ȵ�..��
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

	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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




/* �Լ� ���� _ .h�� */

// hangeul input �Լ�
void CEyeMakeIt_CircleDlg::InputHangeul(int textCode)
{
	hangeulInput.SetHangeulCode(textCode);

	CString complete_text = hangeulInput.completeText;

	if (hangeulInput.ingWord != NULL)
		complete_text += hangeulInput.ingWord;


	SetDlgItemText(IDC_MAINEDIT, complete_text); // mainEdit�� ���
	
	CString sub_text;
	
	int space = GetFindCharCount(complete_text, ' '); // �����̽��ٰ� �� �� �ִ��� ã��
	int enter = GetFindCharCount(complete_text, '\n'); // ���Ͱ� �� �� �ִ��� ã��

	int space_count = GetLastCharCount(complete_text, ' '); // ������ �����̽����� ��ġ
	int enter_count = GetLastCharCount(complete_text, '\n'); // ������ ������ ��ġ

	if (enter_count > space_count) { // 
		AfxExtractSubString(sub_text, complete_text, enter, '\n'); // ������ ���ͷκ��� ���ڿ��� �߶�
	}
	else
		AfxExtractSubString(sub_text, complete_text, space, ' '); // ������ �����̽��κ��� ���ڿ��� �߶�
		
	//sub_text += hangeulInput.completeText;

	SetDlgItemText(IDC_SUBEDIT, sub_text); // subEdit�� ���


	CEdit * pEdit = ((CEdit*)GetDlgItem(IDC_MAINEDIT));
	pEdit->SetSel(pEdit->GetWindowTextLength(), pEdit->GetWindowTextLength());
	pEdit->SetFocus();

}

// textinput �Լ�
void CEyeMakeIt_CircleDlg::InputText(CString text)
{
	hangeulInput.completeText += text;

	CString complete_text = hangeulInput.completeText;

	if (hangeulInput.ingWord != NULL)
		complete_text += hangeulInput.ingWord;

	SetDlgItemText(IDC_MAINEDIT, complete_text);

	CString sub_text;
	int space = GetFindCharCount(complete_text, ' '); // �����̽��ٰ� �� �� �ִ��� ã��
	int enter = GetFindCharCount(complete_text, '\n'); // ���Ͱ� �� �� �ִ��� ã��

	int space_count = GetLastCharCount(complete_text, ' '); // ������ �����̽����� ��ġ
	int enter_count = GetLastCharCount(complete_text, '\n'); // ������ ������ ��ġ

	if (enter_count > space_count) { // 
		AfxExtractSubString(sub_text, complete_text, enter, '\n'); // ������ ���ͷκ��� ���ڿ��� �߶�
	}
	else
		AfxExtractSubString(sub_text, complete_text, space, ' '); // ������ �����̽��κ��� ���ڿ��� �߶�

	SetDlgItemText(IDC_SUBEDIT, sub_text); // subEdit�� ���

	CEdit * pEdit = ((CEdit*)GetDlgItem(IDC_MAINEDIT));
	pEdit->SetSel(pEdit->GetWindowTextLength(), pEdit->GetWindowTextLength());
	pEdit->SetFocus();
}




//��ư Ŭ�� �Լ�

void CEyeMakeIt_CircleDlg::OnBtnClick(UINT uiID)
{
	switch (uiID)
	{
		// �� ������
		case IDC_K_YII:
		{
			if (clicked_ZUM)	// �� + �� = ��
			{
				InputHangeul(23);
				clicked_ZUM = false;
				clicked_EOO = true;
			}
			else if (clicked_ZUM2)	// ���� + �� = ��
			{
				InputHangeul(25);
				clicked_ZUM2 = false;
				clicked_YEO = true;
			}
			else if (clicked_EOO)	//	�� + �� = ��
			{
				InputHangeul(-3);
				InputHangeul(24);
				clicked_EOO = false;
			}
			else if (clicked_AAA)	// �� + �� = ��
			{
				InputHangeul(-3);
				InputHangeul(20);
				clicked_AAA = false;
			}
			else if (clicked_YAA)	// �� + �� = ��
			{
				InputHangeul(-3);
				InputHangeul(22);
				clicked_YAA = false;
			}
			else if (clicked_OOO)	// �� + �� = ��
			{
				InputHangeul(-3);
				InputHangeul(30);
				clicked_OOO = false;
				clicked_OEE = true;
			}
			else if (clicked_WAA)	// �� + �� = ��
			{
				InputHangeul(-3);
				InputHangeul(29);
				clicked_WAA = false;
			}
			else if (clicked_UUU)	// �� + �� = ��
			{
				InputHangeul(-3);
				InputHangeul(35);
				clicked_UUU = false;
			}
			else if (clicked_YUU)	// �� + �� = ��
			{
				InputHangeul(-3);
				InputHangeul(33);
				clicked_YUU = false;
				clicked_WOU = true;
			}
			else if (clicked_WOU)	// �� + �� = ��
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
		// �� ������
		case IDC_K_ZUM:
		{
			if (clicked_YII)		// �� + �� = ��
			{
				InputHangeul(-3);
				InputHangeul(19);
				clicked_YII = false;
				clicked_AAA = true;
			}
			else if (clicked_AAA)	// �� + �� = ��
			{
				InputHangeul(-3);
				InputHangeul(21);
				clicked_AAA = false;
				clicked_YAA = true;
			}
			else if (clicked_EUU)	// �� + �� = ��
			{
				InputHangeul(-3);
				InputHangeul(32);
				clicked_EUU = false;
				clicked_UUU = true;
			}
			else if (clicked_UUU)	// �� + �� = ��
			{
				InputHangeul(-3);
				InputHangeul(36);
				clicked_UUU = false;
				clicked_YUU = true;
			}
			else if (clicked_OEE)	// �� + �� = ��
			{
				InputHangeul(-3);
				InputHangeul(28);
				clicked_OEE = false;
				clicked_WAA = true;
			}
			else if (clicked_ZUM)	// �� + �� = ����
			{
				clicked_ZUM = false;
				clicked_ZUM2 = true;
			}
			else 					// ��
			{
				clicked_ZUM = true;
			}

			break;
		}
		// �� ������
		case IDC_K_EUU:
		{
			if (clicked_ZUM)		//�� + �� = ��
			{
				InputHangeul(27);
				clicked_ZUM = false;
				clicked_OOO = true;
			}
			else if (clicked_ZUM2)	//���� + �� = ��
			{
				InputHangeul(31);
				clicked_ZUM2 = false;
			}
			else 					// �� = ��
			{
				InputHangeul(37);
				clicked_EUU = true;
			}
			break;
		}


		// ����

		case IDC_K_GIY:		// ��
		{
			initButtonState();
			if (clickedShift)
				InputHangeul(1);
			else
				InputHangeul(0);

			break;
		}
		case IDC_K_NIE:		// ��
		{
			initButtonState();

			InputHangeul(2);

			break;
		}
	}
}






