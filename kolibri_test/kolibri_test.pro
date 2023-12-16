QT += testlib widgets
QT += core gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

HEADERS +=      autotest.h \
                ../kolibri/textconverter.h \
                ../kolibri/directorymanager.h


SOURCES +=      tst_main.cpp \
                tst_directorymanager.cpp    ../kolibri/directorymanager.cpp \
                tst_textconverter.cpp       ../kolibri/textconverter.cpp






