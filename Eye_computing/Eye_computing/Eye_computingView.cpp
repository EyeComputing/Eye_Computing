
// Eye_computingView.cpp : CEye_computingView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_KEYDOWN()
	ON_WM_CREATE()
END_MESSAGE_MAP()

// CEye_computingView 생성/소멸

CEye_computingView::CEye_computingView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CEye_computingView::~CEye_computingView()
{
}

BOOL CEye_computingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CEye_computingView 그리기

void CEye_computingView::OnDraw(CDC* /*pDC*/)
{
	CEye_computingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CEye_computingView 인쇄

BOOL CEye_computingView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CEye_computingView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CEye_computingView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CEye_computingView 진단

#ifdef _DEBUG
void CEye_computingView::AssertValid() const
{
	CView::AssertValid();
}

void CEye_computingView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEye_computingDoc* CEye_computingView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEye_computingDoc)));
	return (CEye_computingDoc*)m_pDocument;
}
#endif //_DEBUG


// CEye_computingView 메시지 처리기


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
