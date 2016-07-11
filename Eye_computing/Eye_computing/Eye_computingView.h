
// Eye_computingView.h : CEye_computingView 클래스의 인터페이스
//

#pragma once


class CEye_computingView : public CView
{
protected: // serialization에서만 만들어집니다.
	CEye_computingView();
	DECLARE_DYNCREATE(CEye_computingView)

// 특성입니다.
public:
	CEye_computingDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CEye_computingView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Eye_computingView.cpp의 디버그 버전
inline CEye_computingDoc* CEye_computingView::GetDocument() const
   { return reinterpret_cast<CEye_computingDoc*>(m_pDocument); }
#endif

