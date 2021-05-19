QT -= gui
QT += sql

TEMPLATE = lib
DEFINES += GALLERYCORE_LIBRARY

CONFIG += c++17

SOURCES += \
    src/AlbumModel.cpp \
    src/Album.cpp \
    src/AlbumDao.cpp \
    src/DatabaseManager.cpp \
    src/Picture.cpp \
    src/PictureDao.cpp

HEADERS += \
    include/AlbumModel.h \
    include/AlbumDao.h \
    include/DatabaseManager.h \
    include/Picture.h \
    include/PictureDao.h \
    include/gallery-core_global.h \
    include/Album.h
