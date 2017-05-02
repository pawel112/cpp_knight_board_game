#-------------------------------------------------
#
# Project created by QtCreator 2016-08-25T01:15:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = knight
TEMPLATE = app

SOURCES += main.cpp\
    validation.cpp \
    tile.cpp \
    settings.cpp \
    language.cpp \
    movement.cpp \
    choose_movement.cpp \
    about_window.cpp \
    choose_language.cpp \
    rules_window.cpp \
    main_window.cpp

HEADERS  += \
    validation.h \
    tile.h \
    settings.h \
    language.h \
    compare_movements.h \
    choose_movement.h \
    movement.h \
    about_window.h \
    choose_language.h \
    rules_window.h \
    main_window.h

FORMS    += \
    about_window.ui \
    choose_language.ui \
    rules_window.ui \
    main_window.ui

RESOURCES += \
    images.qrc

DISTFILES += \
    TO_DO.txt

win32: RC_ICONS = Images\icon.ico
VERSION = 1.0
QMAKE_TARGET_COMPANY = Pawel Roszatycki
QMAKE_TARGET_PRODUCT = Game Knight
QMAKE_TARGET_DESCRIPTION = Game Knight

QT += xml svg
QTPLUGIN += qsvg
QTPLUGIN += qsvg qsvgicon
