
// Eye_computing.h : Eye_computing ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CEye_computingApp:
// �� Ŭ������ ������ ���ؼ��� Eye_computing.cpp�� �����Ͻʽÿ�.
//

class CEye_computingApp : public CWinAppEx
{
public:
	CEye_computingApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CEye_computingApp theApp;
