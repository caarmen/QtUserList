#include "UserDisplayDataDeserializer.h"
#include "UserDisplayData.h"
#include <QJsonObject>

QList<UserDisplayData*>* UserDisplayDataDeserializer::parse(QJsonArray usersJson)
{
    QList<UserDisplayData*> *dataList = new QList<UserDisplayData*>();
    for (auto item : usersJson) {
        QJsonObject userJson = item.toObject();
        UserDisplayData *userDisplayData = UserDisplayDataDeserializer::parse(userJson);
        dataList->append(userDisplayData);
    }
    return dataList;
}

UserDisplayData* UserDisplayDataDeserializer::parse(QJsonObject userJson)
{
    QJsonObject nameJson = userJson["name"].toObject();
    QString firstName = nameJson["first"].toString();
    QString lastName = nameJson["last"].toString();

    QJsonObject picture = userJson["picture"].toObject();
    QString smallAvatarUrl = picture["thumbnail"].toString();
    QString largeAvatarUrl = picture["large"].toString();

    QString phone = userJson["phone"].toString();
    return new UserDisplayData(firstName + " " + lastName, smallAvatarUrl, largeAvatarUrl, phone);
}
