#include "UserRepository.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QCoreApplication>

UserRepository::UserRepository(QObject *parent) : QObject(parent) {
    netMgr = new QNetworkAccessManager();
}

UserRepository::~UserRepository() {
    netMgr->deleteLater();
}
void UserRepository::fetchUsers(int page, int size)
{
    QString endpoint = QString("https://randomuser.me/api/?results=%1&page=%2&seed=abc").arg(QString::number(size), QString::number(page));
    QNetworkRequest request;
    request.setUrl(QUrl(endpoint));
    QNetworkReply *reply = netMgr->get(request);
    QObject *context = new QObject(this);
    QObject::connect(reply, &QNetworkReply::finished, context, [=](){
        context->deleteLater();
        if (reply->error()) {
            emit onUsersFetched({false, QJsonArray()});
        } else {
            QByteArray responseData = reply->readAll();
            QJsonDocument json = QJsonDocument::fromJson(responseData);
            QJsonArray usersJson = json["results"].toArray();
            reply->deleteLater();
            emit onUsersFetched({true, usersJson});
        }
    });
}
