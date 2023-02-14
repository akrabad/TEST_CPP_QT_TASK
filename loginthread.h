#ifndef LOGINTHREAD_H
#define LOGINTHREAD_H

#include <QThread>

#include <QString>

#include "user.h"

class LoginThread : public QThread
{
    Q_OBJECT
public:
    explicit LoginThread(QString);

public slots:
    void run();

signals:
    void moveNewUser(QSharedPointer<User>);
private:
    QString password;

};

#endif // LOGINTHREAD_H
