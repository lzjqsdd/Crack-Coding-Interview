QT += core
QT -= gui

TARGET = opencvDemo
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    demoimage.cpp


unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += opencv

HEADERS += \
    demoimage.h
