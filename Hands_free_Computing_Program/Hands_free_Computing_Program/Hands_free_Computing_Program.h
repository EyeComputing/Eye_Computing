
// Hands_free_Computing_Program.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.
#include "xSkinButton.h"

// CHands_free_Computing_ProgramApp:
// �� Ŭ������ ������ ���ؼ��� Hands_free_Computing_Program.cpp�� �����Ͻʽÿ�.
//

class CHands_free_Computing_ProgramApp : public CWinApp
{
public:
	CHands_free_Computing_ProgramApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CHands_free_Computing_ProgramApp theApp;