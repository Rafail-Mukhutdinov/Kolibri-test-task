TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
#CONFIG -= qt

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
        conditioncontroller.cpp \
        directorymanager.cpp \
        main.cpp \
        mainwindow.cpp \
        textconverter.cpp

HEADERS += \
  conditioncontroller.h \
  directorymanager.h \
  mainwindow.h \
  paramformmain.h \
  textconverter.h

FORMS += \
    mainwindow.ui
