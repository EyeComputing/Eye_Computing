
// Eye_computingView.h : CEye_computingView Ŭ������ �������̽�
//

#pragma once


class CEye_computingView : public CView
{
protected: // serialization������ ��������ϴ�.
	CEye_computingView();
	DECLARE_DYNCREATE(CEye_computingView)

// Ư���Դϴ�.
public:
	CEye_computingDoc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CEye_computingView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Eye_computingView.cpp�� ����� ����
inline CEye_computingDoc* CEye_computingView::GetDocument() const
   { return reinterpret_cast<CEye_computingDoc*>(m_pDocument); }
#endif

