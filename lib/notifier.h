#pragma once

#include <QObject>
#include <QDBusConnection>
#include <QDBusInterface>
#include <QDBusMessage>

class Notifier : public QObject
{
  Q_OBJECT

public:
  explicit Notifier(QObject* parent = nullptr);

  void notify(const QString& title,
	      const QString& msg,
	      const bool critical,
	      const int timeout = 5000);

private:
  QDBusInterface* m_interface;
};
