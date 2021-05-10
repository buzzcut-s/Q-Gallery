QT -= gui
QT += sql

TEMPLATE = lib
DEFINES += GALLERYCORE_LIBRARY

CONFIG += c++17

SOURCES += \
    Album.cpp \
    AlbumDao.cpp \
    DatabaseManager.cpp \
    Picture.cpp

HEADERS += \
    AlbumDao.h \
    DatabaseManager.h \
    Picture.h \
    gallery-core_global.h \
    Album.h
