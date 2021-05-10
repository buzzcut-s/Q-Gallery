QT -= gui
QT += sql

TEMPLATE = lib
DEFINES += GALLERYCORE_LIBRARY

CONFIG += c++17

SOURCES += \
    Album.cpp \
    DatabaseManager.cpp \
    Picture.cpp

HEADERS += \
    DatabaseManager.h \
    Picture.h \
    gallery-core_global.h \
    Album.h
