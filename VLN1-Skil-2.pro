QT += core
QT -= gui
QT += sql

CONFIG += c++11

TARGET = VLN1-Skil-2
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    consoleui.cpp \
    servicelayer.cpp

HEADERS += \
    consoleui.h \
    servicelayer.h
