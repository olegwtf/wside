#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSplitter>
#include "sourceeditorpanel.h"
#include "webviewerpanel.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    SourceEditorPanel *m_sourceEditorPanel;
    WebViewerPanel *m_webViwerPanel;
    QSplitter *m_splitter;
};

#endif // MAINWINDOW_H
