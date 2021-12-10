#ifndef USERREPOSITORY_H
#define USERREPOSITORY_H

#include <QJsonArray>
#include <QCoreApplication>

class UserRepository
{
public:
    UserRepository();
    QJsonArray fetchUsersBlocking(const QCoreApplication *app, int page, int size) const;
};


#endif // USERREPOSITORY_H
