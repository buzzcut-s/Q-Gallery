QT -= gui
QT += sql

TEMPLATE = lib
DEFINES += GALLERYCORE_LIBRARY

CONFIG += c++17

SOURCES += \
    Album.cpp \
    Picture.cpp

HEADERS += \
    Picture.h \
    gallery-core_global.h \
    Album.h
