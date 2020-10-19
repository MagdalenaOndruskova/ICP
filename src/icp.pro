

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++1z

TARGET = mhdsimulator
TEMPLATE = app


DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    src/main.cpp \
    src/mainwindow.cpp \
    src/mycoordinate.cpp \
    src/myline.cpp \
    src/myscene.cpp \
    src/myshow.cpp \
    src/mystop.cpp \
    src/mystreet.cpp \
    src/myvehicle.cpp

HEADERS += \
    src/mainwindow.h \
    src/mycoordinate.h \
    src/myline.h \
    src/myscene.h \
    src/myshow.h \
    src/mystop.h \
    src/mystreet.h \
    src/myvehicle.h

FORMS += \
    src/gui/mainwindow.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    examples/myRes.qrc





