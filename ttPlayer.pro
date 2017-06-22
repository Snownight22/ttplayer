#-------------------------------------------------
#
# Project created by QtCreator 2017-06-19T13:42:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ttPlayer
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        ttplayermainwindow.cpp \
    ttplayerwidget.cpp \
    ttplayerthread.cpp \
    ttplayermainwidget.cpp \
    ttplayerslider.cpp \
    ttplayermsgbox.cpp

HEADERS += \
        ttplayermainwindow.h \
    ttplayerwidget.h \
    ttplayerthread.h \
    ttplayermainwidget.h \
    ttplayerslider.h \
    ttplayermsgbox.h

INCLUDEPATH += $$PWD/include/ffmpeg

LIBS += $$PWD/libs/ffmpeg/avcodec.lib \
        $$PWD/libs/ffmpeg/avdevice.lib \
        $$PWD/libs/ffmpeg/avfilter.lib \
        $$PWD/libs/ffmpeg/avformat.lib \
        $$PWD/libs/ffmpeg/avutil.lib \
        $$PWD/libs/ffmpeg/postproc.lib \
        $$PWD/libs/ffmpeg/swresample.lib \
        $$PWD/libs/ffmpeg/swscale.lib
        #$$PWD/libs/SDL2/lib/x86/SDL2.lib
