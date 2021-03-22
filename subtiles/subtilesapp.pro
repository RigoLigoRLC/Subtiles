QT       += core gui svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = subtilesapp
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++11

SOURCES += \
    src/app/subtilesmainframe.cpp \
    src/datatypes/STTimecode.cpp \
    src/guests/stguestuistyleshow.cpp \
        src/gui/subtilesmainwindow.cpp \
        src/main.cpp

HEADERS += \
        inc/app/subtilesabstractguest.h \
        inc/app/subtileshost.h \
        inc/app/subtilesmainframe.h \
        inc/datatypes/STTimecode.h \
        inc/guests/stguestuistyleshow.h \
        inc/gui/subtilesmainwindow.h

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
