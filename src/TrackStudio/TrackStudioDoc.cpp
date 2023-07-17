
// TrackStudioDoc.cpp: implementação da classe CTrackStudioDoc
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS pode ser definido em um projeto ATL implementando a visualização, a miniatura
// e manipuladores de filtro de pesquisa e permite o compartilhamento de código do documento com esse projeto.
#ifndef SHARED_HANDLERS
#include "TrackStudio.h"
#endif

#include "TrackStudioDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CTrackStudioDoc

IMPLEMENT_DYNCREATE(CTrackStudioDoc, CDocument)

BEGIN_MESSAGE_MAP(CTrackStudioDoc, CDocument)
END_MESSAGE_MAP()


// Construção/destruição de CTrackStudioDoc

CTrackStudioDoc::CTrackStudioDoc() noexcept
{
	// TODO: adicione o código de construção avulsa aqui

}

CTrackStudioDoc::~CTrackStudioDoc()
{
}

BOOL CTrackStudioDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: adicione código de reinicialização aqui
	// (Os documentos SDI reutilizarão este documento)

	return TRUE;
}




// serialização de CTrackStudioDoc

void CTrackStudioDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: adicione código de armazenamento aqui
	}
	else
	{
		// TODO: adicione código de carregamento aqui
	}
}

#ifdef SHARED_HANDLERS

// Suporte a miniaturas
void CTrackStudioDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modificar este código para desenhar os dados do documento
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Suporte a Manipuladores de Pesquisa
void CTrackStudioDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Definir o conteúdo da pesquisa dos dados do documento.
	// As partes do conteúdo devem ser separadas por ";"

	// Por exemplo: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CTrackStudioDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// Diagnóstico de CTrackStudioDoc

#ifdef _DEBUG
void CTrackStudioDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTrackStudioDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// comandos de CTrackStudioDoc
