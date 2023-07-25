
// TrackStudioView.cpp: implementação da classe CTrackStudioView
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS pode ser definido em um projeto ATL implementando a visualização, a miniatura
// e manipuladores de filtro de pesquisa e permite o compartilhamento de código do documento com esse projeto.
#ifndef SHARED_HANDLERS
#include "TrackStudio.h"
#endif

#include <atlimage.h>

#include "TrackStudioDoc.h"
#include "TrackStudioView.h"

#include "Panel.h"
#include "PanelSingleton.h"

#include "sqlite/sqlite3.h"

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
	panel = PanelSingleton::getInstance();
    LoadTrackFromDb();
    LoadMapImg();
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

void CTrackStudioView::OnDraw(CDC* pDC)
{
	CTrackStudioDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

    CRect rectClient;
    GetClientRect(rectClient);
    DrawMapImg(pDC);
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

/// <summary>
/// Loads structured Track DTO objects from SQLite Database into corresponding Panel objects. Call this method to either
/// first draw of GUI track or subsequent updates
/// </summary>
void CTrackStudioView::LoadTrackFromDb()
{
    //Open SQLite database
    sqlite3* db;
    int rc = sqlite3_open("c:\\trackstudio.db", &db);

    if (rc != SQLITE_OK)
    {
        CString prefix = _T("Error opening database: ");
        CString errorMessage = prefix + CString(sqlite3_errmsg(db));
        AfxMessageBox(errorMessage, MB_ICONERROR | MB_OK);
        sqlite3_close(db);
        return;
    }

    // Load all Waypoint table records into a list of Waypoint
    std::list<Waypoint> waypoints;
    const char* waypointQuery = "SELECT dbId, xCoordinate, yCoordinate, locationName FROM Waypoint";
    sqlite3_stmt* stmt;
    rc = sqlite3_prepare_v2(db, waypointQuery, -1, &stmt, nullptr);

    if (rc != SQLITE_OK)
    {
        CString prefix = _T("Error loading Waypoints: ");
        CString errorMessage = prefix + CString(sqlite3_errmsg(db));
        AfxMessageBox(errorMessage, MB_ICONERROR | MB_OK);
        sqlite3_close(db);
        return;
    }
  
    //Table record iteration
    while (sqlite3_step(stmt) == SQLITE_ROW) 
    {
        int dbId = sqlite3_column_int(stmt, 0);
        int xCoordinate = sqlite3_column_int(stmt, 1);
        int yCoordinate = sqlite3_column_int(stmt, 2);
        const char* locationName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));

        Waypoint waypoint(dbId, xCoordinate, yCoordinate, locationName);
         
        waypoints.push_back(waypoint);
    }
    sqlite3_finalize(stmt);

    // Load all Segment table records into a list 
    std::list<Segment> segments;
    // Queries only Segments that match the first TrackD
    const char* segmentQuery = "SELECT s.dbId, s.TrackId, s.startPointId, s.endPointId FROM Segment s WHERE s.trackId = (SELECT MIN(dbId) FROM Track)";
    rc = sqlite3_prepare_v2(db, segmentQuery, -1, &stmt, nullptr);

    if (rc != SQLITE_OK)
    {
        CString prefix = _T("Error loading Segments: ");
        CString errorMessage = prefix + CString(sqlite3_errmsg(db));
        AfxMessageBox(errorMessage, MB_ICONERROR | MB_OK);
        sqlite3_close(db);
        return;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) 
    {
        int dbId = sqlite3_column_int(stmt, 0);
        int startPointId = sqlite3_column_int(stmt, 2);
        int endPointId = sqlite3_column_int(stmt, 3);

        // Find corresponding waypoints for start and end points
        Waypoint startPoint, endPoint;

        for (auto& waypoint : waypoints) 
        {
            if (waypoint.GetId() == startPointId)
            {
                startPoint = waypoint;
            }
            else if (waypoint.GetId() == endPointId)
            {
                endPoint = waypoint;
            }
        }

        Segment segment (dbId, startPoint, endPoint);

        segments.push_back(segment);
    }
    sqlite3_finalize(stmt);

    //TODO: Get the track id from DB
    Track track (1, segments);

    panel->SetTrack(track);
    
    // Close the database connection
    sqlite3_close(db);
}

/// <summary>
/// Load image map from file
/// </summary>
void CTrackStudioView::LoadMapImg()
{
    m_pngImage.Destroy();
    m_pngImage.Load(m_mapFilePath);
}

/// <summary>
/// Draw the Panel map backgroud from loaded m_pngImage
/// </summary>
/// <param name="pDC"></param>
void CTrackStudioView::DrawMapImg(CDC* pDC)
{
    if (m_pngImage.IsNull())
    {
        return;
    }

    // Draw the image using CImage::Draw
    m_pngImage.Draw(pDC->GetSafeHdc(), 0, 0, m_pngImage.GetWidth(), m_pngImage.GetHeight());

    // Get the image size
    int imgWidth = m_pngImage.GetWidth();
    int imgHeight = m_pngImage.GetHeight();

    // Resize the frame window to fit the image size
    CFrameWnd* pFrameWnd = GetParentFrame();
    if (pFrameWnd)
    {
        CRect rectFrame;
        pFrameWnd->GetWindowRect(&rectFrame);

        // Calculate the new window size based on the image size
        int newWidth = imgWidth + GetSystemMetrics(SM_CXSIZEFRAME) * 2 + 260;  // Add frame borders
        int newHeight = imgHeight + GetSystemMetrics(SM_CYSIZEFRAME) * 2 + GetSystemMetrics(SM_CYCAPTION) + 100;

        pFrameWnd->SetWindowPos(nullptr, 0, 0, newWidth, newHeight, SWP_NOMOVE | SWP_NOZORDER);
    }    
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