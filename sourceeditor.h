#ifndef SOURCEEDITOR_H
#define SOURCEEDITOR_H

#include <QWidget>
#include <QVBoxLayout>
#include <QToolBar>
#include <QFont>
#include <QtCore/qmath.h>
#include <Qsci/qsciscintilla.h>
#include <Qsci/qscilexerperl.h>

#include <QDebug>

class SourceEditor : public QWidget
{
    Q_OBJECT
public:
    explicit SourceEditor(QWidget *parent = 0);

protected:
    QsciScintilla *m_sourceEdit;
    int m_marginWidth;

protected slots:
    void linesCountChanged();
};

#endif // SOURCEEDITOR_H
