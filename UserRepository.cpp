#include "UserRepository.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QCoreApplication>

UserRepository::UserRepository() {

}

QJsonArray UserRepository::fetchUsersBlocking(const QCoreApplication *app, int page, int size) const
{
    QString endpoint = "https://randomuser.me/api/?results=" + QString::number(size) + "&page=" + QString::number(page) + "&seed=abc";
    QNetworkRequest request;
    request.setUrl(QUrl(endpoint));
    QNetworkAccessManager restClient;
    QNetworkReply *reply = restClient.get(request);
    // TODO we should return a Future instead of the result directly, instead
    // of processing events like this here
    while (!reply->isFinished()) {
        app->processEvents();
    }
    QByteArray responseData = reply->readAll();
    QJsonDocument json = QJsonDocument::fromJson(responseData);
    QJsonArray usersJson = json["results"].toArray();
    reply->deleteLater();
    return usersJson;
}
