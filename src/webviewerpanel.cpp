#include "webviewerpanel.h"

WebViewerPanel::WebViewerPanel(QWidget *parent) :
    QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    QToolBar *toolBar = new QToolBar;
    layout->addWidget(toolBar);

    m_viewer = new WebViewer;
    layout->addWidget(m_viewer);
}
