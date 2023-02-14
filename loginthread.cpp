#include "loginthread.h"
#include <QDebug>


LoginThread::LoginThread(QString pass)
{
    password = pass;
}



void LoginThread::run()
{

    if (password == "111")
    {
        auto usr = QSharedPointer<User>::create(USER_LEVEL::TECHNIC);
        emit moveNewUser(usr);
    }
    else if (password == "222")
    {
        auto usr = QSharedPointer<User>::create(USER_LEVEL::ENGINEER);
        emit moveNewUser(usr);
    }
    else
    {
        auto  usr = QSharedPointer<User>::create(USER_LEVEL::OPERATOR);
        emit moveNewUser(usr);
    }


}
