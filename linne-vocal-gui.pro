#-------------------------------------------------
#
# Project created by QtCreator 2015-04-26T15:43:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = linne-vocal-gui
TEMPLATE = app

QMAKE_CXXFLAGS += "-std=c++11"
LIBS += -lsxdb

SOURCES += main.cpp\
        mainwindow.cpp \
    TermainalOutput.cpp

HEADERS  += mainwindow.h \
    TermainalOutput.h

FORMS    += mainwindow.ui \
    TermainalOutput.ui
