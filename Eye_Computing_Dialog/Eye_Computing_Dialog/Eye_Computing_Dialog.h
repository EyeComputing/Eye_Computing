
// Eye_Computing_Dialog.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CEye_Computing_DialogApp:
// �� Ŭ������ ������ ���ؼ��� Eye_Computing_Dialog.cpp�� �����Ͻʽÿ�.
//

class CEye_Computing_DialogApp : public CWinApp
{
public:
	CEye_Computing_DialogApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CEye_Computing_DialogApp theApp;