QT += core
QT -= gui
QT += core sql

CONFIG += c++11

TARGET = VLN1-Skil-2
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    consoleui.cpp \
    servicelayer.cpp \
    persons.cpp \
    computer.cpp \
    validation.cpp

HEADERS += \
    consoleui.h \
    servicelayer.h \
    persons.h \
    computer.h \
    validation.h
