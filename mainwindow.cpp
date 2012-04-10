#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowState(Qt::WindowMaximized);

    m_srcEditor = new SourceEditor;
    ui->centralWidget->layout()->addWidget(m_srcEditor);
}

MainWindow::~MainWindow()
{
    delete ui;
}
