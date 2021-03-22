#-------------------------------------------------
#
# Project created by QtCreator 2020-09-13T13:38:18
#
#-------------------------------------------------

TARGET = subtiles
TEMPLATE = subdirs

SUBDIRS += \
    subtiles/subtilesapp.pro \
    subtiles/unittest/datatypes_test \
    subtiles/src/thirdparty/ads/src

adslib.subdir = subtiles/src/ads/src
app.file = subtiles/subtilesapp.pro
app.depends = adslib
