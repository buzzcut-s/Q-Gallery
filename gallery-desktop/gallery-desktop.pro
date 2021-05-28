QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    src/AlbumListWidget.cpp \
    src/main.cpp \
    src/MainWindow.cpp

HEADERS += \
    include/AlbumListWidget.h \
    include/MainWindow.h

FORMS += \
    forms/AlbumListWidget.ui \
    forms/MainWindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../gallery-core/release/ -lgallery-core
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../gallery-core/debug/ -lgallery-core
else:unix: LIBS += -L$$OUT_PWD/../gallery-core/ -lgallery-core

INCLUDEPATH += $$PWD/../gallery-core
DEPENDPATH += $$PWD/../gallery-core

RESOURCES += \
    res/resource.qrc
