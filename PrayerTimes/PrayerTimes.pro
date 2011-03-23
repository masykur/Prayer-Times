#-------------------------------------------------
#
# Project created by QtCreator 2011-03-23T22:04:59
#
#-------------------------------------------------

QT       += core gui

TARGET = PrayerTimes
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    calculator.cpp

HEADERS  += mainwindow.h \
    calculator.h

FORMS    += mainwindow.ui

CONFIG += mobility
MOBILITY = 

symbian {
    TARGET.UID3 = 0xe102f736
    # TARGET.CAPABILITY += 
    TARGET.EPOCSTACKSIZE = 0x14000
    TARGET.EPOCHEAPSIZE = 0x020000 0x800000
}
