#ifndef WEBVIEWER_H
#define WEBVIEWER_H

#include <QWebView>

class WebViewer : public QWebView
{
    Q_OBJECT
public:
    explicit WebViewer(QWidget *parent = 0);
};

#endif // WEBVIEWER_H
