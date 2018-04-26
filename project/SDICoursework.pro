QT       += core gui widgets
TARGET = SDICoursework
DESTDIR = ../bin
DEFINES += QT_DEPRECATED_WARNINGS
TEMPLATE = app
CONFIG += c++11

OBJECTS_DIR += ../build

SOURCES += \
        ../src/main.cpp \
        ../src/mainwindow.cpp \
        ../src/controller.cpp \
        ../src/project.cpp \
	../src/material.cpp

INCLUDEPATH += ../include

DEPENDPATH += ../include

HEADERS += \
        ../include/mainwindow.h \
        ../include/controller.h \
        ../include/project.h \
	../include/material.h

FORMS += \
        ../forms/mainwindow.ui
