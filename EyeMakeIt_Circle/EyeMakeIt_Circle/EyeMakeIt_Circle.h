
// EyeMakeIt_Circle.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CEyeMakeIt_CircleApp:
// �� Ŭ������ ������ ���ؼ��� EyeMakeIt_Circle.cpp�� �����Ͻʽÿ�.
//

class CEyeMakeIt_CircleApp : public CWinApp
{
public:
	CEyeMakeIt_CircleApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CEyeMakeIt_CircleApp theApp;