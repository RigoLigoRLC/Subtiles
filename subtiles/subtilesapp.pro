QT       += core gui svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = subtilesapp
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++11

SOURCES += \
    src/app/commander.cpp \
    src/app/host.cpp \
    src/app/mainframe.cpp \
    src/datatypes/STDialog.cpp \
    src/datatypes/STTimecode.cpp \
    src/datatypes/STTrack.cpp \
    src/guests/timeline.cpp \
    src/guests/uistyleshow.cpp \
    src/gui/dialogtile.cpp \
    src/gui/mainwindow.cpp \
    src/gui/timelineview.cpp \
        src/main.cpp

HEADERS += \
        inc/app/abstractguest.h \
        inc/app/commander.h \
        inc/app/host.h \
        inc/app/mainframe.h \
        inc/datatypes/STDialog.h \
        inc/datatypes/STTimecode.h \
        inc/datatypes/STTrack.h \
        inc/guests/timeline.h \
        inc/guests/uistyleshow.h \
        inc/gui/dialogtile.h \
        inc/gui/mainwindow.h \
        inc/gui/timelineview.h

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
