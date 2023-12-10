TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
#CONFIG -= qt

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
        Calculator.cpp \
        main.cpp \
        mainwindow.cpp

HEADERS += \
  Calculator.h \
  mainwindow.h

FORMS += \
    mainwindow.ui
