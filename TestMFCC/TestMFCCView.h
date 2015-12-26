
// TestMFCCView.h : CTestMFCCView ��Ľӿ�
//

#pragma once


class CTestMFCCView : public CView
{
protected: // �������л�����
	CTestMFCCView();
	DECLARE_DYNCREATE(CTestMFCCView)

// ����
public:
	CTestMFCCDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CTestMFCCView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // TestMFCCView.cpp �еĵ��԰汾
inline CTestMFCCDoc* CTestMFCCView::GetDocument() const
   { return reinterpret_cast<CTestMFCCDoc*>(m_pDocument); }
#endif

