#
# PowerDwarf <https://github.com/rodlie/powerdwarf>
# Copyright (c) 2018, Ole-André Rodlie <ole.andre.rodlie@gmail.com> All rights reserved.
#
# Available under the 3-clause BSD license
# See the LICENSE file for full details
#
#

QT += core gui dbus
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = powerdwarf
TEMPLATE = app

SOURCES += main.cpp systray.cpp
HEADERS += systray.h
RESOURCES += ../$${TARGET}.qrc
LIBS += -L../lib -lPowerDwarf
INCLUDEPATH += ../lib

include(../powerdwarf.pri)

target.path = $${PREFIX}/bin
target_desktop.path = $${XDGDIR}/autostart
target_desktop.files = $${TARGET}.desktop
target_docs.path = $${DOCDIR}/$${TARGET}-$${VERSION}
target_docs.files = ../LICENSE ../README.md
INSTALLS += target target_desktop target_docs
