# Created by and for Qt Creator This file was created for editing the project sources only.
# You may attempt to use it for building too, by modifying this file here.

#TARGET = subtilesapp

QT = core gui widgets

HEADERS = \
   $$PWD/inc/datatypes/STTimecode.h \
   $$PWD/inc/gui/subtilesmainwindow.h

SOURCES = \
   $$PWD/resources/splash/subtiles-splash.png \
   $$PWD/resources/splash/subtiles-splash.svg \
   $$PWD/resources/styles/standard/svgs/checkbox-ticked.svg \
   $$PWD/resources/styles/standard/standard.qss \
   $$PWD/resources/largeimgs.qrc \
   $$PWD/resources/theme.qrc \
   $$PWD/src/datatypes/STTimecode.cpp \
   $$PWD/src/gui/subtilesmainwindow.cpp \
   $$PWD/src/main.cpp \
   $$PWD/ui/subtilesmainwindow.ui \
   $$PWD/subtiles.pro

INCLUDEPATH = \
    $$PWD/inc/datatypes \
    $$PWD/inc/gui

#DEFINES = 

