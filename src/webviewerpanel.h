#ifndef WEBVIEWERPANEL_H
#define WEBVIEWERPANEL_H

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QToolButton>
#include <QToolBar>
#include <QComboBox>
#include <QLineEdit>
#include <QRegExp>
#include "webviewer.h"

#include <QDebug>

class WebViewerPanel : public QWidget
{
    Q_OBJECT
public:
    explicit WebViewerPanel(QWidget *parent = 0);
    WebViewer *viewer();

protected:
    WebViewer *m_viewer;
    QComboBox *m_urlEdit;
    QToolButton *m_actButton;

protected slots:
    void changeUrlEdit(const QUrl &newUrl);
    void loadUrl(QString url);
    void loadUrl(const QUrl &url);
    void startLoading();
    void setActButtonStop();
    void setActButtonStart();
};

#endif // WEBVIEWERPANEL_H
