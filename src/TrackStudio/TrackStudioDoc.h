
// TrackStudioDoc.h: interface da classe CTrackStudioDoc
//


#pragma once


class CTrackStudioDoc : public CDocument
{
protected: // criar apenas com base na serialização
	CTrackStudioDoc() noexcept;
	DECLARE_DYNCREATE(CTrackStudioDoc)

// Atributos
public:

// Operações
public:

// Substitui
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementação
public:
	virtual ~CTrackStudioDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Funções geradas de mapa de mensagens
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Função auxiliar que define o conteúdo de pesquisa para um Manipulador de Pesquisa
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
