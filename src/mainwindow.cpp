#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowState(Qt::WindowMaximized);

    m_splitter = new QSplitter(Qt::Horizontal);
    centralWidget()->layout()->addWidget(m_splitter);

    m_sourceEditorPanel = new SourceEditorPanel;
    m_splitter->addWidget(m_sourceEditorPanel);

    m_webViwerPanel = new WebViewerPanel;
    m_splitter->addWidget(m_webViwerPanel);

    QList<int> sizes;
    sizes.append(width() / 2.5);
    sizes.append(width() - sizes[0]);
    m_splitter->setSizes(sizes);
}

MainWindow::~MainWindow()
{
    delete ui;
}
