#ifndef DWEBPAGE_H
#define DWEBPAGE_H

#include <QtWebEngineWidgets>

class DWebPage : public QWebEnginePage
{
    Q_OBJECT
public:
    explicit DWebPage( QObject* parent = 0 );

    QSettings* appSettings;
    QMimeDatabase* mimeDatabase;
    QString saveName;

    QStringList chooseFiles( FileSelectionMode mode, const QStringList &oldFiles, const QStringList &acceptedMimeTypes );

signals:

public slots:
    void downloadFile( QWebEngineDownloadItem* download );
};

#endif // DWEBPAGE_H
