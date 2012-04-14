#ifndef WEBVIEWERPANEL_H
#define WEBVIEWERPANEL_H

#include <QVBoxLayout>
#include <QToolBar>
#include "webviewer.h"

class WebViewerPanel : public QWidget
{
    Q_OBJECT
public:
    explicit WebViewerPanel(QWidget *parent = 0);

protected:
    WebViewer *m_viewer;
};

#endif // WEBVIEWERPANEL_H
