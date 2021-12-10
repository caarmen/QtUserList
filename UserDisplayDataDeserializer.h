#ifndef USERDISPLAYDATADESERIALIZER_H
#define USERDISPLAYDATADESERIALIZER_H
#include <UserDisplayData.h>
#include <QJsonArray>
#include <QJsonObject>

class UserDisplayDataDeserializer
{
public:
    static QList<UserDisplayData*>* parse(QJsonArray usersJson);
private:
    static UserDisplayData* parse(QJsonObject userJson);
};

#endif // USERDISPLAYDATADESERIALIZER_H
