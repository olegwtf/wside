#ifndef SOURCEEDITORPANEL_H
#define SOURCEEDITORPANEL_H

#include <QVBoxLayout>
#include <QToolBar>
#include "sourceeditor.h"

class SourceEditorPanel : public QWidget
{
    Q_OBJECT
public:
    explicit SourceEditorPanel(QWidget *parent = 0);
    SourceEditor *editor();

protected:
    SourceEditor *m_editor;
};

#endif // SOURCEEDITORPANEL_H
