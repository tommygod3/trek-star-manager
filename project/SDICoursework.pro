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
	../src/material.cpp \
	../src/logger.cpp \ 
	../src/sbst.cpp

INCLUDEPATH += ../include

DEPENDPATH += ../include

HEADERS += \
        ../include/mainwindow.h \
        ../include/controller.h \
        ../include/project.h \
	../include/material.h \
	../include/logger.h \
	../include/sbst.h

FORMS += \
        ../forms/mainwindow.ui
