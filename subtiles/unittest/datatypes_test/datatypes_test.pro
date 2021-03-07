QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_datatypes_test.cpp

INCLUDEPATH += ../../inc/datatypes

SOURCES += ../../src/datatypes/STTimecode.cpp
