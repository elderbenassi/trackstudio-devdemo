
// TrackStudio.h: arquivo de cabeçalho principal para o aplicativo TrackStudio
//
#pragma once

#ifndef __AFXWIN_H__
	#error "inclua 'pch.h' antes de incluir este arquivo para PCH"
#endif

#include "resource.h"       // símbolos principais


// CTrackStudioApp:
// Consulte TrackStudio.cpp para a implementação desta classe
//

class CTrackStudioApp : public CWinAppEx
{
public:
	CTrackStudioApp() noexcept;


// Substitui
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementação
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CTrackStudioApp theApp;
