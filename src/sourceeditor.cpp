#include "sourceeditor.h"

SourceEditor::SourceEditor(QWidget *parent) :
    QsciScintilla(parent)
{
    setLexer(new QsciLexerPerl(this)); // only Perl for now :(
    setAutoIndent(true);
    setMarginLineNumbers(NumberMargin, true);
    setMarginWidth(NumberMargin, "3 ");
    setBraceMatching(SloppyBraceMatch);
    setUtf8(true);

    m_marginWidth = 1;
    connect(this, SIGNAL(linesChanged()), this, SLOT(linesCountChanged()));
}

void SourceEditor::linesCountChanged()
{
    int marginWidth = qCeil( qLn( lines() ) / qLn(10) + 0.000001 );

    if (marginWidth != m_marginWidth) {
        m_marginWidth = marginWidth;
        setMarginWidth(NumberMargin, QString(marginWidth, '3') + ' ');
    }
}
