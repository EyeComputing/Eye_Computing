
// EyeMakeIt.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CEyeMakeItApp:
// �� Ŭ������ ������ ���ؼ��� EyeMakeIt.cpp�� �����Ͻʽÿ�.
//

class CEyeMakeItApp : public CWinApp
{
public:
	CEyeMakeItApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CEyeMakeItApp theApp;