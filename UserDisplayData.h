#ifndef USERDISPLAYDATA_H
#define USERDISPLAYDATA_H

#include <QObject>

class UserDisplayData : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name MEMBER name CONSTANT)
    Q_PROPERTY(QString smallAvatarUrl MEMBER smallAvatarUrl CONSTANT)
    Q_PROPERTY(QString largeAvatarUrl MEMBER largeAvatarUrl CONSTANT)
    Q_PROPERTY(QString phone MEMBER phone CONSTANT)
public:
    explicit UserDisplayData(QString name, QString smallAvatarUrl, QString largeAvatarUrl, QString phone);
    const QString name;
    const QString smallAvatarUrl;
    const QString largeAvatarUrl;
    const QString phone;

};

#endif // USERDISPLAYDATA_H
