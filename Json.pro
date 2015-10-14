#-------------------------------------------------
#
# Project created by QtCreator 2015-09-30T14:21:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Json
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    datajson.cpp \
    settingpreferencias.cpp \
    dialogpre.cpp

HEADERS  += mainwindow.h \
    datajson.h \
    settingpreferencias.h \
    dialogpre.h

FORMS    += mainwindow.ui \
    dialogpre.ui
