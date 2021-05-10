QT -= gui
QT += sql

TEMPLATE = lib
DEFINES += GALLERYCORE_LIBRARY

CONFIG += c++17

SOURCES += \
    Album.cpp

HEADERS += \
    gallery-core_global.h \
    Album.h
