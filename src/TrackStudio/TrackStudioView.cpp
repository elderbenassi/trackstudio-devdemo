
// TrackStudioView.cpp: implementação da classe CTrackStudioView
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS pode ser definido em um projeto ATL implementando a visualização, a miniatura
// e manipuladores de filtro de pesquisa e permite o compartilhamento de código do documento com esse projeto.
#ifndef SHARED_HANDLERS
#include "TrackStudio.h"
#endif

#include "TrackStudioDoc.h"
#include "TrackStudioView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTrackStudioView

IMPLEMENT_DYNCREATE(CTrackStudioView, CView)

BEGIN_MESSAGE_MAP(CTrackStudioView, CView)
	// Comandos de impressão padrão
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CTrackStudioView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// Construção/destruição de CTrackStudioView

CTrackStudioView::CTrackStudioView() noexcept
{
	// TODO: adicione o código de construção aqui

}

CTrackStudioView::~CTrackStudioView()
{
}

BOOL CTrackStudioView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: modifique a classe ou os estilos de Janela aqui modificando
	//  os cs CREATESTRUCT

	return CView::PreCreateWindow(cs);
}

// desenho de CTrackStudioView

void CTrackStudioView::OnDraw(CDC* /*pDC*/)
{
	CTrackStudioDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: adicione o código de desenho para dados nativos aqui
}


// impressão de CTrackStudioView


void CTrackStudioView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CTrackStudioView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// preparação padrão
	return DoPreparePrinting(pInfo);
}

void CTrackStudioView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: adicione inicialização extra antes de imprimir
}

void CTrackStudioView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: adicione a limpeza após a impressão
}

void CTrackStudioView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CTrackStudioView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Diagnóstico de CTrackStudioView

#ifdef _DEBUG
void CTrackStudioView::AssertValid() const
{
	CView::AssertValid();
}

void CTrackStudioView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTrackStudioDoc* CTrackStudioView::GetDocument() const // a versão sem depuração está embutida
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTrackStudioDoc)));
	return (CTrackStudioDoc*)m_pDocument;
}
#endif //_DEBUG


// Manipuladores de mensagens de CTrackStudioView
