#include "dwebpage.h"

DWebPage::DWebPage( QObject* parent ) : QWebEnginePage( parent )
{
    appSettings = new QSettings(QCoreApplication::applicationDirPath() + QStringLiteral("/settings.ini"),
                                QSettings::IniFormat);
    mimeDatabase = new QMimeDatabase();

    QObject::connect( profile(), &QWebEngineProfile::downloadRequested, this, &DWebPage::downloadFile );
}

QStringList DWebPage::chooseFiles( FileSelectionMode mode, const QStringList &oldFiles, const QStringList &acceptedMimeTypes ){
    Q_UNUSED(mode);
    Q_UNUSED(oldFiles);
    Q_UNUSED(acceptedMimeTypes);

    QString lastUsedPath = appSettings->value("last_used_path").toString();
    QDir directory;
    if ( !directory.exists( lastUsedPath ) ){
        lastUsedPath = QStandardPaths::standardLocations( QStandardPaths::DownloadLocation ).first();
        appSettings->setValue( QStringLiteral("last_used_path"), lastUsedPath );
    }

    // default implementation doesn't use mime types so we use QFileDialog::getOpenFileName()
    QString filename = QFileDialog::getOpenFileName(Q_NULLPTR,
                                                    QStringLiteral(""),
                                                    lastUsedPath,
                                                    QStringLiteral("Images (*jpeg *jpg *png)"));
    QStringList filenameList;
    // if nothing is selected then it's correct to return empty list instead of a list with ""
    if ( filename != QStringLiteral("") ){
        filenameList.append( filename );
        saveName = QFileInfo( filename ).completeBaseName();
        qDebug() << "filename: " << filename;
        qDebug() << "saveName: " << saveName;
        appSettings->setValue( QStringLiteral("last_used_path"), QFileInfo( filename ).absolutePath() );
    }
    return filenameList;
}

void DWebPage::downloadFile( QWebEngineDownloadItem* download ){
    QString newPath = appSettings->value("last_used_path").toString() + QStringLiteral("/") + saveName;
    QString mimeType = download->mimeType();
    QString extFilter;
    if ( mimeType == QStringLiteral("image/gif") ){
        newPath += QStringLiteral(".gif");
        extFilter = QStringLiteral("Images (*gif)");
    }
    else if ( mimeType == QStringLiteral("image/jpeg") ){
        newPath += QStringLiteral(".jpg");
        extFilter = QStringLiteral("Images (*jpg)");
    }
    else if ( mimeType == QStringLiteral("image/png") ){
        newPath += QStringLiteral(".png");
        extFilter = QStringLiteral("Images (*png)");
    }
    else if ( mimeType == QStringLiteral("video/webm") ){
        newPath += QStringLiteral(".webm");
        extFilter = QStringLiteral("Videos (*webm)");
    }
    download->setPath( newPath );

    QString filename = QFileDialog::getSaveFileName(Q_NULLPTR,
                                                    QStringLiteral(""),
                                                    newPath,
                                                    extFilter);

    if ( filename != QStringLiteral( "" ) ){
        download->setPath( filename );
        appSettings->setValue("last_used_path", QFileInfo( filename ).absolutePath());
        download->accept();
    }
    else{
        download->cancel();
    }
}
