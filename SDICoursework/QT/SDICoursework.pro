QT       += core gui widgets
TARGET = SDICoursework
DESTDIR = ../bin
DEFINES += QT_DEPRECATED_WARNINGS
TEMPLATE = app
CONFIG += c++11

OBJECTS_DIR += ../build

SOURCES += \
        ../src/main.cpp \
        ../src/mainwindow.cpp

INCLUDEPATH += ../include

DEPENDPATH += ../include

HEADERS += \
        ../include/mainwindow.h

FORMS += \
        ../forms/mainwindow.ui
