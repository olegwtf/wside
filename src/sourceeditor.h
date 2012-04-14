#ifndef SOURCEEDITOR_H
#define SOURCEEDITOR_H

#include <QtCore/qmath.h>
#include <Qsci/qsciscintilla.h>
#include <Qsci/qscilexerperl.h>

#include <QDebug>

class SourceEditor : public QsciScintilla
{
    Q_OBJECT
public:
    explicit SourceEditor(QWidget *parent = 0);

protected:
    int m_marginWidth;

protected slots:
    void linesCountChanged();
};

#endif // SOURCEEDITOR_H
