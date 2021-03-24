QT       += core gui svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = subtilesapp
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++11

SOURCES += \
    src/app/mainframe.cpp \
    src/datatypes/STTimecode.cpp \
    src/guests/uistyleshow.cpp \
    src/gui/mainwindow.cpp \
        src/main.cpp

HEADERS += \
        inc/app/abstractguest.h \
        inc/app/host.h \
        inc/app/mainframe.h \
        inc/datatypes/STTimecode.h \
        inc/guests/uistyleshow.h \
        inc/gui/mainwindow.h

FORMS += \
    ui/guest_uistyleshow.ui

INCLUDEPATH += \
        inc \
        inc/datatypes \
        src/thirdparty/ads/src

RESOURCES += \
    resources/largeimgs.qrc \
    resources/theme.qrc



# From ADS "simple" example
LIBS += -L.
CONFIG(debug, debug|release){
    win32 {
        LIBS += -lqtadvanceddockingd
    }
    else:mac {
        LIBS += -lqtadvanceddocking_debug
    }
    else {
        LIBS += -lqtadvanceddocking
    }
}
else{
    LIBS += -lqtadvanceddocking
}
