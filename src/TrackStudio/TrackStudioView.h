
// TrackStudioView.h: interface da classe CTrackStudioView
//
#include "Panel.h"
#pragma once


class CTrackStudioView : public CView
{
private:
	Panel *panel;
protected: // criar apenas com base na serialização
	CTrackStudioView() noexcept;
	DECLARE_DYNCREATE(CTrackStudioView)

// Atributos
public:
	CTrackStudioDoc* GetDocument() const;

// Operações
private:
	void LoadDataIntoClasses();

// Substitui
public:
	virtual void OnDraw(CDC* pDC);  // substituído para desenhar esta visualização
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementação
public:
	virtual ~CTrackStudioView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Funções geradas de mapa de mensagens
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // versão de depuração em TrackStudioView.cpp
inline CTrackStudioDoc* CTrackStudioView::GetDocument() const
   { return reinterpret_cast<CTrackStudioDoc*>(m_pDocument); }
#endif

