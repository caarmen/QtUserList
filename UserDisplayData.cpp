#include "UserDisplayData.h"

UserDisplayData::UserDisplayData(QString name, QString smallAvatarUrl, QString largeAvatarUrl, QString phone)
    : QObject(), name(name), smallAvatarUrl(smallAvatarUrl), largeAvatarUrl(largeAvatarUrl), phone(phone)
{
}

