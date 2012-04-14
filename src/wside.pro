#-------------------------------------------------
#
# Project created by QtCreator 2012-04-09T22:43:03
#
#-------------------------------------------------

QT       += core gui webkit
LIBS     += -lqscintilla2

TARGET = wside
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    sourceeditor.cpp \
    webviewer.cpp \
    sourceeditorpanel.cpp \
    webviewerpanel.cpp

HEADERS  += mainwindow.h \
    sourceeditor.h \
    webviewer.h \
    sourceeditorpanel.h \
    webviewerpanel.h

FORMS    += mainwindow.ui

RESOURCES += \
    img.qrc
