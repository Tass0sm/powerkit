/*
# powerdwarf <https://github.com/rodlie/powerdwarf>
# Copyright (c) 2018, Ole-André Rodlie <ole.andre.rodlie@gmail.com> All rights reserved.
#
# Available under the 3-clause BSD license
# See the LICENSE file for full details
*/

#include "login1.h"
#include <QDBusObjectPath>
#include <QDBusConnection>
#include <QDBusMessage>
#include <QDBusReply>
#include <QDBusInterface>

#include "def.h"

bool Login1::hasService()
{
    QDBusInterface iface(LOGIN1_SERVICE,
                         LOGIN1_PATH,
                         LOGIN1_MANAGER,
                         QDBusConnection::systemBus());
    if (iface.isValid()) { return true; }
    return false;
}

bool Login1::canRestart()
{
    QDBusInterface iface(LOGIN1_SERVICE,
                         LOGIN1_PATH,
                         LOGIN1_MANAGER,
                         QDBusConnection::systemBus());
    if (!iface.isValid()) { return false; }
    QDBusMessage reply = iface.call(LOGIN1_CAN_REBOOT);
    if (reply.arguments().first().toString() == "yes") { return true; }
    return false;
}

QString Login1::restart()
{
    QDBusInterface iface(LOGIN1_SERVICE,
                         LOGIN1_PATH,
                         LOGIN1_MANAGER,
                         QDBusConnection::systemBus());
    if (!iface.isValid()) { return QObject::tr("Failed D-Bus connection."); }
    QDBusMessage reply = iface.call(LOGIN1_REBOOT, true);
    return reply.errorMessage();
}

bool Login1::canPowerOff()
{
    QDBusInterface iface(LOGIN1_SERVICE,
                         LOGIN1_PATH,
                         LOGIN1_MANAGER,
                         QDBusConnection::systemBus());
    if (!iface.isValid()) { return false; }
    QDBusMessage reply = iface.call(LOGIN1_CAN_POWEROFF);
    if (reply.arguments().first().toString() == "yes") { return true; }
    return false;
}

QString Login1::poweroff()
{
    QDBusInterface iface(LOGIN1_SERVICE,
                         LOGIN1_PATH,
                         LOGIN1_MANAGER,
                         QDBusConnection::systemBus());
    if (!iface.isValid()) { return QObject::tr("Failed D-Bus connection."); }
    QDBusMessage reply = iface.call(LOGIN1_POWEROFF, true);
    return reply.errorMessage();
}

bool Login1::canSuspend()
{
    QDBusInterface iface(LOGIN1_SERVICE,
                         LOGIN1_PATH,
                         LOGIN1_MANAGER,
                         QDBusConnection::systemBus());
    if (!iface.isValid()) { return false; }
    QDBusMessage reply = iface.call(LOGIN1_CAN_SUSPEND);
    if (reply.arguments().first().toString() == "yes") { return true; }
    return false;
}

QString Login1::suspend()
{
    QDBusInterface iface(LOGIN1_SERVICE,
                         LOGIN1_PATH,
                         LOGIN1_MANAGER,
                         QDBusConnection::systemBus());
    if (!iface.isValid()) { return QObject::tr("Failed D-Bus connection."); }
    QDBusMessage reply = iface.call(LOGIN1_SUSPEND, true);
    return reply.errorMessage();
}

bool Login1::canHibernate()
{
    QDBusInterface iface(LOGIN1_SERVICE,
                         LOGIN1_PATH,
                         LOGIN1_MANAGER,
                         QDBusConnection::systemBus());
    if (!iface.isValid()) { return false; }
    QDBusMessage reply = iface.call(LOGIN1_CAN_HIBERNATE);
    if (reply.arguments().first().toString() == "yes") { return true; }
    return false;
}

QString Login1::hibernate()
{
    QDBusInterface iface(LOGIN1_SERVICE,
                         LOGIN1_PATH,
                         LOGIN1_MANAGER,
                         QDBusConnection::systemBus());
    if (!iface.isValid()) { return QObject::tr("Failed D-Bus connection."); }
    QDBusMessage reply = iface.call(LOGIN1_HIBERNATE, true);
    return reply.errorMessage();
}
