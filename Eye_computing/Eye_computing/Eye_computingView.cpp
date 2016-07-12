
// Eye_computingView.cpp : CEye_computingView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "Eye_computing.h"
#endif

#include "Eye_computingDoc.h"
#include "Eye_computingView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEye_computingView

IMPLEMENT_DYNCREATE(CEye_computingView, CView)

BEGIN_MESSAGE_MAP(CEye_computingView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_KEYDOWN()
	ON_WM_CREATE()
END_MESSAGE_MAP()

// CEye_computingView ����/�Ҹ�

CEye_computingView::CEye_computingView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CEye_computingView::~CEye_computingView()
{
}

BOOL CEye_computingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CEye_computingView �׸���

void CEye_computingView::OnDraw(CDC* /*pDC*/)
{
	CEye_computingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CEye_computingView �μ�

BOOL CEye_computingView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CEye_computingView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CEye_computingView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CEye_computingView ����

#ifdef _DEBUG
void CEye_computingView::AssertValid() const
{
	CView::AssertValid();
}

void CEye_computingView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEye_computingDoc* CEye_computingView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEye_computingDoc)));
	return (CEye_computingDoc*)m_pDocument;
}
#endif //_DEBUG


// CEye_computingView �޽��� ó����


void CEye_computingView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


int CEye_computingView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	return 0;
}
