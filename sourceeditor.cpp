#include "sourceeditor.h"

SourceEditor::SourceEditor(QWidget *parent) :
    QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    QToolBar *toolBar = new QToolBar;
    layout->addWidget(toolBar);

    m_sourceEdit = new QsciScintilla;
    m_sourceEdit->setLexer(new QsciLexerPerl(m_sourceEdit)); // only Perl for now :(
    m_sourceEdit->setAutoIndent(true);
    m_sourceEdit->setMarginLineNumbers(QsciScintilla::NumberMargin, true);
    m_sourceEdit->setMarginWidth(QsciScintilla::NumberMargin, "3 ");
    m_marginWidth = 1;
    connect(m_sourceEdit, SIGNAL(linesChanged()), this, SLOT(linesCountChanged()));
    layout->addWidget(m_sourceEdit);
}

void SourceEditor::linesCountChanged()
{
    int marginWidth = qCeil(qLn(m_sourceEdit->lines()) / qLn(10) + 0.000001);
    if (marginWidth == 0) {
        marginWidth++;
    }

    if (marginWidth != m_marginWidth) {
        m_marginWidth = marginWidth;
        m_sourceEdit->setMarginWidth(QsciScintilla::NumberMargin, QString(marginWidth, '3') + ' ');
    }
}
