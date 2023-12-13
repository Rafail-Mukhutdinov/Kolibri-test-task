TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
#CONFIG -= qt

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
        Calculator.cpp \
        conditioncontroller.cpp \
        directorymanager.cpp \
        main.cpp \
        mainwindow.cpp

HEADERS += \
  Calculator.h \
  conditioncontroller.h \
  directorymanager.h \
  mainwindow.h \
  paramformmain.h

FORMS += \
    mainwindow.ui
