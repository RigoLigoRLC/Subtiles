#-------------------------------------------------
#
# Project created by QtCreator 2020-09-13T13:38:18
#
#-------------------------------------------------

QT       += core gui svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = subtilesapp
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    src/app/subtilesmainframe.cpp \
    src/datatypes/STTimecode.cpp \
        src/gui/subtilesmainwindow.cpp \
        src/main.cpp

HEADERS += \
        inc/app/subtilesabstractguest.h \
        inc/app/subtileshost.h \
        inc/app/subtilesmainframe.h \
        inc/datatypes/STTimecode.h \
        inc/gui/subtilesmainwindow.h

FORMS += \
        ui/subtilesmainwindow.ui

INCLUDEPATH += \
        inc \
        inc/datatypes

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources/largeimgs.qrc \
    resources/theme.qrc