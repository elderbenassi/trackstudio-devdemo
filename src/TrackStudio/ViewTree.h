
#pragma once

/////////////////////////////////////////////////////////////////////////////
// Janela CViewTree

class CViewTree : public CTreeCtrl
{
// Construção
public:
	CViewTree() noexcept;

// Substitui
protected:
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);

// Implementação
public:
	virtual ~CViewTree();

protected:
	DECLARE_MESSAGE_MAP()
};
