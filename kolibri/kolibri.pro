TEMPLATE = app
CONFIG += console c++17 moc
CONFIG -= app_bundle
#CONFIG -= qt

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
        conditioncontroller.cpp \
        directorymanager.cpp \
        hexadecimalxorprocessor.cpp \
        main.cpp \
        mainwindow.cpp \
        textconverter.cpp

HEADERS += \
  conditioncontroller.h \
  directorymanager.h \
  hexadecimalxorprocessor.h \
  mainwindow.h \
  paramformmain.h \
  textconverter.h

FORMS += \
    mainwindow.ui
