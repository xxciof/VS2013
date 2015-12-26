
// TestMFCCView.cpp : CTestMFCCView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "TestMFCC.h"
#endif

#include "TestMFCCDoc.h"
#include "TestMFCCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestMFCCView

IMPLEMENT_DYNCREATE(CTestMFCCView, CView)

BEGIN_MESSAGE_MAP(CTestMFCCView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CTestMFCCView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CTestMFCCView ����/����

CTestMFCCView::CTestMFCCView()
{
	// TODO:  �ڴ˴���ӹ������

}

CTestMFCCView::~CTestMFCCView()
{
}

BOOL CTestMFCCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CTestMFCCView ����

void CTestMFCCView::OnDraw(CDC* /*pDC*/)
{
	CTestMFCCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CTestMFCCView ��ӡ


void CTestMFCCView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CTestMFCCView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CTestMFCCView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CTestMFCCView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}

void CTestMFCCView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CTestMFCCView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CTestMFCCView ���

#ifdef _DEBUG
void CTestMFCCView::AssertValid() const
{
	CView::AssertValid();
}

void CTestMFCCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTestMFCCDoc* CTestMFCCView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTestMFCCDoc)));
	return (CTestMFCCDoc*)m_pDocument;
}
#endif //_DEBUG


// CTestMFCCView ��Ϣ�������
