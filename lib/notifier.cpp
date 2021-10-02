#include "notifier.h"

Notifier::Notifier(QObject* parent)
  : QObject(parent)
  , m_interface(nullptr)
{
  m_interface =
    new QDBusInterface(QStringLiteral("org.freedesktop.Notifications"),
		       QStringLiteral("/org/freedesktop/Notifications"),
		       QStringLiteral("org.freedesktop.Notifications"),
		       QDBusConnection::sessionBus(),
		       this);
}

void Notifier::notify(const QString& title,
		      const QString& msg,
		      const bool critical,
		      const int timeout)
{
  QList<QVariant> args;

  args << "powerkit"                   // appname
       << static_cast<unsigned int>(0) // id
       << "powerkit"                   // icon
       << title                        // summary
       << msg                          // body
       << QStringList()                // actions
       << QVariantMap()                // hints
       << timeout;                     // timeout

  m_interface->callWithArgumentList(QDBus::AutoDetect,
				    QStringLiteral("Notify"),
				    args);
}
