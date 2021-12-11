#ifndef USERREPOSITORY_H
#define USERREPOSITORY_H

#include <QObject>
#include <QJsonArray>
#include <QCoreApplication>
#include <QNetworkAccessManager>

class UserRepository : public QObject
{
    Q_OBJECT
public:
    explicit UserRepository(QObject *parent = nullptr);
    ~UserRepository();
    void fetchUsers(int page, int size);

signals:
    void onUsersFetched(QJsonArray usersJson);

private:
    QNetworkAccessManager *netMgr;
};


#endif // USERREPOSITORY_H
