
// TrackStudio.cpp: define os comportamentos de classe para o aplicativo.
//

#include "pch.h"
#include "framework.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "TrackStudio.h"
#include "MainFrm.h"

#include "TrackStudioDoc.h"
#include "TrackStudioView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTrackStudioApp

BEGIN_MESSAGE_MAP(CTrackStudioApp, CWinAppEx)
	ON_COMMAND(ID_APP_ABOUT, &CTrackStudioApp::OnAppAbout)
	// Comandos do documento baseados no arquivo padrão
	ON_COMMAND(ID_FILE_NEW, &CWinAppEx::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinAppEx::OnFileOpen)
	// Comando de configuração de impressão padrão
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinAppEx::OnFilePrintSetup)
END_MESSAGE_MAP()


// construção de CTrackStudioApp

CTrackStudioApp::CTrackStudioApp() noexcept
{
	m_bHiColorIcons = TRUE;


	m_nAppLook = 0;
	// suporte ao Gerenciador de Reinicialização
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
#ifdef _MANAGED
	// Se o aplicativo for compilado usando o suporte a Common Language Runtime (/clr):
	//     1) Essa configuração adicional é necessária para o suporte ao Gerenciador de Reinicialização funcionar corretamente.
	//     2) no seu projeto, você deve adicionar uma referência a System.Windows.Forms para compilar.
	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO: substitua a cadeia de caracteres de ID do aplicativo abaixo pela cadeia de caracteres de ID exclusiva. Recomendado
	// o formato de cadeia de caracteres é CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("TrackStudio.AppID.NoVersion"));

	// TODO: adicione código de construção aqui,
	// Coloque todas as inicializações significativas em InitInstance
}

// O único objeto de CTrackStudioApp

CTrackStudioApp theApp;


// inicialização de CTrackStudioApp

BOOL CTrackStudioApp::InitInstance()
{
	// InitCommonControlsEx() será necessário no Windows XP se um aplicativo
	// o manifesto especifica o uso do Comctl32.dll versão 6 ou posterior para habilitar
	// estilos visuais. Caso contrário, a criação de qualquer janela falhará.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Definir esta opção para incluir todas as classes de controle comuns que você deseja usar
	// em seu aplicativo.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinAppEx::InitInstance();


	// Inicializar bibliotecas OLE
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	EnableTaskbarInteraction(FALSE);

	// O AfxInitRichEdit2() é necessário para usar o controle RichEdit
	// AfxInitRichEdit2();

	// Inicialização padrão
	// Se você não estiver usando esses recursos e desejar reduzir o tamanho
	// do seu arquivo executável final, que você deve remover de
	// as rotinas de inicialização específicas que não são necessárias
	// Alterar a chave do Registro sob a qual as configurações são armazenadas
	// TODO: você deve modificar esta cadeia de caracteres para algo apropriado
	// como o nome da sua empresa ou organização
	SetRegistryKey(_T("Aplicativos Locais Gerados pelo AppWizard"));
	LoadStdProfileSettings(4);  // Carregar opções de arquivo INI padrão (incluindo MRU)


	InitContextMenuManager();
	InitShellManager();

	InitKeyboardManager();

	InitTooltipManager();
	CMFCToolTipInfo ttParams;
	ttParams.m_bVislManagerTheme = TRUE;
	theApp.GetTooltipManager()->SetTooltipParams(AFX_TOOLTIP_TYPE_ALL,
		RUNTIME_CLASS(CMFCToolTipCtrl), &ttParams);

	// Registre os modelos de documento do aplicativo. Modelos de documento
	//  serve como a conexão entre os documentos, janelas de quadro e modos de exibição
	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CTrackStudioDoc),
		RUNTIME_CLASS(CMainFrame),       // janela de quadro SDI principal
		RUNTIME_CLASS(CTrackStudioView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);


	// Analisar a linha de comando para comandos shell padrão, DDE, arquivo aberto
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);



	// Comandos de expedição especificados na linha de comando. Retornarão FALSE se
	// aplicativo foi inicializado com /RegServer, /Register, /Unregserver ou /Unregister.
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// A única janela foi inicializada, portanto, mostre-a e atualize-a
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

int CTrackStudioApp::ExitInstance()
{
	//TODO: manipule recursos adicionais que podem ter sido adicionados
	AfxOleTerm(FALSE);

	return CWinAppEx::ExitInstance();
}

// Manipuladores de mensagens de CTrackStudioApp


// Caixa de diálogo CAboutDlg usada para o Sobre o Aplicativo

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg() noexcept;

// Janela de Dados
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Suporte DDX/DDV

// Implementação
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() noexcept : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// Comando de aplicativo para executar a caixa de diálogo
void CTrackStudioApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// métodos de carregamento/salvamento da personalização de CTrackStudioApp

void CTrackStudioApp::PreLoadState()
{
	BOOL bNameValid;
	CString strName;
	bNameValid = strName.LoadString(IDS_EDIT_MENU);
	ASSERT(bNameValid);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EDIT);
	bNameValid = strName.LoadString(IDS_EXPLORER);
	ASSERT(bNameValid);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EXPLORER);
}

void CTrackStudioApp::LoadCustomState()
{
}

void CTrackStudioApp::SaveCustomState()
{
}

// Manipuladores de mensagens de CTrackStudioApp



