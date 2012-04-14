#include "sourceeditorpanel.h"

SourceEditorPanel::SourceEditorPanel(QWidget *parent) :
    QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    QToolBar *toolBar = new QToolBar;
    layout->addWidget(toolBar);

    m_editor = new SourceEditor;
    layout->addWidget(m_editor);
}

SourceEditor *SourceEditorPanel::editor()
{
    return m_editor;
}
