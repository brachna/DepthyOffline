#include "mainwindow.h"

MainWindow::MainWindow( QWidget* parent ) : QMainWindow( parent )
{
    setWindowTitle( QStringLiteral( "DepthyOffline 160909" ) );
    QWidget* centralWidget = new QWidget( this );
    setCentralWidget( centralWidget );

    QWebEngineView* webView = new QWebEngineView( this );
    DWebPage* dPage = new DWebPage( webView );
    webView->setPage( dPage );

    QHBoxLayout* hBoxLayout = new QHBoxLayout( centralWidget );
    hBoxLayout->setContentsMargins( 0, 0, 0, 0 );
    hBoxLayout->setSpacing( 0 );
    hBoxLayout->addWidget( webView );
    centralWidget->setLayout( hBoxLayout );

    resize( QDesktopWidget().availableGeometry().size() * 0.8 );

    webView->load( QUrl( QStringLiteral( "qrc:/rsc/depthy/index.html" ) ) );
}

MainWindow::~MainWindow()
{

}
