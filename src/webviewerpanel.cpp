#include "webviewerpanel.h"

WebViewerPanel::WebViewerPanel(QWidget *parent) :
    QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    QToolBar *toolBar = new QToolBar;
    layout->addWidget(toolBar);

    m_urlEdit = new QComboBox;
    m_urlEdit->setEditable(true);
    m_urlEdit->addItem("");
    connect(m_urlEdit, SIGNAL(activated(QString)), this, SLOT(loadUrl(QString)));
    layout->addWidget(m_urlEdit);

    m_viewer = new WebViewer;
    QPalette palette;
    palette.setColor(QPalette::Window, this->palette().base().color());
    m_viewer->setPalette(palette);
    m_viewer->setAutoFillBackground(true);
    connect(m_viewer, SIGNAL(urlChanged(QUrl)), this, SLOT(changeUrlEdit(QUrl)));
    layout->addWidget(m_viewer);
}

WebViewer *WebViewerPanel::viewer()
{
    return m_viewer;
}

void WebViewerPanel::changeUrlEdit(const QUrl &newUrl)
{
    m_urlEdit->setItemText(0, newUrl.toString());
    m_urlEdit->setCurrentIndex(0);
    m_urlEdit->lineEdit()->setCursorPosition(0);
}

void WebViewerPanel::loadUrl(QString url)
{
    if (url.indexOf(QRegExp("^https?://")) != 0) {
        url.prepend("http://");
    }

    m_viewer->load(QUrl(url));
}
