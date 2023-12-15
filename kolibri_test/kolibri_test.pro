QT += testlib widgets
QT += core gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

HEADERS += ../kolibri/calculator.h

SOURCES +=  tst_calculator.cpp ../kolibri/calculator.cpp \






