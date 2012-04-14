#include "webviewerpanel.h"

WebViewerPanel::WebViewerPanel(QWidget *parent) :
    QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    QToolBar *toolBar = new QToolBar;
    layout->addWidget(toolBar);

    QHBoxLayout *hbox = new QHBoxLayout;
    layout->addLayout(hbox);

    m_urlEdit = new QComboBox;
    m_urlEdit->setEditable(true);
    m_urlEdit->addItem("");
    connect(m_urlEdit, SIGNAL(activated(QString)), this, SLOT(loadUrl(QString)));
    hbox->addWidget(m_urlEdit);

    m_actButton = new QToolButton;
    m_actButton->setIconSize(QSize(16,16));
    m_actButton->setAutoRaise(true);
    setActButtonStart();
    hbox->addWidget(m_actButton);

    m_viewer = new WebViewer;
    QPalette palette;
    palette.setColor(QPalette::Window, this->palette().base().color());
    m_viewer->setPalette(palette);
    m_viewer->setAutoFillBackground(true);
    m_viewer->page()->setLinkDelegationPolicy(QWebPage::DelegateAllLinks);
    connect(m_viewer, SIGNAL(urlChanged(QUrl)), this, SLOT(changeUrlEdit(QUrl)));
    connect(m_viewer, SIGNAL(loadStarted()), this, SLOT(setActButtonStop()));
    connect(m_viewer, SIGNAL(loadFinished(bool)), this, SLOT(setActButtonStart()));
    connect(m_viewer, SIGNAL(linkClicked(QUrl)), this, SLOT(loadUrl(QUrl)));
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
    m_viewer->setFocus();
}

void WebViewerPanel::loadUrl(QString url)
{
    if (url.length() == 0) {
        return;
    }

    if (url.indexOf(QRegExp("^https?://")) != 0) {
        url.prepend("http://");
    }

    loadUrl(QUrl(url));
}

void WebViewerPanel::loadUrl(const QUrl &url)
{
    m_viewer->load(url);
}

void WebViewerPanel::startLoading()
{
    loadUrl(m_urlEdit->currentText());
}

void WebViewerPanel::setActButtonStop()
{
    m_actButton->setIcon(QIcon(":/img/stop.png"));
    m_actButton->disconnect();
    connect(m_actButton, SIGNAL(clicked()), m_viewer, SLOT(stop()));
}

void WebViewerPanel::setActButtonStart()
{
    m_actButton->setIcon(QIcon(":/img/enter.png"));
    m_actButton->disconnect();
    connect(m_actButton, SIGNAL(clicked()), this, SLOT(startLoading()));
}
